#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include<string>
#include "egg.h"
#include "ship.h"
#include"bullets.h"
#include "collision.h"
#include "pickup.h"
#include "menu.h"
#include "HighScore.h"
#include <fstream>
#include "rocks.h"
#include "rockets.h"
#include "cannons.h"

using namespace sf;
using namespace std;

enum state { menustate, game, postgame, highscore };
enum level { one, two, three, four, boss };
enum Status {Stopped,Paused,Playing};

void initializeboss(RenderWindow &window, Sprite &BossSprite, const Texture&BossTexture) {

	BossSprite.setTexture(BossTexture);
	BossSprite.scale(2.5, 2.5);
	BossSprite.setPosition(850, 100);

}

void initialize2(RenderWindow &window, Sprite CommandoSprite[10][2], const Texture&commando, const Texture&commando2) {



	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			CommandoSprite[i][j].setTexture(commando);
			CommandoSprite[i][j].scale(0.8, 0.8);
			CommandoSprite[i][j].setPosition((i + 1) * 250, (j * 350)+200);


		}
	}

}
void Initalize(RenderWindow &window, Sprite ChickenSprite[10][4], const Texture&chicken,const Texture&chicken2)
{



	window.create(sf::VideoMode(3000, 1500), "Chicken Invaders");

	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			ChickenSprite[i][j].setTexture(chicken);
			ChickenSprite[i][j].scale(0.275, 0.275);
			ChickenSprite[i][j].setPosition((i + 1) * 250, j*200);

		
		}
	}

}
void renderboss(sf::RenderWindow &window,Sprite Background, Sprite BossSprite, std::vector<bullets>& BulletVec,std::vector<cannons>& CannonVec, std::vector<lazers>& LazersVec, ship &spaceship, vector<Sprite>LivesVec) {

	window.draw(Background);

	for (int i = 0; i < LivesVec.size(); i++) {
		window.draw(LivesVec[i]);
	}
	for (int i = 0; i < CannonVec.size(); i++)
		CannonVec[i].draw(window);

	for (int i = 0; i < LazersVec.size(); i++)
		LazersVec[i].draw(window);
	
	
	for (int i = 0; i < BulletVec.size(); i++)
		BulletVec[i].draw(window);

	for (int i = 0; i < CannonVec.size(); i++)
		CannonVec[i].draw(window);
	spaceship.draw(window);

	for (int i = 0; i < CannonVec.size(); i++)
		CannonVec[i].draw(window);
	window.draw(BossSprite);
	spaceship.draw(window);

}

void render2(sf::RenderWindow &window, Sprite Background, std::vector<rocks>& RockVec, std::vector<bullets>& BulletVec, ship &spaceship, vector<Sprite>LivesVec) {

	window.draw(Background);
	for (int i = 0; i < LivesVec.size(); i++) {
		window.draw(LivesVec[i]);
	}
	for (int i = 0; i < RockVec.size(); i++)
		RockVec[i].draw(window);
	
	for (int i = 0; i < BulletVec.size(); i++)
		BulletVec[i].draw(window);
	spaceship.draw(window);

}
void render3(sf::RenderWindow &window, Sprite Background, Sprite CommandoSprite[10][2], std::vector<rockets>& RocketVec, std::vector<bullets>& BulletVec, ship &spaceship, int grid2[10][2], vector<Sprite>LivesVec, vector<pickup>PickupVec) {

	window.draw(Background);
	for (int i = 0; i < LivesVec.size(); i++) {
		window.draw(LivesVec[i]);
	}
	for (int i = 0; i < RocketVec.size(); i++)
		RocketVec[i].draw(window);
	for (int i = 0; i < PickupVec.size(); i++)
		PickupVec[i].draw(window);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			if (grid2[i][j] > 0)
				window.draw(CommandoSprite[i][j]);
		}
	}
	for (int i = 0; i < BulletVec.size(); i++)
		BulletVec[i].draw(window);
	spaceship.draw(window);

}

