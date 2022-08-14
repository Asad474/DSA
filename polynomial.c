#include <stdio.h>
#include <stdlib.h>

typedef struct term{
    int coeff;
    int exp;
}term;


typedef struct polynomial{
    int n;
    term *t;
}polynomial;


void create(polynomial *p){
    printf("\nEnter no of terms : ");
    scanf("%d",&p->n);

    p->t=(term*)malloc(p->n*sizeof(term));
    printf("\nEnter polynomial : \n");
    for (int i=0 ; i < p->n ; i++)
       scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
}


void display(polynomial *p){
    int i;

    for (i=0 ; i < p->n-1 ; i++){
        if (p->t[i].coeff < 0)
            printf("(%dx^%d) + ",p->t[i].coeff,p->t[i].exp);  
        else   
            printf("%dx^%d + ",p->t[i].coeff,p->t[i].exp);
    }    
    printf("%dx^%d",p->t[i].coeff,p->t[i].exp);    
}


polynomial* sum(polynomial *p1, polynomial *p2){
    int i,j,k;
    i=j=k=0;

    polynomial *p3=(polynomial*)malloc(sizeof(polynomial));
    p3->t=(term*)malloc((p1->n+p2->n)*sizeof(term));

    while (i < p1->n && j < p2->n){
        if (p1->t[i].exp > p2->t[j].exp)
           p3->t[k++]=p1->t[i++];

        else if (p1->t[i].exp < p2->t[j].exp)
           p3->t[k++]=p2->t[j++];   

        else{
            p3->t[k]=p1->t[i++];
            p3->t[k++].coeff += p2->t[j++].coeff;
        }   
    }

    for (; i < p1->n ; i++){ p3->t[k++]=p1->t[i];}
    for (; j < p2->n ; j++){ p3->t[k++]=p2->t[j];}
    p3->n=k;
    return p3;
}


polynomial* difference(polynomial *p1, polynomial *p2){
    int i,j,k;
    i=j=k=0;

    polynomial *p3=(polynomial*)malloc(sizeof(polynomial));
    p3->t=(term*)malloc((p1->n+p2->n)*sizeof(term));

    while (i < p1->n && j < p2->n){
        if (p1->t[i].exp > p2->t[j].exp)
           p3->t[k++]=p1->t[i++];

        else if (p1->t[i].exp < p2->t[j].exp){
            p3->t[k].exp=p2->t[j].exp;
            p3->t[k++].coeff=-p2->t[j++].coeff;
        }

        else{
            p3->t[k]=p1->t[i++];
            p3->t[k++].coeff -= p2->t[j++].coeff;
        }
    }

    for (; i < p1->n ; i++){ p3->t[k++]=p1->t[i];}
    for (; j < p2->n ; j++){ 
        p3->t[k].exp=p2->t[j].exp;
        p3->t[k++].coeff=-p2->t[j++].coeff;        
    }
    p3->n=k;
    return p3;
}


void swap(term *a, term *b){
    term t=*a;
    *a=*b;
    *b=t;
}


void sort(polynomial *p){
    for (int i=0 ; i < p->n-1 ; i++){
        for (int j=i+1 ; j < p->n ; j++){
            if (p->t[i].exp < p->t[j].exp)
               swap(&p->t[i],&p->t[j]);
            else if (p->t[i].exp == p->t[j].exp)
               swap(&p->t[i+1],&p->t[j]);   
        }
    }
}


void delete(polynomial *p, int j){
    for (int i=j ; i < p->n-1 ; i++)
        p->t[i]=p->t[i+1];
    p->n--;
}


polynomial* multiply(polynomial *p1, polynomial *p2){
    int k=0;
    polynomial *p3=(polynomial*)malloc(sizeof(polynomial));
    p3->t=(term*)malloc((p1->n+p2->n)*sizeof(term));

    for (int i=0 ; i < p1->n ; i++){
        for (int j=0 ; j <p2->n ; j++){
            p3->t[k].exp=p1->t[i].exp+p2->t[j].exp;
            p3->t[k++].coeff=p1->t[i].coeff*p2->t[j].coeff;
        }
    }
    
    p3->n=k;
    sort(p3);
    int i=0,j;
    
    while (i < p3->n-1){
        j=i+1;
        while (p3->t[i].exp == p3->t[j].exp){
            p3->t[i].coeff += p3->t[j].coeff;
            delete(p3,j);
            j=i+1;
        }
        i++;
    }
    return p3;
}


int main(){
    polynomial p1,p2,*p3;

    printf("\nEnter Polynomial 1 : ");
    create(&p1);
    printf("\nEnter Polynomial 2 : ");
    create(&p2);

    printf("\nPolynomial 1 : ");
    display(&p1);
    printf("\nPolynomial 2 : ");
    display(&p2);

    p3=sum(&p1,&p2);
    printf("\n\nSum of two polynomials : ");
    display(p3);

    p3=difference(&p1,&p2);
    printf("\n\nDifference of two polynomials : ");
    display(p3);

    p3=multiply(&p1,&p2);
    printf("\n\nMultiplication of two polynomials : ");
    display(p3);

    return 0;
}