/*
 * Matrix.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: SunMaungOo
 */

#include "Matrix.h"

Matrix::Matrix(const int& column_count,const int& row_count)
:pcolumn_count{column_count},
 prow_count{row_count}
{
	//column_count = x
	// row_count = y

	pdata=new int*[row_count];

	for(auto i=0;i<row_count;i++) {

		pdata[i]=new int[column_count];

		for(auto j=0;j<column_count;j++) {

			pdata[i][j]=0;

		}

	}
}

Matrix::Matrix(const Matrix& data)
:pcolumn_count{data.pcolumn_count},
 prow_count{data.prow_count}
{
	pdata=new int*[prow_count];

	for(auto i=0;i<prow_count;i++) {

		pdata[i]=new int[pcolumn_count];

		for(auto j=0;j<pcolumn_count;j++) {

			pdata[i][j]=data.pdata[i][j];

		}
	}
}

Matrix::Matrix(Matrix&& data)
:pcolumn_count{data.pcolumn_count},
 prow_count{data.prow_count}
{


	pdata=new int*[prow_count];

	for(auto i=0;i<prow_count;i++) {

		pdata[i]=new int[pcolumn_count];

		for(auto j=0;j<pcolumn_count;j++) {

			pdata[i][j]=data.pdata[i][j];

			data.pdata[i][j]=0;
		}
	}

	data.pcolumn_count=0;
	data.prow_count=0;

}

Matrix& Matrix::operator=(const Matrix& data)
{
	pcolumn_count=data.pcolumn_count;

	prow_count=data.prow_count;

	pdata=new int*[prow_count];

	for(auto i=0;i<prow_count;i++) {

		pdata[i]=new int[pcolumn_count];

		for(auto j=0;j<pcolumn_count;j++) {

			pdata[i][j]=data.pdata[i][j];

		}
	}

	return *this;
}

Matrix& Matrix::operator=(Matrix&& data)
{
	pcolumn_count=data.pcolumn_count;

	prow_count=data.prow_count;

	pdata=new int*[prow_count];

	for(auto i=0;i<prow_count;i++) {

		pdata[i]=new int[pcolumn_count];

		for(auto j=0;j<pcolumn_count;j++) {

			pdata[i][j]=data.pdata[i][j];

			data.pdata[i][j]=0;
		}
	}

	data.pcolumn_count=0;
	data.prow_count=0;

	return *this;
}

Matrix::~Matrix()
{
	for(auto i=0;i<prow_count;i++) {

		delete[] pdata[i];
	}

	delete[] pdata;


}

void Matrix::set(const int& data,const int& column_index,const int& row_index)
{
	pdata[column_index][row_index]=data;
}

int Matrix::at(const int& column_index,const int& row_index) const
{
	return pdata[column_index][row_index];
}

int Matrix::get_column_count() const
{
	return pcolumn_count;
}

int Matrix::get_row_count() const
{
	return prow_count;
}


