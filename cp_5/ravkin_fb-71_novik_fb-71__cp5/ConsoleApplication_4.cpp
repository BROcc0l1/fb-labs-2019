
#include <iostream>
#include <NTL/ZZ.h>
NTL_CLIENT
using namespace std;

ZZ gcd(ZZ a, ZZ b, ZZ& x, ZZ& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ZZ x1, y1;
	ZZ d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}




long simplicity_test(const ZZ& n, long t)
{
	if (n <= 1) return 0;

	long p;
	PrimeSeq s;  
	

	p = s.next();  
	while (p && p < 2000) {
		if ((n % p) == 0) return (n == p);
		p = s.next();
	}

	long i;
	ZZ x;
	

	for (i = 0; i < t; i++) {

		x = RandomBnd(n); 
		ZZ m, y, z;
		long j, k;
		if (x == 0) return 0;

		m = n / 2; k = 1;

		while (m % 2 == 0) {
			m /= 2;
			k++;
		}

		z = PowerMod(x, m, n); // z = x^m % n
		if (z == 1) return 0;

		j = 0;
		do {
			y = z;
			z = (y * y) % n;
			j++;
		} while (j < k && z != 1);

		if(z != 1 || y != n - 1)return 0;
	}

	return 1;
}

void GenerateKeyPair(ZZ p,ZZ q,ZZ& e,ZZ& n,ZZ& d, ZZ& fi)
{
	ZZ x,y,pq;
	e = 65537;
	pq = p * q;
	fi = (p - 1) * (q - 1);
  ZZ g = gcd(e, fi, x, y);
  //cout << "d=" << g << endl;
  if (g == 1){
    x = (x % fi +fi) % fi;
   // cout << "obratnoe:" << x << endl;
  }
  if (x > 0)
    while (x > fi) x = x -fi;
  if (x < 0)
    while (x < 0) x = x +fi;

  d = x;
  n = pq;
}

void Encrypt(ZZ& C, ZZ M, ZZ e, ZZ n)
{
	C = PowerMod(M, e, n);
}
void Decrypt(ZZ& M, ZZ C, ZZ d, ZZ n)
{
	M = PowerMod(C, d, n);
}
void Sign(ZZ& S, ZZ M, ZZ d, ZZ n) 
{
	S = PowerMod(M, d, n);
}
ZZ Verify(ZZ M, ZZ S, ZZ e, ZZ n)
{
	M = PowerMod(S, e, n);
	return M;
}

void Send(ZZ& k1, ZZ& S1, ZZ k, ZZ& S, ZZ n1, ZZ n, ZZ d, ZZ e)
{
	S= PowerMod(k, d, n);
	std::cout << "S:" << S << endl;
	S1= PowerMod(S, e, n1);
	std::cout << "S1:" << hex << S1 << endl;
	k1 = PowerMod(k, e, n1);
	std::cout << "k1:" << hex << k1 << endl;
}

void Receive(ZZ k, ZZ S, ZZ k1, ZZ S1, ZZ d1, ZZ n1, ZZ e, ZZ n)
{
	k = PowerMod(k1, d1, n1);
	std::cout << "k:" << hex << k << endl;
	ZZ buff;
	buff = k;
	S = PowerMod(S1, d1, n1);
	std::cout << "S:" << hex << S << endl;
	k = PowerMod(S, e, n);
	std::cout << "k:" << hex << k << endl;
	if (buff == k) { std::cout << "digital true\n"; }
	else { std::cout << "digital false\n"; }
}

ZZ random(ZZ a, ZZ b) {

	return RandomBnd(b - a) + a ;
}

int main()
{
	cout.setf(ios::showbase);
	const std::string hex("0x31c3");
	//std::istringstream stream(hex);

	setlocale(LC_ALL, "Russian");

	ZZ  c_256;
	c_256 = 2;
	for (int i = 2; i <= 256; i++)
		c_256 = c_256 * 2;
		

	ZZ c_260 = c_256 * 2*2*2*2*1024*1024;
	//cout << c_256 << "\n";

	ZZ n1, n2, n3, n4;

	
	//n1 = RandomBnd(c_256);
	//cout << simplicity_test(n1, 2)<<endl;

	for(;;){
		//ZZ n1;

		while ((simplicity_test(n1,4)) == 0)
		{	//while(n1<c_256)
			//n1 = RandomBnd(c_260);
			n1 = random(c_256, c_260);
		}
		std::cout << "n1\n";
		//ZZ n2;

		while ((simplicity_test(n2, 4)) == 0)
		{
			//while (n2 < c_256)
			n2 = random(c_256, c_260);
		}
		std::cout << "n2\n";
		//ZZ n3;

		while ((simplicity_test(n3, 4)) == 0)
		{	
			//while (n3 < c_256)
			n3 = random(c_256, c_260);
		}
		std::cout << "n3\n";
		//ZZ n4;

		while ((simplicity_test(n4, 4)) == 0)
		{
			//while (n4 < c_256)
			n4 = random(c_256, c_260);
		}
		std::cout << "n4\n";

		if (n1 * n2 <= n3 * n4)break;
	} 
	std::cout <<"n1:"<< n1 << endl;
	std::cout <<"n2::" <<n2 << endl;
	std::cout <<"n3:" <<n3 << endl;
	std::cout << "n4:"<<n4 << endl;

	ZZ p, q, p1, q1;
	if (n1 * n2 <= n3 * n4) {
		std::cout << "OK\n\n";
		//cout << n1 * n2 << endl<< n3* n4 << endl;
		p = n1; q = n2; p1 = n3; q1 = n4;
	}
	ZZ e,n,d,fi;
	std::cout << "Generate Key Pair A:" << endl;
	GenerateKeyPair(p, q, e, n, d,fi);
	std::cout <<"e: " <<e << endl;
	std::cout <<"n: "<< n << endl;
	std::cout <<"d: "<< d << endl<<endl;
	ZZ e1, d1, fi1;
	std::cout << "Generate Key Pair B:" << endl;
	GenerateKeyPair(p1, q1, e1, n1, d1,fi1);
	std::cout << "e:" << e1 << endl;
	std::cout << "n1:" << n1 << endl;
	std::cout << "d1:" << d1 << endl<<endl;

	
	ZZ M,C;
	std::cout << "VT:" << endl;
	std::cin >> M;
	std::cout<<"Шифруем"<<endl;
	Encrypt(C, M, e, n);
	std::cout << "C: " << C << endl;
	Decrypt(M, C, d, n);
	std::cout<<"Расшифровываем"<<endl;
	std::cout << "M: " << M << endl<<endl;
	//cout << "5)------------------------" << endl;
	
	

	ZZ k1,S1,k,S;
	/*
	Sign(S, M, d, n);

	if (M == Verify(M, S, e, n)) {cout << "digital true\n"; cout << Verify(M, S, e, n) << endl;}
	else{ cout << "digital false\n"; cout << Verify(M, S, e, n) << endl;}
	*/
	std::cout << "vvedite k:";
	std::cin >> k;
	std::cout << "Send: k, n1, n, d, e" << endl;
	Send(k1, S1, k, S, n1, n, d, e);
	std::cout << "Receive:k1, S1, d1, n1, e, n" << endl;
	Receive(k, S, k1, S1, d1, n1, e, n);


	
}

