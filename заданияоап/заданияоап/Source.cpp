#include<iostream>
using namespace std;
//4 ������� 
//int *answer(int **PArr, int size2, int size) {
//	
//	int *Arr2 = new int[size];
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size2; j++) {
//			sum += PArr[i][j];
//		}
//		Arr2[i] = sum;
//		sum = 0;
//	}
//	
//	return Arr2;
//}
////1 �������
//void zadanie1(int *(Arr),int size) {
//	for (int *pArr = Arr; pArr - Arr < size; pArr++) {
//		if (*pArr % 2 == 0) {
//			*pArr = *pArr / 2;
//		}
//	}
//}

//2 ������� 
void zadanie2_13(int *Arr, int size) {
	int temp = 0;
	for (int *pArr = Arr; pArr - Arr <= size/2; pArr++)
	{
		


		temp = *pArr;
		*pArr = *(Arr + (&Arr[size] - pArr));
		*(Arr + (&Arr[size] - pArr)) = temp;
	}
}
void main() {
	//4 �������
	
	//int size = 5;
	//int size2 = 5;
	//setlocale(LC_ALL, "");
	//cout << "4 �������" << endl;
	//int **Array = new int *[size];
	//int **Array2 = new int *[size];
	//for (int i = 0; i < size2; i++) {
	//	Array[i] = new int[size2];
	//}
	//for (int i = 0; i < size2; i++) {
	//	Array2[i] = new int[size2];
	//}
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size2; j++) {
	//		Array[i][j] = (i + j) * 2;
	//	}
	//}
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size2; j++) {
	//		Array2[i][j] = (i + j) * 10;
	//	}
	//}
	//cout << "------------------" << endl;
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size2; j++) {
	//		cout << Array[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//cout << "------------------" << endl;
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size2; j++) {
	//		cout << Array2[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//cout << "------------------" << endl;
	//int *answer2 = answer(Array, size2, size);
	//int *answer3 = answer(Array2, size2, size);
	//for (int i = 0 ;i < size; i++) {
	//	cout << answer2[i] << "\t";
	//}
	//cout << endl << "------------------" << endl;
	//for (int i = 0; i < size; i++) {
	//	cout << answer3[i] << "\t";
	//}
	//cout << endl;
	////1 �������
	//cout << "1 �������" << endl;
	//const int size_13 = 5;
	//int mass_13_1[size_13] = {1,2,3,4,5};
	//int mass2_13_1[size_13] = { 5,6,6,7,8 };
	//cout << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass_13_1[i] << "\t";
	//}
	//cout << endl << "------------------" << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass2_13_1[i] << "\t";
	//}

	//zadanie1(mass_13_1, size_13);
	//zadanie1(mass2_13_1, size_13);

	//cout << endl << "------------------" << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass_13_1[i] << "\t";
	//}
	//cout << endl << "------------------" << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass2_13_1[i] << "\t";
	//}
	//cout << endl << "------------------" << endl;
	////2 �������
	//cout << "2 �������" << endl;
	//const int size_13_2 = 6;
	//int mass_13_2[size_13] = { 1,2,3,4,5 };
	//int mass2_13_2[size_13] = { 5,6,6,7,8 };
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass_13_2[i] << "\t";
	//}
	//cout << endl;
	//cout << "------------------" << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass2_13_2[i] << "\t";
	//}
	//cout << endl;
	////������� �������
	//zadanie2_13(mass_13_2, size_13_2);
	//zadanie2_13(mass2_13_2, size_13_2);

	//for (int i = 0; i < size_13; i++) {
	//	cout << mass_13_2[i] << "\t";
	//}
	//cout << endl;
	//cout << "------------------" << endl;
	//for (int i = 0; i < size_13; i++) {
	//	cout << mass2_13_2[i] << "\t";
	//}




	system("PAUSE");
}









//��� ����� �� 13 , ������� 2 ���� ��� ���� ������
//1)������� �������� ������ 1������ � ��� �����, ������ �������� ��������� � ��� ����, ��� ������ ��������, � �������� � ������� ����������
//2)������� �������� 1������ ������ � ��� ������, ������� �������������� ������, ������ ������� ����� ���������, ������ ���������� ������
//3)������� ����������� �������, � ������� ��� ���������, ��������� ������� � ���������, � ���������� ������ �������� ������ ��� ��� ��� �������;
//4)�������� ��������� ������ � ���������� ��������� �� ���������� ������, ������ ������� �������� ������ ��������� ����� 