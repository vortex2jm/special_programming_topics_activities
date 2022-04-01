#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario tUsuario;

tUsuario * CriaUsuario(char * nome, int cpf);

void DestroiUsuario(tUsuario * usuario);

void ImprimeUsuario(tUsuario * usuario);

void ImprimeUsuarioNoArquivo(tUsuario * usuario, FILE * arquivo);

#endif