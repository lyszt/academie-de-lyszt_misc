#ifndef GRAFO_H

#define GRAFO_H

#include "../Aresta/Aresta.h"
#include <vector>

class Grafo {
public:
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     *  nao seja um laco */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    void imprime();

    /** Percorre o grafo a partir do vertice origem usando busca em largura
     *  (BFS), visitando todos os vertices alcancaveis a partir dele.
     *  Retorna a sequencia de vertices na ordem em que foram visitados. */
    std::vector<int> busca_largura(int origem);

    /** Percorre o grafo a partir do vertice origem usando busca em
     *  profundidade (DFS), visitando todos os vertices alcancaveis a partir
     *  dele. Retorna a sequencia de vertices na ordem em que foram
     *  visitados. */
    std::vector<int> busca_profundidade(int origem);

    // bool eh_passeio(int seq_verts[], int tam_seq_verts);
    // ou
    // bool eh_passeio(std::vector<int> &seq_verts);
    
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
};

#endif /* GRAFO_H */
