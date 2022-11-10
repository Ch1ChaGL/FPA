#include <iostream>
using namespace std;
//Найти сумму элементов массива и каждой строки
void main() {
	setlocale(LC_ALL, "");
	/*const int size = 4;
	int number[size]{ 1,2,3,4 };
	int *pnumber = number;

	for (int *pnumber = number;  pnumber-number < size; pnumber++) {
		cout << *pnumber <<"Номер элемента = "<< pnumber - number << endl;
	}

	int n = 5, m=0;
	int **Arr;
	Arr = new int*[n];
	for (int i = 0; i < n; i++) {
		m++;
		Arr[i] = new int[m];


	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-i; j++) {
			Arr[i][j] = i + j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-i; j++) {
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}*/
	int size = 5, count = 0, count2 = 1;
	int** Arr = new int* [size];
	int n = 0; int m = 0, SumArray = 0, SumArrayString = 0;
	for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
		cout << " i = " << (Arr2 - Arr) << endl;
		Arr[(Arr2 - Arr)] = new int[(Arr2 - Arr) + 1];
	}
	for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
		for (int j = 0; j < (Arr2 - Arr) + 1; j++) {			
			Arr[Arr2 - Arr][j] = count++;
		}
	}
	for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
		for (int j = 0; j < (Arr2 - Arr) + 1; j++) {
			cout << Arr[(Arr2 - Arr)][j] << "\t";
		}
		cout << endl;
	}

	for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
		for (int j = 0; j < (Arr2 - Arr) + 1; j++) {
			SumArray += Arr[(Arr2 - Arr)][j];
		}
	}
	for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
		for (int j = 0; j < (Arr2 - Arr) + 1; j++) {
			SumArrayString += Arr[(Arr2 - Arr)][j];
		}
		cout << "Сумма " << Arr2 - Arr << " строки = " << SumArrayString<<endl;
		SumArrayString = 0;
	}
	cout << "Вся сумма массива = " << SumArray << endl;








	//Почти решение

	//for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
	//	cout << " i = " << (Arr2 - Arr) << endl;
	//	Arr[(Arr2 - Arr)] = new int[(Arr2 - Arr)+1];
	//}
	//
	//cout << "sdfsdf" << endl;
	//for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
	//	for (int** Arr3 = Arr2; Arr3 - Arr2 < (Arr2 - Arr) + 1; Arr3++) {		
	//		Arr[Arr2 - Arr][Arr3 - Arr2] = count++;	
	//	}
	//}
	//cout << "sdfsdf" << endl;
	//for (int** Arr2 = Arr; Arr2 - Arr < size; Arr2++) {
	//	for (int** Arr3 = Arr2; Arr3 - Arr2 < (Arr2 - Arr) + 1; Arr3++) {
	//		cout << Arr[(Arr2 - Arr)][(Arr3 - Arr2)] <<"\t";
	//	}
	//	cout << endl;
	//}
	






















	//for (int* Arr2 = *Arr; *Arr2 < size; *Arr2++) {
	//	Arr2 = new int[size];
	//}
	//for (int* Arr2 = *Arr; *Arr2 < size;*Arr2++) {
	//	for (int* Arr3 = Arr2; *Arr3 < size; *Arr3++) {
	//		*Arr3 = count++;
	//	}
	//}
	//for (int* Arr2 = *Arr; *Arr2 < size; *Arr2++) {
	//	for (int* Arr3 = Arr2; *Arr3 < size; *Arr3++) {
	//		cout << *Arr3 <<"\t" << endl;
	//	}
	//	cout << endl;
	//}




	/*int main() {
		const int N = 10;
		int ar[N];
		int *pLast = ar + N;
		int content = 20;
		for (int *p = ar; p < pLast; p++) {
			*p = content++;
		}
		for (int *p = ar; p < pLast; p++) {
			cout << *p << " ";
		}
		system("pause");
	}
*/

/*
	int main() {
		int n = 3, m = 5;
		int **p;													указатель на указатель
		p = new int*[n];											массив указателей на целое
		for (int i = 0; i < n; i++) {
			p[i] = new int[m];					Выделяется память под массив размера N и адресс памяти присваивается соответвующему указателю
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				p[i][j] = i + j;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
	}
*/




//#include <iostream>
//
//	using namespace std;
//
//	int main() {
//		const int N = 4;
//		const int M = 5;
//		int ar__2[N][M];
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				ar__2[i][j] = i + j;
//			}
//		}
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				cout << ar__2[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//		system("pause");
//	}
//






	system("PAUSE");
}