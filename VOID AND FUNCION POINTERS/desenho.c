#include <stdio.h>
#include <stdlib.h>
#include "desenho.h"

void DesenhaQuadrado(void * qtd){

    for(int x=0; x < *(int*)qtd; x++){

        printf("\n");
        printf("*********\n");
        printf("*       *\n");
        printf("*       *\n");
        printf("*       *\n");
        printf("*********\n");
    }
}

void DesenhaTriangulo(void * qtd){

    for(int x=0; x < *(int*)qtd; x++){

        printf("\n");
        printf("     *     \n");
        printf("    * *    \n");
        printf("   *   *   \n");
        printf("  *     *  \n");
        printf(" ********* \n");
    }
}

void DesenhaCirculo(void * qtd){

    for(int x=0; x < *(int*)qtd; x++){

        printf("\n");
        printf("      * * *    \n");
        printf("    *       *  \n");
        printf("   *         * \n");
        printf("   *         * \n");
        printf("    *       *  \n");
        printf("      * * *    \n");
    
    }
}