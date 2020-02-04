// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

int linear_search(ln arr[], int arr_size, ln key) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == key) {
            return i + 1;
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
    int result = linear_search(arr, arr_size, 125);
    if (result == -1) {
        cout << "Key Not Found" << endl;
    } else {
        cout << "Key Found at position " << result << endl;
    }
}
