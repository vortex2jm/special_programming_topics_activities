#include <stdio.h>
#include <stdlib.h>

#ifdef TIPADO
#ifdef IO_FORMATO
#ifdef TIPO

//Estrutura
struct TIPADO(_vetor){

    int capacidade;
    TIPO * array;
};

//Criar
TIPADO(tVetor *) TIPADO(CriaVetor)(int tam){

    TIPADO(tVetor *) vector = (TIPADO(tVetor *))malloc(sizeof(TIPADO(tVetor)));

    vector->capacidade = tam;
    vector-> array = (TIPO *) malloc(tam * sizeof(TIPO));

    return vector;
}

//Set
void TIPADO(InserirElemento)(TIPADO(tVetor *) vector, TIPO elemento, int indice){

    vector->array[indice] = elemento;
}

//Impressão
void TIPADO(ImprimeVetor)(TIPADO(tVetor *) vector){

    printf("vet = {");

    for(int x=0;x<vector->capacidade;x++){

        printf(IO_FORMATO, vector->array[x]);
        if(x != vector->capacidade - 1) printf(", ");

    }
    printf("}\n");
}

//Somar
TIPADO(tVetor *) TIPADO(SomaVetores)(TIPADO(tVetor *) vet1, TIPADO(tVetor *) vet2){

    if(vet1->capacidade != vet2->capacidade) {

        printf("Vetores de tamanhos diferentes não podem ser somados\n");

        return NULL;
    }
    
    else{

        TIPADO(tVetor *) result = (TIPADO(tVetor *))malloc(sizeof(TIPADO(tVetor)));

        result->capacidade = vet1->capacidade;
        result->array = (TIPO *)malloc(result->capacidade * sizeof(TIPO));

        for(int x=0;x<vet1->capacidade;x++){

            result->array[x] = vet1->array[x] + vet2->array[x];
        }

        return result;
    }
    
}


//Multiplicação por escalar
TIPADO(tVetor *) TIPADO(MultiplicaVetor)(TIPADO(tVetor *) vector, TIPO constante){

    TIPADO(tVetor *) result = (TIPADO(tVetor *))malloc(sizeof(TIPADO(tVetor)));

    result->capacidade = vector->capacidade;
    result->array = (TIPO *)malloc(result->capacidade * sizeof(TIPO));

    for(int x=0;x<vector->capacidade;x++){

        result->array[x] = vector->array[x] * constante;
    }

    return result;
}

//Destruir
void TIPADO(DestroiVetor)(TIPADO(tVetor *) vector){

    if(vector != NULL){
        if(vector->array != NULL){
            free(vector->array);
        }
        free(vector);
    }
}



#endif
#endif
#endif