#include <iostream>
#include <vector>
#include <string>
#include <memory>

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
    std::vector<std::shared_ptr<Pessoa>> cadeiras;
public:

    Sala(int lotacao): cadeiras(lotacao, nullptr) {
    }

    bool reservar(std::shared_ptr<Pessoa> pessoa) {
        for (int i = 0; i < cadeiras.size(); i++) {
            if (cadeiras[i] == nullptr) {
                cadeiras[i] = pessoa;
                return true;
            }
        }
        return false;
    }

    void cancelar(std::shared_ptr<Pessoa> pessoa) {
        for (int i = 0; i < cadeiras.size(); i++) {
            if (cadeiras[i] == pessoa) {
                cadeiras[i] = nullptr;
                return;
            }
        }
    }

    int procurarPessoa(std::string id) {
        for (int i = 0; i < (int) cadeiras.size(); i++)
            if (cadeiras[i] != nullptr && cadeiras[i]->id == id)
                return i;
        return -1;
    }

    void adicionarPessoa(std::shared_ptr<Pessoa> pessoa, int indice) {
        if (indice < 0 || indice >= (int) cadeiras.size()) {
            std::cout << "Indice invalido" << std::endl;
            return;
        }
        if (cadeiras[indice] != nullptr) {
            std::cout << "Cadeira ocupada" << std::endl;
            return;
        }
        if(this->procurarPessoa(pessoa->id) != -1) {
            std::cout << "Pessoa ja esta no Sala" << std::endl;
            return;
        }
        cadeiras[indice] = pessoa;
    }

    std::shared_ptr<Pessoa> removerPessoa(std::string id) {
        int indice = procurarPessoa(id);
        if (indice == -1) {
            std::cout << "Pessoa nao encontrada" << std::endl;
            return nullptr;
        }
        return std::exchange(cadeiras[indice], nullptr);
    }

    //trocar duas pessoas de lugares
    void trocarPessoas(std::string id1, std::string id2) {
        int indice1 = procurarPessoa(id1);
        int indice2 = procurarPessoa(id2);
        if (indice1 == -1 || indice2 == -1) {
            std::cout << "Pessoa nao encontrada" << std::endl;
            return;
        }
        std::shared_ptr<Pessoa> pessoa1 = cadeiras[indice1];
        std::shared_ptr<Pessoa> pessoa2 = cadeiras[indice2];
        cadeiras[indice1] = pessoa2;
        cadeiras[indice2] = pessoa1;
    }


    friend std::ostream& operator<<(std::ostream& os, const Sala& c) {
        os << "[ ";
        for (auto cadeira : c.cadeiras) {
            if (cadeira == nullptr)
                os << "- ";
            else
                os << *cadeira << " ";
        }
        os << "]";
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
    Sala sala(5);
    std::string cmd;
    while (std::cin >> cmd) {
        if (cmd == "help") {
            show_help();
        } else if (cmd == "init") {
            int qtd;
            std::cin >> qtd;
            sala = Sala(qtd);
        } else if (cmd == "add") {
            std::string id;
            int fone;
            int indice;
            std::cin >> id >> fone >> indice;
            sala.adicionarPessoa(std::make_shared<Pessoa>(id, fone), indice);
        } else if (cmd == "rm") {
            std::string id;
            std::cin >> id;
            sala.removerPessoa(id);
        } else if (cmd == "show") {
            std::cout << sala << std::endl;
        } else if (cmd == "trocar") {
            std::string id1, id2;
            std::cin >> id1 >> id2;
            sala.trocarPessoas(id1, id2);
        } else if (cmd == "cancel") {
            std::string id;
            std::cin >> id;
            sala.cancelar(sala.removerPessoa(id));
        } else if (cmd == "end") {
            break;
        } else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
    
}