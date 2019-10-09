#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int t,cargo, platform,n,k,res, aux, tot, voy,lala;
queue<int> arr[105];
stack<int> pila;

int main()
{
    cin>>t;
    while (t--)
    {
        res = 0;
        tot = 0;
        cin>>n>>cargo>>platform;
        for (int i=0;i<n;i++)
        {
            cin>>k;
            while (k--)
            {
                cin>>aux;
                tot++;
                arr[i].push(aux-1);
            }
        }
        voy = 0;
        while (tot != 0)
        {
            while (!pila.empty() && (arr[voy].size()<platform || pila.top()==voy))
            {
                lala=pila.top();
                if (pila.top()==voy)
                {
                    tot--;
                }
                else
                {
                    arr[voy].push(pila.top());
                }
                pila.pop();
                res++;
            }
            while (pila.size()<cargo && !arr[voy].empty())
            {
                pila.push(arr[voy].front());
                lala=arr[voy].front();
                arr[voy].pop();
                res++;
            }
            if (tot)
            {
                res+=2;
                voy++;
                voy%=n;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
