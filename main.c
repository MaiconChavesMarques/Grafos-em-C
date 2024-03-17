#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include <stdbool.h>

int main(){

    printf("Digite o numero de vertices que deseja que o grafo tenha:\n");
    int n;
    scanf("%d", &n);

    GRAPH *grafo1 = MyGraph (n); // a)
    print_info(grafo1);
    char comando[30];
    bool teste = true;

    while(teste){
        scanf(" %s", comando);
        if((strcmp(comando, "ADC_ARESTA"))==0){             // h)  
            int vertice01, vertice02, peso;
            scanf("%d %d %d", &vertice01, &vertice02, &peso);
            add_edge(grafo1, vertice01, vertice02, peso);
            print_info(grafo1);
        }
        if((strcmp(comando, "ADC_VERTICE"))==0){
            int vertice01;
            scanf("%d", &vertice01);
            add_vertex(grafo1, vertice01);
            print_info(grafo1);
        }
        if((strcmp(comando, "EXISTE_ARESTA"))==0){    //b)
            int vertice01, vertice02;
            scanf("%d %d", &vertice01, &vertice02);
            exist_edge(grafo1, vertice01, vertice02);
        }
        if((strcmp(comando, "ADJACENTES_VERTICE"))==0){  //c)
            int vertice01;
            scanf("%d", &vertice01);
            get_adj_vertex(grafo1, vertice01);
        }
        if((strcmp(comando, "REMOVE_ARESTA"))==0){ //d)
            int vertice01, vertice02;
            scanf("%d %d", &vertice01, &vertice02);
            remove_edge(grafo1, vertice01, vertice02);
            print_info(grafo1);
        }
        if((strcmp(comando, "IMPRIMIR_GRAFO"))==0){ //e)
            print_info(grafo1);
        }
        if((strcmp(comando, "NUMERO_VERTICES"))==0){ //f)
            number_of_vertexs(grafo1);
        }
        if((strcmp(comando, "REMOVER_GRAFO"))==0){  //g)
            remove_graph(&grafo1);
            teste = false;
        }
        if((strcmp(comando, "REMOVER_MENOR_PESO"))==0){  //i)
            print_info(grafo1);
            menor_peso_graph(grafo1);
            print_info(grafo1);
        }
        if((strcmp(comando, "MATRIZ_ADJACENCIA"))==0){  //j)
            int** mat = adjacency_matrix(grafo1);
            for(int i = 0; i < number_of_vertexs(grafo1); i++){
                for(int j = 0; j < number_of_vertexs(grafo1); j++){
                    printf("%d ", mat[i][j]);
                }       
            printf("\n");
            }
            for(int i = 0; i < number_of_vertexs(grafo1); i++){
                free(mat[i]);
            }
            free(mat);
        }
        if((strcmp(comando, "SAIR"))==0){
            remove_graph(&grafo1);
            teste = false;
        }
    }

    return 0;
}
