#include<iostream>
#include <list>
#include<Windows.h>
using namespace std;
struct Complex
{
	int i;
	int j;
};
Complex zadanie(Complex num1, Complex num2 ) {
	Complex *p = new Complex;
	p->i = num1.i + num2.i;
	p->j = num1.j + num2.j;
	return *p;
}
Complex zadanie2(Complex num1, Complex num2) {
	Complex *p = new Complex;
	p->i = num1.i - num2.i;
	p->j = num1.j - num2.j;
	return *p;
}
Complex zadanie3(Complex num1, Complex num2) {
	Complex *p = new Complex;
	p->i =((num1.i*num2.i)+(num2.j*num1.j))/num2.i*num2.i + num2.j*num2.j;
	p->j = (num1.j*num2.i - num1.i*num2.j)/ num2.i*num2.i + num2.j*num2.j;
	return *p;
}
void print(Complex answer) {
	cout << "Действительная часть "<<answer.i << endl;
	cout << "Мнимая часть " << answer.j<<" i"<< endl;
}
void main() {

	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Complex answer, answer2, answer3,num1,num2;
	num1.i = 7;
	num1.j = -2;
	num2.i = 5;
	num2.j = 3;
	answer = zadanie(num1, num2);
	answer2 = zadanie2(num1, num2);
	answer3 = zadanie3(num1, num2);
	print(answer);
	print(answer2);
	print(answer3);	


	system("PAUSE");
}