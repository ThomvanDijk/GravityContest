#ifndef SCENE_H
#define SCENE_H

#include <common/entity.h>

class Scene: public Entity
{
public:
	Scene();
	virtual ~Scene();

	void updateScene();
};

#endif /* SCENE_H */
