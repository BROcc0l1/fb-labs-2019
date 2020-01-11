#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>



using namespace std;
double sum = 0;
double entropy(double tmp)
{
	if (tmp == 0.) return 0;
	return -tmp * log2( tmp );
}

void quickSort(int arr[], char strLC[], int left, int right) {

	int i = left, j = right;

	int tmp;
	char ctmp;

	int pivot = arr[(left + right) / 2];
	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			ctmp = strLC[i];
			tmp = arr[i];

			strLC[i] = strLC[j];
			arr[i] = arr[j];

			strLC[j] = ctmp;
			arr[j] = tmp;

			i++;

			j--;

		}

	};
	if (left < j)

		quickSort(arr, strLC, left, j);

	if (i < right)

		quickSort(arr, strLC, i, right);

}

void copytext()
{
	ofstream output("output.txt");
	ifstream input("input.txt");

	string str, str1 = "";
	bool flag = 0;
	const int n = 34;
	int length; 
	char strLC[n] = { ' ', 'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	char strUC[n] = { ' ', 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', '¨', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß' };


	while (input)
	{
		getline(input, str);
		length = str.length();
		for (int i = 0; i < length; i++)
		{
			flag = 0;
			for (int j = 0; j < n; j++)
				if (str[i] == strLC[j] || str[i] == strUC[j])
				{
					if (j == 7) { str1 += strLC[j - 1]; flag = 1; break;}
				    if(j == 28){ str1+=strLC[30]; flag = 1; break;}
					str1 += strLC[j];
					flag = 1;
					break;
				}

			if (!flag) { str.erase(i, 1); i--; length--; }

		}
		str1 += " ";
		if (input.eof())break;
		
	}
	string strtemp = "";
	length = str1.length() - 1;
	for (int i = 0; i < length; i++)
	{
		strtemp = str1[i];
		strtemp += str1[i + 1];
		if (strtemp == "  ") { str1.erase(i, 1); i--; length--; }
	}


	output << str1 << endl;

	input.close();
	output.close();
}


void monog()
{
	ofstream output("monog.txt");
	ifstream input("output.txt");

	string str;

	const int n = 32;
	int length;
	double lengfull = 0.0, tmp = 0.0; 
	char strLC[n] = { ' ','à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	while (input)
	{
		getline(input, str);
		length = str.length();
		lengfull += length;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < n; j++)
				if (str[i] == strLC[j]) arr[j]++;

		}

	}
	int snum = arr[0]; // number of spaces in text
	
	quickSort(&arr[0], &strLC[0], 0, n - 1);

	output <<setw(6) << "With space: "  <<"  " << endl;
	for (int j = n-1; j >= 0; j--)
	{
		if (strLC[j] == ' ')continue;
		tmp = arr[j] / lengfull;
		sum = sum + entropy(tmp);
		output << strLC[j] << " - " << std::setprecision(6) << tmp <<setw(6) << "  " <<  endl;
	}
	output << "Entropia - " << sum << setw(6) << endl;

	output <<setw(6) << "\nWithout space: " <<" " << endl;
	sum = 0;
	for (int j = n-1; j >= 0; j--)
	{
		if (strLC[j] == ' ')continue;
		tmp = arr[j] / (lengfull - snum);
		sum = sum + entropy(tmp);
		output << strLC[j] << " - " << std::setprecision(6) << tmp <<setw(6) << "  "<<  endl;
	}
	output << "Entropia - " << sum << setw(6) << endl;
	input.close();
	output.close();
}

void bigr_ws_wi() // Ïåðåòèí ç ïðîá³ëàìè
{
	ofstream output("bigr_ws_wi.txt");
	ifstream input("output.txt");//changed

	string str;
	const int n = 32;
	int	length;
	double tmp = 0.0;
	char strLC[n] = { ' ','à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	int arr[n * n];

	for (int i = 0; i < n * n; i++)
		arr[i] = 0;

	double count = 0.0;

	string arr1[n * n];
	for (int i = 0; i < n * n; i++)
		arr1[i] == "  ";/////Òèïó âåñü ìàñèâ çàáèâ íóëÿìè (ïîäâ³éíèìè ïðîá³ëàìè)

	while (input)
	{
		getline(input, str);
		length = str.length();

		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ' || str[i] == EOF)continue;

			for (int k = 0; k < n; k++)
				if (str[i] == strLC[k])
				{
					if (str[i + 1] == ' ' || str[i + 1] == EOF) { i++; continue; }
					for (int j = 0; j < n; j++)
						if (str[i + 1] == strLC[j])
						{
							arr[k * n + j] += 1;
							count++;
							break;
						}
					break;
				}

		}
		if (input.eof())break;


	}
	
	output <<fixed<< "   "; //Matrix for frequency
	for (int i = 1; i < 32; i++)
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
			output << setw(9) << floor((arr[i * n + j] / count )* 1000000.) / 1000000.  << "  ";
		output << "\n\n\n";
	}

	output << "\n\n\n\n\n\n";
	sum = 0;
	for (int i = 1; i < 32; i++) //Matrix for entropy
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
		{
			tmp = floor((arr[i * n + j] / count) * 1000000.) / 1000000.;
			sum = sum + entropy(tmp);
			output << setw(9) << entropy(tmp) << "  ";
		}
		output << "\n\n\n";
	}
	output <<setw(9) << "Entropy = " << 0.5 * sum << endl;

	
	input.close();
	output.close();
}


