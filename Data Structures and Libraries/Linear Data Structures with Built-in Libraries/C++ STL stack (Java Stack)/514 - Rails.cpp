#include <iostream>
#include <stack>
using namespace std;
stack<int> vias;
int arr[1010],n,voy;
int main()
{
    cin>>n;
    while (n)
    {
        cin>>arr[0];
        while (arr[0])
        {
            for (int i=1; i<n; i++)
            {
                cin>>arr[i];
            }
            voy=0;
            for (int i=1;i<=n;i++)
            {
                vias.push(i);
                while (!vias.empty() && vias.top()==arr[voy])
                {
                    voy++;
                    vias.pop();
                }
            }
            cout<<(voy==n?"Yes":"No")<<endl;
            cin>>arr[0];
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}
