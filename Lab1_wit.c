// Punjapong Poobanchuen 67070503423
// Sorawit Chaithong 67070503442
// Kittiphat Noikate 67070503459
#include <stdio.h>


int abs(int value){

  if (value < 0) {
    return -value;
  }
  return value;

}

void two_com(int bit, long long int decimal){
    int arr[bit] = {0};
    int dec;

    if (decimal < 0){
        dec = abs(decimal);
    }else{
        dec = decimal;
    }

    for (int i = bit-1; i>=0; i--){
        arr[i] = dec%2;
        dec /= 2;
    }
}

void input(){
    int bit;
    long long int decimal;
    printf("Please enter the number of bits between 1 and 32 inclusive: ");
    scanf("%d", &bit);
    printf("Please enter a number between -4 and 3 inclusive: ");
    scanf("%lld", &decimal);
    binary(decimal, bit);
    two_com()
}

int main() {
    input();
  return 0;
}