#include <iostream>
#include <vector>
using namespace std;
/*
  Memoization -> tend to store the value of sub-problems in some map/table
           Memoization is a Top-Down approach that uses recursion.
  Top-Down approach : required answer to base case & come back
  Tabulation -> Bottom-Up approach : base case to required answer
          Comparatively faster than Memoization, as previously solved sub-problems can be directly accessed from the table (i.e. Array)
*/


// Fibonacci number using Memoization
/*
int f(int n, vector<int> &dp) {
  if (n <= 1) return n;

  if (dp[n] != -1) return dp[n];

  return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1, -1);
  cout << f(n, dp);

  return 0;
}
*/


// Fibonacci number: Time Complexity - O(n), Space Complexity - 1
int main() {
  int n;
  cin >> n;

  int prev2 = 0;
  int prev1 = 1;
  for (int i = 2; i <= n; i++) {
    int curi = prev1 + prev2;
    prev2 = prev1;
    prev1 = curi;
  }

  cout << prev1 << endl;
  return 0;
}
