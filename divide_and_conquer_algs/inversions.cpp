//
//  inversions.cpp
//  Based on my Merge Sort implementation
//
//  Created by Adam on 11/25/17.
// Compiled:  g++ -o output_name inversions.cpp

#include <iostream>
#include <vector>
using namespace std;

vector<int>* fillVector();
int SortCountInversions(vector<int>* data, int lhs, int rhs);
int mergeCountSplitInversions(vector<int> *data, int lhs, int rhs, int mid);
void outputVector(vector<int>* data);

int main() {
    vector<int>* data = fillVector();
    cout <<"Current vector:" <<endl;
    outputVector(data);
    int a = SortCountInversions(data, 0, data->size()-1);
    cout <<"Number of inversions: " <<a <<endl;
    // Vector is sorted, output vector contents
    cout <<"Sorted vector: " <<endl;
    outputVector(data);
    return 0;
}

// Method to allow user to enter data into vector
vector<int>* fillVector() {
    int n, iter = 0, temp;
    cout <<"Enter number of elements: ";
    cin >> n;
    
    vector<int>* vec = new vector<int>();
    while (iter != n) {
        cout <<endl <<"Enter numbers to fill array: ";
        cin >> temp;
        vec->push_back(temp);
        iter++;
    }
    return vec;
}

// Recursive function to count inversions of a given vector
int SortCountInversions(vector<int> *data, int lhs, int rhs) {
    // Base case
    if (data->size() < 2) {
        return 0;
    }
    int mid, count = 0;
    if (lhs < rhs) {
        mid = (lhs + rhs) /2;
        count = SortCountInversions(data, lhs, mid);
        count += SortCountInversions(data, mid +1, rhs);
        count += mergeCountSplitInversions(data, lhs, rhs, mid);
    }
    return count;
}

int mergeCountSplitInversions(vector<int>* data, int lhs, int rhs, int mid) {
    int a = lhs;
    int b = mid + 1, c = 0, count = 0;
    int temp[rhs - lhs + 1];
    
    // Merge 2 halfs into a temp array
    while (a <= mid && b <= rhs) {
        if ((*data)[a] <= (*data)[b]) {
            temp[c] = (*data)[a];
            a++;
        } else {
            temp[c] = (*data)[b];
            count += mid - a + 1; // Count inversions
            b++;
        }
        c++;
    }
    
    // Add remaining values from 0 to mid into temp array
    while (a <= mid) {
        temp[c] = (*data)[a];
        c++;
        a++;
    }
    
    // Add remaining values from mid+1 to end into temp array
    while (b <= rhs) {
        temp[c] = (*data)[b];
        c++;
        b++;
    }
    
    // replace unsortedVec with sorted elements in temp array
    for (int i = lhs; i <= rhs; i++) {
        (*data)[i] = temp[i - lhs];
    }
    return count;
}

void outputVector(vector<int> *data) {
    for (int a = 0; a < data->size(); a++) {
        cout <<(*data)[a] <<"  ";
    }
    cout <<endl;
}
