#include <iostream>

using namespace std;
int grafica[205][205];
int color[205];
int n,m,a,b;
bool colorear(int nodo, int c)
{
    color[nodo] = c;
    bool res = true;
    for (int i=0; i<n; i++)
    {
        if (grafica[nodo][i]==1)
        {
            if (color[i]==-1)
            {
                res = colorear(i, (c+1)%2);
            }
            else
            {
                if (color[i]==c)
                {
                    return false;
                }
            }
        }
    }
    return res;
}
int main()
{
    cin>>n;
    while (n)
    {
        for (int i=0; i<n; i++)
        {
            color[i] = -1;
            for (int j=0; j<n; j++)
            {
                grafica[i][j] = -1;
            }
        }
        cin>>m;
        for (int i=0; i<m; i++)
        {
            cin>>a>>b;
            grafica[a][b] = grafica[b][a] = 1;
        }
        cout<<(colorear(0,0)?"BICOLORABLE.\n":"NOT BICOLORABLE.\n");
        cin>>n;
    }
    return 0;
}
