/* 
 * This program solves a given mathematical expression using 'STACK' 
 * data structure.
 * The program takes care of paranthesis.
 * Allowed operators : [paranthesis, + , -, *, /,^(raised to)]

 * Example: 2*(1+9/3)+1 evaluates to => 9 | 2^3+2^2 evaluates to => 12
 */

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int calculator(string &exp)
{
  stack<int> operands;
  int number = 0;
  int length;
  char sign = '+';
  length = exp.length();
  for (int i = 0; i < length; i++)
  {
    char c = exp[i];
    if (c == ' ') //! This should have handled blank spaces in expression, but fails to do so.
      continue;
    // Current character is processed, so make it blank so it's not reprocessed.
    exp[i] = ' ';
    if (c == '(')
      number = calculator(exp);
    if (isdigit(c))
      number = number * 10 + (c - '0');
    if (!isdigit(c) || i == length - 1)
    {
      int temp;
      switch (sign)
      {
      case '+':
        operands.push(number);
        break;
      case '-':
        operands.push(-number);
        break;
      case '*':
        temp = operands.top();
        operands.pop();
        temp *= number;
        operands.push(temp);
        break;
      case '/':
        temp = operands.top();
        operands.pop();
        temp /= number;
        operands.push(temp);
        break;
      case '^':
        temp = operands.top();
        operands.pop();
        temp = int(pow(temp, number));
        operands.push(temp);
        break;
      default:
        break;
      }
      sign = c;
      number = 0;
    }
    if (c == ')')
      break;
  }
  int result = 0;
  while (!operands.empty())
  {
    result += operands.top();
    operands.pop();
  }
  return result;
}

int main(int argc, char const *argv[])
{
  string exp;
  cout << "Enter expression:\t";
  cin >> exp;
  int result = calculator(exp);
  cout << "Result:\t" << result << endl;
  return 0;
}
