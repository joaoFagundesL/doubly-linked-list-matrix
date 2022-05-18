#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define SUCCESS 0
#define ERROR 1

//Assumindo inicialmente uma matriz 3x3, porem qualquer valor irá funcionar, basta alterar aqui os valores.
short const LINHA = 3;
short const COLUNA = 3;

int preencherMatrizDeExemplo() {
    double valor = 1.0;

    matriz = (No**) malloc(LINHA * sizeof(No *));

    for(int linha = 0; linha < LINHA; ++linha) {
        matriz[linha] = (No*)malloc(COLUNA * sizeof(No));
        for(int coluna = 0; coluna < COLUNA; ++coluna) {
            (*(matriz + linha) + coluna)->valorNo = valor++;
        }
    }

    return SUCCESS;
}

No *buscarValorQualquer(double valorQualquer) {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    short contadorDireita = 0, contadorBaixo = 0;

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            if(moverParaDireita->valorNo == valorQualquer) {
                inicio = moverParaDireita;
                printf("VALOR [%.2lf] ENCONTRADO\n", moverParaDireita->valorNo);
                if(moverParaDireita->noAcima == NULL) printf("Valor acima = NULL\n");
                else printf("Valor acima = [%.2lf]\n", moverParaDireita->noAcima->valorNo);

                if(moverParaDireita->noAbaixo == NULL) printf("Valor abaixo = NULL\n");
                else printf("Valor abaixo = [%.2lf]\n", moverParaDireita->noAbaixo->valorNo);

                if(moverParaDireita->proximoNo == NULL) printf("Valor a direita = NULL\n");
                else printf("Valor a direita = [%.2lf]\n", moverParaDireita->proximoNo->valorNo);

                if(moverParaDireita->noAnterior == NULL) printf("Valor a esquerda = NULL\n");
                else printf("Valor a esquerda = [%.2lf]\n\n", moverParaDireita->noAnterior->valorNo);

                return inicio;
            }
            contadorDireita++;
            moverParaDireita = moverParaDireita->proximoNo;
        }
        contadorDireita = 0;
        contadorBaixo++;
        moverParaBaixo = moverParaBaixo->noAbaixo;
    }

    printf("VALOR [%.2lf] NAO ENCONTRADO\n\n", valorQualquer);
    return NULL;
}

int conectarElementosDaMatriz() {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    short contadorDireita = 0, contadorBaixo = 0;

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            if(contadorBaixo == 0) (*(matriz + contadorBaixo) + contadorDireita)->noAcima = NULL;
            else (*(matriz + contadorBaixo) + contadorDireita)->noAcima =  (*(matriz + contadorBaixo - 1) + contadorDireita);

            if(contadorDireita == 0) (*(matriz + contadorBaixo) + contadorDireita)->noAnterior = NULL;
            else (*(matriz + contadorBaixo) + contadorDireita)->noAnterior = (*(matriz + contadorBaixo) + contadorDireita - 1);

            if(contadorBaixo == LINHA - 1 ) (*(matriz + contadorBaixo) + contadorDireita)->noAbaixo = NULL;
            else (*(matriz + contadorBaixo) + contadorDireita)->noAbaixo = (*(matriz + contadorBaixo + 1) + contadorDireita);

            if(contadorDireita == COLUNA - 1) (*(matriz + contadorBaixo) + contadorDireita)->proximoNo = NULL;
            else (*(matriz + contadorBaixo) + contadorDireita)->proximoNo = (*(matriz + contadorBaixo) + contadorDireita + 1);
            contadorDireita++;
            moverParaDireita = moverParaDireita->proximoNo;
        }
        contadorDireita = 0;
        contadorBaixo++;
        moverParaBaixo = moverParaBaixo->noAbaixo;

    }

    return SUCCESS;
}

