#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Node.h"

using namespace std;

class Graph
{
    public:
        // Construtor e Destrutor
        Graph(int order, bool directed, bool weighted_edge, bool weighted_node);
        ~Graph();

        //construtor subgrafo vértice induzido
        Graph(int order, int* listIdNodes, bool directed, bool weighted_edge, bool weighted_node);

        //Getters
        int getOrder();
        int getNumberEdges();
        bool getDirected();
        bool getWeightedEdge();
        bool getWeightedNode();
        Node* getFirstNode();
        Node* getLastNode();


        //Search algorithms

        //não informados
        void irrevogavel(int id);
        Edge* heuristicaIrrevogavel(Node* noaux);

        void backtracking();
        void buscaEmLargura();
        void buscaEmProfundidade();
        void buscaOrdenada();

        //informados
        void buscaGulosa();
        void aEstrela();
        void idaEstrela();


        //Other methods
        void setNosNaoVisitado();
        void insertNode(int id);
        void insertEdge(int id, int target_id, float weight);
        bool searchNode(int id);
        Node* getNode(int id);
        void PrintGraphList();


    private:
    
        int insert_aux;
        int order;
        int number_edges;
        bool directed;
        bool weighted_edge;
        bool weighted_node;
        Node* first_node;
        Node* last_node;
};

#endif // GRAPH_H_INCLUDED