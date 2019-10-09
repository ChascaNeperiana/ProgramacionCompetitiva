#include <iostream>
#include <cstdio>
using namespace std;
char mapa[110][110];
string instrucciones;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int orientacion;
int fil, col, n, m, inst, res;
bool valido(int fil, int col)
{
    if (mapa[fil][col]=='#') return false;
    if (fil<1 || fil>n) return false;
    if (col<1 || col>m) return false;
    return true;
}
void avanza()
{
    if (valido(fil+dir[orientacion][0], col+dir[orientacion][1]))
    {
        fil+=dir[orientacion][0];
        col+=dir[orientacion][1];
    }
}
void izquierda()
{
    orientacion += 3;
    orientacion %= 4;
}
void derecha()
{
    orientacion++;
    orientacion%=4;
}
int main()
{
    cin>>n>>m>>inst;
    while (n)
    {
        res = 0;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cin>>mapa[i][j];
                if (mapa[i][j]>='A' && mapa[i][j]<='Z')
                {
                    fil = i;
                    col = j;
                    switch (mapa[i][j])
                    {
                    case 'N':
                        orientacion = 0;
                        break;
                    case 'L':
                        orientacion = 1;
                        break;
                    case 'S':
                        orientacion = 2;
                        break;
                    case 'O':
                        orientacion = 3;
                        break;
                    }
                }
            }
        }
        cin>>instrucciones;
        for (int i=0; i<instrucciones.size(); i++)
        {
            switch(instrucciones[i])
            {
            case 'D':
                derecha();
                break;
            case 'E':
                izquierda();
                break;
            case 'F':
                avanza();
                if (mapa[fil][col]=='*')
                {
                    res++;
                    mapa[fil][col]='.';
                }
            }
        }
        cout<<res<<"\n";
        cin>>n>>m>>inst;
    }
    return 0;
}
