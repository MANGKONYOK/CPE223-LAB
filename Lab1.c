// Panjapong Poobancheun 67070503423
// Sorawit Chaithong 67070503442
// Kittiphat Noikate 67070503459

#include <stdio.h>

int abs(int value){

  if(value < 0){

    return -value;

  }

  return value;

}

int power_2(int n){

  return 1 << n;

}

void binary(int val, int n){

  int bit;

  for(bit = n - 1; bit >= 0; bit--){

    int bit_val = power_2(bit);

    if(val >= bit_val) {

      printf("1");
      val = val - bit_val;

    }else{

      printf("0");

    }

  }

  printf(".");

}

void sign_and_magnitude(int n, int val){

  int MSB = power_2(n - 1) - 1;
  int abs_val = abs(val);

  if(abs_val <= MSB){

    printf("The sign-magnitude representation of %d is ", val);

    if(val < 0){

      printf("1");
    }else{

      printf("0");

    }

    binary(abs_val, n - 1);
    printf("\n");

  }else{

    printf("The sign-magnitude doesn't represent %d.\n", val);

  }

}

int main(){

  sign_and_magnitude(3, -4);
  sign_and_magnitude(4, -7);
  sign_and_magnitude(3, 2);
  sign_and_magnitude(4, 0);
  sign_and_magnitude(4, -0);
  sign_and_magnitude(8, 64);
  sign_and_magnitude(3, 3);

  return 0;

}

// void two_com(int bit, long long int decimal){
//     int arr[bit] = {0};
//     int dec;

//     if (decimal < 0){
//         dec = abs(decimal);
//     }else{
//         dec = decimal;
//     }

//     for (int i = bit-1; i>=0; i--){
//         arr[i] = dec%2;
//         dec /= 2;
//     }
// }

// void input(){
//     int bit;
//     long long int decimal;
//     printf("Please enter the number of bits between 1 and 32 inclusive: ");
//     scanf("%d", &bit);
//     printf("Please enter a number between -4 and 3 inclusive: ");
//     scanf("%lld", &decimal);
//     binary(decimal, bit);
//     two_com()
// }

// int main() {
//     input();
//   return 0;
// }