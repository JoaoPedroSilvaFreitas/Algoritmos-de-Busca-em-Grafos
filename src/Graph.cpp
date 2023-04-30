#include "../header/Graph.h"
#include "../header/Edge.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
#include <list>

using namespace std;

// Constructor & Destructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{
    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
    this->insert_aux = 0;

    //Função para inserir nós
    for(int i = 0; i < order; i++)
    {
        insertNode(i);
    }
}

Graph::~Graph()
{
    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {
        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}


// Getters
int Graph::getOrder()
{
    return this->order;
}

int Graph::getNumberEdges()
{
    return this->number_edges;
}

Node *Graph::getFirstNode()
{
    return this->first_node;
}

Node *Graph::getLastNode()
{
    return this->last_node;
}

bool Graph::getDirected()
{
    return this->directed;
}

bool Graph::getWeightedEdge()
{
    return this->weighted_edge;
}

bool Graph::getWeightedNode()
{
    return this->weighted_node;
}

//insere nó
void Graph::insertNode(int id)
{
    Node* node = new Node(id);
    node->setNextNode(nullptr);

    if(last_node != nullptr) last_node->setNextNode(node);
    last_node = node;

    insert_aux++;
    if(insert_aux == 1) first_node = node;

    if(!getWeightedNode())
    {
        node->setWeight(1);
    }
}

//insere aresta
void Graph::insertEdge(int id, int target_id, float weight)
{
    //Caso o grafo seja direcionado
    if(getDirected())
    {
        Node* node = getNode(id);
        Node* node_target = getNode(target_id);
        node->insertEdge(target_id,weight);
        node->incrementOutDegree();
        node_target->incrementInDegree();
        this->number_edges++;
    }
    else
    {
        //Caso o grafo nao seja direcionado
        Node* node = getNode(id);
        Node* node_target = getNode(target_id);
        node->insertEdge(target_id,weight);
        node_target->insertEdge(id,weight);
        this->number_edges++;
    }
}

//procura um nó pelo id
bool Graph::searchNode(int id)
{
    Node* node;
    for(node = first_node; node != nullptr; node = node->getNextNode())
    {
        if(node->getId() == id)
        {
            return true;
        }
    }
    return false;
}

//Seleciona um nó pelo id
Node *Graph::getNode(int id)
{
    Node* node;
    for(node = first_node; node != nullptr; node = node->getNextNode())
    {
        if(node->getId() == id)
        {
            break;
        }
    }
    return node;
}


void Graph::PrintGraphList()
{
    for(Node* aux = first_node; aux != nullptr; aux = aux->getNextNode())
    {
        cout << "[" << aux->getId() << "]-->";
        aux->PrintEdges();
        cout << endl;
    }
}

void Graph::setNosNaoVisitado()
{
    Node* noAux;
    for(int i = 0; i < getOrder(); i++)
    {
        noAux = getNode(i);
        noAux->setVisitado(false);
    }
}


Edge* Graph::heuristicaIrrevogavel(Node* noAux)
{
    //Essa heuristica escolhe baseado na aresta de menor valor
    if(noAux->getNumberEdges() != 0 && !noAux->getVisitado())
    {
        Edge* arestaAux = noAux->getFirstEdge();
        for(Edge* aux = noAux->getFirstEdge(); aux != nullptr; aux = aux->getNextEdge())
        {
            if((aux->getWeight() < arestaAux->getWeight()) && !getNode(aux->getTargetId())->getVisitado())
            {
                arestaAux = aux;
            }
        }
        return arestaAux;
    }else{
        return nullptr;
    }
}

void Graph::irrevogavel(int idObjetivo)
{
    PrintGraphList();
    setNosNaoVisitado();
    Node* noAux = getFirstNode();
    bool sucesso = false;

    while(!sucesso)
    {
        cout << noAux->getId() << endl;
        Edge* arestaAux = heuristicaIrrevogavel(noAux);
        if(arestaAux != nullptr)
        {
            noAux->setVisitado(true);
            noAux = getNode(arestaAux->getTargetId());
            
            if(noAux->getId() == idObjetivo){

                cout << noAux->getId() << endl;
                sucesso = true;
                cout << "Sucesso!" << endl;
                return;
            }
        }else{
            cout << "Fracasso!" << endl;
            return;
        }
    }

}


Edge* Graph::heuristicaBacktracking(Node* noAux, int idObjetivo)
{

    if(noAux->getNumberEdges() != 0)
    {
        for(Edge* aux = noAux->getFirstEdge(); aux != nullptr; aux = aux->getNextEdge())
        {
            if(aux->getTargetId() == idObjetivo || !getNode(aux->getTargetId())->getVisitado()){

                return aux;

            }else if(aux == noAux->getLastEdge()){
                noAux->setVisitado(true);
                return nullptr;
            }
        }

    }else{
        noAux->setVisitado(true);
        return nullptr;
    }    
}

void Graph::backtracking(int idObjetivo)
{
    Node* noAux = getFirstNode();
    Edge* arestaAux;
    bool sucesso = false;
    PrintGraphList();
    setNosNaoVisitado();
    
    while(!sucesso)
    {
        cout << noAux->getId() << endl;
        arestaAux = heuristicaBacktracking(noAux,idObjetivo);
        if(arestaAux != nullptr)
        {
            getNode(arestaAux->getTargetId())->setPai(noAux);
            noAux = getNode(arestaAux->getTargetId());
            if(noAux->getId() == idObjetivo){

                cout << noAux->getId() << endl;
                sucesso = true;
                cout << "Sucesso!" << endl;
                return;
            }
        }else if(arestaAux == nullptr){
            noAux = getNode(noAux->getPai()->getId());//get pai
        }else{
            cout << "Fracasso!" << endl;
            return;
        }
    }
}

