#include<iostream>
#include<vector>

using namespace std;

void merge(int left, int right, int mid, vector<int>& v) {
    vector<int> leftSorted;
    vector<int> rightSorted;

    for(int i = left; i <= mid; i++) {
        leftSorted.push_back(v[i]);
    }

    for(int j = mid + 1; j <= right; j++) {
        rightSorted.push_back(v[j]);
    }

    int index = left;
    int i = 0;
    int j = 0;

    while(i < leftSorted.size() && j < rightSorted.size()) {
        if(leftSorted[i] <= rightSorted[j]) {
            v[index++] = leftSorted[i++];
        } else {
            v[index++] = rightSorted[j++];
        }
    }

    while(i < leftSorted.size()) {
        v[index++] = leftSorted[i++];
    }

    while(j < rightSorted.size()) {
        v[index++] = rightSorted[j++];
    }
}

void mergeSort(int left, int right, vector<int>& v) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid, v);
    mergeSort(mid + 1, right, v);
    merge(left, right, mid, v);
}

int main() {
    vector<int> v {100, 100, 100, 1, 8, 30, 100, -5, -12, 40};

    mergeSort(0, v.size() - 1, v);

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}