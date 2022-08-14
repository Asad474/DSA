#include <stdio.h>
#include <stdlib.h>

struct element{
    int i;
    int j;
    int x;
};


struct sparse{
    int m;
    int n;
    int num;
    struct element *e;
};


void create(struct sparse *s){
    printf("\n\nEnter Dimensions : ");
    scanf("%d%d",&s->m,&s->n);
    printf("\nEnter no of non-zero elements : ");
    scanf("%d",&s->num);

    s->e=(struct element*)malloc(s->num*sizeof(struct element));

    printf("\n\nEnter Elements : \n");
    for (int i=0 ; i < s->num ; i++)
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
}



void display(struct sparse *s){
    int k=0;

    printf("\n\n");
    for (int i=0 ; i < s->m ; i++){
        for (int j=0 ; j < s->n ; j++){
            if (i == s->e[k].i && j == s->e[k].j)
               printf("%d\t",s->e[k++].x);
            else 
               printf("0\t");
        }
        printf("\n");
    }
}


struct sparse* sum(struct sparse  *s1, struct sparse *s2){
    if ((s1->m != s2->m) || (s1->n != s2->n))
        return NULL;

    struct sparse *sum;
    sum=(struct sparse*)malloc(sizeof(struct sparse));
    sum->m=s1->m;
    sum->n=s1->n;
    sum->e=(struct element*)malloc((sum->m+sum->n)*sizeof(struct element));

    int i,j,k;
    i=j=k=0;

    while (i < s1->num && j < s2->num){
        if (s1->e[i].i < s2->e[j].i)
           sum->e[k++]=s1->e[i++];

        else if (s1->e[i].i > s2->e[j].i)
           sum->e[k++]=s2->e[j++];   

        else{
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++]=s1->e[i++];

            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++]=s2->e[j++];      

            else{
                sum->e[k]=s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }             
        }   
    }

    for (; i < s1->num ; i++)
        sum->e[k++]=s1->e[i];

    for (; j < s2->num ; j++)
        sum->e[k++]=s2->e[j];

    sum->num=k;
    return sum;    
}


int main(){
    struct sparse s1,s2;
    printf("\nEnter first matrix : ");
    create(&s1);
    printf("\n\nEnter second matrix : ");
    create(&s2);

    printf("\n\nFirst matrix : \n");
    display(&s1);
    printf("\n\nSecond matrix : \n");
    display(&s2);

    struct sparse *s3=sum(&s1,&s2);
    if (s3 == NULL)
        printf("\n\nDimensions are not same!!!");

    else{
        printf("\n\nSum of matrices : \n");
        display(s3);
    }

    return 0;
}