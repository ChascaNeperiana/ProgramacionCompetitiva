#include <iostream>
using namespace std;

int main() {
    int n, r;
    int caso = 0;
    cin >> r >> n;
    while (r || n) {
        caso++;
        if (r == 0) {
            cout << "Case " << caso << ": 0\n";
        }
        else {
            if (n == 0) {
                cout << "Case " << caso << ": impossible\n";
            }
            else {
                int res = (r - 1) / n;
                cout << "Case " << caso << ": ";
                if(res > 26) {
                    cout<< "impossible";
                }
                else {
                 cout << res;
                }
                cout<<"\n";
            }
        }
        cin >> r >> n;
    }
}
