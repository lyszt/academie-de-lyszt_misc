#include "circulo.h"
#include <iostream>

const float PI = 3.141;

Circulo::Circulo(double raio) {
    this->raio_ = raio;
}

double Circulo::calcula_area() {
    return PI * (this->raio_ * this->raio_);  
}

void Circulo::imprime_area() {
    std::cout << calcula_area() << std::endl;
}


// Adicione métodos que calculam o perimetro
double Circulo::calcula_perimetro() {
    return 2*PI*this->raio_;
}
void Circulo::imprime_perimetro() {
    std::cout << calcula_perimetro() << std::endl;
}