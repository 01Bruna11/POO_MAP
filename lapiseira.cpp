#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre {0.0};
    std::string dureza {"HB"};
    int tamanho { 0 };

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) :
        calibre{calibre}, dureza{dureza}, tamanho{tamanho} {
    }
};

std::ostream& operator<<(std::ostream& os, const Grafite& grafite) {
    os << "Calibre: " << grafite.calibre << " mm, \n";
    os << "Dureza: " << grafite.dureza << ", \n";
    os << "Tamanho: " << grafite.tamanho << " mm\n";
    return os;
}

struct Lapiseira {
    float calibre;
    Grafite* grafite;
    bool temGrafite;
    Lapiseira(float calibre, Grafite* grafite = nullptr) : 
        calibre{calibre}, grafite{grafite} {
    }

    bool inserirGrafite(Grafite* grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Lapiseira já tem grafite\n";
            return false;
        }
        if(grafite->calibre != this->calibre) {
            std::cout << "Calibre incompativel\n";
            return false;
        }
        this->grafite = grafite;
        return true;
    }
    Grafite* removerGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Nao tem grafite\n";
            return nullptr;
        }
        return std::exchange(this->grafite, nullptr);
    }
    Grafite* quebraGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Nao tem grafite\n";
            return nullptr;
        }
        this->grafite->tamanho /= 2;
        return this->grafite;
    }
    bool grafiteEstaCompleto() {
        if(this->grafite == nullptr) {
            std::cout << "Cheio\n";
            return false;
        }
        return this->grafite->tamanho == this->calibre;
    }
};

int main(void) 
{
  
    Grafite grafite(10, "HC", 10);
    Lapiseira lapiseira(0.5, &grafite);
    lapiseira.grafite->tamanho -= 5;
    std::cout << grafite.tamanho << "\n";
    std::cout << lapiseira.grafite->tamanho << "\n";
    std::cout << lapiseira.grafiteEstaCompleto() << "\n";
    std::cout << lapiseira.quebraGrafite()->tamanho << "\n";

    return 0;

}