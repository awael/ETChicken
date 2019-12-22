//EGG CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef egg_h
#define egg_h

using namespace sf;
class egg {
private:
	Texture EggTexture;
	Sprite EggSprite;

public:

	egg() {
		if (!EggTexture.loadFromFile("images/eggimage.png")) {

			std::cout << "loading error : Egg";

		}
		EggSprite.setScale(0.1, 0.1);

	}

	void draw(RenderWindow &window) {
		EggSprite.setTexture(EggTexture);
		window.draw(EggSprite);
	}
	void move() {
		EggSprite.move(0, 1);
	}
	void setPosition(Vector2f position) {
		EggSprite.setPosition(position);
	}
	Vector2f getPosition()
	{
		return EggSprite.getPosition();
	}
	FloatRect getSize() {
		return EggSprite.getGlobalBounds();
	}

};
#endif