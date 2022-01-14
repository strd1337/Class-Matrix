#include "BheadLAB7.h"
#include <ctime>


//����������� �� ���������
template<typename T>
Matrix<T>::Matrix()											
{
	//�����������
	p_n = 2;
	p_m = 2;
	
	try {
	   	//�������� ������ ��� �������
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];       
	            
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		
		//�������� ������ �������
		p_n = 0;
		p_m = 0;
	}
}


//����������� � ����� ����������
template<typename T>
Matrix<T>::Matrix(int n)											
{
	//������ �������
	p_n = n;
	p_m = n;
   	
   	try {
	   	//�������� ������ ��� �������
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
	    	//������
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 8) - 2;
		}
	    
		cout << endl;       
	            
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		
		//�������� ������ �������
		p_n = 0;
		p_m = 0;
	}
}


//����������� � ����� �����������
template<typename T>
Matrix<T>::Matrix(int n, int m)						
{
	//������ �������
	p_n = n;
	p_m = m;
	
	try {
	   	//�������� ������ ��� �������
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //���������
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
	    	//������
		    for (int i = 0; i < p_n; i++)
		        for (int j = 0; j < p_m; j++)
		            pointer[i][j] = (rand() % 8) - 2;
		}
			
	    cout << endl;
		       
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		
		//�������� ������ �������
		p_n = 0;
		p_m = 0;
	}
}


//����������� �����������
template<typename T>
Matrix<T>::Matrix(const Matrix <T> & other)
{
	//������ �������
	p_n = other.p_n;
	p_m = other.p_m;
	
	try {
		//�������� ������ ��� �������
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //��������� ����������
	    for (int i = 0; i < p_n; i++)
	        for (int j = 0; j < p_m; j++)
	            pointer[i][j] = other.pointer[i][j];
		
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		
		//�������� ������ �������
		p_n = 0;
		p_m = 0;
	}
}


//����������
template<typename T>
Matrix<T>::~Matrix()
{ 
	for (int i = 0; i < p_n; i++)
		delete[] pointer[i];
	
	delete[] pointer;	
}


//�������� ������������
template<typename T>
Matrix <T> & Matrix<T>::operator = (const Matrix <T> & other)
{
	//������������ ������ ����
	if (this == &other)
		return *this; 	
	
	//������� ������
	for (int i = 0; i < p_n; i++)
		delete[] pointer[i];
			
	delete[] pointer;
	
	//������ �������
	p_n = other.p_n;
	p_m = other.p_m;
	
	try {
		//�������� ������ ��� �������
	   	pointer = new T * [p_n];
	 
	    for(int i = 0; i < p_n; i++)
	        pointer[i] = new T[p_m];
	    
	    //��������� ����������
	    for (int i = 0; i < p_n; i++)
	        for (int j = 0; j < p_m; j++)
	            pointer[i][j] = other.pointer[i][j];
		
		//����������
		return *this;
		
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		
		//�������� ������ �������
		p_n = 0;
		p_m = 0;
	}
}


//�������� +=
template<typename T>
Matrix <T> & Matrix<T>::operator += (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n";
		*this = other;
		return *this;
	}
	
	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	pointer[i][j] += other.pointer[i][j];
        	
	return *this;
}


//�������� +
template<typename T>
Matrix <T> operator + (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//������� ����� �������
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n\n";
		return newMtrx;
	}
	
	newMtrx += two;
     	
	return newMtrx;
}


//�������� -=
template<typename T>
Matrix <T> & Matrix<T>::operator -= (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n";
		*this = other;
		return *this;
	}
	
	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	pointer[i][j] -= other.pointer[i][j];
        	
	return *this;
}


//�������� -
template<typename T>
Matrix <T> operator - (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//������� ����� �������
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n\n";
		return newMtrx;
	}
	
	newMtrx -= two;
     	
	return newMtrx;
}


//�������� *=
template<typename T>
Matrix <T> & Matrix<T>::operator *= (const Matrix <T> & other)
{
	if (p_n != other.p_n || p_m != other.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n";
		*this = other;
		return *this;
	}
	
	//������� ����� �������
	Matrix <T> newMtrx(*this);
	
	//��������
	if (typeid(T) == typeid(char))
		for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	newMtrx.pointer[i][j] = '\0';
    else 
    	for (int j = 0; j < p_m; j++)
        	for (int i = 0; i < p_n; i++)
            	newMtrx.pointer[i][j] = 0;
	       	
	//��������
	for (int j = 0; j < other.p_m; j++)
        for (int i = 0; i < p_n; i++)
        	for (int k = 0; k < other.p_n; k++)
            	newMtrx.pointer[i][j] = pointer[i][k]*other.pointer[k][j] + newMtrx.pointer[i][j];
    
    *this = newMtrx;
	 	
	return *this;
}


//�������� *
template<typename T>
Matrix <T> operator * (const Matrix <T> & one, const Matrix <T> & two)		
{	
	//������� ����� �������
	Matrix <T> newMtrx(one);

	if (one.p_n != two.p_n || one.p_m != two.p_m) {
		cout << "\n������. ������� �� ���������� ��������.\n";
		cout << "������� ����� ��������� ������ ���������.\n\n";
		return newMtrx;
	}
	
	newMtrx *= two;
     	
	return newMtrx;
}


//��������� ���-�� ����� �������
template<typename T>
int Matrix<T>::getRows() const
{
	return p_n;
}


//��������� ���-�� �������� �������
template<typename T>
int Matrix<T>::getCols() const
{
	return p_m;
}


//������ �������
template<typename T>
void Matrix<T>::print(const char* name) const
{
	if (!p_n) 
		cout << "\n������. ������� �� ����������.\n";
	else {
		cout << "������ ������� " << name << ":" << endl;
		
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


//�������� [] const ������
template<typename T>
const T *& Matrix<T>::operator [] (int i) const
{	
	return pointer[i];
}


//�������� [] ��-const ������/������
template<typename T>
T *& Matrix<T>::operator [] (int i)
{
	return pointer[i];
}


//����
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


//�����
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
