#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*********************************************************
 *                  MAP - MANIPULAÇÃO                    *
 *********************************************************/

//SOZINHOS ---> Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)

std::vector<int> sozinhos(const vector<int>& v) {
    std::vector<int> novo;
    
    for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
		   if(v[i] != v[j]) {
		       novo.push_back(v[i]);
		   return novo;
		   }
		}
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//MAIS_OCORRENCIAS ---> Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)

int mais_ocorrencias(const std::vector<int>& v) {
    std::vector<int> novo;
    int cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if(v[i] == v[j]) {
                cont++;
            }
        }
    }
    return cont;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//MAIS_RECORRENTES ---> Quais os níveis de stress mais recorrentes. (abs)

std::vector<int> mais_recorrentes(const std::vector<int>& v) {
    std::vector<int> novo;
    int cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if(v[i] == v[j]) {
                novo.push_back(v[i]);
            return novo;
            }
        }
    }
}
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

/*********************************************************
 *                     PROXIMIDADE                       *
 *********************************************************/

//BRIGA ---> Quando alguém super estressado(>50) está ao 
//lado de duas pessoas muito estressadas(>30) pode dar briga. 
//Quantas vezes essa situação acontece?

int briga(const std::vector<int>& v) {
    std::vector<int> novo;
    int cont = 0;
    int i = 0;
    
    for(i = 0; i < v.size(); i++) {
        if(v[i-1] > 30 && v[i] > 50 && v[i+1] > 30) {
            cont++;
        }
    }
    return cont;
}
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//APAZIGUADO ---> Se alguém hiper estressado(>80) estiver ao lado 
//de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. 
//Em que posições estão esses que serão apaziguados?

int apaziguado(const std::vector<int>& v) {
    std::vector<int> novo;
    int pos = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 80 && v[i+1] < 10 || v[i] > 80 && v[i-1] < 10) {
            pos = i;
        }
    }
    return pos;
}
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

/*********************************************************
 *                     SEQUÊNCIAS                        *
 *********************************************************/

//QUANTOS_TIME ---> Duas ou mais pessoas do mesmo sexo seguidas podem 
//formar um time. Quantos times existem na fila?

int quantos_times(const std::vector<int>& v) {
    std::vector<int> novo;
    int cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 0 && v.size()-1 > 0 || v[i] < 0 && v.size()-1 < 0) {
           cont++;
        }
    }
    return cont;
}
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//MAIOR_TIME ---> Qual o maior time que apareceu na fila?

char maior_time(const std::vector<int>& v) {
    std::vector<int> novo;
    int contM = 0, contH = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 0 && v.size()-1 > 0) {
           contM++;
        }
        if(v[i] < 0 && v.size()-1 < 0) {
            contH++;
        }
    }
    
    if(contM > contH) {
        std::cout << "Time Mulheres";
    } else {
        std::cout << "Time Homens";
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//SOZINHOS ---> Quantas pessoas não estavam em um time?

int sozinhos2(const std::vector<int>& v) {
    std::vector<int> novo;
    int cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > 0 && v[i-1] > 0 || v[i] < 0 && v[i-1] < 0) {
           cont++;
        }
    }
    return cont;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

/*********************************************************
 *                        GRUPOS                         *
 *********************************************************/

//CASAIS ---> Casais são formados quando quando um homem e uma mulher 
//com o mesmo nível de stress são formados. O 3 e o -3 formam um casal.
//Os participantes fossem orientados a sair da fila e procurar seu par. 
//Quantos casais poderiam ser formados?

int casais(const std::vector<int>& v) {
    std::vector<int> novo;
    int x = 0, cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {    
            if((v[i] > 0 == v[j] < 0) || (v[j] > 0 && v[i] < 0)) {
                cont++;   
            }
       }
    } 
        
    return cont/2;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//TRIOS ---> Pedimos pros participantes se organizassem em trios. Todos os 3 
//deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

int trios(const std::vector<int>& v) {
    std::vector<int> novo;
    int x = 0, cont = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == v[i+1] && v[i] == v[i-1]) {
            cont++;   
       }
    } 
        
    return cont;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

/*********************************************************
 *                      ALTERAÇÃO                        *
 *********************************************************/

//REMOVE ---> Dado a pessoa X, como fica a fila após remover X?

