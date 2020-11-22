#include <stdio.h> 
void print(int n) 
{ 
    int i,j; 
    for(i=1; i<=n; i++) 
    { 
        for(j=1; j<=n-i; j++) 
        { 
            printf(" "); 
        } 
        for(j=n-i+1; j<n+i; j++) 
        { 
            printf("*"); 
        } 
        printf("\n"); 
    } 
     
    for(i=n-1; i>=1; i--) 
    { 
        for(j=1; j<=(n-i); j++) 
        { 
            printf(" "); 
        } 
        for(j=n-i+1; j<n+i; j++) 
        { 
            printf("*"); 
        } 
        printf("\n"); 
    } 
} 
 
int main() 
{ 
    int n=7; 
    print(n); 
    return 0;
} 
