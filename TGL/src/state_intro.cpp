#ifdef KITSCHY_DEBUG_MEMORY 
#include "debug_memorymanager.h"
#endif

#ifdef _WIN32
#include "windows.h"
#endif

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

#include "GL/gl.h"
#include "GL/glu.h"
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
#include "TGLobject_ship.h"
#include "TGLmap.h"
#include "TGL.h"
#include "TGLapp.h"
#include "TGLreplay.h"

#include "LevelPack.h"


// state cycle 0-50 : brain games appears
// state cycle 50-250 : brain games
// state cycle 250-300 : brain games disappears

// state cycle 300-350 : black


int TGLapp::intro_cycle(KEYBOARDSTATE *k)
{
	if (k->key_press(SDLK_SPACE) ||
		k->key_press(SDLK_ESCAPE) ||
		k->key_press(SDLK_RETURN)) return TGL_STATE_MAINMENU;

	if (m_state_cycle>1000) return TGL_STATE_MAINMENU;
	return TGL_STATE_INTRO;
} /* TGLapp::intro_cycle */ 

void TGLapp::intro_draw(void)
{
	glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

	if (m_state_cycle>=0 && m_state_cycle<50) {
		float f1=m_state_cycle/50.0f;
		float f2=0.75f+(m_state_cycle/250.0f)*0.25f;
		m_GLTM->get_smooth("interface/braingames")->draw(1,1,1,f1,320,240,0,0,f2);
	} // if 
	if (m_state_cycle>=50 && m_state_cycle<250) {
		float f2=0.75f+(m_state_cycle/250.0f)*0.25f;
		m_GLTM->get_smooth("interface/braingames")->draw(1,1,1,1,320,240,0,0,f2);
	} // if 
	if (m_state_cycle>=250 && m_state_cycle<300) {
		float f1=(300-m_state_cycle)/50.0f;
		float f2=0.75f+(m_state_cycle/250.0f)*0.25f;
		m_GLTM->get_smooth("interface/braingames")->draw(1,1,1,f1,320,240,0,0,f2);
	} // if 

	if (m_state_cycle>=350 && m_state_cycle<550) {
		float f1=(m_state_cycle-350)/200.0f;
		m_GLTM->get_smooth("interface/transball")->draw(1,1,1,f1*f1,320,240*(1-f1)+120*f1,0,0,2*(1-f1)+f1*0.5f);
	} // if 

	if (m_state_cycle>=550) {

		if (m_state_cycle>=600 && m_state_cycle<1000) {
			float f1=(m_state_cycle-600)/400.0f;
			m_GLTM->get_smooth("interface/gl")->draw(1,1,1,f1,320,240,0,0,0.9f+f1*0.1f);
		} // if 
		if (m_state_cycle>=1000) {
			m_GLTM->get_smooth("interface/gl")->draw(1,1,1,1,320,240,0,0,1);
		} // if 
	
		m_GLTM->get_smooth("interface/transball")->draw(1,1,1,1,320,120,0,0,0.5f);
	} // if 
	
} /* TGLapp::intro_draw */ 
