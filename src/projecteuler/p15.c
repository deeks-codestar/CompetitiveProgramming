#include <stdio.h>
#define MAX 507
#define MAX_GRID 500
#define MOD 1000000007
int main()
{

    int T = 0, N = 0, M = 0,i,j;
    int OPT[MAX][MAX];
    // Zero ways to go from (0,0) to (0,0)
    OPT[0][0] = 0;

    // When the point is on the x axis there is only one way of reaching
    // (0,0)
    for ( i = 1; i <= MAX_GRID; i++)
        OPT[0][i] = 1;

    // When the point is on the y axis there is only one way of reaching
    // (0,0)
    for ( i = 1; i <= MAX_GRID; i++)
        OPT[i][0] = 1;

    // At every point there are two possible ways of moving either up or
    // left. 
    for (i = 1; i <= MAX_GRID; i++)
        for (j = 1; j<= MAX_GRID; j++)
            OPT[i][j] = (OPT[i-1][j] + OPT[i][j-1]) % MOD;


    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &M);
        scanf("%d", &N);

        printf("%d\n", OPT[M][N]);

    }
    return 0;
}
