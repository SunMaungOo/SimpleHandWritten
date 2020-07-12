/*
 * NeuralNetwork.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: SunMaungOo
 */

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int column_count,int row_count,std::vector<std::string>& labels)
{
	for(size_t index=0;index<labels.size();index++) {

		plabel_weight.insert(std::pair<std::string,Matrix>(labels[index],Matrix(column_count,row_count)));

	}
}

void NeuralNetwork::feed_forward(const Matrix& input_matrix)
{
	poutput.clear();

	Matrix data_matrix=std::move(create_data_matrix(input_matrix));

	for(std::pair<std::string,Matrix> entry : plabel_weight) {

		poutput.insert(std::pair<std::string,double>(entry.first,calculate_recognition_quotient(data_matrix,entry.second)));

	}


}

std::vector<std::string> NeuralNetwork::get_output()
{
	std::vector<std::string> output_vec;

	double max_value=find_max_value();

	for(std::pair<std::string,double> entry : poutput) {

		if(entry.second==max_value) {

			output_vec.push_back(entry.first);

		}
	}

	return output_vec;
}

double NeuralNetwork::find_max_value()
{
	bool first_time=false;

	int max_value=0;

	for(std::pair<std::string,double> entry : poutput) {

		if(first_time) {

			first_time=false;

			max_value=entry.second;

		}else {

			if(entry.second>max_value) {

				max_value=entry.second;

			}
		}
	}

	return max_value;
}


void NeuralNetwork::train(const Matrix& input_matrix,const std::string& label)
{
	Matrix data_matrix=std::move(create_data_matrix(input_matrix));

	//because not to change plabel_weight at after the constructor
	//since we take the address as reference when the plabel_weight changes
	//the address may be invalid

	Matrix& weight_matrix=plabel_weight.at(label);

	int row_count=data_matrix.get_row_count();

	int column_count=data_matrix.get_column_count();

	for(auto i=0;i<row_count;i++) {

		for(auto j=0;j<column_count;j++) {

			weight_matrix.set((weight_matrix.at(i,j)+data_matrix.at(i,j)),i,j);

		}

	}

}

Matrix NeuralNetwork::create_data_matrix(const Matrix& input_matrix)
{
	Matrix data_matrix(input_matrix);

	int row_count=data_matrix.get_row_count();

	int column_count=data_matrix.get_column_count();

	for(auto i=0;i<row_count;i++) {

		for(auto j=0;j<column_count;j++) {

			if(data_matrix.at(i,j)==1) {

				data_matrix.set(1,i,j);

			}else if(data_matrix.at(i,j)==0) {

				data_matrix.set(-1,i,j);

			}

		}

	}


	return data_matrix;
}

double NeuralNetwork::calculate_canidate_score(const Matrix& data_matrix,Matrix& weight_matrix)
{
	double canidate_score=0;

	int row_count=data_matrix.get_row_count();

	int column_count=data_matrix.get_column_count();

	for(auto i=0;i<row_count;i++) {

		for(auto j=0;j<column_count;j++) {

			canidate_score=canidate_score+weight_matrix.at(i,j) * data_matrix.at(i,j);

		}

	}

	return canidate_score;
}

double NeuralNetwork::calculate_ideal_weight_model_score(Matrix& weight_matrix)
{
	double ideal_weight_model_score=0;

	int row_count=weight_matrix.get_row_count();

	int column_count=weight_matrix.get_column_count();

	for(auto i=0;i<row_count;i++) {

		for(auto j=0;j<column_count;j++) {

			if(weight_matrix.at(i,j)>0) {

				ideal_weight_model_score=ideal_weight_model_score+weight_matrix.at(i,j);

			}

		}

	}

	return ideal_weight_model_score;

}

double NeuralNetwork::calculate_recognition_quotient(const Matrix& data_matrix,Matrix& weight_matrix)
{
	return calculate_canidate_score(data_matrix,weight_matrix)/calculate_ideal_weight_model_score(weight_matrix);
}

void NeuralNetwork::print_probability()
{
	for(std::pair<std::string,double> entry : poutput) {

		std::cout << "Probability of being " << entry.first << " is:" << entry.second << std::endl;
	}
}


