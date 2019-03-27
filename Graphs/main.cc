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

int main()
{

	IGraph* graph = new EdgeListGraph::DiaEgdeListGraph(3);
	graph->addEdge(0,1,4);
	graph->addEdge(0,2,5);
	graph->addEdge(1,2,41);
	graph->display();
	graph->addNode();
	graph->addNode();
	graph->addNode();
	graph->addNode();
	graph->addNode();
	graph->display();
	return 0;
}


