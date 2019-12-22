#pragma once
#pragma once
#pragma once
//SHIP CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#ifndef ship_h
#define ship_h

using namespace sf;
class ship {

private:

		sf::Vector2f pl;
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
public:
	ship() {

		shipTexture.loadFromFile("images/ship.png");
		if (!shipTexture.loadFromFile("images/ship.png"))
			std::cout << "image not found ";

		
		shipSprite.setTexture(shipTexture);
		shipTexture.setSmooth(true);
		shipSprite.setPosition(1500, 1100);
		shipSprite.setScale(0.3, 0.3);

	}
	void update(Event event) {


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			shipSprite.move(0, -50);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			shipSprite.move(0, 50);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			shipSprite.move(-50, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			shipSprite.move(50, 0);
	}
		Vector2f getPosition()
		{
			return shipSprite.getPosition();
		}
	
	void draw(RenderWindow &window) {

		window.draw(shipSprite);
	}
	FloatRect getSize() {
		return shipSprite.getGlobalBounds();
	}

	void changeColor() {
		shipSprite.setColor(Color::Blue);
	}

};







#endif ship_h