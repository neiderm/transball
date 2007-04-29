#ifndef TGL_INTERFACE
#define TGL_INTERFACE

class TGLInterfaceElement {
public:
	virtual ~TGLInterfaceElement();

	virtual bool check_status(int mousex,int mousey,int button,int button_status,class KEYBOARDSTATE *k);
	virtual void draw(float alpha);
	virtual void draw(void);

	int m_ID;
	bool m_enabled;
	bool m_active;	/* This indictes wether the component is active or passive, */ 
					/* e.g.: TGLText and TGLframe are passive					*/ 
	float m_x,m_y,m_dx,m_dy;
};


class TGLText : public TGLInterfaceElement {
public:

	TGLText(char *text,TTF_Font *font,float x,float y,bool centered);
	virtual ~TGLText();

	virtual void draw(float alpha);
	virtual void draw(void);

	bool m_centered;
	char *m_text;
	TTF_Font *m_font;
};


class TGLbutton : public TGLInterfaceElement {
public:

	TGLbutton(char *text,TTF_Font *font,float x,float y,float dx,float dy,int ID);
	TGLbutton(GLTile *icon,float x,float y,float dx,float dy,int ID);
	virtual ~TGLbutton();

	virtual bool check_status(int mousex,int mousey,int button,int button_status,KEYBOARDSTATE *k);
	virtual void draw(float alpha);
	virtual void draw(void);

	char *m_text;
	TTF_Font *m_font;
	int m_status;
	GLTile *m_tile;
};


class TGLbuttonTransparent : public TGLbutton {
public:

	TGLbuttonTransparent(char *text,TTF_Font *font,float x,float y,float dx,float dy,int ID);

	virtual void draw(float alpha);
};



class TGLframe : public TGLInterfaceElement {
public:

	TGLframe(float x,float y,float dx,float dy);
	virtual ~TGLframe();

	virtual void draw(float alpha);
	virtual void draw(void);

};


class TGLTextInputFrame : public TGLframe {
public:

	TGLTextInputFrame(char *initial_text,int max_characters,TTF_Font *font,float x,float y,float dx,float dy,int ID);
	virtual ~TGLTextInputFrame();

	virtual bool check_status(int mousex,int mousey,int button,int button_status,KEYBOARDSTATE *k);
	virtual void draw(float alpha);
	virtual void draw(void);

	TTF_Font *m_font;
	char *m_editing;
	int m_max_characters;
	unsigned int m_editing_position;
	bool m_focus;
	int m_cycle;
	bool m_change_in_last_cycle;
};


class TGLslider : public TGLInterfaceElement {
public:

	TGLslider(float x,float y,float dx,float dy,float slider_dx,float slider_dy,int ID);
	virtual ~TGLslider();

	virtual bool check_status(int mousex,int mousey,int button,int button_status,KEYBOARDSTATE *k);
	virtual void draw(float alpha);
	virtual void draw(void);

	float m_slider_dx,m_slider_dy;
	float m_value;
};




class TGLinterface {
public:
	static List<TGLInterfaceElement> m_elements;

	static void add_element(TGLInterfaceElement *b);
	static void remove_element(TGLInterfaceElement *b);
	static void substitute_element(TGLInterfaceElement *old,TGLInterfaceElement *n);
	static void reset(void);
	static int update_state(int mousex,int mousey,int button,int button_status,KEYBOARDSTATE *k);
	static void draw(float alpha);
	static void draw(void);

	static void clear_print_cache(void);
	static void print_left(char *text,TTF_Font *font,float x,float y);
	static void print_center(char *text,TTF_Font *font,float x,float y);
	static void print_left(char *text,TTF_Font *font,float x,float y,float r,float g,float b,float a);
	static void print_center(char *text,TTF_Font *font,float x,float y,float r,float g,float b,float a);

	// Centered in both X and Y:
	static void print_centered(char *text,TTF_Font *font,float x,float y,float r,float g,float b,float a,float angle,float scale);
};

#endif