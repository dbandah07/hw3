#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
  : m_(m), comp_(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  // Add whatever helper functions and data members you need below
  std::vector<T> data_; // stores heap elements
  int m_; // m-ary heap
  PComparator comp_; // Comparator functor

};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {

  data_.push_back(item); // add new element
  int index = data_.size() - 1; // new index of element 

  while (index > 0) {
    int parent = (index - 1) / m_; // find the parent
    if (!comp_(data_[index], data_[parent])) { // if parent alrdy is prio, then leave it
      break;
    }  
    std::swap(data_[index], data_[parent]); // otherwise, swap
    index = parent; // move up
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0]; // first 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");
  }

  data_[0] = data_.back(); // move last to root
  data_.pop_back(); // remove last

  int index = 0;
  int size = data_.size();

  // child - m*index + 1;
  // go down
  while (m_*index + 1 < size) { // keep going while curr node has a child. 
    int temp = index;

    // check children
    for (int k = 1; k <= m_; k++) {
      int child = m_*index+k;

      if (child < size && comp_(data_[child], data_[temp])){
        temp = child;
      }
    }

    // if alrdy in the right spot, then break
    if (temp == index) {
      break;
    }

    std::swap(data_[index], data_[temp]);
    index = temp;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}


#endif

