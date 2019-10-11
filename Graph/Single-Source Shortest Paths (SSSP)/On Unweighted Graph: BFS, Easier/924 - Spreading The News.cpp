#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class cosa{
public:
    int empleado, dia;
}act, aux;
queue<cosa> cola;
int n,m,t,s,ma,dia,k,tdia,tma;
vector< vector<int> > grafica;
bool usa[2505];
int main()
{
    cin>>n;
    grafica.resize(n);
    for (int i=0; i<n; i++)
    {
        cin>>m;
        for (int j=0; j<m; j++)
        {
            cin>>k;
            grafica[i].push_back(k);
        }
    }
    cin>>t;
    while (t--)
    {
        cin>>s;
        dia = 0;
        ma = 0;
        act.dia = 0;
        act.empleado = s;
        cola.push(act);
        tdia = 0;
        tma = 0;
        for (int i=0; i<n; i++)
        {
            usa[i] = false;
        }
        usa[s] = true;
        while (!cola.empty())
        {
            act = cola.front();
            cola.pop();
            if (act.dia != tdia)
            {
                if (tma > ma)
                {
                    dia = tdia;
                    ma = tma;
                }
                tdia = act.dia;
                tma = 1;
            }
            else
            {
                if (act.dia != 0)
                    tma++;
            }
            for (int i=0; i<grafica[act.empleado].size(); i++)
            {
                if (!usa[grafica[act.empleado][i]])
                {
                    aux.empleado = grafica[act.empleado][i];
                    aux.dia = act.dia + 1;
                    usa[aux.empleado] = true;
                    cola.push(aux);
                }
            }
        }
        if (tma > ma)
        {
            dia = tdia;
            ma = tma;
        }
        tdia = act.dia;
        tma = 1;
        if (dia == 0)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<ma<<" "<<dia<<"\n";
        }
    }
    return 0;
}
