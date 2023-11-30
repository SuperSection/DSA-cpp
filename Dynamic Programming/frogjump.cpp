#include <bits/stdc++.h>
using namespace std;

/*	here we are considering zero base indexing of the stairs

Frog can jump to (i+1)th or (i+2)th stair from current-i stair.
Need to find minimum energy to climb up to n-th stair from 1st stair:
  where energy lose in each step is absolute difference of the values in those two steps (in the Array)
*/



// solution using Memoization
static int f(int index, vector<int>& heights, vector<int>& dp)
{
  if (index == 0) return 0; // base condition
  if (dp[index] != -1) return dp[index]; // if the sub-problem has been already solved, use that

  int oneStep = f(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
  int twoStep = INT_MAX; // if index is 1 or 0, 2step can't be taken
  if (index > 1) twoStep = f(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

  return dp[index] = min(oneStep, twoStep);
}

static int frogJumpMemoization(int n, vector<int>& heights)
{
  vector<int> dp(n, -1); // to store already solved sub-problems' value => Momoization
  return f(n - 1, heights, dp);
}



// solution using Tabulation
static int frogJumpTabulation(int n, vector<int>& heights)
{
  vector<int> dp(n, 0);
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int twoStep = INT_MAX;
    if (i > 1) twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);

    dp[i] = min(oneStep, twoStep);
  }
  return dp[n - 1];
}



// Space Optimized solution: Time Complexity - O(n)
static int frogJump(int n, vector<int>& heights)
{
  int prev1 = 0, prev2 = 0;

  for (int i = 1; i < n; i++)
  {
    int oneStep = prev1 + abs(heights[i] - heights[i - 1]);
    int twoStep = INT_MAX;
    if (i > 1) twoStep = prev2 + abs(heights[i] - heights[i - 2]);

    int curi = min(oneStep, twoStep);
    prev2 = prev1;
    prev1 = curi;
  }
  return prev1;
}



int main() {
  vector<int> arr = { 30, 10, 60, 10, 60, 50 };
  cout << "The minimum energy lost can be " << frogJump(6, arr) << endl;

  return 0;
}
