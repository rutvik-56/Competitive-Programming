// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void insertion_sort(ln arr[], int arr_size) {
    for (int i = 1; i < arr_size; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                // for swap the value arr[j-1] and arr[j]
                ln tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            } else {
                break;
            }
        }
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
