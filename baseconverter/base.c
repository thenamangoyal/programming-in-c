#include <stdio.h>
#include <stdlib.h>

//Prototyping all functions
//Functions to check if number is valid in given base
int isHex (char a[]);
int isOct (char a[]);
int isBin (char a[]);
int isDec (char a[]);

//Counter function
int counter (char a[]);

//Converts number to decimal form from given base
long long int convertFromOct (char a[]);
long long int convertFromHex (char a[]);
long long int convertFromBin (char a[]);
long long int convertFromDec (char a[]);

//Power function
long long int power(long long int a,long long int b);

//Converts number from decimal form to given base
char *convertToOct(long long int dec);
char *convertToHex(long long int dec);
char *convertToBin(long long int dec);
char *convertToDec(long long int dec);

int main(){
    int i,b1,b2;
    long long int dec;
    char num[100];
    //Taking input
    printf("b1 is: ");
    scanf("%d",&b1);
    printf("b2 is: ");
    scanf("%d",&b2);
    printf("num is: ");
    scanf("%s",num);

    //Printing output
    printf("Output: ");

    if (b1 == 2 && isBin(num) == 1){
        dec = convertFromBin(num);
        if (b2 == 2){
            printf("%s\n",convertToBin(dec));
        }
        else if (b2 == 8){
            printf("%s\n",convertToOct(dec));
        }
        else if (b2 == 10){
            printf("%s\n",convertToDec(dec));
        }
        else if (b2 == 16){
            printf("%s\n",convertToHex(dec));
        }
        else {
            printf("0\n");
        }

    }
    else if (b1 == 8 && isOct(num) == 1){
        dec = convertFromOct(num);
        if (b2 == 2){
            printf("%s\n",convertToBin(dec));
        }
        else if (b2 == 8){
            printf("%s\n",convertToOct(dec));
        }
        else if (b2 == 10){
            printf("%s\n",convertToDec(dec));
        }
        else if (b2 == 16){
            printf("%s\n",convertToHex(dec));
        }
        else {
            printf("0\n");
        }
    }
    else if (b1 == 10 && isDec(num) == 1){
        dec = convertFromDec(num);
        if (b2 == 2){
            printf("%s\n",convertToBin(dec));
        }
        else if (b2 == 8){
            printf("%s\n",convertToOct(dec));
        }
        else if (b2 == 10){
            printf("%s\n",convertToDec(dec));
        }
        else if (b2 == 16){
            printf("%s\n",convertToHex(dec));
        }
        else {
            printf("0\n");
        }
    }
    else if (b1 == 16 && isHex(num) == 1){
        dec = convertFromHex(num);
        if (b2 == 2){
            printf("%s\n",convertToBin(dec));
        }
        else if (b2 == 8){
            printf("%s\n",convertToOct(dec));
        }
        else if (b2 == 10){
            printf("%s\n",convertToDec(dec));
        }
        else if (b2 == 16){
            printf("%s\n",convertToHex(dec));
        }
        else {
            printf("0\n");
        }
    }
    else{
        printf ("0\n");
    }
    return 0;
}

int isHex (char a[]){
    int i;
    for (i=0;a[i] != '\0';i++){
        if (a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9' && a[i] != 'a' && a[i] != 'b' && a[i] != 'c' && a[i] != 'd' && a[i] != 'e' && a[i] != 'f' && a[i] != 'A' && a[i] != 'B' && a[i] != 'C' && a[i] != 'D' && a[i] != 'E' && a[i] != 'F'){
            return 0;
        }
    }
    return 1;
}

int isOct (char a[]){
    int i;
    for (i=0;a[i] != '\0';i++){
        if (a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] !='7'){
            return 0;
        }
    }
    return 1;
}

int isBin (char a[]){
    int i;
    for (i=0;a[i] != '\0';i++){
        if (a[i] != '0' && a[i] != '1'){
            return 0;
        }
    }
    return 1;
}

int isDec (char a[]){
    int i;
    for (i=0;a[i] != '\0';i++){
        if (a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] !='7' && a[i] != '8' && a[i] !='9'){
            return 0;
        }
    }
    return 1;
}

int counter (char a[]){
    int i;
    for (i=0;a[i] !='\0';i++);
    return i;
}

long long int power(long long int a,long long int b){
    long long int i,ans=1;
    for (i=0;i<b;i++) {
            ans = ans*a;

    }
    return ans;
}

