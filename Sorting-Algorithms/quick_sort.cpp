// Created by rutvik on 28/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void swap(ln *a, ln *b) {
    ln tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(ln arr[], int start, int end) {
    ln pivot = start;
    while (start < end) {
        while (start <= end && arr[pivot] >= arr[start]) {
            start++;
        }
        while (start <= end && arr[pivot] < arr[end]) {
            end--;
        }
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[pivot], arr[end]);
    return end;
}

void quick_sort(ln arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, 0, arr_size - 1);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
