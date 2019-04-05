/*
 * IGraphAlgo.hh
 *
 *  Created on: Apr 1, 2019
 *      Author: erasunn
 */

#ifndef IGRAPHALGO_HH_
#define IGRAPHALGO_HH_

#include <IGraph.hh>

class IGraphAlgo : public IGraph
{
public:
	virtual ~IGraphAlgo()
	{

	}

	// Graphs search Algo
	virtual void BFS(int s, int level =0) = 0;
	virtual void DFS(int s = 0) = 0;

	/* detect
	 *  1. Tree Edge,
	 *  2. BackTrack Edge,
	 * 	3. Forward Edges,
	 *	4. cross edges
	 */
	virtual void detectEdges() = 0;
	/*
	 * Shortest Path Algos
	 *
	 */
	virtual void dijkstra(int s = 0) = 0;
};


#endif /* IGRAPHALGO_HH_ */
