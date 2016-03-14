#ifndef CORE_H
#define CORE_H

#include <common/scene.h>
#include <common/renderer.h>

class Core
{
	public:
		Core();
		virtual ~Core();

		void update(Scene* scene);

		bool running;

	private:
		Renderer _renderer;
};

#endif /* CORE_H */