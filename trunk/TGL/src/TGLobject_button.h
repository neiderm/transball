#ifndef TGL_OBJECT_BUTTON
#define TGL_OBJECT_BUTTON

class TGLobject_button : public TGLobject {
public:
	TGLobject_button(float x,float y,int event,int type);
	virtual ~TGLobject_button();

	void ball_hit(void);

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

	int get_type(void) {return m_type;};

private:
	int m_type;
	int m_event;
};

#endif