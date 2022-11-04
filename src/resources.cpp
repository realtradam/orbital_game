#include <unordered_map>
#include <string>
#include <stdexcept>
#include "raylib.h"
#include "resources.h"

namespace Resources {
	static std::unordered_map<std::string, std::string> textureFiles = {
		{"ship", "./assets/textures/spaceShooter2_spritesheet_2X.png"}
	};
	static std::unordered_map<std::string, Texture> textures;
	Texture useTexture(std::string id) {
		Texture texture;
		auto texSearch = textures.find(id);
		if (texSearch != textures.end()) {
			return texSearch->second;
		}
		auto texPathSearch = textureFiles.find(id);
		if (texPathSearch != textureFiles.end()) {
			texture = LoadTexture(texPathSearch->second.c_str());
			textures.insert({id, texture});
		} else {
			throw std::invalid_argument("Texture id '" + id + "' has no assigned path.");
		}
		return texture;
	}

	Sprite::Sprite(std::string texture_name,
			Rectangle source_rectangle,
			Vector2 origin
			):texture_name(texture_name),
	source_rectangle(source_rectangle),
	origin(origin){

	}

	void Sprite::drawPro(Rectangle dest_rectangle, float rotation, Color color) {
		DrawTexturePro(useTexture(texture_name),
				source_rectangle,
				dest_rectangle,
				origin,
				rotation,
				color);
	}

	void Sprite::draw(float x, float y, float scale, float rotation, Color color) {
		DrawTexturePro(useTexture(texture_name),
				source_rectangle,
				(Rectangle){x,y,source_rectangle.width * scale,source_rectangle.height * scale},
				origin,
				rotation,
				color);
	}
}
