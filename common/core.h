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
		double _calculateDeltaTime();

		Renderer _renderer;
		double _deltaTime;
};

#endif /* CORE_H */