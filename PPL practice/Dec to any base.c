
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//program to convert any decimal to various types and vice versa

void dectobin(int dec){ //convert decimal to binary
    int bin[32];

    int i = 0;
    while (dec!= 0) {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
    int j;
    for (j = i - 1; j >= 0; j--)
        printf("%d",bin[j]);
}

int bintodec(int bin){  //convert binary to decimal
    int dec=0,rem =0,i=0;
    while(bin!=0){
    rem = bin%10;
    bin = bin/10;
    dec += rem*pow(2,i);
    i++;
    }
    return dec;
}

void dectooct(int dec) //convert decimal to octal
{
    int oct[32];

    int i = 0;
    while (dec!= 0) {

        oct[i] = dec % 8;
        dec = dec / 8;
        i++;
    }
     int j=0;
    for (j = i - 1; j >= 0; j--)
        printf("%d", oct[j]);
}

int octtodec(int oct){ //convert octal to decimal
    int dec=0,rem =0,i=0;
    while(oct!=0){
    rem = oct%10;
    oct = oct/10;
    dec += rem*pow(8,i);
    i++;
    }
    return dec;
}

void dectohex(int dec){ //convert decimal to hexadecimal
    int hex[32],rem;
    int i = 0;
    while (dec!= 0) {
        rem = dec%16;
        if(rem>9){
            rem = rem-10+65;
            hex[i]=rem;
        }else{
         hex[i] = dec % 16;
        }
        dec = dec / 16;
        i++;
    }
     int j=0;
    for (j = i - 1; j >= 0; j--){
        if(hex[j]>=65){
            printf("%c",hex[j]);
        }else{
            printf("%d", hex[j]);
        }
    }       
}

int hextodec(char strhex[]){ //convert hexadecimal to decimal
    
    int dec=0,rem =0,i,len,j=0;
    for(len=0;strhex[len]!='\0';len++);    

    for(i=len-1;i>=0;i--){
        if(strhex[i]>=65){
            rem = strhex[i]-65+10;
            dec += rem*pow(16,j);
        }else{
            rem = strhex[i]-48;
            dec += rem*pow(16,j);
        }
        j++;
    }
    return dec;
}

int main() {
        
    int dec,bin,oct,n=0;
    char hex[100];
    printf("Menu: ");
    printf("\n1. decimal to binary");
    printf("\n2. binary to decimal");
    printf("\n3. decimal to octal");
    printf("\n4. octal to decimal");
    printf("\n5. decimal to Hexadecimal");
        printf("\n6. hexadecimal to decimal");
    printf("\n7. Exit!");
    while(n!=7){
    printf("\n\nEnter your choice: ");
    scanf("%d", &n);
    switch(n){
        case 1: printf("Enter a decimal number: ");
    scanf("%d",&dec);
    dectobin(dec);
    break;
         case 2:  printf("Enter a binary: ");
    scanf("%d",&bin);
    printf("%d",bintodec(bin));
    break;
     case 3: printf("Enter a Decimal number: ");
    scanf("%d",&dec);
    dectooct(dec);
    break;
    case 4: printf("Enter an Octal number: ");
    scanf("%d",&oct);
    printf("%d",octtodec(oct));
    break;
    case 5: printf("Enter a Decimal number: ");
    scanf("%d",&dec);
    dectohex(dec);
    break;
    case 6: printf("Enter a Hexadecimal number: ");
    scanf("%s",hex);
    printf("%d",hextodec(hex));
    break;
    case 7: return(0);
    break;
    default:
        printf("Invalid choice!");
        break;
    }
    }
    
        return 0;
}

