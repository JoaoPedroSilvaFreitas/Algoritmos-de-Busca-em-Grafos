# Algoritmos-de-Busca-em-Grafos
apenas para praticar

.\main files/input/Grafo.txt files/output/output.txt 0 0 1



-Parametros para iniciar o programa:
Nome_do_programa    Nome_do_arquivo_de_entrada.txt  Nome_do_arquivo_de_saida.txt (direcionado)   (aresta)    (nó)

comando para compilar(windows): cd "path do programa" ; if ($?) { g++ main.cpp Graph.cpp Node.cpp Edge.cpp -o main } ; if ($?) { .\main files/input/file.txt files/output/file.txt (0 ou 1) (0 ou 1) (0 ou 1)}


-Formato arquivo de entrada:

    -Caso Grafo não tenha peso nos nós ou arestas:
        ordem do grafo
        Id(i)   Id(j)

    -Caso Grafo tenha peso nas arestas:
        ordem do grafo
        Id(i)   Id(j)   Peso(ij)

    -Caso Grafo tenha peso nos nós:
        ordem do grafo
        Id(i)   Peso(i)   Id(j)   Peso(j)

    -Caso Grafo tenha peso nos nós e nas arestas
        ordem do grafo
        Id(i)   Peso(i)   Id(j)   Peso(j)   Peso(ij)
