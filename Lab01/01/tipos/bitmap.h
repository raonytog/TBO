/** Define um TAD representando um mapa de bits.
 * @file bitmap.h
 * @author Joao Paulo Andrade Almeida (jpalmeida@inf.ufes.br)
 */

#ifndef BITMAP_H_
#define BITMAP_H_

/**
 * Estrutura para representar um mapa de bits.
 */
typedef struct map bitmap;

unsigned char* bitmapGetContents(bitmap* bm);
unsigned long int bitmapGetMaxSize(bitmap* bm);
unsigned long int bitmapGetLength(bitmap* bm);
bitmap* bitmapInit(unsigned long int max_size);
unsigned char bitmapGetBit(bitmap* bm, unsigned long int index);
void bitmapSetBit(bitmap* bm, unsigned long int index, unsigned char bit);
void bitmapAppendLeastSignificantBit(bitmap* bm, unsigned char bit);
void bitmapLibera (bitmap* bm);

#endif /*BITMAP_H_*/
