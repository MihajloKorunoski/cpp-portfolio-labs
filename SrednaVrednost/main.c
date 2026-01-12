#include<stdio.h>
#include<math.h>
int prosek(int *a, int n){
    int pom=0;
    for(int i=0;i<n;i++)
        pom+=a[i];
    pom=pom/n;
    int najblisku=abs(a[0]-pom);
    int indeks=0;
    for(int i=0;i<n;i++){
        if(abs(a[i]-pom)<najblisku){

            najblisku=abs(a[i]-pom);
            indeks=i;
        }
        if(abs(a[i]-pom)==najblisku) {
            if (a[i] < a[indeks]) {
                najblisku = abs(a[i] - pom);
                indeks = i;
            }
        }
    }
    if(najblisku==0)
        return pom;
    return a[indeks];

}
int main()
{
    int i, n, najblisku;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    najblisku=prosek(a,n);

    printf("%d\n",najblisku);
    return 0;
}