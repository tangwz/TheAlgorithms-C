void run_all_tests()
{
    test_adjacency_matrix();
    // test_adjacency_matrix_dfs();
}

void test_adjacency_matrix()
{
    Adjacency_Matrix* graph = (Adjacency_Matrix *)malloc(sizeof(Adjacency_Matrix));
    int size = 10;
    init_graph(graph, size);

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 5);
    add_edge(graph, 5, 6);
    //print_graph(graph);
    //print_dfs(graph);
    //dfs(graph);
    bfs(graph);
}
