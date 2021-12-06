#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <list>

class Pessoa {
public:
    std::string id;
    int fone;

    Pessoa(std::string id, int fone) : id(id), fone(fone) {}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
        os << p.id << ":" << p.fone;
        return os;
    }

    std::string getId() {
        return id;
    }
    void setId(std::string id) {
        this->id = id;
    }
    int getFone() {
        return fone;
    }
    void setFone(int fone) {
        this->fone = fone;
    }
};

class Sala { 
private:
    std::map<std::string, std::shared_ptr<Pessoa>> cadeiras;
public:

    std::list<std::shared_ptr<Pessoa>> getPessoas() {
        std::list<std::shared_ptr<Pessoa>> pessoas;
        for (auto& p : cadeiras) {
            pessoas.push_back(p.second);
        }
        return pessoas;
    }

    bool reservarPessoa(std::shared_ptr<Pessoa> pessoa) {
        if (cadeiras.find(pessoa->getId()) == cadeiras.end()) {
            cadeiras[pessoa->getId()] = pessoa;
            return true;
        }
        return false;
    }

    void cancelar(std::shared_ptr<Pessoa> pessoa) {
        if (cadeiras.find(pessoa->getId()) != cadeiras.end()) {
            cadeiras.erase(pessoa->getId());
        }
    }

    std::shared_ptr<Pessoa> procurarPessoa(std::string id) {
        if (cadeiras.find(id) != cadeiras.end()) {
            return cadeiras[id];
        }
        return nullptr;
    }

    int adicionarPessoa(std::shared_ptr<Pessoa> pessoa, int indice) {
        if (cadeiras.find(pessoa->getId()) == cadeiras.end()) {
            cadeiras[pessoa->getId()] = pessoa;
            return indice;
        }
        return -1;
    }
    
    void trocarPessoas(std::shared_ptr<Pessoa> pessoa1, std::shared_ptr<Pessoa> pessoa2) {
        if (cadeiras.find(pessoa1->getId()) != cadeiras.end() && cadeiras.find(pessoa2->getId()) != cadeiras.end()) {
            std::shared_ptr<Pessoa> pessoa = cadeiras[pessoa1->getId()];
            cadeiras[pessoa1->getId()] = cadeiras[pessoa2->getId()];
            cadeiras[pessoa2->getId()] = pessoa;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Sala& s) {
        os << "Sala: " << std::endl;
        for (auto& p : s.cadeiras) {
            os << p.second << std::endl;
        }
        return os;
    }


};

void show_help() {
    std::cout << "Comandos:" << std::endl;
    std::cout << "  help" << std::endl;
    std::cout << "  init <qtd>" << std::endl;
    std::cout << "  add <id> <fone> <indice>" << std::endl;
    std::cout << "  rm <id>" << std::endl;
    std::cout << "  show" << std::endl;
    std::cout << "  end" << std::endl;
    std::cout << "  trocar" << std::endl;
}

int main(){
    Sala sala;
    std::string cmd;
    std::string id;
    int fone;
    int indice;
    std::shared_ptr<Pessoa> pessoa;
    while (true) {
        std::cin >> cmd;
        if (cmd == "help") {
            show_help();
        } else if (cmd == "init") {
            int qtd;
            std::cin >> qtd;
        } else if (cmd == "add") {
            std::cin >> id >> fone >> indice;
            sala.adicionarPessoa(std::make_shared<Pessoa>(id, fone), indice);
        } else if (cmd == "rm") {
            std::cin >> id;
            sala.cancelar(sala.procurarPessoa(id));
        } else if (cmd == "show") {
            std::cout << sala << std::endl;
        } else if (cmd == "end") {
            break;
        } else if (cmd == "trocar") {
            std::cin >> id >> id;
            sala.trocarPessoas(sala.procurarPessoa(id), sala.procurarPessoa(id));
        } else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
    return 0;
}