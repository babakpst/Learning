
/*
===============================================================================
Developer: Babak Poursartip
Data:      05/29/2020
class:     cluster related methods
===============================================================================
*/

// libraries
#include <algorithm> // std::for_each
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>


// classes
#include "../../include/module_1/message.h"

#ifndef CLUSTER_H
#define CLUSTER_H

class cluster {

  // members
private:
  message m;
  int nVertices;      // no. of vertices in the graph
  int nCluster;       // no. of desires clusters
  int currentCluster; // no. of current clusters
  std::multimap<int, std::pair<int, int>> inpGraph;
  std::vector<int> clusters;
  int distance = 0;

public:
  // methods
private:
  cluster();

public:
  cluster(const int, const int);

  // pushes a vertix and its corresponding weighted edge
  void pushEdge(const int u, const int v, const int w, const int i,
                const int j);

  void print();
  void printCluster();
  void findClusters();
  void clusterRenumber();
  void numberCluster(const int); // number of clusters-debugging
  void findDist();
  int indexfinder(const int, const int);
};

#endif // ! CLUSTER_H
