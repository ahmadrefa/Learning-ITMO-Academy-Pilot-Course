// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// // Merge two sorted arrays
// vector<int> merge_arrays(vector<int>& a, vector<int>& b) {
//     int i = 0, j = 0;
//     vector<int> c(a.size() + b.size());
//     while (i < a.size() || j < b.size()) {
//         if (j == b.size() || (i < a.size() && a[i] < b[j])) {
//             c[i + j] = a[i];
//             i++;
//         } else {
//             c[i + j] = b[j];
//             j++;
//         }
//     }
//     return c;
// }

// // Using Two Pointers to find elements in one array less than elements in another array
// vector<int> find_less(vector<int>& a, vector<int>& b) {
//     int i = 0, j = 0;
//     vector<int> res(b.size());
//     while (j < b.size() && i < a.size()) {
//         if (a[i] < b[j]) {
//             i++;
//         } else {
//             res[j] = i;
//             j++;
//         }
//     }
//     while (j < b.size()) {
//         res[j] = a.size();
//         j++;
//     }
//     return res;
// }

// // Full example
// int main() {
//     // Example arrays
//     vector<int> a = {1, 3, 5, 8, 10};
//     vector<int> b = {2, 6, 7, 9, 13};

//     // Merge arrays
//     vector<int> c = merge_arrays(a, b);

//     // Find elements in a less than elements in b
//     vector<int> res = find_less(a, b);

//     // Output results
//     for (int x : c) {
//         cout << x << " ";
//     }
//     // cout << endl;
//     // for (int x : res) {
//     //     cout << x << " ";
//     // }
//     cout << endl;

//     return 0;
// }


//////////////////////////////////////////////// C++ ///////////////////////////////////////////////
///------------------------------------///

#include <iostream>
#include <algorithm>
using namespace std;

// Merge two sorted arrays
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
}

// Using Two Pointers to find elements in one array less than elements in another array
int* findLess(int arr1[], int n1, int arr2[], int n2) {
    int* res = new int[n2];
    int i = 0, j = 0;
    while (j < n2 && i < n1) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            res[j] = i;
            j++;
        }
    }
    while (j < n2) {
        res[j] = n1;
        j++;
    }
    return res;
}

// Full example
int main() {
    // Example arrays
    int a[] = {1, 3, 5, 8, 10};
    int b[] = {2, 6, 7, 9, 13};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);

    // Merge arrays
    

    int c[n1+n2];

    mergeArrays(a, n1, b, n2, c);

    // Find elements in a less than elements in b
    int* res = findLess(a, n1, b, n2);

    // Output results
    for (int i = 0; i < n1+n2; i++) {
        cout << c[i] << " ";
    }
    // cout << endl;
    // for (int i = 0; i < n2; i++) {
    //     cout << res[i] << " ";
    // }
    cout << endl;

    // Free memory
    delete[] res;

    return 0;
}

