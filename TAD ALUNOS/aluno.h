#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno tAluno;

tAluno *CriaAluno(char * nome, int matricula, float n1, float n2, float n3);

void OrdenaAlunosPorOrdemDeMatricula (tAluno *alunos[], int qtd);

int GetMatricula(tAluno * aluno);

int EstaAlunoAprovado(tAluno * aluno);

char *GetNome(tAluno * aluno);

void DestroiAluno(tAluno * aluno);

#endif