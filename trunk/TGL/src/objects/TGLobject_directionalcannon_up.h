#ifndef TGL_OBJECT_DIRECTIONALCANNON_UP
#define TGL_OBJECT_DIRECTIONALCANNON_UP

class TGLobject_directionalcannon_up : public TGLobject_enemy {
public:
	TGLobject_directionalcannon_up(float x,float y,int animation_offset);
	virtual ~TGLobject_directionalcannon_up();

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

private:
};

#endif