int exibirTodosVizinhosDeUmElemento(short posicaoDaLinhaDesejada, short posicaoDaColunaDesejada) {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    short contadorDireita = 0, contadorBaixo = 0;;

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            if(contadorDireita == posicaoDaColunaDesejada && contadorBaixo == posicaoDaLinhaDesejada) {
                printf("\nELEMENTO ESCOLHIDO = [%.2lf]\n", matriz[contadorBaixo][contadorDireita].valorNo);

                if((*(matriz + contadorBaixo) + contadorDireita)->noAcima == NULL) printf("Valor acima = NULL\n");
                else printf("\nValor acima = [%.2lf]\n", (*(matriz + contadorBaixo) + contadorDireita)->noAcima->valorNo);

                if((*(matriz + contadorBaixo) + contadorDireita)->noAbaixo == NULL) printf("Valor abaixo = NULL\n");
                else printf("Valor abaixo = [%.2lf]\n", (*(matriz + contadorBaixo) + contadorDireita)->noAbaixo->valorNo);

                if((*(matriz + contadorBaixo) + contadorDireita)->noAnterior == NULL) printf("Valor a esquerda = NULL\n");
                else printf("Valor anterior = [%.2lf]\n", (*(matriz + contadorBaixo) + contadorDireita)->noAnterior->valorNo);

                if((*(matriz + contadorBaixo) + contadorDireita)->proximoNo == NULL) printf("Valor a direita = NULL\n");
                else printf("Valor a direita = [%.2lf]\n\n", (*(matriz + contadorBaixo) + contadorDireita)->proximoNo->valorNo);
            }
            contadorDireita++;
            moverParaDireita = moverParaDireita->proximoNo;
        }
        contadorDireita = 0;
        contadorBaixo++;
        moverParaBaixo = moverParaBaixo->noAbaixo;
    }
    return SUCCESS;
}

void mostrarMatriz() {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            printf("[%.2lf] ", moverParaDireita->valorNo);
            moverParaDireita = moverParaDireita->proximoNo;
        }
        printf("\n");
        moverParaBaixo = moverParaBaixo->noAbaixo;
    }
}

void verificarSePosicoesSaoValidas(short linha, short coluna) {
    if(linha >= LINHA || coluna >= COLUNA) {
        printf("POSICAO %hi, %hi NAO EXISTE\n\n", linha, coluna);
    }
}

int inserirValorEmPosicaoEspecifica(short linhaEspecifica, short colunaEspecifica, double valorDesejado) {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    int contadorDireita = 0, contadorBaixo = 0;

    verificarSePosicoesSaoValidas(linhaEspecifica, colunaEspecifica);

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            if(linhaEspecifica == contadorBaixo && colunaEspecifica == contadorDireita) {
                printf("[%.2lf] ALTERADO PARA [%.2lf]\n\n", (*(matriz + contadorBaixo) + contadorDireita)->valorNo, valorDesejado);
                (*(matriz + contadorBaixo) + contadorDireita)->valorNo = valorDesejado; //ALTERANDO SÓ O VALOR POR MEIO DO PONTEIRO, AS CONEXOES CIMA, BAIXO, ESQUERDA E DIREITA CONTINUAM
            }
        contadorDireita++;
        moverParaDireita = moverParaDireita->proximoNo;
        }
        contadorDireita = 0;
        contadorBaixo++;
        moverParaBaixo = moverParaBaixo->noAbaixo;
    }
    return SUCCESS;
}

No *consultarPosicao(short linha, short coluna) {
    No *inicio = &matriz[0][0];
    No *moverParaDireita;
    No *moverParaBaixo = inicio;

    short contadorDireita = 0, contadorBaixo = 0;

    verificarSePosicoesSaoValidas(linha, coluna);

    while(moverParaBaixo) {
        moverParaDireita = moverParaBaixo;
        while(moverParaDireita) {
            if(linha == contadorBaixo && coluna == contadorDireita) {
                printf("VALOR NA POSICAO %hi, %hi = [%.2lf]\n\n", linha, coluna, moverParaDireita->valorNo);
                return moverParaDireita;
            }
            contadorDireita++;
            moverParaDireita = moverParaDireita->proximoNo;
        }
        contadorDireita = 0;
        contadorBaixo++;
        moverParaBaixo = moverParaBaixo->noAbaixo;
    }

}

void liberarMatriz() {
    //funcao para liberar a memoria da matriz

    for(short linha = 0; linha < LINHA; ++linha)
        free(matriz[linha]);
    free(matriz);
}
