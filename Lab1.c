// Panjapong Poobancheun 67070503423
// Sorawit Chaithong 67070503442
// Kittiphat Noikate 67070503459

#include <stdio.h>

// =====================================================
// SHARED UTILITY FUNCTIONS (for all representations)
// =====================================================

int power_2(int n){

  int result = 1;
  int i;

  for (i = 0; i < n; i++){
    result = result * 2;
  }

  return result;

}

int abs(int value){

  if (value < 0) {
    return -value;
  }
  return value;

}

void binary(int val, int n){

  int bit;
  for(bit = n - 1; bit >= 0; bit--){

    int bit_val = power_2(bit);
    if(val >= bit_val){

      printf("1");
      val = val - bit_val;

    }else{

      printf("0");

    }
  }
}

// =====================================================
// SIGN-MAGNITUDE REPRESENTATION
// =====================================================
// Range: -(2^(n-1) - 1) to +(2^(n-1) - 1)
// Note: Has two representations for zero (+0 and -0)

void sign_and_magnitude(int n, int val){

  int MSB = power_2(n - 1) - 1;
  int abs_val = abs(val);

  if(abs_val <= MSB){

    printf("The sign-magnitude does represent %d.\n", val);

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