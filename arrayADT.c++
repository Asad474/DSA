#include <iostream>
#include <conio.h>
using namespace std;

class array{    
private:
    int *A;
    int capacity;
    int size;

public: 
    array(){
        capacity=10;
        size=0;
        A=new int[capacity];
    }

    array(int sz){
        capacity=sz;
        size=0;
        A=new int[capacity];
    }

    ~array(){
        delete []A;
    }

    void append(int data);
    void insert(int index, int data);
    void del(int index);    
    void swap(int *a,int *b);
    void display();
    void bubblesort();
    int linearsearch(int data);
    int binarysearchiter(int data);
    int binarysearchrecur(int low, int high, int data);
    int get(int index);
    void set(int index, int data);
    int max();
    int min();
    int sum();
    int sumrev(int n);
    float avg();
    void reverse();
    void leftrotateshift();
    void rightrotateshift();
    int checksort();
    void insertinsort(int data);
    void rearrangenegpos();
    array* merge(array *arr2);
    array* unionunsort(array *arr2);
    array* unionsort(array *arr2);
    array* differenceunsort(array *arr2);
    array* differencesort(array *arr2);
    array* intersectunsort(array *arr2);
    array* intersectsort(array *arr2);
};


void array::swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void array::bubblesort(){
    for (int i=0 ; i < size-1 ; i++){
        for (int j=i+1; j < size ; j++){
            if (A[i] > A[j])
                swap(&A[i],&A[j]);
        }
    }
}


void array::display(){
    cout<<endl<<"Array Elements : ";
    for (int i=0 ; i < size ; i++)
        cout<<A[i]<<" ";

    cout<<endl<<endl<<"Capacity : "<<capacity;
    cout<<endl<<"Size : "<<size;            
}


void array::append(int data){
    if (capacity > size){
        A[size]=data;
        size++;
    }
    else 
        cout<<endl<<"Capacity is full!!!";
}


void array::insert(int index, int data){
    if (capacity > size && index >= 0 && index <= size){
        for (int i=size ; i > index ; i--)
            A[i]=A[i-1];
        A[index]=data;
        size++;    
    }
}


void array::del(int index){
    if (index >=0 && index < size){
        for (int i=index ; i < size-1 ; i++)
            A[i]=A[i+1];
        size--;    
    }
}


int array::linearsearch(int data){
    for (int i=0 ; i < size ; i++){
        if (A[i] == data){
            swap(&A[i],&A[0]);
            return i;
        }
    }

    return -1;
}


int array::binarysearchiter(int data){
    int low=0 , high=size-1;
    int mid;

    while (low <= high){
        mid=(high+low)/2;
        if (A[mid] == data)
            return mid;

        else if(A[mid] > data)    
            high=mid-1;

        else 
            low=mid+1;    
    }

    return -1;
}


int array::binarysearchrecur(int low, int high, int data){
    if (low > high)
        return -1;

    int mid=(high+low)/2;
    if (A[mid] == data)    
        return mid;
    
    else if (A[mid] > data)
        return binarysearchrecur(low,mid-1,data);

    else 
        return binarysearchrecur(mid+1,high,data);    
}


int array::get(int index){
    if (index >= 0 && index < size)
        return A[index];
    return -1;    
}


void array::set(int index, int data){
    if (index >= 0 && index < size)
       A[index]=data;
    else 
       cout<<endl<<"Given index out of range!!!";   
}


int array::max(){
    int max=A[0];
    for (int i=1 ; i < size ; i++){
        if (A[i] > max)
           max=A[i];
    }

    return max;
}


int array::min(){
    int min=A[0];
    for (int i=1 ; i < size ; i++){
        if (A[i] < min)
           min=A[i];
    }

    return min;
}


int array::sum(){
    int sum=0;
    for (int i=0 ; i < size ; i++) 
        sum+=A[i];  
    return sum;    
}


int array::sumrev(int n){
    if (n < 0)
       return 0;

    return sumrev(n-1) + A[n];   
}


float array::avg(){
    return (float) sum()/size;
}


void array::reverse(){
    for (int i=0 ; i<size/2 ; i++)
        swap(&A[i],&A[size-1-i]);
}


void array::leftrotateshift(){
    int temp=A[0] , i;
    for (i=0 ; i < size-1 ; i++)
        A[i]=A[i+1];
    A[i]=temp;    
}


void array::rightrotateshift(){
    int temp=A[size-1] , i;
    for (i=size-1 ; i>0 ; i--)
        A[i]=A[i-1];
    A[i]=temp;    
}


int array::checksort(){
    for (int i=0 ; i<size-1 ; i++){
        if (A[i] > A[i+1])
           return 0;
    }
    return 1;
}


void array::insertinsort(int data){
    int i=size-1;
    if (capacity > size){
        while (A[i] > data && i>=0){   
            A[i+1]=A[i];
            i--;
        }
    }    

    A[i+1]=data;   
    size++;
}


void array::rearrangenegpos(){
    int i=0 , j=size-1;
    if (i < j){
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j)
           swap(&A[i],&A[j]);
    }    
}


array* array::merge(array *arr2){
    int i=0 , j=0 , k=0;
    array *arr3=new array(size+arr2->size);

    while (i < size && j < arr2->size){
        if (A[i] < arr2->A[j])
           arr3->A[k++]=A[i++];
        else 
           arr3->A[k++]=arr2->A[j++];   
    }

    for (; i <size ; i++)
        arr3->A[k++]=A[i];
    for (; j < arr2->size ; j++)    
        arr3->A[k++]=A[j];

    arr3->size=k;
    return arr3;    
}


