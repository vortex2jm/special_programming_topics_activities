#ifndef vetor_h
#define vetor_h

#ifdef TIPADO
#ifdef IO_FORMATO
#ifdef TIPO

typedef struct TIPADO(_vetor) TIPADO(tVetor);

TIPADO(tVetor *) TIPADO(CriaVetor)(int tam);
TIPADO(tVetor *) TIPADO(SomaVetores)(TIPADO(tVetor *) vet1, TIPADO(tVetor *) vet2);
TIPADO(tVetor *) TIPADO(MultiplicaVetor)(TIPADO(tVetor *) vector, TIPO constante);

void TIPADO(InserirElemento)(TIPADO(tVetor *) vector, TIPO elemento, int indice);
void TIPADO(ImprimeVetor)(TIPADO(tVetor *) vector); 
void TIPADO(DestroiVetor)(TIPADO(tVetor *) vector);

#endif
#endif
#endif
#endif