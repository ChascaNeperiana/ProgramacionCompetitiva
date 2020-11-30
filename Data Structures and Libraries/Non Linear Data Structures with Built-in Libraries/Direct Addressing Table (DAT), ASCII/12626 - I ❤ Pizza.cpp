#include <iostream>
#include <cmath>
using namespace std;
string s;
int arr[30], t, res;
int main()
{
    cin>>t;
    while (t--) {
        cin>>s;
        for (int i=0; i<26; i++) {
            arr[i] = 0;
        }
        for (int i=0; i<s.size(); i++) {
            arr[s[i]-'A']++;
        }
        res = s.size();
        res = min(res, arr['M' - 'A']);
        res = min(res, arr['A' - 'A']/3);
        res = min(res, arr['R' - 'A']/2);
        res = min(res, arr['G' - 'A']);
        res = min(res, arr['I' - 'A']);
        res = min(res, arr['T' - 'A']);
        cout<<res<<endl;
    }
    return 0;
}
