/*
*Name = Rishabh
*Reg No = 201800631
*Dept = IT
*Due Lab Date = 2 Nov 2020
*Lab Work : 10
*
*AIM :  Factorial of a number using Recursion and Iteration
*/

#include<stdio.h>
long int fact(int n);
long int Ifact(int n);

int main( )
{
        int num;
        printf("Enter a number : ");
        scanf("%d", &num);

        printf("\nUsing Recursion :: \n");
        if(num<0)
                printf("No factorial for negative number\n");
        else
                printf("Factorial of %d is %ld\n", num, fact(num) );

    printf("\nUsing Iterative :: \n");

        if(num<0)
                printf("No factorial for negative number\n");
        else
                printf("Factorial of %d is %ld\n", num, Ifact(num) );

                return 0;
}/*End of main()*/

/*Recursive*/
long int fact(int n)
{
        if(n == 0)
                return(1);
        return(n * fact(n-1));
}/*End of fact()*/

/*Iterative*/
long int Ifact(int n)
{
        long fact=1;
        while(n>0)
        {
                fact = fact*n;
                n--;
        }
        return fact;
}/*End of ifact()*/