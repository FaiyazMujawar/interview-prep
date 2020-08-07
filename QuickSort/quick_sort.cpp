#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

/**
  @brief Converts the given array into two partially sorted arrays.
  @param array[] Array to be sorted.
  @param low Index of the lower bound.
  @param high Index of the upper bound.
  @return  The index of pivot point dividing the two partially sorted arrays.
 */
int partition(int array[], int low, int high)
{
  int j = low;
  int pivot = array[low];
  for (int i = low + 1; i < high; i++)
  {
    if (array[i] < pivot)
    {
      j++;
      swap(array[i], array[j]);
    }
  }
  swap(array[low], array[j]);
  return j;
}

/**
  @brief Sorts the given array.
  @param array[] Array to be sorted.
  @param low Index of the lower bound.
  @param high Index of the upper bound.
 */
void quick_sort(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(array, low, high);
    quick_sort(array, low, pivot);
    quick_sort(array, pivot + 1, high);
  }
}

int main(int argc, char const *argv[])
{
  int *array;
  int n, num;
  cout << "Enter no of elements:\t";
  cin >> n;
  array = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    array[i] = num;
  }
  quick_sort(array, 0, n);
  for (int i = 0; i < n; i++)
  {
    cout << array[i] << " ";
  }

  cout << endl;
  return 0;
}
