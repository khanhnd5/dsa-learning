#include<iostream>
#include<vector>

using namespace std;

int pivot(int left, int right, vector<int>& v) {
    int count = 0;
    int pivotIndex = left;

    for(int i = left + 1; i <= right; i++) {
        if(v[i] <= v[pivotIndex]) count++;
    }

    pivotIndex += count;

    swap(v[left], v[pivotIndex]);

    int i = left;
    int j = right;
    
    while(i < pivotIndex && j > pivotIndex) {
        while(i < pivotIndex && v[i] <= v[pivotIndex]) i++;
        while(j > pivotIndex && v[j] > v[pivotIndex]) j--;
        if(i < pivotIndex && j > pivotIndex) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int left, int right, vector<int>& v) {
    if(left >= right) return;
    int pivotIndex = pivot(left, right, v);
    quickSort(left, pivotIndex - 1, v);
    quickSort(pivotIndex + 1, right, v);
}

int main() {
    vector<int> v {100, 100, 100, 1, 8, 30, 100, -5, -12, 40};

    quickSort(0, v.size() - 1, v);

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}