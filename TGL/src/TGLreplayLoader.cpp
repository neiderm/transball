#ifdef KITSCHY_DEBUG_MEMORY 
#include "debug_memorymanager.h"
#endif

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#include <time.h>

#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "pthread.h"

#include "List.h"
#include "Symbol.h"
#include "2DCMC.h"
#include "auxiliar.h"
#include "GLTile.h"
#include "2DCMC.h"
#include "sound.h"
#include "keyboardstate.h"
#include "randomc.h"
#include "VirtualController.h"

#include "GLTManager.h"
#include "SFXManager.h"

#include "TGLobject.h"
#include "TGLobject_ship.h"
#include "TGLobject_ball.h"
#include "TGLmap.h"
#include "TGL.h"
#include "TGLapp.h"
#include "XMLparser.h"

#include "TGLreplay.h"
#include "TGLreplayLoader.h"

#include "debug.h"


TGLreplayLoaderTask::~TGLreplayLoaderTask()
{
	if (m_running) {
		stop();
		pthread_join(m_thread,0);
	} // if 
	if (m_fp!=0) fclose(m_fp);
	m_fp=0;
	m_father=0;
	m_destination=0;
	m_running=false;
} /* TGLreplayLoaderTask::~TGLreplayLoaderTask */ 


void *TGLreplayLoaderTask::thread(void *task)
{
	TGLreplayLoaderTask *t=(TGLreplayLoaderTask *)task;
	TGLreplayLoader *father=t->m_father;

	{
		TGLreplay *r=new TGLreplay(t->m_fp);
		fclose(t->m_fp);
		t->m_fp=0;
		r->rewind();
		if (t->m_stopsignal) {
			delete r;
			return 0;
		} // if 
		*t->m_destination=r;
	}

	t->m_running=false;
	pthread_mutex_lock(&father->m_mutex);
	father->m_executing_tasks.DeleteElement(t);
	delete t;
	pthread_mutex_unlock(&father->m_mutex);

	father->launch_threads();

	return 0;
} /* TGLreplayLoaderTask::thread */ 


void TGLreplayLoaderTask::stop(void)
{
	m_stopsignal=true;
} /* TGLreplayLoaderTask::stop */ 



TGLreplayLoader::TGLreplayLoader(void)
{
	pthread_mutex_init(&m_mutex,NULL);
} /* TGLreplayLoader::TGLreplayLoader */ 


TGLreplayLoader::~TGLreplayLoader()
{
	cancel_all();
} /* TGLreplayLoader::~TGLreplayLoader */ 


void TGLreplayLoader::load_replay(FILE *fp,TGLreplay **destination)
{
	TGLreplayLoaderTask *t;

	t=new TGLreplayLoaderTask();
	t->m_fp=fp;
	t->m_father=this;
	t->m_destination=destination;
	t->m_running=false;
	t->m_stopsignal=false;
	pthread_mutex_lock(&m_mutex);
	m_pending_tasks.Add(t);
	pthread_mutex_unlock(&m_mutex);

	launch_threads();

} /* TGLreplayLoader::load_replay */ 


void TGLreplayLoader::launch_threads(void)
{
	TGLreplayLoaderTask *t;

	pthread_mutex_lock(&m_mutex);
	while(!m_pending_tasks.EmptyP() && m_executing_tasks.Length()<TGL_RL_MAXTHREADS) {
		int retval;

		t=m_pending_tasks.ExtractIni();
		t->m_running=true;
		m_executing_tasks.Add(t);
		pthread_attr_init(&t->m_thread_attr);
		retval=pthread_create(&t->m_thread, &t->m_thread_attr, TGLreplayLoaderTask::thread, (void *)t);

	} // if  
	pthread_mutex_unlock(&m_mutex);
} /* TGLreplayLoader::launch_threads */ 


void TGLreplayLoader::cancel_all(void)
{
	TGLreplayLoaderTask *t;

	pthread_mutex_lock(&m_mutex);
	while(!m_pending_tasks.EmptyP()) {
		t=m_pending_tasks.ExtractIni();
		t->stop();
		delete t;
	} // while 

	while(!m_executing_tasks.EmptyP()) {
		t=m_executing_tasks.ExtractIni();
		t->stop();
	} // while 
	pthread_mutex_unlock(&m_mutex);
} /* TGLreplayLoader::cancel_all */  



