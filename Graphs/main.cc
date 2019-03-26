/*
 * main.cc
 *
 *  Created on: Mar 25, 2019
 *      Author: erasunn
 */

#include <Graphs.hh>
#include <DiaGraph.hh>
#include <trace.hh>

int main()
{
	Graph* graph = new DiaGraph(3);
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


