#pragma once

#include <string>
using namespace std;

class Game
{
public:	
	Game(string t) { title = t; };
	virtual void play() = 0;
private:
	string title;
};