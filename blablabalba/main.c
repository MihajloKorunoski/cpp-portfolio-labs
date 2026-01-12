#include <stdio.h>
#include <malloc.h>

typedef struct Cake {
    int code;
    int price;
    struct Cake *link;
} node;

node *mk_link_list(int n) {
    node *p = NULL, *q = NULL, *r = NULL;
    int i, code, price;

    for (i = 0; i < n; i++) {
        scanf("%d", &code);
        scanf("%d", &price);
        r = (node *) malloc(sizeof(node));

        r->code = code;
        r->price = price;
        r->link = NULL;
        if (p == NULL)
            p = r;
        else
            q->link = r;
        q = r;
    }
    return (p);
}

node *removeCakes(node *p) {
    double pom=0.0;
    int pom2=0;
    node *temp=p;
    while(temp!=NULL){
        pom+=temp->price;
        pom2++;
        temp=temp->link;
    }
    pom=pom/pom2;
    temp=p;
    node *pred=p;
    while(temp!=NULL){
        if(temp->price>pom){
                if(pred==p){
                    p=p->link;
                    temp=pred=p;
                } else {
                    pred->link=temp->link;
                    temp=temp->link;
                }
            } else {
                pred=temp;
                temp=temp->link;
            }
    }
    return p;
}

int main() {
    node *p;
    int n;

    scanf("%d", &n);
    p = mk_link_list(n);
    p = removeCakes(p);

    while (p != NULL) {
        printf("%d\n", p->code);
        p = p->link;
    }
    return (0);
}
/*public static void removeCakes(SLL cakes) {
    double sum=0;
    int count=0;
    SLLNode temp=cakes.first;
    while(temp!=null)
    {
        count++;
        sum+=temp.price;
        temp=temp.succ;
    }
    double prosek=sum/count;
    SLLNode prev=cakes.first;
    temp=cakes.first;
    while(temp!=null)
    {
        if(temp.price>prosek)
        {
            if(temp==cakes.first)
            {
                cakes.first=cakes.first.succ;
                temp=prev=cakes.first;
            }
            else
            {
                prev.succ=temp.succ;
                temp=temp.succ;
            }
        }
        else
        {
            prev=temp;
            temp=temp.succ;
        }
    }
}*/