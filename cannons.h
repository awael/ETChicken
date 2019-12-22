#pragma once
#pragma once
#pragma once
//cannons CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef cannon_h
#define cannon_h

using namespace sf;
class cannons {
private:
	Texture cannonTexture;
	Sprite cannonSprite;

public:

	cannons() {
		if (!cannonTexture.loadFromFile("images/cannonimage.png")) {

			std::cout << "loading error : Lazer";

		}
		cannonSprite.setScale(0.35, 0.35);

	}

	void draw(RenderWindow &window) {
		cannonSprite.setTexture(cannonTexture);
		window.draw(cannonSprite);
	}
	void move() {
		int x = (rand() % 20) - 1;
		int y = (rand() % 20) + 1;
		cannonSprite.move(-0.3 - x / 3.5, -0.5 + y / 3.5);
	}
	void setPosition(int x, int y) {
		cannonSprite.setPosition(x, y);
	}
	Vector2f getPosition()
	{
		return cannonSprite.getPosition();
	}
	FloatRect getSize() {
		return cannonSprite.getGlobalBounds();
	}


};
#endif