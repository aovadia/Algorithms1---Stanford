//
//  mergeSort.cpp
//  
//
//  Created by Adam on 11/23/17.
// Compiled: g++ -o output_name mergeSort.cpp
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> *unsortedVec);
void mergeSortRec(vector<int> *unsortedVec, int low, int high);
void merge(vector<int> *unsortedVec, int low, int mid, int high);
void printVector(vector<int> *vec);

int main() {
    // Setup vector of input
    int array[] = {4,63,646,15,25,7,1,4,34,43,673,43,75,36,7856,325,46,2,5,7,3,754,57,574,25,76,63,543,64,4643,63,32,63,86,52,21,43,2,64,6436,635,32,35,25,434,64,345,443,433,0,0,52,5,30,0,52,1};
    
    vector<int> unsorted (array, array + sizeof(array) / sizeof(int));
    cout <<"Printing unsorted vector!" <<endl;
    printVector(&unsorted);
    mergeSort(&unsorted);
    cout <<"Printing sorted vector!" <<endl;
    printVector(&unsorted);
    return 0;
}

// Create wrapper function so user only needs to pass vector
void mergeSort(vector<int> *unsortedVec) {
    mergeSortRec(unsortedVec, 0, unsortedVec->size()-1);
}

void mergeSortRec(vector<int> *unsortedVec, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        
        mergeSortRec(unsortedVec, low, mid);
        mergeSortRec(unsortedVec, mid + 1, high);
        
        merge(unsortedVec, low, high, mid);
    }
}

// Merge 2 halfs of a sorted vector
void merge(vector<int> *unsortedVec, int low, int high, int mid) {
    int a = low;
    int b = mid + 1, c = 0;
    int temp[high - low + 1];
    
    // Merge 2 halfs into a temp array
    while (a <= mid && b <= high) {
        if ((*unsortedVec)[a] < (*unsortedVec)[b]) {
            temp[c] = (*unsortedVec)[a];
            a++;
        } else {
            temp[c] = (*unsortedVec)[b];
            b++;
        }
        c++;
    }
    
    // Add remaining values from 0 to mid into temp array
    while (a <= mid) {
        temp[c] = (*unsortedVec)[a];
        c++;
        a++;
    }
    
    // Add remaining values from mid+1 to end into temp array
    while (b <= high) {
        temp[c] = (*unsortedVec)[b];
        c++;
        b++;
    }
    
    // replace unsortedVec with sorted elements in temp array
    for (int i = low; i <= high; i++) {
        (*unsortedVec)[i] = temp[i - low];
    }
}

// output content of vector to stout
void printVector(vector<int> *vec) {
    for (int a = 0; a < vec->size(); a++) {
        cout <<(*vec)[a] <<"  ";
    }
    cout <<endl;
}
