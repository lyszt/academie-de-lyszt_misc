#ifndef ARESTA_H

#define ARESTA_H

#include <string>

class Edge {
public:
    const int v1;
    const int v2;

    Edge(int v1, int v2);

    std::string to_string();
};

#endif /* EDGE_H */
