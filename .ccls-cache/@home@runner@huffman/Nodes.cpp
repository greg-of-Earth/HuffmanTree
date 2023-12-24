#include "Nodes.h"

//Constructor
Node::Node(char n_c, int n_freq, Node* n_left, Node* n_right){
  c=n_c;
  freq=n_freq;
  leftLeaf=n_left;
  rightLeaf=n_right;
}

void Node::SetNode(char n_c, int n_freq, Node* n_left, Node* n_right){
  c=n_c;
  freq=n_freq;
  leftLeaf=n_left;
  rightLeaf=n_right;
}



char Node::GetChar() const{
  return c;
}

Node* Node::GetLeft() const{
  return leftLeaf;
}

Node* Node::GetRight()const{
  return rightLeaf;
}

int Node::GetFreq() const {
  return freq;
}


