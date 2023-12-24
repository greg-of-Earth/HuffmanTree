#ifndef PRIORITY_H
#define PRIORITY_H
#include <map>
#include <string>
#include <vector>
#include "Nodes.h"
#include <algorithm>
using namespace std;

//max string size 
const int MAX = 50;

class PriorityQ {
public:
  PriorityQ(int QSize = 0, vector<Node> pq = vector<Node>());
  void EnQ(const Node&);
  LeafNode DeQ();
  int GetQSize();
  bool IsEmptyQ() const;
  void HeapUp(int);
  void HeapDwn(int);
  int GetProcCnt() const;

  friend class Huffman;
  friend class Node;

  void Print();

private:
  int QSize;  
  vector<Node> pq;

  int procCnt;
};

#endif