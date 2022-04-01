#ifndef vetor_double_h
#define vetor_double_h

#undef vetor_h
#undef TIPADO
#undef IO_FORMATO
#undef TIPO

#define TIPADO(COISA) DOUBLE_##COISA
#define IO_FORMATO "%.2f"
#define TIPO double

#include "vetor.h" 

#endif