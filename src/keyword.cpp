#include <iostream>
using namespace std;

int main() {
    // Question 1
    cout << "Break at 6\n";
    for (int i = 1; i <= 10 ; i++) {
        if (i == 6) {
            break;
        }
        cout << i << " ";
    }

    // Question 2
    cout << "\n\nOnly even numbers\n";
    for (int i = 1; i <= 10 ; i++) {
        if (i % 2 == 0) {
            continue;
        }
        cout << i << " ";
    }

    // Question 3
    cout << "\n\nUse of goto\n";
    int i = 1;
    test:
    cout << i << " ";
    i += 1;
    if (i != 4) {
        goto test;
    }

    return 0;
}