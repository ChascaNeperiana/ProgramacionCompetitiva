#include <iostream>
#include <string>
#include <vector>
using namespace std;
string entrada;
bool usa[30];
vector< vector<int> > arbol(30);
int t, trees, acorns;
int elementos(int nodo)
{
    usa[nodo] = true;
    int res = false;
    for (int i=0; i<arbol[nodo].size(); i++)
    {
        if (!usa[arbol[nodo][i]])
        {
            res += elementos(arbol[nodo][i]);
        }
    }
    return res+1;
}
int main()
{
    cin>>t;
    while (t--)
    {
        trees = 0;
        acorns = 0;
        for (int i=0; i<30; i++)
        {
            usa[i] = false;
            arbol[i].clear();
        }
        cin>>entrada;
        while (entrada[0] != '*')
        {
            arbol[entrada[1]-'A'].push_back(entrada[3]-'A');
            arbol[entrada[3]-'A'].push_back(entrada[1]-'A');
            cin>>entrada;
        }
        cin>>entrada;
        for (int i=0; i<entrada.size(); i++)
        {
            if (entrada[i]!=',' && !usa[entrada[i]-'A'])
            {
                if (elementos(entrada[i]-'A')>1)
                {
                    trees++;
                }
                else
                {
                    acorns++;
                }
            }
        }
        cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s).\n";
    }
    return 0;
}
