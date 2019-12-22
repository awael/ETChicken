#pragma once
//BULLETS CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef bullets_h
#define bullets_h

using namespace sf;
class bullets {

private:
	Texture BulletTexture;
	Sprite BulletSprite;

public:

	bullets() {
		if (!BulletTexture.loadFromFile("images/bullet.png")) {

			std::cout << "loading error : Bullet";

		}
		BulletSprite.setScale(0.1, 0.1);

	}

	void draw(RenderWindow &window) {
		BulletSprite.setTexture(BulletTexture);
		window.draw(BulletSprite);
	}
	void move() {
		BulletSprite.move(0, -2);
	}
	void setPosition(Vector2f position) {
		BulletSprite.setPosition(position);
	}
	Vector2f getPosition()
	{
		return BulletSprite.getPosition();
	}
	FloatRect getSize() {
		return BulletSprite.getGlobalBounds();
	}


};
#endif