#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Edge.h"

using namespace std;

class Node
{
    public:
        // Construtor e Destrutor
        Node(int id);
        ~Node();


        // Getters
        Edge* getFirstEdge();
        Edge* getLastEdge();
        int getId();
        int getInDegree();
        int getOutDegree();
        float getWeight();
        Node* getNextNode();
        Edge* getEdge(int target_id);
        bool getVisitado();
        Node* getPai();//backtracking


        // Setters
        void setNextNode(Node* node);
        void setWeight(float weight);
        void setVisitado(bool val);
        void setPai(Node* node);//backtracking


        // Other methods
        bool searchEdge(int target_id);
        void insertEdge(int target_id, float weight);
        void removeAllEdges();
        void incrementOutDegree();
        void decrementOutDegree();
        void incrementInDegree();
        void decrementInDegree();
        Edge* hasEdgeBetween(int target_id);
        int getNumberEdges();
        void PrintEdges();


    private:
        Edge* first_edge;
        Edge* last_edge;
        int id;
        int number_edges;
        unsigned int in_degree;
        unsigned int out_degree;
        float weight;
        Node* next_node;

        //Atributos auxiliares 
        bool visitado;
        Node* pai;//backtracking
};

#endif // NODE_H_INCLUDED