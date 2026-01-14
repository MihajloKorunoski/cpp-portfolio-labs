#include <stdio.h>

void writeToFile()
{
	FILE *f = fopen("input.txt", "w");
	char c;
	while ((c = getchar()) != '#')
	{
		fputc(c, f);
	}
	fclose(f);
}
void printFile()
{
	FILE* f = fopen("output.txt", "r");
	char line[100];
	while (!feof(f))
	{
		fgets(line, 100, f);
		if (feof(f))
			break;
		printf("%s", line);
	}
	fclose(f);
}
int main()
{
	writeToFile();
	FILE* f = fopen("input.txt", "r");
	int a[100][100];
	int i, j, n, sum = 0;
	fscanf(f, "%d", &n);
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			fscanf(f, "%d", &a[i][j]);
			if (i == j)
				sum += a[i][j];
		}
	fclose(f);
	FILE* f1 = fopen("output.txt", "w");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i < j)
				fprintf(f, "%0.3d", sum);
			else
				fprintf(f, "      ");
		}
		fprintf(f1, "\n");
	}
	fclose(f1);
	printFile();
	return 0;
}