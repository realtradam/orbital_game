#include "renderer.hpp"
#include "resources.hpp"

namespace Renderer {
	Sprite::Sprite(std::string texture_name,
			Rectangle source_rectangle,
			Vector2 origin
			):texture_name(texture_name),
	source_rectangle(source_rectangle),
	origin(origin){

	}

	void Sprite::drawPro(Rectangle dest_rectangle, float rotation, Color color) {
		DrawTexturePro(Resources::useTexture(texture_name),
				source_rectangle,
				dest_rectangle,
				origin,
				rotation,
				color);
	}

	void Sprite::draw(float x, float y, float scale, float rotation, Color color) {
		DrawTexturePro(Resources::useTexture(texture_name),
				source_rectangle,
				(Rectangle){x,y,source_rectangle.width * scale,source_rectangle.height * scale},
				origin,
				rotation,
				color);
	}
}
