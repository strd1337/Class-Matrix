#include "BheadLAB7.h"
#include <ctime>


//конструктор по умолчанию
template<typename T>
Matrix<T>::Matrix()											
{
	//размерность
	p_n = 2;
	p_m = 2;
	
	try {
	   	//выделяем память для матрицы
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];       
	            
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		
		//обнуляем размер матрицы
		p_n = 0;
		p_m = 0;
	}
}


//конструктор с одним параметром
template<typename T>
Matrix<T>::Matrix(int n)											
{
	//размер матрицы
	p_n = n;
	p_m = n;
   	
   	try {
	   	//выделяем память для матрицы
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
 		if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
			//float, double
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = ((rand() % 101) - 50) / 10.0;
		            
		} else if (typeid(T) == typeid(bool)) {
			//bool
			for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 2) - 1;
		            
		} else if (typeid(T) == typeid(char)) {
			//char
			char tmp = 'a';
			
			for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		        {
		        	if (!isalpha(tmp)) 
						tmp = 'a';
						
		            pointer[i][j] = tmp;
		            tmp += 1;
				}
				
		} else {
	    	//другие
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 8) - 2;
		}
	    
		cout << endl;       
	            
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		
		//обнуляем размер матрицы
		p_n = 0;
		p_m = 0;
	}
}


//конструктор с двумя параметрами
template<typename T>
Matrix<T>::Matrix(int n, int m)						
{
	//размер матрицы
	p_n = n;
	p_m = m;
	
	try {
	   	//выделяем память для матрицы
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //заполняем
	    if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
			//float, double
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = ((rand() % 101) - 50) / 10.0;
		            
		} else if (typeid(T) == typeid(bool)) {
			//bool
			for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 2) - 1;
		            
		} else if (typeid(T) == typeid(char)) {
			//char
			char tmp = 'a';
			
			for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		        {
		        	if (!isalpha(tmp)) 
						tmp = 'a';
						
		            pointer[i][j] = tmp;
		            tmp += 1;
				}
				
		} else {
	    	//другие
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 8) - 2;
		}
			
	    cout << endl;
		       
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		
		//обнуляем размер матрицы
		p_n = 0;
		p_m = 0;
	}
}


//конструктор корирования
template<typename T>
Matrix<T>::Matrix(const Matrix <T> & other)
{
	//размер матрицы
	p_n = other.p_n;
	p_m = other.p_m;
	
	try {
		//выделяем память для матрицы
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //заполняем значениями
	    for (int i = 0; i < p_n; i++)
	        for (int j = 0; j < p_m; j++)
	            pointer[i][j] = other.pointer[i][j];
		
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		
		//обнуляем размер матрицы
		p_n = 0;
		p_m = 0;
	}
}


//деструктор
template<typename T>
Matrix<T>::~Matrix()
{ 
	for (int i = 0; i < p_n; i++)
		delete[] pointer[i];
	
	delete[] pointer;	
}


//оператор присваивания
template<typename T>
Matrix <T> & Matrix<T>::operator = (const Matrix <T> & other)
{
	//присваивание самому себе
	if (this == &other)
		return *this; 	
	
	//очищаем память
	for (int i = 0; i < p_n; i++)
		delete[] pointer[i];
			
	delete[] pointer;
	
	//размер матрицы
	p_n = other.p_n;
	p_m = other.p_m;
	
	try {
		//выделяем память для матрицы
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //заполняем значениями
	    for (int i = 0; i < p_n; i++)
	        for (int j = 0; j < p_m; j++)
	            pointer[i][j] = other.pointer[i][j];
		
		//возвращаем
		return *this;
		
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		
		//обнуляем размер матрицы
		p_n = 0;
		p_m = 0;
	}
}


//оператор +=
template<typename T>
Matrix <T> & Matrix<T>::operator += (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n";
		*this = other;
		return *this;
	}
	
	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	pointer[i][j] += other.pointer[i][j];
        	
	return *this;
}


//оператор +
template<typename T>
Matrix <T> operator + (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//создаем новую матрицу
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n\n";
		return newMtrx;
	}
	
	newMtrx += two;
     	
	return newMtrx;
}


//оператор -=
template<typename T>
Matrix <T> & Matrix<T>::operator -= (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n";
		*this = other;
		return *this;
	}
	
	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	pointer[i][j] -= other.pointer[i][j];
        	
	return *this;
}


//оператор -
template<typename T>
Matrix <T> operator - (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//создаем новую матрицу
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n\n";
		return newMtrx;
	}
	
	newMtrx -= two;
     	
	return newMtrx;
}


//оператор *=
template<typename T>
Matrix <T> & Matrix<T>::operator *= (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n";
		*this = other;
		return *this;
	}
	
	//создаем новую матрицу
	Matrix <T> newMtrx(*this);
	
	//обнуляем
	if (typeid(T) == typeid(char))
		for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	newMtrx.pointer[i][j] = '\0';
    else 
    	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	newMtrx.pointer[i][j] = 0;
	       	
	//умножаем
	for (int j = 0; j < other.p_m; j++)
        for (int i = 0; i < p_n; i++)
        	for (int k = 0; k < other.p_n; k++)
            	newMtrx.pointer[i][j] = pointer[i][k]*other.pointer[k][j] + newMtrx.pointer[i][j];
    
    *this = newMtrx;
	 	
	return *this;
}


//оператор *
template<typename T>
Matrix <T> operator * (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//создаем новую матрицу
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\nОшбика. Матрицы не одинаковых размеров.\n";
		cout << "Матрице будет присвоено первое слогаемое.\n\n";
		return newMtrx;
	}
	
	newMtrx *= two;
     	
	return newMtrx;
}


//получения кол-ва строк матрицы
template<typename T>
int Matrix<T>::getRows() const
{
	return p_n;
}


//получения кол-ва столбцов матрицы
template<typename T>
int Matrix<T>::getCols() const
{
	return p_m;
}


//печать матрицы
template<typename T>
void Matrix<T>::print(const char* name) const
{
	if (!p_n) 
		cout << "\nОшибка. Матрица не существует.\n";
	else {
		cout << "Печать объекта " << name << ":" << endl;
		
		for (int i = 0; i < p_n; i++)
	    {
	      for (int j = 0; j < p_m; j++)
	      {
				if (pointer[i][j] == '\0' && typeid(T) == typeid(char))
					cout << "\\0\t";
				else
					cout << pointer[i][j] << "\t";
		  } 
	      cout << endl;
	    }
	    
	    cout << endl;
	}
}


//оператор [] const чтение
template<typename T>
const T *& Matrix<T>::operator [] (int i) const
{	
	return pointer[i];
}


//оператор [] не-const чтение/запись
template<typename T>
T *& Matrix<T>::operator [] (int i)
{
	return pointer[i];
}


//ввод
template<typename T>
istream & operator >> (istream & ist, Matrix <T> & other)			
{
	for (int i = 0; i < other.p_n; i++)
	{
	    for (int j = 0; j < other.p_m; j++)
	    {
	    	cout << "Matrix[" << i + 1 << "][" << j + 1 << "] = ";
	    	ist >> other.pointer[i][j];
		}
	} 
	
	return ist;
}


//вывод
template<typename T>
ostream & operator << (ostream & ost, const Matrix <T> & other)	
{
	for (int i = 0; i < other.p_n; i++)
	{
	    for (int j = 0; j < other.p_m; j++)
	        ost << other.pointer[i][j] << "\t";
	        
	    ost << endl;
	}
	
    return ost;
}
