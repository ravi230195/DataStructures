/*
 * EdgeListGraph.hh
 *
 *  Created on: Mar 26, 2019
 *      Author: erasunn
 */

#include <iostream>
#include <stdio.h>
#include "EdgeListGraph.hh"
#include "trace.hh"
#include <IGraph.hh>
#include <list>
#include <vector>
#include <map>

using namespace EdgeListGraph;
using namespace std;
Graph::Graph(int size, bool isDirect):nodeSize(size),isDirectional(isDirect)
{
	method(__func__);
}

void
Graph::addEdge(int orgin, int dest, int weight)
{
	method(__func__);
	int* array = new int[3]();
	array[0] = orgin;
	array[1] = dest;
	array[2] = weight;
	edgeList.push_back(array);
}

void
Graph::display()
{
	method(__func__);
	list<int*>::iterator it = edgeList.begin();
	for(;it!= edgeList.end();++it)
	{
		cout<<(*it)[0]<<"-----"<<(*it)[1]<<"("<<(*it)[2]<<")"<<endl;
		if (!isDirectional)
			cout<<(*it)[1]<<"-----"<<(*it)[0]<<"("<<(*it)[2]<<")"<<endl;
	}
}

void
Graph::addNode()
{
	method(__func__);
	++nodeSize;
}
