#include <stdio.h>
#define MAX_LEN 2000

int max_of_3(int a, int b, int c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}

int find_max_sum(int N, int K, int *A)
{

    int OPT[N+1][K+1];
    int k = 0, n = 0;
    int value1 = 0, value2 = 0, value3 = 0;

    for (n = 0; n <= N; n++)
    {
        for (k = 0; k <= K; k++)
        {   
            if (n == 0 || k == 0)
            {
                OPT[n][k] = 0;
            }
            else
            {
                if (k >= A[n-1])
                {
                    value1 = OPT[n - 1][k - A[n-1]] + A[n-1];
                    value2 = OPT[n][k - A[n-1]] + A[n-1];
                    //value2 = 0;
                }
                value3 = OPT[n-1][k];
                printf("\n n: %d k: %d v1: %d v2: %d v3: %d", n, k, value1, value2, value3);
                OPT[n][k] = max_of_3(value1, value2, value3);
                value1 = 0;
                value2 = 0;
                value3 = 0;
            }
        }   
    }
    for (n = 0; n <= N; n++)
    {
        for (k = 0; k <= K; k++)
        {   
            printf("%d ", OPT[n][k]);
        }   
        printf("\n");
    }

    return OPT[N][K];
}

int main()
{
    int T = 0, K = 0, N = 0;
    int a[MAX_LEN];
    int i = 0, j = 0;

    //scanf("%d", &T);
    //for (i = 0; i < T; i++)
    {
        scanf("%d", &N);
        scanf("%d", &K);
        for (j = 0; j < N; j++)
            scanf("%d", &a[j]);

        printf("%d\n",find_max_sum(N, K, a));
    }
}
