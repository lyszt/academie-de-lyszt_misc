#ifndef GRAPH_H

#define GRAPH_H

#include "../Edge/Edge.h"
#include <vector>

class Graph {
public:
    Graph(int num_vertices);

    int num_vertices();
    int num_edges();

    bool has_edge(Edge e);
    void insert_edge(Edge e);
    void remove_edge(Edge e);

    void print();

    bool is_walk(std::vector<int> &vertex_sequence);
    bool is_path(std::vector<int> &vertex_sequence);

    std::vector<int> breadth_first_search(int origin);
    std::vector<int> ttl_breadth_first_search(int origin, int ttl);

private:
    int num_vertices_;
    int num_edges_;
    std::vector<std::vector<int>> adj_matrix_;

    void validate_vertex(int v);
    void validate_edge(Edge e);
};

#endif 
