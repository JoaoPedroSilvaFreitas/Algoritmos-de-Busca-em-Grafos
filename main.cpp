#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "header/Graph.h"

using namespace std;

Graph* Cria_Grafo(ifstream& input_file, int directed, int weightedEdge, int weightedNode)
{
    //Variáveis para auxiliar na criação de arestas no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode);

    if(!graph->getWeightedEdge() && !graph->getWeightedNode())//Caso o grafo não tenha peso nos nós e arestas
    {
        while(input_file >> idNodeSource >> idNodeTarget) 
        {
            graph->insertEdge(idNodeSource, idNodeTarget, 1);
        }

    }else if(graph->getWeightedEdge() && !graph->getWeightedNode() )//Caso o grafo tenha peso nas arestas
    {
        float edgeWeight;

        while(input_file >> idNodeSource >> idNodeTarget >> edgeWeight) 
        {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);

        }

    }else if(graph->getWeightedNode() && !graph->getWeightedEdge())//Caso o grafo tenha peso nos nós
    {
        float nodeSourceWeight, nodeTargetWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) 
        {

            graph->insertEdge(idNodeSource, idNodeTarget, 1);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }

    }else if(graph->getWeightedNode() && graph->getWeightedEdge())//Caso o grafo tenha peso nos nós e arestas
    {

        float nodeSourceWeight, nodeTargetWeight, edgeWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight >> edgeWeight) 
        {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }
    }

    return graph;
}

char MainMenu(Graph* grafo)
{
    char opt = '1';
    cout << "--------------------------------Main Menu---------------------------------" << endl;
    cout << "1-" << endl;
    cout << "2-" << endl;
    cout << "3-" << endl;
    cout << "0- Sair" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cin >> opt;
    return opt;
}

void AuxMainMenu(Graph* grafo, ofstream& output_file, string output_file_name)
{
    char opt = '1';
    while(opt != '0')
    {
        opt = MainMenu(grafo);
    }
}

int main(int argc, const char*argv[])
{
    //Verifica se foram passados todos parametros
    if (argc != 6) 
    {
        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;
    }

    //Declara três strings que recebem nome do programa, nome dos arquivos de entrada e saida
    string program_name(argv[0]);
    string input_file_name(argv[1]);
    string output_file_name(argv[2]);

    //"Declara" arquivo de entrada e saida
    ifstream input_file;
    ofstream output_file;

    //Abre o aquivo de entrada e o arquivo de saida
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);

    //Declara um ponteiro de grafo
    Graph* grafo;

    //Verifica se o arquivo de entrada foi aberto com sucesso
    if(input_file.is_open())
    {
        //Lê o arquivo de entrada (atoi converte string em inteiro)
        grafo = Cria_Grafo(input_file, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    }
    else
    {
        cout << "ERRO: Nao foi possivel abrir arquivo " << argv[1];
        exit(1);
    } 

    AuxMainMenu(grafo,output_file,output_file_name);

   //Fechando arquivos de entrada e saída
    input_file.close();
    output_file.close();
}
