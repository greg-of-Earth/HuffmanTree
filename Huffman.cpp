#include "Huffman.h"
#include <map>




//constructor
Huffman::Huffman(string n_inpStr, Node* n_root, string n_result, map<char, int> n_charsCnt, map<char,string> n_output) {
  inpStr = n_inpStr;
  charsCnt = n_charsCnt;
  output = n_output;
  strSze = inpStr.size();
  result = n_result;
  root = n_root;
}

// destructor implicitly constructed 
// Huffman::~Huffman(){
//   if(root!=nullptr){
//     DestroyTree(root);
//   }
// }

// // traverse tree and delete nodes 
// void Huffman::DestroyTree(Node* node){
//   if(node!=root){
//     DestroyTree(node->GetLeft());
//     DestroyTree(node->GetRight());
//     delete node;
//   }
//  root = nullptr;
// }

//create map of chars and their frequencies
void Huffman::MapValues(){
  for(char c : inpStr){
    if(charsCnt.find(c) != charsCnt.end()){
      // char found so increment it value in map
      charsCnt[c]++;
    }else {
      // character not found so add it to map and set value to 1
      charsCnt[c]=1;
    }
  }

  ConvertToNode();
  
  // TEST: print mapped pairs
  // for(const auto& pair : charsCnt){
  //   cout << "mapped pairs are: " << pair.first << " : " << pair.second << endl;
  // }
}


// convert our mapped values to nodes and put them in a priority queue: pq 
void Huffman::ConvertToNode(){
  // declare a priority queue that is defined as a vector that contains pointers of Node type and a comparator function to sort by frequency
  priority_queue<Node*, vector<Node*>, CompareNodesByFrequency> pq;

  // for ever char in map add a node to priority queue
  for(const auto& pair : charsCnt){
    
   //dynamic declaration. CLEAN UP!
    LeafNode* newLeaf = new LeafNode(pair.first, pair.second);
    // PUSH LEAF onto Priority Q. leaf has freq and char
    pq.push(newLeaf);
    
  }
  //TESTING 
  // priority_queue<Node*, vector<Node*>, CompareNodesByFrequency> tempQueue = pq;


  // cout << "Contents of the priority_queue after inserting elements:" << endl;

  // while (!tempQueue.empty()) {
  //     Node* node = tempQueue.top();
  //     tempQueue.pop();

  //     cout << "Char: " << node->GetChar() << ", Freq: " << node->GetFreq() << endl;
  // }
  
  root = BuildParent(pq);
  string prefix = "";
  Compress(root, prefix);
  PrintEncoded();
  PrintCompressed();
  PrintDecompressed();

}

//return size to build array in Q
int Huffman::GetSize() const{
  return strSze;
}



//build priorityQ and Binary Tree
  Node* Huffman::BuildParent(priority_queue<Node*, vector<Node*>, CompareNodesByFrequency> &pq) {
    //InternalNode* root;
    Node* leftNode;
    Node* rightNode;
    Node* parent;
    while (pq.size() > 1) {
      
      leftNode = pq.top();
     // cout << "left node char: " << leftNode->GetChar() << endl;
      pq.pop();
      rightNode = pq.top();
      // cout << "rt node char: " << rightNode->GetChar() << endl;
      pq.pop();
      parent = new InternalNode(leftNode->GetFreq() + rightNode->GetFreq(), leftNode, rightNode);
      //cout << "parent freq: " << parent->GetFreq() << endl;
     // cout << "parent lft: " << parent->GetLeft()->GetFreq() << endl;
      pq.push(parent);
    }
   
    root = parent;
     pq.pop();
    //Node* root = pq.top();
    if (root->GetLeft() != nullptr) {
       // cout << "Character to the left of the root: " << root->GetLeft()->GetChar() << endl;
    } else {
       // cout << "No character to the left of the root." << endl;
    }
   
  return root;
}

void Huffman::Compress(Node* node, string &prefix) {
  
    if (node == nullptr) {
        return; // Handle the case of a null node.
    }

    if (node->GetChar() != 0) {
        // This is a leaf node, assign the prefix to the character.
        output[node->GetChar()] = prefix;
       // cout << "Character: " << node->GetChar() << ", Encoding: " << prefix << endl;
    } else {
        // its not a leaf so give edges value. 0 if a left edge and 1 if a right edge
        string leftPrefix = prefix + "0";
        string rightPrefix = prefix + "1";
        Compress(node->GetLeft(), leftPrefix);
        Compress(node->GetRight(), rightPrefix);
    }
}

//decode the message 
void Huffman::Decompress(const string &compStr){
  Node* node = root;
   result = ""; //  clear result 
  // for each character in the string convert to int and traverse the tree
  for(char c : compStr){
    int charToInt = c - '0';
    if(charToInt==0){
      node = node->GetLeft();
    }else if(charToInt == 1){
      node = node->GetRight();
    }
    // if leaf node concatenate char to result string and go back to root for next character
    if(node->GetChar() != 0){
      result += node->GetChar();
      node = root;
    }
  }
}


void Huffman::PrintEncoded() {
  cout << "Huffman Codes are:\n";
  for(const auto& entry : output) {
    cout << entry.first << ": " << entry.second << endl;
  }
}

void Huffman::PrintCompressed() {
  string outStr = "";
  cout << "\nCOMPRESSED MESSAGE: ";
  // for each letter in inpString find the encoded string and add to outStr
  for(const char c: inpStr){
    for(const auto& entry : output) {
      if(c == entry.first){
        outStr += entry.second;
      }
    }
  }
     cout << outStr << '\n';
 
  Decompress(outStr);
}

void Huffman::PrintDecompressed(){
  cout << "\nDECOMPRESSED MESSAGE: " << result << endl;
}

