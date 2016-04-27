#include <stdio.h>
#include <time.h>
#include <locale.h>
#define TAM 3 //Tamanho da Matriz

/**
* Função       : geraTabuleiro()
* Definição    : Função que gera a matriz no tamanho definido
*/
void geraTabuleiro(int tab[TAM][TAM]){
    int i, j;
    for(i=0; i<TAM; i++ )
        for(j=0;j<TAM;j++)
            tab[i][j]=0;
insereNavios(tab); //Insere navios aleatoriamentes
}

/**
* Função       : mostraTabuleiro()
* Definição    : Função que exibe na tela um tabuleiro com base no matriz do parametro.
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
* Função       : insereNavios()
* Definição    : Função que insere "Navios" randômicos em uma matriz
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
* Função       : fazTentativas()
* Definição    : Loop de tentativas
*/
int fazTentativas(int tab[TAM][TAM]) {
    int x, y, n = 0;
    do {
        do {
            system("cls"); //Limpa a tela
            mostraTabuleiro(tab);
            printf("Digite o nº referente a coluna: ");
            scanf("%d", &y);
            printf("Digite o nº referente a linha: ");
            scanf("%d", &x);
            x = x-1;
            y = y-1;
        } while(tab[x][y] == 0 || tab[x][y] == 2);
        printf("\nVocê acertou o navio inimigo!\n\n");
        tab[x][y] = 2;
        n++;

    } while (n<TAM);
    return 1;
}

/**
* Função       : main()
* Definição    : Função Principal / Main
*/
void main(void){
    int tab[TAM][TAM];
    setlocale(LC_ALL,""); //Pega a lingua do timezone default, no caso, pt-br
    geraTabuleiro(tab);
    if(fazTentativas(tab)) {
        system("cls");
        mostraTabuleiro(tab);
        printf("\nVocê venceu!\n\n");
    }
    return 0;
}

