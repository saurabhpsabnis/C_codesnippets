#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

struct vertex
{
    int val;
    unsigned int index;
    int adj_count;
    struct vertex* adj_vert[100];
};

typedef struct vertex vertex;

typedef struct
{
    unsigned int count;
    vertex** nodes;
}graph;

void create_graph(graph* g,unsigned int count,int* arr);

void add_edge(graph* g,unsigned int u, unsigned int v);
void DFS(graph* g);
void BFS(graph* g);
void print_graph(graph* g);


#endif // GRAPH_H_INCLUDED
