#include <iostream>
#include <queue>
using namespace std;
#define INF 100000000
class cosa{
public:
    int fil, col, dist;
}act, aux;
bool operator <(cosa c1, cosa c2)
{
    return c1.dist > c2.dist;
}
priority_queue<cosa> monticulo;
int mapa[1005][1005], dist[1005][1005];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,t;
bool valido(int fil, int col)
{
    return fil>0 && fil<=n && col>0 && col <=m;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                dist[i][j] = INF;
                cin>>mapa[i][j];
            }
        }
        dist[1][1] = mapa[1][1];
        act.fil = 1;
        act.col = 1;
        act.dist = mapa[1][1];
        monticulo.push(act);
        while (!monticulo.empty())
        {
            act = monticulo.top();
            monticulo.pop();
            if (act.dist == dist[act.fil][act.col])
            {
                for (int i=0; i<4; i++)
                {
                    int sfil = act.fil + dir[i][0];
                    int scol = act.col + dir[i][1];
                    if (act.dist + mapa[sfil][scol] < dist[sfil][scol] && valido(sfil,scol))
                    {
                        dist[sfil][scol] = act.dist + mapa[sfil][scol];
                        aux.fil = sfil;
                        aux.col = scol;
                        aux.dist = dist[sfil][scol];
                        monticulo.push(aux);
                    }
                }
            }
        }
        cout<<dist[n][m]<<"\n";
    }
    return 0;
}
