#include<iostream>
#include "Header.h"

using namespace std;
Complex zadanie(Complex num1, Complex num2) {
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
	p->i = ((num1.i*num2.i) + (num2.j*num1.j)) / num2.i*num2.i + num2.j*num2.j;
	p->j = (num1.j*num2.i - num1.i*num2.j) / num2.i*num2.i + num2.j*num2.j;
	return *p;
}
void print(Complex answer) {
	cout << "Действительная часть " << answer.i << endl;
	cout << "Мнимая часть " << answer.j << " i" << endl;
}


