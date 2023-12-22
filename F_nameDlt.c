// bro codes practice...
#include <stdio.h>
#include <ctype.h>
#include <string.h>
struct data
{
    char fnam[10], lnam[10], adr[20], tel[10];
    float sal;
} E;
int main()
{
    char ch, s[10];
    int n = 0, i = 0;
    FILE *p;
    printf("Doyou want to enter datas (Y/N): ");
    scanf("%c", &ch);
    p = fopen("F_nameDlt.txt", "a+");
    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter first name of employe: ");
        scanf("%s", &E.fnam);
        printf("Enter last name of %s: ", E.fnam);
        scanf("%s", &E.lnam);
        printf("Enter adres of %s: ", E.fnam);
        scanf("%s", &E.adr);
        printf("Enter telephone number of %s: ", E.fnam);
        scanf("%s", &E.tel);
        printf("Enter salary of %s: ", E.fnam);
        scanf("%f", &E.sal);
        fprintf(p, "\n%s\n%s\n%s\n%s\n%f\n", E.fnam, E.lnam, E.adr, E.tel, E.sal);
        printf("\nDo you want to add any more: ");
        scanf(" %c", &ch);
    }
    rewind(p);
    while (fscanf(p, "%s%s%s%s%f", &E.fnam, &E.lnam, &E.adr, &E.tel, &E.sal) != EOF)
    {
        printf("\nfirst name : %s\n", E.fnam);
        printf("last name : %s\n", E.lnam);
        printf("address  : %s\n", E.adr);
        printf("telephone  : %s\n", E.tel);
        printf("salary : %f\n", E.sal);
        n++;
    }
    rewind(p);
    struct data N[n];

    while (i < n)
    {
        fscanf(p, "%s%s%s%s%f", &N[i].fnam, &N[i].lnam, &N[i].adr, &N[i].tel, &N[i].sal);
        // printf("%d", i);
        i++;
    }
    fclose(p);
    i = 0;
    p = fopen("F_nameDlt", "W");
    printf("name of employee whose data is to be deleted: ");
    scanf("%s", &s);
    while (i < n)
    {
        if (strcmpi(s, N[i].fnam) != 0 || strcmpi(s, N[i].lnam) != 0)
        {
            fprintf(p, "%s\n%s\n%s\n%s\n%f\n", N[i].fnam, N[i].lnam, N[i].adr, N[i].tel, N[i].sal);
        }
        i++;
    }
    fclose(p);
    p = fopen("F_nameDlt", "r");

    while (fscanf(p, "%s%s%s%s%f", &E.fnam, &E.lnam, &E.adr, &E.tel, &E.sal) != EOF)
    {
        printf("\nfirst name : %s\n", E.fnam);
        printf("last name : %s\n", E.lnam);
        printf("address  : %s\n", E.adr);
        printf("telephone  : %s\n", E.tel);
        printf("%f is salary \n", E.sal);
    }
    fclose(p);

    return 0;
}