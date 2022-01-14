#include <Windows.h>
#include <stdlib.h> 	
#include <math.h>   				
#include <conio.h>  	
#include <iomanip> 
#include <iostream>	 
#include <new>
#include <typeinfo>


using namespace std;


//��������� ���������
template<typename T> 
class Matrix;															//�������

template <typename T> 
istream & operator >> (istream &, Matrix <T> &); 						//����

template <typename T> 
ostream & operator << (ostream &, const Matrix <T> &);					//�����

template <typename T> 
Matrix <T> operator + (const Matrix <T> &, const Matrix <T> &);			//�������� ��������

template <typename T> 
Matrix <T> operator - (const Matrix <T> &, const Matrix <T> &);			//�������� ������

template <typename T> 
Matrix <T> operator * (const Matrix <T> &, const Matrix <T> &);			//�������� ��������� ������� �� �������


//��������� �����
template <typename T>
class Matrix
{
	private:
		T **pointer;													//��������� �� �������
		int p_n;														//���-�� �����
		int p_m;														//���-�� ��������
	public:
		//������������
		Matrix();														//����������� �� ���������
		explicit Matrix(int);											//����������� � ����� ����������
		explicit Matrix(int, int);										//����������� � ����� �����������
		Matrix(const Matrix <T> &);										//����������� �����������
		~Matrix();														//����������
		
		//������ ������
		Matrix <T> & operator = (const Matrix <T> &);					//�������� ������������									
		Matrix <T> & operator += (const Matrix <T> &);					//�������� ��������
 		Matrix <T> & operator -= (const Matrix <T> &);					//�������� ���������
 		Matrix <T> & operator *= (const Matrix <T> &);					//�������� ��������� ������� �� �������
		const T *& operator [] (int i) const;							//�������� [] const ������
		T *& operator [] (int i);										//�������� [] ��-const ������/������
		int getRows() const;											//��������� ���-�� ����� �������
		int getCols() const;											//��������� ���-�� �������� �������
		void print(const char *) const;									//������ �������
		
		//������������� �������
		friend istream & operator >> <> (istream &, Matrix &); 			//����
		friend ostream & operator << <> (ostream &, const Matrix &);	//�����
		friend Matrix operator + <> (const Matrix &, const Matrix &);	//�������� ��������
 		friend Matrix operator - <> (const Matrix &, const Matrix &);	//�������� ���������
 		friend Matrix operator * <> (const Matrix &, const Matrix &);	//�������� ��������� ������� �� �������
};
