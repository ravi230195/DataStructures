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

int main()
{

	IGraph* graph = new AdjListGraph::Graph(4);
	graph->addEdge(0,1);
	graph->addEdge(0,2,21);
	graph->addEdge(1,2,41);
	graph->addEdge(0,3,31);
	graph->display();
	graph->addNode();
	graph->addEdge(3,4,41);
	graph->addNode();
	graph->addEdge(3,5,51);
	graph->addNode();
	graph->addEdge(3,6,61);
	graph->addNode();
	graph->addNode();
	graph->addNode();
	graph->addNode();
	graph->display();
	graph->BFS(4);
	return 0;
}


