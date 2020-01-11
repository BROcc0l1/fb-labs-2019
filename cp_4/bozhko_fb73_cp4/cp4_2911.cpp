#include "pch.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

long long q = 1;
int period;
int equation_cur0[] = { 1,1,1,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0 };
int equation_cur1[] = { 1,1,1,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0 };//коэф. уравнения X20+X17+X15+X14+X9+X7+X5+X3+X2+X+1
int equation_cur[] = { 1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0};//коэф. уравнения X24 + X22 + X18 + X17 + X16 + X15 + X12 + X11 + X9 + X4 + X2 + X + 1
int gram_1[] = { 0,1 };
int gram_2[] = { 0,0,0,1,1,0,1,1 };
int gram_3[] = { 0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1 };
int gram_4[] = { 0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1 };
int size_eq = sizeof(equation_cur) / sizeof(equation_cur[0]);
vector<int> shift((pow(2, size_eq) - 1));//сдвиг регистра(первый элемент)
vector<int> recur_sequence((pow(2, size_eq) - 1) * size_eq);//рекурсивная последовательность 
void find_recur_sequence() {// выводит
	cout << size_eq << endl;
	for (long long i = 0; i < (pow(2, size_eq) - 1); i++) {
		//cout <<endl<< i << " i " <<endl;
		for (int n = 0; n < size_eq; n++) {//cout << endl << n <<" n "<< endl;
			if (i > 0 && n != (size_eq - 1)) {//сдвигаем на элемент вперед по модулю size_eq
				recur_sequence[i * size_eq + n] = recur_sequence[(i - 1) * size_eq + n + 1];
				//cout <<recur_sequence[i * size_eq + n];//"i>0 " <<n << " "<<endl
				//cout<<" recur_sequence[(i-1)* sizel + n+1]; "<< recur_sequence[(i - 1)* sizel + n + 1];
			}
			if (((i + n) >= size_eq) && (n == size_eq - 1)) {
				recur_sequence[i * size_eq + n] = 0;
				for (int j = n; j >= 0; j--) {
					recur_sequence[i * size_eq + n] = (recur_sequence[i * size_eq + n] + recur_sequence[(i - 1) * size_eq + j]*equation_cur[((i - 1) * size_eq + j)%size_eq]) % 2;
					while (recur_sequence[i * size_eq + n] < 0)recur_sequence[i * size_eq + n] = recur_sequence[i * size_eq + n] + 2;
				}
			}
		}
	}
}
void find_shift() {
	long long n=0;
	for (long long i = 0; i < (pow(2, size_eq) - 1) * size_eq; i++) {
		shift[n] = recur_sequence[i];
		n++;
		i = i + size_eq - 1;
	}
}
long long period_rec() {
	for (long long i = 1; i < (pow(2, size_eq) - 1) ;i++) {
		int y = 0;
		for (int n = 0; n < size_eq;n++) {
			if ((recur_sequence[n] == recur_sequence[i*size_eq + n])) {//((i*q+n)< (pow(2, size_eq) - 1) * size_eq)&&
				y++;
				}
			//cout << y << " "<< recur_sequence[n] <<" "<< recur_sequence[i*size_eq + n]<<endl;
		}
		if (y == size_eq) {
			//cout << y << " " << size_eq << endl;
			break;
		}
		else {
			q++; if (q > (pow(2, size_eq) - 1))break;
		}
		//cout << q << endl;
	}
	return q;
}

void autocorrelation() {
	long int s = (pow(2, size_eq) - 1);
	vector<long long> d(10);
	for (int n = 1; n <= 10; n++) {
		d[n-1] = 0;
		for (long long i = 0; i < period; i++) {//1 1 1 1 1 
			d[n-1] = d[n-1] + (shift[i]+shift[((i+n)% period)])%2;
		}
	}
	for (int n= 0; n < 10; n++) {//1 1 1 1 1 
		cout<<" "<<d[n];
	}
}
int partition_1gramm(int n, int Ngramm[]) {//n=1
	for (int i = 0; i < pow(2, n)*n; i = i + n) {
		int count = 0;
		for (int j = 0; j < period; j++) {
			if (Ngramm[i] == shift[j])count++;
		}
		cout << endl << Ngramm[i] << " " << count;
	}
	return 0;
}
int partition_2gramm(int n, int Ngramm[]) {//n=1
	for (int i = 0; i < pow(2, n)*n; i = i + n) {
		int count = 0;
		for (int j = 1; j < period; j++) {
			if ((Ngramm[i] == shift[j - 1]) && (Ngramm[i + 1] == shift[j]))count++;
		}
		cout << endl << Ngramm[i] << Ngramm[i + 1] << " " << count;
	}
	return 0;
}
int partition_3gramm(int n, int Ngramm[]) {//n=1
	for (int i = 0; i < pow(2, n)*n; i = i + n) {
		int count = 0;
		for (int j = 2; j < period; j++) {
			if ((Ngramm[i] == shift[j - 2]) && (Ngramm[i + 1] == shift[j - 1]) && (Ngramm[i + 2] == shift[j]))count++;
		}
		cout << endl << Ngramm[i] << Ngramm[i + 1] << Ngramm[i + 2] << " " << count;
	}
	return 0;
}
int partition_4gramm(int n, int Ngramm[]) {//n=1
	for (int i = 0; i < pow(2, n)*n; i = i + n) {
		int count = 0;
		for (int j = 3; j < period; j++) {
			if ((Ngramm[i] == shift[j - 3]) && (Ngramm[i + 1] == shift[j - 2]) && (Ngramm[i + 2] == shift[j - 1]) && (Ngramm[i + 3] == shift[j]))count++;
		}cout << endl << Ngramm[i] << Ngramm[i + 1] << Ngramm[i + 2] << Ngramm[i + 3] << " " << count;
	}
	return 0;
}


int main()
{
	cout << size_eq << " ";
	for (int i = 0; i < size_eq; i++) {//находим первые size_eq элементы
		if(i==(size_eq-1)) recur_sequence[i] = 1;
		else recur_sequence[i] = 0;
		//cout << recur_sequence[i]<< endl;
	}
	find_recur_sequence();
	//cout << endl;

	//for (int i = 0; i < (pow(2, size_eq) - 1) * size_eq; i++) {
	// if (i%size_eq ==0)cout << " ";
	//cout << recur_sequence[i];
	// }
	 cout << endl;
	//period = period_rec();
	 period = 1118481;
	cout << "Period " << period<<endl;
	find_shift();

	ofstream f;
	//открываем файл в режиме записи,
	//режим ios::out устанавливается по умолчанию
	f.open("C:\\Users\\Настя\\Desktop\\l3.txt", ios::out);
	//цикл для ввода вещественных чисел
	//и записи их в файл
	for (long long i = 0; i < (pow(2, size_eq) - 1); i++) {
		//cout << shift[n];
		f << shift[i] << " ";
		//cout << shift[i];
		//закрытие потока
	}
	f.close();
	autocorrelation();
	partition_1gramm(1, gram_1);
	partition_2gramm(2, gram_2);
	partition_3gramm(3, gram_3);
	partition_4gramm(4, gram_4);

	return 0;
}