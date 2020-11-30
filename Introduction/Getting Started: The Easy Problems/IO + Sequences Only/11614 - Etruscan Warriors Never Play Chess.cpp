#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int t;
long long n, res;
int main()
{
    cin>>t;
    while (t--) {
        cin>>n;
        res = -1;
        res +=sqrt(1+8*n);
        res/=2;
        cout<<res<<endl;
    }
    return 0;
}
