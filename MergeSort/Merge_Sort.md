# Merge Sort Algorithm

### <u>Description</u>
 _Merge Sort algorithm is a sorting algorithm that sorts a given array by recursively dividing into equal sub-arrays. When the sub-arrays contains only single elements, the sorting starts by merging the two arrays in sorted array._
 
**Complexity:** Average time complexity `O(nlogn)`

### <u>Working</u>
The main idea behind the Merge Sort algorithm is to divide the array until it contains only single element. On reaching this condition, the sorting of the array starts by merging the two sub-arrays into single array in sorted fashion.


The Merge Sort algorithm finds the middle (`mid`) of the array. Then splits the array into `'lower_bound to mid'` and `'mid + 1 to upper_bound'` and then sorts these sub-arrays recursively.

### <u>Algorithm</u>
_Merge sort works in two phases:_ `Divide` _and_ `Merge`.

To divide the array recursively: `Divide`
- If has single element, return.
- Find mid of the `array`.
- Divide the array into `lower_bound to mid` and `mid + 1 to upper_bound`.
- Call `merge_sort` on these sub-arrays.
- When the recursive call returns, start merging the sub-arrays.


```C++
/* 
  array: array to be sorted.
  low: starting index of subarray in 'array'.
  high: last index of subarray in 'array'.
*/
void merge_sort(int array[], int low, int high) {
  if (array has more than one element) {
    find mid;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);
    merge(low, mid, high);
  }
}
```

---
To merge the divided sub-arrays recursively: `Merge`
- Find the length of left and right sub_arrays.
- Create a temporary array with elements of left sub_array (`left`).
- Create a temporary array with elements of right sub_array (`right`).
- Merge the elements from left and right array into single array in sorted fashion.

```C++
/* 
 array: array to be sorted
 low: starting index of subarray in 'array'.
 mid: mid of the array to be sorted.
 high: last index of subarray in 'array'.
*/
void merge(int array[], int low, int mid, int high) {
  int l1 = length of left sub_array;
  int l2 = length of right sub_array;
  int left[l1] = array with elements of left sub_array;
  int right[l2] = array with elements of right sub_array;
  int k = low;
  // Merging the left & right sub_array
  while (i < l1 and j < l2) {
    array[k] = min(left[i], right(j));
    i++ or j++; // accordingly
    k++;
  }
  Add remaining elements of left and right into array, if any.
}
```
