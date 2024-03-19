#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v {100, 20, 25, 1, 8, 30, 0, -5, -12, 40};

    for(int i = 0; i < v.size(); i++) {
        int min = i;
        for(int j = i + 1; j < v.size(); j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        swap(v[i], v[min]);   
    }

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }

    cout<<endl;
}