#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
string path = "C:\\Users\\User\\Desktop\\test.txt";
ofstream fs1;
fstream fs;
ifstream fin;
string str,str2,str3;
/*Узел содержащий пользовательские поля, указатель на следующий элемент и конструктор со списком инициализации*/
struct Node						
{	
	string addres;
	float price;
	int countRoom;
	Node* next;
	Node(string _addres, float _price, int _countRoom) : addres(_addres), 
		price(_price), countRoom(_countRoom), next(nullptr){}

};

struct list {
	int size = 0;
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {};
	//Функция проверки наличия узлов в списке
	bool is_empty() {
		return first == nullptr;
	}
	//Функция добавления элемента в конец списка
	void push_back(string _addres, float _price, int _countRoom) {
		Node* p = new Node(_addres, _price, _countRoom);
		//Если список пустой, то присвоим указателю на первый и последний элмент новый адресс
		if (_addres == "" || _price == 0 || _countRoom == 0) return;
		if (is_empty()) {
			size++;
			first = p;
			last = p;
			return;
		}
		//Если список не пустой
		size++;
		last->next = p;
		last = p;
	}

	void print_in_file() {
		fs.close();
		fs1.open(path);
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			fs1 << "Адресс: " << p->addres<<"," << " Цена: " <<p->price << "," << " Количество комнат: " << p->countRoom << endl;
			p = p->next;
		}
		fs1.close();
	}
	
	void print() {
		int i = 0;
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			
			cout <<i++<<" Адресс: " << p->addres<< " Цена: " << p->price << " Количество комнат: " << p->countRoom << endl;
			p = p->next;

		}
	}

	//Функция поиска узла по заданному значению
	Node* find(string _addres, float _price, int _countRoom) {
		if (is_empty()) return nullptr;
		Node* p = first;
		while (p && p->countRoom != _countRoom) p = p->next;
		return p;
	}

	//Функция удаления первого узла
	void remove_first() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		size--;
		delete p;
	}
	
	//Функция удаления последнего узла
	void remove_last() {
		if (is_empty())return;
		//Если конец списка одновременно начало
		if (first == last) {
			remove_first();
			return;
		}
		size--;
		Node* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;


	}

	//Функция удаления узла по заданному значению
	void remove(string _addres) {
		if (is_empty())return;
		if (first->addres == _addres) {
			remove_first();
			return;
		}
		else if (last->addres == _addres) {
			remove_last();
			return;
		}
		Node* pFirst = first;
		Node* pNext = first->next;
		while (pNext && pNext->addres != _addres) {
			pFirst = pFirst->next;
			pNext = pNext->next;
		}
		if (!pFirst) {
			cout << "Нет такого объекта недвижимости" << endl;
			return;
		}
		pFirst->next = pNext->next;
		size--;
		delete pNext;

	}
	int operator [](const int index){

		string addres;
		if (is_empty()) return 0;
			Node* p = first;
			for (int i = 0; i < index; i++) {
				p = p->next;
				if (!p) return 0;
			}
			addres = p->addres;
			remove(addres);
			return 1;
	}

	//Поиск по индексу через перегрузку оператора
	//Node* operator[] (const int index) {
	//	if (is_empty()) return nullptr;
	//	Node* p = first;
	//	for (int i = 0; i < index; i++) {
	//		p = p->next;
	//		if (!p) return nullptr;
	//	}
	//	return p;
	//}

	void print_out_file() {

		while (!fin.eof()) {
			
			int index = 0;
			str = "";
			getline(fin, str);
			cout << str << endl;
			
			/*string::size_type pos{};
			string::size_type pos2{};
			pos = message.find_first_of(delim1, pos);
			pos2 = message.find_first_of(delim2, pos2);
			message.erase(pos2);
			message.erase(0, pos + 2);*/
			
		}


	}
	void copy_in_list() {
		double price;
		string addres;
		int countRoom;
		if (is_empty()) {
			while (!fin.eof()) {
				addres = "";
				price = 0;
				countRoom = 0;
				const char* delim1 = ":";
				const char* delim2 = ",";
				str = "";
				str2 = "";
				str3 = "";
				getline(fin, str);
				str2 = str3 = str;
				size_t pos = str.find("Адресс: ");
				size_t pos2 = str2.find("Цена: ");
				size_t pos3 = str3.find("Количество комнат: ");
				if (pos != string::npos) {
					string::size_type pos1{};
					pos1 = str.find_first_of(delim2, pos1);
					str.erase(pos1);
					str.erase(pos, 8);
					addres = str;
				}
				if (pos2 != string::npos) {

					string::size_type pos1{};
					str2.erase(0, pos2 + 6);
					pos1 = str2.find_first_of(delim2, pos1);
					str2.erase(pos1);
					price = stod(str2);
					
				}
				if (pos3 != string::npos) {
					string::size_type pos1{};
					str3.erase(0, pos3 + 18);
					countRoom = stoi(str3);

				}
				push_back(addres, price, countRoom);
				
			}
		}
	}
	/*void sort() {
		for (int i = 1; i < size - 1; i++) {
			Node* pFirst = first;
			Node* pNext = first->next;
			Node* pFictiv = first;
			for (int j = 1; j < size - 1; j++) {					
				if(pNext->countRoom < pFirst->countRoom){					
					if (i == 1) {
						pFirst->next = pNext->next;
						pNext->next = pFirst;
					}
					else {
						pFirst->next = pNext->next;
						pNext->next = pFirst;
						pFictiv->next = pNext;
					}
				}
				if (j % 2 != 0) {
					pFictiv->next = pNext->next;
				}
				pFirst = pFirst->next;
				pNext = pNext->next;
			}
		}
	}*/
	void slist_for_countRoom() {
		Node* t, * m, * a, * b;
		if (first == NULL)
			return;

		for (bool go = true; go; ) {
			go = false;
			a = t = first;
			b = first->next;

			while (b != NULL) {
				if (a->countRoom > b->countRoom) {
					if (t == a)
						first = b;
					else
						t->next = b;

					a->next = b->next;
					b->next = a;

					m = a, a = b, b = m;
					go = true;
				}
				t = a;
				a = a->next;
				b = b->next;
			}
		}
	}
	void slist_for_price() {
		Node* t, * m, * a, * b;
		if (first == NULL)
			return;

		for (bool go = true; go; ) {
			go = false;
			a = t = first;
			b = first->next;

			while (b != NULL) {
				if (a->price > b->price) {
					if (t == a)
						first = b;
					else
						t->next = b;

					a->next = b->next;
					b->next = a;

					m = a, a = b, b = m;
					go = true;
				}
				t = a;
				a = a->next;
				b = b->next;
			}
		}
	}
	void slist_for_addres() {
		Node* t, * m, * a, * b;
		if (first == NULL)
			return;

		for (bool go = true; go; ) {
			go = false;
			a = t = first;
			b = first->next;

			while (b != NULL) {
				if (a->addres > b->addres) {
					if (t == a)
						first = b;
					else
						t->next = b;

					a->next = b->next;
					b->next = a;

					m = a, a = b, b = m;
					go = true;
				}
				t = a;
				a = a->next;
				b = b->next;
			}
		}
	}
};





