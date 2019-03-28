/*
 * AdjListGraph.hh
 *
 *  Created on: Mar 28, 2019
 *      Author: erasunn
 */

#ifndef ADJLIST_INCL_ADJLISTGRAPH_HH_
#define ADJLIST_INCL_ADJLISTGRAPH_HH_


#include <IGraph.hh>
#include <list>
#include <map>
#include <trace.hh>

namespace AdjListGraph
{
class Graph: public IGraph
{
	int nodeSize;
	std::list<int*>* AdjList;
	bool isDirectional;
	int adjListSize;
	void resize(int size);
public:
	Graph(int node_size, bool isDirectional = false );
    virtual ~Graph()
	{
		method(__func__);
	}
    virtual void addNode();  // to be done
    virtual void deleteNode(int Node){}; //to be done
    virtual void display();
    virtual void addEdge(int orgin, int dest, int weight = 1);
    virtual void BFS(int s, int level = 0);

};
}


#endif /* ADJLIST_INCL_ADJLISTGRAPH_HH_ */
