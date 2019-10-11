#include <iostream>
#include <queue>
using namespace std;
class cosa{
public:
    int num, pasos;
}act, aux;
bool usa[10005];
int botones[20];
int l,r,u,res,caso;
queue<cosa> cola;
int main()
{
    cin>>l>>u>>r;
    while (l || u || r)
    {
        caso++;
        while (!cola.empty())
        {
            cola.pop();
        }
        for (int i=0; i<r; i++)
        {
            cin>>botones[i];
        }
        for (int i=0; i<10000; i++)
        {
            usa[i] = false;
        }
        act.num = l;
        act.pasos = 0;
        cola.push(act);
        usa[l] = true;
        res = -1;
        while (!cola.empty())
        {
            act = cola.front();
            cola.pop();
            if (u == act.num)
            {
                res = act.pasos;
            }
            for (int i=0; i<r; i++)
            {
                aux.num = (act.num+botones[i])%10000;
                aux.pasos = act.pasos + 1;
                if (!usa[aux.num])
                {
                    cola.push(aux);
                    usa[aux.num] = true;
                }
            }
        }
        cout<<"Case "<<caso<<": ";
        if (res==-1)
        {
            cout<<"Permanently Locked\n";
        }
        else
        {
            cout<<res<<"\n";
        }
        cin>>l>>u>>r;
    }
    return 0;
}
