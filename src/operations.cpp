#include <iostream>
using namespace std;

int main() {
  // Question 1
  cout << "ARITHMETIC OPERATIONS\n";
  int a;
  int b;
  cout << "Enter an integer : ";
  cin >> a;
  cout << "Enter an other integer : ";
  cin >> b;
  cout << a << " + " << b << " = " << (a+b) << "\n";
  cout << a << " - " << b << " = " << (a-b) << "\n";
  cout << a << " / " << b << " = " << (a/b) << "\n";
  cout << a << " x " << b << " = " << (a*b) << "\n";

  // Question 2
  cout << "\nBIT OPERATION\n";
  cout << "Enter an integer : ";
  cin >> a;
  cout << "Enter an other integer (for binary operations) : ";
  cin >> b;
  cout << a << " xor " << b << " = " << (a^b) << "\n";
  cout << a << " and " << b << " = " << (a&b) << "\n";
  cout << a << " or " << b << " = " << (a|b) << "\n";
  cout << a << " shifted left by " << b << " = " << (a << b) << "\n";
  
  return 0;
}