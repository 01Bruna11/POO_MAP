#include <iostream>
#include <memory>
#include <vector>

class Cliente
{
private:
    std::string id;
    std::string fone;
public:
    Cliente(std::string id, std::string fone);
    std::string getId();
    void setId(std::string id);
    std::string getFone();
    void setFone(std::string fone);
};

class Sala
{
private:
    std::vector<std::shared_ptr<Cliente>> cadeiras;
    bool validar_index(int index) {
        if (index < 0 || index >= (int) this->cadeiras.size()) {
            std::cout << "Index invalido" << std::endl;
            return false;
        }
        return true;
    }
public:
    int capacidade;
    Sala(int lugares): cadeiras(lugares, nullptr) {}

    //qtd de lugares disponiveis inicialmente
    int getLugaresDisponiveis() {
        int lugares_disponiveis = 0;
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if (this->cadeiras[i] == nullptr) {
                lugares_disponiveis++;
            }
        }
        return lugares_disponiveis;
    }

    //reservar e mostra nome e id do cliente
    void reservar(std::string id, std::string fone) {
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if (this->cadeiras[i] == nullptr) {
                this->cadeiras[i] = std::make_shared<Cliente>(id, fone);
                std::cout << "Cliente " << id << " reservado na cadeira " << i << std::endl;
                return;
            }
        }
        std::cout << "Nao ha lugares disponiveis" << std::endl;
    }

    //duas pessoas não podem estar na mesma cadeira
    bool desreservar(int index) {
        if (!this->validar_index(index)) {
            return false;
        }
        if (this->cadeiras[index] == nullptr) {
            std::cout << "Cadeira nao ocupada" << std::endl;
            return false;
        }
        this->cadeiras[index] = nullptr;
        return true;
    }

    void cancelar(std::string id) {
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if (this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == id) {
                this->cadeiras[i] = nullptr;
                return;
            }
        }
    }

    //procurar por cliente pelo id 
    void procurar(std::string id) {
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if (this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == id) {
                std::cout << "Cliente ja esta no cinema" << std::endl;
                return;
            }
        }
        std::cout << "Cliente nao esta no cinema" << std::endl;
    }
    

    std::string toString() {
        std::string str = "";
        for (int i = 0; i < (int) this->cadeiras.size(); i++) {
            if (this->cadeiras[i] != nullptr) {
                str += this->cadeiras[i]->getId() + " ";
            } else {
                str += "* ";
            }
        }
        return str;
    }

    friend std::ostream& operator<<(std::ostream& os, Sala& s) {
        os << s.toString();
        return os;
    }
};

class Fluxo
{
private:
    std::vector<std::shared_ptr<Cliente>> clientes;
public:
    Fluxo(std::vector<std::shared_ptr<Cliente>> clientes)
    {
        this->clientes = clientes;
    }

    //controle de entrada e saida de cientes na sala
    void entrar(std::string id, std::string fone) {
        this->clientes.push_back(std::make_shared<Cliente>(id, fone));
    }

    void sair(std::string id) {
        for (int i = 0; i < (int) this->clientes.size(); i++) {
            if (this->clientes[i]->getId() == id) {
                this->clientes.erase(this->clientes.begin() + i);
                return;
            }
        }
    }

    //mostra todos os clientes
    void mostrar() {
        for (int i = 0; i < (int) this->clientes.size(); i++) {
            std::cout << this->clientes[i]->getId() << " " << this->clientes[i]->getFone() << std::endl;
        }
    }

};

int main()
{
    Sala sala1(10);
    std::cout << sala1 << std::endl;
    sala1.reservar("123", "123");
    std::cout << sala1 << std::endl;
    sala1.reservar("456", "456");
    std::cout << sala1 << std::endl;
    sala1.reservar("789", "789");
    std::cout << sala1 << std::endl;
    sala1.cancelar("123");
    std::cout << sala1 << std::endl;
    sala1.procurar("123");
    std::cout << sala1 << std::endl;
    sala1.desreservar(0);
    std::cout << sala1 << std::endl;
    sala1.procurar("456");
    std::cout << sala1 << std::endl;

}