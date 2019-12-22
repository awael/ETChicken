#pragma once
//ROCKET CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef rockets_h
#define rockets_h

using namespace sf;
class rockets {
private:
	Texture RocketTexture;
	Sprite RocketSprite;

public:

	rockets() {
		if (!RocketTexture.loadFromFile("images/rocketimage.png")) {

			std::cout << "loading error : Rocket";

		}
		RocketSprite.setScale(0.68, 0.68);

	}

	void draw(RenderWindow &window) {
		RocketSprite.setTexture(RocketTexture);
		window.draw(RocketSprite);
	}
	void move() {
		RocketSprite.move(0, 1);
	}
	void setPosition(Vector2f position) {
		RocketSprite.setPosition(position);
	}
	Vector2f getPosition()
	{
		return RocketSprite.getPosition();
	}
	FloatRect getSize() {
		return RocketSprite.getGlobalBounds();
	}

};
#endif