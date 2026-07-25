#include <stdio.h>
#include <math.h>
#define NUM_VERTICES 25


int* make_vertices(int n_vertices){
    int vertices = (int)(sqrt(n_vertices));
    int[vertices][vertices] matriz_adj;
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            matriz_adj[i][j] = {i,j};
        }
    }
    return matriz_adj;
}

int main() {
    int* matriz_adj = make_vertices(NUM_VERTICES);
    return 0;
}