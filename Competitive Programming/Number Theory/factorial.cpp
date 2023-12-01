/*
Given a number N. Print its factorial.
Constraints
1 <= N <= 100

Print answer module M
where M = 47
(because we can't store that amount of huge integer value)

if A = N! (factorial of N)
Required Answer: A % M 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int M = 47;
    long long fact = 1;
    for(int i = 2; i <= n; ++i) {
        fact = (fact * i) % M;
    }
    cout << fact << endl;
    return 0;
}

/* How it's working-
for the factorial of 5:
    (1*2*3*4*5) % M
    ((1*2*3*4)%M * 5%M) % M
    (((1*2*3)%M * 4%M) * 5%M) % M
    ((((1*2)%M * 3%M)* 4%M) * 5%M) % M
    now down to top calculation part by part goes into the 'fact' variable
*/


/* In most programming competitions, we are required to answer the result in 10^9+7 modulo.
Reason:
    10^9+7 -> very close to INT_MAX, so makes it possible to store in an int
    10^9+7 is a prime number, hence it's helpful to calculate Multiplicative Inverse from 1 to 10^9
*/