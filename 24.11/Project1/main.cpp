#include "Header.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "");
	Complex a1 = { 3,7 };
	Complex b1 = { 2,10 };
	Complex answer = zadanie(a1, b1);
	print(answer);
}