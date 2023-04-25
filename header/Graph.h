#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

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



        //Other methods
        void insertNode(int id);
        void insertEdge(int id, int target_id, float weight);
        bool searchNode(int id);
        Node* getNode(int id);
        void Print_Ad_list();
        void Print_Graph_OF(ofstream& output_file);
        bool VerificaCiclos(ofstream& output_file);
        bool AuxVerificaCiclos(int i,bool* V, ofstream& output_file);
        bool VerificaCiclosNegativos(ofstream& output_file);
        bool AuxVerificaCiclosNegativos(int i,bool* V, ofstream& output_file);


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