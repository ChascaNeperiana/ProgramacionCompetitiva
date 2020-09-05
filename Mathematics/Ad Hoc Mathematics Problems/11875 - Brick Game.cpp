#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    int arr[15];
    cin>>t;
    for (int caso = 1; caso <= t; caso++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<"Case "<<caso<<": "<<arr[n/2]<<"\n";
    }
}
