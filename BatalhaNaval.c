#include <stdio.h>
#include <time.h>
#include <locale.h>
#define TAM 3 //Tamanho da Matriz

/**
* Fun��o       : geraTabuleiro()
* Defini��o    : Fun��o que gera a matriz no tamanho definido
*/
void geraTabuleiro(int tab[TAM][TAM]){
    int i, j;
    for(i=0; i<TAM; i++ )
        for(j=0;j<TAM;j++)
            tab[i][j]=0;
insereNavios(tab); //Insere navios aleatoriamentes
}

/**
* Fun��o       : mostraTabuleiro()
* Defini��o    : Fun��o que exibe na tela um tabuleiro com base no matriz do parametro.
*/
void mostraTabuleiro(int tab[TAM][TAM]){
    int i, j;
    for(i=0; i<TAM; i++ ) {
        for(j=0;j<TAM;j++) {
            if(tab[i][j] == 2)
                printf("[ # ]\t",tab[i][j]);
            else
                printf("[ - ]\t",tab[i][j]);
        }
        printf("\n");
    }
}

/**
* Fun��o       : insereNavios()
* Defini��o    : Fun��o que insere "Navios" rand�micos em uma matriz
*/
void insereNavios(int tab[TAM][TAM]) {
    srand (time(NULL));
    int i, j, total = 0;
    do {
        i = rand() % TAM;
        j = rand() % TAM;
        if(!tab[i][j]) {
            tab[i][j] = 1;
            total++;
        }
    } while(total<TAM);
}

/**
* Fun��o       : fazTentativas()
* Defini��o    : Loop de tentativas
*/
int fazTentativas(int tab[TAM][TAM]) {
    int x, y, n = 0;
    do {
        do {
            system("cls"); //Limpa a tela
            mostraTabuleiro(tab);
            printf("Digite o n� referente a coluna: ");
            scanf("%d", &y);
            printf("Digite o n� referente a linha: ");
            scanf("%d", &x);
            x = x-1;
            y = y-1;
        } while(tab[x][y] == 0 || tab[x][y] == 2);
        printf("\nVoc� acertou o navio inimigo!\n\n");
        tab[x][y] = 2;
        n++;

    } while (n<TAM);
    return 1;
}

/**
* Fun��o       : main()
* Defini��o    : Fun��o Principal / Main
*/
void main(void){
    int tab[TAM][TAM];
    setlocale(LC_ALL,""); //Pega a lingua do timezone default, no caso, pt-br
    geraTabuleiro(tab);
    if(fazTentativas(tab)) {
        system("cls");
        mostraTabuleiro(tab);
        printf("\nVoc� venceu!\n\n");
    }
    return 0;
}

