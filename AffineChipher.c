#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fileObject;
    char charecter;
    int a, b;
    unsigned int counter = 0;

    fileObject = fopen("./textfile.txt", "r+");
    
    if(fileObject == NULL){
        printf("File isn't exist!");
        exit(1);
    }


    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    charecter = fgetc(fileObject);
    fseek(fileObject, 0, SEEK_END);

    char chipherText[ftell(fileObject) + 1];
    fseek(fileObject, 1, SEEK_SET);

    while(charecter != EOF){
        charecter = charecter - 'A';
        charecter = (((a * charecter) + b) % 26) + 'A';
        chipherText[counter++] = charecter;
        charecter = fgetc(fileObject);
    }

    chipherText[counter++] = '\0';
    fseek(fileObject, 0, SEEK_SET);
    fputs(chipherText, fileObject);
    fclose(fileObject);
    return 0;
}