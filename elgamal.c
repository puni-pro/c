#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define size 100

int gcd(int x, int y)//最大公約数
 {
     int t;
 
     while (y != 0) {
         t = x % y;  x = y;  y = t;
     }
     return x;
     
 }
 
int gen_key(int q){
    int key = rand() % 2000 + 2000;
    while(gcd(q,key) != 1){
        key = rand() % 2000 + 2000;
    }
    return key;
}

int power(int a,int b,int c){
    int x = 1;
    int y = a;
    
    while(b > 0){
        if(b%2 != 0){
            x = (x * y) % c;
        }
        y = (y*y) % c;
        b = (int) b /2;
    }
    return x % c;
}



int encrypt(int msg[size], int k,int q,int h,int g, int en_msg[size]){
    
    int s = power( h, k, q);
    
    for(int i = 0;i<size;i++){
        en_msg[i] = msg[i];
    }
    
    printf("g^k used  : %d\n" ,q);
    printf("g^ak used : %d\n" ,s);
    
    for(int i = 0 ;i < size; i++){
        en_msg[i] = s * en_msg[i];
    }
}


int decrypt(int en_msg[size], int p, int key, int q, int dr_msg[size]){

    int h = power(p , key , q);
    for(int i = 0; i < size ; i++){
        dr_msg[i] = en_msg[i] / h;
    }
    
}



int text_print(int text[size]){
    for(int i = 0; i < size;i++){
        if(text[i] == 0){
            break;
        }
        printf("%c  ",text[i]);
    }
    printf("\n");
}


int main(void){
    srand((unsigned int)time(NULL));

    char text[size];
    int msg[size],en_msg[size],dr_msg[size];
    
    printf("text input:");
    scanf("%s",text);
    
    
    for(int i = 0;i<size;i++){
        msg[i] = text[i];
    }


    printf("Original Message :");
    text_print( msg);
    
    int q = rand()%8000 + 2000;
    int g = rand()% (q-2) + 2;
    
    int key = gen_key( q);
    int h = power( g, key, q);
    printf("g used : %d\n", g);
    printf("g^a used: %d\n", h);

    int k = gen_key( q);
    int p = power( g, k, q); 


    encrypt( msg, k, q, h, g, en_msg);
    
    printf("encrypted Message :");
    text_print(en_msg);
    
    decrypt( en_msg, p, key,q, dr_msg);

    printf("Decrypted Message :");
    text_print(dr_msg);
}

