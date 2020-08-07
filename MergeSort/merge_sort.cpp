#include <iostream>
using namespace std;

/** 
  @brief Merges the two sub_arrays into single array in sorted fashion.
  @param array array to be sorted
  @param low starting index of subarray in 'array'.
  @param mid mid index of the array to be sorted.
  @param high last index of subarray in 'array'.
*/
void merge(int array[], int low, int mid, int high)
{
  // '+1' as the mid element is also included.
  int n_left = mid - low + 1;
  int n_right = high - mid;
  int left[n_left];
  int right[n_right];

  // Creating left sub-array
  for (int i = 0; i < n_left; i++)
    left[i] = array[i + low]; // 'i + low' so that the elements are copied from index 'low', not i.

  // Creating right sub-array
  for (int i = 0; i < n_right; i++)
    right[i] = array[i + mid + 1];

  // Merging and sorting left & right sub-arrays
  int i = 0, j = 0, k = low; // k=low so that array in merged from index 'low to high', not 0.
  while (i < n_left && j < n_right)
  {
    array[k] = left[i] <= right[j] ? left[i++] : right[j++];
    k++;
  }
  while (i < n_left)
  {
    array[k] = left[i++];
    k++;
  }
  while (j < n_right)
  {
    array[k] = right[j++];
    k++;
  }
}

/** 
  @brief Divides the array into two equal parts and sorts them recursively.
  @param array array to be sorted
  @param low starting index of array.
  @param high last index of array.
*/
void merge_sort(int array[], int low, int high)
{
  if (low < high)
  {
    int mid = (high + low) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);
    merge(array, low, mid, high);
  }
}

int main(int argc, char const *argv[])
{
  int array[5] = {2, 4, 1, 6, 9};
  for (int i = 0; i < 5; i++)
  {
    cout << array[i] << " ";
  }
  merge_sort(array, 0, 4);
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << array[i] << " ";
  }
  return 0;
}
