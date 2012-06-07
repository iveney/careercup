#ifndef NODE_2L14WGJV

#define NODE_2L14WGJV

#include <stdio.h>

// no template, quick code
// XXX: intentionally do not manage space
class Node {
 public:
  Node(int key) : key_(key), left(NULL), right(NULL) {};

  // data members
  int key_;
  Node* left;
  Node* right;
};

#endif /* end of include guard: NODE_2L14WGJV */
