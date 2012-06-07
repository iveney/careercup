#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

//    _0_
//   /   \
//  1     2
// /    /  \
//3    4    5

void print(Node *nd) {
  // preorder
  if (nd == NULL) {
    cout << "# ";
    return;
  }
  cout << nd->key_ << " ";
  print(nd->left);
  print(nd->right);
}

void serialize(Node *nd, ofstream& ofs) {
  // preorder serialize
  if (nd == NULL) {
    ofs << "# ";
    return;
  }
  ofs << nd->key_ << " ";
  serialize(nd->left, ofs);
  serialize(nd->right, ofs);
}

bool readNextKey(ifstream& ifs, int& key) {
  while(1) {
    char c;
    int next = ifs.peek();
    switch(next) {
      case EOF:
        return false;
      case ' ':
        ifs.get(c);
        break;
      case '#':
        ifs >> c;
        return false;
      default:
        ifs >> key;
        return true;
    }
  }
}

void deserialize(ifstream& ifs, Node* &nd) {
  int key;
  // reaches file end or NULL pointer
  if (readNextKey(ifs, key) == false) {
    return;
  }
  nd = new Node(key);
  deserialize(ifs, nd->left);
  deserialize(ifs, nd->right);
}

int main(int argc, const char *argv[])
{
  // construct tree
  const int size = 6;
  Node* n[size];
  for (int i = 0; i < size; i++) {
    n[i] = new Node(i);
  }

  n[0]->left = n[1];
  n[0]->right = n[2];
  n[1]->left = n[3];
  n[2]->left = n[4];
  n[2]->right = n[5];

  // print the original tree
  print(n[0]);
  cout << endl;

  // serialize tree
  ofstream ofs("tree.dat");
  serialize(n[0], ofs);
  ofs.close();

  // deserialize
  ifstream ifs("tree.dat");
  Node* root = NULL;
  deserialize(ifs, root);
  print(root);
  cout << endl;
  ifs.close();

  return 0;
}
