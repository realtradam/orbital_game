#include <unordered_map>
#include <string>
#include "raylib.h"

namespace Resources {
	Texture useTexture(std::string id);
	class Sprite {
		public:
			std::string texture_name;
			Rectangle source_rectangle;
			Vector2 origin;

			Sprite(std::string texture_name,
					Rectangle source_rectangle,
					Vector2 origin = (Vector2){0,0}
				  );
			void drawPro(Rectangle dest_rectangle, float rotation = 0, Color color = WHITE);
			void draw(float x, float y, float scale = 1.0, float rotation = 0, Color color = WHITE);
	};
}
