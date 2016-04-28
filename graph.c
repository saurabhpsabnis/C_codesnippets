

#include <stdio.h>
#include <malloc.h>
#include "graph.h"


void create_graph(graph* g,unsigned int count,int* arr)
{
    int i;
    g->nodes = (vertex**)malloc(count*sizeof(vertex*));
    g->count = count;
    for(i=0;i<count;i++)
    {
        g->nodes[i] = (vertex*)malloc(sizeof(vertex));
        g->nodes[i]->val = arr[i];
        g->nodes[i]->adj_count=0;
        g->nodes[i]->index=i;
    }
}

void add_edge(graph* g,unsigned int u, unsigned int v)
{
    int i;
    for(i=0;i<g->nodes[u]->adj_count;i++)
    {
        if(g->nodes[u]->adj_vert[i] == g->nodes[v])
        {
            printf("\n \n Edge already present %d --> %d",u,v);
            return;
        }
    }
    g->nodes[u]->adj_vert[g->nodes[u]->adj_count] = g->nodes[v];
    g->nodes[u]->adj_count++;
}

static void DFS_node(vertex* node,int*  visited)
{
    int i;
    printf("\n\t%d %d",node->index,node->val);
    visited[node->index]=1;
    for(i=0;i<node->adj_count;i++)
    {
        if(!visited[node->adj_vert[i]->index])
        {
            DFS_node(node->adj_vert[i],visited);
        }
    }
}

void DFS(graph* g)
{
    int *visited = (int*)malloc(g->count*sizeof(int));
    int i;

    for(i=0;i<g->count;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<g->count;i++)
    {
        if(!visited[i])
        {
            DFS_node(g->nodes[i],visited);
        }
    }
    free(visited);
}

void BFS(graph* g)
{
    int i,j,k;
    int *visited = (int*)malloc(g->count*sizeof(int));
    vertex** queue =(vertex**)malloc(10*g->count*sizeof(vertex*));
    vertex* v;
    unsigned int head=0,tail=0;

    for(i=0;i<g->count;i++)
    {
        visited[i]=0;
    }

    for(i=0;i<g->count;i++)
    {
        head=0;tail=0;
        if(!visited[g->nodes[i]->index])
        {
            queue[tail] = g->nodes[i];
            tail++;
            visited[g->nodes[i]->index] = 1;
        }
        while(head < tail)
        {
            //printf("\n h %d t %d q ",head,tail);
          //  for(k=head;k<tail;k++)
           //     printf(" %d",queue[k]->val);
            v = queue[head];
            head++;
            printf(" \n \t %d %d",v->index,v->val);
            for(j=0;j<v->adj_count;j++)
            {
                if(!visited[v->adj_vert[j]->index])
                {
                    queue[tail] = v->adj_vert[j];
                    tail++;
                    visited[v->adj_vert[j]->index] = 1;
                }
            }
        }
    }
}

void print_graph(graph* g)
{
    int i,j;
    printf("\n\n\t Graph : adjecency List");
    for(i=0;i<g->count;i++)
    {
       printf("\n node: %d",g->nodes[i]->val);
       printf("\t index %d adj: %d",g->nodes[i]->index,g->nodes[i]->adj_count);
       for(j=0;j<g->nodes[i]->adj_count;j++)
       {
           printf("\t%d",g->nodes[i]->adj_vert[j]->val);
       }
    }
}
