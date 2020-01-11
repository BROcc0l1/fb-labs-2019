using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Security.Cryptography;



namespace CryptoLab5
{
    class Abonent:Program
    {
        private BigInteger p, q, d;
        public BigInteger e, n;
        public string name;   
        public Abonent()
        {
            p = 0;q = 0;d = 0;e = 0;n = 0;
        }
        public Abonent(string a)
        {
            name = a;
        }
        public void GenerateKeyPair()
        {
            p = SimpleChislo();
            q = SimpleChislo();
            n = BigInteger.Multiply(p, q);
            BigInteger fin = BigInteger.Multiply(BigInteger.Subtract(p, (BigInteger)1), BigInteger.Subtract(q, (BigInteger)1));     
            e = (BigInteger)(Math.Pow(2, 16) + 1);        
            if (BigInteger.GreatestCommonDivisor(fin,e)!= 1)
            {
                Console.WriteLine("Please reload programm,gcd(fin,e)>1");
                return;
            }

            d = MultiplicativeInverse(e, fin);
            Console.WriteLine(name);
            Console.WriteLine("");
            Console.WriteLine($"p = {p.ToString("X")}");
            Console.WriteLine($"q = {q.ToString("X")}");
            Console.WriteLine($"n = {n.ToString("X")}");
            Console.WriteLine($"fi(n) = {fin.ToString("X")}");
            Console.WriteLine($"e = {e.ToString("X")}");
            Console.WriteLine($"d = {d.ToString("X")}");
            Console.WriteLine($"_____________________________________________");

        }

        public static BigInteger Encrypt(BigInteger massage, BigInteger e,BigInteger n)
        {
           

            BigInteger answ=BigInteger.ModPow(massage, e, n);
            Console.WriteLine(answ);
            Console.WriteLine(answ.ToString("X"));
           
            return answ;
        }
        public static BigInteger Decrypt(BigInteger massage, BigInteger d,BigInteger n)
        {
            BigInteger answ = BigInteger.ModPow(massage, d, n);
            return answ;
        }
        public  BigInteger Sign(int massage,BigInteger d, BigInteger n)
        {
            BigInteger answ = BigInteger.ModPow(massage, d, n);

            return answ;

        }
        public  void Verify(int massage,BigInteger s,BigInteger n, BigInteger e)
        {
            if (massage == BigInteger.ModPow(s, e, n)) Console.WriteLine("Verifed");
            else Console.WriteLine("Not verified");
        }

        public BigInteger SendKey(int key,BigInteger e1, BigInteger n1,ref BigInteger Value4returnS1)
        {
            while (n1 < n)
            {
                Console.WriteLine("Generating new keys...");
                GenerateKeyPair();
            }
            BigInteger k1 = BigInteger.ModPow(key, e1, n1);
            BigInteger S = BigInteger.ModPow(key, d, n);
            Value4returnS1 = BigInteger.ModPow(S, e1, n1);
            return k1;
        }
        public void ReceiveKey(BigInteger k1,BigInteger S1,BigInteger eA, BigInteger nA)
        {
            BigInteger k = BigInteger.ModPow(k1, d, n);
            BigInteger S = BigInteger.ModPow(S1, d, n);
            BigInteger k2 = BigInteger.ModPow(S, eA, nA);
            if (k == k2) Console.WriteLine("ReceiveKey TRUE");
            else Console.WriteLine("FALSE");
        }
       
     

    }
    class Program
    {
        static Random rnd = new Random();  
        static int colvo = 15; //длинна генереруемого числа

        public static BigInteger MultiplicativeInverse(BigInteger e, BigInteger fi)
        {
            BigInteger result;
            BigInteger res1;
            int k = 1;
            while (true)
            {
                result = (1 + (k * fi)) / e;
                res1= (1 + (k * fi)) % e;
                if (res1 == 0) //integer
                {
                    return result;
                }
                else
                {
                    k++;
                }
            }
        }

        public static BigInteger mod(BigInteger a, BigInteger mod) 
        {
            do
            {
                if (a.CompareTo((BigInteger)0) == -1) a = BigInteger.Add(a, mod);
                if (a.CompareTo(mod) == 1) a = BigInteger.Subtract(a, mod);


            } while (a.CompareTo((BigInteger)0) == -1 || a.CompareTo((BigInteger)mod) == 1);     //a<0 || a>mod
            return a;
        }
       
        static public bool ProstotaTest(BigInteger chislo, int cycles)
        {
            if (chislo == 2 || chislo == 3)
                return true;
            if (chislo < 2 || chislo % 2 == 0)
                return false;


            BigInteger t = chislo - 1;
            int counter = 0;
             while (t % 2 == 0)
            {
                t=t/2;
                counter++;
            }

            for (int i = 0; i < cycles; i++)
            {
                RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();

                byte[] _zz = new byte[chislo.ToByteArray().LongLength];

                BigInteger zz;

                do
                {
                    rng.GetBytes(_zz);
                    zz = new BigInteger(_zz);
                }
                while (zz < 2 || zz >= chislo - 2);     
                BigInteger x = BigInteger.ModPow(zz, t, chislo);

                if (x == 1 || x == chislo - 1)
                    continue;

                for (int r = 1; r < counter; r++)
                {
                    x = BigInteger.ModPow(x, 2, chislo);
                    if (x == 1)
                        return false;
                    if (x == chislo - 1)
                        break;
                }

                if (x != chislo - 1)
                    return false;
            }
            return true;
        }

        static BigInteger BigGen(int length)
        {
           
            string a = "";
          
            a += rnd.Next(1, 10).ToString();
            for (int i = 0; i < length - 1; i++)
            {
                int value = rnd.Next(0, 10);
                a += value.ToString();
            }
            BigInteger b= BigInteger.Parse(a);
            return b;
        }

        public static BigInteger SimpleChislo()
        {
            
            BigInteger a;
            do
            {
                a = BigGen(colvo);           
            } while (!(ProstotaTest(a, 20)));
            return a;
        }
       
        public static BigInteger To10(string input)
        {
            BigInteger result = 0;
            result = BigInteger.Parse(input, System.Globalization.NumberStyles.HexNumber);
            return result;
        }


        static void Main(string[] args)
        {

            string a = "9892515245781643203548322512694297002734929930336103961308827076858951801232194368154095843280365701800280246244749782278628765246257508230685723422420631";
            BigInteger n =BigInteger.Parse(a);
            BigInteger e = To10("10001");
          
            Abonent A = new Abonent("Abonent A");
            Abonent B = new Abonent("Abonent B");
            A.GenerateKeyPair();
            B.GenerateKeyPair();
            BigInteger S1 = 0;
            BigInteger k1 = A.SendKey(35, B.e, B.n, ref S1);

            Console.WriteLine($"S1= {S1.ToString("X")}");
            Console.WriteLine($"k1= {k1.ToString("X")}");

            B.ReceiveKey(k1, S1, A.e, A.n);

            Console.ReadKey();
        }
    }
}


