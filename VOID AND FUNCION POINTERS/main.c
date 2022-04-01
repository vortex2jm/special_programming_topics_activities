#include <stdio.h>
#include <stdlib.h> 
#include "desenho.h"



int main(){

    f_desenho tabela[255];
    tabela['q'] = DesenhaQuadrado;
    tabela['t'] = DesenhaTriangulo;
    tabela['c'] = DesenhaCirculo;

    char letra; int qtd;

    printf("Digite o objeto que deseja desenhar (q - quadrado, t - triangulo, c - circulo)\n");
    scanf("%c", &letra);
    printf("Agora digite a quantidade: ");
    scanf("%d", &qtd);

    tabela[letra](&qtd); //Executando função que desenha um polígono

    return 0;
}