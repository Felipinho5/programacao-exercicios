using System;
using System.Collections.Generic;

class Binario
{
    static void Main()
    {
        int n, resto;
        Stack<int> pilha = new Stack<int>();
        
        Console.Write("Insira um número inteiro: ");
        n = Convert.ToInt32(Console.ReadLine());
        
        do
        {
            resto = n % 2;
            pilha.Push(resto);
            n = n / 2;
        } while (n != 0);
        
        Console.Write("Equivalente em binário: ");
        
        while(pilha.Count != 0)
            Console.Write(pilha.Pop());
    }
}
