// program to search the file and update salary...
#include <stdio.h>
struct data
{
    char name[25];
    double sal;
} S;
int main()
{
    int count = 0, i;
    FILE *fpt;
    fpt = fopen("f_employe.txt", "r");
    if (fpt == NULL)
    {
        printf("\n \t!!!!!ERROR!!!!\n");
        return -1;
    }

    while (fscanf(fpt, "%s%lf", &S.name, &S.sal) == 2)
        count++;
    struct data A[count];
    rewind(fpt);
    i = 0;
    while (i < count)
    {
        fscanf(fpt, "%s%lf", &A[i].name, &A[i].sal);
        i++;
    }
    fclose(fpt);
    for (i = 0; i < count; i++)
    {
        printf("%s\tRS.%lf\n", A[i].name, A[i].sal);
    }
    i = 0;
    while (i < count)
    {
        fscanf(fpt, "%s%lf", &A[i].name, &A[i].sal);
        if (A[i].sal >= 5000)
            A[i].sal += 0.2 * A[i].sal;
        i++;
    }
    for (i = 0; i < count; i++)
    {
        printf("\t%s\tRS.%lf\n", A[i].name, A[i].sal);
    }
    fpt = fopen("f_employe.txt", "w");
    i = 0;
    while (i < count)
    {
        fprintf(fpt, "%s\t%lf\n", A[i].name, A[i].sal);
        i++;
    }
    fclose(fpt);
    return 0;
}