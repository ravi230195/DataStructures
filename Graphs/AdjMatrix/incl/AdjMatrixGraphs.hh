/*
 * Graphs.hh
 *
 *  Created on: Mar 25, 2019
 *      Author: erasunn
 */

#ifndef GRAPHS_HH_
#define GRAPHS_HH_

#include <stdio.h>
#include <stddef.h>
#include <IGraph.hh>

namespace AdjMatrix
{
class Graph: public IGraph
{
protected:
    int max_size;
    int** AdjMatrix = NULL;
    int matrix_size;

    virtual void resizeMatrix(int size);

    int** createAdjMatrix(int size);
    void deleteMatrix(int size, int** matrix);
public:
    Graph(int Node);
    virtual ~Graph()
    {
    	deleteMatrix(matrix_size, AdjMatrix);
    }
    virtual void addNode();
    virtual void deleteNode(int Node){};
    virtual void display();
    virtual void addEdge(int orgin, int dest, int weight = 1);
};
}

#endif /* GRAPHS_HH_ */
