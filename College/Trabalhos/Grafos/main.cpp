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

class MessageFrom
{
    public:
        int origin, ttl;
        Graph* graph;

        MessageFrom(int origin, int ttl, Graph* graph) {
            this->origin = origin;
            this->ttl = ttl;
            this->graph = graph;
        }

        void Run() {
            Graph graph_copy = *graph;
            std::vector<int> messages = 
            graph_copy.ttl_breadth_first_search(origin, ttl);
            
            // Faz um vetor de recebimentos e vai mudando pra true conforme a bfs
            std::vector<bool> received(graph->num_vertices(), false);
            for (int node : messages) {
                received[node] = true;
            }

            std::cout << origin << " " << ttl << ":";
            for (int node = 0; node < graph->num_vertices(); node++) {
                if (!received[node]) {
                    std::cout << " " << node;
                }
            }
            std::cout << "\n";
        };
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
        graph = new Graph(input->network_nodes);
        for (int i = 0; i < input->network_connections; i++)
        {
            int a, b;
            std::cin >> a >> b;
            [[maybe_unused]]ConnectionBetween *connections = new ConnectionBetween(a, b, graph);
        }
        std::cin >> input->does_not_receive_message_count;
        std::vector<MessageFrom*> messages;
        for (int i = 0; i < input->does_not_receive_message_count; i++)
        {
            int origin, content;
            std::cin >> origin >> content;
            messages.push_back(new MessageFrom(origin, content, graph));
        }
        for(auto message : messages) {
            message->Run();
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
