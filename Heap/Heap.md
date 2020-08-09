# Heap Data Structure

### <u>Description</u>
_A Heap is a data structure similar to binary tree, with one special property:_
> The value of the parent node is always either less than [or greater than] or equal to it's child nodes.

_A Heap is always a complete binary tree i.e nodes are inserted from left to right level-wise._

_If the value of parent node is less than or equal to it's child nodes, the heap is called_ `Min Heap`.

_If the value of parent node is greater than or equal to it's child nodes, the heap is called_ `Max Heap`.

### <u>Structure</u>
As the heap is a complete binary tree, it can easily implemented using an array instead of a linked list. Implementation using an array removes the overhead of memory manipulation using pointers.

The index of the left & right child of a node can be found using:
- Left child: `(2 * parent_index) + 1`
- Right child: `(2 * parent_index) + 2`

As the heap is complete binary tree, any element can be easily added to the heap by inserting at the end of the array.

### <u>Implementation</u>
The implementation for a Binary Min Heap. 

```C++
class MinHeap
{
  private:
    // Heap of size 100 (arbitrary).
    int heap[100];
    int size;
  public:
    MinHeap()
    {
      size = 0;
    }
    int extractMin();
    void insert(int data);
    void heapifyUp(int index);
    void heapifyDown(int index);
}
```

_This implementation shows the basic operations to be performed on a heap._

**extractMin()** : int
<br>
_Returns the lowest element in the heap i.e the root element and removes it from the heap._

<u>Algorithm</u>

- Initialize a variable (`min`) with first element in heap (root).
- Replace the first element in the heap with the last element (element at index `size-1`).
- Delete the last element. Decrement the size.
- Call `heapifyDown()` with the index of root node i.e 0.
- Return `min`.


```C++
int extractMin() {
  int min = heap[0];
  Replace 1st element with last element;
  Delete last element;
  heapifyDown(0);
  return min;
}
```
---

**insert(int data)** : void
<br>
_Inserts a new element into the heap._

Params: 
<br>
`data` - Element to inserted.

<u>Algorithm</u>

- Insert element at index `size`
- Increment size.
- Call `heapifyUp()` with index of last element i.e `size-1`.

```C++
void insert(int data) {
  heap[size] = data;
  size = size + 1;
  heapifyUp(size - 1);
}
```
---

**heapifyUp(int index)** : void
<br>
_Maintains the heap property while inserting a new element into the heap._

Params: 
<br>
`index` - Index at which the heap property is to be checked (current node).

<u>Algorithm</u>

- Find the index of the parent of node at index `index`.
- If the current index is 0, or the value at parent index is smaller than or equal to current index, return.
- Else, swap the values at parent index & current index.
- Call `heapifyUp()` on the parent index.

```C++
void heapifyUp(int index) {
  int parent = index of parent of current node.
  if(index = 0 || parent node value <= current node value)
    return;
  Swap parent node and current node;
}
```
---

**heapifyDown(int index)** : void
<br>
_Maintains the heap property while deleting the root element from the heap._

Params: 
<br>
`index` - Index at which the heap property is to be checked (current node).

<u>Algorithm</u>

- Find the index of left & right child, if they exist.
- Find the smallest value among the current index, the left child & the right child.
- If the smallest value is at current index, return.
- Else, swap the values at current index and the index of smallest.
- Call `heapifyDown()` on smallest.


```C++
void heapifyDown(int index) {
  int left = index of left child, if exists.
  int right = index of right child, if exists.

  // Finding the smallest value in current index, left_child & right_child.
  int smallest = index;
  if(left exists && value at left < smallest value)
    smallest = left;
  if(right exists && value at right < smallest value)
    smallest = right;
    
  if (current index is smallest)
    return;
  Swap values at smallest and index;
  heapifyDown(smallest);
}
```
---

### <u>Applications of Heap Data Structure</u>

- Priority Queues: For removing the element with highest priority from the queue [`Max Heap`].
- Heap Sort: For sorting an array.
