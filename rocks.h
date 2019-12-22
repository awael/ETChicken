#pragma once
//EGG CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef rocks_h
#define rocks_h

using namespace sf;
class rocks {
private:
	Texture RockTexture;
	Sprite RockSprite;

public:

	rocks() {
		
		if (!RockTexture.loadFromFile("images/rockimage.png")) {
			std::cout << "loading error : rock";
		}
		RockSprite.setScale(0.8, 0.8);
	}

	void draw(RenderWindow &window) {
		window.draw(RockSprite);
		RockSprite.setTexture(RockTexture);

	}
	void move() {
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		RockSprite.move(1 + x/3.5 , 2+y/3.5);
	}
	void setPosition(int x,int y) {
		RockSprite.setPosition(x, y);
	}
	Vector2f getPosition()
	{
		return RockSprite.getPosition();
	}
	FloatRect getSize() {
		return RockSprite.getGlobalBounds();
	}

};
#endif