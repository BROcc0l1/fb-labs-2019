using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;

/// <summary>
/// test
/// </summary>


namespace test
{
    public partial class Form1 : Form
    {
        public string path = @"E:\Codes\test\text1.txt";
        public char[] lang = new char[] { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и','й', 'к', 'л', 'м', ///34
            'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ','ъ','ы','ь', 'э', 'ю', 'я',' '};
        public int[] count = new int[34] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 };
        
        public string[] bigrams = new string[1024];
        public int[] bigramsCount = new int[1024];
        public int kolvo = 0;
        public double summaBigram = 0;
        public double spaceBigrams = 0;



        public string[] nocrossbigrams = new string[1156];
        public int[] nocrossbigramsCount = new int[1156];
        public int nocrosskolvo = 0;
        public double summaNocrossBigram = 0;
        public double spaceNocrossBigrams = 0;

        public double letters = 0;

        public bool lettersCheck(char a)
        {

            for (int i = 0; i < 34; i++)
            {
                if (lang[i] == a) return false;
            }
            return true;
        }
        public bool lettersCount(char a)
        {
            //Debug.WriteLine("AG");
            for (int i = 0; i < 34; i++)
            {
                if (lang[i] == a)
                {
                    count[i]++;
                    letters++;
                    return false;
                }
            }
            return true;
        }
        
        public void check(char a, char b) ///с пересекающимися биграммами
        {
            if (lettersCount(b) || lettersCheck(a)) return;
            if (b == ' '||  a==' ') spaceBigrams++;
            string z = a.ToString() + b.ToString();
            bool isadd = false;
            summaBigram++;
            for(int i = 0; i <= kolvo; i++)
            {
                //Debug.WriteLine(i);
                if (bigrams[i] == z)
                {
                    bigramsCount[i]++;
                    isadd = true;
                    break;
                }

            }
            if (isadd == false)
            {
                bigrams[kolvo] = z;
                bigramsCount[kolvo] = 1;
                kolvo++;
            }
            

           
            }///
        public void checkNocross(char a, char b)
        {
            if (lettersCheck(b) || lettersCheck(a)) return;
            if (b == ' ' || a == ' ') spaceNocrossBigrams++;
            string z = a.ToString() + b.ToString();
            bool isadd = false;
            summaNocrossBigram++;
            for (int i = 0; i < nocrosskolvo; i++)
            {
               
                if (nocrossbigrams[i] == z)
                {
                    nocrossbigramsCount[i]++;
                    isadd = true;
                    break;
                }

            }
            if (isadd == false)
            {
                nocrossbigrams[nocrosskolvo] = z;
                nocrossbigramsCount[nocrosskolvo] = 1;
                nocrosskolvo++;
            }
        }
        public double entropybigrams()
        {
            double answ = 0f;

            for (int i = 0; i < kolvo; i++)
            {
                if (bigramsCount[i] != 0) answ = answ + (bigramsCount[i] / summaBigram) * Math.Log((bigramsCount[i] / summaBigram), 2);
            }

            answ = -(answ / 2);
            return answ;
        }
        public double entropybigrams1()
        {
            double answ = 0f;
            spaceBigrams = spaceBigrams / 8;
            for (int i = 0; i < kolvo; i++)
            {
                //string bb=bigrams[i];
                
                if (bigrams[i][0] != ' ' || bigrams[i][1] != ' ')
                {
                    if (bigramsCount[i] != 0) answ = answ + (bigramsCount[i] / (summaBigram-(spaceBigrams))) * Math.Log((bigramsCount[i] / (summaBigram - (spaceBigrams ))), 2);
                }
                }

            answ = -(answ/2);
            return answ;
        }
        public double entropy()
        {
            double answ = 0f;
            
            for (int i = 0; i < 34; i++)
            {
              if(count[i]!=0)answ = answ + (count[i] / letters) * Math.Log((count[i] / letters), 2);     
            }

            answ = -answ;
            return answ;
        }

        public double entropy1()
        {
            double answ = 0f;

            for (int i = 0; i < 33; i++)
            {
                if (count[i] != 0) answ += -((count[i] / (letters-count[33])) * Math.Log((count[i] / (letters-count[33])), 2));
            }

            
            return answ;
        }

