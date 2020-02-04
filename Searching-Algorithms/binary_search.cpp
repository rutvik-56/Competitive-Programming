// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

int binary_search(ln arr[], int arr_size, ln key) {
    int left = 0, right = arr_size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid + 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    int result = binary_search(arr, arr_size, 125);
    if (result == -1) {
        cout << "Key Not Found" << endl;
    } else {
        cout << "Key Found at position " << result << endl;
    }
}
