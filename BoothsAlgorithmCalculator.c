#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int a, int b)
{
    int c; 
    printf("Enter an integer:\n"); 
    scanf("%d", &a); 
    printf("Enter an integer:\n");
    scanf("%d", &b); 
    int arr[33];
    int arrA[33];
    int arrB[33];
    int arrA2[33];
    int carry;
    //Fill everything with 0s
    for(int i = 0; i < 33;i++){
        arr[i] = 0;
        arrB[i] = 0;
        arrA[i] = 0;
        arrA2[i] = 0;
    }
    //Add b to array
    int count = 31;
    int n = abs(b);
    while(n){
        arrB[count] = n % 2;
        //arr[count] = n % 2;
        n /= 2;
        count--;
    }
    //If B is NEGATIVE***
    if(b < 0){
        for(int i = 0;i < 33;i++){
        arrB[i] = arrB[i] + 1;
        if(arrB[i] == 2){
            arrB[i] = 0;
        }
    }
    //If B is NEGATIVE PART 2***
    arrB[32] = arrB[32] + 1;
    if(arrB[32] == 2){
        carry = 1;
        arrB[32] = 0;
        int count = 31;
        while(carry == 1){
            if(arrB[count] = arrB[count] + carry > 1){
                arrB[count] = 0;
                carry = 1;
            }
            else{
                arrB[count] = arrB[count] + carry;
                carry = 0;
            }
            count--;
        }
    }
    }
    //Artificial Zeroes
    for(int i = 0; i < 16;i++){
        arrB[i] = 0;
    }
    count = 31;
    while(count > 15){
        arr[count] = arrB[count];
        count--;
    }
    //Add a to array and get a in binary
    n = a;
    count = 15;
    while(n){
        arr[count] = 0;
        arrA[count] = n % 2;
        n /= 2;
        count--;
    } 
    //***If A is NEGATIVE***
    if(a < 0){
        for(int i = 0;i < 33;i++){
        arrA[i] = arrA[i] + 1;
        if(arrA[i] == 2){
            arrA[i] = 0;
        }
    }
    //***IF A is NEGATIVE PART 2***
    arrA[32] = arrA[32] + 1;
    if(arrA[32] == 2){
        carry = 1;
        arrA[32] = 0;
        int count = 31;
        while(carry == 1){
            if(arrA[count] = arrA[count] + carry > 1){
                arrA[count] = 0;
                carry = 1;
            }
            else{
                arrA[count] = arrA[count] + carry;
                carry = 0;
            }
            count--;
        }
    }
    }
    //Two's complement 1s to 0s
    for(int i = 0;i < 33;i++){
        arrA2[i] = arrA[i] + 1;
        if(arrA2[i] == 2){
            arrA2[i] = 0;
        }
    }
    //Two's complement add 1
    arrA2[32] = arrA2[32] + 1;
    if(arrA2[32] == 2){
        carry = 1;
        arrA2[32] = 0;
        int count = 31;
        while(carry == 1){
            if(arrA2[count] = arrA2[count] + carry > 1){
                arrA2[count] = 0;
                carry = 1;
            }
            else{
                arrA2[count] = arrA2[count] + carry;
                carry = 0;
            }
            count--;
        }
    }
    //Convert to Two's Complement if negative
    /*if(a < 0){
        for(int i = 0; i < 33;i++){
            
        }
    }*/
    
    
    printf("Array's Initial State:\n");
    //print array's initial state
    for(int i = 0; i < 33;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    
    printf("B:\n");
    //print the 16 bit value of a with 16 0s
    for(int i = 0; i < 33;i++){
        printf("%d",arrB[i]);
    }
    printf("\n");
    
    printf("A:\n");
    //print the 16 bit value of a with 16 0s
    for(int i = 0; i < 33;i++){
        printf("%d",arrA[i]);
    }
    printf("\n");
    
    
    printf("A in Two's Complement:\n");
    //print Two's Complement of a
    for(int i = 0; i < 33;i++){
        printf("%d",arrA2[i]);
    }
    printf("\n");
    printf("\n\n\n\n\n");
    //*****MAIN LOOP AFTER SETUP*****
    for(int i = 0;i < 16;i++){
        carry = 0;
        if(arr[32] == arr[31]){
            for(int i = 32; i > 1;i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = arr[1];
        }
        else{
            if(arr[32] == 0){
                //two's complement addition
                for(int i = 0; i < 33;i++){
                    printf("%d",arrA2[i]);
                }
                printf("-");
                printf("\n");
                carry = 0;
                for(int i = 32;i >= 0;i--){
                    if(arr[i] + arrA2[i] + carry > 2){
                        arr[i] = 1;
                        carry = 1;
                    }
                    else if(arr[i] + arrA2[i] + carry > 1){
                        arr[i] = 0;
                        carry = 1;
                    }
                    else{
                        arr[i] = arr[i] + arrA2[i] + carry;
                        carry = 0;
                    }
                }
                for(int i = 0; i < 33;i++){
                    printf("%d",arr[i]);
                }
                printf("\n");
            }
            else if(arr[32] == 1){
                //addition
                for(int i = 0; i < 33;i++){
                    printf("%d",arrA[i]);
                }
                printf("+");
                printf("\n");
                carry = 0;
                for(int i = 32;i >= 0;i--){
                    if(arr[i] + arrA[i] + carry > 2){
                        arr[i] = 1;
                        carry = 1;
                    }
                    else if(arr[i] + arrA[i] + carry > 1){
                        arr[i] = 0;
                        carry = 1;
                    }
                    else{
                        arr[i] = arr[i] + arrA[i] + carry;
                        carry = 0;
                    }
                }
                for(int i = 0; i < 33;i++){
                    printf("%d",arr[i]);
                }
                printf("\n");
            }
            for(int i = 32; i > 1;i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = arr[1];
        }
        for(int i = 0; i < 33;i++){
            printf("%d",arr[i]);
        }
        //printf("Shift");
        printf("\n");
    }
    for(int i = 32; i > 1;i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = arr[1];
            for(int i = 0; i < 33;i++){
            printf("%d",arr[i]);
        }
        printf(" : End");
        printf("\n");
        
    //convert back to decimal
    int decimal = 0;
    int go = 0;
    for(int h = 0;h<=32;h++){
        //convert back if negative
        if((a<0&b>0)|(b<0&a>0)){
            if(arr[h]+1==2){
                arr[h] = 0;
            }else{
                arr[h] = 1;
            }
        }
        if(arr[h]==1){
            decimal = decimal + pow(2,abs(h-32));
        }
    }
    if((a<0&b>0)|(b<0&a>0)){
        int temp = 0;
        decimal = decimal + 1;
        temp = decimal;
        decimal = decimal - temp - temp;
    }
    //printf("%i",decimal);
    return decimal;
}
