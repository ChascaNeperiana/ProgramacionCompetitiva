#include <iostream>

using namespace std;
int res[105][105];
int n,k;
int formas(int n, int k)
{
    if (res[n][k] == 0)
    {
        if (k==1)
        {
            return res[n][k] = 1;
        }
        for (int i=0;i<=n;i++)
        {
            res[n][k] += formas(n-i,k-1);
            res[n][k] %= 1000000;
        }
    }
    return res[n][k];
}
int main()
{
    cin>>n>>k;
    while (n || k)
    {
        cout<<formas(n,k)<<endl;
        cin>>n>>k;
    }
    return 0;
}
