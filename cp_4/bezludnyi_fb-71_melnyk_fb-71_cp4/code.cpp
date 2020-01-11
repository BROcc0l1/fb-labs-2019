#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int corelz(vector<int> outmas, int step) {
	int corel = 0;
	for (int i = 0; i < outmas.size(); i++) {
		if (step >= outmas.size())step = 0;
		corel = (outmas[i] + outmas[step]) % 2 + corel;
		step++;
	}
	cout << "step " << step << " = " << corel << "\n";
	return corel;

};
int mod(int first, int mode) {
	first = first % mode;
	return first;
};
bool sr(vector<int> first, vector<int>two,int size) {
	int k = 0 ;
	for (int i = 0; i < size; i++) {
		if (first[i] == two[i])k++;
	}
	if (k == size) return true;
	else return false;
};  
int main() {
	ofstream record;
	record.open("output.txt", ios::app);
	int buf = 0;
	int iter = 1;
	int num;
	vector <int> pl = { 1,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1 };
	vector <int> sig_ex = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> sig = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> pl_2 = { 1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,1,1,1,1 };
	vector <int> sig_2 = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector <int> sig_ex_2 = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	/*vector<int> pl =     {1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0};
	vector<int> sig_ex = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	vector<int> sig =    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	vector<int> pl_2 =     { 1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0 };
	vector<int> sig_ex_2 = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	vector<int> sig_2 =    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };*/
	/*vector<int> pl = { 1,1,0 };
	vector<int> sig_ex = { 0,0,1 };
	vector<int> sig = { 0,0,1 };
	vector<int> pl_2 = { 1,0,1 };
	vector<int> sig_ex_2 = { 0,0,1 };
	vector<int> sig_2 = { 0,0,1 };*/
	vector<int> out_2;
	vector<int> out;
	record << "That start date for first : \n";
	record << "Polynomial = (";
	for (int i = 0; i < pl.size(); i++) {
		if (i == (pl.size() - 1))record << pl[i];
		else record << pl[i] << ",";
	}
	record << ")\n";
	record << "Signal polynomial = (";
	for (int i = 0; i < sig.size(); i++) {
		if (i == (sig.size() - 1))record << sig[i];
		else record << sig[i] << ",";
	}
	record << ")\n";
	record << "The first polynomial\n";
	cout << "That start date for first : \n";
	cout << "Polynomial = (";
	for (int i = 0; i < pl.size(); i++) {
		if (i == (pl.size() - 1))cout << pl[i];
		else cout << pl[i]<<",";
	}
	cout << ")\n";
	cout << "Signal polynomial = (";
	for (int i = 0; i < sig.size(); i++) {
		if (i == (sig.size() - 1))cout << sig[i];
		else cout << sig[i] << ",";
	}
	cout << ")\n";
	cout << "The first polynomial\n";
	for (;;) {
		
			
			for (int i = 0; i < pl.size(); i++) {
				buf = (pl[i] * sig[i]) + buf;
			}
			num = mod(buf, 2);
			out.push_back(sig[0]);
			sig.push_back(num);
			sig.erase(sig.begin());
			iter++;
			buf = 0;
			if (sr(sig, sig_ex, sig.size()) == true)break;	
	}
	record << "time(out): " << iter << "\n";
	cout << "time(out): " << iter << "\n";
	cout << "---------------------------------------------------------- \n";
	iter = 1;
	buf = 0;
	record << "That start date for second : \n";
	record << "Polynomial = (";
	for (int i = 0; i < pl_2.size(); i++) {
		if (i == (pl_2.size() - 1))record << pl_2[i];
		else record << pl_2[i] << ",";
	}
	record << ")\n";
	record << "Signal polynomial = (";
	for (int i = 0; i < sig_2.size(); i++) {
		if (i == (sig_2.size() - 1))record << sig_2[i];
		else record << sig_2[i] << ",";
	}
	record << ")\n";
	record << "The second polynomial\n";
	//--------------
	cout << "That start date for second : \n";
	cout << "Polynomial = (";
	for (int i = 0; i < pl_2.size(); i++) {
		if (i == (pl_2.size() - 1))cout << pl_2[i];
		else cout << pl_2[i] << ",";
	}
	cout << ")\n";
	cout << "Signal polynomial = (";
	for (int i = 0; i < sig_2.size(); i++) {
		if (i == (sig_2.size() - 1))cout << sig_2[i];
		else cout << sig_2[i] << ",";
	}
	cout << ")\n";
	cout << "The second polynomial\n";
	for (;;) {
		for (int i = 0; i < pl_2.size(); i++) {
			buf = (pl_2[i] * sig_2[i]) + buf;
		}
		num = mod(buf, 2);
		out_2.push_back(sig_2[0]);
		sig_2.push_back(num);
		sig_2.erase(sig_2.begin());
		iter++;
		buf = 0;
		if (sr(sig_2, sig_ex_2, sig_2.size()) == true)break;
	}
	record << "time(out_2): " << iter << "\n";
	cout << "time(out_2): " << iter << "\n";
	record << "1 - gramma out\n";
	int sum = 0 ;
	for (int i = 0; i < out.size(); i++) {
		if (out[i] == 0) sum++;
	}
	record <<"[0] = "<<sum<<"\n" ;
	sum = 0; 
	for (int i = 0; i < out.size(); i++) {
		if (out[i] == 1) sum++;
	}
	record << "[1] = " << sum << "\n";
		record << "2 - gramma out\n";
		 sum = 0;
		 int bg_00 = 0;
		 int bg_01 = 0;
		 int bg_10 = 0;
		 int bg_11 = 0;
		int next = 1;
		for (int i = 0; i < out.size(); i=i + 2) {
			if (next >= out.size())break;
			if ((out[i] == 0) && ((out[next]) == 0)) bg_00++;
			if ((out[i] == 0) && ((out[next]) == 1)) bg_01++;
			if ((out[i] == 1) && ((out[next]) == 0)) bg_10++;
			if ((out[i] == 1) && ((out[next]) == 1)) bg_11++;
			next = next + 2;
		}
		record << "[00] = " << bg_00 << "\n";
		record << "[01] = " << bg_01 << "\n";
		record << "[10] = " << bg_10 << "\n";
		record << "[11] = " << bg_11 << "\n";
		int thregr_000 = 0;
		int thregr_001 = 0;
		int thregr_010 = 0;
		int thregr_011 = 0;
		int thregr_100= 0;
		int thregr_101 = 0;
		int thregr_110 = 0;
		int thregr_111 = 0;
		next = 1;
		int next_3 = 2;
		for (int i = 0; i < out.size(); i = i + 3) {
			if ((next_3 >= out.size()))break;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0)) thregr_000++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1)) thregr_001++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0)) thregr_010++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1)) thregr_011++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0)) thregr_100++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1)) thregr_101++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0)) thregr_110++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1)) thregr_111++;
			next = next + 3;
			next_3 = next_3 + 3;
		}
		record << "3 - gramma out\n";
		record << "[000] = " << thregr_000 << "\n";
		record << "[001] = " << thregr_001 << "\n";
		record << "[010] = " << thregr_010 << "\n";
		record << "[011] = " << thregr_011 << "\n";
		record << "[100] = " << thregr_100 << "\n";
		record << "[101] = " << thregr_101 << "\n";
		record << "[110] = " << thregr_110 << "\n";
		record << "[111] = " << thregr_111 << "\n";
		//--------------4-gramma
		int fourgr_0000 = 0;
		int fourgr_0001 = 0;
		int fourgr_0010 = 0;
		int fourgr_0011 = 0;
		int fourgr_0100 = 0;
		int fourgr_0101 = 0;
		int fourgr_0110 = 0;
		int fourgr_0111 = 0;
		int fourgr_1000 = 0;
		int fourgr_1001 = 0;
		int fourgr_1010 = 0;
		int fourgr_1011 = 0;
		int fourgr_1100 = 0;
		int fourgr_1101 = 0;
		int fourgr_1110 = 0;
		int fourgr_1111 = 0;
		int next_4 = 3;
		next = 1;
		next_3 = 2;
		for (int i = 0; i < out.size(); i = i + 4) {
			if (next_4 >= out.size())break;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0)) fourgr_0000++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1)) fourgr_0001++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0)) fourgr_0010++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1)) fourgr_0011++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0)) fourgr_0100++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1)) fourgr_0101++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0)) fourgr_0110++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1)) fourgr_0111++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0)) fourgr_1000++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1)) fourgr_1001++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0)) fourgr_1010++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1)) fourgr_1011++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0)) fourgr_1100++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1)) fourgr_1101++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0)) fourgr_1110++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1)) fourgr_1111++;
			next = next + 4;
			next_3 = next_3 + 4;
			next_4 = next_4 + 4;
		}
			record << "4 - gramma out\n";
			record << "[0000] = " << fourgr_0000 << "\n";
			record << "[0001] = " << fourgr_0001 << "\n";
			record << "[0010] = " << fourgr_0010 << "\n";
			record << "[0011] = " << fourgr_0011 << "\n";
			record << "[0100] = " << fourgr_0100 << "\n";
			record << "[0101] = " << fourgr_0101 << "\n";
			record << "[0110] = " << fourgr_0110 << "\n";
			record << "[0111] = " << fourgr_0111 << "\n";
			record << "[1000] = " << fourgr_1000 << "\n";
			record << "[1001] = " << fourgr_1001 << "\n";
			record << "[1010] = " << fourgr_1010 << "\n";
			record << "[1011] = " << fourgr_1011 << "\n";
			record << "[1100] = " << fourgr_1100 << "\n";
			record << "[1101] = " << fourgr_1101 << "\n";
			record << "[1110] = " << fourgr_1110 << "\n";
			record << "[1111] = " << fourgr_1111 << "\n";
		//-------------------------------------5-gramma
		int fivegr00000 = 0;
		int fivegr00001 = 0;
		int fivegr00010 = 0;
		int fivegr00011 = 0;
		int fivegr00100 = 0;
		int fivegr00101 = 0;
		int fivegr00110 = 0;
		int fivegr00111 = 0;
		int fivegr01000 = 0;
		int fivegr01001 = 0;
		int fivegr01010 = 0;
		int fivegr01011 = 0;
		int fivegr01100 = 0;
		int fivegr01101 = 0;
		int fivegr01110 = 0;
		int fivegr01111 = 0;
		int fivegr10000 = 0;
		int fivegr10001 = 0;
		int fivegr10010 = 0;
		int fivegr10011 = 0;
		int fivegr10100 = 0;
		int fivegr10101 = 0;
		int fivegr10110 = 0;
		int fivegr10111 = 0;
		int fivegr11000 = 0;
		int fivegr11001 = 0;
		int fivegr11010 = 0;
		int fivegr11011 = 0;
		int fivegr11100 = 0;
		int fivegr11101 = 0;
		int fivegr11110 = 0;
		int fivegr11111 = 0;
		int next_5 = 4;
	    next_4 = 3;
		next = 1;
		next_3 = 2;
		for (int i = 0; i < out.size(); i = i + 5) {
			if (next_5 >= out.size())break;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr00000++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr00001++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr00010++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr00011++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr00100++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr00101++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr00110++;
			if ((out[i] == 0) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr00111++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr01000++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr01001++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr01010++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr01011++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr01100++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr01101++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr01110++;
			if ((out[i] == 0) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr01111++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr10000++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr10001++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr10010++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr10011++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr10100++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr10101++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr10110++;
			if ((out[i] == 1) && ((out[next]) == 0) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr10111++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr11000++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr11001++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr11010++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 0) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr11011++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 0)) fivegr11100++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 0) && (out[next_5] == 1)) fivegr11101++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 0)) fivegr11110++;
			if ((out[i] == 1) && ((out[next]) == 1) && (out[next_3] == 1) && (out[next_4] == 1) && (out[next_5] == 1)) fivegr11111++;
			next = next + 4;
			next_3 = next_3 + 5;
			next_4 = next_4 + 5;
			next_5 = next_5 + 5;
		}
		record << "5 - gramma out\n";
		record << "[00000] = " << fivegr00000 << "\n";
		record << "[00001] = " << fivegr00001 << "\n";
		record << "[00010] = " << fivegr00010 << "\n";
		record << "[00011] = " << fivegr00011 << "\n";
		record << "[00100] = " << fivegr00100 << "\n";
		record << "[00101] = " << fivegr00101 << "\n";
		record << "[00110] = " << fivegr00110 << "\n";
		record << "[00111] = " << fivegr00111 << "\n";
		record << "[01000] = " << fivegr01000 << "\n";
		record << "[01001] = " << fivegr01001 << "\n";
		record << "[01010] = " << fivegr01010 << "\n";
		record << "[01011] = " << fivegr01011 << "\n";
		record << "[01100] = " << fivegr01100 << "\n";
		record << "[01101] = " << fivegr01101 << "\n";
		record << "[01110] = " << fivegr01110 << "\n";
		record << "[01111] = " << fivegr01111 << "\n";
		record << "[10000] = " << fivegr10000 << "\n";
		record << "[10001] = " << fivegr10001 << "\n";
		record << "[10010] = " << fivegr10010 << "\n";
		record << "[10011] = " << fivegr10011 << "\n";
		record << "[10100] = " << fivegr10100 << "\n";
		record << "[10101] = " << fivegr10101 << "\n";
		record << "[10110] = " << fivegr10110 << "\n";
		record << "[10111] = " << fivegr10111 << "\n";
		record << "[11000] = " << fivegr11000 << "\n";
		record << "[11001] = " << fivegr11001 << "\n";
		record << "[11010] = " << fivegr11010 << "\n";
		record << "[11011] = " << fivegr11011 << "\n";
		record << "[11100] = " << fivegr11100 << "\n";
		record << "[11101] = " << fivegr11101 << "\n";
		record << "[11110] = " << fivegr11110 << "\n";
		record << "[11111] = " << fivegr11111 << "\n";
		//-------------------------------------out_2
		record << "1 - gramma out_2\n";
		sum = 0;
		for (int i = 0; i < out_2.size(); i++) {
			if (out_2[i] == 0) sum++;
		}
		record << "[0] = " << sum << "\n";
		sum = 0;
		for (int i = 0; i < out_2.size(); i++) {
			if (out_2[i] == 1) sum++;
		}
		record << "[1] = " << sum << "\n";
		record << "2 - gramma out_2\n";
		sum = 0;
		 bg_00 = 0;
		 bg_01 = 0;
		 bg_10 = 0;
		 bg_11 = 0;
		 next = 1;
		for (int i = 0; i < out_2.size(); i = i + 2) {
			if (next >= out_2.size())break;
			if ((out_2[i] == 0) && ((out_2[next]) == 0)) bg_00++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1)) bg_01++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0)) bg_10++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1)) bg_11++;
			next = next + 2;
		}
		record << "[00] = " << bg_00 << "\n";
		record << "[01] = " << bg_01 << "\n";
		record << "[10] = " << bg_10 << "\n";
		record << "[11] = " << bg_11 << "\n";
		 thregr_000 = 0;
		 thregr_001 = 0;
		 thregr_010 = 0;
		 thregr_011 = 0;
		 thregr_100 = 0;
		 thregr_101 = 0;
		 thregr_110 = 0;
		 thregr_111 = 0;
		next = 1;
		 next_3 = 2;
		for (int i = 0; i < out_2.size(); i = i + 3) {
			if ((next_3 >= out_2.size()))break;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0)) thregr_000++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1)) thregr_001++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0)) thregr_010++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1)) thregr_011++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0)) thregr_100++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1)) thregr_101++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0)) thregr_110++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1)) thregr_111++;
			next = next + 3;
			next_3 = next_3 + 3;
		}
		record << "3 - gramma out_2\n";
		record << "[000] = " << thregr_000 << "\n";
		record << "[001] = " << thregr_001 << "\n";
		record << "[010] = " << thregr_010 << "\n";
		record << "[011] = " << thregr_011 << "\n";
		record << "[100] = " << thregr_100 << "\n";
		record << "[101] = " << thregr_101 << "\n";
		record << "[110] = " << thregr_110 << "\n";
		record << "[111] = " << thregr_111 << "\n";
		//--------------4-gramma
		 fourgr_0000 = 0;
		 fourgr_0001 = 0;
		 fourgr_0010 = 0;
		 fourgr_0011 = 0;
		 fourgr_0100 = 0;
		 fourgr_0101 = 0;
		 fourgr_0110 = 0;
		 fourgr_0111 = 0;
		 fourgr_1000 = 0;
		 fourgr_1001 = 0;
		 fourgr_1010 = 0;
		 fourgr_1011 = 0;
		 fourgr_1100 = 0;
		 fourgr_1101 = 0;
		 fourgr_1110 = 0;
		 fourgr_1111 = 0;
		 next_4 = 3;
		next = 1;
		next_3 = 2;
		for (int i = 0; i < out_2.size(); i = i + 4) {
			if (next_4 >= out_2.size())break;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0)) fourgr_0000++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1)) fourgr_0001++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0)) fourgr_0010++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1)) fourgr_0011++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0)) fourgr_0100++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1)) fourgr_0101++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0)) fourgr_0110++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1)) fourgr_0111++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0)) fourgr_1000++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1)) fourgr_1001++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0)) fourgr_1010++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1)) fourgr_1011++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0)) fourgr_1100++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1)) fourgr_1101++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0)) fourgr_1110++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1)) fourgr_1111++;
			next = next + 4;
			next_3 = next_3 + 4;
			next_4 = next_4 + 4;
		}
			record << "4 - gramma out_2\n";
			record << "[0000] = " << fourgr_0000 << "\n";
			record << "[0001] = " << fourgr_0001 << "\n";
			record << "[0010] = " << fourgr_0010 << "\n";
			record << "[0011] = " << fourgr_0011 << "\n";
			record << "[0100] = " << fourgr_0100 << "\n";
			record << "[0101] = " << fourgr_0101 << "\n";
			record << "[0110] = " << fourgr_0110 << "\n";
			record << "[0111] = " << fourgr_0111 << "\n";
			record << "[1000] = " << fourgr_1000 << "\n";
			record << "[1001] = " << fourgr_1001 << "\n";
			record << "[1010] = " << fourgr_1010 << "\n";
			record << "[1011] = " << fourgr_1011 << "\n";
			record << "[1100] = " << fourgr_1100 << "\n";
			record << "[1101] = " << fourgr_1101 << "\n";
			record << "[1110] = " << fourgr_1110 << "\n";
			record << "[1111] = " << fourgr_1111 << "\n";
		
		//-------------------------------------5-gramma
		 fivegr00000 = 0;
		 fivegr00001 = 0;
		 fivegr00010 = 0;
		 fivegr00011 = 0;
		 fivegr00100 = 0;
		 fivegr00101 = 0;
		 fivegr00110 = 0;
		 fivegr00111 = 0;
		 fivegr01000 = 0;
		 fivegr01001 = 0;
		 fivegr01010 = 0;
		 fivegr01011 = 0;
		 fivegr01100 = 0;
		 fivegr01101 = 0;
		 fivegr01110 = 0;
		 fivegr01111 = 0;
		 fivegr10000 = 0;
		 fivegr10001 = 0;
		 fivegr10010 = 0;
		 fivegr10011 = 0;
		 fivegr10100 = 0;
		 fivegr10101 = 0;
		 fivegr10110 = 0;
		 fivegr10111 = 0;
		 fivegr11000 = 0;
		 fivegr11001 = 0;
		 fivegr11010 = 0;
		 fivegr11011 = 0;
		 fivegr11100 = 0;
		 fivegr11101 = 0;
		 fivegr11110 = 0;
		 fivegr11111 = 0;
		 next_5 = 4;
		next_4 = 3;
		next = 1;
		next_3 = 2;
		for (int i = 0; i < out_2.size(); i = i + 5) {
			if (next_5 >= out_2.size())break;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr00000++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr00001++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr00010++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr00011++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr00100++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr00101++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr00110++;
			if ((out_2[i] == 0) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr00111++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr01000++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr01001++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr01010++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr01011++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr01100++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr01101++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr01110++;
			if ((out_2[i] == 0) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr01111++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr10000++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr10001++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr10010++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr10011++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr10100++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr10101++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr10110++;
			if ((out_2[i] == 1) && ((out_2[next]) == 0) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr10111++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr11000++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr11001++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr11010++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 0) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr11011++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 0)) fivegr11100++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 0) && (out_2[next_5] == 1)) fivegr11101++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 0)) fivegr11110++;
			if ((out_2[i] == 1) && ((out_2[next]) == 1) && (out_2[next_3] == 1) && (out_2[next_4] == 1) && (out_2[next_5] == 1)) fivegr11111++;
			next = next + 4;
			next_3 = next_3 + 5;
			next_4 = next_4 + 5;
			next_5 = next_5 + 5;
		}
		record << "5 - gramma out_2\n";
		record << "[00000] = " << fivegr00000 << "\n";
		record << "[00001] = " << fivegr00001 << "\n";
		record << "[00010] = " << fivegr00010 << "\n";
		record << "[00011] = " << fivegr00011 << "\n";
		record << "[00100] = " << fivegr00100 << "\n";
		record << "[00101] = " << fivegr00101 << "\n";
		record << "[00110] = " << fivegr00110 << "\n";
		record << "[00111] = " << fivegr00111 << "\n";
		record << "[01000] = " << fivegr01000 << "\n";
		record << "[01001] = " << fivegr01001 << "\n";
		record << "[01010] = " << fivegr01010 << "\n";
		record << "[01011] = " << fivegr01011 << "\n";
		record << "[01100] = " << fivegr01100 << "\n";
		record << "[01101] = " << fivegr01101 << "\n";
		record << "[01110] = " << fivegr01110 << "\n";
		record << "[01111] = " << fivegr01111 << "\n";
		record << "[10000] = " << fivegr10000 << "\n";
		record << "[10001] = " << fivegr10001 << "\n";
		record << "[10010] = " << fivegr10010 << "\n";
		record << "[10011] = " << fivegr10011 << "\n";
		record << "[10100] = " << fivegr10100 << "\n";
		record << "[10101] = " << fivegr10101 << "\n";
		record << "[10110] = " << fivegr10110 << "\n";
		record << "[10111] = " << fivegr10111 << "\n";
		record << "[11000] = " << fivegr11000 << "\n";
		record << "[11001] = " << fivegr11001 << "\n";
		record << "[11010] = " << fivegr11010 << "\n";
		record << "[11011] = " << fivegr11011 << "\n";
		record << "[11100] = " << fivegr11100 << "\n";
		record << "[11101] = " << fivegr11101 << "\n";
		record << "[11110] = " << fivegr11110 << "\n";
		record << "[11111] = " << fivegr11111 << "\n";
		cout << "corelatia :\nout\n";
		record << "corelatia :\nout\n";
		for (int i = 1; i < 11; i++) {
			record << "step " << i << " = " <<corelz(out, i)<<"\n";
		}
		cout << "out_2\n";
		record << "out_2\n";
		for (int i = 1; i < 11; i++) {
			record << "step " << i << " = " << corelz(out_2, i)<<"\n";
		}
	system("pause");
	return 0;
}