#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Implements Binary Min Heap Data Structure using Vector.
 */
class MinHeap
{
private:
  vector<int> heap;

public:
  int getParentIndex(int);
  int getLeftChildIndex(int);
  int getRightChildIndex(int);
  int extractMin();
  void swap(int, int);
  void insert(int);
  void heapifyUp(int);
  void heapifyDown(int);
  void printHeap();
};

/**
 * @brief Finds the index of left child of an element.
 * @param index Index of element whose left child is to be found.
 * @return Index of left child if found, or -1. 
*/
int MinHeap::getLeftChildIndex(int index)
{
  int child = (2 * index) + 1;
  return child < heap.size() - 1 ? child : -1;
}

/**
 * @brief Finds the index of right child of an element.
 * @param index Index of element whose right child is to be found.
 * @return Index of right child if found, or -1. 
*/
int MinHeap::getRightChildIndex(int index)
{
  int child = (2 * index) + 2;
  return child < heap.size() - 1 ? child : -1;
}

/**
 * @brief Extracts minimum element from the heap.
 * @return Minimum element from the heap (root).
 */
int MinHeap::extractMin()
{
  int min = heap.at(0);
  heap.at(0) = heap.back();
  heap.pop_back();
  heapifyDown(0);
  return min;
}

/**
 * @brief Inserts new element into the heap.
 * @param data Element to be inserted.
 */
void MinHeap::insert(int data)
{
  heap.push_back(data);
  heapifyUp(heap.size() - 1);
}

/**
 * @brief Finds the index of parent of an element.
 * @param index Index of element whose parent is to be found.
 * @return Index of parent.
*/
int MinHeap::getParentIndex(int index)
{
  int parent = index % 2 == 0 ? (index - 2) / 2 : (index - 1) / 2;
  return parent < 0 ? 0 : parent;
}

void MinHeap::swap(int a, int b)
{
  int temp = heap.at(a);
  heap.at(a) = heap.at(b);
  heap.at(b) = temp;
}

/**
 * @brief Maintains the heap property in the heap, after inserting a new element.
 * @param index Index of element at which heap property is to be checked.
*/
void MinHeap::heapifyUp(int index)
{
  int parent = getParentIndex(index);
  if (index == 0 || heap.at(parent) <= heap.at(index))
    return;
  swap(parent, index);
  heapifyUp(parent);
}

/**
 * @brief Maintains the heap property in the heap, after deleting an element.
 * @param index Index of element at which heap property is to be checked.
*/
void MinHeap::heapifyDown(int index)
{
  int smallest = index;
  int left_child = getLeftChildIndex(index);
  int right_child = getRightChildIndex(index);
  if (left_child != -1 && heap.at(left_child) < heap.at(smallest))
    smallest = left_child;
  if (right_child != -1 && heap.at(right_child) < heap.at(smallest))
    smallest = right_child;
  if (smallest == index)
    return;
  swap(index, smallest);
  heapifyDown(smallest);
}

/**
 * @brief Prints the heap level wise.
*/
void MinHeap::printHeap()
{
  for (int element : heap)
    cout << element << " ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  MinHeap heap;
  int array[10] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
  for (int i = 0; i < 10; i++)
    heap.insert(array[i]);
  heap.printHeap();
  heap.extractMin();
  heap.printHeap();
  heap.insert(8);
  heap.printHeap();
  return 0;
}
