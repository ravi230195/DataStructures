/*
 * DiaGraph.cc
 *
 *  Created on: Mar 26, 2019
 *      Author: erasunn
 */

#include <iostream>
#include <stdio.h>
#include "DiaGraph.hh"
#include "trace.hh"

void
DiaGraph::resizeMatrix(int size)
{
	method(__func__);
	int** new_adjMatrix = createAdjMatrix(2*size);
	for(int i = 0; i<size;i++)
	{
		for(int j = 0; j<size;j++)
		{
			//cout <<"i "<<"j "<<i<<j<<endl;
			new_adjMatrix[i][j] = AdjMatrix[i][j];
		}
	}
	deleteMatrix(size, AdjMatrix);
	AdjMatrix = new_adjMatrix;
}

void
DiaGraph::addEdge(int origin, int dest, int weight)
{
	method(__func__);
	bool isValid = origin < 0 || dest < 0 || origin > max_size || dest > max_size;
	if (origin == dest || isValid)
		return;
	else
	{
		AdjMatrix[origin][dest] = weight;
	}
}

