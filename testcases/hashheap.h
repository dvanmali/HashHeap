// hashheap.h
// Dylan Vanmali
// CS130A Spring 2017 Prof. Suri

#ifndef HASHHEAP_H
#define HASHHEAP_H

#include "heap.h"
#include <vector>
using namespace std;

/**
 * HashHeap class
 * Contains structure for integers, specifically in max assortment
 * Structure utilizes a Hash table filled with (Max) Heap objects
 * @class HashHeap
 */
class HashHeap {
 public:
  // Constructor and Destructor
  HashHeap();
  HashHeap(int size);
  
  // Functions in O(1) time
  bool insert(int value);
  bool deleteValue(int value);
  bool lookup(int value);
  void deleteMax();       // returns deleted max value
  void print();
  
 //protected:
  
 private:
  int used;        // Number of Entries Used in the Table
  vector<Heap> table;
  int hash(int value);
};

#endif
