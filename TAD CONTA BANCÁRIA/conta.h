#ifndef conta_h
#define conta_h

typedef struct conta tConta;

tConta * CriaConta(char * nome, int cpf, int num);

void Saque(tConta ** conta, int qtd, float valor, int num);

void Deposito(tConta ** conta, int qtd, float valor, int num);

void Transferencia(tConta ** conta, int qtd, int numOrigem, int numDestino, float valor);

void DestroiConta(tConta * conta);

void ImprimeConta(tConta * conta);

void ImprimeContaNoArquivo(tConta * conta, FILE * arquivo);

void ImprimeTodasAsContas(tConta ** conta, int qtd);

void ImprimeRelatorioNoArquivo(tConta ** contas, int qtd, FILE * arquivo);

tConta ** AdicionaConta(tConta ** contas, int tam, char * nome, int cpf, int num);

void ImprimeMovimentacoes(tConta ** contas, int qtd, int numConta, int qtdMov, FILE * arquivo);

void ImprimeContaEspecifica(tConta ** contas, int qtd, int numConta, FILE * arquivo);

void ImprimeExtrato(tConta ** contas, int qtd, int numConta, int qtdMov, FILE * arquivo);

#endif