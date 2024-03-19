#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v {100, 20, 25, 1, 8, 30, 0, -5, -12, 40};

    while(true) {
        bool check = true;

        for(int i = 0; i < v.size() - 1; i++) {
            if(v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                check = false;
            }
        }

        if(check) break; 
    }

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}