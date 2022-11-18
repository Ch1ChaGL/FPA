//2)Функция получает 1мерный массив и его размер, функция переворачивает массив, массив обходим через указатели, меняет полученный массив
//3)Функция перемножает матрицы, у функции три параметра, двумерные массивы и результат, в вызывающем модуле выделяем память под все три массива;
#include<iostream>

using namespace std;
const int size3 = 3;
const int size4 = 3;
void zadanie2(int arr[], int size) {
	int temp = 0;
	for (int* Parr = arr, *Parr1 = arr; Parr - arr < size / 2; Parr++) {
		temp = Parr1[Parr - arr];
		Parr1[Parr - arr] = Parr1[size - (Parr - arr) - 1];
		Parr1[size - (Parr - arr) - 1] = temp;
	}


}

void zadanie3(int **Arr , int **Arr2 , int **Arr3) {
	int* a = *Arr;
	int column = size4;
	int row = size3;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			for (int in = 0; in < row; in++) {
				Arr3[i][j] += Arr[i][in] * Arr2[in][j];
			}
		}
	}


}

void main() {
    setlocale(LC_ALL, "");
	int a;
	const int size = 5;
	const int size2 = 10;

	int Arr1[size] = { 1,2,3,4,5 };
	int Arr2[size2] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < size; i++) {
		cout << Arr1[i] << "\t";
	}
	cout << endl;
	zadanie2(Arr1, size);
	for (int i = 0; i < size; i++) {
		cout << Arr1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << Arr2[i] << "\t";
	}
	cout << endl;
	zadanie2(Arr2, size2);
	for (int i = 0; i < size2; i++) {
		cout << Arr2[i] << "\t";
	}
	cout<<endl<< "-----------------" << endl;

	int **Mass1 = new int* [size3];
	int **Mass2 = new int* [size3];
	int **Mass3 = new int* [size3];

	for (int** Arr = Mass1, **Arr2 = Mass2, **Arr3 = Mass3; Arr - Mass1 < size3; Arr++) {
		Mass1[Arr - Mass1] = new int[size4];
		Mass2[Arr - Mass1] = new int[size4];
		Mass3[Arr - Mass1] = new int[size4];
	}
	for (int i = 0; i < size3; i++) {
		for (int j = 0; j < size4; j++) {
			Mass1[i][j] = (i + j);
			Mass2[i][j] = (i + j) + 1;
			Mass3[i][j] = 0;
		}
	}
	
	for (int i = 0; i < size3; i++) {
		for (int j = 0; j < size4; j++) {
			cout<<Mass1[i][j]<<"\t";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
	for (int i = 0; i < size3; i++) {
		for (int j = 0; j < size4; j++) {
			cout << Mass2[i][j] << "\t";
		}
		cout << endl;
	}
	zadanie3(Mass1, Mass2, Mass3);
	cout << "-----------------" << endl;
	for (int i = 0; i < size3; i++) {
		for (int j = 0; j < size4; j++) {
			cout << Mass3[i][j] << "\t";
		}
		cout << endl;
	}




}