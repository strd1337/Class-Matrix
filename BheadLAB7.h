#include <Windows.h>
#include <stdlib.h> 	
#include <math.h>   				
#include <conio.h>  	
#include <iomanip> 
#include <iostream>	 
#include <new>
#include <typeinfo>


using namespace std;


//шаблонные прототипы
template<typename T> 
class Matrix;															//матрица

template <typename T> 
istream & operator >> (istream &, Matrix <T> &); 						//ввод

template <typename T> 
ostream & operator << (ostream &, const Matrix <T> &);					//вывод

template <typename T> 
Matrix <T> operator + (const Matrix <T> &, const Matrix <T> &);			//оператор сложения

template <typename T> 
Matrix <T> operator - (const Matrix <T> &, const Matrix <T> &);			//оператор итания

template <typename T> 
Matrix <T> operator * (const Matrix <T> &, const Matrix <T> &);			//оператор умножения матрицу на матрицу


//шаблонный класс
template <typename T>
class Matrix
{
	private:
		T **pointer;													//указатель на матрицу
		int p_n;														//кол-во строк
		int p_m;														//кол-во столбцов
	public:
		//конструкторы
		Matrix();														//конструктор по умолчанию
		explicit Matrix(int);											//конструктор с одним параметром
		explicit Matrix(int, int);										//конструктор с двумя параметрами
		Matrix(const Matrix <T> &);										//конструктор копирования
		~Matrix();														//Деструктор
		
		//Методы класса
		Matrix <T> & operator = (const Matrix <T> &);					//оператор присваивания									
		Matrix <T> & operator += (const Matrix <T> &);					//оператор сложения
 		Matrix <T> & operator -= (const Matrix <T> &);					//оператор вычитания
 		Matrix <T> & operator *= (const Matrix <T> &);					//оператор умножения матрицу на матрицу
		const T *& operator [] (int i) const;							//оператор [] const чтение
		T *& operator [] (int i);										//оператор [] не-const чтение/запись
		int getRows() const;											//получения кол-ва строк матрицы
		int getCols() const;											//получения кол-ва столбцов матрицы
		void print(const char *) const;									//печать матрицы
		
		//дружественные функции
		friend istream & operator >> <> (istream &, Matrix &); 			//ввод
		friend ostream & operator << <> (ostream &, const Matrix &);	//вывод
		friend Matrix operator + <> (const Matrix &, const Matrix &);	//оператор сложения
 		friend Matrix operator - <> (const Matrix &, const Matrix &);	//оператор вычитания
 		friend Matrix operator * <> (const Matrix &, const Matrix &);	//оператор умножения матрицу на матрицу
};