void render(sf::RenderWindow &window, Sprite Background, Sprite ChickenSprite[10][4], std::vector<egg>& EggVec, std::vector<bullets>& BulletVec, ship &spaceship, bool grid[10][4], vector<Sprite>LivesVec,vector<pickup>PickupVec)
{
	
	window.draw(Background);
	for (int i = 0; i < LivesVec.size(); i++) {
		window.draw(LivesVec[i]);
	}
	for (int i = 0; i < EggVec.size(); i++)
		EggVec[i].draw(window);
	for (int i = 0; i < PickupVec.size(); i++)
		PickupVec[i].draw(window);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j])
			window.draw(ChickenSprite[i][j]);
		}
	}
	for (int i = 0; i < BulletVec.size(); i++)
		BulletVec[i].draw(window);
	spaceship.draw(window);

}
void Bossmovement(RenderWindow &window, Sprite BossSprite, float BossSpeed) {
	for (int i=0;i<2;i++){
		if ((BossSprite.getPosition().x + 250) >= 3000) {
			BossSpeed *= -1;
		}

		if ((BossSprite.getPosition().x) <= 0) {
			BossSpeed *= -1;
		}
	}

	for (int i = 0; i < 2; i++) {
		BossSprite.move(BossSpeed, 0);
	}

}
void movement2(RenderWindow &window, Sprite CommandoSprite[10][2], const Texture&commando, const Texture&commando2, float MoveSpeedX[4]) {

	for (int i = 0; i < 2; i++) {
		if ((CommandoSprite[9][i].getPosition().x + 250) >= 3000) {
			MoveSpeedX[i] *= -1;
		}
		if ((CommandoSprite[0][i].getPosition().x) <= 0) {
			MoveSpeedX[i] *= -1;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			CommandoSprite[i][j].move(MoveSpeedX[j], 0);
			if (MoveSpeedX[j] > 0)
				CommandoSprite[i][j].setTexture(commando2);
			else if (MoveSpeedX[j] < 0)
				CommandoSprite[i][j].setTexture(commando);
		}
	}


}
void movement(RenderWindow &window, Sprite ChickenSprite[10][4],const Texture&chicken, const Texture&chicken2, float MoveSpeed[4]) {

	
	for (int i = 0; i < 4; i++) {
		if ((ChickenSprite[9][i].getPosition().x + 250) >= 3000) {
			MoveSpeed[i] *= -1;
		}
		if ((ChickenSprite[0][i].getPosition().x) <= 0) {
			MoveSpeed[i] *= -1;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			ChickenSprite[i][j].move(MoveSpeed[j], 0);
			if (MoveSpeed[j] > 0)
				ChickenSprite[i][j].setTexture(chicken2);
			else if (MoveSpeed[j] < 0)
				ChickenSprite[i][j].setTexture(chicken);
		}
	}







}

