// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void counting_sort(ln arr[], int arr_size, int devide);
void radix_sort(ln arr[], int arr_size) {
    // find max value in arr
    ln max = INT64_MIN;
    for (int i = 0; i < arr_size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    int devide = 1;
    while (max) {
        counting_sort(arr, arr_size, devide);
        devide *= 10;
        max /= 10;
    }
}

void counting_sort(ln arr[], int arr_size, int devide) {
    ln count[10];
    // initialize count[] to 0
    memset(count, 0, sizeof(count));
    // store the frequency of each distinct element of arr[]
    for (int i = 0; i < arr_size; i++) {
        count[(arr[i] / devide) % 10]++;
    }
    for (int i = 1; i < 11; i++) {
        count[i] = count[i] + count[i - 1];
    }
    ln tmp[arr_size];
    for (int i = arr_size - 1; i >= 0; i--) {
        tmp[--count[(arr[i] / devide) % 10]] = arr[i];
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
    radix_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
