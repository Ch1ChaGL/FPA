#include<iostream>
#include <list>
#include<Windows.h>
#include"Student.h"
#include <string>

using namespace std;
const int N = 2;
Student fill(Student student) {
	string name;
	Student newstudent;
	int oplata;
	int nz;
	cout << "������� ���" << endl;
	cin >> name;
	cout << "������� ����� �������" << endl;
	cin >> nz;
	cout << "������� ��������� ��������" << endl;
	cin >> oplata;
	newstudent.FIO = name;
	newstudent.n_z = nz;
	newstudent.opl = oplata;
	return newstudent;

}
void print(Student student) {
	cout << student.FIO << endl;
	cout << student.n_z << endl;
	cout << student.opl<< endl;
}
void fillArray(Student *array) {
	for (int i = 0; i < 2; i++) {
		string name;
		int oplata;
		int nz;
		cout << "������� ���" << endl;
		cin >> name;
		cout << "������� ����� �������" << endl;
		cin >> nz;
		cout << "������� ��������� ��������" << endl;
		cin >> oplata;
		array[i].FIO = name;
		array[i].n_z = nz;
		array[i].opl = oplata;
	}
}
void printArray(Student *array) {
	for (int i = 0; i < 2; i++) {
		cout << array[i].FIO << endl;
		cout << array[i].n_z << endl;
		cout << array[i].opl << endl;
	}
}