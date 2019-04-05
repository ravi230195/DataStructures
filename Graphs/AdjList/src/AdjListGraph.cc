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
#include <algorithm>

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
	method(__func__);
	map<int,int> nodeLevelVisitedMap;
	map<int,int> parentNodeMap;
	BFS(s, level, nodeLevelVisitedMap, parentNodeMap);
	cout<<"node --> level Map"<<endl;
    printMap(nodeLevelVisitedMap);
    cout<<"node --> parent Node Map"<<endl;
    printMap(parentNodeMap);
}


void
Graph::DFS(int s)
{
	method(__func__);
	map<int, int> nodeVisitedMap;
	for(int i =0; i< nodeSize; ++i)
	{
        if (nodeVisitedMap.find(i) == nodeVisitedMap.end()) // to avoid 0 -- 1 sort of cyclic iteration done here.. can be done inside SF also
        {
           nodeVisitedMap[i] = 1010000;
           DFS(i, nodeVisitedMap);
        }

	}
	//cout<<"Tree Edges"<<endl;
	//printMap(nodeVisitedMap);

}


void
Graph::detectEdges()
{
	method(__func__);

	map<int, int> nodeVisitedMap;
	multimap<int,int> BackTrackMap;
	multimap<int,int> ForwardMap;
	multimap<int,int> crossMap;
	map<int, int> counterMap;
	int counter =0 ;

	for(int i =0; i< nodeSize; ++i)
	{

           if (nodeVisitedMap.find(i) == nodeVisitedMap.end()) // to avoid 0 -- 1 sort of cyclic iteration done here.. can be done inside SF also
           {
              nodeVisitedMap[i] = 1010000;
              counterMap[i] = 1010000;
              detectEdges(i, nodeVisitedMap, BackTrackMap, ForwardMap, crossMap, counterMap, counter);
           }

	}
	cout<<"Tree Edges"<<endl;
	printMap(nodeVisitedMap);

	cout<<"Back Edges"<<endl;
	printMap(BackTrackMap);

	cout<<"Forward Edges"<<endl;
	printMap(ForwardMap);

	cout<<"cross Edges"<<endl;
	printMap(crossMap);
}

// DFS Utils
void
Graph::DFS(int s, map<int,int>& nodeVisitedMap)
{

	cout <<s<<endl;
	if (AdjList[s].empty())
		return;
	list<int*>::iterator it = AdjList[s].begin();
	for (; it != AdjList[s].end(); ++it)
	{
         if (nodeVisitedMap.find((*it)[0]) == nodeVisitedMap.end())
         {
        	 nodeVisitedMap[(*it)[0]] = s;
         	 DFS((*it)[0], nodeVisitedMap);
         }
	}
}


