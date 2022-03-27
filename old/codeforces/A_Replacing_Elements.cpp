#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void heapify(int* arr, int i, int n) {
    int least = -1;
    if (i*2 + 1 < n && arr[i] > arr[i*2 + 1]) {
        least = i*2 + 1;
        swap(arr[i], arr[i*2+1]);
    }
    if ((i+1)*2 < n && arr[i] > arr[(i+1)*2]) { 
        least = (i+1)*2;
        swap(arr[i], arr[(i+1)*2]);
    }
    if (least != -1) {
        heapify(arr, least, n);
    }
}

void makeheap(int* arr, int n) {
    for (int i = n/2 - 1; i >= 0; --i) {
        heapify(arr, i, n);
    }
}

int popheap(int* arr, int n) {
    int out = arr[0];
    swap(arr[0], arr[n-1]);
    heapify(arr, 0, n-1);
    return out;
}

int main() {
    int arr[100];
    int arr2[100];
    int t;
    cin >> t;
    while (t --) {
        int n, d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        makeheap(arr, n);
        for (int i = 0; i < n; ++i) {
            int a = popheap(arr, n-i);
            arr2[i] = a;
        }
        int left = 0;
        int right = n;

        while (left < right) {
            int middle = (left + right) / 2;
            if (arr2[middle] <= d) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        if (left == n) {
            cout <<"YES" <<endl;
        } else if (arr2[0] + arr2[1] <= d) {
            cout <<"YES" <<endl;
        } else {
            cout << "NO" << endl;
        }
    }
}