array* array::unionunsort(array *arr2){
    int k=0, f;
    array *arr3=new array();

    for (int i=0 ; i<size ; i++)
        arr3->A[k++]=A[i];

    for (int j=0 ; j < arr2->size ; j++){
        f=0;
        for (int i=0 ; i < size ; i++){
            if (A[i] == arr2->A[j]){
                f=1;
                break;
            }
        }

        if (f==0)
            arr3->A[k++]=arr2->A[j];
    }

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;
}


array* array::unionsort(array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array();

    while (i < size && j < arr2->size){
        if (A[i] == arr2->A[j]){
            arr3->A[k++]=A[i++];
            j++;
        }

        else if (A[i] < arr2->A[j])
            arr3->A[k++]=A[i++];

        else 
            arr3->A[k++]=arr2->A[j++];    
    }

    for (; i <size ; i++)
        arr3->A[k++]=A[i];
    for (; j < arr2->size ; j++)    
        arr3->A[k++]=A[j];

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;
}


array* array::intersectunsort(array *arr2){
    int k=0 , f;
    array *arr3=new array();

    for (int i=0 ; i < size ; i++){
        f=0;
        for (int j=0 ; j < arr2->size ; j++){
            if (A[i] == arr2->A[j]){
                f=1;
                break;
            }
        }

        if (f==1)
            arr3->A[k++]=A[i];
    }

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;
}


array* array::intersectsort(array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array();

    while (i < size && j < arr2->size){
        if (A[i] == arr2->A[j]){
            arr3->A[k++]=A[i++];
            arr2->A[j++];
        }

        else if (A[i] < arr2->A[j])
            i++;

        else 
            j++;    
    }

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;
}


array* array::differenceunsort(array *arr2){
    int k=0 , f;
    array *arr3=new array();

    for (int i=0 ; i < size ; i++){
        f=0;
        for (int j=0 ; j < arr2->size ; j++){
            if (A[i] == arr2->A[j]){
                f=1;
                break;
            }
        }

        if (f==0)
            arr3->A[k++]=A[i];
    }

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;
}


array* array::differencesort(array *arr2){
    int i,j,k;
    i=j=k=0;
    array *arr3=new array();

    while (i < size && j < arr2->size){
        if (A[i] == arr2->A[j]){
            i++;
            j++;
        }

        else if (A[i] < arr2->A[j])
            arr3->A[k++]=A[i++]; 

        else 
            j++;    
    }

    for (; i < size ; i++)
        arr3[k++]=A[i];

    arr3->size=k;
    arr3->capacity=(arr3->size)*2;
    return arr3;    
}


int main(){
    array arr1(10);
    char ch='y';

    while (ch=='y' || ch=='Y'){
        printf("\n\t\tMain Menu");
        printf("\n\n1.Append");
        printf("\n2.Insert");
        printf("\n3.Delete");
        printf("\n4.Search");
        printf("\n5.Max and Min");
        printf("\n6.Sum and Avg");
        printf("\n7.Display");
        printf("\n8.Exit");

        int choice , elem , index;
        printf("\n\nEnter your choice (1-8) : ");
        scanf("%d",&choice);
        printf("\n\nPress Enter or any other character!!!");
        getch();
        system("cls");

        switch(choice){
            case 1: cout<<endl<<"Enter Element : ";
                    cin>>elem;
                    arr1.append(elem);
                    break;

            case 2: cout<<endl<<"Enter Element : ";
                    cin>>elem;    
                    cout<<endl<<"Enter Index : ";
                    cin>>index; 
                    arr1.insert(index,elem);
                    break;

            case 3: cout<<endl<<"Enter index of element to be deleted : ";
                    cin>>index;
                    arr1.del(index);
                    break;

            case 4: cout<<endl<<"Enter Element for searching : ";
                    cin>>elem;
                    int n;
                    printf("\n\n1.Binary Search");
                    printf("\n2.Linear Search");
                    cout<<endl<<"Enter your choice(1-2) : ";
                    cin>>n;

                    printf("\n\n");
                    if (n == 1){
                        int index=arr1.binarysearchiter(elem);
                        if (index == -1)
                            printf("\n%d does not exist in the array!!!",elem);
                        else     
                            printf("\n%d found at index %d",elem,index);
                    }

                    else{
                        int index=arr1.linearsearch(elem);
                        if (index == -1)
                            printf("\n%d does not exist in the array!!!",elem);
                        else     
                            printf("\n%d found at index %d",elem,index);                        
                    }

                    break;

            case 5: printf("\nMaximum Element : %d",arr1.max());
                    printf("\nMinimum Element : %d",arr1.min());
                    break;

            case 6: printf("\nSum : %d",arr1.sum());    
                    printf("\nAverage : %f",arr1.avg());
                    break;                   

            case 7: arr1.display();
                    break;         

            case 8 : exit(0);        

            default: printf("\nEnter correct choice (1-8)!!!");         
                     break; 
        }
        printf("\n\nPress Enter or any other character!!!");
        getch();
        system("cls");
        fflush(stdin);
        printf("\n\nDo you want to do more operations(y/n) : ");
        scanf("%c",&ch);
    }    
}