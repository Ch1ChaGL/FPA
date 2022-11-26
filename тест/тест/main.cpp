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
/*���� ���������� ���������������� ����, ��������� �� ��������� ������� � ����������� �� ������� �������������*/
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
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {};
	//������� �������� ������� ����� � ������
	bool is_empty() {
		return first == nullptr;
	}
	//������� ���������� �������� � ����� ������
	void push_back(string _addres, float _price, int _countRoom) {
		Node* p = new Node(_addres, _price, _countRoom);
		//���� ������ ������, �� �������� ��������� �� ������ � ��������� ������ ����� ������
		if (_addres == "" || _price == 0 || _countRoom == 0) return;
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		//���� ������ �� ������
		last->next = p;
		last = p;
	}

	void print_in_file() {
		fs.close();
		fs1.open(path);
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			fs1 << "������: " << p->addres<<"," << " ����: " << p->price << "," << " ���������� ������: " << p->countRoom << endl;
			p = p->next;
		}
		fs1.close();
	}
	
	void print() {
		int i = 0;
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			
			cout <<i++<<" ������: " << p->addres<< " ����: " << p->price << " ���������� ������: " << p->countRoom << endl;
			p = p->next;

		}
	}

	//������� ������ ���� �� ��������� ��������
	Node* find(string _addres, float _price, int _countRoom) {
		if (is_empty()) return nullptr;
		Node* p = first;
		while (p && p->countRoom != _countRoom) p = p->next;
		return p;
	}

	//������� �������� ������� ����
	void remove_first() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}
	
	//������� �������� ���������� ����
	void remove_last() {
		if (is_empty())return;
		//���� ����� ������ ������������ ������
		if (first == last) {
			remove_first();
			return;
		}
		Node* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;


	}

	//������� �������� ���� �� ��������� ��������
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
			cout << "��� ������ ������� ������������" << endl;
			return;
		}
		pFirst->next = pNext->next;
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

	//����� �� ������� ����� ���������� ���������
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
				size_t pos = str.find("������: ");
				size_t pos2 = str2.find("����: ");
				size_t pos3 = str3.find("���������� ������: ");
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
};





int main() {

	setlocale(LC_ALL, "");
	list l;
	
	//cout << "������� ����� �����" << endl;

	//cin >> path;

	fs.open(path, fstream::in | fstream::out);
	fin.open(path);

	
	if (!fs.is_open() && !fin.is_open()) {
		cout << "������ �������� �����" << endl;
	}
	else {
		cout << "���� ������!" << endl;
		l.copy_in_list();
		while (true) {
			int answer;
			cout << "1.�������� � �������\n2.������� ������ �� �����\n3.������� �� ������\n4.�����" << endl;
			cin >> answer;
			switch (answer)
			{
			case 1: {
				string addres;
				double price;
				int countRoom;
				cout << "������� ������" << endl;
				cin >> addres;
				cout << "������� ����" << endl;
				cin >> price;
				cout << "������� ���������� ������" << endl;
				cin >> countRoom;
				l.push_back(addres,price,countRoom);
				l.print_in_file();
				break;
			}
			case 2: {
				l.print();
				break;
			}
			case 3: {
				int a;
				cout << "������� ����� � ������ ��� ��������" << endl;
				cin >> a;
				l[a];
				l.print_in_file();
				break;
			}
			case 4: {
				l.print_in_file();
				return 0;
				
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