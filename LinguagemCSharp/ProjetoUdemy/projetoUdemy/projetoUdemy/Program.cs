using System;

namespace MyNamespace
{
    internal class Program
    {
        static float soma(float num1, float num2)
        {
            return num1 + num2;
        }
        
        static void Main(string[] args)
        {
            int[,] arrayBraba = { {1, 2}, {3, 4}};
            foreach (int i in arrayBraba)
            {
                Console.WriteLine($"bagulho atual: {i}");
            }
            Console.WriteLine(soma(5, 10));
        }
    }
}

