#ifndef UF_H_
#define UF_H_

#include <stdbool.h>

static int id[100];
static int N;

/// @brief Initialize an array with given size
/// @param size 
void uf_init(int size);

/// @brief Make a union between p and q
/// @param p 
/// @param q 
void uf_union(int p, int q);

/// @brief Find the p id
/// @param p 
/// @return p's id
int uf_find(int p);

/// @brief Verify if p is connected with q
/// @param p 
/// @param q 
/// @return True if is connected, False else
bool uf_connected(int p, int q);


/// @brief Print the whole connections
void uf_print();

#endif // !UF_H_
