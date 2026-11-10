#include <iostream>
#include <vector>
#include <random>

using namespace std;


static mt19937 rng(random_device{}());

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int st, int end) {
    uniform_int_distribution<int> distrib(st, end);
    int r_pivot = distrib(rng);
    swap(arr[r_pivot], arr[end]);

    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    
    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

void QuickSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int idx = partition(arr, st, end);
        QuickSort(arr, st, idx - 1);
        QuickSort(arr, idx + 1, end);
    }
}

int main() {
    vector<int> arr = {5, 3, 1, 0, 9, 3, 4, 10};

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    QuickSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}