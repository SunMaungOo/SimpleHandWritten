/*
 * NeuralNetwork.h
 *
 *  Created on: Jul 17, 2017
 *      Author: SunMaungOo
 */

#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "Matrix.h"

#include <vector>
#include <string>
#include <map>
#include <algorithm>

/**
 * Based on "Visual Character Recognition using Artifical Neural Networks"
 * by Shashank Araokar,
 * MGM’s College of Engineering and
 * Technology
 * University of Mumbai, India
 *
 */
class NeuralNetwork {
public:
	NeuralNetwork(int column_count,int row_count,std::vector<std::string>& labels);

	void feed_forward(const Matrix& input_matrix);

	std::vector<std::string> get_output();

	//label should be included in labels we have set in the constructor

	void train(const Matrix& input_matrix,const std::string& label);

	void print_probability();

private:

	//For every data in the matrix
	//if the data is 1,set it to 1
	//if the data is 0,set it to -1
	Matrix create_data_matrix(const Matrix& input_matrix);

	double calculate_canidate_score(const Matrix& data_matrix,Matrix& weight_matrix);

	double calculate_ideal_weight_model_score(Matrix& weight_matrix);

	double calculate_recognition_quotient(const Matrix& data_matrix,Matrix& weight_matrix);

	double find_max_value();

private:

	//std::map<label,Weight of the label>

	std::map<std::string,Matrix> plabel_weight;

	//std::map<label,probability that it will be a label>

	std::map<std::string,double> poutput;

};

#endif /* NEURALNETWORK_H_ */
