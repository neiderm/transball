#ifndef TGL_OBJECT_VIPPERBEAM
#define TGL_OBJECT_VIPPERBEAM

class TGLobject_ship_vipperbeam : public TGLobject_ship {
public:
	TGLobject_ship_vipperbeam(float x,float y,int initial_fuel);
	virtual ~TGLobject_ship_vipperbeam();

	virtual bool is_a(char *n);
	virtual bool is_a(Symbol *n);
	virtual const char *get_class(void);

	virtual bool cycle(VirtualController *k,class TGLmap *map,GLTManager *GLTM,SFXManager *SFXM,int sfx_volume);
	virtual void draw(GLTManager *GLTM);

private:
	bool m_thrusting;
	int m_laser_channel;
};

#endif