        public double nocrossentropy()
        {
            double answ = 0f;

            for (int i = 0; i < nocrosskolvo; i++)
            {                      
                    if (nocrossbigramsCount[i] != 0) answ = answ + (nocrossbigramsCount[i] / summaNocrossBigram) * Math.Log((nocrossbigramsCount[i] / summaNocrossBigram), 2);  
             }


            answ = -(answ / 2);
            return answ;
        }
        public double nocrossentropy1()
        {
            double answ = 0f;
            spaceNocrossBigrams = spaceNocrossBigrams / 8;
            for (int i = 0; i < nocrosskolvo; i++)
            {
                if (nocrossbigrams[i][0] != ' ' || nocrossbigrams[i][1] != ' ')
                {
                    if (nocrossbigramsCount[i] != 0) answ = answ + (nocrossbigramsCount[i] / (summaNocrossBigram-(spaceNocrossBigrams))) * Math.Log((nocrossbigramsCount[i] / (summaNocrossBigram - (spaceNocrossBigrams))), 2);
                }
            }


            answ = -(answ / 2);
            return answ;
        }

        public Form1()
         {
            InitializeComponent();
         

            button1.Click += Button1_Click;
            button2.Click += Button2_Click;
            button9.Click += Button9_Click;
            button3.Enabled = false; 
            button4.Enabled = false;        
            button5.Enabled = false;
            button6.Enabled = false;
            button7.Enabled = false;
            button8.Enabled = false;

            textBox1.Enabled = false;
            textBox2.Enabled = false;
            textBox3.Enabled = false;
            textBox4.Enabled = false;
            textBox5.Enabled = false;
            textBox6.Enabled = false;


        }

        private void Button9_Click(object sender, EventArgs e)
        {
            string writePath = @"E:\Codes\test\hta.txt";

      
            try
            {
                using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
                {
                    double r1, r2, r3;

                    r1 = 1 - ((Math.Log(34, 2) / entropy()));
                    r2 = 1 - ((Math.Log(34, 2) / (entropybigrams())));
                    r3 = 1 - ((Math.Log(34, 2) / nocrossentropy()));
                    sw.WriteLine($"R1 == {-r1}");
                    sw.WriteLine($"R2 == {-r2}");
                    sw.WriteLine($"R3 == {-r3}");

                    for (int i = 0; i < 34; i++)
                    {                
                        sw.WriteLine($" {lang[i]} === {Math.Round((count[i]/letters),3)}");
                    }
                    sw.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
                 
                    for(int i = 0; i < kolvo; i++)
                    {
                        
                        sw.WriteLine($" {bigrams[i]} === {Math.Round((bigramsCount[i]/summaBigram),8)}");
                       
                      
                    }
                    sw.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                 
                    for (int i = 0; i < kolvo; i++)
                    {

                        sw.WriteLine ($" {nocrossbigrams[i]} === {Math.Round((nocrossbigramsCount[i]/summaNocrossBigram),8)}");
                        

                    }
                }
                Console.WriteLine("Запись выполнена");
            }
            catch (Exception eeeee)
            {
                Console.WriteLine(eeeee.Message);
            }
        }

        private void Button1_Click(object sender, EventArgs e)
        {


            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.UTF8))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    for (int i = 0; i < line.Length - 1; i++)
                    {
                        line = line.ToLower();
                        check(line[i], line[i + 1]);           
                    }
                   
                   
                    if(line.Length!=0)lettersCount(line[0]);
                   //if(line.)
   
                }
                button3.Enabled = true;
                button4.Enabled = true;
                button1.Enabled = false;
                button5.Enabled = true;
                button6.Enabled = true;        
            }
            textBox1.Enabled = true;
            textBox1.Text = Math.Round(entropy(), 3).ToString();
            textBox2.Enabled = true;
            textBox2.Text = Math.Round(entropy1(), 3).ToString();
            textBox3.Enabled = true;
            textBox3.Text = Math.Round(entropybigrams(), 3).ToString();
            textBox4.Enabled = true;
            textBox4.Text = Math.Round(entropybigrams1(), 3).ToString();
       

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.UTF8))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    for (int i = 0; i < line.Length - 1; i++)
                    {
                        line = line.ToLower();
                        checkNocross(line[i], line[i +1]);
                        i++;
                    }
                }


                
                    
            }
            button2.Enabled = false;
            button7.Enabled = true;
            button8.Enabled = true;
            textBox5.Enabled = true;
            textBox5.Text = Math.Round(nocrossentropy(), 3).ToString();
            textBox6.Enabled = true;
            textBox6.Text = Math.Round(nocrossentropy1(), 3).ToString();
            Debug.WriteLine(nocrossentropy());
            Debug.WriteLine(nocrossentropy1());

        }

        
    }
}
