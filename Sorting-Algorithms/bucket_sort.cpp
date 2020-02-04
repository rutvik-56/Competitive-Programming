// Created by rutvik on 27/01/20.

#include "bits/stdc++.h"

#define ld long double
using namespace std;

void bucket_sort(ld arr[], int arr_size) {
    //create 10 bucket for 0-9
    vector<ld> bucket[10];
    for (int i = 0; i < arr_size; i++) {
        //put element into bucket
        bucket[((int) arr[i] * 10)].emplace_back(arr[i]);
    }
    //sort all individual bucket
    for (int i = 0; i < 10; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int position = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[position++] = bucket[i][j];
        }
    }
}

int main() {
    int arr_size;
    cin >> arr_size;
    ld arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    bucket_sort(arr, arr_size);
    // print the array
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}
