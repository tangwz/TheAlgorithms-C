#ifndef PROJECT_C_ADJ_MATRIX_H
#define PROJECT_C_ADJ_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
#include "queue.h"
#include "queue.c"

typedef struct {
    int size;
    int** matrix;
} Adjacency_Matrix;

void empty_graph(Adjacency_Matrix *g);
void init_graph(Adjacency_Matrix *g, int size);
void free_graph(Adjacency_Matrix *g);
int add_edge(Adjacency_Matrix *g, int v1, int v2);
int remove_edge(Adjacency_Matrix *g, int v1, int v2);
int exists_edge(Adjacency_Matrix *g, int v1, int v2);
void add_vertex(Adjacency_Matrix *g, int v);
int remove_vertex(Adjacency_Matrix *g, int v);
void print_graph(Adjacency_Matrix *g);
void print_dfs(Adjacency_Matrix *g);
void dfs_recursive(Adjacency_Matrix *g, int *visited, int i);
void dfs(Adjacency_Matrix *g);
void bfs(Adjacency_Matrix *g);


#endif //PROJECT_C_ADJ_MATRIX_H
