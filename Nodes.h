#ifndef NODES_H
#define NODES_H
#include <map>
#include <string>

using namespace std;


class Node {
public:
    Node(char c = 0, int freq = 0, Node* leftLeaf = nullptr, Node* rightLeaf = nullptr);
    virtual void SetNode(char c, int freq, Node* leftLeaf, Node* rightLeaf) = 0;
    virtual void SetFreq(int freq)=0;
    virtual int GetFreq() const = 0;
    virtual char GetChar() const = 0;
    virtual Node* GetLeft() const = 0;
    virtual Node* GetRight() const = 0;
    virtual ~Node(){};

private:
    Node* leftLeaf;
    Node* rightLeaf;
    char c;
    int freq=0;
    
};


class LeafNode : public Node {
public:
    LeafNode(char c = 0, int freq = 0) : c(c), freq(freq) {}  

    // Implementations for the pure virtual functions
    void SetNode(char c, int freq, Node* leftLeaf, Node* rightLeaf) override {
        void SetNode(char c, int freq);
    }

    virtual ~LeafNode(){};

void SetFreq(int freq) override {
  }

    int GetFreq() const override {
        return freq;
    }

    char GetChar() const override {
        return c;
    }

    Node* GetLeft() const override {
        return nullptr; // Implement as needed
    }

    Node* GetRight() const override {
        return nullptr; // Implement as needed
    }

private:
   char c;
   int freq;
};



class InternalNode : public Node {
  public: 
    InternalNode(int freq=0, Node* leftLeaf=nullptr, Node* rightLeaf= nullptr) : freq(freq), leftLeaf(leftLeaf), rightLeaf(rightLeaf) {}

    void SetNode(char c, int freq, Node* leftLeaf, Node* rightLeaf) override {
      void SetNode(int freq, Node* leftLeaf, Node* rightLeaf);
    }

    virtual ~InternalNode(){};

    void SetFreq(int freq) override {
    }
  
    int GetFreq() const override {
        return freq;
    }

    char GetChar() const override {
        return c;
    }

    Node* GetLeft() const override {
        return leftLeaf; // Implement as needed
    }

    Node* GetRight() const override {
        return rightLeaf; // Implement as needed
    }


  private:
    char c;
    int freq;
    Node* leftLeaf;
    Node* rightLeaf;
};

#endif