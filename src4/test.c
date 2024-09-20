#include <stdio.h>
#include <stdlib.h> 
#include <grid.h>

int main(void)
{
    grid *g = NULL;
    
    g = createGrid(4);
    
    if(g !=  NULL)
    {
        printf("\n\n\tMEMORY ALLOCATED WITH SUCCESS!\n\n");
    }
    else
    {
        exit(1);
    }
    
    addUndirectedEdge(g, 0, 1);
    addUndirectedEdge(g, 0, 2);
    addUndirectedEdge(g, 1, 2);
    addUndirectedEdge(g, 2, 3);
    printGrid(g);
    destroyGrid(g);
    
    return 0;
}
