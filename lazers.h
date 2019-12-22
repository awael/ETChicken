#pragma once
#pragma once
//lazers CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef lazers_h
#define lazers_h

using namespace sf;
class lazers {
private:
	Texture LazerTexture;
	Sprite LazerSprite;

public:

	lazers() {
		if (!LazerTexture.loadFromFile("images/lazerimage.png")) {

			std::cout << "loading error : Lazer";

		}
		LazerSprite.setScale(0.3, 0.3);

	}

	void draw(RenderWindow &window) {
		LazerSprite.setTexture(LazerTexture);
		window.draw(LazerSprite);
	}
	void move() {
		int x = rand() % 20 + 1;
		int y = rand() % 20 + 1; 
		LazerSprite.move(0.3 + x / 3.5, 0.5 + y / 3.5);
	}
	void setPosition(int x,int y) {
		LazerSprite.setPosition(x, y);
	}
	Vector2f getPosition()
	{
		return LazerSprite.getPosition();
	}
	FloatRect getSize() {
		return LazerSprite.getGlobalBounds();
	}


};
#endif