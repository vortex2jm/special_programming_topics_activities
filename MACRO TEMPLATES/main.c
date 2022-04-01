#include <stdio.h>
#include "vetor_int.h"
#include "vetor_double.h"


int main(){

    printf("___________________VETORES DE INTEIROS___________________\n");

    //Criando vetores
    INT_tVetor * vetorInt1 = INT_CriaVetor(3);
    INT_tVetor * vetorInt2 = INT_CriaVetor(3);

    
    //Inserindo elementos
    INT_InserirElemento(vetorInt1, 2, 0);
    INT_InserirElemento(vetorInt1, 4, 1);
    INT_InserirElemento(vetorInt1, 6, 2);

    INT_InserirElemento(vetorInt2, 3, 0);
    INT_InserirElemento(vetorInt2, 6, 1);
    INT_InserirElemento(vetorInt2, 9, 2);


    //Imprimindo os vetores
    printf("\nPrimeiro vetor\n");
    INT_ImprimeVetor(vetorInt1);
    printf("\nSegundo vetor\n");
    INT_ImprimeVetor(vetorInt2);


    //Somando e imprimindo a soma
    INT_tVetor * soma = INT_SomaVetores(vetorInt1, vetorInt2);
    printf("\nSoma dos 2 vetores\n");
    INT_ImprimeVetor(soma);


    //Multiplicando e imprimindo a multiplicação
    INT_tVetor * mult = INT_MultiplicaVetor(vetorInt1, 5);
    printf("\nMultiplicação do primeiro vetor por 5\n");
    INT_ImprimeVetor(mult);

    
    //Destruindo os vetores    
    INT_DestroiVetor(vetorInt1);     
    INT_DestroiVetor(vetorInt2);
    INT_DestroiVetor(soma);
    INT_DestroiVetor(mult);


    //_______________________________________________________________//

    printf("\n___________________VETORES DOUBLE___________________\n");


    DOUBLE_tVetor * vetorDouble1 = DOUBLE_CriaVetor(3);
    DOUBLE_tVetor * vetorDouble2 = DOUBLE_CriaVetor(3);


    DOUBLE_InserirElemento(vetorDouble1, 2.5, 0);
    DOUBLE_InserirElemento(vetorDouble1, 4.5, 1);
    DOUBLE_InserirElemento(vetorDouble1, 8.5, 2);


    DOUBLE_InserirElemento(vetorDouble2, 3.5, 0);
    DOUBLE_InserirElemento(vetorDouble2, 6.5, 1);
    DOUBLE_InserirElemento(vetorDouble2, 12.5, 2);


    printf("\nPrimeiro vetor\n");
    DOUBLE_ImprimeVetor(vetorDouble1);
    printf("\nSegundo vetor\n");
    DOUBLE_ImprimeVetor(vetorDouble2);


    DOUBLE_tVetor * somaD = DOUBLE_SomaVetores(vetorDouble1, vetorDouble2);
    printf("\nSoma dos dois vetores\n");
    DOUBLE_ImprimeVetor(somaD);


    DOUBLE_tVetor * multD = DOUBLE_MultiplicaVetor(vetorDouble1, 10.0);
    printf("\nMultiplicação do vetor 1 por 10\n");
    DOUBLE_ImprimeVetor(multD);


    DOUBLE_DestroiVetor(vetorDouble1);
    DOUBLE_DestroiVetor(vetorDouble2);
    DOUBLE_DestroiVetor(somaD);
    DOUBLE_DestroiVetor(multD);

    return 0;
}


