/*
Hatim Painter
CST 211 Assignment 2
10/8/2015
*/

template <typename T>
Array2D<T>::Array2D()
{
	m_array = nullptr;
	m_col = 0;
	m_row = 0;
}

template <typename T>
Array2D<T>::Array2D(int row, int col)
{
	m_array = new T *[row];

	for (int i = 0; i < row; i++)
	{
		m_array[i] = new T[col];
	}

	m_row = row;
	m_col = col;
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & aCopy)
{
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;

	m_array = new T*[aCopy.m_row];

	for (int i = 0; i < aCopy.m_row; i++)
	{
		m_array[i] = new T[aCopy.m_col];
	}

	for (int i = 0; i < aCopy.m_row; i++)
	{
		for (int k = 0; k < aCopy.m_col; k++)
		{
			m_array[i][k] = aCopy.m_array[i][k];
		}
	}

	m_row = aCopy.m_row;
	m_col = aCopy.m_col;
}

template <typename T>
Array2D<T>::~Array2D()
{
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
}

template <typename T>
Array2D<T> & Array2D<T>::operator =(Array2D<T> & anArray)
{
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;

	m_array = new T*[anArray.m_row];

	for (int i = 0; i < anArray.m_row; i++)
	{
		m_array[i] = new T[anArray.m_col];
	}

	for (int i = 0; i < anArray.m_row; i++)
	{
		for (int k = 0; k < anArray.m_col; k++)
		{
			m_array[i][k] = anArray.m_array[i][k];
		}
	}

	m_row = anArray.m_row;
	m_col = anArray.m_col;

	return *this;
}

template <typename T>
Row<T> Array2D<T>::operator [](int index)
{
	if (index > m_row || index < 0)
	{

		if (index > m_row)
		{
			throw Exception("Row Out of Bounds! Index larger than upper bound (Row)");
		}
		else
			throw Exception("Row Out of Bounds! Index smaller than lower bound (Row)");

	}
	else
		return Row<T> (*this, index);
}

template <typename T>
void Array2D<T>::display() const
{
	for (int i = 0; i < m_row; i++)
	{
		cout << "| ";
		for (int k = 0; k < m_col; k++)
		{
			cout << m_array[i][k] << " | ";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename T>
int Array2D<T>::getRow() const 
{
	return m_row;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{
	if (rows < 0)
	{
		throw Exception("Cannot set to rows to less than 0!");
	}
	else
	{
		T ** tempArray = m_array;

		m_array = new T*[rows];

		for (int i = 0; i < rows; i++)
		{
			m_array[i] = new T[m_col];
		}

		if (rows < m_row)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int k = 0; k < m_col; k++)
				{
					m_array[i][k] = tempArray[i][k];
				}
			}
		}
		else
		{
			for (int i = 0; i < m_row; i++)
			{
				for (int k = 0; k < m_col; k++)
				{
					m_array[i][k] = tempArray[i][k];
				}
			}
		}


		for (int i = 0; i < m_row; i++)
		{
			delete[] tempArray[i];
		}
		delete[] tempArray;

		m_row = rows;
	}
	
}

template <typename T>
int Array2D<T>::getColumn() const
{
	return m_col;
}

template <typename T>
void Array2D<T>::setColumn(int columns)
{
	if (columns < 0)
	{
		throw Exception("Cannot set to columns to less than 0!");
	}
	else
	{
		T ** tempArray = m_array;

		m_array = new T*[m_row];

		for (int i = 0; i < m_row; i++)
		{
			m_array[i] = new T[columns];
		}

		if (columns < m_col)
		{
			for (int i = 0; i < m_row; i++)
			{
				for (int k = 0; k < columns; k++)
				{
					m_array[i][k] = tempArray[i][k];
				}
			}
		}
		else
		{
			for (int i = 0; i < m_row; i++)
			{
				for (int k = 0; k < m_col; k++)
				{
					m_array[i][k] = tempArray[i][k];
				}
			}
		}

		for (int i = 0; i < m_row; i++)
		{
			delete[] tempArray[i];
		}
		delete[] tempArray;

		m_col = columns;
	}
	
}

template <typename T>
T & Array2D<T>::Select(int row, int column) const
{
	return m_array[row][column];
}