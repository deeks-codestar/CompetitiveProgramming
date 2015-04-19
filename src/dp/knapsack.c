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
            // n=0 implies, o elements are taken, k=0 implies, max allowable sum is 0.
            // Hence the values of OPT for n or k = 0 is zero
            if (n == 0 || k == 0)
            {
                OPT[n][k] = 0;
            }
            else    
            {
                // Only if there is suffienct weight left to be subtracted from. 
                // If you dont check this condition can lead to negative index
                if (k >= A[n-1])   
                {
                    value1 = OPT[n - 1][k - A[n-1]] + A[n-1]; //Include the nth item once
                    value2 = OPT[n][k - A[n-1]] + A[n-1];   // Include the nth item repeatedly
                }
                value3 = OPT[n-1][k];   // nth item is not included
                OPT[n][k] = max_of_3(value1, value2, value3);
                //Reset values otherwise could cause using of wrong values across loops
                value1 = 0;
                value2 = 0;
                value3 = 0;
            }
        }   
    }
    return OPT[N][K];
}

int main()
{
    int T = 0, K = 0, N = 0;
    int A[MAX_LEN];
    int i = 0, j = 0;

    // Scan the number of test cases
    scanf("%d", &T);
    // Process each test case.
    for (i = 0; i < T; i++)
    {
        scanf("%d", &N);
        scanf("%d", &K);
        for (j = 0; j < N; j++)
            scanf("%d", &A[j]);

        printf("%d\n",find_max_sum(N, K, A));
    }
}
