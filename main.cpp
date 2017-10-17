// main.cpp
// Dylan Vanmali
// CS130A Spring 2017 Prof. Suri

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "hashheap.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  string   line;
  HashHeap *h;
  int      lineNum = 0;
  int      operations = 0;
  //if (myfile.is_open()) {
  while( getline( cin, line ) ) {
    //cout << line << endl;
    
    if (lineNum == 0)
      h = new HashHeap(atoi(line.c_str()));
    else if (lineNum == 1)
      operations = atoi(line.c_str());
    else {
      if (line.find("insert ") == 0) {
	h->insert(atoi(line.substr(7).c_str()));
      }
      else if (line.find("delete ") == 0) {
	bool b = h->deleteValue(atoi(line.substr(7).c_str()));
      }
      else if (line.find("deleteMax") == 0) {
	h->deleteMax();
      }
      else if (line.find("lookup ") == 0) {
	bool b = h->lookup(atoi(line.substr(7).c_str()));
	}
      else if (line.find("print") == 0) {
	h->print();
      }
    }
    lineNum++;
  }
  return 0;
}
