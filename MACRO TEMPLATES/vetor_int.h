#ifndef vetor_int_h
#define vetor_int_h

#undef vetor_h
#undef TIPADO
#undef IO_FORMATO
#undef TIPO

#define TIPADO(COISA) INT_##COISA
#define IO_FORMATO "%d"
#define TIPO int

#include "vetor.h"

#endif