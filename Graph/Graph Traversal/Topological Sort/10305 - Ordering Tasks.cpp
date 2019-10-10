#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int grafica[105][105], n, m, a, b;
stack<int> pila;
bool usa[105];
void ordenar(int nodo)
{
    usa[nodo] = true;
    for (int i=1; i<=n; i++)
    {
        if (!usa[i] && grafica[nodo][i]==1)
        {
            ordenar(i);
        }
    }
    pila.push(nodo);
}
int main()
{
    cin>>n>>m;
    while (n)
    {
        for (int i=0; i<=n; i++)
        {
            usa[i] = false;
            for (int j=1; j<=n; j++)
            {
                grafica[i][j] = 0;
            }
        }
        for (int i=0; i<m; i++)
        {
            cin>>a>>b;
            grafica[a][b] = 1;
        }
        for (int i=1; i<=n; i++)
        {
            if (!usa[i])
            {
                ordenar(i);
            }
        }
        while (!pila.empty())
        {
            cout<<pila.top()<<" ";
            pila.pop();
        }
        cout<<"\n";
        cin>>n>>m;
    }
    return 0;
}
