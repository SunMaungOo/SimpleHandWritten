/*
 * Main.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: SunMaungOo
 */

#include "NeuralNetwork.h"

#include <iostream>
#include <vector>
#include <string>


int main()
{
	int row_count=6;

	int column_count=6;

	const int BLANK_SQUARE=0;

	const int WRITTEN_SQUARE=1;


	std::vector<std::string> labels;
	labels.push_back("A");
	labels.push_back("B");
	labels.push_back("C");

	NeuralNetwork network(column_count,row_count,labels);

	Matrix a_matrix(column_count,row_count);
	a_matrix.set(WRITTEN_SQUARE,0,0);
	a_matrix.set(WRITTEN_SQUARE,0,1);
	a_matrix.set(WRITTEN_SQUARE,0,2);

	network.train(a_matrix,"A");
	network.train(a_matrix,"A");
	network.train(a_matrix,"A");

	network.feed_forward(a_matrix);

	network.print_probability();

	Matrix b_matrix(column_count,row_count);
	b_matrix.set(WRITTEN_SQUARE,0,1);

	network.train(b_matrix,"B");

	network.feed_forward(b_matrix);

	std::vector<std::string> outputs=std::move(network.get_output());

	for(std::string data : outputs) {

		std::cout << data << std::endl;

	}

	network.print_probability();

	std::cin.get();

	return 0;
}


