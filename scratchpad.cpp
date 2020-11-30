#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Function to generate permutations of given string
*/
set<string> generate_permutations(string str)
{
  int length = str.length();
  set<string> result;
  if (length == 1)
    result.insert(str);
  else
  {
    set<string> permutations = generate_permutations(str.substr(1, length));
    string character(1, str[0]);
    result.insert(character);
    for (string permutation : permutations)
    {
      result.insert(permutation);
      result.insert(character + permutation);
      result.insert(permutation + character);
      for (int i = 0; i < permutation.length(); i++)
      {
        result.insert(permutation.substr(0, i) + character + permutation.substr(i, length));
      }
    }
  }
  return result;
}

int main(int argc, char const *argv[])
{
  set<string> permutations = generate_permutations("abc");
  for (auto &&perm : permutations)
  {
    cout << perm << " ";
  }
  cout << endl;
  return 0;
}

/******************************************************************/