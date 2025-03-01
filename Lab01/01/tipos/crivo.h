#ifndef _CRIVO_H_
#define _CRIVO_H_

typedef struct Crivo Crivo;

Crivo *InitCrivo(unsigned long int size);

void FillCrivoArray(Crivo *this_crivo);

void ExecuteCrivo(Crivo *this_crivo);

void PrintCrivoArray(Crivo *this_crivo);

void PrintCrivoPrimes(Crivo *this_crivo);

void DestroyCrivo(Crivo *this_crivo);

#endif