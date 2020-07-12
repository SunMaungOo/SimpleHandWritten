/*
 * Matrix.h
 *
 *  Created on: Jul 17, 2017
 *      Author: SunMaungOo
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "gsl/gsl"

class Matrix
{
public:

	Matrix(const int& column_count,const int& row_count);

	//copy constructor

	Matrix(const Matrix& data);

	//move constructor

	Matrix(Matrix&& data);

	Matrix& operator=(const Matrix& data);

	Matrix& operator=(Matrix&& data);

	virtual ~Matrix();

	void set(const int& data,const int& column_index,const int& row_index);

	int at(const int& column_index,const int& row_index) const;

	int get_column_count() const;

	int get_row_count() const;

private:

	int pcolumn_count;

	int prow_count;

	gsl::owner<int**> pdata;

};



#endif /* MATRIX_H_ */
