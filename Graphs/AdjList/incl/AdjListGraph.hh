/*
 * AdjListGraph.hh
 *
 *  Created on: Mar 28, 2019
 *      Author: erasunn
 */

#ifndef ADJLIST_INCL_ADJLISTGRAPH_HH_
#define ADJLIST_INCL_ADJLISTGRAPH_HH_


#include <IGraphAlgo.hh>
#include <list>
#include <map>
#include <trace.hh>

namespace AdjListGraph
{
class Graph: public IGraphAlgo
{
	int nodeSize;
	std::list<int*>* AdjList;
	bool isDirectional;
	int adjListSize;
	void resize(int size);

	void BFS(int s, int level, std::map<int,int>& nodeLevelVisitedMap, std::map<int,int>& parentNodeMap);
	void DFS(int s, std::map<int,int>& nodeVisitedMap);
	void printMap(std::map<int,int>& mapObject);
	void printMap(std::multimap<int,int>& mapObject);
	void detectEdges(int s, std::map<int,int>& nodeVisitedMap, std::multimap<int,int>& BackTrackMap,
			                std::multimap<int,int>& ForwardMap, std::multimap<int,int>& crossMap, std::map<int,int>& counterMap, int& counter);
	std::map<int,int>::iterator findMinInPaths(std::map<int,int>& v);
	void relaxEdges(int u, int& v, int w);

public:
	Graph(int node_size, bool isDirectional = false );
    virtual ~Graph()
	{
		method(__func__);
	}
    virtual void addNode();
    virtual void deleteNode(int Node){}; //to be done
    virtual void display();
    virtual void addEdge(int orgin, int dest, int weight = 1);

    virtual void BFS(int s, int level = 0);
    virtual void DFS(int s = 0);
    virtual void detectEdges();
    virtual void dijkstra(int s = 0);

};
}


#endif /* ADJLIST_INCL_ADJLISTGRAPH_HH_ */
