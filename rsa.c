
#include<stdio.h>

#define size 1000

int pow_mod(int x,int k,int n){//xをk乗しnで割った余りを返す
    int result = 1;
    while (k > 0) {
       if ((k & 1) == 1) result = (result * x) % n; 
       k >>= 1;
       x = (x * x) % n;
    }

    return result;
}

int gcd(int x, int y)//最大公約数
 {
     int t;
 
     while (y != 0) {
         t = x % y;  x = y;  y = t;
     }
     return x;
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

int rsa_enc_dec( int text[size], int n, int key, int result_text[size]){//暗号化　複合化
    for(int i = 0; i < size; i++){
        result_text[i] = pow_mod(text[i],key,n);
    }
}


int main(void){

    char text_plain[size];
    int text[size];
    printf("plain text:");
    scanf("%s", text_plain);
    for(int counter = 0; counter < size ; counter++){
        text[counter] = text_plain[counter];
    }


    int enc_text[size],dec_text[size];

    int prime_p = 89,prime_q = 43;
    int n = prime_p*prime_q;
    int s = (prime_p - 1)*(prime_q -1);
    int public_key,secret_key;

    for(int counter = 2;;counter++){
        if(gcd(s,counter) == 1 && counter > 1000){
            public_key = counter;
            break;
        }
    }

    for(int counter = 2 ;; counter++){
        if((public_key * counter)%s == 1 && public_key != counter){
            secret_key = counter;
            break;
        }
    }

    printf("public key = %d, secret key = %d\n",public_key,secret_key);

    text_print(text);
    rsa_enc_dec(text,n,public_key,enc_text);//暗号化
    text_print(enc_text);
    rsa_enc_dec(enc_text,n,secret_key,dec_text);//複合化
    text_print(dec_text);
   

    return 0;
}

