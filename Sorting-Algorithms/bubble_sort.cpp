// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void bubble_sort(ln arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // for swap the value arr[j] and arr[j+1]
                ln tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
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
    bubble_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
