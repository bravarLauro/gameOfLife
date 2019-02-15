//============================================================================
// Name        : gameOfLife.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <windows.h>
#include <stdlib.h>

#include "Lifeform.h"

lifeform::Lifeform create_glider(int size, int row, int column){
	lifeform::Lifeform glider = lifeform::Lifeform(size, size);
	glider.create_life(row, column);
	glider.create_life(row, column+2);
	glider.create_life(row+1, column+1);
	glider.create_life(row+1, column+2);
	glider.create_life(row+2, column+1);
	return glider;
}

lifeform::Lifeform create_small_explosion(int size, int row, int column){
	lifeform::Lifeform small_explosion = lifeform::Lifeform(size, size);
	small_explosion.create_life(row, column+1);
	small_explosion.create_life(row+1, column);
	small_explosion.create_life(row+1, column+1);
	small_explosion.create_life(row+1, column+2);
	small_explosion.create_life(row+2, column);
	small_explosion.create_life(row+2, column+2);
	small_explosion.create_life(row+3, column+1);
	return small_explosion;
}

int main() {
	int size = 15;
	int years = 20;
	lifeform::Lifeform glider = create_glider(size, 0, 0);
	glider.print_state();
	for (int ii = 0; ii < years; ii++){
		glider.age(1);
		glider.print_state();
		Sleep(1000);
	}

	lifeform::Lifeform small_explosion = create_small_explosion(size, 7, 7);
	small_explosion.print_state();

	for (int ii = 0; ii < years; ii++){
		small_explosion.age(1);
		small_explosion.print_state();
		Sleep(1000);
	}
	return 0;

}


