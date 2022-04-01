#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "usuario.h"

struct conta{

    tUsuario * usuario;
    int numero_agencia;
    int numero_conta;
    float saldo;
    float * movimentacoes;
    int qtdMovimentacoes;

};

tConta * CriaConta(char * nome, int cpf, int num){

    tUsuario * usuario;
    usuario = CriaUsuario(nome, cpf);

    tConta * conta;
    conta = (tConta*) malloc(sizeof(tConta));
    if(conta == NULL){
        printf("Erro: Memoria insuficiente!\n");
        exit(1);
    }

    conta->movimentacoes = (float*)malloc(sizeof(float));
    conta->qtdMovimentacoes = 0;

    conta->usuario = usuario;
    conta->numero_agencia = 1234;
    conta->numero_conta = num;
    conta->saldo = 0;

    return conta;
}

void Saque(tConta ** conta, int qtd, float valor, int num){

    for(int y=0;y<qtd;y++){

        if(num == conta[y]->numero_conta){

            if(valor > conta[y]->saldo){

            printf("Saldo insuficiente!\n");
            }
            else{

                conta[y]->saldo -= valor;
                printf("Saque efetuado com sucesso!\n");

                conta[y]->movimentacoes =  realloc(conta[y]->movimentacoes,(conta[y]->qtdMovimentacoes + 1) * sizeof(float));
                conta[y]->movimentacoes[conta[y]->qtdMovimentacoes] = -valor;
                conta[y]->qtdMovimentacoes += 1;
            }
        }
    }
}

void Deposito(tConta ** conta, int qtd, float valor, int num){

    for(int y=0;y<qtd;y++){

        if(num == conta[y]->numero_conta){

            if(valor <= 0){

                printf("Nao eh possivel depositar este valor!\n");
            }
            else{

                conta[y]->saldo += valor;
                printf("Deposito efetuado com sucesso!\n");

                conta[y]->movimentacoes =  realloc(conta[y]->movimentacoes,(conta[y]->qtdMovimentacoes + 1) * sizeof(float));
                conta[y]->movimentacoes[conta[y]->qtdMovimentacoes] = valor;
                conta[y]->qtdMovimentacoes += 1;
            }
        }
    }
}

void Transferencia(tConta ** conta, int qtd, int numOrigem, int numDestino, float valor){

    for(int x=0;x<qtd;x++){

        if(numOrigem == conta[x]->numero_conta){

            for(int y=0;y<qtd;y++){

                if(numDestino == conta[y]->numero_conta){

                    if(valor > conta[x]->saldo){
                        printf("Não é possível realizar a transferência. Saldo insuficiente!");
                    }
                    else{
                        
                        if(valor <= 0){printf("Não eh possivel depositar este valor.");}
                        else{
                            conta[x]->saldo -= valor;

                            conta[x]->movimentacoes =  realloc(conta[x]->movimentacoes,(conta[x]->qtdMovimentacoes + 1) * sizeof(float));
                            conta[x]->movimentacoes[conta[x]->qtdMovimentacoes] = -valor;
                            conta[x]->qtdMovimentacoes += 1;


                            conta[y]->saldo += valor;

                            conta[y]->movimentacoes =  realloc(conta[y]->movimentacoes,(conta[y]->qtdMovimentacoes + 1) * sizeof(float));
                            conta[y]->movimentacoes[conta[y]->qtdMovimentacoes] = valor;
                            conta[y]->qtdMovimentacoes += 1;
                        }
                    }
                }
            }
        }
    }
}

void DestroiConta(tConta * conta){

    if(conta != NULL){

        if(conta->usuario != NULL){
            DestroiUsuario(conta->usuario);
        }
        if(conta->movimentacoes != NULL){
            free(conta->movimentacoes);
        }

        free(conta);
    }
}

void ImprimeConta(tConta * conta){

    printf("Conta: %d\n", conta->numero_conta);
    printf("Saldo: %.f\n", conta->saldo);
    ImprimeUsuario(conta->usuario);
    printf("\n");
    
}

void ImprimeTodasAsContas(tConta ** conta, int qtd){

    for(int x=0;x<qtd;x++){

        ImprimeConta(conta[x]);
    }
}

tConta ** AdicionaConta(tConta ** contas, int tam, char * nome, int cpf, int num){

    int tamanhoDesejado = tam + 1;

    contas = realloc(contas,tamanhoDesejado*sizeof(tConta*));
    contas[tam] = CriaConta(nome,cpf,num);
    
    return contas;
}

void ImprimeMovimentacoes(tConta ** contas, int qtd, int numConta, int qtdMov, FILE * arquivo){

    if(qtdMov){

        printf("Ultimas %d movimentacoes\n", qtdMov);
        fprintf(arquivo, "Ultimas %d movimentacoes\n", qtdMov);

        for(int x=0;x<qtd;x++){
        
            if(contas[x]->numero_conta == numConta){

                if(qtdMov >= contas[x]->qtdMovimentacoes){

                    for(int y=contas[x]->qtdMovimentacoes - 1; y>=0; y--){

                        printf("%.2f\n", contas[x]->movimentacoes[y]);
                        fprintf(arquivo,"%.2f\n", contas[x]->movimentacoes[y]);
                    }
                }
                else{

                    for(int y=contas[x]->qtdMovimentacoes - 1; y>=(contas[x]->qtdMovimentacoes - qtdMov); y--){

                        printf("%.2f\n", contas[x]->movimentacoes[y]);

                        fprintf(arquivo,"%.2f\n", contas[x]->movimentacoes[y]);
                    }
                }              
            }
        }
    }
}

void ImprimeContaEspecifica(tConta ** contas, int qtd, int numConta, FILE * arquivo){

    for(int x=0;x<qtd;x++){

        if(contas[x]->numero_conta == numConta){
            ImprimeConta(contas[x]);
            ImprimeContaNoArquivo(contas[x], arquivo);
        }
    }
}

void ImprimeExtrato(tConta ** contas, int qtd, int numConta, int qtdMov, FILE * arquivo){

    char diretorio[20];
    sprintf(diretorio,"./saida/%d.txt", numConta);
    arquivo = fopen(diretorio,"w");

    printf("\n===Imprimindo Extrato===\n");
    ImprimeContaEspecifica(contas, qtd, numConta, arquivo);
    ImprimeMovimentacoes(contas, qtd, numConta, qtdMov, arquivo);

    fclose(arquivo);
}

void ImprimeContaNoArquivo(tConta * conta, FILE * arquivo){

    fprintf(arquivo,"Conta: %d\n", conta->numero_conta);
    fprintf(arquivo,"Saldo: %.f\n", conta->saldo);
    ImprimeUsuarioNoArquivo(conta->usuario, arquivo);
    fprintf(arquivo,"\n");
}

void ImprimeRelatorioNoArquivo(tConta ** contas, int qtd, FILE * arquivo){

    char diretorio[25];
    sprintf(diretorio,"./saida/relatorio.txt");
    arquivo = fopen(diretorio,"w");

    fprintf(arquivo,"\n===| Imprimindo Relatorio |===\n");

    for(int x=0;x<qtd;x++){

        ImprimeContaNoArquivo(contas[x], arquivo);
    }

    fclose(arquivo);
}