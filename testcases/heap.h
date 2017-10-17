// heap.h
// Dylan Vanmali
// CS130A Spring 2017 Prof. Suri

#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

/**
 * Heap class
 * Contains structure for integers, specifically in max heap assortment
 * @class HashHeap
 */
class Heap {
 public:
  // Constructor and Destructor
  Heap();
  
  // Functions in O(1) time
  bool insert(int value);
  bool deleteValue(int value);
  bool lookup(int index, int value);
  int*  getMax();
  vector<int>* getAll();
  bool empty();
  
 private:
  vector<int> hp;
  void print();
};

#endif
