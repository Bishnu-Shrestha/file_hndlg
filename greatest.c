// program to find the greatest number by accesing the file data....
#include <stdio.h>
void main()
{
	int a, i = 0, j;
	printf("enter lenght ");
	scanf("%d", &a);
	int n[a];
	FILE *fpt;
	fpt = fopen("greatest.txt", "w");
	while (i < a)
	{
		printf("enter %d element: ", i + 1);
		scanf("%d", &n[i]);
		putw(n[i], fpt);
		// fprintf(fpt, "%d\t", n[i]);
		i++;
	}
	fclose(fpt);
	int b[a];
	fpt = fopen("greatest.txt", "r");
	i = 0;
	while (i < a)
	{
		b[i] = getw(fpt);
		// fscanf(fpt, "%d", &b[i]);
		i++;
	}
	fclose(fpt);
	for (i = 0; i < a; i++)
	{
		for (j = i + 1; j < a; j++)
		{
			// using arrey shorting
			int temp = 0;
			if (b[i] < b[j])
			{
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	}
	printf("greatest from shorted arrey is %d.", b[0]);
	fpt = fopen("greatest.txt", "a");
	fprintf(fpt, "\n %d is the greatese", b[0]);
	fclose(fpt);
	int greatest = b[0];
	for (i = 0; i < a; i++)
	{
		if (b[i] > greatest)
			greatest = b[i];
	}
	printf("\ngreatest number from simpler logic is %d.", greatest);
}