// Punjapong Poobanchuen 67070503423
// Sorawit Chaithong 67070503442
// Kittiphat Noikate 67070503459
#include <stdio.h>

void two_com(int bit, long long int binary){
    int arr[bit];
    for(int i=bit-1; i>=0; i--){
        arr[i] = binary % 10;
        binary /= 10;
    }

    //test print
    for(int i=0; i<bit; i++){
        printf("%d", arr[i]);
    }
}

void input(){
    int bit;
    long long int decimal;
    printf("Please enter the number of bits between 1 and 32 inclusive: ");
    scanf("%d", &bit);
    printf("Please enter a number between -4 and 3 inclusive: ");
    scanf("%lld", &decimal);
    two_com(bit, decimal);
}

int main() {
    input();
  return 0;
}