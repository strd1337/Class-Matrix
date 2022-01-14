/*
Вариант 7:

b) Создать параметризированный класс Matrix – матрица. Класс должен содержать
конструкторы, деструктор, функции getRows, getCols, операторы [], +, -, * и ввода/вывода.

Работает только с одинаковыми типами. Н-р: int-int, float-float, char-char.
Действия над char - происходит над двоичным кодом символа.

Оператор [] - помог Валентин Хоменский
*/


#include "BfuncLAB7.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	cout << "\nКонструктор по умолчанию(int).\n";
	Matrix <int> A;
	cout << "\nВвод объекта A:" << endl;
	cin >> A;
	cout << "\nПечать объекта A:" << endl;
	cout << A;
	
	cout << "\nКонструктор с одним параметром(int).\n";
	Matrix <int> L(2);
	L.print("L");
	
	cout << "\nКонструктор с одним параметром(float).\n";
	Matrix <float> O(3);
	O.print("O");
	
	cout << "\nКонструктор с одним параметром(bool).\n";
	Matrix <bool> J(3);
	J.print("J");
	
	cout << "\nКонструктор с одним параметром(char).\n";
	Matrix <char> B(2);
	B.print("B");
	
	cout << "\nКонструктор с двумя параметрами(int).\n";
	Matrix <int> T(2,3);
	T.print("T");
	
	cout << "\nКонструктор с двумя параметрами(float).\n";
	Matrix <float> Y(3,3);
	Y.print("Y");
	
	cout << "\nКонструктор с двумя параметрами(bool).\n";
	Matrix <bool> X(3,3);
	X.print("X");
	
	cout << "\nКонструктор с двумя параметрами(char).\n";
	Matrix <char> V(2,2);
	V.print("V");
	
	cout << "\nКонструктор копирования W(V)(char).\n";
	Matrix <char> W(V);
	W.print("W");
	
	cout << "\nОператор присваивания R = T(int).\n";
	Matrix <int> R;
	R = T;
	R.print("R");
	
	cout << "\nОператор сложения L += A, совпадают размеры (int).\n";
	L.print("L");
	A.print("A");
	L += A;
	L.print("L");
	
	cout << "\nОператор сложения B += V, совпадают размеры (char).\n";
	B.print("B");
	V.print("V");
	B += V;
	B.print("B");
	
	cout << "\nОператор сложения S = Y + O, совпадают размеры (float).\n";
	Matrix <float> S;
	Y.print("Y");
	O.print("O");
	S = Y + O;
	S.print("S");
	
	cout << "\nОператор сложения Q = B + V, совпадают размеры (char).\n";
	Matrix <char> Q;
	B.print("B");
	V.print("V");
	Q = B + V;
	Q.print("Q");
	
	cout << "\nОператор сложения U += T, не совпадают размеры (int).\n";
	Matrix <int> U;
	U.print("U");
	T.print("T");
	U += T;
	U.print("U");
	
	cout << "\nОператор сложения U = L + T, не совпадают размеры (int).\n";
	T.print("T");
	L.print("L");
	U = L + T;
	U.print("U");
	
	cout << "\nОператор сложения U -= A, совпадают размеры (int).\n";
	U.print("U");
	A.print("A");
	U -= A;
	U.print("U");
	
	cout << "\nОператор сложения B -= P, совпадают размеры (char).\n";
	Matrix <char> P(2);
	B.print("B");
	P.print("P");
	B -= P;
	B.print("B");
	
	cout << "\nОператор сложения U = L - A, совпадают размеры (int).\n";
	L.print("L");
	A.print("A");
	U = L - A;
	U.print("U");
	
	cout << "\nОператор сложения B = V - P, совпадают размеры (char).\n";
	V.print("V");
	P.print("P");
	B = V - P;
	B.print("B");
	
	cout << "\nОператор сложения U -= T, не совпадают размеры (int).\n";
	U.print("U");
	T.print("T");
	U -= T;
	U.print("U");
	
	cout << "\nОператор сложения U = L - T, не совпадают размеры (int).\n";
	L.print("L");
	T.print("T");
	U = L - T;
	U.print("U");
	
	cout << "\nОператор сложения U *= A, совпадают размеры (int).\n";
	U.print("U");
	A.print("A");
	U *= A;
	U.print("U");
	
	cout << "\nОператор сложения V *= P, совпадают размеры (char).\n";
	V.print("V");
	P.print("P");
	V *= P;
	V.print("V");
	
	cout << "\nОператор сложения N = U * A, совпадают размеры (int).\n";
	Matrix <int> N;
	U.print("U");
	A.print("A");
	N = U * A;
	N.print("N");
	
	cout << "\nОператор сложения P = V * Q, совпадают размеры (char).\n";
	V.print("V");
	Q.print("Q");
	P = V * Q;
	P.print("P");
	
	cout << "\nОператор сложения U *= T, не совпадают размеры (int).\n";
	U.print("U");
	T.print("T");
	U *= T;
	U.print("U");
	
	cout << "\nОператор сложения U = L * T, не совпадают размеры (int).\n";
	L.print("L");
	T.print("T");
	U = L * T;
	U.print("U");
	
	cout << "\nОператор [] const чтение.\n";
	for (int i = 0; i < V.getRows(); i++)
	{
	    for (int j = 0; j < V.getCols(); j++)
	        cout << V[i][j] << "\t";
	        
	    cout << endl;
	}

	cout << "\nОператор [] не-const чтение/запись.\n";
	Matrix <int> E;
	for (int i = 0; i < E.getRows(); i++)
	    for (int j = 0; j < E.getCols(); j++)
	    	E[i][j] = (rand() % 8) - 2;
	
	E.print("E");
	
	system("pause");
	return 0;
}
