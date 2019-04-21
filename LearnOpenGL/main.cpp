#include <iostream>
#include <Graphics.hpp>
#include <Window/Keyboard.hpp>
#include <Windows.h>
#include <Audio.hpp>
#include <Window/Mouse.hpp>


	sf::Texture background,buttonTexture;
	sf::Vector2f targetSize(1680.0f, 1050.0f);
	sf::Texture cursor;
	sf::Sprite cursorSprite,bg;
	sf::Music music;
	sf::SoundBuffer sfxBuffer;
	sf::Sound sfx;
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Communist Propaganda", sf::Style::Fullscreen);



	void loadTexture(const std::string filename ) {
		if (!buttonTexture.loadFromFile("Images/" + filename)){
			::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			std::cout << " There was a problem getting the texture \n";
			system("pause");
			return;
			
		}
	
	
	}

  
void loadBackground(const std::string filename) {
		if (!background.loadFromFile("Backgrounds/" + filename)) {
			::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			std::cout << " There was a problem getting the background. \n";
			system("pause");
			return;
		}

}


	void playMusic(const std::string filename) {
		if (!music.openFromFile("Audio/" + filename)) {
			::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			std::cout << " There was a problem getting the song. \n";
			system("pause");
			return;
		}
		music.play();
	}

	void playSFX(const std::string filename) {
		if (!sfxBuffer.loadFromFile("SFX/" + filename)) {
			::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			std::cout << " There was a problem getting the sound effect. \n";
			system("pause");
		}
		sfx.play();
	}

	void makeButton(std::string* shape_id, float x_size, float y_size, float x_pos, float y_pos,const color) {

		sf::RectangleShape id;
		id.setSize(sf::Vector2f(x_size, y_size));
		id.setPosition(sf::Vector2f(x_pos, y_pos));
		id.sf::Shape::setFillColor(color);
		id.draw();
	}

	

int main() {  
	


	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	

	

	

		
	

	if (!cursor.loadFromFile("cursor.png")) {
		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
		std::cout << " There was a problem getting the cursor \n";
		system("pause");
		return -1;
	}

	cursorSprite.setTexture(cursor);
	sfx.setBuffer(sfxBuffer);
	playMusic("ussr.wav");
	loadBackground("ussr_anime.png");

bg.setTexture(background);
bg.setScale(targetSize.x / bg.getLocalBounds().width,targetSize.y / bg.getLocalBounds().height);

	while (window.isOpen())

	{
		sf::Event event;
		
		SetCursor(false);
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				music.stop();
				playSFX("baka.wav");
				DWORD duration = sfxBuffer.getDuration().asMilliseconds();
				Sleep(duration);
				window.close();
			}
				
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			music.pause();
			playSFX("baka.wav");
			DWORD duration = sfxBuffer.getDuration().asMilliseconds();
			Sleep(duration);
			music.play();
		}





		window.clear();

		window.draw(bg);

		cursorSprite.setPosition(event.mouseMove.x, event.mouseMove.y);

		window.draw(cursorSprite);

		window.display();

	}

	return 0;
}

