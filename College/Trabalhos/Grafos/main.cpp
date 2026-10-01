#include "src/Edge/Edge.h"
#include "src/Graph/Graph.h"
#include "src/Exceptions/Exception.h"
#include <string>
#include <iostream>

struct Input
{
    int network_nodes;       // vertex
    int network_connections; // edges
    int does_not_receive_message_count;
};

struct Message
{
    int origin;
    int content;
};

class ConnectionBetween
{
public:
    Edge *connection;
    ConnectionBetween(int a, int b, Graph *graph)
    {
        connection = new Edge(a, b);
        try
        {
            graph->insert_edge(*connection);
        }
        catch (...)
        {
            delete connection;
            connection = nullptr;
            throw;
        }
        delete connection;
        connection = nullptr;
    }
};

int main()
{
    Input *input = new Input;
    Graph *graph;
    try
    {
        std::cin >> input->network_nodes >> input->network_connections;
        for (int i = 0; i < input->network_connections; i++)
        {
            graph = new Graph(input->network_connections);
            int a, b;
            std::cin >> a >> b;
            ConnectionBetween *connections = new ConnectionBetween(a, b, graph);
        }
        std::cin >> input->does_not_receive_message_count;
        for (int i = 0; i < input->does_not_receive_message_count; i++)
        {
            Message message;
            std::cin >> message.origin >> message.content;
        }
    }
    catch (const std::exception &e)
    {
        delete input;
        delete graph;
        Exception::print(e);
    }
    delete input;
    delete graph;
    return 0;
}
