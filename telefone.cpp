#include <iostream>
#include <string>
#include <vector>
#include <list>

class Fone
{
public:
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
        return " Id:" + id + " | Numero:" + numero;
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
            saida += "[" + std::to_string(i) + ": |" + fone.toString() + "] ";
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

void show_help() {
    std::cout << "Comandos:" << std::endl;
    std::cout << "  help" << std::endl;
    std::cout << "  init <qtd>" << std::endl;
    std::cout << "  add <id> <numero>" << std::endl;
    std::cout << "  rm <id>" << std::endl;
    std::cout << "  show" << std::endl;
    std::cout << "  end" << std::endl;
}

int main()
{
    std::vector<Contato> contatos;
    std::string cmd;
    while (std::cin >> cmd)
    {
        if (cmd == "help")
        {
            show_help();
        }
        else if (cmd == "init")
        {
            std::string nome;
            std::cin >> nome;
            Contato contato(nome, std::list<Fone>());
            contatos.push_back(contato);
        }
        else if (cmd == "add")
        {
            std::string id;
            std::string numero;
            std::cin >> id >> numero;
            contatos[0].addFone(Fone(numero, id));
        }
        else if (cmd == "rm")
        {
            std::string id;
            std::cin >> id;
            contatos[0].removeFone(id);
        }
        else if (cmd == "show")
        {
            for (auto contato : contatos)
            {
                std::cout << contato.toString() << std::endl;
            }
        }
        else if (cmd == "end")
        {
            return 0;
        }
        else
        {
            std::cout << "Comando invalido" << std::endl;
        }
    }
    return 0;
}