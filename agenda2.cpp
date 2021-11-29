#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

class Fone
{
public:
    std::string nome;
    std::string id;
    std::string numero;

    Fone(std::string numero, std::string id) : numero(numero), id(id) {}

    static bool validarNumero(std::string numero)
    {
        return numero.size() == 4;
    }
    std::string getId()
    {
        return id;
    }
    void setId(std::string id)
    {
        this->id = id;
    }
    std::string getNumero()
    {
        return numero;
    }
    void setNumero(std::string numero)
    {
        this->numero = numero;
    }
    std::string toString()
    {
        return " " + nome + " " + id + "  " + numero;
    }
};

class Contato
{
private:
    std::string nome;
    std::list<Fone> fones;

protected:
    std::string prefix = "-";

public:
    Contato(std::string nome, std::list<Fone> fones) : nome(nome), fones(fones) {}

    void addFone(Fone fone)
    {
        if (Fone::validarNumero(fone.getNumero()))
        {
            fones.push_back(fone);
        }
        else
        {
            std::cout << "Numero invalido" << std::endl;
        }
    }
    void removeFone(std::string id)
    {
        for (auto it = fones.begin(); it != fones.end(); it++)
        {
            if (it->getId() == id)
            {
                fones.erase(it);
                return;
            }
        }
        std::cout << "Fone nao encontrado" << std::endl;
    }

    std::string toString()
    {
        std::string saida = prefix + nome + " ";
        int i = 0;
        for (auto fone : fones)
        {
            saida += "[" + std::to_string(i) + " :" + fone.toString() + "] ";
            i++;
        }
        return saida;
    }
    void listarFones()
    {
        int i = 0;
        for (auto fone : fones)
        {
            std::cout << i << " " << fone.toString() << std::endl;
            i++;
        }
    }
    std::string getNome()
    {
        return nome;
    }
    void setNome(std::string nome)
    {
        this->nome = nome;
    }
    std::list<Fone> getFones()
    {
        return fones;
    }
};

class Agenda
{
private:
    std::vector<Contato> contatos;
    int encontrarPosicaoContato(std::string nome)
    {
        for (int i = 0; i < contatos.size(); i++)
        {
            if (contatos[i].getNome() == nome)
            {
                return i;
            }
        }
        return -1;
    }

public:
    Agenda() {}

    //retorna o objeto contato com esse nome ou null se não existir
    //utilize o método findPos
    Contato getContato(std::string nome)
    {
        int pos = encontrarPosicaoContato(nome);
        if (pos == -1)
        {
            return Contato("", std::list<Fone>());
        }
        return contatos[pos];
    }

    void ordenar()
    {
        std::sort(contatos.begin(), contatos.end(), [](Contato a, Contato b)
                  { return a.getNome() < b.getNome(); });
    }

    void addContato(std::string nome, std::list<Fone> fones)
    {
        int pos = encontrarPosicaoContato(nome);
        if (pos == -1)
        {
            Contato contato(nome, fones);
            contatos.push_back(contato);
        }
        else
        {
            for (auto fone : fones)
            {
                contatos[pos].addFone(fone);
            }
        }
        ordenar();
    }
    //Utilize o método findPos
    void removeContato(std::string nome)
    {
        int pos = encontrarPosicaoContato(nome);
        if (pos != -1)
        {
            contatos.erase(contatos.begin() + pos);
        }
        else
        {
            std::cout << "Contato nao encontrado" << std::endl;
        }
    }

    std::vector<Contato> search(std::string procurado)
    {
        std::vector<Contato> resultado;
        for (auto contato : contatos)
        {
            if (contato.getNome().find(procurado) != std::string::npos)
            {
                resultado.push_back(contato);
            }
        }
        return resultado;
    }

    void listarContatos()
    {
        for (auto contato : contatos)
        {
            std::cout << contato.toString() << std::endl;
        }
    }

    std::vector<Contato> getContatos()
    {
        return contatos;
    }

    std::string toString()
    {
        std::string saida = "";
        for (auto contato : contatos)
        {
            saida += contato.toString() + "\n";
        }
        return saida;
    }
};

void show_help()
{
    std::cout << "Comandos:" << std::endl;
    std::cout << "  help" << std::endl;
    std::cout << "  add <nome> <id> <numero>" << std::endl;
    std::cout << "  rm <id>" << std::endl;
    std::cout << " search" << std::endl;
    std::cout << "  show" << std::endl;
    std::cout << "  end" << std::endl;
}

int main()
{
    //cria um contato a partir do vetor de entrada tal como
    //add joao oi:123 tim:432 claro:09123
    std::vector<Contato> contatos;
    std::string comandos;
    while (std::cin >> comandos)
    {
        if (comandos == "help")
        {
            show_help();
        }
        else if (comandos == "add")
        {
            std::string nome;
            std::cin >> nome;
            std::string id;
            std::cin >> id;
            std::string numero;
            std::cin >> numero;
            std::list<Fone> fones;
            fones.push_back(Fone(id, numero));
            contatos.push_back(Contato(nome, fones));
        }
        else if (comandos == "rm")
        {
            std::string id;
            std::cin >> id;
            for (auto contato : contatos)
            {
                contato.removeFone(id);
            }
        }
        else if (comandos == "search")
        {
            std::string procurado;
            std::cin >> procurado;
            std::vector<Contato> resultado;
            for (auto contato : resultado)
            {
                std::cout << contato.toString() << std::endl;
            }
        }
        else if (comandos == "show")
        {
            for (auto contato : contatos)
            {
                std::cout << contato.toString() << std::endl;
            }
        }
        else if (comandos == "end")
        {
            break;
        }
        else
        {
            std::cout << "Comando invalido" << std::endl;
        }
    }
}