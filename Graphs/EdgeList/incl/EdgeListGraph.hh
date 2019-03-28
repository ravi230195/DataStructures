/*
 * EdgeListGraph.hh
 *
 *  Created on: Mar 26, 2019
 *      Author: erasunn
 */

#ifndef EDGELIST_INCL_EDGELISTGRAPH_HH_
#define EDGELIST_INCL_EDGELISTGRAPH_HH_

#include <IGraph.hh>
#include <list>
#include <trace.hh>

namespace EdgeListGraph
{
class Graph: public IGraph
{
	int nodeSize;
	std::list<int*> edgeList;
	bool isDirectional;
public:
	Graph(int node_size, bool isDirectional = false );
    virtual ~Graph()
	{
		method(__func__);
	}
    virtual void addNode();
    virtual void deleteNode(int Node){};
    virtual void display();
    virtual void addEdge(int orgin, int dest, int weight = 1);

    virtual void BFS(int s){}   // Not implemented

};
}

#endif /* EDGELIST_INCL_EDGELISTGRAPH_HH_ */
