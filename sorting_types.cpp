#include <iostream>
using namespace std;

const int N = 10;
void buble_sort(int arr[]) {
    bool SWAP = true;
    while (SWAP) {
        SWAP = false;
        for (int i(0); i < (N - 1); i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                SWAP = true;
            }
        }
    }
    for (int i(0); i < N; i++) {
        cout << arr[i] << ' ';
    }
}

void shaker_sort(int arr[]) {
    int start = 0; 
    int end = N - 1;
    for (int i(0); i < end; i++) {

        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);

        }
        for (int j(end); j > start; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);

            }
        }
    }
    for (int i(0); i < N; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {

    //int arr[40] = {41, 63, 20, 9, 36, 47, 31, 75, 95, 16, 60, 29, 0, 89, 68, 98, 23, 33, 58, 50, 24, 99, 3, 43, 64, 5, 4, 19, 34, 66, 35, 44, 26, 92, 11, 38, 74, 90, 21, 10};
    int arr[N] = {};
    for (int i(0); i < N; i++) {
        cin >> arr[i];
    }
    
    shaker_sort(arr);
    buble_sort(arr);
    return 0;
}
