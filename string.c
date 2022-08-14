#include <stdio.h>

void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}


void duplicatesusingbits(char s[]){
    long int A=0 , n=0;
    for (int i=0 ; s[i]!='\0' ; i++){
        n=1;
        n = n<<(s[i]-97);
        if ((n & A) > 0)
            printf("\n%c is a duplicate",s[i]);
        else 
            A = n | A;
    }
}


void permutation(char s[], int low, int high){
    if (low == high){
        printf("%s ",s);
    }
    
    else{
        for (int i=low ; i<=high ; i++){
            swap(&s[low],&s[i]);
            permutation(s,low+1,high);
            swap(&s[low],&s[i]);
        }
    }    
}


int main() {
    char s[]="ABCD";
    permutation(s,0,3);

    char st[]="finding";
    duplicatesusingbits(st);
    return 0;
}