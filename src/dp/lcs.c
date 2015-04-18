#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 1000

int max(int a, int b, int c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b: c;
}
int main() 
{
    int N = 0, M = 0, i, value = 0, m = 0, n = 0;
    int a[MAX_LEN], b[MAX_LEN];
    int OPT[MAX_LEN][MAX_LEN];
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        OPT[i][0] = 0;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d", &b[i]);
        OPT[0][i] = 0;
    }


    for (n = 1; n <= N; n++)
    {
        for (m = 1; m <= M; m++)
        {
            if (a[n] == b[m])
            {
                value = OPT[n-1][m-1] + 1;
            }
            OPT[n][m] = max(value, OPT[n][m-1], OPT[n-1][m]);
        }
    }

    int max_len = OPT[N][M];

    n = N;
    m = M;
    int output[max_len];
    i = max_len - 1;

    while (max_len > 0)
    {
        if (((1 + OPT[n-1][m-1]) >= OPT[n-1][m]) &&  ((1 + OPT[n-1][m-1]) >= OPT[n][m - 1]))
        {

            output[i] = a[n-1];
            i--;
            n--;
            m--;   
        }
        else if (OPT[n-1][m] > OPT[n][m-1])
        {

            n--;
        }
        else
        {

            m--;
        }
        max_len--;

    }
    max_len = OPT[N][M];
    i = 0;
    while (max_len > 0)
    {
        printf("%d ", output[i]);
        max_len--;
        i++;

    }

    return 0;
}