// BFS Utils
void
Graph::BFS(int s, int level, map<int,int>& nodeLevelVisitedMap, map<int,int>& parentNodeMap)
{

	if (nodeLevelVisitedMap.find(s) == nodeLevelVisitedMap.end())   // for the first time
	{
		parentNodeMap[s] = 100000;  // Infinte value first node
		nodeLevelVisitedMap[s] = level;
	}
	//cout<<s<<"--->"<<level<<endl;
	list<int*>::iterator it = AdjList[s].begin();
	++level;
	vector<int> adjcentNode;
	for(;it != AdjList[s].end(); ++it)
	{
		if (nodeLevelVisitedMap.find((*it)[0]) == nodeLevelVisitedMap.end())
		{
			parentNodeMap[(*it)[0]] = s;
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
		BFS(adjcentNode[i], level, nodeLevelVisitedMap, parentNodeMap);
	}
}


void
Graph::detectEdges(int s, map<int,int>& nodeVisitedMap, multimap<int,int>& BackTrackMap,
		multimap<int,int>& ForwardMap, multimap<int,int>& crossMap, map<int, int>& counterMap, int& counter)
{
	static list<int> ancestorList;          // To identify BackTrack Edges

    cout <<s<<endl;
	if (AdjList[s].empty())
		return;

	ancestorList.push_back(s);
	++counter;
	list<int*>::iterator it = AdjList[s].begin();

	for (; it != AdjList[s].end(); ++it)
	{
		 //cout<<s<<" "<<(*it)[0]<<" "<<counter<<endl;
         if (nodeVisitedMap.find((*it)[0]) == nodeVisitedMap.end())
         {
        	 nodeVisitedMap[(*it)[0]] = s;
        	 counterMap[(*it)[0]] = counter;
        	 detectEdges((*it)[0], nodeVisitedMap, BackTrackMap, ForwardMap, crossMap, counterMap, counter);
         }

         else if (find(ancestorList.begin(),ancestorList.end(),(*it)[0]) != ancestorList.end())
         {
             // Found a backTracek
        	 // cout << "Found a backTracek"<<endl;
        	 BackTrackMap.insert(pair<int,int>(s,(*it)[0]));
         }

         else if ( counterMap[(*it)[0]] <= counter)
         {
            // Found a cross Edge
        	// cout <<"Found a cross Edge"<< counterMap[(*it)[0]] << " "<< counter<<endl;
        	 crossMap.insert(pair<int,int>(s,(*it)[0]));
         }
         else if (counterMap[(*it)[0]] > counter)
         {
        	 // only left is forward edge
        	 // cout << "only left is forward edge"<< counterMap[(*it)[0]] << " "<< counter<<endl;;
        	 ForwardMap.insert(pair<int,int>(s,(*it)[0]));
         }
         else
         {
            cout<<"error: not a edge"<<endl;
         }

	}
	ancestorList.erase(find(ancestorList.begin(),ancestorList.end(),s));
	--counter;
}

void
Graph::printMap(map<int,int>& mapObject)
{

	map<int,int>::iterator it = mapObject.begin();
	for(; it != mapObject.end(); ++it)
	{
		cout<<it->first<<"-->"<<it->second<<endl;
	}
}


void
Graph::dijkstra(int s)
{
	method(__func__);

	map<int,int> pathsFromA;
	map<int,int> pathsFromAMin;
	map<int, int> parentNode;

	for(int i = 0; i<nodeSize; i++ )
	{
		pathsFromA[i] = 65111; // initialize everything to infinity
	}

	pathsFromA[s] = 0;

    while (!pathsFromA.empty())
    {

    	map<int,int>::iterator smallest = findMinInPaths(pathsFromA);
    	//cout<<"smallest path "<< smallest->first<<" "<<smallest->second<<"size of pathFromA "<<pathsFromA.size()<<endl;

    	if (smallest->second == 65111) // cant be reached from node S so just move it to s;
    	{
    		//cout<<"cant be reached "<<smallest->second<<endl;
    		pathsFromAMin[smallest->first] = smallest->second;
    		pathsFromA.erase(smallest);
    		continue;
    	}

    	pathsFromAMin[smallest->first] = smallest->second;    // move from un relaxed to relaxed nodeMap
    	pathsFromA.erase(smallest);

    	list<int*>::iterator it = AdjList[smallest->first].begin();
    	for (; it!=AdjList[smallest->first].end(); ++it)
    	{
    		//cout<<(*it)[0] << " " <<(*it)[1]<<endl;
    		if (pathsFromA.find((*it)[0]) == pathsFromA.end())   // Incase it is already visited then node
    			continue;                                        //will be removed from pathsFromA; maybe cyclic graph
    		relaxEdges(pathsFromAMin[smallest->first], pathsFromA[(*it)[0]], (*it)[1]);
    	}
    }
    printMap(pathsFromAMin);
}


void
Graph::relaxEdges(int u, int& v, int w)
{
	if( v > (u + w)) // found new shortest path
	{
		v = u + w;
	}
	return;
}

map<int,int>::iterator
Graph::findMinInPaths(map<int,int>& v)         // O(n-1) complexity
{
	typedef map<int,int>::iterator mapIt;
	mapIt first = v.begin();
	mapIt last = v.end();

    if (v.size() == 0)
    	return last;
    if(v.size() == 1)
    {
    	return first;
    }

    int smallest = first->second;
    mapIt smallestIterator = first;
    ++first;
    for (; first != last; ++first) {
        if (first->second < smallest) {
            smallest = first->second;
            smallestIterator = first;
        }
    }
    return smallestIterator;
}

void
Graph::printMap(multimap<int,int>& mapObject)
{

	map<int,int>::iterator it = mapObject.begin();
	for(; it != mapObject.end(); ++it)
	{
		cout<<it->first<<"-->"<<it->second<<endl;
	}
}
