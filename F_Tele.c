// Program to store data provided ...
#include <stdio.h>
#include <ctype.h>
#include <string.h>
struct data
{
    char fname[20];
    char lname[20];
    char adr[25];
    char tel[10];
} T;
void main()
{
    char c = 'Y';
    FILE *ptr;
    ptr = fopen("F_Tele.txt", "w");
    while (c == 'Y')
    {
        printf("Enter first name: ");
        scanf("%s", &T.fname);
        printf("Enter last name: ");
        scanf("%s", &T.lname);
        printf("Enter adress: ");
        scanf("%s", &T.adr);
        printf("Enter telephone nnumber: ");
        scanf("%s", &T.tel);
        fwrite(&T, sizeof(T), 1, ptr);
        getchar();
        printf("Do you want to continue(Y/N): ");
        c = toupper(getchar());
    }
    fclose(ptr);
    printf("\n  The records have been succesfully been stored !!!\n");
}