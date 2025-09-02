using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Security.Policy;
using System.Threading;
using System.IO;
using System.Diagnostics;

namespace cs_app
{
    internal class Program
    {
        [DllImport("libcpp_dll", EntryPoint = "ProcessMatrix")]
        public extern static double ProcessMatrix(int mx_size, int cicle_num);

        [DllImport("libcpp_dll", EntryPoint = "SolutionOfMatrixByKramer")]
        public extern static bool SolutionOfMatrixByKramer(double[] solving, double[] rou, double[] mxb, int mx_size);
        //----------------------------------------------------------------------------------------------------------------
        static void Main(string[] args)
        {
            string str;
            Console.WriteLine(" 1 ----------------------------------------------------------------------------------");
            Console.WriteLine(" Решение системы линейных уравнений на основе циркулянтной матрицы.");
            Console.WriteLine(" Матрица порядка 3х3, вычисление в коде C#, с инициализации генератором случайных чисел");
            int matrix_size = 3;
            Random rnd = new Random();
            double[] rou = new double[matrix_size];
            double[] mxB = new double[matrix_size];
            double[] solving = new double[matrix_size];
            //--------------------------------------------
            for (int i = 0; i < matrix_size; i++)
                rou[i] = (double)rnd.Next(-100, 100);
            for (int i = 0; i < matrix_size; i++)
                mxB[i] = (double)rnd.Next(100);
            Matrix mx = new Matrix(rou, mxB, matrix_size);
            if (mx.getSolving())
                Console.WriteLine(mx.ToString());
            else
                Console.WriteLine("\nОшибка решения системы линейных уравнений");

            Console.WriteLine(" 2 ----------------------------------------------------------------------------------");
            Console.WriteLine(" Решение той же системы линейных уравнений функцией из библиотеки C++ DLL");
            try
            {
                bool dll = SolutionOfMatrixByKramer(solving, mx.rou, mx.mxB, matrix_size);
                if (dll)
                {
                    Console.WriteLine("Решешие системы линейных уравнений");
                    for (int j = 0; j < matrix_size; j++)
                        Console.Write($"x{j + 1}={solving[j]:F1} ");
                    Console.WriteLine();

                }
                else
                    Console.WriteLine("\nОшибка решения системы линейных уравнений");
            }
            catch (DllNotFoundException exc)
            {
                Console.WriteLine("*** " + exc.Message + " ***");
            }
            Console.Write("\nДля продолжения нажмите любую клавишу >");
            str = Console.ReadLine();

            Console.WriteLine(" 3 ----------------------------------------------------------------------------------");
            Console.WriteLine(" Создание объекта типа TimesList методом сериализации из файла");
            string output = "";
            string fname = "";
            TimesList tl = new TimesList();
            Console.WriteLine(" Ввести имя файла информационной базы ");
            do
            {
                output = "нет";
                Console.Write(" Имя файла копии объекта -> ");
                fname = Console.ReadLine();
                if (!fname.Contains("Copies\\"))
                    fname = "Copies\\" + fname;
                if (!initTimesList(fname, tl))
                {
                    Console.Write(" Повторить ввод имени файла ? <да(по умолчанию)/ нет>   -> ");
                    output = Console.ReadLine();
                    if (!(output == "да" || output == ""))
                    {
                        Console.Write("\n**** Программа завершена ****\n");
                        Thread.Sleep(5000);
                        return;
                    }
                }
            } while (output == "да" || output == "");

            Console.WriteLine(" 4 ----------------------------------------------------------------------------------");
            bool isChange = false;
            Console.WriteLine(tl.ToString());
            do
            {
                Console.Write(" Ввести параметры для теста ? <да(по умолчанию)/ нет>   -> ");
                output = Console.ReadLine();
                if (!(output == "да" || output == ""))
                {
                    Console.Write(" Загрузить новый файл ? <да / нет(по умолчанию)>   -> ");
                    output = Console.ReadLine();
                    if (output == "да")
                    {
                        Console.WriteLine(" Ввести имя файла информационной базы ");
                        Console.Write(" Имя файла копии объекта -> ");
                        fname = Console.ReadLine();
                        if (!fname.Contains("Copies\\"))
                            fname = "Copies\\" + fname;
                        initTimesList(fname, tl);
                        Console.WriteLine(tl.ToString());
                        continue;
                    }
                    else
                        break;
                }
                output = "да";
                Console.WriteLine(" Ввести порядок матрицы и число повторов");
                int mx_size = 0, cicle_num = 0;
                try
                {
                    Console.Write(" Порядок матрицы   -> ");
                    str = Console.ReadLine();
                    mx_size = Convert.ToInt32(str);
                    Console.Write(" Количество циклов повторов -> ");
                    str = Console.ReadLine();
                    cicle_num = Convert.ToInt32(str);
                }
                catch (FormatException ex)
                {
                    Console.WriteLine(" *** " + ex.Message);
                    continue;
                }
                Console.Clear();
                Console.WriteLine("\n 5 -------------------------------------------------");
                Console.WriteLine(" Приложение выполняет вычисления ");
                if (PerformMatrixTimer(mx_size, cicle_num, tl))
                {
                    Console.WriteLine(tl.ToString());
                    isChange = true;
                }
                else
                    Console.WriteLine("*** Execution PerformMatrixTimer Error ***");
            } while (output == "да");

            Console.WriteLine("\n 6 ----------------------------------------------------------------------------------");
            Console.WriteLine(" Если внесены изменения, коллекция из объекта TimesList будет сохранена в файле");
            if (isChange)
            {
                Console.WriteLine(" Коллекция сохранена в файле " + fname + " c использованием сериализации");
                tl.Save(fname);
                tl.SaveText("report.txt");
            }


            Console.Write("\n**** Программа завершена ****\n");
            Thread.Sleep(5000);
        }   // main()
        //---------------------------------------------------------------------------------------------------------------------
        static bool PerformMatrixTimer(int size, int cicle, TimesList tl)
        {
            // C# perform  timer -----------------------------
            Matrix mx = new Matrix(size);
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Restart();
            for (int i = 0; i < cicle; i++)
                mx.getSolving();
            stopWatch.Stop();
            GC.Collect();
            GC.WaitForPendingFinalizers();
            double timeCS = (double)stopWatch.ElapsedMilliseconds / 1000;
            // C++ DLL function perform  timer ---------------
            double timeCPP = -1;
            try
            {
                timeCPP = ProcessMatrix(size,cicle);
            }
            catch (DllNotFoundException exc)
            {
                Console.WriteLine("*** " + exc.Message + " ***");
            }
            // -----------------------------------------------
            tl.Add(size, cicle, timeCS, timeCPP);
            return true;
        }  // PerformMatrixTime
        //---------------------------------------------------------------------------------------------------------------------
        static bool initTimesList(string fname, TimesList tl)
        {
            if (File.Exists(fname))
            {
                Console.WriteLine(" *** Произведена инициализации объекта данными из файла " + fname + "\n");
                tl.Load(fname);
            }
            else
            {
                if(!tl.Save(fname))
                    return false;
                else
                    Console.WriteLine(" *** Файла не существует. Создана копия объекта в файле " + fname + "\n");
            }
            return true;
        }
    }   // class Program
}
