
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

// elemento da lista ligada a ser gerada
// observando que cada nó contém apenas um caractere (ch)
typedef struct estr {
        char ch;
        struct estr *prox;
} NO;

//funcao para criar um NO
NO* criarNo(char pCaracter){

    NO* novoNo = NULL;

    //alocando memoria e preenchendo NO.
    novoNo = (NO*)malloc(sizeof(NO));
    //(*novoNo).
    novoNo->ch = pCaracter;
    novoNo->prox = NULL;

    return novoNo;
}

//funcao para inserir o novoNo no final da ListaLigada
void inserirNo(NO** pUltimoNo, NO* pNovoNo, NO** pListaLigada /*ponteiro para o ponteiro da Lista*/){

    //se a lista estiver vazia
    if(*pListaLigada == NULL){
        *pListaLigada = pNovoNo;
    }else{
        /* antes trocar  */
        (*pUltimoNo)->prox = pNovoNo; //acessando o conteudo do ponteiro pUltimoNo
    }
    *pUltimoNo = pNovoNo;
}


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* decodificar(char* entrada)
{
    NO* listaLigada = NULL;//inicio da lista
    NO* ultimoNo = NULL;
    NO* novoNo;
    char caracter;
    int digito, i;
    int iEntrada = 0;

    //percorrendo o vetor
    while(entrada[iEntrada]){
        digito = entrada[iEntrada] - '0'; //convertendo o caracter em digito

        //verificando se é digito e nao eh o ultimo char da string
        if(digito >= 0 && digito <= 9 && entrada[iEntrada + 1]){
            iEntrada++;
            //caracter a ser repetido.
            caracter = entrada[iEntrada];

            //caso do numero seguido de char, cria n vezes o NO
            for(i = 0; i < digito; i++){
                novoNo = criarNo(caracter);
                inserirNo(&ultimoNo, novoNo, &listaLigada);
            }
        }else{ //se nao for digito ou se o ultimo char da string for digito
            caracter = entrada[iEntrada]; //char a ser incluido na lista
            novoNo = criarNo(caracter);
            inserirNo(&ultimoNo, novoNo, &listaLigada);
        }
        iEntrada++;
    }

    return listaLigada;
}

//funcao para exibir a lista com fins de testar o programa criado
void imprimirLista(NO* listaLigada){

    printf("\n");
    while(listaLigada){
        printf("%c", listaLigada->ch); //caracter da ListaLigada
        listaLigada = listaLigada->prox;
    }
    printf("\n");
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {
	NO* teste = NULL;
	char entrada[] = "Li 12 vezes e nao entendi nad5a 7!";
	teste = decodificar(entrada);
	imprimirLista(teste);
	return 0;
}

// por favor nao inclua nenhum código abaixo da função main()
