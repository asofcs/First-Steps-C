/*****************************************************************/
/*       GRID STUDENT  | Linked List based | asofcs | 2024       */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <grid.h>


#define ERRORPTR NULL


grid *createGrid(int size)
{
    if (size < 1)
    {
        return ERRORPTR;
    }
    
    grid *g = ERRORPTR;
    g = (grid*)malloc(sizeof(grid));
    
    if (g == ERRORPTR)
    {
        return ERRORPTR;
    }
    
    g->size = size;
    g->adj = (gridEdge **)malloc((size*sizeof(gridEdge*)));
    
    if (g->adj == ERRORPTR)
    {
        free(g);
        g = ERRORPTR;
        return ERRORPTR;
    }
    
    for (int i = 0; i < size; i++)
    {
        g->adj[i] = ERRORPTR;
    }
    
    return g;
}

void destroyGrid(grid *g)
{
    if (g != ERRORPTR)
    {
        for (int i = 0; i < g->size; i++)
        {
            if (g->adj[i] != ERRORPTR)
            {
                free(g->adj[i]);
            }
        } 
        
        free(g->adj);
        g->size = 0;
        free(g);
        g = ERRORPTR;
        
        printf("\n\n\tMEMORY FREED WITH SUCCESS!\n\n");
    }
}

gridEdge *createEdge(int src, int dst)
{
    if(src < 0  || dst < 0)
    {
        return ERRORPTR;
    }
    
    gridEdge *node = (gridEdge*)malloc((sizeof(gridEdge)));
    
    if (node == ERRORPTR)
    {
        return ERRORPTR;
    }
    node->src = src;
    node->dest = dst;
    node->value = 1;
    
    return node;
}

void addDirectedEdge(grid *g, int src, int dst)
{
    gridEdge *node = createEdge(src, dst);
    
    if(node != ERRORPTR)
    {
        node->next = g->adj[src];
        g->adj[src] = node;
    }
}

void addUndirectedEdge(grid *g, int src, int dst)
{
    addDirectedEdge(g,src, dst);
    addDirectedEdge(g, dst, src);
}

void printGrid(grid *g)
{
    if(g != ERRORPTR)
    {

        for(int i = 0; i < g->size; i++)
        {
            gridEdge *head = g->adj[i];
            
            printf("Source vertex %d is connected to ", i);
            while(head)
            {
                printf(" %d[%d] ", head->dest, head->value);
                head = head->next;
            }
            printf("\n");
        }
    }
}