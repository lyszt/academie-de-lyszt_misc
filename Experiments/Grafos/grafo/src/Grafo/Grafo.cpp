#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (tem_aresta(e)) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime() {
    // Grafo:
    // 0:
    // 1: 3
    // 2:
    // 3: 1
    // ...
    // 5:

    cout << "Grafo:\n";
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

vector<int> Grafo::busca_largura(int origem) {
    // TODO: implemente a busca em largura (BFS) aqui.
    //
    // Dicas:
    // - Voce vai precisar marcar quais vertices ja foram visitados (ex:
    //   std::vector<bool> visitados(num_vertices_, false)).
    // - Precisa de uma estrutura auxiliar com disciplina "primeiro a
    //   entrar, primeiro a sair" para decidir a ordem de visita.
    // - Para descobrir os vizinhos de um vertice v, use matriz_adj_[v][u],
    //   igual ao que o imprime() ja faz.
    // - O retorno deve ser a ordem em que os vertices foram visitados.

    throw runtime_error("Grafo::busca_largura: ainda nao implementado");
}

vector<int> Grafo::busca_profundidade(int origem) {
    // TODO: implemente a busca em profundidade (DFS) aqui.
    //
    // Dicas:
    // - Mesma ideia da BFS (visitados[] + vizinhos via matriz_adj_), mas
    //   com uma estrutura auxiliar de disciplina "ultimo a entrar, primeiro
    //   a sair" -- ou resolva com recursao, que usa a pilha de chamadas do
    //   proprio programa para isso.

    throw runtime_error("Grafo::busca_profundidade: ainda nao implementado");
}
