#include "VirtualController.h"

VirtualController::VirtualController(void)
{
	m_joystick[VC_UP]=false;
	m_joystick[VC_RIGHT]=false;
	m_joystick[VC_LEFT]=false;
	m_joystick[VC_DOWN]=false;
	m_button[0]=false;
	m_button[1]=false;
	m_pause=false;
	m_quit=false;

	m_old_joystick[VC_UP]=false;
	m_old_joystick[VC_RIGHT]=false;
	m_old_joystick[VC_LEFT]=false;
	m_old_joystick[VC_DOWN]=false;
	m_old_button[0]=false;
	m_old_button[1]=false;
	m_old_pause=false;
	m_old_quit=false;
} /* VirtualController::VirtualController */ 


VirtualController::VirtualController(VirtualController *vc)
{
	copy(vc);
} /* VirtualController::VirtualController */ 


void VirtualController::copy(VirtualController *vc)
{
	m_joystick[VC_UP]=vc->m_joystick[VC_UP];
	m_joystick[VC_RIGHT]=vc->m_joystick[VC_RIGHT];
	m_joystick[VC_LEFT]=vc->m_joystick[VC_LEFT];
	m_joystick[VC_DOWN]=vc->m_joystick[VC_DOWN];
	m_button[0]=vc->m_button[0];
	m_button[1]=vc->m_button[1];
	m_pause=vc->m_pause;
	m_quit=vc->m_quit;

	m_old_joystick[VC_UP]=vc->m_old_joystick[VC_UP];
	m_old_joystick[VC_RIGHT]=vc->m_old_joystick[VC_RIGHT];
	m_old_joystick[VC_LEFT]=vc->m_old_joystick[VC_LEFT];
	m_old_joystick[VC_DOWN]=vc->m_old_joystick[VC_DOWN];
	m_old_button[0]=vc->m_old_button[0];
	m_old_button[1]=vc->m_old_button[1];
	m_old_pause=vc->m_old_pause;
	m_old_quit=vc->m_old_quit;
} /* VirtualController::copy */ 


void VirtualController::copy_current(VirtualController *vc)
{
	m_joystick[VC_UP]=vc->m_joystick[VC_UP];
	m_joystick[VC_RIGHT]=vc->m_joystick[VC_RIGHT];
	m_joystick[VC_LEFT]=vc->m_joystick[VC_LEFT];
	m_joystick[VC_DOWN]=vc->m_joystick[VC_DOWN];
	m_button[0]=vc->m_button[0];
	m_button[1]=vc->m_button[1];
	m_pause=vc->m_pause;
	m_quit=vc->m_quit;
} /* VirtualController::copy_current */ 


