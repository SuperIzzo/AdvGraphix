
template< int I, typename T>
void TransformUtils::SetIdentity(Matrix<I,I, T> &theMatrix)
{
	for( int i=0; i< I; i++ )
	{
		for( int j=0; j< I; j++ )
		{
			if( i==j )
			{
				theMatrix(i, j) = 1;
			}
			else
			{
				theMatrix(i, j) = 0;
			}
		}
	}
}





template< typename T >
void TransformUtils::SetTranslation(Matrix<4,4, T> &theMatrix, Vector3f &theTranslation)
{
	SetIdentity( theMatrix );
	theMatrix(0,3) = theTranslation.x;
	theMatrix(1,3) = theTranslation.y;
	theMatrix(2,3) = theTranslation.z;
}





template< typename T >
void TransformUtils::SetScale(Matrix<4,4, T> &theMatrix, T sx, T sy, T sz)
{
	SetIdentity( theMatrix );
	theMatrix(0, 0) = sx;
	theMatrix(1, 1) = sy;
	theMatrix(2, 2) = sz;
}