long long int convertFromHex(char a[]){

    long long int i,v,dec,length;
    dec = 0;
    length = counter(a);
    for(i =0;a[i]!='\0';i++){
      
            if (a[i]>= 48 && a[i] <=57){
	      // Converting from corresponding ASCII value
                v = a[i] -48;
            }
            else if (a[i]>=65 && a[i] <=70){
	      // Converting from corresponding ASCII value
                v = a[i] -65+ 10;
            }
            else if (a[i] >= 97 && a[i] <= 102){
	      // Converting from corresponding ASCII value
                v = a[i] -97 + 10;
            }
	    //Since we are converting from left to right
            dec = dec + v*power(16,length - i -1);
    }
    return dec;
}

long long int convertFromOct(char a[]){

    long long int i,v,dec,length;
    dec = 0;
    length = counter(a);
    for(i =0;a[i]!='\0';i++){

            if (a[i]>= 48 && a[i] <=55){
	      // Converting from corresponding ASCII value
                v = a[i] -48;
            }
	    //Since we are converting from left to right
            dec = dec + v*power(8,length - i -1);
    }
    return dec;
}

long long int convertFromDec(char a[]){

    long long int i,v,dec,length;
    dec = 0;
    length = counter(a);
    for(i =0;a[i]!='\0';i++){

            if (a[i]>= 48 && a[i] <=57){
	      // Converting from corresponding ASCII value
                v = a[i] -48;
            }
	    //Since we are converting from left to right
            dec = dec + v*power(10,length - i -1);
    }
    return dec;
}

long long int convertFromBin(char a[]){

    long long int i,v,dec,length;
    dec = 0;
    length = counter(a);
    for(i =0;a[i]!='\0';i++){
      
            if (a[i]>= 48 && a[i] <=49){
	      // Converting from corresponding ASCII value
                v = a[i] -48;
            }
	    //Since we are converting from left to right
            dec = dec + v*power(2,length - i -1);
    }
    return dec;
}

char *convertToHex(long long int dec){
    long long int i,j,r,q;
    static char ihex[100];
    static char hex[100];
    ihex[0] ='0';
    hex[0] ='0';
    ihex[1] ='\0';
    hex[1] ='\0';
    q= dec;
    // Using division process for conversion
    for (i=0;q>0;i++){
        r = q % 16;
        if (r >=0 && r<= 9){
            ihex[i] = r + 48;
        }
        else if (r >=10 && r<=15){
            ihex[i] = r + 55;
        }
        q = q/16;
        ihex[i+1] ='\0';
    }
    //Reversing the converted number
    for (j=0;j<i;j++){
        hex[j] = ihex[i-j-1];
        hex[j+1] = '\0';
    }

    return hex;
}

char *convertToOct(long long int dec){
    long long int i,j,r,q;
    static char ioct[100];
    static char oct[100];
    ioct[0] ='0';
    oct[0] ='0';
    ioct[1] ='\0';
    oct[1] ='\0';
    q= dec;
    // Using division process for conversion
    for (i=0;q>0;i++){
        r = q % 8;
        if (r >=0 && r<= 7){
            ioct[i] = r + 48;
        }
        q = q/8;
        ioct[i+1] ='\0';
    }
    //Reversing the converted number
    for (j=0;j<i;j++){
        oct[j] = ioct[i-j-1];
        oct[j+1] = '\0';
    }

    return oct;
}
char *convertToBin(long long int dec){
    long long int i,j,r,q;
    static char ibin[100];
    static char bin[100];
    ibin[0] ='0';
    bin[0] ='0';
    ibin[1] ='\0';
    bin[1] ='\0';
    q= dec;
    // Using division process for conversion
    for (i=0;q>0;i++){
        r = q % 2;
        if (r >=0 && r<= 1){
            ibin[i] = r + 48;
        }
        q = q/2;
        ibin[i+1] ='\0';
    }
    //Reversing the converted number
    for (j=0;j<i;j++){
        bin[j] = ibin[i-j-1];
        bin[j+1] = '\0';
    }

    return bin;
}
char *convertToDec(long long int dec){
    long long int i,j,r,q;
    static char ideci[100];
    static char deci[100];
    ideci[0] ='0';
    deci[0] ='0';
    ideci[1] ='\0';
    deci[1] ='\0';
    q= dec;
    // Using division process for conversion
    for (i=0;q>0;i++){
        r = q % 10;
        if (r >=0 && r<= 9){
            ideci[i] = r + 48;
        }
        q = q/10;
        ideci[i+1] ='\0';
    }
    //Reversing the converted number
    for (j=0;j<i;j++){
        deci[j] = ideci[i-j-1];
        deci[j+1] = '\0';
    }

    return deci;
}
