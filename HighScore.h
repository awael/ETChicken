#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#ifndef HighScore_h
#define HighScore_h
using namespace std;
using namespace sf;
class HighScore
{

private:
	vector<string> scorearray;
	vector<Text> scoretext;
	Text title_hs, title_n, title_s;
	Font f;
	string path = "input.txt";
	Sprite BackgroundSprite;
	Texture BackgroundTexture;

public:
	HighScore() {

		if (!f.loadFromFile("digital-7.ttf"))
			std::cout << "font not loaded";

		if (!BackgroundTexture.loadFromFile("images/backgroundimage.jpg")) {
			std::cout << "loading error : background ";
		}
		
		BackgroundSprite.setTexture(BackgroundTexture);
		int x = 1000, d = 400;
		title_hs.setFont(f);
		title_hs.setFillColor(Color::White);
		title_hs.setString("High Scores");
		title_hs.setPosition(Vector2f(1300, 100));
		title_hs.setScale(Vector2f(5.0f, 5.0f));

	
		title_s.setFont(f);
		title_s.setFillColor(Color::White);
		title_s.setString("Score");
		title_s.setPosition(Vector2f(1475, 400));
		title_s.setScale(Vector2f(3.0f, 3.0f));

		/*title_s.setFont(f);
		title_s.setFillColor(Color::White);
		title_s.setString("Score");
		title_s.setPosition(Vector2f(1800, 400));
		title_s.setScale(Vector2f(3.0f, 3.0f));*/
		
		loadfile(path);
		/*for (int y = 0; y < nameatrray.size(); y++)
		{
			nametext[y].setFont(f);
			nametext[y].setFillColor(Color::Green);
			nametext[y].setString(nameatrray[y]);
			nametext[y].setPosition(Vector2f(150, x + 30));
			nametext[y].setScale(Vector2f(3.0f, 3.0f));
		}*/

		

	}
	void update(long score) {
		scorearray.push_back(to_string(score));
		Text temp;
		temp.setFont(f);
		temp.setFillColor(Color::Yellow);
		temp.setString(to_string(score));
		temp.setScale(Vector2f(3.0f, 3.0f));
		scoretext.push_back(temp);

	}
	void update(string score) {
		scorearray.push_back(score);
		Text temp;
		temp.setFont(f);
		temp.setFillColor(Color::Yellow);
		temp.setString(score);
		temp.setScale(Vector2f(3.0f, 3.0f));
		scoretext.push_back(temp);

	}
	void loadfile(string path)
	{
		ifstream input(path);
		string tempint;
		if (!input.fail())
		{
			//input >> temp;
			input >> tempint;
			while (!input.eof())
			{
				update(tempint);
				input >> tempint;

			}
		}	
		input.close();
		sort();
	}
	void sort()
	{
		for (int i = 0; i < scorearray.size(); i++)
			for (int j = 0; j < scorearray.size(); j++)
				if (scorearray[i] < scorearray[j])
					swap(scorearray[i], scorearray[j]);
	}
	void draw(RenderWindow & window)
	{
		BackgroundSprite.setScale(1.5625, 1.3889);
		window.draw(BackgroundSprite);
		window.draw(title_hs);
		window.draw(title_n);
		window.draw(title_s);
		//std::cout << "phase 1";
		
		for (int x = 0; x < scoretext.size(); x++) {
			scoretext[x].setPosition(Vector2f(1475, x * 100 + 500));
			window.draw(scoretext[x]);
			//std::cout << ".";
		}
	
	}

};
#endif