int main() {

	setlocale(LC_ALL, "");
	list l;
	
	//cout << "Введите адрес файла" << endl;

	//cin >> path;

	fs.open(path, fstream::in | fstream::out);
	fin.open(path);

	
	if (!fs.is_open() && !fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт!" << endl;
		l.copy_in_list();
		while (true) {
			int answer;
			cout << "1.Записать в блокнот\n2.Вывести список на экран\n3.Удалить из списка\n4.Cортировка.\n5.Выход" << endl;
			cin >> answer;
			switch (answer)
			{
			case 1: {
				string addres;
				double price;
				int countRoom;				
				cout << "Введите цену" << endl;
				cin >> price;
				cout << "Введите количество комнат" << endl;
				cin >> countRoom;
				cout << "Введите адресс" << endl;
				cin >> addres;
				l.push_back(addres,price,countRoom);
				l.print_in_file();
				break;
			}
			case 2: {
				l.print();
				cout << "Всего записей = " << l.size << endl;
				break;
			}
			case 3: {
				int a;
				cout << "Введите номер в списке для удаления" << endl;
				cin >> a;
				l[a];
				l.print_in_file();
				break;
			}
			case 5: {
				l.print_in_file();
				return 0;
				
			}
			case 4: {
				int answer;
				cout << "Выберите варинат сортировки \n1.По комнатам\n2.По алфавиту\n3.По цене" << endl;
				cin >> answer;
				if (answer == 1) {
					l.slist_for_countRoom();
					l.print_in_file();
					break;
				}if (answer == 2) {
					l.slist_for_addres();
					l.print_in_file();
					break;
				}if (answer == 3) {
					l.slist_for_price();
					l.print_in_file();
					break;
				}
				else {
					cout << "Нет такого ответа" << endl;
					break;
				}
				
			}
			default:
				break;
			}

		}

		fin.close();
		fs.close();
	}

	



	system("PAUSE");
	return 0;
}