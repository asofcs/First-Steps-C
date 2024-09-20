/*****************************************************************/
/*       GRID STUDENT  | Linked List based | asofcs | 2024       */
/*****************************************************************/

#ifndef GRID_H

/*
 * Stores the source vertice, the destiny vertice, value (1 if it exists), and pointer for the next edge. 
 */
typedef struct GridEdge
{
    int src;
    int dest;
    int value;
    struct GridEdge *next;
}gridEdge;

/*
 * Stores the total size/vertices and the linked list of adjacencies. 
 */
typedef struct{
    int size;
    gridEdge **adj;
}grid;

/*
 * Create an empty grid/graph with size possible vertices. 
 * return: IF VALID: pointer to the new grid. ELSE: NULL.
 */
grid *createGrid(int size);

/*
 * Delete grid and free all memory IF it is not NULL.
 */
void destroyGrid(grid *g);

/*
 * Add an edge to the grid
 * return: IF VALID: pointer to the new edge. ELSE: NULL.
 */
gridEdge *createEdge(int src, int dst);

/*
 * Add an directed edge to the grid
 */
void addDirectedEdge(grid *g, int src, int dst);

/*
 * Add an undireted edge to the grid
 */
void addUndirectedEdge(grid *g, int src, int dst);


/*
 * Print the grid
 */
void printGrid(grid *g);


#define GRID_H
#endif
