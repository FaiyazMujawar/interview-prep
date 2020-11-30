/**
 * Question:
 * Is Unique: Implement an algorithm to determine if a string
 * has all unique characters. What if you cannot use additional
 * data structures?
 */

// Solution

#include <iostream>
using namespace std;

bool checkIsUnique(string str)
{
  int length = str.length();
  for (int i = 1; i < length; i++)
  {
    for (int j = 0; j < i; j++)
      if (str[i] == str[j])
        return false;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  string str = "a";
  if (checkIsUnique(str))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
