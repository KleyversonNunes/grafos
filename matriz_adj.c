/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implementar uma representação de matriz de adjacências utilizando como base listas encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem {
    int vertice;
    struct TipoItem* proximo;  
}TipoItem;

typedef struct Grafo {
    int numVertices;
    TipoItem** listaAdj;
    // Tipo de Grafo: Direcionado (Digrafo) ou Não direcionado
    char tipo;
} Grafo;

TipoItem* criarItem(int vertice) {
    TipoItem* novoItem = (TipoItem*)malloc(sizeof(TipoItem));
    novoItem->vertice = vertice;
    novoItem->proximo = NULL;
    return novoItem;
}

Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;

    grafo->listaAdj = (TipoItem**)malloc(numVertices * sizeof(TipoItem*));
    for (int i = 0; i < numVertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int V1, int V2) {
    TipoItem* novoItem = criarItem(V2);
    novoItem->proximo = grafo->listaAdj[V1];
    grafo->listaAdj[V1] = novoItem;

    novoItem = criarItem(V1);
    novoItem->proximo = grafo->listaAdj[V2];
    grafo->listaAdj[V2] = novoItem;
}

void imprimeGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        TipoItem* temp = grafo->listaAdj[i];
        printf("Vértice %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices = 5;

    Grafo* grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    imprimeGrafo(grafo);

    return 0;
}