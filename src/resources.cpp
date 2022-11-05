#include <unordered_map>
#include <string>
#include <stdexcept>
#include "raylib.h"
#include "resources.hpp"

namespace Resources {
	static std::unordered_map<std::string, std::string> textureFiles = {
		{"kenneySpaceShooter", "./assets/textures/spaceShooter2_spritesheet_2X.png"}
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

}
