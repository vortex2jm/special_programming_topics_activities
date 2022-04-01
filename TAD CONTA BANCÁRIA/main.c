#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main(){

    char nome[50];
    int cpf=0, operacao = -1, numConta = 0, qtdContas = 0;
    float valor=0;
    tConta **contas = (tConta**) malloc(sizeof(tConta*));
    FILE * relatorio, * extrato;

    while(1){

        printf("Digite a operacao que deseja! (0-sair, 1-saque, 2-deposito, 3-transferencia, 4-cadastro, 5-relatorio, 6-extrato)\n");
        scanf("%d", &operacao);

        if(!operacao){            
            break;
        } 

        else if (operacao == 1){

            printf("Escolha o numero da conta que deseja sacar\n\n");
            ImprimeTodasAsContas(contas,qtdContas);
            printf("Numero da conta: ");
            scanf("%d", &numConta);
            printf("\n");
            printf("Digite o valor que deseja sacar: ");
            scanf("%f", &valor);
            Saque(contas, qtdContas, valor, numConta);
        }

        else if(operacao == 2){

            printf("Escolha o numero da conta que deseja depositar\n\n");
            ImprimeTodasAsContas(contas,qtdContas);
            printf("Numero da conta: ");
            scanf("%d", &numConta);
            printf("\n");
            printf("Digite o valor que deseja depositar: ");
            scanf("%f", &valor);
            Deposito(contas, qtdContas,valor, numConta);
        }

        else if(operacao == 3){
            int contaOrigem, contaDestino;
            ImprimeTodasAsContas(contas, qtdContas);
            printf("\nDigite o numero da conta na qual deseja retirar o dinheiro: ");
            scanf("%d", &contaOrigem);
            printf("\nDigite o numero da conta na qual transferir o dinheiro: ");
            scanf("%d", &contaDestino);
            printf("\nQual valor deseja transferir?");
            scanf("%f", &valor);
            Transferencia(contas, qtdContas, contaOrigem, contaDestino, valor);
        }

        else if(operacao == 4){
            
            printf("Digite seu nome, em seguida seu CPF e por ultimo o numero da conta (separados por espaco):\n");
            scanf("%s%*c%d%d", nome, &cpf, &numConta);
        
            contas = AdicionaConta(contas,qtdContas,nome,cpf,numConta);
                     
            qtdContas++;
        }

        else if(operacao == 5){

            printf("\n===| Imprimindo Relatorio |===\n");
            ImprimeTodasAsContas(contas,qtdContas);
            ImprimeRelatorioNoArquivo(contas,qtdContas, relatorio);
        }


        else if(operacao == 6){

            int qtdMov;    
            printf("Digite o numero da conta e a quantidade de movimentacoes que deseja solicitar: ");
            scanf("%d%d", &numConta, &qtdMov);

            ImprimeExtrato(contas, qtdContas, numConta, qtdMov, extrato);
        }

        else printf("Operacao invalida!\n");
    }

    for(int x=0;x<qtdContas;x++){

        DestroiConta(contas[x]);
    }
    free(contas);

    return 0;
}
