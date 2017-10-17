// hashheap.cpp
// Dylan Vanmali
// CS130A Spring 2017 Prof. Suri

#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;

/**                                                                             
 * Creates an empty Heap
 */
Heap::Heap() { }

/**                                                                             
 * Inserts a value into the Heap
 * Inserts the value at the end of the list and percolates up through tree
 * @param {int} value - value to insert                                         
 * @returns {bool} true if already exists, false if didn't before               
 */
bool Heap::insert(int value) {
  bool found = lookup(0,value);
  if (!found) {
    hp.push_back(value);
    // Percolate up
    int index = hp.size()-1;
    while (index > 0) {
      if (index % 2 == 1) {
	int left = hp[index];
	int parent = hp[(index-1)/2];
	if (left > parent) {
	  int tmp = parent;
	  hp[(index-1)/2] = left;
	  hp[index] = tmp;
	  index = (index-1)/2;
	}
	else
	  index = 0;
      }
      else if (index % 2 == 0) {
	int right = hp[index];
	int parent = hp[(index/2)-1];
	if (right > parent) {
	  int tmp = parent;
	  hp[(index/2)-1] = right;
	  hp[index] = tmp;
	  index = (index/2)-1;
	}
	else
	  index = 0;
      }
    }
  }
  return found;
}

/**                                                                             
 * Deletes a value from the Heap
 * Deletes the value by switching with last value, deleting last value, and percolating down
 * @param {int} value - value to delete                             
 * @returns {bool} true if value present and deleted, false if not present     
 */
bool Heap::deleteValue(int value) {
  for (int i=0; i<hp.size(); i++) {
    if (hp[i] == value) {
      hp[i] = hp[hp.size()-1];
      hp.pop_back();
      // Percolate down
      bool even = (hp.size()%2 == 0);
      while (i < hp.size()/2) {
	// Even size means last element is left node
	if (even && (i==(hp.size()/2)-1)) {
	  int left = hp[2*i+1];
	  int current = hp[i];
	  if (current < left) {
	    hp[i] = left;
	    hp[2*i+1] = current;
	    i = 2*i+1;
	  }
	  else
	    i = hp.size();
	}
	// Odd size means full binary heap
	else {
	  int left = hp[2*i+1];
	  int right = hp[2*i+2];
	  int current = hp[i];
	  if (current < left && left > right) {
	    hp[i] = left;
	    hp[2*i+1] = current;
	    i = 2*i+1;
	  }
	  else if (current < right && right > left) {
	    hp[i] = right;
	    hp[2*i+2] = current;
	    i = 2*i+2;
	  }
	  else
	    i = hp.size();
	}	
      }
      return true;
    }
  }
  return false;
}

/**                                                                             
 * Finds value in the Heap
 * @param {int} index - starting position of tree, usually always 0
 * @param {int} value - value to find                            
 * @returns {bool} true if found, false if not                   
 */
bool Heap::lookup(int index, int value) {
  if (hp.empty())
    return false;
  if (hp[index] == value)
    return true;
  if (hp[index] < value || index > hp.size())
    return false;
  if (hp[index] > value) {
    bool b;
    // Go left
    b = lookup(2*index+1,value);
    // Go right
    if (!b)
      b =lookup(2*index+2, value);
    return b;
  }
  return false;
}

/**
 * Gets the Maximum value of the heap, which is also the first value
 * @return {int*} Pointer to the maximum value, NULL if no maximum
 */
int* Heap::getMax() {
  if (!hp.empty()) {
    return &hp.front();
  }
  return NULL;
}

/**
 * Gets pointer of the start of the heap
 * @return {vector<int>*} Pointer to start of heap
 */
vector<int>* Heap::getAll() {
  return &hp;
}

/**
 * Checks to see if heap is empty
 * @return {bool} true if heap is empty, false if not
 */
bool Heap::empty() {
  return hp.empty();
}


/**
 * Prints the entire heap for debugging purposes
 */
void Heap::print() {
  for (unsigned i=0; i<hp.size(); i++)
    cout << hp[i] << " ";
  cout << endl;
}
