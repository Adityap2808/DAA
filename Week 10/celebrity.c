#include <stdio.h>

#define N 4  


int knows(int M[N][N], int a, int b) {
    return M[a][b];
}


int findCelebrity(int M[N][N], int n) {
    int stack[n];
    int top = -1;

    
    for(int i = 0; i < n; i++)
        stack[++top] = i;

   
    while(top > 0) {
        int a = stack[top--]; 
        int b = stack[top--]; 

        if(knows(M, a, b))
            stack[++top] = b;
        else
            stack[++top] = a; 
    }

   
    int cand = stack[top]; 
    for(int i = 0; i < n; i++) {
        if(i != cand && (knows(M, cand, i) || !knows(M, i, cand)))
            return -1; 
    }

    return cand; 
}

int main() {
   
    int M[N][N] = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int celeb = findCelebrity(M, N);

    if(celeb == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", celeb);

    return 0;
}
