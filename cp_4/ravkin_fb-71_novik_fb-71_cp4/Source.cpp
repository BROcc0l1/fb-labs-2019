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
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void polinoms(vector <int> T1)
{
	//2-gramm количество
	map <string, int> bigram_kolvo;
	string bigrama; char symbol_1, symbol_2;
	for (int i = 0; i < T1.size() - 1; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		bigrama.push_back(symbol_1);
		bigrama.push_back(symbol_2);
		auto iter = bigram_kolvo.find(bigrama);
		if (iter == bigram_kolvo.end()) { bigram_kolvo.emplace(bigrama, 1); }
		else { iter->second++; }
		bigrama.clear();
	}
	for (auto it = bigram_kolvo.begin(); it != bigram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	//3-gramm количество
	map <string, int> trigram_kolvo;
	string trigrama; char symbol_3;
	for (int i = 0; i < T1.size() - 2; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		trigrama.push_back(symbol_1);
		trigrama.push_back(symbol_2);
		trigrama.push_back(symbol_3);
		auto iter = trigram_kolvo.find(trigrama);
		if (iter == trigram_kolvo.end()) { trigram_kolvo.emplace(trigrama, 1); }
		else { iter->second++; }
		trigrama.clear();
	}
	for (auto it = trigram_kolvo.begin(); it != trigram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	//4-gramm количество
	map <string, int> gram_kolvo;
	string grama; char symbol_4;
	for (int i = 0; i < T1.size() - 3; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();
	//5-gramm количество
	char symbol_5;
	for (int i = 0; i < T1.size() - 4; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();
	//6-gramm количество
	char symbol_6;
	for (int i = 0; i < T1.size() - 5; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_6 = '0'; }
		else { symbol_6 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		grama.push_back(symbol_6);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();

	//7-gramm количество
	char symbol_7;
	for (int i = 0; i < T1.size() - 6; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_6 = '0'; }
		else { symbol_6 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_7 = '0'; }
		else { symbol_7 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		grama.push_back(symbol_6);
		grama.push_back(symbol_7);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();

	//8-gramm количество
	char symbol_8;
	for (int i = 0; i < T1.size() - 7; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_6 = '0'; }
		else { symbol_6 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_7 = '0'; }
		else { symbol_7 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_8 = '0'; }
		else { symbol_8 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		grama.push_back(symbol_6);
		grama.push_back(symbol_7);
		grama.push_back(symbol_8);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();
	//9-gramm количество
	char symbol_9;
	for (int i = 0; i < T1.size() - 8; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_6 = '0'; }
		else { symbol_6 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_7 = '0'; }
		else { symbol_7 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_8 = '0'; }
		else { symbol_8 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_9 = '0'; }
		else { symbol_9 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		grama.push_back(symbol_6);
		grama.push_back(symbol_7);
		grama.push_back(symbol_8);
		grama.push_back(symbol_9);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();
	//10-gramm количество
	char symbol_10;
	for (int i = 0; i < T1.size() - 9; i++)
	{
		if (T1[i] == 0) { symbol_1 = '0'; }
		else { symbol_1 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_2 = '0'; }
		else { symbol_2 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_3 = '0'; }
		else { symbol_3 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_4 = '0'; }
		else { symbol_4 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_5 = '0'; }
		else { symbol_5 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_6 = '0'; }
		else { symbol_6 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_7 = '0'; }
		else { symbol_7 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_8 = '0'; }
		else { symbol_8 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_9 = '0'; }
		else { symbol_9 = '1'; }
		i++;
		if (T1[i] == 0) { symbol_10 = '0'; }
		else { symbol_10 = '1'; }
		grama.push_back(symbol_1);
		grama.push_back(symbol_2);
		grama.push_back(symbol_3);
		grama.push_back(symbol_4);
		grama.push_back(symbol_5);
		grama.push_back(symbol_6);
		grama.push_back(symbol_7);
		grama.push_back(symbol_8);
		grama.push_back(symbol_9);
		grama.push_back(symbol_10);
		auto iter = gram_kolvo.find(grama);
		if (iter == gram_kolvo.end()) { gram_kolvo.emplace(grama, 1); }
		else { iter->second++; }
		grama.clear();
	}
	for (auto it = gram_kolvo.begin(); it != gram_kolvo.end(); ++it)
	{
		cout << it->first << "  " << it->second << endl;
	}
	gram_kolvo.clear();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////karelyaciya
	int sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 1) { sum_ka += (T1[i] + T1[0]) % 2; break; }
		sum_ka += (T1[i] + T1[i + 1]) % 2;

	}
	cout << "1:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 2) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2; break;
		}
		sum_ka += (T1[i] + T1[i + 2]) % 2;

	}
	cout << "2:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 3) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 3]) % 2;

	}
	cout << "3:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 4) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 4]) % 2;

	}
	cout << "4:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 5) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 5]) % 2;

	}
	cout << "5:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 6) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2;
			sum_ka += (T1[i + 5] + T1[5]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 6]) % 2;

	}
	cout << "6:" << sum_ka << endl;

	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 7) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2;
			sum_ka += (T1[i + 5] + T1[5]) % 2;
			sum_ka += (T1[i + 6] + T1[6]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 7]) % 2;

	}
	cout << "7:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 8) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2;
			sum_ka += (T1[i + 5] + T1[5]) % 2;
			sum_ka += (T1[i + 6] + T1[6]) % 2;
			sum_ka += (T1[i + 7] + T1[7]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 8]) % 2;

	}
	cout << "8:" << sum_ka << endl;

	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 9) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2;
			sum_ka += (T1[i + 5] + T1[5]) % 2;
			sum_ka += (T1[i + 6] + T1[6]) % 2;
			sum_ka += (T1[i + 7] + T1[7]) % 2;
			sum_ka += (T1[i + 8] + T1[8]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 9]) % 2;

	}
	cout << "9:" << sum_ka << endl;
	sum_ka = 0;
	for (int i = 0; i < T1.size(); i++)
	{
		if (i == T1.size() - 10) {
			sum_ka += (T1[i] + T1[0]) % 2;
			sum_ka += (T1[i + 1] + T1[1]) % 2;
			sum_ka += (T1[i + 2] + T1[2]) % 2;
			sum_ka += (T1[i + 3] + T1[3]) % 2;
			sum_ka += (T1[i + 4] + T1[4]) % 2;
			sum_ka += (T1[i + 5] + T1[5]) % 2;
			sum_ka += (T1[i + 6] + T1[6]) % 2;
			sum_ka += (T1[i + 7] + T1[7]) % 2;
			sum_ka += (T1[i + 8] + T1[8]) % 2;
			sum_ka += (T1[i + 9] + T1[9]) % 2; break;
		}

		sum_ka += (T1[i] + T1[i + 10]) % 2;

	}
	cout << "10:" << sum_ka << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	
	vector <int> polinom_1{  1,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1 };
	vector <int> signal_1{   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> signal_1_1{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> polinom_2{  1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,1,1,1,1 };
	vector <int> signal_2{   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> signal_2_2{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	//Заполняем Т1___________________________________________________________________________________________________________________________________
	vector <int> T1;
	int sum = 0;
	int new_chislo;
	do
	{
		for (int i = 0; i < polinom_1.size(); i++)
		{
			sum = polinom_1[i] * signal_1[i] + sum;
		}
		new_chislo = sum % 2;
		T1.push_back(signal_1[0]);
		signal_1.erase(signal_1.begin());
		signal_1.push_back(new_chislo);
		sum = 0;
	} while (signal_1 != signal_1_1);
	//Заполнили Т1___________________________________________________________________________________________________________________________________
	cout << "T для первого полинома:" << T1.size() << endl;

	//Заполняем Т2___________________________________________________________________________________________________________________________________
	vector <int> T2;
	sum = 0;
	do
	{
		for (int i = 0; i < polinom_2.size(); i++)
		{
			sum += polinom_2[i] * signal_2[i];
		}
		new_chislo = sum % 2;
		signal_2.push_back(new_chislo);
		T2.push_back(signal_2[0]);
		signal_2.erase(signal_2.begin());
		sum = 0;
	} while (signal_2 != signal_2_2);
	//Заполнили Т2___________________________________________________________________________________________________________________________________
	cout << "T для второго полинома:" << T2.size() << endl;
	polinoms(T1);
	polinoms(T2);
}