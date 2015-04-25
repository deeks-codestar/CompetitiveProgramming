#include <stdio.h>

long ap_sum(long n, long d)
{
    n = n + 1;
    if (n == 0)
        return 0;
    return ((n-1)*d*n)/2;
}

int main()
{
    int T = 0, i;
    long N = 0, output = 0;
    scanf("%d", &T);
    for (i = 0; i < T ; i++)
    {
        scanf("%ld", &N);
        N = N - 1;
        // Could also do it as sum (N/5) * 5 where sum computes just normal n(n+1)/2
        output = ap_sum(N/3, 3) + ap_sum(N/5, 5) - ap_sum(N/15, 15);
        printf("%ld\n", output);
    }
    return 0;

}
