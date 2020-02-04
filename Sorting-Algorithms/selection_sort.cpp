// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void selection_sort(ln arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        ln min = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // for swap the value arr[i] and arr[min]
        ln tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    selection_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
