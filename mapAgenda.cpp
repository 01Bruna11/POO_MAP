#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

class Fone
{
private:
    std::string nome;
    std::string id;
    std::string numero;
    
public:
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
    std::map<std::string, Contato> contatos;
    //retornar a posicao do contato com esse nome no vetor ou -1 se nao existir
    int findPosByName(std::string nome)
    {
        int i = 0;
        for (auto contato : contatos)
        {
            if (contato.second.getNome() == nome)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

public:
    Agenda() {}

    Contato getContato(std::string nome)
    {
        int pos = findPosByName(nome);
        if (pos == -1)
        {
            return Contato("", std::list<Fone>());
        }
        return contatos[nome];
    }

    void ordenar()
    {
        std::sort(contatos.begin(), contatos.end(), [](auto a, auto b) { return a.second.getNome() < b.second.getNome(); });
    }

    void addContato(std::string nome, std::list<Fone> fones)
    {
        int pos = findPosByName(nome);
        if (pos == -1)
        {
            Contato contato(nome, fones);
            contatos.insert(std::pair<std::string, Contato>(nome, contato));
            ordenar();
        }
        else
        {
            for (auto fone : fones)
            {
                contatos[nome].addFone(fone);
            }
        }
    }

    void removeContato(std::string nome)
    {
        int pos = findPosByName(nome);
        if (pos != -1)
        {
            contatos.erase(contatos.begin());
        }
    }
    
    std::list<Contato> procurar(std::string procurado)
    {
        std::list<Contato> aux;
        for (auto contato : contatos)
        {
            if (contato.second.toString().find(procurado) != std::string::npos)
            {
                aux.push_back(contato.second);
            }
        }
        return aux;
    }

    std::list<Contato> getContatos()
    {
        std::list<Contato> aux;
        for (auto contato : contatos)
        {
            aux.push_back(contato.second);
        }
        return aux;
    }

    std::string toString()
    {
        std::string saida = "";
        for (auto contato : contatos)
        {
            saida += contato.second.toString() + "\n";
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
    std::map<std::string, std::string> contato;
    std::string nome;
    std::string id;
    std::string numero;
    std::string entrada;
    std::string procurado;
    std::list<Contato> contatos;
    Agenda agenda;
    std::string comandos;
    while (std::cin >> comandos)
    {
        if (comandos == "help")
        {
            show_help();
        }
        else if (comandos == "add")
        {
            std::cin >> nome;
            std::cin >> id;
            std::cin >> numero;
            Fone fone(id, numero);
            agenda.addContato(nome, std::list<Fone>{fone});
        }
        else if (comandos == "rm")
        {
            std::cin >> id;
            agenda.removeContato(id);
        }
        else if (comandos == "search")
        {
            std::cin >> procurado;
            contatos = agenda.procurar(procurado);
            for (auto contato : contatos)
            {
                std::cout << contato.toString() << std::endl;
            }
        }
        else if (comandos == "show")
        {
            contatos = agenda.getContatos();
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