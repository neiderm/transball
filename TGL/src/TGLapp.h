#ifndef _TGL_APP
#define _TGL_APP


// This is to have a 640x480 screen:
#define PERSPECTIVE_DISTANCE	-895.8F

#define MAXLOCAL_PLAYERS	4

#define TGL_STATE_NONE	-1
#define TGL_STATE_PLAYERPROFILE	1
#define TGL_STATE_INTRO			2
#define TGL_STATE_LEVELPACKSCREEN	3
#define TGL_STATE_LEVELPACKBROWSER	4
#define TGL_STATE_MAINMENU		5
#define TGL_STATE_CONFIGURE		6
#define TGL_STATE_PREGAME		7
#define TGL_STATE_GAME			8
#define TGL_STATE_POSTGAME		9
#define TGL_STATE_SAVEREPLAY	10
#define TGL_STATE_REPLAYBROWSER	11

#define KEY_THRUST		0
#define KEY_SPECIAL		1
#define KEY_LEFT		2
#define KEY_RIGHT		3
#define KEY_FIRE		4
#define KEY_ATTRACTOR	5
#define KEY_PAUSE		6
#define KEY_QUIT		7

#define SAVEREPLAY_REPLAYSPERPAGE	12
#define LEVELPACKBROWSER_LPPERPAGE	10
#define PROFILESPERPAGE				12

class TGLapp {
public:
	TGLapp();
	~TGLapp();

	bool cycle(class KEYBOARDSTATE *k);
	void draw(int SCREEN_X,int SCREEN_Y);

	void save_playerprofile(void);
	void load_playerprofile(char *name);

	void MouseClick(int mx,int my);

	static void string_editor_cycle(char *editing_text,unsigned int *editing_position,unsigned int max_length,KEYBOARDSTATE *k);

	class PlayerProfile *get_player_profile(void) {return m_player_profile;};


protected:
	int playerprofile_cycle(KEYBOARDSTATE *k);
	int intro_cycle(KEYBOARDSTATE *k);
	int levelpackscreen_cycle(KEYBOARDSTATE *k);
	int levelpackbrowser_cycle(KEYBOARDSTATE *k);
	int mainmenu_cycle(KEYBOARDSTATE *k);
	int configure_cycle(KEYBOARDSTATE *k);
	int game_cycle(KEYBOARDSTATE *k);
	int pregame_cycle(KEYBOARDSTATE *k);
	int postgame_cycle(KEYBOARDSTATE *k);
	int savereplay_cycle(KEYBOARDSTATE *k);
	int replaybrowser_cycle(KEYBOARDSTATE *k);

	void playerprofile_draw(void);
	void intro_draw(void);
	void levelpackscreen_draw(void);
	void levelpackbrowser_draw(void);
	void mainmenu_draw(void);
	void configure_draw(void);
	void game_draw(void);
	void pregame_draw(void);
	void postgame_draw(void);
	void savereplay_draw(void);
	void replaybrowser_draw(void);

	int screen_x(int x);	/* given a coordinate in 640x480, returns the proper coordinate at the current resolution */ 
	int screen_y(int y);    /* given a coordinate in 640x480, returns the proper coordinate at the current resolution */ 

	// Fade in/out effects:
	void fade_in_alpha(float f);
	void fade_in_squares(float f,float size);
	void fade_in_triangles(float f,float size);

	class GLTManager *m_GLTM;
	class SFXManager *m_SFXM;

	TTF_Font *m_font32,*m_font16,*m_ifont32;

	List<int> m_mouse_click_x;
	List<int> m_mouse_click_y;

	int m_screen_dx,m_screen_dy;
	int m_state;
	int m_state_cycle;
	int m_state_fading;
	int m_state_fading_cycle;
	int m_state_selection;
	class TGL *m_game;

	List<class VirtualController> m_lvc;

	// configuration:
	PlayerProfile *m_player_profile;

	// Game state:
	int m_game_state;
	int m_game_state_cycle;
	int m_game_fade_effect;
	int m_game_replay_mode;	//  1 : saving replay, 2 : replaying replay
	class TGLreplay *m_game_replay;
	class LevelPack *m_current_levelpack;
	int m_selected_level;
	int m_selected_ship;
	int m_game_previous_state;
	bool m_game_reinit_previous_state;

	// Post game:
	int m_ship_unlocked;

	// Main menu:
	int m_mm_demo_state;
	int m_mm_demo_timmer;
	TGL *m_mm_game;
	TGLreplay *m_mm_replay;

	// Save Replay
	class TGLTextInputFrame *m_replay_name_inputframe;
	class TGLInterfaceElement *m_replay_save_button;
	TGLInterfaceElement *m_sr_replay_uparrow;
	TGLInterfaceElement *m_sr_replay_downarrow;
	List<char> m_sr_replay_fullnames;
	List<char> m_sr_replay_names;
	List<char> m_sr_replay_info;
	int m_sr_first_replay;

	// Replay Browser:
	TGLInterfaceElement *m_replay_rename_button;
	TGLInterfaceElement *m_replay_play_button;
	TGLInterfaceElement *m_replay_delete_button;
	int m_rb_mouse_over_replay;
	int m_rb_replay_selected;

	// LevelPack screen:
	int m_lp_music_channel;
	int m_lp_first_level;
	TGLInterfaceElement *m_lp_level_uparrow;
	TGLInterfaceElement *m_lp_level_downarrow;
	TGLInterfaceElement *m_lp_level_name[3];
	TGLInterfaceElement *m_lp_level_time[3];
	TGLInterfaceElement *m_lp_level_points[3];
	TGLInterfaceElement *m_lp_play_buttons[3];
	TGLInterfaceElement *m_lp_viewreplay_buttons[3];
	TGLInterfaceElement *m_lp_ship_leftarrow;
	TGLInterfaceElement *m_lp_ship_rightarrow;
	TGL *m_lp_tutorial_game;
	TGLreplay *m_lp_tutorial_replay;
	int m_lp_replay_mode;
	int m_lp_replay_timmer;

	// Levelpack Browser
	TGLInterfaceElement *m_lpb_select_button;
	TGLInterfaceElement *m_lpb_lp_uparrow;
	TGLInterfaceElement *m_lpb_lp_downarrow;
	List<char> m_lpb_lp_fullnames;
	List<char> m_lpb_lp_names;
	List<char> m_lpb_lp_info;
	List<char> m_lpb_lp_longinfo;
	int m_lpb_first_lp;
	int m_lpb_mouse_over_lp;
	int m_lpb_lp_selected;

	// configure:
	int m_configure_key_to_change;
	TGLInterfaceElement *m_configure_fullscreen;
	TGLInterfaceElement *m_configure_window;
	TGLInterfaceElement *m_configure_music_volume;
	TGLInterfaceElement *m_configure_sfx_volume;

	// Player profile selection:
	TGLInterfaceElement *m_profile_select_button;
	TGLInterfaceElement *m_profile_create_button;
	TGLTextInputFrame *m_profile_name_inputframe;
	int m_profile_mouse_over_profile;
	int m_profile_profile_selected;
	TGLInterfaceElement *m_profile_profile_uparrow;
	TGLInterfaceElement *m_profile_profile_downarrow;
	List<char> m_profile_profile_fullnames;
	List<char> m_profile_profile_names;
	List<char> m_profile_profile_info;
	int m_profile_first_profile;
};

#endif
