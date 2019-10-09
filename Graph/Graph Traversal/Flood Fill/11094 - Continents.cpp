#include <iostream>
#include <cstdio>
using namespace std;
int n,m,f0, c0,ma;
string mapa[20];
bool usa[20][20];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
char l;
bool valido(int fil, int col)
{
    return fil>=0 && fil<n;
}
int elementos(int fil, int col)
{
    usa[fil][col]=true;
    int res = 0;
    for (int i=0; i<4; i++)
    {
        int sfil = fil+dir[i][0];
        int scol = (col+dir[i][1]+m)%m;
        if (valido(sfil,scol) && !usa[sfil][scol] && mapa[sfil][scol]==l)
        {
            res += elementos(sfil,scol);
        }
    }
    return res+1;
}
int main()
{
    while (cin>>n>>m)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                usa[i][j]=false;
            }
        }
        for (int i=0; i<n; i++)
        {
            cin>>mapa[i];
        }
        cin>>f0>>c0;
        l = mapa[f0][c0];
        elementos(f0,c0);
        ma = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (mapa[i][j]==l && !usa[i][j])
                {
                    ma = max(ma, elementos(i,j));
                }
            }
        }
        cout<<ma<<"\n";
    }
    return 0;
}
