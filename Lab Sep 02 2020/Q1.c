/*
*Name = Rishabh
*Reg No = 201800631
*Dept = IT
*Lab Date = 2 Sep 2020
*
*AIM : Store elements in a linear array, and display the addresses of the array elements using pointers.
*/


#include <stdio.h>

int main()
{
    int arr[10] ;
    int *p = arr;
    
    printf("Enter 10 integers : ");
    for(int i=0; i<10 ; i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("Element\tAddress\n");
    for(int i = 0; i<10; i++) {
        printf("%d\t%p\n",*p,p);
        p++;
    }

 

    return 0;
}