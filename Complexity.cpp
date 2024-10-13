#include <iostream>
#include <vector>
#include <ctime> // for measuring execution time

using namespace std;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is already sorted
        if (!swapped) break;
    }
}

// Merge Sort helper functions
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Enter the number of deliveries: ";
    cin >> N;

    vector<int> deliveryTimes(N);
    cout << "Enter the delivery times (in minutes):" << endl;
    for (int i = 0; i < N; i++) {
        cin >> deliveryTimes[i];
    }

    // Bubble Sort
    vector<int> bubbleSortedTimes = deliveryTimes; // Copy original list for bubble sort
    clock_t start = clock();
    bubbleSort(bubbleSortedTimes);
    clock_t end = clock();
    double bubbleSortTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted delivery times using Bubble Sort: ";
    for (int time : bubbleSortedTimes) cout << time << " ";
    cout << endl;
    cout << "Bubble Sort Time: " << bubbleSortTime << " seconds" << endl;

    // Merge Sort
    vector<int> mergeSortedTimes = deliveryTimes; // Copy original list for merge sort
    start = clock();
    mergeSort(mergeSortedTimes, 0, N - 1);
    end = clock();
    double mergeSortTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted delivery times using Merge Sort: ";
    for (int time : mergeSortedTimes) cout << time << " ";
    cout << endl;
    cout << "Merge Sort Time: " << mergeSortTime << " seconds" << endl;

    return 0;
}