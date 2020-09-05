#include <cstdio>
#include <cmath>
using namespace std;

#define EPS 1e-8

int main() {
    int t, caso;
    double d, v, u, t1, t2;
    scanf("%d", &t);
    for (int caso = 1; caso <=t; caso++) {
        scanf("%lf%lf%lf",&d,&v,&u);
        if (abs(v) < EPS || v > u || abs(u-v) < EPS) {
            printf("Case %d: can't determine\n", caso);
        }
        else {
            t1 = d/u;
            t2 = d/sqrt(u*u-v*v);
            printf("Case %d: %.3lf\n",caso, t2-t1);
        }
    }
}
