#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 1000

inline int max(int a, int b, int c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b: c;
}

inline int max_of_2(int a, int b)
{
        return (a > b) ? a : b;
} 

int main() 
{
    // declaration and intializations
    int N = 0, M = 0, i, value = 0, m = 0, n = 0;
    int a[MAX_LEN], b[MAX_LEN];
    int OPT[MAX_LEN][MAX_LEN];
    
    // Get inputs from user
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

    // DP where OPT[n][m] represents the longest common subsequence found among 
    // the first n characters of string a and first m characters of string b.
    for (n = 1; n <= N; n++)
    {
        for (m = 1; m <= M; m++)
        {
            if (a[n-1] == b[m-1])
            {
                OPT[n][m] = OPT[n-1][m-1] + 1;
            }
            else 
                OPT[n][m] = max_of_2(OPT[n][m-1], OPT[n-1][m]);
        }
    }
    
    //DEBUG: Print the characters of OPT array
    n = N;
    m = M;
    for (n = 0; n <= N; n++)
    {
        for (m = 0; m <= M; m++)
        {   
            printf("%d ", OPT[n][m]);
        }   
        printf("\n");
    }
    
    // LCS is the last element.
    int max_len = OPT[N][M];
    n = N;
    m = M;
    int output[max_len + 1];
    output[max_len] = '\0';
    i = max_len - 1;

    // Find LCS and populate the value of LCS into output array
    // WHY: Because, we will find the LCS in the reverse order.
    // We need to print it in the sequential order.   
    while (n > 0 && m > 0)
    {
        printf("\n %d %d ", n,m);
        if (a[n-1] == b[m-1])
        {
            printf("   %d ", a[n-1]);
            output[i--] = a[n-1];
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
    }
    
    // Print the LCS 
    for (i = 0; i < max_len; i++)
    {
        printf("%d ", output[i]);
    }

    return 0;
}
