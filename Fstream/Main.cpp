#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void  file_insert(string path, int pos, string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	string path = "file.txt";

	//Класс FSTREAM
	/*fstream file;
	file.open(path,ios::in | ios::app);

	if (file.is_open()) {
		cout << "Файл открыт.\n";
		//Запись в файл
		file << "Bye world!\n";
		cout << "Данные записаны.\n";
		file.seekg(0,ios::beg);// перемещение курсора для считывания в начало файла
		//Считывание из файла
		cout << "Содержимое файла\n";
		char sym;
		while (file.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка открытия файла.\n";
	file.close();*/

	//Задание "Запись в файл"
	/*cout << "Введите строку: ";
	string str;
	getline(cin, str);
	cout << "Введите позицию: ";
	cin >> n;
	file_insert(path, n, str);*/
	//Задача 1.Дата из файла
	cout << "Задача 1\n";
	ifstream in;
	in.open("date.txt");

	if (in.is_open()) {
		int day, month, year;
		string  tmp;
		getline(in, tmp);  //из объекта  in в tmp
		day = stoi(tmp);
		cout << "День: " << day << endl;
		month = stoi(tmp.substr(tmp.find('.')+ 1));
		cout << "Месяц: " << month << endl;
		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		cout << "Год: " << year << endl;
	}
	else
		cout << "Ошибка открытия файла.\n\n";

	in.close();

	return 0;
}
void  file_insert(string path, int pos, string str) {
	//Шаг 1. Копируем содержимое файла в строку tmp
	ifstream in;
	in.open(path);// если файл открыт успешно
	string tmp;
	

	if (in.is_open()) {
		char sym;
		while (in.get(sym))//считывание посимвольно с помощью get
			tmp += sym;
	}
	in.close();
	/*cout << tmp;*/ //промежуточный вывод
	//Шаг 2 . Вставляем содержимое в строку tmp
	tmp.insert(pos, str);
	//Шаг 3. Заменяем содержимое файла на строку tmp
	ofstream out;
	out.open(path);
	if (out.is_open())
		out << tmp;
	out.close();
}