#include <stdio.h>
#include <stdlib.h>

//Prototyping all functions
int counter(char a[]);
int checkLength(char a[]);
int checkAlphanumeric(char a[]);
int checkNumber(char a[]);
int checkSpace(char a[]);
int checkUpper (char a[]);


int main(int argc, char *argv[]){


    if (argc == 2 && checkLength(argv[1]) == 1 && checkAlphanumeric(argv[1]) == 1 && checkNumber(argv[1]) == 1 && checkSpace(argv[1]) == 1 && checkUpper(argv[1]) == 1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}

int counter(char a[]){
    int i;
    for (i=0; a[i] != '\0'; i++);
    return i;
}

int checkLength(char a[]){
    if (counter(a)>= 5 && counter(a) <= 15) {
        return 1;
    }

    return 0;

}

int checkAlphanumeric(char a[]){
    if ( (a[0] >= 48 && a[0] <=57) || (a[0] >= 65 && a[0] <=90) || (a[0] >= 97 && a[0] <=122) ){
        return 1;
    }

    return 0;
}

int checkNumber(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if (a[i] >= 48 && a[i] <=57){
            return 1;
            }
    }
    return 0;
}

int checkSpace(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if (a[i]==' '){
            return 0;
            }
    }
    return 1;
}

int checkUpper (char a[]){
    int i;
    for(i=0;a[i]!='\0';i++){
        if (a[i]>=65 && a[i]<=90){
            return 1;
        }
    }
    return 0;
}

