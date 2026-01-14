#include <stdio.h>
int n;
//implement the func here
void printArray(int array[])
{
    for(int i = 0; i < n; ++i)
    {
        printf("%d " , array[i]);
	} printf("\n");
}

//use the print func in the int main() func
int main()
{
	

	scanf("%d", &n);

	int niza[n];

	for(int i = 0; i < n; ++i){

		scanf("%d", &niza[i]);
	}


	printArray(niza);

	for(int i = 0; i < n/2; ++i){

		int temp = niza[i];
		niza[i] = niza[n-1-i];
		niza[n-1-i] = temp;
	}

	printArray(niza);

	int newN = 0;
	int entries = 0;
	for(int i = 0; i < n; i += 2){

		niza[entries] = niza[i];
		newN++;
		entries++;
	}
	n = newN;




	printArray(niza);




	for(int i = 0; i < n/2; ++i){

		int temp = niza[i];
		niza[i] = niza[n-1-i];
		niza[n-1-i] = temp;
	}

	printArray(niza);



	return 0;
}

