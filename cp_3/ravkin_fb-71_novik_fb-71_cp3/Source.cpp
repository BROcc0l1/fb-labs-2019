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
int A;
int B;
int x;
int y;
int gcd(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
void ab(int Y1, int Y2, int X1, int X2, int m, int& a, int& b,bool& gcd_31, vector<int>& gcd_31_a, vector<int>& gcd_31_b );
int main()
{
	


	SetConsoleOutputCP(1251);

	// ѕ”Ќ “ 2.  5 найчаст≥ших б≥грам запропонованого шифртексту (за вар≥антом:12)-----------------------------------------------------------------------
	map <string, int> bigrama_kvo; vector<pair<int, string>> kvo_bigrama; char ch1, ch2; string ch1ch2;
	ifstream shifro_text_12("D:\\VISUAL STUDIO 4\\laba 3\\12.txt");
	while (!shifro_text_12.eof())
	{
		shifro_text_12.get(ch1);
		shifro_text_12.get(ch2);
		ch1ch2.push_back(ch1); ch1ch2.push_back(ch2);

		auto iterator_ch1ch2 = bigrama_kvo.find(ch1ch2);
		if (iterator_ch1ch2 == bigrama_kvo.end()) { bigrama_kvo.insert(pair<string, int>(ch1ch2, 1)); }
		else { iterator_ch1ch2->second++; }
		ch1ch2.clear();
	}
	for (auto it = bigrama_kvo.begin(); it != bigrama_kvo.end(); it++)
	{
		kvo_bigrama.push_back(make_pair(it->second, it->first));
	}
	sort(kvo_bigrama.rbegin(), kvo_bigrama.rend());
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	// ѕ”Ќ “ 3. ѕеребрати можлив≥ вар≥анти сп≥вставленн€ частих б≥грам мови та частих б≥грам шифртексту (розгл€даючи пари б≥грам ≥з пТ€ти найчаст≥ших). ƒл€ кожного сп≥вставленн€ знайти можлив≥ кандидати на ключ ) ,( b a шл€хом розвТ€занн€ системи (1). )-----------------------------------------------------------------------
	map <char, int> alf{ {'а',0},{'б',1},{'в',2},{'г',3},{'д',4},{'е',5},{'ж',6},{'з',7},{'и',8},{'й',9},{'к',10},{'л',11},{'м',12},{'н',13},{'о',14},{'п',15},{'р',16},{'с',17},{'т',18},{'у',19},{'ф',20},{'х',21},{'ц',22},{'ч',23},{'ш',24},{'щ',25} ,{'ь',26},{'ы',27},{'э',28},{'ю',29},{'€',30} };
	vector <int> X1_X2_X3_X4_X5 = { 545,417,572,403,168 };
	vector <int> Y1_Y2_Y3_Y4_Y5; string bigramaa; char a = 'а'; char b = 'б'; int y1, y2; int counter = 0;
	for (auto it = kvo_bigrama.begin(); it != kvo_bigrama.end(); ++it) //«јѕќЋЌя≈ћ „»—Ћјћ» Y1 Y2 Y3 Y4 Y5
	{
		counter++;
		bigramaa = it->second;
		a = bigramaa[0];
		b = bigramaa[1];
		auto iter = alf.find(a);
		y1 = iter->second;
		iter = alf.find(b);
		y2 = iter->second;
		Y1_Y2_Y3_Y4_Y5.push_back(y1 * 31 + y2);
		if (counter == 5) { break; }
	}                                  // «јѕќЋЌ»Ћ» „»—Ћјћ» Y1 Y2 Y3 Y4 Y5

	multimap < int, int> pari_X_Y_25;
	int X; int Y; int i = 0;
	for (int i = 0; i <= 4; i++) {
		X = X1_X2_X3_X4_X5[i];
		for (int y = 0; y <= 4; y++)
		{
			Y = Y1_Y2_Y3_Y4_Y5[y];
			pari_X_Y_25.insert(pair<int, int>(X, Y));
		}
	}
	//int count = 0; int w = 0;
	int X1, X2, Y1, Y2, Z, XX;
	shifro_text_12.close();
	ifstream shifro_text2_12("D:\\VISUAL STUDIO 4\\laba 3\\12.txt");
	map <int, char> alf2{ { 0, 'а'},{1, 'б'},{2, 'в'},{3, 'г'},{4, 'д'},{5, 'е'},{6, 'ж'},{7, 'з'},{8, 'и'},{9, 'й'},{10, 'к'},{11, 'л'},{12, 'м'},{13, 'н'},{14, 'о'},{15, 'п'},{16, 'р'},{17, 'с'},{18,'т'},{19, 'у'},{20, 'ф'},{21, 'х'},{22, 'ц'},{23, 'ч'},{24, 'ш'},{25, 'щ'},{26, 'ь'},{27, 'ы'},{28, 'э'},{29, 'ю'},{30, '€'} };
	vector <string> VT;
	string vt;
	bool gcd_31;
	vector <int> gcd_31_a;
	vector <int> gcd_31_b;
	for (auto it = pari_X_Y_25.begin(); it != pari_X_Y_25.end(); ++it)
	{

		for (auto iter = pari_X_Y_25.begin(); iter != pari_X_Y_25.end(); ++iter)
		{
			if (it->first == 572) { break; }
			//if (it->first == 417 && iter->first == 572) { break; }
			cout << it->first << "  " << iter->first << endl;
			gcd_31 = false;
			ab(it->second, iter->second, it->first, iter->first, 961, A, B, gcd_31, gcd_31_a, gcd_31_b);
			if (gcd_31)
			{
				for (int i = 0; i < 31; i++) {

					gcd(gcd_31_a[i], 31, x, y);
					if (x < 0) while (x < 0) x += 31;
					if (x > 0) while (x > 31) x -= 31;
					while (!shifro_text2_12.eof())
					{
						shifro_text2_12.get(ch1);
						shifro_text2_12.get(ch2);
						auto it1 = alf.find(ch1);


						auto it2 = alf.find(ch2);
						int Z = it1->second * 31 + it2->second;
						int XX = (Z - gcd_31_b[i]) * x;
						if (XX > 0) { while (XX > 31) XX = XX - 31; }
						if (XX < 0) { while (XX < 0) XX = XX + 31; }
						int x2 = XX % 31;
						int x1 = (XX - x2) / 31;
						auto it_x1 = alf2.find(x1);
						if (it_x1 == alf2.end()) { cout << "it_x1" << endl; }
						auto it_x2 = alf2.find(x2);
						if (it_x2 == alf2.end()) { cout << "it_x2" << endl; }
						vt.push_back(it_x1->second);
						vt.push_back(it_x2->second);
						//VT[i].push_back(it_x1->second);
						//VT[i].push_back(it_x2->second);

					}
					VT.push_back(vt);
					vt.clear();
					//shifro_text2_12.close();
					shifro_text2_12.clear();
					shifro_text2_12.seekg(0, ios_base::beg);

					/*
					cout << "ѕара " << endl;
					cout << " X: "<<it->first;
					cout << " Y: " << it->second;
					cout << endl;
					cout << "и пара" << endl;
					cout << "X: " << iter->first;
					cout << "Y: " << iter->second;
					cout << endl;
					cout << endl;
					*/
					//count++;
				}
				gcd_31_a.clear();
				gcd_31_b.clear();
				gcd_31 = false;
			}
			else
			{
				gcd(A, 961, x, y);
				if (x < 0) while (x < 0) x += 961;
				if (x > 0) while (x > 961) x -= 961;
				while (!shifro_text2_12.eof())
				{
					shifro_text2_12.get(ch1);
					shifro_text2_12.get(ch2);
					auto it1 = alf.find(ch1);


					auto it2 = alf.find(ch2);
					int Z = it1->second * 31 + it2->second;
					int XX = (Z - B) * x;
					if (XX > 0) { while (XX > 961) XX = XX - 961; }
					if (XX < 0) { while (XX < 0) XX = XX + 961; }
					int x2 = XX % 31;
					int x1 = (XX - x2) / 31;
					auto it_x1 = alf2.find(x1);
					auto it_x2 = alf2.find(x2);
					vt.push_back(it_x1->second);
					vt.push_back(it_x2->second);
					//VT[i].push_back(it_x1->second);
					//VT[i].push_back(it_x2->second);

				}


				VT.push_back(vt);
				vt.clear();
				//shifro_text2_12.close();
				shifro_text2_12.clear();
				shifro_text2_12.seekg(0, ios_base::beg);
			}

		}

	}
		
	
		//cout << count << endl;
		for (auto x : VT)
		{
			if (x[0] != 'а' && x[1] != 'а' && x[2] != 'а')
			{
				bool boo = true;
				for (int i = 0; i < x.size(); i++)
				{
					ch1 = x[i];
					ch2 = x[i + 1];
					ch1ch2.push_back(ch1);
					ch1ch2.push_back(ch2);
					if (ch1ch2 == "аы" || ch1ch2 == "оы" || ch1ch2 == "еы" || ch1ch2 == "уы" || ch1ch2 == "оы" || ch1ch2 == "аь" || ch1ch2 == "оь" || ch1ch2 == "еь" || ch1ch2 == "иь" || ch1ch2 == "уь")
					{
						boo = false;
						ch1ch2.clear();
						break;
					}
					ch1ch2.clear();
				}
				if (boo)
				{
					for (int i = 0; i < x.size(); i++)
					{
						cout << x[i];
					}
					break;
				}
			}
		}

		//shifro_text2_12.close();
		/*
	  char ch1, ch2;
	  map <char, int> alf{ {'а',0},{'б',1},{'в',2},{'г',3},{'д',4},{'е',5},{'ж',6},{'з',7},{'и',8},{'й',9},{'к',10},{'л',11},{'м',12},{'н',13},{'о',14},{'п',15},{'р',16},{'с',17},{'т',18},{'у',19},{'ф',20},{'х',21},{'ц',22},{'ч',23},{'ш',24},{'щ',25} ,{'ы',26},{'ь',27},{'э',28},{'ю',29},{'€',30} };
	  map <int, char> alf2{ { 0, 'а'},{1, 'б'},{2, 'в'},{3, 'г'},{4, 'д'},{5, 'е'},{6, 'ж'},{7, 'з'},{8, 'и'},{9, 'й'},{10, 'к'},{11, 'л'},{12, 'м'},{13, 'н'},{14, 'о'},{15, 'п'},{16, 'р'},{17, 'с'},{18,'т'},{19, 'у'},{20, 'ф'},{21, 'х'},{22, 'ц'},{23, 'ч'},{24, 'ш'},{25, 'щ'},{26, 'ы'},{27, 'ь'},{28, 'э'},{29, 'ю'},{30, '€'} };
	  vector <string> VT;
	  string vt;
		ifstream shifro_text2_12("D:\\VISUAL STUDIO 4\\laba 3\\12.txt");
		  ab(165, 478, 545, 417, 961, A, B);
		cout << "a=" << A << endl;
		cout << "b=" << B << endl;
		gcd(A, 961, x, y);
		if (x < 0) while (x < 0) x += 961;
		if (x > 0) while (x > 961) x -= 961;
		while (!shifro_text2_12.eof())
		{
		  shifro_text2_12.get(ch1);
		  shifro_text2_12.get(ch2);
		  auto it1 = alf.find(ch1);
		  auto it2 = alf.find(ch2);
		  int Z = it1->second * 31 + it2->second;
		  int XX = (Z - B) * x;
		  if (XX > 0) { while (XX > 961) XX = XX - 961; }
		  if (XX < 0) { while (XX < 0) XX = XX + 961; }
		  int x2 = XX % 31;
		  int x1 = (XX - x2) / 31;
		  auto it_x1 = alf2.find(x1);
		  auto it_x2 = alf2.find(x2);
		  vt.push_back(it_x1->second);
		  vt.push_back(it_x2->second);
		  //VT[i].push_back(it_x1->second);
		  //VT[i].push_back(it_x2->second);

		}
		VT.push_back(vt);
		vt.clear();

		int Z = 444; // первые две буквы Ў“
		cout << "a_obratnoe=" << x << endl;
		int XX = (Z - B) * x;
		cout << "X=" << XX << endl;
		if (XX > 0) { while (XX > 961) XX = XX - 961; }
		if (XX < 0) { while (XX < 0) XX = XX + 961; }
		cout << "X=" << XX << endl;
		int x2 = XX % 31;
		int x1 = (XX - x2) / 31;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
		*/

	
}

void ab(int Y1, int Y2, int X1, int X2, int m, int& a, int& b, bool& gcd_31, vector<int>& gcd_31_a, vector<int>& gcd_31_b)
{
	int g = gcd(X1 - X2, m, x, y);
	//cout << "d=" << g << endl;
	if (g == 1){
		x = (x % m + m) % m;
		//cout << "ќбратное:" << x << endl;
	
	a = (Y1 - Y2) * x;
	if (a > 0)
		while (a > m) a = a - m;
	if (a < 0)
		while (a < 0) a = a + m;

	b = Y1 - a * X1;
	if (b < 0)
		while (b < 0) b = b + m;

	if (b > m)
		while (b > m) b = b - m;
	}
	///*
	if(g>1)
	{
		gcd_31 = true;
		a=(Y1 - Y2)* x / 31;
		m = m / 31;
		if (a > 0)
			while (a > m) a = a - m;
		if (a < 0)
			while (a < 0) a = a + m;
		gcd_31_a.push_back(a);
		for (int i = 1; i < 31; i++)
		{
			a = a + i * 31;
			gcd_31_a.push_back(a);
		}
		
		for (int i = 0; i < 31; i++)
		{
			gcd_31_b.push_back(Y1 - gcd_31_a[i] * X1);
		}

	}
	//*/
}