#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct usuario {
    
    char * nome;
    int cpf;

};

tUsuario * CriaUsuario(char * nome, int cpf){

    tUsuario * usuario;
    usuario = (tUsuario*) malloc(sizeof(tUsuario));

    usuario->nome = strdup(nome);
    usuario->cpf = cpf;

    return usuario;
}

void DestroiUsuario(tUsuario * usuario){

    if(usuario != NULL){

        if(usuario->nome != NULL){
            free(usuario->nome);
        }
        free(usuario);
    }
}

void ImprimeUsuario(tUsuario * usuario){

    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %d\n", usuario->cpf);
}

void ImprimeUsuarioNoArquivo(tUsuario * usuario, FILE * arquivo){

    fprintf(arquivo,"Nome: %s\n", usuario->nome);
    fprintf(arquivo,"CPF: %d\n", usuario->cpf);
}