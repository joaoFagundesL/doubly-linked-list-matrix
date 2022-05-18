#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

//estrutura de cada nó da minha matriz. Cada nó possui 4 ponteiros que apontam para um outro nó.
typedef struct no {
    double valorNo;
    struct no *proximoNo;
    struct no *noAnterior;
    struct no *noAcima;
    struct no *noAbaixo;
}No;

//criando minha matriz com ponteiro duplo, ponteiro de ponteiro
No **matriz;

No *buscarValorQualquer(double valorQualquer); //Busca um valor na minha matriz e retorna o nó
No *consultarPosicao(short linha, short coluna); //Consulta uma posição, respeitando os limites da matriz (LINHA E COLUNA) e retorna null ou um nó.
int preencherMatrizDeExemplo(); //Cria todos os nós da minha matriz e preenche com valores de 1 a 9
int conectarElementosDaMatriz(); //Faz a conexão entre os elementos, os endereços dos ponteiros são definidos nessa funcao
int exibirTodosVizinhosDeUmElemento(short posicaoDaLinhaDesejada, short posicaoDaColunaDesejada); //exibe os  vizinhos de um elemento e retorna NULL caso nao haja elemento.
int inserirValorEmPosicaoEspecifica(short linhaEspecifica, short colunaEspecifica, double valorDesejado); //Insere um valor em uma posicao, respeitando os limites da matriz.
void verificarSePosicoesSaoValidas(short linha, short coluna); //funcao que vai validar se a posicao informada (linha e coluna) respeita os limites da matriz.
void liberarMatriz(); //funcao que libera a memoria
void mostrarMatriz(); //mostrar matriz na tela.
