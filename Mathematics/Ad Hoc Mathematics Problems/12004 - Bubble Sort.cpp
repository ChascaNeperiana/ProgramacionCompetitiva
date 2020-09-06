#include <iostream>
using namespace std;

int main() {
    int t, n;
    long long arr[100005];
    arr[1] = 0;
    for (int i=2; i<=100005; i++) {
        arr[i] = arr[i-1] + i - 1;
    }
    cin>>t;
    for (int caso = 1; caso <= t; caso++) {
        cin>>n;
        cout<<"Case "<<caso<<": ";
        if (arr[n]%2==0) {
            cout<<arr[n]/2<<"\n";
        }
        else {
            cout<<arr[n]<<"/2\n";
        }
    }
}
