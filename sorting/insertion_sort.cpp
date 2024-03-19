#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v {100, 20, 25, 1, 8, 30, 0, -5, -12, 40};

    for(int i = 1; i < v.size(); i++) {
        while(i > 0) {
            int j = i - 1;
            if(v[j] < v[i]) break;
            else {
                swap(v[i], v[j]);
                i--;    
            }
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}