/*
 * AdjListGraph.cc
 *
 *  Created on: Mar 28, 2019
 *      Author: erasunn
 */




#include <iostream>
#include <stdio.h>
#include "AdjListGraph.hh"
#include "trace.hh"
#include <IGraph.hh>
#include <list>
#include <vector>
#include <map>

using namespace AdjListGraph;
using namespace std;

Graph::Graph(int size, bool isDirect):nodeSize(size),isDirectional(isDirect),adjListSize(size)
{
	method(__func__);
	AdjList = new list<int*>[nodeSize];
}

void
Graph::addEdge(int origin, int dest, int weight)
{
	method(__func__);
	bool isValid = origin < 0 || dest < 0 || origin > nodeSize || dest > nodeSize;
	if (origin == dest || isValid)
		return;
	else
	{
		int* listEntry = new int[2];
		listEntry[0] = dest;
		listEntry[1] = weight;
        AdjList[origin].push_back(listEntry);
        if(!isDirectional)
        {
    		int* listEntry = new int[2];
    		listEntry[0] = origin;
    		listEntry[1] = weight;
        	AdjList[dest].push_back(listEntry);
        }

	}
}

void
Graph::display()
{
	method(__func__);

	for(int i = 0; i < nodeSize; ++i)
	{

		list<int*>::iterator it;
		cout<<i<<"---->";
		for (it = AdjList[i].begin(); it!=AdjList[i].end(); ++it)
		{
			cout<<(*it)[0]<<"("<<(*it)[1]<<")"<<" ";
		}
		cout<<endl;
	}
}

void
Graph::addNode()
{
	method(__func__);

	if ((nodeSize + 1) > adjListSize)
	{
		resize(nodeSize);
	}
	++nodeSize;
}

void
Graph::resize(int size)
{
	method(__func__);
    adjListSize = 2*size;
	list<int*>* new_AdjList = new list<int*>[2*size];
	for (int i = 0 ; i < size; ++i)
	{
		new_AdjList[i] = AdjList[i];
	};
	delete [] AdjList;
	AdjList = new_AdjList;
}

void
Graph::BFS(int s, int level)
{
	static map<int,int> nodeLevelVisitedMap;
	if (nodeLevelVisitedMap.find(s) == nodeLevelVisitedMap.end())   // for the first time
	{
		nodeLevelVisitedMap[s] = level;
	}
	cout<<s<<"--->"<<level<<endl;
	list<int*>::iterator it = AdjList[s].begin();
	++level;
	vector<int> adjcentNode;
	for(;it != AdjList[s].end(); ++it)
	{
		if (nodeLevelVisitedMap.find((*it)[0]) == nodeLevelVisitedMap.end())
		{
			nodeLevelVisitedMap[(*it)[0]] = level;
			adjcentNode.push_back((*it)[0]);
		}
	}
    if (adjcentNode.empty())
    	return;
    int size = adjcentNode.size();
	for (int i = 0; i<size;++i)
	{
		//cout<<adjcentNode[i]<<endl;
		BFS(adjcentNode[i], level);
	}
}

