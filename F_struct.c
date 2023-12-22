// Program to storet the record till user desires and displaying the data from file
#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct info
{
    char name[20];
    char adrs[20];
    int age;
};
int main()
{
    struct info A;
    int a;
    FILE *fpt;
    fpt = fopen("f_struct.txt", "w");
    char ch = 'Y';
    while (ch == 'Y')
    {
        printf("Enter name, adress and age:   \n");
        scanf("%s%s%d", &A.name, &A.adrs, &A.age);
        fprintf(fpt, "\n%s\n%s\n%d\n", A.name, A.adrs, A.age);
        getchar();
        printf("\nDo you want to continue (Y/N):  ");
        ch = toupper(getchar());
    }
    fclose(fpt);
    fpt = fopen("f_struct.txt", "r");
    while (fscanf(fpt, "%s%s%d", &A.name, &A.adrs, &A.age) != EOF)
    {
        printf("%s\t%s\t%d\n", A.name, A.adrs, A.age);
    }
    fclose(fpt);
    printf("\nThe file has ended!!...");
    return 0;
}