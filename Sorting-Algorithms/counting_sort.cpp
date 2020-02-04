// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void counting_sort(ln arr[], int arr_size) {
    // find max value in arr
    ln max = INT64_MIN;
    for (int i = 0; i < arr_size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    ln count[max + 1];
    // initialize count[] to 0
    memset(count, 0, sizeof(count));
    // store the frequency of each distinct element of arr[]
    for (int i = 0; i < arr_size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < max + 1; i++) {
        count[i] = count[i] + count[i - 1];
    }
    ln tmp[arr_size];
    for (int i = arr_size - 1; i >= 0; i--) {
        tmp[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < arr_size; i++) {
        arr[i] = tmp[i];
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    counting_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
