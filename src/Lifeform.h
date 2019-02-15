/*
 * Lifeform.h
 *
 *  Created on: 15 feb. 2019
 *      Author: Lauro
 */
#include <iostream>
#ifndef GENERATION_H_
#define GENERATION_H_

using namespace std;
namespace lifeform {

class Lifeform {
public:
	// Attributes
	int width;
	int length;
	string reproductive_strategy;
	bool **state;
	// Methods
	Lifeform(int width, int length, string reproductive_strategy);
	Lifeform(int width, int length);
	void print_state();
	void create_life(int row, int column);
	void destroy_life(int row, int column);
	void age(int years);
private:
	void start();
	int count_neighbors(int row, int column);
	void change_state(bool** aux_state);
};

} /* namespace lifeform */

#endif /* GENERATION_H_ */
