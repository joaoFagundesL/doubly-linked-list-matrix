#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Arquivo main com as chamadas das funcoes
int main() {
    preencherMatrizDeExemplo();
    conectarElementosDaMatriz();
    mostrarMatriz();
    exibirTodosVizinhosDeUmElemento(0, 0);
    buscarValorQualquer(9);
    inserirValorEmPosicaoEspecifica(1, 1, -1);
    inserirValorEmPosicaoEspecifica(3, 3, 10);
    mostrarMatriz();
    printf("\n");
    buscarValorQualquer(-1);
    buscarValorQualquer(13);
    consultarPosicao(1, 2);
    exibirTodosVizinhosDeUmElemento(0,2);
    liberarMatriz();

    return SUCCESS;
}
