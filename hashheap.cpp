// hashheap.cpp
// Dylan Vanmali
// CS130A Spring 2017 Prof. Suri

#include "hashheap.h"
#include "heap.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Creates an empty HashHeap with size 97
 */
HashHeap::HashHeap() {
  used = 0;
  vector<Heap> t (97);
  t.swap(table);
}

/**
 * Creates an empty HashHeap with size s
 * @param {int} s - size of HashHeap
 */
HashHeap::HashHeap(int s) {
  used = 0;
  vector<Heap> t (s);
  t.swap(table);
}

/**
 * Hash Function that determines location within the HashHeap
 * Works with negative, zero, and positive values
 * @param {int} s - size of HashHeap
 */
int HashHeap::hash(int value) {
  if (value < 0)
    value *= -1;
  return value % table.size();
}

/**
 * Inserts a value into the HashHeap at its hash location
 * @param {int} value - value to insert
 * @returns {bool} true if already exists, false if didn't before
 */
bool HashHeap::insert(int value) {
  bool exists = table[hash(value)].insert(value);
  if (exists == true) {
    cout << "error: item already exists" << endl;
  }
  return exists;
}

/**
 * Deletes a value from the HashHeap by accessing its hash location
 * @param {int} value - value to delete
 * @returns {bool} true if value present and deleted, false if not present
 */
bool HashHeap::deleteValue(int value) {
  bool present = table[hash(value)].deleteValue(value);
  if (present == false) {
    cout << "error: item not present" << endl;
  }
  return present;
}

/**
 * Finds value in the HashHeap by accessing its hash location
 * @param {int} value - value to find
 * @returns {bool} true if found, false if not
 */
bool HashHeap::lookup(int value) {
  bool found = table[hash(value)].lookup(0,value);
  if (found == false)
    cout << value << " not found " << endl;
  else
    cout << "found " << value << endl;
  return found;
}

/**
 * Deletes the Maximum value in the entire HashHeap
 */
void HashHeap::deleteMax() {
  if (!table.empty()) {
    int* max = table[0].getMax();
    for (int i=0; i<table.size(); i++) {
      if (max == NULL)
	max = table[i].getMax();
      else if (table[i].getMax() == NULL)
	; // Do Nothing
      else if (*(table[i].getMax()) > (*max))
	max = table[i].getMax();
    }
    if (max == NULL)
      cout << "error" << endl;
    else {
      cout << (*max) << endl;
      table[hash(*max)].deleteValue(*max);
    }
  }
  else {
    cout << "error" << endl;
  }
}

/**
 * Prints the integer values in order from Max to Min
 */
void HashHeap::print() {
  vector<int> print_sorted;
  if (!table.empty()) {
    for (int i=0; i<table.size(); i++) {
      if (!table[i].empty()) {
	vector<int>* tmp = table[i].getAll();
	print_sorted.insert(print_sorted.end(), tmp->begin(), tmp->end());
      }
    }
  }
  sort(print_sorted.begin(), print_sorted.end());
  if (!print_sorted.empty())
    for (int k=print_sorted.size()-1; k>=0; k--)
      cout << print_sorted[k] << " ";
  cout << endl;
}
