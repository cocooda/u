#include <iostream>
#include <vector>
using namespace std;

void swap_max_min(vector<int>& arr) {
    int *max_element = &arr[0];
    int *min_element = &arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > *max_element) {
            max_element = &arr[i];
        } else if (arr[i] < *min_element) {
            min_element = &arr[i];
        }
    }

    int temp = *max_element;
    *max_element = *min_element;
    *min_element = temp;
}

void print_array(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 2, 3, 1, 5, 6, 4};
    
    cout << "Original array: ";
    print_array(arr);

    swap_max_min(arr);

    cout << "Array after swapping max and min: ";
    print_array(arr);

    return 0;
}
