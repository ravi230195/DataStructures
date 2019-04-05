/*
 * DiaAdjListGraph.hh
 *
 *  Created on: Mar 31, 2019
 *      Author: erasunn
 */

#ifndef ADJLIST_INCL_DIAADJLISTGRAPH_HH_
#define ADJLIST_INCL_DIAADJLISTGRAPH_HH_

#include <AdjListGraph.hh>

#include <IGraph.hh>
#include <list>
#include <map>
#include <trace.hh>

namespace AdjListGraph
{
class DiaGraph: public AdjListGraph::Graph
{

public:
	DiaGraph(int node_size):AdjListGraph::Graph(node_size, true){};
    virtual ~DiaGraph()
	{
		method(__func__);
	}
};
}



#endif /* ADJLIST_INCL_DIAADJLISTGRAPH_HH_ */
