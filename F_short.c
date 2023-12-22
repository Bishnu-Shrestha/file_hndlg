// Program to short the user input and store in seperate file.
#include <stdio.h>
int main()
{
    int a, n, i = 0, j;
    printf("Enter total numbers you want to store: ");
    scanf("%d", &n);
    int b[n];
    FILE *p, *q;
    p = fopen("F_short.txt", "w");
    while (i < n)
    {
        printf("Enter %d data: ", i + 1);
        scanf("%d", &a);
        fprintf(p, "%d\n", a);
        i++;
    }
    fclose(p);
    printf("displaying un-shorted data:\n");
    i = 0;
    a = 0;
    p = fopen("F_short.txt", "r");
    while (fscanf(p, "%d", &b[i]) != EOF)
    {
        printf("\n %d ", b[i]);
        i++;
    }
    fclose(p);
    i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n)
        {
            if (b[i] < b[j])
            {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
            j++;
        }
        i++;
    }
    printf("\ndisplaying shorted data:\n");
    i = 0;
    while (i < n)
    {
        printf("\n %d ", b[i]);
        i++;
    }
    q = fopen("F_short2.txt", "w");
    i = 0;
    while (i < n)
    {
        fprintf(q, "%d\n", b[i]);
        i++;
    }
    return 0;
}