void bigr_ws_ni() // Áåç ïåðåòèíó ç ïðîá³ëàìè
{
	ofstream output("bigr_ws_ni.txt");
	ifstream input("output.txt");

	string str;
	const int n = 32;
	int	length;
	double tmp = 0.0;
	char strLC[n] = { ' ','à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	int arr[n * n];

	for (int i = 0; i < n * n; i++)
		arr[i] = 0;

	double count = 0.0;

	string arr1[n * n];
	for (int i = 0; i < n * n; i++)
		arr1[i] == "  ";

	while (input)
	{
		
		getline(input, str);
		length = str.length();

		for (int i = 0; i < length; i = i + 2)
		{
			if (str[i] == ' ' || str[i] == EOF)continue;

			for (int k = 0; k < n; k++)
				if (str[i] == strLC[k])
				{
					if (str[i + 1] == ' ' || str[i + 1] == EOF) { i++; continue; }
					for (int j = 0; j < n; j++)
						if (str[i + 1] == strLC[j])
						{
							if (arr[k * n + j] == 0)arr1[k * n + j] = strLC[k] + strLC[j];
							arr[k * n + j] += 1;
							count++;
							break;
						}
					break;
				}

		}

		if (input.eof())break;


	}
	
	output << fixed << "   ";
	for (int i = 1; i < 32; i++) //Matrix for frequency
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
			output << setw(9) << floor((arr[i * n + j] / count) * 1000000.) / 1000000. << "  ";
		output << "\n\n\n";
	}

	output << "\n\n\n\n\n\n";
	sum = 0;
	for (int i = 1; i < 32; i++) //Matrix for entropy
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
		{
			tmp = floor((arr[i * n + j] / count) * 1000000.) / 1000000.;
			sum = sum + entropy(tmp);
			output << setw(9) << entropy(tmp) << "  ";
		}
		output << "\n\n\n";
	}
	output << setw(9)<<"Entropy = " << 0.5 * sum << endl;

	input.close();
	output.close();
}

void bigr_ns_wi() // Ïåðåòèí áåç ïðîá³ë³â
{
	ofstream output("bigr_ns_wi.txt");
	ifstream input("output_ns.txt");
	double tmp = 0.0;
	string str;
	const int n = 32;
	int	length;

	char strLC[n] = { ' ', 'à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	int arr[n * n];

	for (int i = 0; i < n * n; i++)
		arr[i] = 0;

	double count = 0.0;

	while (input)
	{
		getline(input, str);
		length = str.length();

		for (int i = 0; i < length; i++)
		{
			if (str[i] == EOF)continue;

			for (int k = 1; k < n; k++)
				if (str[i] == strLC[k])
				{
					if (str[i + 1] == EOF) { i++; continue; }
					for (int j = 1; j < n; j++)
						if (str[i + 1] == strLC[j])
						{
							arr[k * n + j] += 1;
							count++;
							break;
						}
					break;
				}

		}
		if (input.eof())break;


	}

	output << fixed << "   ";
	for (int i = 1; i < 32; i++) //For Freq
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
			output << setw(9) << floor((arr[i * n + j] / count) * 1000000.) / 1000000. << "  ";
		output << "\n\n\n";
	}

	output << "\n\n\n\n\n\n";
	sum = 0;
	for (int i = 1; i < 32; i++) //Matrix for entropy
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
		{
			tmp = floor((arr[i * n + j] / count) * 1000000.) / 1000000.;
			sum = sum + entropy(tmp);
			output << setw(9) << entropy(tmp) << "  ";
		}
		output << "\n\n\n";
	}
	output << setw(9) << "Entropy = " << 0.5 * sum << endl;
	input.close();
	output.close();
}



void bigr_ns_ni() // Áåç ïåðåòèíó áåç ïðîá³ë³â
{
	ofstream output("bigr_ns_ni.txt");
	ifstream input("output_ns.txt");

	string str;
	const int n = 32;
	int	length;
	double tmp = 0.0;
	char strLC[n] = { ' ', 'à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'û', 'ü', 'ý', 'þ', 'ÿ' };
	int arr[n * n];

	for (int i = 0; i < n * n; i++)
		arr[i] = 0;

	double count = 0.0;

	while (input)
	{
		getline(input, str);
		length = str.length();

		for (int i = 0; i < length; i = i + 2)
		{
			if (str[i] == EOF)continue;

			for (int k = 1; k < n; k++)
				if (str[i] == strLC[k])
				{
					if (str[i + 1] == EOF) { i++; continue; }
					for (int j = 1; j < n; j++)
						if (str[i + 1] == strLC[j])
						{
							arr[k * n + j] += 1;
							count++;
							break;
						}
					break;
				}

		}
		if (input.eof())break;


	}

	output << fixed << "   ";
	for (int i = 1; i < 32; i++) //For freq
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
			output << setw(9) << floor((arr[i * n + j] / count) * 1000000.) / 1000000. << "  ";
		output << "\n\n\n";
	}

	output << "\n\n\n\n\n\n";
	sum = 0;
	for (int i = 1; i < 32; i++) //Matrix for entropy
		output << setw(9) << strLC[i] << "  ";
	output << "\n\n\n";
	for (int i = 1; i < 32; i++)
	{
		output << strLC[i] << "  ";
		for (int j = 1; j < 32; j++)
		{
			tmp = floor((arr[i * n + j] / count) * 1000000.) / 1000000.;
			sum = sum + entropy(tmp);
			output << setw(9) << entropy(tmp) << "  ";
		}
		output << "\n\n\n";
	}
	output << setw(9) << "Entropy = " << 0.5 * sum << endl;

	input.close();
	output.close();
}


int main(){


	setlocale(LC_ALL, "Russian");
	

	copytext();
	monog();
	bigr_ws_wi();
	bigr_ws_ni();
	bigr_ns_wi();
	bigr_ns_ni();


	
	system("pause");
	return 0;
}
