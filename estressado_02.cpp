#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/*********************************************************
 *                       FILTER                          *
 *********************************************************/

//CLONAR  ---> Retornar um novo vetor copiando os valores

std::vector<int> clonar(std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int value : v)
        if(value != v.size())
            novo.push_back(value);
        return novo;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//PEGAR_HOMENS ---> Retorne uma lista com os homens (valores positivos)

std::vector<int> pegar_homens(std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int value : v)
        if(value > 0)
            novo.push_back(value);
        return novo;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//PEGAR_CALMOS ---> retorne uma lista com as pessoas com stress menor que 10 (positivos menor que 10) (abs)

std::vector<int> pegar_calmos(std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int value : v)
        if(value > 0 && value < 10)
            novo.push_back(value);
        return novo;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//PEGAR_MULHERES_CALMAS ---> Retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)

std::vector<int> pegar_mulheres_calmas(std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int value : v)
        if(value < 0 && value > -10)
            novo.push_back(value);
        return novo;
    
}

/*********************************************************
 *                        ACESSO                         *
 *********************************************************/

//INVERTER_COM_COPIA ---> retorna um novo vetor com os dados invertidos

std::vector<int> inverter_com_copia(const std::vector<int>& v) {
    std::vector<int> novo;
            
    for(int i = v.size() - 1; i >= 0; i--)
        novo.push_back(v[i]);
    return novo;
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//REVERTER_INPLACE ---> inverte os valores do vetor de entrada sem uso de vetor auxiliar

void inverter_inplace(std::vector<int>& v) {
            
    for(int i = v.size() - 1; i >= 0; i--)
        v[i] = v[i];
    
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//SORTEAR ---> Retorna aleatoriamente um elemento do vetor

int sortear(std::vector<int>& v) {
    int temp = 0;
    int r = 0;
    for (int i = 0; i < v.size(); i++) {
		int r = rand() % v.size();
		temp = v[i];
		v[i] = v[r];
		v[r] = temp;
	}
	return temp;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//EMBARALHAR ---> Embaralha o vetor original

void embaralhar(std::vector<int>& v) {
    int temp = 0;
    int r = 0;
    for (int i = 0; i < v.size(); i++) {
		int r = rand() % v.size();
		temp = v[i];
		v[i] = v[r];
		v[r] = temp;
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

//ORDENAR ---> Ordena o vetor original (selection sort utilizando)

void ordenar(std::vector<int>& v) {
    int aux = 0;
            
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
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

/*********************************************************
 *                      CONJUNTOS                        *
 *********************************************************/

//EXCLUSIVOS ---> O fiscal permitiu a entrada de um único representante de 
//cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. 
//Que conjunto foi formado?

std::vector<int> exclusivos(const std::vector<int>& v) {
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


//DIFERENTES --->  Qual a lista dos diferentes níveis de stress que aparecem?

std::vector<int> diferentes(const std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
		   if(v[i] == v[j]) {
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


//ABANDONADOS ---> quais pessoas ficaram na fila após remover um exemplar de cada valor?

std::vector<int> abandonados(const std::vector<int>& v) {
    std::vector<int> novo;
    
    for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
		   if(v[i] == v[j]) {
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


int main () 
{
/*********************************************************
 *                       FILTER                          *
 *********************************************************/

std::vector<int> v = {1, -2, 3, -4, 8, 9};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
   
    std::cout << "\n";
   
    std::cout << clonar(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {1, -2, 3, -4, 8, 9};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
   
    std::cout << "\n";
   
    std::cout << pegar_homens(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {1, -2, 3, -4, 8, 12};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
   
    std::cout << "\n";
   
    std::cout << pegar_homens(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {1, -2, 3, -4, -8, -12};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
   
    std::cout << "\n";
   
    std::cout << pegar_mulheres_calmas(v) << "\n";

std::cout << "\n\n";

/*********************************************************
 *                        ACESSO                         *
 *********************************************************/

std::vector<int> v = {1, 2, 3, 4, 5};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << inverter_com_copia(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {5, 4, 3, 2, 1};
        
    std::cout << "\n";
    inverter_inplace(v);
    std::cout << v << " ";

std::cout << "\n\n";

std::vector<int> v = {1, 2, 3, 4, 5};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << sortear(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {1, 2, 3, 4, 5};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    embaralhar(v);
    std::cout << v << " ";

std::cout << "\n\n";

std::vector<int> v = {1, 3, 5, 4, 2};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    ordenar(v);
    std::cout << v << " ";

std::cout << "\n\n";

/*********************************************************
 *                      CONJUNTOS                        *
 *********************************************************/

std::vector<int> v = {1, 2, 2, -5, -5};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << exclusivos(v) << "\n";

std::cout << "\n\n";

std::vector<int> v = {5, 2, 2, 3};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << diferentes(v) << "\n";

std::cout << "\n\n";
std::vector<int> v = {2, -5, -5};
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
        
    std::cout << "\n";
    
    std::cout << abandonados(v) << "\n";

return 0;

}
