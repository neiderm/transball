#ifdef KITSCHY_DEBUG_MEMORY 
#include "debug_memorymanager.h"
#endif

#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"

#include "gl.h"
#include "glu.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

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
#include "TGLobject_pipevscreen.h"
#include "TGLmap.h"

#include "debug.h"




TGLobject_pipevscreen::TGLobject_pipevscreen(float x,float y,int ao) : TGLobject(x,y,ao)
{
} /* TGLobject_pipevscreen::TGLobject_pipevscreen */ 


TGLobject_pipevscreen::~TGLobject_pipevscreen()
{
} /* TGLobject_pipevscreen::~TGLobject_pipevscreen */ 


void TGLobject_pipevscreen::draw(GLTManager *GLTM)
{
	int local_cycle=((m_animation_offset+m_cycle)%120)/8;
	if (local_cycle==0) m_last_tile=GLTM->get("objects/pipe-vertical-screen1");
	if (local_cycle==1) m_last_tile=GLTM->get("objects/pipe-vertical-screen2");
	if (local_cycle==2) m_last_tile=GLTM->get("objects/pipe-vertical-screen1");
	if (local_cycle==3) m_last_tile=GLTM->get("objects/pipe-vertical-screen2");
	if (local_cycle==4) m_last_tile=GLTM->get("objects/pipe-vertical-screen1");
	if (local_cycle==5) m_last_tile=GLTM->get("objects/pipe-vertical-screen2");
	if (local_cycle==6) m_last_tile=GLTM->get("objects/pipe-vertical-screen1");
	if (local_cycle==7) m_last_tile=GLTM->get("objects/pipe-vertical-screen2");
	if (local_cycle==8) m_last_tile=GLTM->get("objects/pipe-vertical-screen3");
	if (local_cycle==9) m_last_tile=GLTM->get("objects/pipe-vertical-screen4");
	if (local_cycle==10) m_last_tile=GLTM->get("objects/pipe-vertical-screen5");
	if (local_cycle==11) m_last_tile=GLTM->get("objects/pipe-vertical-screen6");
	if (local_cycle==12) m_last_tile=GLTM->get("objects/pipe-vertical-screen7");
	if (local_cycle==13) m_last_tile=GLTM->get("objects/pipe-vertical-screen8");
	if (local_cycle==14) m_last_tile=GLTM->get("objects/pipe-vertical-screen9");
	if (m_last_tile!=0) m_last_tile->draw(m_x,m_y,0,0,1);
} /* TGLobject_pipevscreen::draw */ 


bool TGLobject_pipevscreen::is_a(Symbol *c)
{
	if (c->cmp("TGLobject_pipevscreen")) return true;
	return TGLobject::is_a(c);
} /* TGLobject_pipevscreen::is_a */ 


bool TGLobject_pipevscreen::is_a(char *c)
{
	bool retval;
	Symbol *s=new Symbol(c);

	retval=is_a(s);

	delete s;

	return retval;
} /* TGLobject_pipevscreen::is_a */ 


const char *TGLobject_pipevscreen::get_class(void)
{
	return "TGLobject_pipevscreen";
} /* TGLobject_pipevscreen:get_class */ 

