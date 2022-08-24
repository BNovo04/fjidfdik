/*Grupo - Jogo Domino - COM MA2A - Prof Julio - PUCSP - 2022
    Alice de Oliveira Duarte - RA 00319006
    Bruno dos Santos Torres Novo - RA 00320039
    Caio Pereira Guimaraes - RA 00318945
    Joao Pedro do Carmo Ribeiro - RA00319514
*/

//Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

//Arquivos head para o main file
#include "functions.h"
#include "uivisuals.h"
#include "estruturas.h"

int opcao = 0; //Opcao da selecao do modo de jogo
char regras; //Opcao para visualizar as regras do jogo ou nao

int main()
{

    //Pegando as informacoes dos caracye
    setlocale(LC_ALL, "Portuguese");

    aberturaJogo();

    //Perguntando o modo de jogo para o jogador
    printf("Qual o modo de jogo desejado?\n");
    Sleep(10);
    printf("1- Contra a máquina\t 2- Contra outro jogador\t 3- Sair do Jogo\n");
    scanf("%d", &opcao);

    //Carregando o jogo
    switch (opcao) {
    case 1: printf("Modo de Jogo Contra a Máquina Selecionado\n");
        printf("Carregando o jogo...\n\n");
        Sleep(10);
        determinaJogadores();
        initalizeStack(pieces);
        break;
    case 2: printf("Modo de Jogo Contra outro Jogador Selecionado\n");
        printf("Carregando o jogo...\n\n");
        Sleep(10);
        determinaJogadores();
        initalizeStack(pieces);
        break;
    case 3: leaveGame();
        break;
    default: mensagemErro();
        break;
    }

    return 0;
}
