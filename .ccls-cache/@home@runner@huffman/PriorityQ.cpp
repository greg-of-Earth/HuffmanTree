#include "PriorityQ.h"
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;


//constructor
PriorityQ::PriorityQ(int n_size, vector<Node> pq){
  QSize = 0;
  procCnt = 0;
  }

// add new items to priority queue
// post: first places new element at end of array (last position of heap) and then bubbles up to create min heap structure by calling HeapUp()
void PriorityQ::EnQ(const Node& n_Node){
      pq.push_back(n_Node);
      HeapUp(pq.size()-1);
      QSize++;  
  }

// ensure order of min heap by bubbling up min values 
void PriorityQ::HeapUp(int indx){
  int parentIndx = floor((indx-1)/2);

  while(indx>0){
  if(pq[indx].GetFreq() < pq[parentIndx].GetFreq()) {
    swap(pq[indx], pq[parentIndx]);
    }
    indx=parentIndx;
    parentIndx = floor(indx/2);    
  }
}

//ensures priority ranking and heap order during deque by bubbling down
//bubbled down into position to maintain order 
void PriorityQ::HeapDwn(int indx) {
    int chldIndx = 2 * indx + 1; 

    while (chldIndx < QSize) {
        // Compare the children
        if (chldIndx + 1 < QSize && 
            (pq[chldIndx + 1].GetFreq() < pq[chldIndx].GetFreq() || 
             (pq[chldIndx + 1].GetFreq() == pq[chldIndx].GetFreq() && pq[chldIndx + 1].GetChar() < pq[chldIndx].GetChar()))) {
            chldIndx++;
        }

        // Compare the selected child with the parent
        if (pq[chldIndx].GetFreq() < pq[indx].GetFreq() || 
            (pq[chldIndx].GetFreq() == pq[indx].GetFreq() && pq[chldIndx].GetChar() < pq[indx].GetChar())) {
            swap(pq[indx], pq[chldIndx]);
            indx = chldIndx;
            chldIndx = 2 * indx + 1; 
        } else {
          break; // The min-heap property is satisfied
      }
    }
}

// ensures structure of heap 
// when item is dequed, last item in array (last of heap) is put as the root and passed to HeapDwn() to be put into positon 
LeafNode PriorityQ::DeQ() {
   // while (QSize > 0) {
        LeafNode minPair = pq[0]; // Get the top (min) pair

        //cout << "Character: " << minPair.GetChar() << ", Frequency: " << minPair.GetFreq() << endl;

        pq[0] = pq[QSize - 1]; // Replace the top element with the last element
        HeapDwn(0);

        QSize--;
        procCnt++;
   // }
  return minPair;
}

//Get size of priorityQ
int PriorityQ::GetQSize(){
  return QSize;
}

//check if priorityQ is empty
bool PriorityQ::IsEmptyQ() const{
  return QSize==0; 
}

// track values processed 
int PriorityQ::GetProcCnt() const {return procCnt;}

// print priorityQ
void PriorityQ::Print() {
    cout << "Priority queue:\n";
    while (!IsEmptyQ()) {
        DeQ(); 
    }
}

