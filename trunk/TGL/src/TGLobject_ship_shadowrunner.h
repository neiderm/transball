#ifndef TGL_OBJECT_SHADOWRUNNER
#define TGL_OBJECT_SHADOWRUNNER

class TGLobject_ship_shadowrunner : public TGLobject_ship {
public:
	TGLobject_ship_shadowrunner(float x,float y,int initial_fuel);
	virtual ~TGLobject_ship_shadowrunner();

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

private:
	bool m_thrusting,m_backthrusting;
};

#endif