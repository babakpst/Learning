
/*
===============================================================================
Developer: Babak Poursartip

Course III:     Greedy algorithm
Assignment I:   cluster
Data:           05/25/2020
===============================================================================
*/

// libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// classes
#include "../include/module_1/cluster.h"
#include "../include/module_1/message.h"

int main() {

  message m;
  int mod;
  int nCluster = 4; // input

  m.pt("course III - assingnment II: cluster ");

  // reading the graph from the input file
  std::fstream inpGraph; // input file handler
  inpGraph.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {

    if (DEB) {
      inpGraph.open("input/clustering_test2.txt", std::ios::in);
      mod = 1;
    } else {
      inpGraph.open("input/clustering1.txt", std::ios::in);
      mod = 1;
    }
  } catch (std::ifstream::failure &inputerr) { // catch for the input file
    m.pt(" Error while opening the input file!!! ");
    m.pt(" The error message is: ");
    m.pt(inputerr.what());
    throw inputerr;
  }

  int nV; // no. of Vertices

  inpGraph >> nV;
  m.pti(" vertices: ", nV);

  cluster cl(nV, nCluster);

  int u, v, w;
  for (int i = 0; i < nV - 1; ++i) {
    for (int j = i + 1; j < nV; ++j) {
      inpGraph >> u >> v >> w;
      cl.pushEdge(u - mod, v - mod, w, i, j);
    }
  }

  m.pt("here is the input:");
  // if (DEB)
  cl.print();

  cl.findClusters();

  cl.clusterRenumber();
  cl.findDist();
  cl.printCluster();
  cl.findDist();

  m.pt("End of the code!");
  return 0;
}
