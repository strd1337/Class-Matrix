/*
������� 7:

b) ������� ������������������� ����� Matrix � �������. ����� ������ ���������
������������, ����������, ������� getRows, getCols, ��������� [], +, -, * � �����/������.

�������� ������ � ����������� ������. �-�: int-int, float-float, char-char.
�������� ��� char - ���������� ��� �������� ����� �������.

�������� [] - ����� �������� ���������
*/


#include "BfuncLAB7.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	cout << "\n����������� �� ���������(int).\n";
	Matrix <int> A;
	cout << "\n���� ������� A:" << endl;
	cin >> A;
	cout << "\n������ ������� A:" << endl;
	cout << A;
	
	cout << "\n����������� � ����� ����������(int).\n";
	Matrix <int> L(2);
	L.print("L");
	
	cout << "\n����������� � ����� ����������(float).\n";
	Matrix <float> O(3);
	O.print("O");
	
	cout << "\n����������� � ����� ����������(bool).\n";
	Matrix <bool> J(3);
	J.print("J");
	
	cout << "\n����������� � ����� ����������(char).\n";
	Matrix <char> B(2);
	B.print("B");
	
	cout << "\n����������� � ����� �����������(int).\n";
	Matrix <int> T(2,3);
	T.print("T");
	
	cout << "\n����������� � ����� �����������(float).\n";
	Matrix <float> Y(3,3);
	Y.print("Y");
	
	cout << "\n����������� � ����� �����������(bool).\n";
	Matrix <bool> X(3,3);
	X.print("X");
	
	cout << "\n����������� � ����� �����������(char).\n";
	Matrix <char> V(2,2);
	V.print("V");
	
	cout << "\n����������� ����������� W(V)(char).\n";
	Matrix <char> W(V);
	W.print("W");
	
	cout << "\n�������� ������������ R = T(int).\n";
	Matrix <int> R;
	R = T;
	R.print("R");
	
	cout << "\n�������� �������� L += A, ��������� ������� (int).\n";
	L.print("L");
	A.print("A");
	L += A;
	L.print("L");
	
	cout << "\n�������� �������� B += V, ��������� ������� (char).\n";
	B.print("B");
	V.print("V");
	B += V;
	B.print("B");
	
	cout << "\n�������� �������� S = Y + O, ��������� ������� (float).\n";
	Matrix <float> S;
	Y.print("Y");
	O.print("O");
	S = Y + O;
	S.print("S");
	
	cout << "\n�������� �������� Q = B + V, ��������� ������� (char).\n";
	Matrix <char> Q;
	B.print("B");
	V.print("V");
	Q = B + V;
	Q.print("Q");
	
	cout << "\n�������� �������� U += T, �� ��������� ������� (int).\n";
	Matrix <int> U;
	U.print("U");
	T.print("T");
	U += T;
	U.print("U");
	
	cout << "\n�������� �������� U = L + T, �� ��������� ������� (int).\n";
	T.print("T");
	L.print("L");
	U = L + T;
	U.print("U");
	
	cout << "\n�������� �������� U -= A, ��������� ������� (int).\n";
	U.print("U");
	A.print("A");
	U -= A;
	U.print("U");
	
	cout << "\n�������� �������� B -= P, ��������� ������� (char).\n";
	Matrix <char> P(2);
	B.print("B");
	P.print("P");
	B -= P;
	B.print("B");
	
	cout << "\n�������� �������� U = L - A, ��������� ������� (int).\n";
	L.print("L");
	A.print("A");
	U = L - A;
	U.print("U");
	
	cout << "\n�������� �������� B = V - P, ��������� ������� (char).\n";
	V.print("V");
	P.print("P");
	B = V - P;
	B.print("B");
	
	cout << "\n�������� �������� U -= T, �� ��������� ������� (int).\n";
	U.print("U");
	T.print("T");
	U -= T;
	U.print("U");
	
	cout << "\n�������� �������� U = L - T, �� ��������� ������� (int).\n";
	L.print("L");
	T.print("T");
	U = L - T;
	U.print("U");
	
	cout << "\n�������� �������� U *= A, ��������� ������� (int).\n";
	U.print("U");
	A.print("A");
	U *= A;
	U.print("U");
	
	cout << "\n�������� �������� V *= P, ��������� ������� (char).\n";
	V.print("V");
	P.print("P");
	V *= P;
	V.print("V");
	
	cout << "\n�������� �������� N = U * A, ��������� ������� (int).\n";
	Matrix <int> N;
	U.print("U");
	A.print("A");
	N = U * A;
	N.print("N");
	
	cout << "\n�������� �������� P = V * Q, ��������� ������� (char).\n";
	V.print("V");
	Q.print("Q");
	P = V * Q;
	P.print("P");
	
	cout << "\n�������� �������� U *= T, �� ��������� ������� (int).\n";
	U.print("U");
	T.print("T");
	U *= T;
	U.print("U");
	
	cout << "\n�������� �������� U = L * T, �� ��������� ������� (int).\n";
	L.print("L");
	T.print("T");
	U = L * T;
	U.print("U");
	
	cout << "\n�������� [] const ������.\n";
	for (int i = 0; i < V.getRows(); i++)
	{
	    for (int j = 0; j < V.getCols(); j++)
	        cout << V[i][j] << "\t";
	        
	    cout << endl;
	}

	cout << "\n�������� [] ��-const ������/������.\n";
	Matrix <int> E;
	for (int i = 0; i < E.getRows(); i++)
	    for (int j = 0; j < E.getCols(); j++)
	    	E[i][j] = (rand() % 8) - 2;
	
	E.print("E");
	
	system("pause");
	return 0;
}
