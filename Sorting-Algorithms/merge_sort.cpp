// Created by rutvik on 28/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void merge(ln arr[], int start, int end) {
    int mid = (start + end) / 2;
    int left_size = mid - start + 1;
    int right_size = end - mid;
    ln left[left_size], right[right_size];
    for (int i = start; i <= mid; i++) {
        left[i - start] = arr[i];
    }
    for (int i = mid + 1; i <= end; i++) {
        right[i - mid - 1] = arr[i];
    }
    int left_index = 0, right_index = 0;
    for (int i = start; i <= end; i++) {
        if (left_index >= left_size) {
            arr[i] = right[right_index];
            right_index++;
            continue;
        }
        if (right_index >= right_size) {
            arr[i] = left[left_index];
            left_index++;
            continue;
        }
        if (left[left_index] <= right[right_index]) {
            arr[i] = left[left_index];
            left_index++;
        } else {
            arr[i] = right[right_index];
            right_index++;
        }
    }
}

void merge_sort(ln arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ln arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, arr_size - 1);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
