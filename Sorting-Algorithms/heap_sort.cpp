// Created by rutvik on 28/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void swap(ln *a, ln *b) {
    ln tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(ln arr[], int root, int arr_size) {
    int current = root;
    int left = current * 2;
    int right = current * 2 + 1;
    // this loop runs until the current element not takes its right place
    while (left < arr_size) {
        if (arr[left - 1] < arr[right - 1] && arr[right - 1] > arr[current - 1]) {
            swap(&arr[right - 1], &arr[current] - 1);
            current = right;
            left = current * 2;
            right = current * 2 + 1;
        } else if (arr[left - 1] >= arr[right - 1] && arr[left - 1] > arr[current - 1]) {
            swap(&arr[left - 1], &arr[current - 1]);
            current = left;
            left = current * 2;
            right = current * 2 + 1;
        } else {
            break;
        }
    }
    // if the right node will not be present in the last level
    if (left == arr_size) {
        if (arr[left - 1] > arr[current - 1]) {
            swap(&arr[left - 1], &arr[current - 1]);
        }
    }
}

void max_heap(ln arr[], int arr_size) {
    // starting from nodes/2
    for (int i = (arr_size / 2); i >= 1; i--) {
        heapify(arr, i, arr_size);
    }
}

void heap_sort(ln arr[], int arr_size) {
    max_heap(arr, arr_size);
    for (int i = 0; i < arr_size - 1; i++) {
        // swap max(root) element to last position
        swap(arr[0], arr[arr_size - i - 1]);
        heapify(arr, 1, arr_size - i - 1);

    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    heap_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
