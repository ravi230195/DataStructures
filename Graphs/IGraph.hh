/*
 * IGraph.hh
 *
 *  Created on: Mar 26, 2019
 *      Author: erasunn
 */

#ifndef IGRAPH_HH_
#define IGRAPH_HH_

class IGraph
{
public:
    virtual void addNode() = 0;
    virtual void deleteNode(int Node) =0;
    virtual void display() = 0;
    virtual void addEdge(int orgin, int dest, int weight = 1) = 0;
	virtual ~ IGraph()
	{};

	// Graphs search Algo
	virtual void BFS(int s, int level =0) = 0;
};




#endif /* IGRAPH_HH_ */
