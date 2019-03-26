/*
 * Graphs.cc
 *
 *  Created on: Mar 25, 2019
 *      Author: erasunn
 */

#include <iostream>
#include <stdio.h>
#include "Graphs.hh"
#include "trace.hh"

using namespace std;

Graph::Graph(int Node):max_size(Node)
    {
	   method(__func__);
       cout<<"Number of Node in graph "<< max_size<<endl;
       AdjMatrix = createAdjMatrix(max_size);
    }

int**
Graph::createAdjMatrix(int size)
{
	method(__func__);
	matrix_size = size;
	cout<<"Matrix size "<<matrix_size<<endl;
	int ** matrix = new int*[matrix_size];
	for (int i = 0; i <size ; i++)
	{
		matrix[i] = new int[matrix_size]();
	}
    return matrix;
}


void
Graph::deleteMatrix(int size, int** matrix)
{
	method(__func__);
	cout<<"mat size "<<size<<endl;
	for(int i=0 ; i<size;i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

void
Graph::resizeMatrix(int size)
{
	method(__func__);
	int** new_adjMatrix = createAdjMatrix(2*size);
	for(int i = 0; i<size;i++)
	{
		for(int j = i; j<size;j++)
		{
			//cout <<"i "<<"j "<<i<<j<<endl;
			new_adjMatrix[i][j] = AdjMatrix[i][j];
			new_adjMatrix[j][i] = AdjMatrix[i][j];
		}
	}
	deleteMatrix(size, AdjMatrix);
	AdjMatrix = new_adjMatrix;
}

void
Graph::addEdge(int origin, int dest, int weight)
{
	method(__func__);
	bool isValid = origin < 0 || dest < 0 || origin > max_size || dest > max_size;
	if (origin == dest || isValid)
		return;
	else
	{
		AdjMatrix[origin][dest] = weight;
		AdjMatrix[dest][origin] = weight;
	}
}

void
Graph::addNode()
{
	method(__func__);
	//int old_matrixsize = max_size;

	if(matrix_size < max_size + 1)
	{
		resizeMatrix(max_size);
	}
	++max_size;
	//cout<<"matrix size "<<matrix_size<<endl;
	//cout<<"node size "<<max_size<<endl;
}

void
Graph::display()
{
	method(__func__);
	for(int i = 0; i<matrix_size;i++)
	{
		for(int j = 0; j<matrix_size;j++)
		{
			cout<<"  "<<AdjMatrix[i][j];
		}
		cout<<endl;
	}
}
