#include "heap.h"
#include <iostream>
#include <functional>

int main() {
  try {

    Heap<int> minHeap(3); 
    // T = int
    // comparator = std:: less<int>
    // m = 3

    minHeap.push(4);
    minHeap.push(7);
    minHeap.push(1);
    minHeap.push(20);
    minHeap.push(42);
    minHeap.push(90);

    std::cout << "MinHeap : (top -> bottom)" << std::endl;
    while (!minHeap.empty()) {
      std::cout << "Top: " << minHeap.top() << std::endl;
      minHeap.pop(); 
    }


    // max: **specify max**
    Heap<int, std::greater<int>> maxHeap(2);

    maxHeap.push(3);
    maxHeap.push(88);
    maxHeap.push(15);
    maxHeap.push(9);
    maxHeap.push(67);
    maxHeap.push(45);
    
    std::cout << "MaxHeap : (top -> bottom)" << std::endl;
    while (!maxHeap.empty()) {
      std::cout << "Top: " << maxHeap.top() << std::endl;
      maxHeap.pop(); 
    }


    // call on empty 
    std::cout << "Attempting pop on empty heap" << std::endl;

    minHeap.pop();

  }
  
  catch (const std::underflow_error &e) {
    std::cout << "Caught e: " << e.what() << std::endl;
  }


  return 0;
}