#include <iostream>

using namespace std;

long long res[60][60];
int n, m, k;

int main()
{
    while (cin>>n>>k>>m)
    {
        for (int i=0; i<=n; i++)
        {
            for (int j=0; j<=k; j++)
            {
                res[i][j] = 0;
            }
        }
        res[0][0] = 1;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=k; j++)
            {
                for (int lala=1; lala<=m; lala++)
                {
                    if (i-lala>=0)
                    {
                        res[i][j] += res[i-lala][j-1];
                    }
                }
            }
        }
        cout<<res[n][k]<<endl;
    }
    return 0;
}
