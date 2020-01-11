// Crypt_laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string>

using namespace std;
double res = 0;

char* arr(char* S, int num);
const char filetext[] = "E:\\VisualStudio17\\Projects or only code\\Crypt_laba1\\input.TXT";//файл с текстом 

int fre2file(int l, char* text);// функция, которая считает частоту 2-букв
int frefile(int l, char* text);// функция, которая считает частоту букв 
string alp = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
int main()
{
	setlocale(LC_ALL, "Russian");
	int countt = 0; //длина текста в файле
	ifstream f(filetext);
	while (!f.eof())
	{
		f.get();//Извлекает один символ из потока.
		countt++;
	}
	f.close();

    ifstream ff(filetext);  //создаем поток для работы с файлом
	string s;
	s.assign((istreambuf_iterator<char>(ff.rdbuf())), istreambuf_iterator<char>());
	cout <<"Подлинный текст файла: "<< s << endl;//выводим текст файла
	ff.close(); //закрываем файл

	char* S2 = new char[countt]; //выделяем память по определенному числу символов
	for (int i = 0; i < countt; i++) S2[i] = NULL;

	ifstream f2(filetext);  //создаем поток для работы с файлом
	int i = 0; // номер буквы 
	while (!f2.eof()) //проходим по файлу
	{
		char letter;
		f2.get(S2[i]); //записываем символы
		letter = S2[i];
	    S2[i] = tolower(letter); //проверка буквы на регистр 
		if (alp.find(S2[i]) != string::npos) { i++; }//string::npos без позиции*/
		else {
			S2[i] = NULL;
			countt--;
		}    //переходим для записи следующего символа
	}
	char* S22 = new char[countt];
	f2.close(); //закрываем файл

	cout << "Текст новый: " << S2 << endl;//выводим обраб. текст 
	S22 = arr(S2, countt);
	frefile(countt, S2);
	fre2file(countt, S22);
	//////////////////
	delete[]S22;
	delete[]S2; //освобождаем память
	return 0;
}

char* arr(char* S, int num) {
	char* S2 = new char[num]; // Выделение памяти для массива
	for (int i = 0; i < num; i++) {
		S2[i] = S[i];
	}
	return S2;
}

int fre2file(int l, char* text) {// функция, которая считает частоту 2-букв
	int count, num = 0;
	double result = 0;
	string key{};
	string* bigramm = new string[l];
	string  a, b;
	string c;
	for (int i = 0; i < l - 1; i++) {//рaзбиваем текст на биграммы
		a = b = '/0';
		a = text[i];
		b = text[i + 1];
		bigramm[i] = a + b;
		cout << "bigramm " << bigramm[i] << endl;
	}
	for (int i = 0; i < l - 1; i++) {
		count = 0;
		key = '/0';
		key = bigramm[i];
		if (key != "0") {
			for (int j = i; j < l - 1; j++) {
				if (bigramm[j] == key) {
					count++;
				}
			}
			double frequency;
			cout << endl;
			cout << "bigramm " << bigramm[i] << " кол-во повторений биграммы " << count << endl;
			frequency = double(count) / double(l - 1);
			cout << "frequency for bigramm '" << bigramm[i] << "': " << frequency << endl;
			num++;
			result = result + (-1) * frequency * (log(frequency) / log(2));//сумма энтропий  
			cout << "result " << result << endl;
			for (int z = i; z < l - 1; z++) {
				if (bigramm[z] == key) {
					bigramm[z] = '/0';
				}
			}
		}
	}
	double redundancy, entropybigramm, logm;
	entropybigramm = result / (2 * num);
	logm = log(33) / log(2);
	redundancy = 1 - entropybigramm / logm;
	cout << "full entropyya for [H2]: " << entropybigramm << endl;//энтропия Н2
	cout << "redundancy for [H2]: " << redundancy << endl;//избыточность Н2
	return 0;
}
int frefile(int l, char* text) {// функция, которая считает частоту букв 
	int num = 0, ckey = -1;
	double result = 0;
	char* key = new char[l];
	setlocale(LC_ALL, "Russian");
	cout << "length: " << l << endl;
	for (int i = 0; i < l; i++) {
		ckey++;
		key[ckey] = NULL;
		int count = 0;
		key[ckey] = text[i];
		if (key[ckey] != NULL) {
			cout << endl;
			cout << "key: '" << key[ckey] << "'" << endl;
			if (key[ckey] != NULL) {
				for (int j = i; j < l; j++) {
					if (text[j] == key[ckey]) {
						count++;// cout << "count " << count << endl;
					}
				}
			}
			double frequency;
			frequency = double(count) / double(l);//частота буквы
			cout << "frequency '" << key[ckey] << "': " << frequency << endl;
			cout << "кол-во повторений буквы "<< key[ckey] <<" : " << count<<endl;
			num++;                //кол-во неповтор. букв
			result = result + (-1) * frequency * (log(frequency) / log(2));//сумма энтропий
			cout << "result " << result << endl;
			for (int z = i; z < l; z++) {
				if (text[z] == key[ckey]) text[z] = NULL;
			}
		}
	}
	double redundancy, entropy, logm;
	entropy = result / num;
	logm = log(33) / log(2);
	redundancy = 1 - (entropy / logm);
	cout << "full entropyya for [H1]: " << entropy << endl;//энтропия Н1
	cout << "redundancy for [H2]: " << redundancy << endl;//избыточность Н1
	cout << endl;
	return 0;
}
