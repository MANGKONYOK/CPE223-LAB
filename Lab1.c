// Panjapong Poobanchuen 67070503423
// Sorawit Chaithong 67070503442
// Kittiphat Noikate 67070503459

#include <stdio.h>

int power_2(int n){ 

  return 1 << n; 

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

  printf(".");
}

int is_negative_str(char *str){ 

  return str[0] == '-'; 

}

int str_to_int(char *str){

  int result = 0;
  int i = 0;

  if(str[0] == '-'){
    i = 1;
  }

  while(str[i] != '\0'){
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return result;
}

void sign_and_magnitude(int n, char *val){

  int is_neg = is_negative_str(val);
  int num = str_to_int(val);
  int max_mag = power_2(n - 1) - 1;

  if(num <= max_mag){

    if(is_neg){
      printf("The sign-magnitude representation of -%d is ", num);
      printf("1");
    }else{
      printf("The sign-magnitude representation of %d is ", num);
      printf("0");
    }

    binary(num, n - 1);
    printf("\n");

  }else{

    if(is_neg){
      printf("The sign-magnitude doesn't represent -%d.\n", num);
    }else{
      printf("The sign-magnitude doesn't represent %d.\n", num);
    }
  }
}

void one_com(int bit, char *decimal){

  int arr[32] = {0};
  int is_neg = is_negative_str(decimal);
  int dec = str_to_int(decimal);
  int max_mag = power_2(bit - 1) - 1;
  int i;

  if(dec > max_mag){

    if(is_neg){
      printf("The 1's complement doesn't represent -%d.\n", dec);
    }else{
      printf("The 1's complement doesn't represent %d.\n", dec);
    }
    return;
  }

  for(i = bit - 1; i >= 0; i--){
    arr[i] = dec % 2;
    dec = dec / 2;
  }

  if(is_neg){
    for(i = 0; i < bit; i++){
      arr[i] = (arr[i] == 0) ? 1 : 0;
    }
  }

  if(is_neg){
    printf("The 1's complement representation of -%d is ", str_to_int(decimal));
  } else {
    printf("The 1's complement representation of %d is ", str_to_int(decimal));
  }

  for(i = 0; i < bit; i++){
    printf("%d", arr[i]);
  }

  printf(".\n");
}

void two_com(int bit, char *decimal){

  int arr[32] = {0};
  int is_neg = is_negative_str(decimal);
  int dec = str_to_int(decimal);
  int max_pos = power_2(bit - 1) - 1;
  int max_neg = power_2(bit - 1);
  int i;
  int in_range;

  if(is_neg){
    in_range = (dec <= max_neg);
  }else{
    in_range = (dec <= max_pos);
  }

  if(is_neg && dec == 0){
    printf("The 2's complement doesn't represent -0.\n");
    return;
  }

  if(!in_range){

    if(is_neg){
      printf("The 2's complement doesn't represent -%d.\n", dec);
    }else{
      printf("The 2's complement doesn't represent %d.\n", dec);
    }

    return;
  }

  for(i = bit - 1; i >= 0; i--){
    arr[i] = dec % 2;
    dec = dec / 2;
  }

  if(is_neg){

    for(i = 0; i < bit; i++){
      if(arr[i] == 0){
        arr[i] = 1;
      }else{
        arr[i] = 0;
      }
    }

    for(i = bit - 1; i >= 0; i--){

      if(arr[i] == 0){
        arr[i] = 1;
        break;
      }else{
        arr[i] = 0;
      }
    }
  }

  if(is_neg){
    printf("The 2's complement representation of -%d is ", str_to_int(decimal));
  }else{
    printf("The 2's complement representation of %d is ", str_to_int(decimal));
  }

  for(i = 0; i < bit; i++){
    printf("%d", arr[i]);
  }

  printf(".\n");
}

int main(){

  int bit;
  char decimal[32];

  printf("Please enter the number of bits between 1 and 32 inclusive: ");
  scanf("%d", &bit);
  printf("Please enter a number between %d and %d inclusive: ", -(power_2(bit - 1)), power_2(bit - 1) - 1);
  scanf("%s", decimal);

  sign_and_magnitude(bit, decimal); // test sign & magnitude
  one_com(bit, decimal);            // test one complement
  two_com(bit, decimal);            // test two complement

  return 0;
  
}