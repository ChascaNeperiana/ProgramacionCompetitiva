#include <cstdio>
using namespace std;

int main() {
    int n, sum;
    scanf("%d",&n);
    printf("PERFECTION OUTPUT\n");
    while (n) {
        sum = 0;
        for (int i=1; i*i<n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != 1) {
                    sum += n/i;
                }
            }
        }
        printf("%*d  ",5,n);
        if (sum < n) {
            printf("DEFICIENT\n");
        }
        if (sum == n) {
            printf("PERFECT\n");
        }
        if (sum > n) {
            printf("ABUNDANT\n");
        }
        scanf("%d",&n);
    }
    printf("END OF OUTPUT\n");
}
