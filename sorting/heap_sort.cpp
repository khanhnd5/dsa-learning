#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &v, int n, int root) {
    int largest = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if(l < n && v[largest] < v[l]) largest = l;
    if(r < n && v[largest] < v[r]) largest = r;

    if(largest != root) {
        swap(v[largest], v[root]);
        heapify(v, n, largest);
    }
}

void heapSort(vector<int> &v, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    for(int i = n-1; i >= 0; i--) {
        swap(v[i], v[0]);
        heapify(v, i, 0);
    }
}

int main() {
    vector<int> v {100, 20, 25, 1, 8, 30, 0, -5, -12, 40};

    heapSort(v, v.size());

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}