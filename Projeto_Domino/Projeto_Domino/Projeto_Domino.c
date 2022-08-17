/*Grupo - Jogo Domino - COM MA2A - Prof Julio - PUCSP - 2022
    Alice de Oliveira Duarte - RA 00319006
    Bruno dos Santos Torres Novo - RA 00320039
    Caio Pereira Guimaraes - RA 00318945
    Joao Pedro do Carmo Ribeiro - RA00319514
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include "functions.h"

#define IN_STACK 200 

void clear_console() {

#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct dominos {
    int side1;
    int side2;
    int stackPosition;
    int pieceState;
};
struct dominos pieces[28];

void initalizeStack(struct dominos pieces[28]) {
    for (int i = 0; i < 28; i++) {
        pieces[i].pieceState = IN_STACK;
        for (int lado1 = 0; lado1 <= 6; lado1++) {
            pieces[i].side1 = lado1;
            for (int lado2 = 0; lado2 <= 6; lado2++) {
                pieces[i].side2 = lado2;
            }
        }
    }
}

void shufflePieces(struct dominos pieces[28]) {
    int k;
    int positionSave;
    bool checkStackPos = true;
    bool foo = false;

    for (int i = 0; i < 28; i++) {
        do {
            k = rand() % 28;
            for (int j = 0; j < 28; j++) {
                if (pieces[28].stackPosition == k) {

                }
            }
        } while (checkStackPos);
    }
}

//Mostra as regras do jogo do Domino
void mostraRegras() {
    //Como jogar
    printf("Como jogar o domino?\n\n");
    printf("Cada jogador recebe 7 pedras quando começa a rodada. Se na partida houver menos de 4 jogadores, as pedras restantes ficam no dorme para serem compradas.\n");
    printf("O jogo começa pelo jogador que tenha a pedra dobrada mais alta (se jogam 4 pessoas, sempre começa quem tem o seis dôbre ou carrilhão). No caso de que nenhum jogador tenha dobradas, começará o jogador que tenha a pedra mais alta. A partir desse momento, os jogadores realizam suas jogadas, por turnos e no sentido anti-horário.\n");
    printf("O jogador que começa a partida leva vantagem. Este é um conceito importante para a estratégia do domino, pois o jogador ou dupla que começa, normalmente, é o que leva a vantagem durante a partida.\n\n");
    Sleep(10);

    //Desenvolvimento do jogo
    printf("Desenvolvimento do jogo\n\n");
    printf("Cada jogador, no seu turno, deve colocar uma das suas pedras em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincida com os pontos da extremidade onde está sendo colocada. As dobradas são colocadas de maneira transversal para facilitar sua localização.\n");
    printf("Quando o jogador coloca sua pedra sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.\n");
    printf("Se um jogador não puder jogar, deverá 'comprar' do dorme tantas pedras como forem necessárias. Se não houver pedras no dorme, passará o turno ao seguinte jogador.\n\n");
    Sleep(10);

    printf("Tudo pronto para começar o jogo!\n\n");
}

//Mensagem de erro em caso de bug ou m�-sele��o
void mensagemErro() {
    printf("Ocorreu um erro na seleção, tente novamente!\n\n");
    return;
}

//Sai do jogo
void leaveGame() {
    printf("\n");
    printf("Saindo do Jogo!\n");
    printf("Obrigado por jogar!\n\n");
    exit(1);
}


int opcao = 0; //Opcao da selecao do modo de jogo
char regras; //Opcao para visualizar as regras do jogo ou nao

int main()
{

    //Pegando as informacoes dos caracye
    setlocale(LC_ALL, "Portuguese");

    //Abertura do programa
    printf("\n");
    printf("Bem-Vindo(a) ao Dominos'!");
    printf("\n\n");
    printf("             //\\                       //\\               \n");
    printf("            //  \\                     //. \\              \n");
    printf("           // .' \\                   //.   \\             \n");
    printf("          //\\' .'/                  //\\   '/             \n");
    printf("         //  \\' /                  //  \\ '/              \n");
    printf("        //    \\/                  // '  \\/               \n");
    printf("         \\'   /                   \\ '   /                \n");
    printf("          \\ '/                     \\'  /                 \n");
    printf("           \\/                       \\ /                  \n");
    printf("\n\n");

    Sleep(20);

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
        mostraRegras();
        initalizeStack(pieces);
        break;
    case 2: printf("Modo de Jogo Contra outro Jogador Selecionado\n");
        printf("Carregando o jogo...\n\n");
        Sleep(10);
        mostraRegras();
        initalizeStack(pieces);
        break;
    case 3: leaveGame();
        break;
    default: mensagemErro();
        break;
    }

    return 0;
}