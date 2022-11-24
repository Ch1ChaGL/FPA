#include "Student.h"
#include <iostream>
using namespace std;

void main() {

	setlocale(LC_ALL,"");
	/*Student a;
	a = fill(a);
	Student b;
	b = fill(b);
	print(a);
	print(b);*/
	Student *pStudent = new Student[2];
	fillArray(pStudent);
	printArray(pStudent);

	





	system("PAUSE");
}