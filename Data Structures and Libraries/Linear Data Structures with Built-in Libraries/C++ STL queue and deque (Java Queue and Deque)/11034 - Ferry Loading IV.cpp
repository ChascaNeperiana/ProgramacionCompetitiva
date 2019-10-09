#include <iostream>
#include <queue>
using namespace std;
queue<int> der, izq;
string lado;
int t,l,m,k,res,llevo,voy;
int main()
{
    cin>>t;
    while (t--)
    {
        res = 0;
        cin>>l>>m;
        l*=100;
        for (int i=0;i<m;i++)
        {
            cin>>k>>lado;
            if (lado[0]=='r') der.push(k);
            else izq.push(k);
        }
        voy=0;
        while (!izq.empty() || !der.empty())
        {
            llevo = 0;
            if (voy==0)
            {
                while (!izq.empty() && llevo+izq.front()<=l)
                {
                    llevo+=izq.front();
                    izq.pop();
                }
                res++;
                voy++;
                voy%=2;
            }
            else
            {
                while (!der.empty() && llevo+der.front()<=l)
                {
                    llevo+=der.front();
                    der.pop();
                }
                res++;
                voy++;
                voy%=2;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
