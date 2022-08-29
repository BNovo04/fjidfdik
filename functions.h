#include "estruturas.h"

#define IN_STACK 200

void clear_console() {

#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Inicia a mesa do jogo
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

//Embaralha as peças
void shufflePieces(struct dominos pieces[28]) {
	struct domino piece;
	struct domino *domino, *dominos, *store = NULL;
	int i, j, k=0, flags[28];
	dominos = stack()
	for(i=0; i<28; i++) flags[i] = 0;
	    while(k < 28){
		    srand((time(NULL)+i++));
		    j = rand() % 28;
		if(flags[j]) continue;
		domino = &dominos[j];
		if(store != NULL){
			store->antes = domino;
			domino->depois = store;
		}
		store = domino;
		flags[j] = 1;
		k++;
	}
}

void determinaJogadores(){
    int qtd;

    printf("Quantos jogadores irão participar do jogo? (Até 2 jogadores)\t\n");
    scanf("%d", &qtd);

    if(qtd > 1 && qtd < 3){
        printf("%d jogadores selecionados", qtd);
        mostraRegras();
    }
    else {
        mensagemErro();
        break;
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
    printf("Obrigado por jogar Dominos'!\n\n");
    exit(1);
}
