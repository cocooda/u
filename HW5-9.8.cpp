#include <iostream>
#include <vector>
#include <map>

using namespace std;

int find_mode(int* arr, int size) {
    map<int, int> freq_map;
    for (int i = 0; i < size; i++) {
        freq_map[*(arr + i)]++;
    }

    int mode = -1;
    int max_count = 1;
    for (auto& pair : freq_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode = pair.first;
        }
    }

    return (max_count > 1) ? mode : -1;
}

int main() {
    int size;
    cout << "Number of elements in the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter elements of the array: ";
    for (int i =0; i<size; i++) {
        cin >> arr[i];
        cout << endl;
    }

    int mode = find_mode(arr, size);

    if (mode != -1) {
        cout << "The mode of the array is: " << mode << endl;
    } else {
        cout << "The array has no mode." << endl;
    }

    return 0;
}
