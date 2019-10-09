#include <iostream>
#include <set>
using namespace std;
multiset<long long> s;
long long n, k, aux, chico, grande, res, lala;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    while (n)
    {
        res = 0;
        for (int i=0; i<n; i++)
        {
            cin>>k;
            for (int i=0; i<k; i++)
            {
                cin>>aux;
                s.insert(aux);
            }
            lala = s.size();
            chico = *s.begin();
            grande = *s.rbegin();
            res += grande-chico;
            s.erase(s.lower_bound(chico));
            s.erase(s.lower_bound(grande));
            lala=s.size();
        }
        s.clear();
        cout<<res<<"\n";
        cin>>n;
    }
    return 0;
}
