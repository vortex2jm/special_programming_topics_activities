#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"


int main(){

    int qtd=0, x=0, matricula=0;
    char nome[100];
    float n1, n2, n3;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qtd);

    //vetor de ponteiros para o tipo tAluno
    tAluno *alunos[qtd];

    for(x=0;x<qtd;x++){
        printf("Nome: ");
        scanf("%*c%[^\n]", nome);
        printf("Numero de matricula: ");
        scanf("%d", &matricula);
        printf("Notas:\n");
        scanf("%f%f%f", &n1, &n2, &n3);
        alunos[x] = CriaAluno(nome, matricula, n1, n2, n3);
    }

    OrdenaAlunosPorOrdemDeMatricula (alunos, qtd);

    printf("Alunos aprovados:\n");

    for(x=0;x<qtd;x++){

        if(EstaAlunoAprovado(alunos[x])){
            printf("%s\n", GetNome(alunos[x]));
        }

        DestroiAluno(alunos[x]);
    }
    
    return 0;
}