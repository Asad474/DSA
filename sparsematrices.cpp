#include <iostream>
using namespace std;

class element{
    public:
        int i;
        int j;
        int x;
};


class sparse{
    private:
       int m;
       int n;
       int num;
       element *e;

    public:
       sparse(int m, int n, int num){
           this->m=m;
           this->n=n;
           this->num=num;
           e=new element[num];
       }

       ~sparse(){
           delete []e;
       }

       friend istream & operator>>(istream &in, sparse &s);
       friend ostream & operator<<(ostream &out, sparse &s);
       sparse operator+(sparse &s);
};


istream & operator>>(istream &in, sparse &s){
    cout<<endl;
    for (int i=0 ; i < s.num ; i++)    
        in>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    return in;           
}


ostream & operator<<(ostream &out, sparse &s){
    int k=0;

    cout<<endl;
    for (int i=0 ; i < s.m ; i++){
        for (int j=0 ; j < s.n ; j++){
            if (i == s.e[k].i && j == s.e[k].j)
                out<<s.e[k++].x<<"\t";
            else 
                out<<"0\t";
        }
        cout<<endl;
    }
    return out;
}


sparse sparse::operator+(sparse &s){
    if (m!=s.m || n!=s.n)
       return sparse(0,0,0);

    int i,j,k;
    i=j=k=0;  
    sparse *sum=new sparse(m,n,num+s.num);

    while (i<num && j<s.num){
        if (e[i].i < s.e[j].i)
           sum->e[k++]=e[i++];

        else if (e[i].i > s.e[j].i)   
           sum->e[k++]=s.e[j++];

        else{
            if (e[i].j < s.e[j].j)
                sum->e[k++]=e[i++];

            else if (e[i].j > s.e[j].j)   
                sum->e[k++]=s.e[j++];     

            else{
                sum->e[k]=e[i++];
                sum->e[k++].x += s.e[j++].x;
            }           
        }   
    }

    for (; i < num ; i++){ sum->e[k++]=e[i] ; }
    for (; j < s.num ; i++){ sum->e[k++]=s.e[j] ; }
    sum->num=k;
    return *sum;
}


int main(){
    sparse s1(5,5,6) , s2(5,5,4) ;
    cout<<endl<<"Enter Sparse 1 : ";
    cin>>s1;
    cout<<endl<<"Enter Sparse 2 : ";
    cin>>s2;

    cout<<endl<<endl<<"Sparse 1 : "<<s1;
    cout<<endl<<endl<<"Sparse 2 : "<<s2;

    sparse s3=s1+s2;
    cout<<endl<<endl<<"Sum of sparse 1 and sparse 2 : "<<s3;
}