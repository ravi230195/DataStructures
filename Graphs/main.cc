/*
 * main.cc
 *
 *  Created on: Mar 25, 2019
 *      Author: erasunn
 */

#include <AdjMatrixGraphs.hh>
#include <trace.hh>
#include <IGraph.hh>
#include "AdjMatrixDiaGraph.hh"
#include "EdgeListGraph.hh"
#include "DiaEdgeListGraph.hh"
#include "AdjListGraph.hh"
#include "DiaAdjListGraph.hh"


int main()
{

	IGraph* graph = new AdjListGraph::DiaGraph(5);
	graph->addEdge(0,1,7);
	graph->addEdge(0,2,2);
	graph->addEdge(1,3,1);
	graph->addEdge(1,2,2);
	graph->addEdge(2,1,3);
	graph->addEdge(2,3,8);
	graph->addEdge(2,4,5);
	graph->addEdge(3,4,4);
	graph->addEdge(4,3,5);
	graph->display();
	/*graph->addNode();
	graph->addEdge(3,6,51);
	graph->addNode();
	graph->addEdge(6,7,61);
	graph->addEdge(7,5,61);
	graph->addEdge(5,2,31);
	graph->addEdge(4,7,41);*/
	//graph->display();
	//graph->BFS(3);
	//graph->DFS(0);
	//graph->detectEdges();
	graph->dijkstra(0);
	return 0;
}


