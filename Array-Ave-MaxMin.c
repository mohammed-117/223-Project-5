#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CopyData(char c[], int a[]);
void Display(int a[]);
float FindAve(int a[]);
void DisplayAbove(int a[], float average);
void FindMaxMin(int a[], int *max, int *min);
void DisplayMaxMin(int max, int min);

int main()
{

	int a[6];
	float average;
	int max, min;

	CopyData("data.txt", a);
	Display(a);

	average = FindAve(a);

	printf("\nAverage = %.2f \n", average);

	DisplayAbove(a, average);
	FindMaxMin(a, &max, &min);

	DisplayMaxMin(max, min);

	printf("\n\n");
	system("PAUSE");
	return 0;
}

void CopyData(char c[], int a[])
{
	int number = 0;
	int i = 0;

	FILE * fpointer;
	fpointer = fopen("data.txt", "r");

	if (fpointer == NULL)
	{
		printf("%s is not open", "data.txt");

		exit(-1);
	}

	while (!feof(fpointer))
	{
		fscanf(fpointer, "%d", &number);
		a[i] = number;
		i++;
	}


	fclose(fpointer);
	return 0;
}

void Display(int a[])
{
	int i;
	printf("This is array a: ");
	for (i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

float FindAve(int a[])
{
	int i;
	float average;
	float total;
	float n = 6.00;

	for (i = 0; i < 6; i++)
	{
		total += a[i];
	}

	average = (total / n);
	return average;
}

void DisplayAbove(int a[], float average)
{
	int i;
	printf("Data value above average: ");
	for (i = 0; i < 6; i++)
	{
		if (a[i] >= (int)average)
		{
			printf("%d ", a[i]);
		}
	}

	return 0;
}

void FindMaxMin(int a[], int *max, int *min)
{
	int i, j, maximum, minimum;

	maximum = a[0];
	minimum = a[0];

	for (i = 0; i < 6; i++)
	{
		if (a[i] > maximum)
		{
			maximum = a[i];
		}
	}

	for (j = 0; j < 6; j++)
	{
		if (a[j] < minimum)
		{
			minimum = a[j];
		}
	}

	*max = maximum;
	*min = minimum;

	return 0;
}

void DisplayMaxMin(int max, int min)
{
	printf("\nMaximum : %d\n", max);
	printf("Minimum : %d", min);

	return 0;
}
