#ifndef TGL_OBJECT_LASER_DOWN
#define TGL_OBJECT_LASER_DOWN

class TGLobject_laser_down : public TGLobject_enemy {
public:
	TGLobject_laser_down(float x,float y,int animation_offset);
	virtual ~TGLobject_laser_down();

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

private:
};

#endif