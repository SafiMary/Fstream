#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void  file_insert(string path, int pos, string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	string path = "file.txt";

	//����� FSTREAM
	/*fstream file;
	file.open(path,ios::in | ios::app);

	if (file.is_open()) {
		cout << "���� ������.\n";
		//������ � ����
		file << "Bye world!\n";
		cout << "������ ��������.\n";
		file.seekg(0,ios::beg);// ����������� ������� ��� ���������� � ������ �����
		//���������� �� �����
		cout << "���������� �����\n";
		char sym;
		while (file.get(sym))
			cout << sym;
	}
	else
		cout << "������ �������� �����.\n";
	file.close();*/

	//������� "������ � ����"
	/*cout << "������� ������: ";
	string str;
	getline(cin, str);
	cout << "������� �������: ";
	cin >> n;
	file_insert(path, n, str);*/
	//������ 1.���� �� �����
	cout << "������ 1\n";
	ifstream in;
	in.open("date.txt");

	if (in.is_open()) {
		int day, month, year;
		string  tmp;
		getline(in, tmp);  //�� �������  in � tmp
		day = stoi(tmp);
		cout << "����: " << day << endl;
		month = stoi(tmp.substr(tmp.find('.')+ 1));
		cout << "�����: " << month << endl;
		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		cout << "���: " << year << endl;
	}
	else
		cout << "������ �������� �����.\n\n";

	in.close();

	return 0;
}
void  file_insert(string path, int pos, string str) {
	//��� 1. �������� ���������� ����� � ������ tmp
	ifstream in;
	in.open(path);// ���� ���� ������ �������
	string tmp;
	

	if (in.is_open()) {
		char sym;
		while (in.get(sym))//���������� ����������� � ������� get
			tmp += sym;
	}
	in.close();
	/*cout << tmp;*/ //������������� �����
	//��� 2 . ��������� ���������� � ������ tmp
	tmp.insert(pos, str);
	//��� 3. �������� ���������� ����� �� ������ tmp
	ofstream out;
	out.open(path);
	if (out.is_open())
		out << tmp;
	out.close();
}