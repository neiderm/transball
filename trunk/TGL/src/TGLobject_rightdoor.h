#ifndef TGL_OBJECT_RIGHTDOOR
#define TGL_OBJECT_RIGHTDOOR

class TGLobject_rightdoor : public TGLobject {
public:
	TGLobject_rightdoor(float x,float y,int state,int action);
	virtual ~TGLobject_rightdoor();

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

	void action(int action);

private:
	float m_original_x;
	int m_action;
};

#endif