#include<iostream>
#include <list>
#include<Windows.h>
using namespace std;
const int lenFIO = 20;
const int N = 2;
struct Student
{
	char FIO[lenFIO];
	int  n_z;
	float opl;
};
void main() {
	
	setlocale(LC_ALL,"");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student s1,s2;
	s1.n_z = 1234;
	s2.opl = 42350.64;
	strcpy_s(s1.FIO, "Пеъров");
	
	cout << s1.FIO << endl;
	cout << s1.n_z << endl;
	cout << s2.opl << endl;
	s1.FIO[2] = 'т';
	cout << s1.FIO << endl;

	Student students[N];

	for (int i = 0; i < N; i++) {
		cin >> students[i].n_z;
		cin >> students[i].opl;
		cin >> students[i].FIO;
	}
	/*for (int i = 0; i < N; i++) {
		cout << students[i].n_z<<endl;
		cout << students[i].opl<<endl;
		cout << students[i].FIO<<endl;
	}*/

	//Student Petrov = {
	//"Петров AД",
	//1234, 53.8
	//};

	Student group_319_4[]{
		{"Федя",123,123},
		{"Иван",123,423},
	};

	/*int sizemas = sizeof(group_319_4) / sizeof(Student);
	for (int i = 0; i < sizemas; i++) {
		cout << group_319_4[i].n_z << endl;
		cout << group_319_4[i].opl << endl;
		cout << group_319_4[i].FIO << endl;
	}*/
	Student *p = new Student;
	//p - адрес структуры
	// *p - вся структура 
	// (*p).n_z обращение к полю структуры
	(*p).n_z = 333;
	p->n_z = 334;//тоже самое что и выше
	
	int n = 5;
	Student *gr = new Student[n]; //Выделение памяти под динамический массив студентов

	/*for (int i = 0; i < n; i++)
	{
		cin >> gr[i].FIO;
		cin >> gr[i].n_z;
		cin >> gr[i].opl;

	}*/
	for (int i = 0; i < N; i++)
	{		
		cin >> gr[i].FIO;
		cin >> gr[i].n_z;
		cin >> gr[i].opl;
		
		cout << gr[i].FIO << endl;;
		cout << gr[i].n_z<<endl;
		cout << gr[i].opl<<endl;

	}

	/*for (Student*pnt = gr; pnt<gr+n; pnt++)
	{
		cin >> p->n_z;
		
	}
	for (Student*pnt = gr; pnt < gr + n; pnt++)
	{
		cout << p->n_z;
	}*/
	
	system("PAUSE");
}