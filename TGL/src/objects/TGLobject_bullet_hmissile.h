#ifndef TGL_OBJECT_BULLET_HMISSILE
#define TGL_OBJECT_BULLET_HMISSILE

class TGLobject_bullet_hmissile : public TGLobject_bullet {
public:
	TGLobject_bullet_hmissile(float x,float y,int animation_offset,int angle,float speed,int power,GLTile *tile,GLTile *tile2,TGLobject *ship);

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

private:
	GLTile *m_tile2;

	TGLobject *m_target;
	float m_dest_x,m_dest_y;
};

#endif