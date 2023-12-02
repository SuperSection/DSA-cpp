#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for(int i = 10; i >= 0; --i) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main() {
    cout << INT_MAX << "\n";
    int a = (1LL<<31) - 1; // Signed Int : can only store till 31-bits negative and positive integer value
    // one bit (MSB) is reserved to represent the sign(+ or -) of the integer
    cout << a << "\n";

    unsigned int b = (1LL<<32) - 1; // Unsigned Int: can store upto 32-bits integer (only positive)
    cout << b << "\n";


    printBinary(13);
    int x = 13;
    int i = 1;
    if((x & (1<<i)) != 0) {
        cout << "Set bit!\n";
    } else {
        cout << "Not set bit!\n";
    }

    // Set a bit
    printBinary(x | (1<<i));

    // Invert a binary number (1's Complement)
    printBinary ( ~10 );

    // Unset a bit
    printBinary(x & (~(1<<3)));

    // toggle a bit
    printBinary(x ^ (1<<1));
    printBinary(x ^ (1<<2));

    // count number of Set bits
    int count = 0;
    for(int i = 31; i >= 0; --i) {
        if((x & (1<<i)) != 0) {
            count++;
        }
    }
    cout << count << endl;

    // built-in function to count Set bits
    cout << __builtin_popcount(x) << "\n";
    cout << __builtin_popcountll((1LL<<35)-1) << "\n";

}

