#include <stdio.h>
#include <string.h>
#define MAX_DENOMINATIONS 250

long max_ways_coin_change(int N, int M, int *C)
{
    long OPT[M+1][N+1];
    int n = 0, m = 0, i = 0;
    // Fastest way to intialize all the elements in OPT to zero
    memset(OPT, 0, (sizeof(OPT[0][0])* (M+1) * (N+1)));

    for (i = 0; i <= M; i++)
    {
        OPT[i][0] = 1;
    }
    for (m = 1; m <= M; m++)
    {
        for (n = 1; n <= N; n++)
        {
            if (n >= C[m-1])
                OPT[m][n] = OPT[m][n-C[m-1]];
            OPT[m][n] += OPT[m-1][n];
        }
    }
    
    return OPT[M][N];
}

int main()
{
    int C[MAX_DENOMINATIONS];
    int N = 0, M = 0, i;

    scanf("%d", &N);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
        scanf("%d", &C[i]);
    
    printf("%ld",max_ways_coin_change(N, M, C));
    return 0;
}
