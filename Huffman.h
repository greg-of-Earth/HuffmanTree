#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <map>
using namespace std;
#include <queue>
#include "Nodes.h"
#include <map>



class Huffman{
  public:
    Huffman(string inpStr = "", Node* root = nullptr, string result = "", map<char, int> charsCnt = map<char, int>(), map<char, string> ouput = map<char, string>());

    ~Huffman() = default;
    void DestroyTree(Node*);

   //prioirty queue sort argument
    struct CompareNodesByFrequency {
      bool operator()(const Node* a, const Node* b) const {
        return a->GetFreq() > b->GetFreq();
      }
    };

    void MapValues();
    int GetSize() const;
    Node* BuildParent(priority_queue<Node*, vector<Node*>,CompareNodesByFrequency> &pq);
    void ConvertToNode();
    void Compress(Node*, string&);
    void Decompress(const string&);
    void PrintEncoded();
    void PrintCompressed();
    void PrintDecompressed();

  private:
    string inpStr;
    map<char, int> charsCnt;
    map<char, string> output;
    int strSze;  
    string result;
    Node* root;
};

#endif