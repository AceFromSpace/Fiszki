#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Fiszka
{
public:
	Fiszka(string pol, string eng);
	~Fiszka();

private:
	string word_polish;
	string word_english;
	int points; //if points == 5 add to archive
	bool is_in_archive;

};

