#include "Graph.h"
#include "../Exceptions/Exception.h"
#include <exception>
#include <string>
#include <iostream>

Graph::Graph(int num_vertices) {
    if (num_vertices <= 0) {
        throw Exception("Error in constructor Graph(int): the number of "
            "vertices " + std::to_string(num_vertices) + " is invalid!");
    }

    num_vertices_ = num_vertices;
    num_edges_ = 0;

    adj_matrix_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix_[i].resize(num_vertices, 0);
    }
}

int Graph::num_vertices() {
    return num_vertices_;
}

int Graph::num_edges() {
    return num_edges_;
}

bool Graph::has_edge(Edge e) {
    if (adj_matrix_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Graph::insert_edge(Edge e) {
    try {
        validate_edge(e);
    } catch (...) {
        throw Exception("Error in operation "
            "insere_aresta(Edge): the edge " + e.to_string() + " is "
            "invalid!", std::current_exception());
    }

    if (!has_edge(e) && (e.v1 != e.v2)) {
        adj_matrix_[e.v1][e.v2] = 1;
        adj_matrix_[e.v2][e.v1] = 1;

        num_edges_++;
    }
}

void Graph::remove_edge(Edge e) {
    try {
        validate_edge(e);
    } catch (...) {
        throw Exception("Error in operation "
            "remove_aresta(Edge): the edge " + e.to_string() + " is "
            "invalid!", std::current_exception());
    }

    if (has_edge(e)) {
        adj_matrix_[e.v1][e.v2] = 0;
        adj_matrix_[e.v2][e.v1] = 0;

        num_edges_--;
    }
}

void Graph::print() {
    for (int v = 0; v < num_vertices_; v++) {
        std::cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (adj_matrix_[v][u] != 0) {
                std::cout << " " << u;
            }
        }
        std::cout << "\n";
    }
}

void Graph::validate_vertex(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw Exception("Invalid vertex index: " + std::to_string(v));
    }
}

void Graph::validate_edge(Edge e) {
    validate_vertex(e.v1);
    validate_vertex(e.v2);
}

bool Graph::is_walk(std::vector<int> &vertex_sequence) {
    if (vertex_sequence.size() == 0) {
        throw Exception("Error in operation eh_passeio(vector<int> &): the"
            " vertex sequence is empty");
    }

    for (int i = 1; i < ((int) vertex_sequence.size()); i++) {
        if (adj_matrix_[vertex_sequence[i - 1]][vertex_sequence[i]] == 0) {
            return false;
        }
    }

    return true;
}

bool Graph::is_path(std::vector<int> &vertex_sequence) {
    if (vertex_sequence.size() == 0) {
        throw Exception("Error in operation eh_caminho(vector<int> &): the"
            " vertex sequence is empty");
    }

    std::vector<int> visited(num_vertices_);

    visited[vertex_sequence[0]] = 1;
    for (int i = 1; i < ((int) vertex_sequence.size()); i++) {
        if ((visited[vertex_sequence[i]] != 0) ||
                (adj_matrix_[vertex_sequence[i - 1]][vertex_sequence[i]] == 0)) {
            return false;
        }

        visited[vertex_sequence[i]] = 1;
    }

    return true;
}
