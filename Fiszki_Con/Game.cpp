#include "Game.h"



Game::Game()
{
	string file_name ="fiszki.txt" ;
	number_of_words = get_number_of_words(file_name);

	tab_words = new string*[number_of_words];
	for (int i = 0; i < number_of_words; i++)tab_words[i] = new string[2];
	tab_points = new int[number_of_words];
	tab_archive = new bool[number_of_words];
	fill_tables(file_name, number_of_words);
	
	mode = 0;
	times = 5;

}


Game::~Game()
{
}

void Game::show()
{
	for (int i = 0; i < number_of_words; i++)
	{
		cout << tab_words[i][0] << " " << tab_words[i][1] << " " << tab_points[i] << " " << tab_archive[i] << endl;
	}
}

void Game::new_game()
{
	prephase();
}

void Game::prephase()
{
	cout << "Type: " << endl;
	cout << "p - play new game " << endl;
	cout << "s - show all words and points" << endl;
	cout << "o - options" << endl;
	cout << "e - exit" << endl;
	
	bool flag = false;
	char choose;
	do
	{
			
			cin >> choose;

			switch (choose)
			{
				case 'p':
				{
					play();
				}break;
				case 's':
				{
					show();
				}break;
				case 'o':
				{
					options();
				}break;
				case 'e':
				{
					cout << "Bye, bye" << endl;
				}break;

				default:
				{
					cout << "choose something" << endl;
				}break;
			}
	}while (choose=='e');
}

void Game::play()
{
	cout << "Welcome in the game" << endl;
	cout << "c - come back to menu" << endl;
}

void Game::options()
{
	cout << "l - Chose language of visible world" << endl;
	cout << "t - Chose number of correct answers" << endl;

	bool flag = false;
	do
	{
		char choose;
		cin >> choose;

		switch (choose)
		{
		case 'l':
		{
			opt_language();
		}break;
		case 't':
		{
			opt_times();
		}break;
		default:
		{
			cout << "choose something" << endl;
			flag = true;
		}break;

		}
	} while (flag);
}

void Game::opt_language()
{
	cout << "e - the visible world will be english world" << endl;
	cout << "p - the visible world will be polish world" << endl;
	bool flag = false;
	do
	{
		char choose;
		cin >> choose;

		switch (choose)
		{
		case 'e':
		{
			mode = 0;
			cout << "English is set" << endl;
		}break;
		case 'p':
		{
			mode = 1;
			cout << "Polish is set" << endl;
		}break;
		default:
		{
			cout << "choose something" << endl;
			flag = true;
		}break;

		}
	} while (flag);
}

void Game::opt_times()
{
	cin >> times;
	cout << "Now you need " << times << "correct answers to learn new word" << endl;
}

int Game::get_number_of_words(string file_name)
{
	std::fstream file;
	file.open(file_name, std::ios::in);

	if (file.good() != true)
	{
		cout << "Can't find the file" << endl;
		getchar();
	}
	int i = 0;
	char ch[255];
	while (!file.eof())
	{
		file.getline(ch, 255);
		i++;
	}
	file.close();
	return i;
}

void Game::fill_tables(string file_name,int size_tab)
{
	std::fstream file;
	file.open(file_name, std::ios::in);
	char ch[255];
	
	for (int i = 0; i < size_tab; i++)
	{
		file.getline(ch, 255);
		string temp[4];
		int j = 0;
		
		for (int i = 0; i < 100; i++)
			{		
				if(ch[i]!='-')temp[j] += ch[i];
				else
				{	
					j++;
					if (j > 3)break;
				}
			}
		tab_words[i][0] = temp[0];
		tab_words[i][1] = temp[1];
		tab_points[i] = atoi(temp[2].c_str());
		tab_archive[i] = atoi(temp[3].c_str());
		}
}
