void empty_graph(Adjacency_Matrix *g)
{
    g->size = 0;
    g->matrix = NULL;
}


void init_graph(Adjacency_Matrix *g, int size)
{
    empty_graph(g);
    g->size = size;
    g->matrix = (int**)malloc(g->size * sizeof(int*));
    int i;
    for (i = 0; i < g->size; ++i)
        g->matrix[i] = (int*)malloc(g->size * sizeof(int));

    int j;
    for (i = 0; i < g->size; ++i)
        for (j = 0; j < g->size; ++j)
            g->matrix[i][j] = 0;
}

void free_graph(Adjacency_Matrix *g)
{
    free(g);
}

int add_edge(Adjacency_Matrix *g, int v1, int v2)
{
    if (v1 >= 0 && v1 < g->size && v2 >= 0 && v2 < g->size && g->matrix[v1][v2] == 0) {
        g->matrix[v1][v2] = 1;
        g->matrix[v2][v1] = 1;
        return 0;
    }
    return -1;
}

int remove_edge(Adjacency_Matrix *g, int v1, int v2)
{
    if (v1 >= 0 && v1 < g->size && v2 >= 0 && v2 < g->size && g->matrix[v1][v2] > 0) {
        g->matrix[v1][v2] = 0;
        g->matrix[v2][v1] = 0;
        return 0;
    }
    return -1;
}

int exists_edge(Adjacency_Matrix *g, int v1, int v2)
{
    return g->matrix[v1][v2] > 0;
}

void add_vertex(Adjacency_Matrix *g, int v)
{
    if (g->matrix == NULL) {
        init_graph(g, v);
    }
    else {
        int i, j;
        g->size += v;
        g->matrix = (int **)realloc(g->matrix, g->size * sizeof(int *));

        for (i = 0; i < g->size - v; ++i)
            // realloc the part of the matrix which were used before
            g->matrix[i] = (int *)realloc(g->matrix[i], g->size * sizeof(int));

        for (; i < g->size; ++i)
            g->matrix[i] = (int *)malloc(g->size * sizeof(int));

        for (i = 0; i < g->size; ++i) {
            for (j = g->size - v; j < g->size; ++j) {
                g->matrix[i][j] = 0;
                g->matrix[j][i] = 0;
            }
        }
    }
}

void print_graph(Adjacency_Matrix *g)
{
    int i, j;
    for (i = 0; i < g->size; ++i) {
        for (j = 0; j < g->size; ++j) {
            printf("[%d]", g->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_dfs(Adjacency_Matrix *g)
{
    int *visited = (int *)malloc(g->size * sizeof(int));
    for (int i = 0; i < g->size; ++i)
        visited[i] = 0;

    dfs_recursive(g, visited, 1);
}

void dfs_recursive(Adjacency_Matrix *g, int *visited, int i)
{
    printf("%d\n", i);
    visited[i] = 1;

    for (int j = 0; j < g->size; j++) {
        if (!visited[j] && exists_edge(g, i, j))
            dfs_recursive(g, visited, j);
    }
}


void dfs(Adjacency_Matrix *g)
{
    int start = 1;
    Stack stack = stack_create();
    stack_push(stack, start);
    int* visited = (int *)malloc(g->size * sizeof(int));
    for (int i = 0; i < g->size; ++i)
        visited[i] = 0;

    while (!stack_is_empty(stack)) {
        int i = stack_pop(stack);

        if (!visited[i]) {
            printf("%d\n", i);
            visited[i] = 1;
        }

        for (int j = 0; j < g->size; j++) {
            if (!visited[j] && exists_edge(g, i, j))
                stack_push(stack, j);
        }
    }
}

void bfs(Adjacency_Matrix *g)
{
    Queue q = queue_create();
    int* visited = (int *)malloc(g->size * sizeof(int));
    for (int i = 0; i < g->size; ++i)
        visited[i] = 0;

    int start = 1;
    enqueue(q, start);
    while (!is_empty(q)) {
        int v = dequeue(q);

        if (!visited[v]) {
            printf("%d\n", v);
            visited[v] = 1;
        }

        for (int i = 0; i < g->size; ++i) {
            if (!visited[i] && exists_edge(g, v, i)) {
                enqueue(q, i);
            }
        }
    }
}
