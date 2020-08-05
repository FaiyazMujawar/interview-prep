# Quick Sort Algorithm

**About:** *Quick Sort alorithm is an algorithm that sorts a given array by recursively breaking it into two partially sorted arrays. The recursion continues till the array cannot be further subdivided.*

**Complexity:** Average time complexity `O(nlogn)` 

**Working:**
<br>
The quick sort algorithm works by placing one element in the array, called the `pivot`, in it's correct position in the sorted array, in each recursive call.
<br>
Placing the pivot in correct place creates two partially sorted arrays:
- All elements on left of pivot are smaller than pivot
- All elements on right of pivot are greater than pivot
<br>

The two partially sorted sub-arrays are again sorted recursively using the same procedure.

**Algorithm:**
<br>
To find the pivot point in the array: (*Here the 1<sup>st</sup> element in the array is taken as pivot.*)
<br>
```C++
/*
int *array: Pointer to the array to be sorted.
int low: Lower bound of the array.
int high: Upper bound of the array.
*/
int partition(int *array, int low, int high){
  ...
  return pivot;
}
```
 * Take the first element of the array as the 'pivot'.
 * Initialize i with 2<sup>nd</sup> index(low + 1) and j with 1<sup>st</sup> index(low) of array.
 * While looping the array with i as iteration variable, if any element array[i] < pivot, increment j & swap the i<sup>th</sup> element with j<sup>th</sup> element.
 * The idea is, if any element smaller than the pivot is found in the array, it is placed the lower half of the array. Index j maintains the index upto which the elements are smaller than the pivot.
 * After looping through entire array, swap the j<sup>th</sup> element with 1<sup>st</sup>  element
 * Return the pivot point i.e index j.

Using the pivot index obtained from the `partition` function, divide the array into two sub-arrays: `low to pivot-1` & `pivot+1 to high` and sort them using the same procedure recursively.
