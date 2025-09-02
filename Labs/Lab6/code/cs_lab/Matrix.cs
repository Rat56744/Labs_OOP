using System;

namespace cs_app
{
    internal class Matrix
    {
        private readonly int size;
        private double[,] mxA;
        public double[] mxB { get; }
        public double[] rou { get; }
        public double[] solving { get; }

        private readonly double[,] mx3 = new double[3, 3];
        private readonly double[,] mx4 = new double[4, 4];
        private readonly double[,] mx5 = new double[5, 5];
        private readonly double[,] mx6 = new double[6, 6];
        private readonly double[,] mx7 = new double[7, 7];
        private readonly double[,] mx8 = new double[8, 8];
        private readonly double[,] fmx3 = new double[3, 3];
        private readonly double[,] fmx4 = new double[4, 4];
        private readonly double[,] fmx5 = new double[5, 5];
        private readonly double[,] fmx6 = new double[6, 6];
        private readonly double[,] fmx7 = new double[7, 7];

        public Matrix(int n)
        {
            size = n;
            mxA = new double[size, size];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    mxA[i, j] = 0;
            
            mxB = new double[size];
            for (int i = 0; i < size; i++)
                mxB[i] = (i + 1) * 2;
            
            rou = new double[size];
            for (int i = 0; i < size; i++)
                rou[i] = i;
            
            rou[0] = 55;
            solving = new double[size];
            for (int i = 0; i < size; i++)
                solving[i] = 0;
        }

        public Matrix(double[] rou, double[] mxB, int n)
        {
            size = n;
            this.rou = new double[size];
            for (int i = 0; i < size; i++)
                this.rou[i] = rou[i];
            
            this.mxB = new double[size];
            for (int i = 0; i < size; i++)
                this.mxB[i] = mxB[i];
            
            mxA = new double[size, size];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    mxA[i, j] = 0;
            
            solving = new double[size];
            for (int i = 0; i < size; i++)
                solving[i] = 0;
        }

        public bool getSolving()
        {
            double summ = 0;
            for (int i = 0; i < size; i++)
                summ += rou[i];
            
            if (summ == 0)
                return false;

            mxA = cir_matrix(rou, size);
            double det_A = get_det(mxA, size);
            if (det_A == 0)
                return false;

            for (int j = 0; j < size; j++)
            {
                var mxj = cir_matrix(rou, size);
                for (int i = 0; i < size; i++)
                    mxj[i, j] = mxB[i];
                
                double det_j = get_det(mxj, size);
                solving[j] = det_j / det_A;
            }
            return true;
        }

        private double[,] cir_matrix(double[] rou, int n)
        {
            double[,] mx = new double[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    mx[i, j] = j >= i ? rou[j - i] : rou[n - i + j];
                }
            return mx;
        }

        public static void get_mxB(double[] mxB, double[] rou, double[] solving, int n)
        {
            double[,] mxA = new double[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    mxA[i, j] = j >= i ? rou[j - i] : rou[n - i + j];
                }

            for (int i = 0; i < n; i++)
            {
                mxB[i] = 0;
                for (int j = 0; j < n; j++)
                    mxB[i] += mxA[i, j] * solving[j];
            }
        }

        private double get_det(double[,] mx, int n)
        {
            double summ = 0;
            switch (n)
            {
                case 1: return mx[0, 0];
                case 2: return mx[0, 0] * mx[1, 1] - mx[0, 1] * mx[1, 0];
                case 3: return mx[0, 0] * (mx[1, 1] * mx[2, 2] - mx[1, 2] * mx[2, 1]) - 
                             mx[0, 1] * (mx[1, 0] * mx[2, 2] - mx[1, 2] * mx[2, 0]) + 
                             mx[0, 2] * (mx[1, 0] * mx[2, 1] - mx[1, 1] * mx[2, 0]);
                case 4:
                    for (int j = 0; j < n; j++)
                    {
                        double x = -1;
                        double y = j;
                        for (int k = 0; k < 3; k++)
                            for (int l = 0; l < 3; l++)
                            {
                                if (j == 0)
                                    mx3[k, l] = mx[k + 1, l + 1];
                                else if (l < j)
                                    mx3[k, l] = mx[k + 1, l];
                                else
                                    mx3[k, l] = mx[k + 1, l + 1];
                            }
                        summ += mx[0, j] * Math.Pow(x, y) * get_det3(mx3);
                    }
                    return summ;
                // Остальные case остаются без изменений
                default:
                    double[,] mxX = new double[n - 1, n - 1];
                    for (int j = 0; j < n; j++)
                    {
                        double x = -1;
                        double y = j;
                        for (int k = 0; k < n - 1; k++)
                            for (int l = 0; l < n - 1; l++)
                            {
                                if (j == 0)
                                    mxX[k, l] = mx[k + 1, l + 1];
                                else if (l < j)
                                    mxX[k, l] = mx[k + 1, l];
                                else
                                    mxX[k, l] = mx[k + 1, l + 1];
                            }
                        summ += mx[0, j] * Math.Pow(x, y) * get_det(mxX, n - 1);
                    }
                    return summ;
            }
        }

        private double get_det3(double[,] mx) => 
            mx[0, 0] * (mx[1, 1] * mx[2, 2] - mx[1, 2] * mx[2, 1]) - 
            mx[0, 1] * (mx[1, 0] * mx[2, 2] - mx[1, 2] * mx[2, 0]) + 
            mx[0, 2] * (mx[1, 0] * mx[2, 1] - mx[1, 1] * mx[2, 0]);

        public override string ToString()
        {
            string str = "  Матрица A (a<ij>)\n";
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    str += $"{mxA[i, j],5:F1} ";
                str += $"    b{i + 1,-2}={mxB[i],5:F1} \n";
            }
            str += "\nРешение системы линейных уравнений\n";
            for (int j = 0; j < size; j++)
                str += $"x{j + 1}={solving[j]:F1} ";
            str += "\n";
            return str;
        }
    }
}