#include <iostream>
using namespace std;

//Toeplitz Matrix
class matrices{
    private:
       int *arr;
       int n;

    public:
       matrices(){
           n=10;
           arr=new int[2*n-1];
       }

       matrices(int n){
           this->n=n;
           arr=new int[2*n-1];
       }

       ~matrices(){
           delete []arr;
       }
       
       void create();
       void set(int i, int j, int x);
       int get(int i, int j);
       void display();
};


void matrices::create(){
    int elem;

    cout<<endl<<"\nEnter Elements : \n";
    for (int i=1 ; i <= n ; i++){
        for (int j=1 ; j <= n ; j++){
            cin>>elem;
            set(i,j,elem);
        }
        cout<<endl;
    }
}


void matrices::set(int i, int j, int x){
    if (i <= j)
       arr[j-i]=x;

    else if (i > j)   
       arr[n-1+i-j]=x;
}


int matrices::get(int i, int j){
    if (i <= j)
       return arr[j-i];

    else if (i > j)   
       return arr[n-1+i-j];

    return 0;   
}


void matrices::display(){
    for (int i=1 ; i <= n ; i++){
        for (int j=1 ; j <= n ; j++){
            if (i <= j)
                printf("%d\t",arr[j-i]);

            else if (i > j)   
                printf("%d\t",arr[n-1+i-j]);
        }
        printf("\n");
    }
}


int main(){
    int elem,n,choice,i,j;
    char ch='y';

    cout<<endl<<"Enter Dimension : ";
    cin>>n;

    matrices m(n);
    
    cout<<endl<<endl<<endl<<"\tMain Menu";
    cout<<endl<<endl<<"1.Create Matrix";
    cout<<endl<<"2.Set Matrix";
    cout<<endl<<"3.Get Matrix";
    cout<<endl<<"4.Display";
    cout<<endl<<"5.Exit";

    while (ch=='y' || ch=='Y'){
        printf("\nEnter your choice (1-5) : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: m.create();
                    ch='y';
                    break; 

            case 2: printf("\n\nEnter Element : ");
                    scanf("%d",&elem);        
                    printf("\nEnter indexes i and j : ");
                    scanf("%d %d",&i,&j);
                    m.set(i,j,elem);
                    ch='y';
                    break; 

            case 3: printf("\n\nIndexes i and j : ");
                    scanf("%d %d",&i,&j);         
                    printf("\nElement at M[%d][%d] is %d",i,j,m.get(i,j));
                    ch='y';
                    break;

            case 4: printf("\n\nElements : \n");
                    m.display();
                    ch='y';
                    break;

            case 5: exit(0);

            default: printf("\n\nIncorrect choice\n");
                     ch='y';        
                     break;
        }
    }

    return 0;
}