/*
 * DiaGraph.hh
 *
 *  Created on: Mar 26, 2019
 *      Author: erasunn
 */

#ifndef DIAGRAPH_HH_
#define DIAGRAPH_HH_

#include <trace.hh>
#include <Graphs.hh>

class DiaGraph: public Graph
{
public:
    DiaGraph(int size):Graph(size)
    {
    	method(__func__);
    }
    virtual void addEdge(int orgin, int dest, int weight = 1);
protected:
    virtual void resizeMatrix(int size);
};



#endif /* DIAGRAPH_HH_ */
