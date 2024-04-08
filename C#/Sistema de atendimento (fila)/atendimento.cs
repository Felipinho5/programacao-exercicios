using System;
using System.Collections.Generic;

struct Cliente
{
    public int senha;
    public bool prioritario;
    
    public Cliente(int senha, bool prioritario)
    {
        this.senha = senha;
        this.prioritario = prioritario;
    }
}

class Atendimento
{
    static void Main()
    {
        int escolha = 0;
        int senha = 0;
        Queue<Cliente> fila = new Queue<Cliente>();
        
        exibirOpcoes();
        
        while(escolha != 7)
        {
            escolha = escolherOpcao();
            
            switch(escolha)
            {
                case 1:
                    Cliente novoCliente = new Cliente(senha, false);
                    fila.Enqueue(novoCliente);
                    senha++;
                    Console.WriteLine("Cliente adicionado à fila.");
                    break;
                    
                case 2:
                    if(fila.Count > 0)
                    {
                        fila.Dequeue();
                        Console.WriteLine("Cliente atendido.");
                    }
                    else
                        Console.WriteLine("Não há clientes.");
                        
                    break;
                
                case 3:
                    Cliente novoClientePrioritario = new Cliente(senha, true);
                    fila.Enqueue(novoClientePrioritario);
                    senha++;
                    Console.WriteLine("Cliente prioritário adicionado à fila.");
                    break;
                
                case 4:
                    fila = atendimentoPrioritario(fila);
                    break;
                
                case 5:
                    int i = 1;
                    
                    foreach(Cliente cliente in fila)
                    {
                        string prioridade = cliente.prioritario == true ? "Sim" : "Não";
                        Console.WriteLine($"{i}) Senha: {cliente.senha} - Prioridade: {prioridade}");
                        i++;
                    }
                        
                    if(fila.Count == 0)
                        Console.WriteLine("Fila vazia.");
                        
                    break;
                    
                case 6:
                    fila.Clear();
                    Console.WriteLine("Fila limpa.");
                    break;
                
                case 7:
                    Console.WriteLine("Saindo.");
                    break;
                    
                default:
                    Console.WriteLine("Escolha inválida.");
                    break;
            }
        }
    }
    
    static Queue<Cliente> atendimentoPrioritario(Queue<Cliente> fila)
    {
        Queue<Cliente> novaFila = new Queue<Cliente>();
        bool encontrou = false;
        
        foreach(Cliente cliente in fila)
        {
            if(cliente.prioritario && !encontrou)
            {
                encontrou = true;
                continue;
            }
            
            novaFila.Enqueue(cliente);
        }
        
        if(encontrou)
            Console.WriteLine("Cliente prioritário atendido.");
        else
            Console.WriteLine("Não há clientes prioritários.");
            
        return novaFila;
    }
    
    static void exibirOpcoes()
    {
        string[] opcoes =
        {
            "Gerar nova senha",
            "Efetuar atendimento",
            "Gerar atendimento prioritário",
            "Efetuar atendimento prioritário",
            "Exibir a fila atual",
            "Limpar a fila",
            "Sair"
        };
        
        int i = 1;
        
        Console.WriteLine("---------- OPÇÕES ----------");
        
        foreach(string opcao in opcoes)
        {
            Console.WriteLine($"{i} - {opcao}");
            i++;
        }
    }
    
    static int escolherOpcao()
    {
        Console.Write("\nEscolha uma opção: ");
        int escolha = Convert.ToInt16(Console.ReadLine());
        return escolha;
    }
}