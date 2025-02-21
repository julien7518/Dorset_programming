#include <iostream>
using namespace std;

int main() {
    // Question 1
    int limit;
    cout << "Enter a limit number : ";
    cin >> limit;
    cout << "For loop\n";
    for (int i = 1; i <= limit; i++) {
        cout << i << " ";
    }

    // Question 2
    cout << "\n\nWhile loop\n";
    int i = 1;
    while (i <= limit)
    {
        cout << i << " ";
        i++;
    }

    // Question 3
    cout << "\n\nDo-While loop\n";
    i = 1;
    do
    {
        cout << i << " ";
        i++;
    } while (i <= limit);

    return 0;
}