#include "stack.h"
#include <iostream>

int main() {
  Stack <int> s;

  s.push(6);
  s.push(7);

  std::cout << s.top() << std::endl; // 7
  s.pop();
  std::cout << s.top() << std::endl; // 6
  s.pop(); // empty 


  try {
    s.pop(); //throw
  }
  catch (std::underflow_error &e) {
    std::cout << "Caught e: " << e.what() << std::endl;
  }
}