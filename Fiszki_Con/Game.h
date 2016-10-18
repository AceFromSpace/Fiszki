#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void show();
	void show_archive();
	void add_new ();
	void new_game();
	

private:

	int number_of_words;
	bool mode;// 0- eng-pol | 1 - pol-eng
	int times;
	int get_number_of_words(string fi_name);
	void fill_tables(string fi_name,int size);
	void add_to_archive();
	string** tab_words;//eng pol
	int* tab_points;
	bool* tab_archive;
	void prephase();
	void play();
	void options();
	void opt_language();
	void opt_times();
	

};

