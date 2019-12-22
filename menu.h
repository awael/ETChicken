#include "SFML\Graphics.hpp"
#define max 3
using namespace sf;
#ifndef menu_h
#define menu_h
class menu
{
public:
	menu(float width, float length)
	{
		if (!texture1.loadFromFile("space.jpg"))
		{
			std::cout << "image not loaded";
			system("pause");
		}
		if (!texture3.loadFromFile("images/menuship.png"))
		{
			std::cout << "image not loaded";
			system("pause");
		}
		if (!texture2.loadFromFile("chicken.png"))
		{
			std::cout << "image not loaded";
			system("pause");
		}
		if (!font.loadFromFile("images/SpaceMono.ttf"))
			std::cout << "font not loaded";

		if (!ToggleBuffer.loadFromFile("images/toggle.wav"))
			std::cout << "error loading : toggle Sound";

		sprite1.setTexture(texture1);
		sprite2.setTexture(texture2);
		sprite3.setTexture(texture3);
		sprite1.setScale(Vector2f(1.5625f, 1.3889f)); 
		sprite2.setPosition(Vector2f(300, 400));
		sprite2.setScale(3, 3);
		sprite3.setPosition(2000, 650);
		sprite3.setScale(3, 3);
		ToggleSound.setBuffer(ToggleBuffer);
		
		title.setFont(font);
		title.setFillColor(Color::White);
		title.setString("(Esc) to pause                  MAIN MENU                   (S) for sound");
		title.setPosition(Vector2f(200 , 100));
		title.setScale(Vector2f(2.0f, 2.0f));

		text[0].setFont(font);
		text[0].setFillColor(Color::Red);
		text[0].setString("Start");
		text[0].setPosition(Vector2f(2600, 400));
		text[0].setScale(Vector2f(2.0f, 2.0f));

		text[1].setFont(font);
		text[1].setFillColor(Color::White);
		text[1].setString("High Scores");
		text[1].setPosition(Vector2f(2350, 550));
		text[1].setScale(Vector2f(2.0f, 2.0f));

		text[2].setFont(font);
		text[2].setFillColor(Color::White);
		text[2].setString("Exit");
		text[2].setPosition(Vector2f(2500, 700));
		text[2].setScale(Vector2f(2.0f, 2.0f));

		choose_item_index = 0;
	}
	void draw(RenderWindow & window)
	{
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(title);
		for (int i = 0; i < max; i++)
			window.draw(text[i]);
	}
	~menu()
	{
	}
	void up()
	{
		ToggleSound.play();

		if (choose_item_index - 1 >= 0)
		{
			text[choose_item_index].setFillColor(Color::White);
			choose_item_index--;
			text[choose_item_index].setFillColor(Color::Red);
		}
	}
	void down()
	{
		ToggleSound.play();

		if (choose_item_index + 1 < max)
		{
			text[choose_item_index].setFillColor(Color::White);
			choose_item_index++;
			text[choose_item_index].setFillColor(Color::Red);
		}
	}
	int press_item() { return choose_item_index; }
private:
	int choose_item_index;
	Font font;
	Texture texture1, texture2, texture3;
	Sprite sprite1, sprite2, sprite3;
	Text text[max], title;
	Sound ToggleSound;
	SoundBuffer ToggleBuffer;

};
#endif


