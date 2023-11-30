#include <iostream>
#include <vector>
#include <algorithm> // this header file contains next_permutation function
using namespace std;


static vector<int> nextGreaterPermutation(vector<int>& arr) {
    int breakIndex = -1; // to store the index from where array must be altered to get the answer
    int n = arr.size();

    // find the break point where arr[i] is smaller than arr[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            breakIndex = i;
            break;
        }
    }

    // if no such break point is found, reverse the array
    // because the array itself is the last possible permutation, and reverse of it i.e. first permutation will be the answer
    if (breakIndex == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // swap the breaking point value with its just next greater value, occuring after that break-index in the array
    for (int i = n - 1; i > breakIndex; i--) {
        if (arr[i] > arr[breakIndex]) {
            swap(arr[i], arr[breakIndex]);
            break;
        }
    }

    // reverse the remaining part of the array after the break-point is swapped with its just next greater value (available after the break-index in the array)
    // beacuse after swap, remaining part is in the descending order and the next permutation will have that part in ascending order
    reverse(arr.begin() + breakIndex + 1, arr.end());
    return arr;
}


int main()
{
    vector<int> arr = { 2, 1, 5, 4, 3, 0, 0 };

    // next_permutation(arr.begin(), arr.end());

    cout << "The Next Permutation of the array:\n";
    nextGreaterPermutation(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
