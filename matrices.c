#include <stdio.h>
#include <stdlib.h>

struct matrices{
    int *arr;
    int n;
};

//Tridiagonal Matrix
void set(struct matrices *m, int i, int j, int x){
    if (i-j == 1)
       m->arr[j-1]=x;

    else if (i-j == 0)   
       m->arr[m->n+i-2]=x;

    else if (i-j == -1)   
       m->arr[(2*m->n)+i-2]=x;
}


void create(struct matrices *m){
    int elem;

    printf("\nEnter Elements : \n");
    for (int i=1 ; i <= m->n ; i++){
        for (int j=1 ; j <= m->n ; j++){
            scanf("%d",&elem);
            set(m,i,j,elem);
        }
        printf("\n");
    }
}


int get(struct matrices *m, int i, int j){
    if (i-j == 1)
       return m->arr[j-1];

    else if (i-j == 0)   
       return m->arr[m->n+i-2];

    else if (i-j == -1)   
       return m->arr[(2*m->n)+i-2];    

    return 0;   
}


void display(struct matrices *m){
    for (int i=1 ; i <= m->n ; i++){
        for (int j=1 ; j <= m->n ; j++){
            if (i-j == 1)
                printf("%d\t",m->arr[j-1]);

            else if (i-j == 0)   
                printf("%d\t",m->arr[m->n+i-2]);

            else if (i-j == -1)   
                printf("%d\t",m->arr[(2*m->n)+i-2]);

            else 
                printf("0\t");
        }
        printf("\n");
    }
}


int main(){
    struct matrices m;
    int choice,elem,i,j;
    char ch='y';

    printf("\nEnter Dimension : ");
    scanf("%d",&m.n);

    m.arr=(int *)malloc(((3*m.n)-2)*sizeof(int));

    printf("\n\n\n\tMAIN MENU");
    printf("\n\n1.Create Matrix");
    printf("\n2.Set Matrix");
    printf("\n3.Get Matrix");
    printf("\n4.Display ");
    printf("\n5.Exit");

    while (ch=='y' || ch=='Y'){
        printf("\nEnter your choice (1-5) : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create(&m);
                    ch='y';
                    break; 

            case 2: printf("\n\nEnter Element : ");
                    scanf("%d",&elem);        
                    printf("\nEnter indexes i and j : ");
                    scanf("%d %d",&i,&j);
                    set(&m,i,j,elem);
                    ch='y';
                    break; 

            case 3: printf("\n\nIndexes i and j : ");
                    scanf("%d %d",&i,&j);         
                    printf("\nElement at M[%d][%d] is %d",i,j,get(&m,i,j));
                    ch='y';
                    break;

            case 4: printf("\n\nElements : \n");
                    display(&m);
                    ch='y';
                    break;

            case 5: exit(0);

            default: printf("\n\nIncorrect choice\n");
                     ch='y';        
                     break;
        }
    }
}