#include <stdio.h>
#include <math.h>

int gcd(int x, int y)//最大公約数
 {
     int t;
 
     while (y != 0) {
         t = x % y;  x = y;  y = t;
     }
     return x;
 }


int main()
{
    int p,q,n;
    int P[8] = {1,2,3,4,0,1,2,3};
    int Q[8];
    int A[8];
    
    int k1,k2;
    
    p = 23;
    q = 11;
    
    n = p*q;//15
    int s = (p-1)*(q-1);//8
    for(int counter = 10;;counter++){
        if(gcd(s,counter) == 1){
            k1 = counter;
            break;
        }
    }
    for(int counter = 10 ;; counter++){
        if((k1 * counter)%s == 1){
            k2 = counter;
            break;
        }
    }
    
    printf("k1 = %d\n",k1);
    
    printf("k2 = %d\n",k2);
    
    int N;
    
    for(int x = 0;x<8;x++){


    
        N = (int) pow(P[x], k1);
        printf("%d ",N);
        printf(" ");
        Q[x] = (int) pow(P[x], k1) % n ;
    }
    
    printf("\n" );
    
    for(int x = 0;x<8;x++){
            
        N = (int) pow(Q[x], k2);
        printf("%d ",N);
        A[x] = (int) pow(Q[x], k2) % n;
    }
    
    printf("\n" );

    printf("P =");
    for(int i = 0;i<8 ; i++){
        printf("%d ",P[i]);

    }
    
    printf("\n" );
    printf("Q =");
    for(int i = 0;i<8 ; i++){
        printf("%d ",Q[i]);

    }
    
    printf("\n" );
    
    printf("A =");
    for(int i = 0;i<8 ; i++){
        printf("%d ",A[i]);

    }

    return 0;
}