




//=================================================================
//	Matrix::operator() : indexes the matrix
//---------------------------------------
template<int ROW, int COL, typename T>
T& Matrix<ROW,COL,T>::operator()(size_t i, size_t j)
{
	return mElem[j][i];
}





//=================================================================
//	Matrix::opperator+ : matrix addition
//---------------------------------------
template<int ROW, int COL, typename T>
Matrix<ROW,COL,T> Matrix<ROW,COL,T>::operator+(const Matrix<ROW,COL,T> &other)
{
	Matrix<ROW,COL,T> theResult;

	for( size_t i = 0; i< COL; i++ )
	{
		for( size_t j = 0; j< ROW; j++ )
		{
			theResult.mElem[i][j] = this->mElem[i][j] + other.mElem[i][j];
		}
	}

	return theResult;
}





//=================================================================
//	Matrix::opperator* : matrix multiplication
//---------------------------------------
template<int ROW, int COL, typename T>
template<size_t X>
Matrix<ROW,X,T>	Matrix<ROW,COL,T>::operator*(const Matrix<COL,X,T> &other)
{
	Matrix<ROW,COL,T> theResult;

	for(size_t i = 0; i< X; i++)
	{
		for(size_t j = 0; j< ROW; j++)
		{
			T elem = 0;

			for(size_t k = 0; k< COL; k++)
			{
				T elemA = i>=COL ? 0 : mElem[i][k];
				T elemB = j>=X   ? 0 : other.mElem[k][j];
				elem += (elemA * elemB);
			}

			theResult.mElem[i][j] = elem;
		}
	}

	return theResult;
}





//=================================================================
//	Matrix::opperator* : vector multiplication
//---------------------------------------
template<int ROW, int COL, typename T>
Vector<ROW,T> Matrix<ROW,COL,T>::operator*(const Vector<COL,T> &vector)
{
	Vector<ROW,T> result;

	for( size_t j = 0; j< ROW; j++ )
	{
		for( size_t i = 0; i< COL; i++ )
		{
			result[j] += mElem[i][j] * vector.coords[i];
		}
	}

	return result;
}