std::vector<int> remove(std::vector<int>& v) {
    std::vector<int> novo;
    int x = 0;
    std::cin >> x;
    
    for(int i = 0; i < v.size(); i++) {
        v.erase(v.begin() + 2);
    return v;
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//INSERT --->  Como fica a fila se eu inserir a pessoa X na posição Y.

std::vector<int> inserir(std::vector<int>& v) {
    
    for(int i = 0; i < v.size(); i++) {
        v.insert(v.begin() + 3, v[i+4]);
    return v;
    }
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

//DANCE ---> O coordenador disse: se você está do lado de alguém da com o mesmo 
//nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes 
//se formavam novos pares que também saíam. Quem ficou na fila?

std::vector<int> dance(std::vector<int>& v) {
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            if(v[i] == v[j]) {
                v.erase(v.begin() + i, v.begin() + j+1);
            return v;
            }
        }
    } 
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "{ ";
    for (auto i : v)
        os << i << " ";
    os << "}";
    return os;
}

int main () 
{

/*********************************************************
 *                  MAP - MANIPULAÇÃO                    *
 *********************************************************/

//SOZINHOS ---> Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)

std::vector<int> v = {4, 1, 3, -1, -3, -3}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << sozinhos(v) << "\n";

    std::cout << "\n";
    
//MAIS_OCORRENCIAS ---> Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)

    std::vector<int> v = {1, -5, 4, 5, -1, -5, -5}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << mais_ocorrencias(v) << "\n";

    std::cout << "\n";

//MAIS_RECORRENTES ---> Quais os níveis de stress mais recorrentes. (abs)

    std::vector<int> v = {1, 4, 5, -1, -5, -5, 3, -3}; // Tá voltando valor da posição 0
        for(int i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << mais_recorrentes(v) << "\n";

      std::cout << "\n";

/*********************************************************
 *                     PROXIMIDADE                       *
 *********************************************************/

//BRIGA ---> Quando alguém super estressado(>50) está ao 
//lado de duas pessoas muito estressadas(>30) pode dar briga. 
//Quantas vezes essa situação acontece?

std::vector<int> v = {33, 51, 37, 21, 36, 59, 42}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << briga(v) << "\n";

    std::cout << "\n";

//APAZIGUADO ---> Se alguém hiper estressado(>80) estiver ao lado 
//de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. 
//Em que posições estão esses que serão apaziguados?

std::vector<int> v = {8, 82, 37, 21, 36}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << apaziguado(v) << "\n";

    std::cout << "\n";

/*********************************************************
 *                     SEQUÊNCIAS                        *
 *********************************************************/

//QUANTOS_TIME ---> Duas ou mais pessoas do mesmo sexo seguidas podem 
//formar um time. Quantos times existem na fila?

std::vector<int> v = {5, 7, -6, -3}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << quantos_times(v) << "\n";


//MAIOR_TIME ---> Qual o maior time que apareceu na fila?

std::vector<int> v = {5, 7, 9, -6, -3}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << maior_time(v) << "\n";
    
    std::cout << "\n";

//SOZINHOS ---> Quantas pessoas não estavam em um time?

std::vector<int> v = {7, 9, -6, -3}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << sozinhos2(v) << "\n";
    
    std::cout << "\n";

/*********************************************************
 *                        GRUPOS                         *
 *********************************************************/

//CASAIS ---> Casais são formados quando quando um homem e uma mulher 
//com o mesmo nível de stress são formados. O 3 e o -3 formam um casal.
//Os participantes fossem orientados a sair da fila e procurar seu par. 
//Quantos casais poderiam ser formados?

std::vector<int> v = {2, -2, 3, -3}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << casais(v) << "\n";
    
    std::cout << "\n";

//TRIOS ---> Pedimos pros participantes se organizassem em trios. Todos os 3 
//deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

std::vector<int> v = {2, 2, 2, 3, 3, 3, 4, 4, 4}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << trios(v) << "\n";
    
    std::cout << "\n";

/*********************************************************
 *                      ALTERAÇÃO                        *
 *********************************************************/

//REMOVE ---> Dado a pessoa X, como fica a fila após remover X?

 std::vector<int> v = {1, 2, 3, 4, 5}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << remove(v) << "\n";
    
    std::cout << "\n";

//INSERT --->  Como fica a fila se eu inserir a pessoa X na posição Y.

 std::vector<int> v = {1, 2, 3, 4, 5}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << inserir(v) << "\n";
    
    std::cout << "\n";

//DANCE ---> O coordenador disse: se você está do lado de alguém da com o mesmo 
//nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes 
//se formavam novos pares que também saíam. Quem ficou na fila?

 std::vector<int> v = {6, 1, 1, 3, 4, 5}; // Tá voltando valor da posição 0
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << dance(v) << "\n";
    
    std::cout << "\n";

return 0;

}