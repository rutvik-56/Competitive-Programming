// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

int ternary_search(ln arr[], int arr_size, ln key) {
    int left = 0, right = arr_size - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == key) {
            return mid1 + 1;
        }
        if (arr[mid2] == key) {
            return mid2 + 1;
        }
        if (arr[mid1] > key) {
            right = mid1 - 1;
        } else if (arr[mid2] < key) {
            left = mid2 + 1;
        } else {
            right = mid2 - 1;
            left = mid1 + 1;
        }
    }
    return -1;
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    // Here 125 is key which you want to find in array
    int result = ternary_search(arr, arr_size, 125);
    if (result == -1) {
        cout << "Key Not Found" << endl;
    } else {
        cout << "Key Found at position " << result << endl;
    }
}
