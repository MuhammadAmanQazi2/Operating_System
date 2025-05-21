#include <iostream>
#include <vector>

using namespace std;

// Function to update the vector in Most Recently Used (MRU) fashion
void updateMRU(vector<int>& arr, int elem) {
    int size = arr.size();
    int index = elem % size;
    int value = arr[index];

    // Shift elements to the right up to index
    for (int i = index; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
}

// Function to print the vector
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int elem = 3;
    vector<int> arr = {6, 1, 9, 5, 3};

    updateMRU(arr, elem);

    cout << "Array in Most Recently Used (MRU) fashion: ";
    printArray(arr);

    return 0;
}
