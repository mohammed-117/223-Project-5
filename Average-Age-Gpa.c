#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct RECORD
{
	char Name[16];
	int Age;
	float Gpa;
} RECORD;


void CopyRecords(char fileName[], RECORD *p);
int getSize(char fileName[]);
void Display(RECORD *p, int n);
float AgeAverage(RECORD *p, int n);
void GpaAverage(RECORD *p, float *GpaAve, int n);
void DisplayBothAve(float age, float gpa);



int main()
{
	// set size
	int n = getSize("data2.txt");

	// allocate the dynamic array
	RECORD *p = (RECORD*)calloc(n, sizeof(RECORD));

	//Copy records from file into dynamic array
	CopyRecords("data2.txt", p);

	//Display Records
	Display(p, n);


	// Get Averages
	float AgeAve = AgeAverage(p, n);
	float GpaAve;
	GpaAverage(p, &GpaAve, n);
	DisplayBothAve(AgeAve, GpaAve);

	//Free resources
	free(p);

}

//get the size from the file
int getSize(char fileName[])
{
	FILE *file = fopen(fileName, "r");
	char buff[300];
	fscanf(file, "%s", buff);

	fclose(file);

	return atoi(buff);
}


//copy the records from the file, and into
// a dynamic array of RECORDS
void CopyRecords(char fileName[], RECORD *p)
{
	FILE *file = fopen(fileName, "r");
	char buff[300];

	fscanf(file, "%s", buff);
	int n = atoi(buff);
	int i;
	for (i = 0; i < n; ++i)
	{
		char name[16] = "";
		fscanf(file, "%s", buff);

		do
		{
			strcpy(name, strcat(name, strcat(buff, " ")));
			fscanf(file, "%s", buff);
		} while (isalpha(buff[0]));

		strcpy((p + i)->Name, name);
		(p + i)->Age = atoi(buff);

		fscanf(file, "%s", buff);
		(p + i)->Gpa = atoi(buff);

	}

	fclose(file);

}



//Display the RECORDS contained in the given dynamic array
void Display(RECORD *p, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%s\t%d\t%.1f \n", (p + i)->Name, (p + i)->Age, (p + i)->Gpa);
	}
}

// return the average age
float AgeAverage(RECORD *p, int n)
{
	int sum = 0;
	int ageave;
	int i;
	for (i = 0; i < n; ++i)
	{
		sum += ((p + i)->Age);
	}
	ageave = (sum / n);

	return ageave;
}

// return the average gpa
void GpaAverage(RECORD *p, float *GpaAve, int n)
{
	float sum = 0;
	int i;
	for (i = 0; i < n; ++i)
	{
		sum += ((p + i)->Gpa);
	}

	*GpaAve = sum / n;
}

// Display average age and gpa
void DisplayBothAve(float age, float gpa)
{
	printf("Average Age: %.2f\n", age);
	printf("Average Gpa: %.2f\n", gpa);
}
