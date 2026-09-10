#include "Aresta/Aresta.h"
#include "Grafo/Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo g(6);

        Aresta e(1, 3);
        cout << "Tem aresta (1,3): " << g.tem_aresta(e) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:

        g.insere_aresta(Aresta(1, 3));

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1: 3
        // 2:
        // 3: 1
        // ...
        // 5:

        g.remove_aresta(Aresta(1, 3));
        g.remove_aresta(Aresta(2, 5));

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:
        cout << "\n";
        cout << "=== Busca em largura e profundidade ===\n";

        Grafo g2(6);
        g2.insere_aresta(Aresta(0, 1));
        g2.insere_aresta(Aresta(0, 2));
        g2.insere_aresta(Aresta(1, 3));
        g2.insere_aresta(Aresta(2, 4));
        g2.insere_aresta(Aresta(4, 5));
        g2.imprime();
        // Grafo:
        // 0: 1 2
        // 1: 0 3
        // 2: 0 4
        // 3: 1
        // 4: 2 5
        // 5: 4

        cout << "\n";
        cout << "BFS a partir de 0: ";
        for (int v : g2.busca_largura(0)) {
            cout << v << " ";
        }
        cout << "\n";

        cout << "DFS a partir de 0: ";
        for (int v : g2.busca_profundidade(0)) {
            cout << v << " ";
        }
        cout << "\n";
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
