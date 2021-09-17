#include "ImageManager.h"

map<string, Texture> ImageManager::images_;

void ImageManager::loadImage(string fileName) {
	string path = "images/";
	path += fileName + ".png";

	images_[fileName].loadFromFile(path);
}
Texture& ImageManager::getTexture(string ImageName) {
	if (images_.find(ImageName) == images_.end()) {
		loadImage(ImageName);
	}
	return images_[ImageName];
}
void ImageManager::clear() {
	images_.clear();
}