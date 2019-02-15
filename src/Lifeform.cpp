/*
 * Lifeform.cpp
 *
 *  Created on: 15 feb. 2019
 *      Author: Lauro
 */

#include "Lifeform.h"

#include <iostream>
using namespace std;
namespace lifeform {

Lifeform::Lifeform(const int width, const int length, string reproductive_strategy) {
	this->reproductive_strategy = "test";
	this->length = length;
	this->width = width;
	this->state = new bool*[length];
	for (int ii = 0; ii < length; ii++){
		this->state[ii] = new bool[width];
	}
	this->start();
}

Lifeform::Lifeform(const int width, const int length) {
	this->reproductive_strategy = "test";
	this->length = length;
	this->width = width;
	this->state = new bool*[length];
	for (int ii = 0; ii < length; ii++){
		this->state[ii] = new bool[width];
	}
	this->start();
}

void Lifeform::start() {
	for (int ii = 0; ii < length; ii++){
		for (int jj = 0; jj < width; jj++){
			state[ii][jj] = false;
		}
	}
}

void Lifeform::print_state() {
	string barrier = "";
	for (int ii = 0; ii < width; ii++){
		barrier+="o";
	}
	cout<<barrier<<endl;
	for (int ii = 0; ii < length; ii++){
		for (int jj = 0; jj < width; jj++){
			if(state[ii][jj] == true){
				cout<<"*";
			}
			else{
				cout<<"-";
			}
		}
		cout<<endl;
	}
	cout<<barrier<<endl;
}

void Lifeform::create_life(int row, int column){
	this->state[row][column] = true;
}

void Lifeform::destroy_life(int row, int column){
	this->state[row][column] = false;
}

void Lifeform::age(int years){
	int neighbors;
	bool** aux_state = new bool*[length];
	for (int ii = 0; ii < length; ii++){
		aux_state[ii] = new bool[width];
	}
	for (int year = 0; year < years; year++){
		for (int ii = 0; ii < length; ii++){
			for (int jj = 0; jj < width; jj++){
				neighbors = count_neighbors(ii, jj);
				if (state[ii][jj] == true){
					if (neighbors < 2 || neighbors > 3){
						aux_state[ii][jj] = false;
					}
					else{
						aux_state[ii][jj] = true;
					}
				}
				else {
					if (neighbors == 3){
						aux_state[ii][jj] = true;
					}
					else {
						aux_state[ii][jj] = false;
					}
				}
			}
		}
	}

	change_state(aux_state);
}

int Lifeform::count_neighbors(int row, int column){
	int neighbors = 0;
	if(row != 0 && row != length-1 && column != 0 && column != width-1){
		if (state[row+1][column] == true)
		{
			neighbors++;
		}
		if (state[row-1][column] == true)
		{
			neighbors++;
		}
		if (state[row][column+1] == true)
		{
			neighbors++;
		}
		if (state[row][column-1] == true)
		{
			neighbors++;
		}
		if (state[row+1][column+1] == true)
		{
			neighbors++;
		}
		if (state[row-1][column+1] == true)
		{
			neighbors++;
		}
		if (state[row+1][column-1] == true)
		{
			neighbors++;
		}
		if (state[row-1][column-1] == true)
		{
			neighbors++;
		}
	}
	else{
		if(row == 0){
			if(column == 0){
				if (state[row+1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column+1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column+1] == true)
				{
					neighbors++;
				}
			}
			else if(column == width-1){
				if (state[row+1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column-1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column-1] == true)
				{
					neighbors++;
				}
			}
			else{
				if (state[row+1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column+1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column+1] == true)
				{
					neighbors++;
				}
				if (state[row][column-1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column-1] == true)
				{
					neighbors++;
				}
			}
		}
		else if (row == length-1){
			if(column == 0){
				if (state[row-1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column+1] == true)
				{
					neighbors++;
				}
				if (state[row-1][column+1] == true)
				{
					neighbors++;
				}
			}
			else if(column == width-1){
				if (state[row-1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column-1] == true)
				{
					neighbors++;
				}
				if (state[row-1][column-1] == true)
				{
					neighbors++;
				}
			}
			else{
				if (state[row-1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column+1] == true)
				{
					neighbors++;
				}
				if (state[row-1][column+1] == true)
				{
					neighbors++;
				}
				if (state[row][column-1] == true)
				{
					neighbors++;
				}
				if (state[row-1][column-1] == true)
				{
					neighbors++;
				}
			}
		}
		else{
			if(column == 0){
				if (state[row-1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column+1] == true)
				{
					neighbors++;
				}
				if (state[row-1][column+1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column] == true)
				{
					neighbors++;
				}
				if (state[row+1][column+1] == true)
				{
					neighbors++;
				}
			}
			else if(column == width-1){
				if (state[row-1][column] == true)
				{
					neighbors++;
				}
				if (state[row][column-1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column-1] == true)
				{
					neighbors++;
				}
				if (state[row+1][column] == true)
				{
					neighbors++;
				}
				if (state[row-1][column-1] == true)
				{
					neighbors++;
				}
			}
		}

	}
	return neighbors;
}

void Lifeform::change_state(bool** aux_state){
	for (int ii = 0; ii < length; ii++){
		for (int jj = 0; jj < width; jj++){
			bool this_element = aux_state[ii][jj];
			state[ii][jj] = this_element;
		}
	}
}

} /* namespace lifeform */
