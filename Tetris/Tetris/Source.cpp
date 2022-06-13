#include <iostream>
#include "Tetris.h"
int main()
{
	Tetris* tetris = new Tetris();

	tetris->InitTetris();

	tetris->RunPolling();

	delete tetris;
}