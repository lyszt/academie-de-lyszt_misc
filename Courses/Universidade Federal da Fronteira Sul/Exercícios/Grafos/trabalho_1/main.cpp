#include "src/circulo/circulo.h"
#include <iostream>
#include <stack>

int main() {

    // 2 
    double raio = 3.0;
    Circulo circulo = Circulo(raio);
    std::cout << "PERIMETRO:" << std::endl;
    circulo.imprime_perimetro();
    std::cout << "AREA:" << std::endl;
    circulo.imprime_area();
    
    // 3 

    std::stack<int> pilha;
    std::cout << std::endl << "PILHA:" << std::endl;
    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    while(!pilha.empty()) {
        std::cout << pilha.top() << std::endl;
        pilha.pop();
    }
}