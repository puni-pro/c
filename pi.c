#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int Circumcision(int max){
    double a = 1;
    double n = 6;
    
    for(int i = 0; i < max ; i++){
        n = n*2;
        a = sqrt(2 - 2 *   sqrt(1 - (a/2) * (a/2))   );
        
        
        printf("%f",a);
        printf(":%20.12f\n",n*a/2);
    }
}


int monte_carlo(int max){
    int i,count;
    double x,y,z,pi;
    
    count = 0;
    
    srand(time(NULL));
    
    for(i = 0 ; i < max; i ++){
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x * x + y * y;
        if (z < 1)
        count ++ ;
        
    }
    
    pi = (double)count / max * 4;
    printf("%f\n",pi);
    
}


int main(void){
    

    
    Circumcision(13);
    
    
}
