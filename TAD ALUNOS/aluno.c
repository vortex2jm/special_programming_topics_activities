#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"


struct aluno{

    char * nome;
    int matricula;
    float n1;
    float n2;
    float n3;
};


tAluno *CriaAluno(char * nome, int matricula, float n1, float n2, float n3){

    tAluno * aluno;
    aluno = (tAluno*) malloc(sizeof(tAluno));

    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->n1 = n1;
    aluno->n2 = n2;
    aluno->n3 = n3;

    return aluno;
}


int EstaAlunoAprovado(tAluno * aluno){

    float result;
    result = (aluno->n1 + aluno->n2 + aluno->n3)/3;
    if(result >= 7) return 1;
    else return 0;

}

int GetMatricula(tAluno * aluno){

    return aluno->matricula;
}

char * GetNome(tAluno * aluno){

    return aluno->nome;
}


void OrdenaAlunosPorOrdemDeMatricula (tAluno *alunos[], int qtd){

    tAluno * aux; 
    int x=0, y=0;

    for(x=0;x<qtd-1;x++){
        for(y=x+1;y<qtd;y++){

            if(GetMatricula(alunos[y]) < GetMatricula(alunos[x])){
                aux = alunos[x];
                alunos[x] = alunos[y];
                alunos[y] = aux;
            }
        }
    }
}


void DestroiAluno(tAluno * aluno){

    if(aluno != NULL){
        if(aluno->nome != NULL){
            free(aluno->nome);
        }
        free(aluno);
    }
}