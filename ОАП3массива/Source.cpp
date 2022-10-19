#include<iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "");

	//int *pN;
	//pN = new int;
	////будет выделена пам€ть под переменную целого типа, адрес пам€ти записываетс€ в pN
	//*pN = 1005;

	double a = 5;
	double b = 5;
	double c = 5;
	double* Ar1 = new double[a];
	double* Ar2 = new double[b];
	double* Ar3 = new double[c];
	for (double* pAr1 = Ar1; pAr1 - Ar1 < a; pAr1++) {
		*pAr1 = (pAr1 - Ar1) * 2;
	}
	for (double* pAr1 = Ar1;pAr1-Ar1<a;pAr1++) {
		cout << " Ёлемент массива = " << *pAr1<<endl;
	}
	cout << "-----------------------------" << endl;
	for (double* pAr2 = Ar2; pAr2-Ar2 < a; pAr2++) {
		*pAr2 = (pAr2 - Ar2) * 3;
	}
	for (double* pAr2 = Ar2; pAr2 - Ar2 < b; pAr2++) {
		cout << " Ёлемент массива = " << *pAr2 << endl;		
	}
	cout << "-----------------------------" << endl;
	
	
	for (double* pAr3 = Ar3,*paAr2 = Ar2,*paAr1 = Ar1; pAr3 - Ar3 < c; pAr3++) {
		cout << "*paAr1 = " << *paAr1 << endl;
		*pAr3 =  ( * paAr1++) + ( * paAr2++);
		if(c==c-1){
			paAr1 = nullptr;
			delete paAr1;
			paAr2 = nullptr;
			delete paAr2;
		}
	}
	
	for (double* pAr3 = Ar3; pAr3 - Ar3 < c; pAr3++) {
		cout << " Ёлемент массива = " << *pAr3 << endl;
	}
	cout << "-----------------------------" << endl;
	for (double* pAr2 = Ar2; pAr2 - Ar2 < b; pAr2++) {
		cout << " Ёлемент массива = " << *pAr2 << endl;
	}
	

	





	system("PAUSE");
}