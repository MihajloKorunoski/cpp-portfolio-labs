#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define 	MEMCHECK(x) if(x==NULL) { printf("Nema memorija!\n"); exit(-1); }

typedef char * key_struct;
typedef int value_struct;

typedef struct hashmap_element
{
    key_struct key;                      // kluc
    value_struct value;                  // vrednost
}hashmap_node;                 // Definiranje element vo hash mapa

typedef struct element
{
    hashmap_node info;
    struct element *link;
} h_node;                        // Definiranje na element vo linearna lista (koficka) vo hash mapa

typedef h_node * h_nodep;

typedef struct cbht
{
    int size;
    h_node ** buckets;           // niza od koficki (linearni listi)
}hashmap;                      // Definiranje na hash mapa

void make_hash_map(hashmap *tptr, int n)  // inicijalizacija na hash mapa
{
    int i;
    tptr->buckets=(h_node **) calloc(n, sizeof(h_node *));
    // alokacija na memorija za nizata od koficki
    tptr->size=n;
    //for(i=0;i<tptr->size;i++)
    // tptr->buckets[i]=NULL;
}

int hashCode(key_struct key)
{
    return key[0]-'A';             // funkcija koja naoga hash kod na char *
    // za drugi tipovi na klucevi treba da se definira druga hashCode funkcija
}

int hash(key_struct key, hashmap *tptr)
{ // funkcija koja presmetuva hash
    return hashCode(key)%(tptr->size);

}

h_node * search(key_struct targetKey, hashmap *tptr)
// funkcija za prebaruvanje vo hash
{
    int h;
    h_node *p;
    h=hash(targetKey, tptr);
    for(p=tptr->buckets[h]; p!=NULL; p=p->link)
    {
        if (!strcmp((p->info).key, targetKey))
            return p;
    }
    return NULL;
}

void insert(key_struct key, value_struct val, hashmap *tptr)
// funkcija za vnesuvanje vo hash
{
    h_node *tmp;
    h_node *p;
    int h;

    h=hash(key, tptr);
    p=(h_node *) malloc(sizeof(h_node));  // alokacija za noviot jazel
    (p->info).value=val;
    (p->info).key=key;

    for(tmp=tptr->buckets[h]; tmp!=NULL; tmp=tmp->link)
    {// ako veke postoi takov zapis
        if (!strcmp((tmp->info).key, key))
        {
            (tmp->info).value=val;   // se zamenuva so novata vrednost
            return;
        }
    }

    // se vnesuva noviot jazel na pocetokot na kofickata h
    p->link=tptr->buckets[h];
    tptr->buckets[h]=p;
}

void delete(key_struct key, hashmap *tptr)
// funkcija za brisenje na onie jazli so ist kluc kako dadeniot
{
    h_node *p, *last;
    int h;

    h=hash(key,tptr);
    for (p=tptr->buckets[h]; p!=NULL; p=p->link) {
        if (!strcmp((p->info).key, key))
            break;
    }
    if (p==NULL) return;   // ako nema takvi jazli za brisenje

    if(p==tptr->buckets[h])   // ako najdeniot e na pocetok na koficka za brisenje
        tptr->buckets[h]=p->link;
    else
    {
        // naoganje na prethodnikot na jazelot sto treba da se izbrise
        for (last=tptr->buckets[h];(last!=NULL)&&(last->link!=NULL);last=last->link) {
            if (last->link==p)
                break;
        }
        last->link=p->link;
    }

    free(p);                  // brisenje na jazel
}

void print_h_node(h_node *p)
{
    printf("(%s,%d)",(p->info).key,(p->info).value);
}

void print_hashmap(hashmap *tptr)
{
    int i; h_node *p;
    for(i=0;i<tptr->size;i++)
    {
        printf("%d:",i);
        for(p=tptr->buckets[i]; p!=NULL; p=p->link)
            print_h_node(p);
        printf("\n");
    }
}
int main()
{
    int N,i;
    scanf("%d",&N);
    char user[100][N+N/2];
    char pass[100][N+N/2];
    hashmap *heshtabela=(hashmap *)malloc(sizeof(hashmap));
    hashmap *heshtabela2=(hashmap *)malloc(sizeof(hashmap));
    make_hash_map(heshtabela,20);
    make_hash_map(heshtabela2,20);
    for(i=0; i<N; i++)
    {
        scanf("%s",user[i]);
        insert(user[i],i,heshtabela);
        scanf("%s",pass[i]);
        insert(pass[i],i,heshtabela2);
    }
    print_hashmap(heshtabela2);
    char line[100];
    int flag=0;
    h_node *p,*q;
    while(scanf("%s",line)){
        if(strcmp(line,"KRAJ")==0){
            break;
        }
        if(flag==0){
            flag++;
            p=search(line,heshtabela);
        }
        else if (flag==1){
            flag=0;
            q=search(line,heshtabela2);

                if(q==NULL||p==NULL||p->info.value!=q->info.value){
                    printf("Nenajaven\n");
                } else if(p->info.value==q->info.value) {
                    printf("Najaven\n");
                    break;
                }
        }

    }
    return 0;
}