/*
Hatim Painter
CST 211 Assignment 2
10/8/2015
*/

template <typename T>
Row<T>::Row(Array2D<T> & array, int row) : m_array2D{ array }
{
	m_row = row;
}

template <typename T>
T & Row<T>::operator [](int column)
{
	if (column > m_array2D.getColumn() || column < 0)
	{

		if (column > m_array2D.getColumn() )
		{
			throw Exception("Column Out of Bounds! Index larger than upper bound (Column)");
		}
		else
			throw Exception("Column Out of Bounds! Index smaller than lower bound (Column)");

	}
	else
		return m_array2D.Select(m_row, column);
}
