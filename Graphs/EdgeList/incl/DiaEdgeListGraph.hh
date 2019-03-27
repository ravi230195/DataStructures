/*
 * DaiEdgeListGraph.hh
 *
 *  Created on: Mar 27, 2019
 *      Author: erasunn
 */

#ifndef EDGELIST_INCL_DAIEDGELISTGRAPH_HH_
#define EDGELIST_INCL_DAIEDGELISTGRAPH_HH_
#include <trace.hh>
#include <EdgeListGraph.hh>

namespace EdgeListGraph
{
class DiaEgdeListGraph:public EdgeListGraph::Graph
{
public:

	DiaEgdeListGraph(int size):EdgeListGraph::Graph(size, true)
	{
		method(__func__);
	}
};
}


#endif /* EDGELIST_INCL_DAIEDGELISTGRAPH_HH_ */
