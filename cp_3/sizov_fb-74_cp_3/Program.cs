using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CryptoLab3
{
    class Program
    {
        public static char[] lang = new char[] { 'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и','й', 'к', 'л', 'м', ///31
            'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ','ь','ы', 'э', 'ю', 'я'};
        public static string path = @"E:\Codes\CryptoLab3\14.txt";
        public static string[] bg = new string[1024];
        public static int[] bgcount = new int[1024];
        //correct top of bigram
        static string[] bgcorrect = new string[5] { "ст", "но", "то", "на", "ен" };
        static string[] bgincorrect = new string[5];
        //the most()
        static int[] most = new int[5];
        static int[] pointer = new int[5];
        //findkey()
        public static int[] keyA = new int[1000];
        static int counterA = 0;
        public static int[] keyB = new int[1000];
        //
        static int bglength = 0;
        static int bgsumma = 0;
        //робота с текстами
        public static string[] getedtexts = new string[1000];
        public static string[] zapret = new string[13] { "аь", "иь", "ыь", "йь", "оь", "уь", "еь", "эь", "яь", "ьь", "юь","йа","йу" };
        public static string[] filtered = new string[100];
        public static int[] schet = new int [100];
        //
        public static string[] systems = new string[1000];


        public static int mod(int value, int modul)
        {
            while (value < 0 || value >= modul)
            {
                if (value < 0) value = value + modul;
                if (value >= modul) value = value - modul;
            }
            return value;
        }

        static int summabg(string z)
        {
            int j;
            if (z.Length % 2 == 0) j = z.Length;
            else j = z.Length - 1;
            return j / 2;
        }
        public static void bigramCount(string str)
        {
            int strlength = bgsumma * 2;


            for (int i = 0; i < strlength; i += 2)
            {
                string z = str[i].ToString() + str[i + 1].ToString();
                bool trigger = false;
                for (int j = 0; j < bglength; j++)
                {
                    if (bg[j] == z)
                    {
                        bgcount[j]++;
                        trigger = true;
                        break;
                    }
                }
                if (trigger == false)
                {
                    bg[bglength] = z;
                    bgcount[bglength] = 1;
                    bglength++;
                }
            }
        }


        public static void findthemost()
        {


            most[0] = bgcount[0];
            for (int i = 0; i < bglength; i++)
            {
                if (most[0] < bgcount[i])
                {
                    most[0] = bgcount[i];
                    pointer[0] = i;
                }
            }
            most[1] = bgcount[0];
            for (int i = 0; i < bglength; i++)
            {
                if (most[1] < bgcount[i] && i != pointer[0])
                {
                    most[1] = bgcount[i];
                    pointer[1] = i;
                }
            }
            most[2] = bgcount[0];
            for (int i = 0; i < bglength; i++)
            {
                if (most[2] < bgcount[i] && i != pointer[0] && i != pointer[1])
                {
                    most[2] = bgcount[i];
                    pointer[2] = i;
                }
            }
            most[3] = bgcount[0];
            for (int i = 0; i < bglength; i++)
            {
                if (most[3] < bgcount[i] && i != pointer[0] && i != pointer[1] && i != pointer[2])
                {
                    most[3] = bgcount[i];
                    pointer[3] = i;
                }
            }
            most[4] = bgcount[0];
            for (int i = 0; i < bglength; i++)
            {
                if (most[4] < bgcount[i] && i != pointer[0] && i != pointer[1] && i != pointer[2] && i != pointer[3])
                {
                    most[4] = bgcount[i];
                    pointer[4] = i;
                }
            }
            for (int i = 0; i < 5; i++) Console.WriteLine($"Биграмма {bg[pointer[i]]} частота {most[i]}");
            for (int i = 0; i < 5; i++) bgincorrect[i] = bg[pointer[i]];

        }

        public static int newgcd(int a, int b, ref int xRef, ref int yRef)
        {
            if (a == 0)
            {
                xRef = 0; yRef = 1;
                return b;
            }
            int x1 = 1;
            int y1 = 1;
            ref int x1Ref = ref x1;
            ref int y1Ref = ref y1;
            int d = newgcd(b % a, a, ref x1Ref, ref y1Ref);
            xRef = y1 - (b / a) * x1;
            yRef = x1;
            return d;
        }

        public static int perevod(string bgramma){
            int a = 0, b = 0, z;
            
            for(int i = 0; i < 31; i++)
            {
                if (bgramma[0] == lang[i])
                {
                    a = i;
                    break;
                }
            } //a
            for (int i = 0; i < 31; i++)
            {
                if (bgramma[1] == lang[i])
                {
                    b = i;
                    break;
                }
            }//b
            z = a * 31 + b;
            return z;
        }
        public static string perevod(int z)
        {
            int a, b;
            string bgramma = "";
            a = z / 31; 
            b = z % 31;
            bgramma += lang[a];
            bgramma += lang[b];
            return bgramma;
        }




        public static int ravenstvo(int a,int b, int m)
        {
            int answ;
            int x = 1;
            int y = 1;
          

            ref int xR = ref x;
            ref int yR = ref y;        

            int d = newgcd(a,m, ref xR, ref yR);

            a = mod(a, m);
            b = mod(b, m);
     
            if (d == 1)
            {
                keyA[counterA] = mod(x * b, m);
                
                counterA++;



                return 1;
            }
            if(b%d!=0){
                
                return 0;
            }
            if (b % d == 0)
            {
                Console.WriteLine("Ne odin koren");

                if (a % d != 0) Console.WriteLine("Error a");
                        a = a / d;
          
                if (b % d != 0) Console.WriteLine("Error b");
                b = b / d;
        
                if (m % d != 0) Console.WriteLine("Error m");
               
                m = m / d;
              
                newgcd(a,m, ref xR, ref yR);

                answ = mod(x * b, m);
                for (int i = 0; i < d; i++)
                {
                    keyA[counterA] = answ + m * i;
                    counterA++;               
                }
         

                return d;

            }
            return 0;
        }


    

        public static void findkey(string a1, string a2, string b1, string b2)
        {
            int first1, first2, second1, second2, z, n, jj;
            
          
            first1 = perevod(a1);
            
            second1 = perevod(b1);
            
            first2 = perevod(a2);
         
            second2 = perevod(b2);
            z = mod(first1 - second1,961); //шифров
            n = mod(first2 - second2,961); //не шифр
            jj = ravenstvo(n, z, 961);
            string answ = a2 + " перешла в " + a1 + "; " + b2 + " перешла в " + b1;
            for (int i = counterA - jj; i < counterA; i++)
            {
                systems[i] = answ;
                keyB[i] = mod(first1 - keyA[i] * first2, 961);
               

            }

            




        }


        public static string decript(string text,int a,int b)
        {
            string answ = "";

            int x = 1;
            int y = 1;
            ref int xR = ref x;
            ref int yR = ref y;
            
            int aReverse;
            newgcd(a, 961, ref xR, ref yR);
            aReverse = mod(x, 961);

            int dlinna = text.Length;
            if (dlinna % 2 != 0) dlinna = dlinna-1;
            

            for(int i=0; i < dlinna; i+=2)
            {
                int zz;
                string bbc = text[i].ToString() + text[i + 1].ToString();
                zz = perevod(bbc);
                zz = mod((zz - b) * aReverse, 961);
                bbc = perevod(zz);
                answ += bbc;
            }

            return answ;
        }


        public static bool filter(string text)
        {
            int dlinna = text.Length/2;


            for (int i = 0; i < dlinna; i += 2)
            {
                string bbc = text[i].ToString() + text[i + 1].ToString();
                for(int j = 0; j < 13; j++)
                {
                    if (bbc == zapret[j])
                    {                   
                        Console.WriteLine($"Запрещенная биграмма {zapret[j]}");
                        return false;
                    }
                }
            }
            
            return true;
        }









        static void Main(string[] args)
        {
            string inputtext = "";

            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.UTF8))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    inputtext += line;
                }
            }
            bgsumma = summabg(inputtext);
            bigramCount(inputtext);   
            findthemost();
            Console.WriteLine(inputtext.Length);
            Console.WriteLine(" ");

        
            //(0,*,*,*)                                              ///1
            for (int i = 0; i < 5; i++)                                                             ///2
                                                                                       
            {
                for(int j = 0; j < 5; j++)                                                          ///3
                {
                    if (j != 0) for (int k = 0; k < 5; k++)                                         ///4
                        {
                            if (k != i)
                            {
                                findkey(bgincorrect[0], bgcorrect[i], bgincorrect[j], bgcorrect[k]);
                            }
                        }
                }
            }
            //(1,*,*,*)

            for (int i = 0; i < 5; i++)                                                             ///2

            {
                for (int j = 0; j < 5; j++)                                                          ///3
                {
                    if (j != 1) for (int k = 0; k < 5; k++)                                         ///4
                        {
                            if (k != i)findkey(bgincorrect[1], bgcorrect[i], bgincorrect[j], bgcorrect[k]);
                        }
                }
            }

            //(2,*,*,*)
            for (int i = 0; i < 5; i++)                                                             ///2

            {
                for (int j = 0; j < 5; j++)                                                          ///3
                {
                    if (j != 2) for (int k = 0; k < 5; k++)                                         ///4
                        {
                            if (k != i) findkey(bgincorrect[2], bgcorrect[i], bgincorrect[j], bgcorrect[k]);
                        }
                }
            }

            //(3,*,*,*)
            for (int i = 0; i < 5; i++)                                                             ///2

            {
                for (int j = 0; j < 5; j++)                                                          ///3
                {
                    if (j != 3) for (int k = 0; k < 5; k++)                                         ///4
                        {
                            if (k != i)findkey(bgincorrect[3], bgcorrect[i], bgincorrect[j], bgcorrect[k]);
                        }
                }
            }
            //(4,*,*,*)
            for (int i = 0; i < 5; i++)                                                             ///2

            {
                for (int j = 0; j < 5; j++)                                                          ///3
                {
                    if (j != 4) for (int k = 0; k < 5; k++)                                         ///4
                        {
                            if (k != i) findkey(bgincorrect[4], bgcorrect[i], bgincorrect[j], bgcorrect[k]);
                        }
                }
            }



            for(int i = 0; i < counterA; i++)
            {
                getedtexts[i]=decript(inputtext, keyA[i], keyB[i]);
            }
            for (int i = 0; i < counterA; i++)
            {
                Console.WriteLine($"Key A = {keyA[i]}, Key B = {keyB[i]}");
                Console.WriteLine(systems[i]);
                if (filter(getedtexts[i]))
                {
                    Console.WriteLine(getedtexts[i]);
                }
                Console.WriteLine(" ");
            }

            

                Console.WriteLine("End");
           
            //for(int i=0;i<counterA;i++)  Console.WriteLine(keyA[i]);



            Console.ReadKey();
        }
       
      


    }
}
