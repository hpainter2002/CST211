/*
Hatim Painter
CST 211 Assignment 1
10/8/2015
*/

template <typename T>
Array<T>::Array()
{
	m_myArray = nullptr;
	m_length = 0;
	m_start_index = 0;
}

template <typename T>
Array<T>::Array(int length, int start_index)
{
	m_myArray = new T[length];
	m_length = length;
	m_start_index = start_index;
}

template <typename T>
Array<T>::Array(const Array<T> & aCopy)
{
	m_myArray = new T[aCopy.m_length];

	for (int i = 0; i < aCopy.m_length; i++)
	{
		m_myArray[i] = aCopy.m_myArray[i];
	}

	m_length = aCopy.m_length;
	m_start_index = aCopy.m_start_index;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_myArray;
}

template <typename T>
Array<T> & Array<T>::operator =(const Array<T> & anArray)
{

	m_myArray = new T[anArray.m_length];

	for (int i = 0; i < anArray.m_length; i++)
	{
		m_myArray[i] = anArray.m_myArray[i];
	}

	m_length = anArray.m_length;
	m_start_index = anArray.m_start_index;

	return *this;
}

template <typename T>
T & Array<T>::operator [](int index)
{
	if (index > m_length - 1 || index < m_start_index)
	{
		
		if (index > m_length - 1)
		{
			throw Exception("Out of Bounds! Index larger than upper bound.");
		}
		else
			throw Exception("Out of Bounds! Index smaller than lower bound.");
		
	}
	else
	{
		return m_myArray[index];
	}
}

template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

template <typename T>
void Array<T>::setLength(int length)
{
	T * arrayCopy = new T[m_length];
	arrayCopy = m_myArray;

	m_myArray = new T[length];

	for (int i = 0; i < length; i++)
	{
		m_myArray[i] = arrayCopy[i];
	}

	m_length = length;
}

template <typename T>
void Array<T>::display() const
{
	for (int i = 0; i < m_length; i++)
	{
		cout << "Element number " << i + 1 << " is " << m_myArray[i] << endl;
	}
	cout << endl;
}