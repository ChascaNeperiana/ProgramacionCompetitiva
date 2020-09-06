#include <iostream>
using namespace std;

int main() {
    int t;
    long long n,m;

    cin>>t;
    while (t--) {
        cin>>m>>n;
        cout<<(n*(n-1)-(n-m)*(n-m-1))/2<<"\n";
    }
}
