#include "windows.h"
#include <iostream>
#include <fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
	map<char, int> m = { {'о', 0},{'а', 0},{'е', 0},{'и', 0},{'н', 0},{'т', 0},{'р', 0},{'с', 0},{'л', 0},{'в', 0},{'к', 0},{'п', 0},{'м', 0},{'у', 0},{'д', 0},{'я', 0},{'ы', 0},{'ь', 0},{'з', 0},{'б', 0},{'г', 0},{'й', 0},{'ч', 0},{'ю', 0},{'х', 0},{'ж', 0},{'ш', 0},{'ц', 0},{'щ', 0},{'ф', 0},{'э', 0},{'Ъ', 0},{'ё', 0},{'Й', 0},{'Ц', 0},{'У', 0},{'К', 0},{'Е', 0},{'Н', 0},{'Г', 0},{'Ш', 0},{'Щ', 0},{'З', 0},{'Х', 0},{'Ъ', 0},{'Ё', 0},{'Ф', 0},{'Ы', 0},{'В', 0},{'А', 0},{'П', 0},{'Р', 0},{'О', 0},{'Л', 0},{'Д', 0},{'Ж', 0},{'Э', 0},{'Я', 0},{'Ч', 0},{'С', 0},{'М', 0},{'И', 0},{'Т', 0},{'Ь', 0},{'Б', 0},{'Ю', 0},{' ',0} };
	vector <pair<string, int>> vector_b;
	setlocale(LC_ALL, "Rus");

	ifstream file("D:\\VISUAL STUDIO 4\\Project3\\text.txt");
	ofstream file_after_filter_with_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space.txt");
	ofstream file_after_filter_without_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");
	ofstream file_after_filter_with_space2("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");

	if (!file) { cout << "Файл не открыт\n\n"; }
	else { cout << "Все ОК! Файл открыт!\n\n"; }

	int n = 0;
	char ch = 'а';
	while (file.get(ch)) {

		auto it = m.find(ch);
		if (it != m.end()) {

			if (((it->first) >= 'А') && ((it->first) <= 'Я'))
			{
				ch = it->first + ('я' - 'Я');
			}
			else { ch = it->first; }
			file_after_filter_with_space << ch;

		}
	}
	file.close();
	file_after_filter_with_space.close();

	ifstream file_with_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space.txt");

	if (!file_with_space) { cout << "Файл2 не открыт\n\n"; }
	else { cout << "Все ОК! Файл открыт!\n\n"; }
	char pred = '!';
	while (file_with_space.get(ch)) {

		if (!(pred == ' ' && ch == ' ')) {
			if (ch == 'Ъ' || ch == 'ъ')ch = 'ь';
			if (ch == 'Ё' || ch == 'ё')ch = 'е';
			auto iter = m.find(ch);
			if (iter != m.end()) { iter->second++; }
			file_after_filter_with_space2 << ch;
			n++;
		}
		pred = ch;
	}
	file_with_space.close();
	file_after_filter_with_space2.close();
	ifstream file3("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	while (file3.get(ch))
	{
		if ((ch != ' ')) {
			file_after_filter_without_space << ch;
		}
	}
	map<unsigned, string>::iterator it;
	//частоат букв

	vector<pair<int, char>> vector;
	for (auto it = m.begin(); it != m.end(); it++) {
		vector.push_back(make_pair(it->second, it->first));
	}
	sort(vector.rbegin(), vector.rend());
	float buff0 = 0;
	cout << "Частота букв с пробелом" << endl;
	for (int i = 0; i < 32; i++) {
		cout << vector[i].second << ":" << ((float)(vector[i].first) / n * 100) << " %" << endl;
		buff0 += ((float)(vector[i].first) / n * 100);
	}
	cout << buff0 << endl;
	cout << "всего символов: " << n << endl<<endl;
	file3.close();

	//частота биграмм
	ifstream file4("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	
	map <string, int> bigram;
	char ch1, ch2;
	string ch3;
	int nn = 0;
	while (!file4.eof()) {
		file4.get(ch1);
		file4.get(ch2);
		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else 
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	double buff=0;
	cout << "Частота биграмм в тексте с шагом 2 С ПРОБЕЛАМИ:" << endl;
	int l = 0;
	for (auto it = bigram.begin(); it != bigram.end(); it++) {

		cout<< it->first<<":"<<(double)it->second/nn*100<<" ";
		buff += (double)it->second / nn * 100;
	}
	cout << buff << endl;
	file4.close();

	//энтропия для монограмы с пробелами
	double H = 0;
	double p;
	for (int i = 0; i < 32; i++) {
		p = (double)vector[i].first / n;
		H += p * (log(1 / p)/log(2));
	}
	cout << endl;
	cout <<"энтропия для моногорамы c пробелами:\t\t" << H << endl;
	cout << "R для моногорамы c пробелами:\t\t\t" << 1 - (H / 5) <<endl;
	cout << endl;
	//энтропия для моногорамы без пробелов 1 вариант
	/*cout << vector[0].first << "probel" << endl;
	H = 0;
	p = 0;
	for (int i = 1; i < 32; i++) {
		
			p = (float)vector[i].first / (n-vector[0].first);
			H += p * log(1 / p);
		
	}
	
	cout << "энтропия для моногорамы без пробелов:" << H << endl;
	cout << n - vector[0].first << endl;
	*/
	//энтропия для моногорамы без пробелов 2 вариант
	ifstream file5("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");
	n = 0;
	H = 0;
	p = 0;
	vector.clear();
	for (auto it = m.begin(); it != m.end(); it++)
	{
		it->second = 0;
	}
	while (file5.get(ch)) {
		n++;
		auto it = m.find(ch);
		if (it != m.end()) { it->second++; }	
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		vector.push_back(make_pair(it->second, it->first));
	}
	sort(vector.rbegin(), vector.rend());
	buff0 = 0;
	cout << "Частота букв без пробела:" << endl;
	for (int i = 0; i < 31; i++) {
		cout << vector[i].second << ":" << ((float)(vector[i].first) / n * 100) << " %" << endl;
		buff0 += ((float)(vector[i].first) / n * 100);
		p = (float)vector[i].first / n;
		H += p * (log(1 / p)/log(2));
	}

	cout << buff0 << endl;
	cout << endl;
	cout <<"энтропия для моногораммы без пробелов:\t\t"<< H << endl;
	cout << "R для монограммы без пробелов:\t\t\t" << 1-(H / 5) << endl;
	//cout << n << endl;
	//ЭНТРОПИЯ ДЛЯ БИГРАММЫ С ПРОБЕЛАМИ С ШАГОМ 2
	H = 0;
	p = 0;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		p = (double)it->second / nn;
		H += (p * (log(1 / p) / log(2)))/2;
	}
	/*for (int i = 0; i < vector_b.size(); i++)
	{
		p = (float)vector_b[i].second / nn;
		H += p * (log(1 / p) / log(2));
	}
	*/
	cout << "энтропия для биграммы c пробелами С ШАГОМ 2:\t" << H << endl;
	cout << "R для биграммы c пробелами С ШАГОМ 2::\t\t" << 1-(H / 5) << endl;
	//ЭНТРОПИЯ ДЛЯ БИГРАММЫ БЕЗ ПРОБЕЛОВ С ШАГОМ 2
	ifstream file6("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");

	map <string, int> bigram2;
	H = 0;
	p = 0;
	nn = 0;
	while (!file6.eof()) {
		file6.get(ch1);
		file6.get(ch2);
		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram2.find(ch3);
		if (it == bigram2.end())
		{
			bigram2.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	vector_b.clear();
	cout << endl;
	cout << "Частота биграмм без пробелов С ШАГОМ 2:" << endl;
	cout << endl;
	for (auto it = bigram2.begin(); it != bigram2.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 << "  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl << endl;
	cout << "энтропия для биграмы без пробелов с шагом 2:\t" << H/2 << endl;
	cout << "R для биграммы без пробелов с шагом 2:\t\t" <<1 - H / 10 << endl;
	file6.close();
	file4.close();
	//ЭНТРОПИЯ ДЛЯ БИГРАММЫ С ПРОБЕЛАМИ С ШАГОМ 1
	//
	ifstream file7("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	bigram.clear();
	ch3.clear();
	nn = 0;
	H = 0;
	ch1 = '!';
	while (!file7.eof()) {
		if(ch1!='!')
		ch1 = ch2;
		else
		file7.get(ch1);

		file7.get(ch2);
		
		ch3.push_back(ch1);
		ch3.push_back(ch2);
		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	cout << endl;
	cout << "Частота биграмм в тексте с шагом 1 С ПРОБЕЛАМИ:" << endl;
	cout << endl;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 <<"  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl;
	cout << endl;
	cout << "ЭНТРОПИЯ ДЛЯ БИГРАММЫ С ПРОБЕЛАМИ С ШАГОМ 1:\t" << H/2  << endl;
	cout << "R ДЛЯ БИГРАММЫ С ПРОБЕЛАМИ С ШАГОМ 1:\t\t" << 1 - (H / 10) << endl;
	file7.close();
	//ЭНТРОПИЯ ДЛЯ БИГРАММЫ без пробелов С ШАГОМ 1
	ifstream file8("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");

	bigram.clear();
	H = 0;
	p = 0;
	nn = 0;
	ch3.clear();
	ch1 = '!';
	while (!file8.eof()) {
		if (ch1 != '!')
			ch1 = ch2;
		else
			file8.get(ch1);
			
		file8.get(ch2);

		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	cout << endl;
	cout << "Частота биграмм без пробелов С ШАГОМ 1:" << endl;
	cout << endl;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 << "  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl;
	cout << endl;
	cout << "энтропия для биграмы без пробелов c шагом 1:\t" << H / 2 << endl;
	cout << "R ДЛЯ БИГРАММЫ без пробелов С ШАГОМ 1:\t\t" << 1-(H / 10) << endl;
	cout << endl;
	return 0;
}