int main() {
	//declarations
	pickup pickup1;
	Event event;
	RenderWindow window;
	Texture chicken, chicken2, background, heart, commando, commando2, BossTexture;
	Sprite ChickenSprite[10][4], Egg, Background, CommandoSprite[10][2], BossSprite;
	ship spaceship;
	Vector2f vector;
	std::vector<egg>EggVec;
	std::vector<Sprite>LivesVec;
	std::vector<bullets>BulletVec;
	std::vector<pickup>PickupVec;
	std::vector<rocks>RockVec;
	std::vector<rockets>RocketVec;
	std::vector<lazers>LazerVec;
	std::vector<cannons>CannonVec;
	bool LevelSwitch = true;

	SoundBuffer buffer, bufferDrop, bufferHit, bufferDead, bufferRocket, bufferDamage, bufferMenu;
	Sound bulletSound, dropSound, hitSound, deadSound, menuSound, rocketSound, damageSound;
	Sprite temp;
	Clock clock;
	Time elapsed;
	level level_state = one;
	bool grid[10][4], IsAllDead = true, IsAllDead2 = true;
	int grid2[10][2];
	int lives = 3, kills = 10, BossHP = 30, kills2 = 10;

	// Menu Variables

	menu menux(window.getSize().x, window.getSize().y);
	HighScore high;
	state game_state = menustate;
	int x, y;

	float WaveSpeed[4] = { 0.4,-0.4,0.4,-0.4 }, WaveSpeed2X[4] = { 0.5,-0.5 }, BossSpeed = 0;
	window.setFramerateLimit(60);
	srand(unsigned(time(NULL)));

	//loading textures
	if (!BossTexture.loadFromFile("images/boss.png"))
		std::cout << "failed to load boss";

	if (!background.loadFromFile("images/backgroundimage.jpg")) {
		std::cout << "loading error : background ";
	}
	Background.setTexture(background);
	Background.setScale(1.5625, 1.3889);

	if (!heart.loadFromFile("images/heart.png")) {
		cout << "loading error : heart";
	}
	for (int i = 0; i < 3; i++) {
		temp.setTexture(heart);
		temp.setScale(0.1, 0.1);
		temp.setPosition(2920 - i * 60, 0);
		LivesVec.push_back(temp);
	}
	if (!chicken.loadFromFile("images/chickenimage.png"))
		std::cout << "loading error";

	if (!chicken2.loadFromFile("images/chickenimage2.png"))
		std::cout << "loading error";

	if (!commando.loadFromFile("images/commandoimage.png"))
		std::cout << "loading error";

	if (!commando2.loadFromFile("images/commandoimage2.png"))
		std::cout << "loading error";

	//sounds
	if (!bufferMenu.loadFromFile("images/menusong.wav"))
		std::cout << "error loading : Menu";

	menuSound.setBuffer(bufferMenu);

	if (!buffer.loadFromFile("images/missileshot.wav"))
		std::cout << "error loading : Missile Sound";

	bulletSound.setBuffer(buffer);

	if (!bufferRocket.loadFromFile("images/rocket.wav"))
		std::cout << "error loading : Drop Rocket";

	rocketSound.setBuffer(bufferRocket);

	if (!bufferDamage.loadFromFile("images/damage.wav"))
		std::cout << "error loading : damage";

	damageSound.setBuffer(bufferDamage);

	if (!bufferDrop.loadFromFile("images/eggdropped.wav"))
		std::cout << "error loading : Drop Egg";

	dropSound.setBuffer(bufferDrop);

	if (!bufferHit.loadFromFile("images/hit.flac"))
		std::cout << "error loading : Hit";

	hitSound.setBuffer(bufferHit);

	if (!bufferDead.loadFromFile("images/chickendead.wav"))
		std::cout << "error loading: chicken dead";

	deadSound.setBuffer(bufferDead);

	//Initialize bool grid Grid 1 & 2

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i][j] = true;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			grid2[i][j] = 3;
		}
	}


	//game loop
	Initalize(window, ChickenSprite, chicken, chicken2);
	initialize2(window, CommandoSprite, commando, commando2);
	initializeboss(window, BossSprite, BossTexture);
	window.setKeyRepeatEnabled(false);
	while (window.isOpen()) {


		//Events
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Escape)
			{
				game_state = menustate;
			}

			if (game_state == game)
				spaceship.update(event);

			if (event.type == sf::Event::KeyPressed)
			{
				if (game_state == game)
					menuSound.pause();

				if (event.key.code == sf::Keyboard::Space)
				{
					bullets bullet;
					bullet.setPosition(spaceship.getPosition() + Vector2f(spaceship.getSize().width / 2.5, 0));
					BulletVec.push_back(bullet);
					bulletSound.play();

				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (game_state == menustate)
				{
					if (event.key.code == sf::Keyboard::S) {
						menuSound.setLoop(true);
						menuSound.play();
					}
					switch (event.key.code)
					{
					case Keyboard::Up:
						menux.up();
						break;
					case Keyboard::Down:
						menux.down();
						break;
					case Keyboard::Return:
					case Keyboard::Space:
						switch (menux.press_item())
						{
						case 0:
							game_state = game;
							clock.restart();
							break;
						case 1:
							game_state = highscore;
							break;
						case 2:
							window.close();
							break;
						}
						break;
					}
				}
			}
		}

		// Logic
		if (game_state == game)
		{		// Move Bullet
			for (int i = 0; i < BulletVec.size(); i++) {
				BulletVec[i].move();
			}
			// Erase Bullet
			for (int i = 0; i < BulletVec.size(); i++) {
				if (BulletVec[i].getPosition().y <= 0)
				{
					BulletVec.erase(BulletVec.begin() + i);
				}
			}
			if (level_state == one) { //////////////////////////////////////LEVEL ONE HERE ////////////////////////////////////////////////////////////////

				IsAllDead = true;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 4; j++) {
						if (grid[i][j] == true) {
							IsAllDead = false;
						}
					}
				}
				if (IsAllDead == true) {
					level_state = two;
					std::cout << "level";
				}

				//  Handle Collisions Chicken and Bullets
				for (int k = 0; k < BulletVec.size(); k++) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 4; j++) {
							if (grid[i][j])
								if (k < BulletVec.size())
									if (collision::BulletChickenCollide(ChickenSprite[i][j], BulletVec[k])) {
										BulletVec.erase(BulletVec.begin() + k);
										deadSound.play();
										grid[i][j] = false;
									}
						}
					}
				}
				//Handle collison ship and egg
				for (int i = 0; i < EggVec.size(); i++) {
					if (collision::EggShipCollide(EggVec[i], spaceship)) {
						EggVec.erase(EggVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}
				//Handle Collision Ship and Pickup
				for (int i = 0; i < PickupVec.size(); i++) {
					if (collision::PickupShipCollide(PickupVec[i], spaceship)) {

						PickupVec.erase(PickupVec.begin() + i);
						LivesVec.push_back(temp);
						lives++;
					}
				}

				//Handle Collision Ship and Chicken
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 4; j++) {
						if (collision::ChickenShipCollide(ChickenSprite[i][j], spaceship) && grid[i][j] == true) {
							LivesVec.pop_back();
							lives--;
							grid[i][j] = false;
						}
					}
				}
				//LOSS SCREEN 
				if (lives == 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()) * 1000) + 123);//ADD FORMULA HERE
				}
				//Random Pickup & control
				if (rand() % 8000 == 0)
				{
					int row = rand() % 10;
					int col = rand() % 4;
					if (grid[row][col] == true) {
						

						pickup1.setPosition(ChickenSprite[row][col].getPosition() + Vector2f(ChickenSprite[row][col].getGlobalBounds().width / 2, ChickenSprite[row][col].getGlobalBounds().height));
						PickupVec.push_back(pickup1);

					}

				}
				// Random Egg & control
				if (rand() % 200 == 0)
				{
					int row = rand() % 10;
					int col = rand() % 4;
					if (grid[row][col] == true) {
						egg egg1;

						egg1.setPosition(ChickenSprite[row][col].getPosition() + Vector2f(ChickenSprite[row][col].getGlobalBounds().width / 2, ChickenSprite[row][col].getGlobalBounds().height));
						EggVec.push_back(egg1);
						dropSound.play();
					}

				}
				// Erase Eggs
				for (int i = 0; i < EggVec.size(); i++) {
					if (EggVec[i].getPosition().y >= 1500)
					{
						EggVec.erase(EggVec.begin() + i);
					}
				}
				// Move Eggs
				for (int i = 0; i < EggVec.size(); i++) {

					EggVec[i].move();


				}
				//move pickups
				for (int i = 0; i < PickupVec.size(); i++) {

					PickupVec[i].move();

				}
				//erase pickups
				for (int i = 0; i < PickupVec.size(); i++) {
					if (PickupVec[i].getPosition().y >= 1500)
					{
						PickupVec.erase(PickupVec.begin() + i);
						//i--;
					}
				}
				movement(window, ChickenSprite, chicken, chicken2, WaveSpeed);
			}/////////////////////// LEVEL TWO HERE /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (level_state == two) {
				//switch level at max kills
				if (kills <= 0 ) {
					level_state = three;
				}
				//  Handle Collisions Rock and Bullets
				for (int k = 0; k < BulletVec.size(); k++) {
					for (int i = 0; i < RockVec.size(); i++) {
						if (k < BulletVec.size())
							if (collision::BulletRockCollide(BulletVec[k], RockVec[i])) {
								BulletVec.erase(BulletVec.begin() + k);
								RockVec.erase(RockVec.begin() + i);
								kills--;
								hitSound.play();


							}
					}
				}

				//Handle collison ship and rock
				for (int i = 0; i < RockVec.size(); i++) {
					if (collision::RockShipCollide(RockVec[i], spaceship)) {
						RockVec.erase(RockVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}

				//LOSS SCREEN 
				if (lives == 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()))*(lives * 1000) + 500);//ADD FORMULA HERE
				}

				// Random Rock & control
				if (rand() % 200 == 0)
				{
					int x = rand() % 750;

					rocks rock1;

					rock1.setPosition(x, 0);
					RockVec.push_back(rock1);


				}
				// Erase Rocks
				for (int i = 0; i < RockVec.size(); i++) {
					if (RockVec[i].getPosition().y >= 1500)
					{
						RockVec.erase(RockVec.begin() + i);
					}
				}
				// Move rocks
				for (int i = 0; i < RockVec.size(); i++) {

					RockVec[i].move();


				}
			}
			if (level_state == three) {/////////////// LEVEL THREE HERE////////////////////////////////////////////////////////////////////////////////////
				IsAllDead2 = true;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 2; j++) {
						if (grid2[i][j] > 0) {
							IsAllDead2 = false;
						}
					}
				}
				if (IsAllDead2 == true) {
					level_state = four;
					std::cout << "level";
				}

				//  Handle Collisions Commando and Bullets
				for (int k = 0; k < BulletVec.size(); k++) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 2; j++) {
							if (grid2[i][j])
								if (k < BulletVec.size())
									if (collision::BulletChickenCollide(CommandoSprite[i][j], BulletVec[k])) {
										BulletVec.erase(BulletVec.begin() + k);
										damageSound.play();
										grid2[i][j] --;
										if (grid2[i][j] == 0) {
											deadSound.play();
										}

									}
						}
					}
				}
				//Handle collison ship and rocket
				for (int i = 0; i < RocketVec.size(); i++) {
					if (collision::RocketShipCollide(RocketVec[i], spaceship)) {
						RocketVec.erase(RocketVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}
				//Handle Collision Ship and Pickup
				/*for (int i = 0; i < PickupVec.size(); i++) {
					if (collision::PickupShipCollide(PickupVec[i], spaceship)) {

						PickupVec.erase(PickupVec.begin() + i);
						LivesVec.push_back(temp);
						lives++;
					}
				}*/

				//Handle Collision Ship and Commando
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 2; j++) {
						if (collision::CommandoShipCollide(CommandoSprite[i][j], spaceship) && grid2[i][j] == true) {
							LivesVec.pop_back();
							lives--;
							grid[i][j] = false;
						}
					}
				}
				//LOSS SCREEN 
				if (lives == 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()) * 1000) + 123);//ADD FORMULA HERE
				}
				//Random Pickup & control
				/*if (rand() % 100000 == 0)
				{
					int row = rand() % 10;
					int col = rand() % 4;
					if (grid[row][col] == true) {
						pickup pickup1;

						pickup1.setPosition(ChickenSprite[row][col].getPosition() + Vector2f(ChickenSprite[row][col].getGlobalBounds().width / 2, ChickenSprite[row][col].getGlobalBounds().height));
						PickupVec.push_back(pickup1);

					}

				}*/
				// Random Rocket & control
				if (rand() % 100 == 0)
				{

					int row = rand() % 10;
					int col = rand() % 2;
					if (grid2[row][col] > 0) {
						rockets rocket1;

						rocket1.setPosition(CommandoSprite[row][col].getPosition() + Vector2f(CommandoSprite[row][col].getGlobalBounds().width / 2, CommandoSprite[row][col].getGlobalBounds().height));
						RocketVec.push_back(rocket1);
						rocketSound.play();
					}

				}
				// Erase Rockets
				for (int i = 0; i < RocketVec.size(); i++) {
					if (RocketVec[i].getPosition().y >= 1500)
					{
						RocketVec.erase(RocketVec.begin() + i);
					}
				}
				// Move Rockets
				for (int i = 0; i < RocketVec.size(); i++) {

					RocketVec[i].move();


				}
				//move pickups
				/*for (int i = 0; i < PickupVec.size(); i++) {

					PickupVec[i].move();

				}*/
				//erase pickups
				/*for (int i = 0; i < PickupVec.size(); i++) {
					if (PickupVec[i].getPosition().y >= 1500)
					{
						PickupVec.erase(PickupVec.begin() + i);
					}
				}*/
				movement2(window, CommandoSprite, commando, commando2, WaveSpeed2X);
			}
			if (level_state == four) {
				//switch level at max kills
				if (kills2 <= 0) {
					level_state = boss;
				}
				//  Handle Collisions Rock and Bullets
				for (int k = 0; k < BulletVec.size(); k++) {
					for (int i = 0; i < RockVec.size(); i++) {
						if (k < BulletVec.size())
							if (collision::BulletRockCollide(BulletVec[k], RockVec[i])) {
								BulletVec.erase(BulletVec.begin() + k);
								RockVec.erase(RockVec.begin() + i);
								kills2--;
								hitSound.play();


							}
					}
				}

				//Handle collison ship and rock
				for (int i = 0; i < RockVec.size(); i++) {
					if (collision::RockShipCollide(RockVec[i], spaceship)) {
						RockVec.erase(RockVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}

				//LOSS SCREEN 
				if (lives == 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()))*(lives * 1000) + 500);//ADD FORMULA HERE
				}

				// Random Rock & control
				if (rand() % 200 == 0)
				{
					int x = rand() % 750;

					rocks rock1;

					rock1.setPosition(x, 0);
					RockVec.push_back(rock1);


				}
				// Erase Rocks
				for (int i = 0; i < RockVec.size(); i++) {
					if (RockVec[i].getPosition().y >= 1500)
					{
						RockVec.erase(RockVec.begin() + i);
					}
				}
				// Move rocks
				for (int i = 0; i < RockVec.size(); i++) {

					RockVec[i].move();


				}
			}
			if (level_state == boss) {///////////////////////////////////////////////////////// BOSS HERE ///////////////////////////////////////////////////////////

				if (BossHP == 0 || lives <= 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()) * 1000) + 123);
					game_state = highscore;
				}

				//  Handle Collisions boss and Bullets
				for (int k = 0; k < BulletVec.size(); k++) {
								if (k < BulletVec.size())
									if (collision::BulletChickenCollide(BossSprite, BulletVec[k])) {
										BulletVec.erase(BulletVec.begin() + k);
										hitSound.play();
										BossHP--;
									}
				}
				//LOSS SCREEN 
				if (lives <= 0) {
					game_state = highscore;
					elapsed = clock.getElapsedTime();
					high.update((1 / (elapsed.asSeconds()) * 1000) + 123);//ADD FORMULA HERE
				}
				//Handle collison ship and lazer
				for (int i = 0; i < LazerVec.size(); i++) {
					if (collision::LazerShipCollide(LazerVec[i], spaceship)) {
						LazerVec.erase(LazerVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}
				//Handle collison ship and cannon
				for (int i = 0; i < CannonVec.size(); i++) {
					if (collision::CannonShipCollide(CannonVec[i], spaceship)) {
						CannonVec.erase(CannonVec.begin() + i);
						LivesVec.pop_back();
						hitSound.play();
						lives--;
					}
				}
				//Handle Collision Ship and Pickup
				/*for (int i = 0; i < PickupVec.size(); i++) {
					if (collision::PickupShipCollide(PickupVec[i], spaceship)) {

						PickupVec.erase(PickupVec.begin() + i);
						LivesVec.push_back(temp);
						lives++;
					}
				}*/

				//Handle Collision Ship and Boss
				
						if (collision::ChickenShipCollide(BossSprite, spaceship)) {
							lives=0;
						}
				
				//Random Pickup & control
				/*if (rand() % 100000 == 0)
				{
					int row = rand() % 10;
					int col = rand() % 4;
					if (grid[row][col] == true) {
						pickup pickup1;

						pickup1.setPosition(ChickenSprite[row][col].getPosition() + Vector2f(ChickenSprite[row][col].getGlobalBounds().width / 2, ChickenSprite[row][col].getGlobalBounds().height));
						PickupVec.push_back(pickup1);

					}

				}*/
				// Random Lazer & control
				if (rand() % 400 == 0)
				{
					int row = rand() % 10;
						lazers lazer1;
						lazer1.setPosition(890,580);
						LazerVec.push_back(lazer1);
						bulletSound.play();
					}
				//random cannon & control
				if (rand() % 400 == 0)
				{
					int row = rand() % 10;
					cannons cannon1;
					cannon1.setPosition(2000, 580);
					CannonVec.push_back(cannon1);
					bulletSound.play();
				}
				// Erase lazers
				for (int i = 0; i < LazerVec.size(); i++) {
					if (LazerVec[i].getPosition().y >= 1500)
					{
						LazerVec.erase(LazerVec.begin() + i);
					}
				}
				// Erase cannons
				for (int i = 0; i < CannonVec.size(); i++) {
					if (CannonVec[i].getPosition().y >= 1500)
					{
						CannonVec.erase(CannonVec.begin() + i);
					}
				}
				// Move cannons
				for (int i = 0; i < CannonVec.size(); i++) {
					CannonVec[i].move();
				}
				// Move lazers
				for (int i = 0; i < LazerVec.size(); i++) {
					LazerVec[i].move();
				}
				}
				
				//move pickups
				/*for (int i = 0; i < PickupVec.size(); i++) {
					PickupVec[i].move();

				}*/
				//erase pickups
				/*for (int i = 0; i < PickupVec.size(); i++) {
					if (PickupVec[i].getPosition().y >= 1500)
					{
						PickupVec.erase(PickupVec.begin() + i);
					}
				}*/
				Bossmovement(window, BossSprite,BossSpeed);
			}


		
	

   // Drawing
		window.clear();
		if (game_state == game)
		{
			if (level_state == one) {
				render(window, Background, ChickenSprite, EggVec, BulletVec, spaceship, grid, LivesVec, PickupVec);
			}
			else if (level_state == two || level_state == four) {
				render2(window, Background, RockVec, BulletVec, spaceship, LivesVec);
			}
			else if (level_state == three) {
				render3(window, Background, CommandoSprite, RocketVec, BulletVec, spaceship, grid2, LivesVec, PickupVec);
			}
			else if (level_state == boss) {
				renderboss(window, Background, BossSprite, BulletVec,CannonVec, LazerVec, spaceship, LivesVec);
			}
		}

		else if (game_state == menustate) {
			menux.draw(window);

		}

		else if (game_state == highscore)
			high.draw(window);


		window.display();




	}
	return EXIT_SUCCESS;
}


