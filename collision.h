#pragma once
//COLLISION CLASS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#include "egg.h"
#include "ship.h"
#include"bullets.h"
#include "pickup.h"
#include "rocks.h"
#include "rockets.h"
#include "lazers.h"
#include "cannons.h"

#ifndef collision_h
#define collision_h

using namespace sf;

class collision {

public:
	static bool BulletChickenCollide(Sprite &chicken, bullets &bullet) {

		if (chicken.getGlobalBounds().intersects(bullet.getSize()))
			return true;
		else return false;
	}

	static bool ChickenShipCollide(Sprite &chicken, ship &ship) {

		if (chicken.getGlobalBounds().intersects(ship.getSize()))
			return true;
		else return false;
	}
	static bool CommandoShipCollide(Sprite &commando, ship &ship) {

		if (commando.getGlobalBounds().intersects(ship.getSize()))
			return true;
		else return false;
	}

	static bool EggShipCollide(egg &Egg, ship &ship) {

		if (Egg.getSize().intersects(ship.getSize()))
			return true;
		else return false;
	}
	static bool LazerShipCollide(lazers &Lazer, ship &ship) {

		if (Lazer.getSize().intersects(ship.getSize()))
			return true;
		else return false;
	}
	static bool CannonShipCollide(cannons &Cannon, ship &ship) {

		if (Cannon.getSize().intersects(ship.getSize()))
			return true;
		else return false;
	}

	static bool RocketShipCollide(rockets &Rocket, ship &ship) {

		if (Rocket.getSize().intersects(ship.getSize()))
			return true;
		else return false;
	}

	static bool PickupShipCollide(pickup &pickup, ship &ship) {

		if (pickup.getSize().intersects(ship.getSize())) 
			return true;
		else return false;
		
	}
	static bool RockShipCollide(rocks &rock, ship &ship) {

		if (rock.getSize().intersects(ship.getSize()))
			return true;
		else return false;

	}
	static bool BulletRockCollide(bullets &bullet, rocks &rock) {

		if (rock.getSize().intersects(bullet.getSize()))
			return true;
		else return false;

	}


};
#endif

