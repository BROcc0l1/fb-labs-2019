#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
string Alpha = { 'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','€' };
//—читаем общее
void AlphaLink(string text, int *numb)
{
	for (;;)
	{
		if (text[(*numb)] == '\0') break;
		else (*numb)++;
	}

}
int modul(int indexbig,int letter)
{
	int newlet = 0;
	newlet = indexbig - letter;
	if (newlet < 0) newlet += 32;
	return newlet;
}

void monogramlink(int link, string  text2, int numbofalpha[32], string alpha,float Ind, int switcher, int letter)
{
	for (int i = 0; i <= link; i++)
	{
		for (int j = 0; j <= 31; j++)
		{
			if (text2[i] == alpha[j])
			{
				numbofalpha[j]++;
				break;
			}
		}
	}
	//вывод результата букв неотсортированный 
	int bigger = 0;
	int indexbig = 0;
	int newlet = 0;
		switch (switcher)
		{
		case 1:
			for (int i = 0; i <= 31; i++)
			{
				Ind += (float(numbofalpha[i]) * float(numbofalpha[i] - 1)) / (link * (link - 1));
			}
			std::cout << Ind << endl;
			break;
			
		case 2:
			
			for (int i = 0; i <= 31; i++)
			{
				if (numbofalpha[i] > bigger)
				{
					indexbig = i;
					bigger = numbofalpha[i];
				}
			}
			
			std::cout <<"["<<alpha[indexbig]<<"]["<<indexbig << "][" <<bigger  << "]\t["<<alpha[14] <<"]{"<< alpha[modul(indexbig, 14)] << "}" ;
			cout << "\t[" << alpha[5] << "]{" << alpha[modul(indexbig, 5)] << "}";
			cout << "\t[" << alpha[0] << "]{" << alpha[modul(indexbig, 0)] << "}";
			cout << "\t["<<alpha[8] <<"]{"<< alpha[modul(indexbig, 8)] << "}";
			cout << "\t[" << alpha[13] << "]{" << alpha[modul(indexbig, 13)] << "}" << endl;
			break;
		default:
			break;
		
		}		
}
char decryptFunction(char a, char b)
{
	int apos = Alpha.find(a);
	int bpos = Alpha.find(b);
	int result = apos - bpos;
	if (result < 0)
	{
		result += 32;
	}
	return Alpha[result];


}
std::string DecryptEncryptVeginer(std::string data, std::string key)
{
	std::string final_data;
	int key_length = key.length();

	for (int i = 0; i < data.length(); i += key_length)
	{
		std::string small_data = data.substr(i, key_length);
		for (int j = 0; j < small_data.length(); j++)
		{
			{
				final_data += decryptFunction(small_data[j], key[j]);
			}
		}
	}

	return final_data;
}



int main()
{
	setlocale(LC_ALL, "rus");
	string text;
	string text15;
	
	int numberofletters = 0;
	float Ind=0;
	fstream file;
	file.open("D:\\Crypta2\\TextDecode.txt", ios::out | ios::in);
	while (!file.eof())
	{
		getline(file, text);
	}
	file.close();
	AlphaLink(text, &numberofletters);
	std::cout << numberofletters<<endl;
	for (int i=2;i<=20;i++)
	{
		string text2;
		int link = 0;
		int numbofalpha[32] = { 0 };
			for (int j = 0; j <= numberofletters; j+=i)
			{
				text2 += text[j];
			}
			std::cout <<"step"<< i << endl;
			AlphaLink(text2, &link);
			monogramlink(link, text2, numbofalpha, Alpha, Ind,1,0);
	}
	
	int fift = 15;
	for (int i = 0; i < fift; i++)
	{
		string text152;
		int numbofalpha[32] = { 0 };
		for (int j = i; j <= numberofletters; j += 15)
		{
			text152 += text[j];
		}
		monogramlink(505, text152, numbofalpha, Alpha, Ind, 2,14);
		//cout << text152 << endl;
	}
	string key = { "абсолютныйигрок" };
	std::string decrypted = DecryptEncryptVeginer(text, key);
	std::cout << decrypted;
	system("pause");
	return 0;
}