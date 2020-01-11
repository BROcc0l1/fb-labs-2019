using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CriptoLab4
{
    class Program
    {
        static int[] P1 = new int[] { 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0 }; //24
        static int[] P2 = new int[] { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1 };//20
        static int[] zeroOne = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; //24
        static int[] zeroOneCpy = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; //24
        static int[] zeroTwo = new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; //20
        static int[] zeroTwoCpy = new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; //20
        static int period = 0;
        static int period2 = 0;
        //
        static int[] buff1 = new int[5000000];
        static int buffcounter = 0;
        static int[] buff2 = new int[5000000];
        static int buff2counter = 0;

        public static int mod(int value, int modul)
        {
            while (value < 0 || value >= modul)
            {
                if (value < 0) value = value + modul;
                if (value >= modul) value = value - modul;
            }
            return value;
        }
        public static bool equals(int[]a, int[]b)
        {
            for(int i = 0; i < a.Length; i++)
            {
                if (a[i] != b[i]) return true;
            }
            return false;
        }
        public static void raschet(int[] a)
        {
            int NewNumb = 0;
            for(int i = 0; i < a.Length; i++)
            {
                NewNumb += a[i] * P1[i];
            }
            NewNumb = mod(NewNumb, 2);


            //buff += a[0].ToString();
            buff1[buffcounter] = a[0];
            buffcounter++;
    
            for(int i = 1; i < a.Length; i++)
            {
                a[i - 1] = a[i];
            }
            a[a.Length - 1] = NewNumb;
            

        }
        public static void raschet2(int[] a)
        {
            int NewNumb = 0;
            for (int i = 0; i < a.Length; i++)
            {
                NewNumb += a[i] * P2[i];
            }
            NewNumb = mod(NewNumb, 2);


            //buff += a[0].ToString();
            buff2[buff2counter] = a[0];
            buff2counter++;

            for (int i = 1; i < a.Length; i++)
            {
                a[i - 1] = a[i];
            }
            a[a.Length - 1] = NewNumb;


        }

        public static void kgramms(int k,int[] text,int length)
        {
            string[] kgramms = new string[500];
            int[] kgrammsKolvo = new int[500];       
            int counter = 0;
            int cycle = 0;
            int dlina = length - (length % k);

            for(int i = 0; i < dlina; i += k)
            {
                string zz = "";
                bool trigg = false;
                for(int j = 0; j < k; j++)
                {
                    zz += text[i + j].ToString();
                }

                for(int z = 0; z < counter; z++)
                {
                    if (kgramms[z] == zz)
                    {
                        kgrammsKolvo[z]++;
                        trigg = true;
                        break;
                    }
                }
                if (trigg == false)
                {
                    kgramms[counter] = zz;
                    kgrammsKolvo[counter] = 1;
                    counter++;
                }
                cycle++;
            }
            Console.WriteLine($"{k}-gramms");
            int perehod = 0;
            for(int j = 0; j < counter; j++)
            {
                double chastot = kgrammsKolvo[j] / (double)cycle;
                
                Console.Write($"{kgramms[j]} - {chastot}               ");
                perehod++;
                if (perehod == 2)
                {
                    Console.Write("\n");
                    perehod = 0;
                }
            }
        }

        public static void autocorelation(int d,int[] text, int length)
        {
            int summa = 0;
            for(int i = 0; i < length - 1; i++)
            {
                summa += mod((text[i] + text[mod((i + d),length)]), 2);
            }
            Console.WriteLine($"d={d}  {summa}");
        }




        static void Main(string[] args)
        {
          
   

            do
            {
                raschet(zeroOne);
                period++;
                //if (period % 1000 == 0) Console.WriteLine(period);
            } while (equals(zeroOne, zeroOneCpy));
            do
            {
                raschet2(zeroTwo);
                period2++;
                //if (period2 % 1000 == 0) Console.WriteLine(period);
            } while (equals(zeroTwo, zeroTwoCpy));
            Console.WriteLine($"FIRST PERIOD {period}");
            Console.WriteLine($"SECOND PERIOD {period2}");
            Console.WriteLine("");
            Console.WriteLine("THE FIRST");
            for (int i = 1; i <6; i++)
            {
                kgramms(i, buff1, buffcounter);
            }
            Console.WriteLine("THE SECOND");
            for (int i = 1; i < 6; i++)
            {
                kgramms(i, buff2, buff2counter);
            }
            Console.WriteLine("AUTOCORRELATION");
            Console.WriteLine("\n FIRST");
            for (int i = 1; i < 11; i++)
            {
                autocorelation(i, buff1, buffcounter);
            }
            Console.WriteLine("\n SECOND");
            for (int i = 1; i < 11; i++)
            {
                autocorelation(i, buff2, buff2counter);
            }
            Console.ReadKey();
        }
    }
}
