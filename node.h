#ifndef NODE_H
#define NODE_H

class Node {
public:
  Node(int x, int y){
    this->x = x;
    this->y = y;
  }
  int g_cost = 0;
  int h_cost = 0;
  int f_cost = 0;
  int x = 0;
  int y = 0;
  int parentIndex = -1; 
};

#endif
