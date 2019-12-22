#pragma once
//PICKUP CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef pickup_h
#define pickup_h

using namespace sf;
class pickup {
private:
	Texture PickupTexture;
	Sprite PickupSprite;

public:

	pickup() {
		if (!PickupTexture.loadFromFile("images/pickup.png")) {

			std::cout << "loading error : pickup";

		}
		PickupSprite.setScale(0.1, 0.1);
		PickupSprite.setTexture(PickupTexture);
	}

	void draw(RenderWindow &window) {
		//PickupSprite.setTexture(PickupTexture);
		window.draw(PickupSprite);

	}
	void move() {
		PickupSprite.move(0,10);// (0.0f, 1.0f);
	}
	void setPosition(Vector2f position) {
		PickupSprite.setPosition(position);
	}
	Vector2f getPosition()
	{
		return PickupSprite.getPosition();
	}
	FloatRect getSize() {
		return PickupSprite.getGlobalBounds();
	}


};
#endif
