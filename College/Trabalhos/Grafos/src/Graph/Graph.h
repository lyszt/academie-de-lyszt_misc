#ifndef GRAPH_H

#define GRAPH_H

#include "../Edge/Edge.h"
#include <vector>

class Graph {
public:
    /** Builds a simple graph with the given number of vertices and no
     *  edges */
    Graph(int num_vertices);

    int num_vertices();
    int num_edges();

    bool has_edge(Edge e);

    /** Inserts an edge into the graph if it does not exist yet and is not
     *  a loop */
    void insert_edge(Edge e);

    /** Removes an edge from the graph if it exists */
    void remove_edge(Edge e);

    void print();

    bool is_walk(std::vector<int> &vertex_sequence);
    bool is_path(std::vector<int> &vertex_sequence);

private:
    int num_vertices_;
    int num_edges_;
    std::vector<std::vector<int>> adj_matrix_;

    void validate_vertex(int v);
    void validate_edge(Edge e);
};

#endif /* GRAPH_H */
