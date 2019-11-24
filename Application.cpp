#include <iostream>
#include <Windows.h>
class Game
{
public:

	bool GameOver;

	char Response;

	int unsoldInventory;
	int paperclips;
	int wire;
	float budget;
	float pricePerPaperclip;
	float wirePrice;
	float publicDemand;

	Game()
	{
		GameOver = true;
		Response = NULL;
		paperclips = 50;
		wire = 100;
		budget = 5.f;
		pricePerPaperclip = 0.25f;
		wirePrice = 10.f;
		publicDemand = 25.f;
		unsoldInventory = 0;
	}

	~Game()
	{}

	void Input()
	{
		switch (Response)
		{
		case 'q':
			GameOver = true;
			break;
		case 'w':
			wire++;
			budget -= wirePrice;
			break;
		case 'r':
			pricePerPaperclip += 0.01;
			break;
		case 'l':
			pricePerPaperclip -= 0.01;
			break;
		case 'p':
			paperclips++;
			wire -= 2;
			budget += pricePerPaperclip;
			break;
		}

		if (budget < 0.f || wire <= 0)
		{
			GameOver = true;
		}
	}

	void MainMenu()
	{
		while (GameOver == false)
		{
			Input();
			system("Cls");
			std::cout << "PAPERCLIPS!" << std::endl << paperclips << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "BUSINESS" << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "BUDGET: $" << budget << std::endl;
			std::cout << "PRICE PER PAPERCLIP: $" << pricePerPaperclip << std::endl;
			std::cout << "UNSOLD INVENTORY: " << unsoldInventory << std::endl;
			std::cout << "PUBLIC DEMAND: " << publicDemand << "%" << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "MANUFACTURING" << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "WIRE: " << wire << std::endl << "WIRE COST: $" << wirePrice << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "Press P to make more Paperclips\nPress W to make more Wire\nPress L to lower price per paperclip\nPress R to raise price per paperclip\nPress Q to quit" << std::endl;
			for (int i = 0; i < 20; i++)
			{
				std::cout << "~";
			}
			std::cout << std::endl << "Input: ";
			std::cin >> Response;
		}
	}
};

int main()
{
	Game* game = new Game();
	game->GameOver = false;
	game->MainMenu();
	delete game;
	return 0;
}
