#include<stdio.h>

int sumofdigits(int n){
	if(n == 0){
		return 0;
	}
	return (n % 10) + sumofdigits(n/10);
}

int main()
{
	int number;
	printf("enter a number: ");
	scanf("%d",&number);
	printf("sum o9f digits of the number %d is : %d \n ", number , sumofdigits(number) );
	
	return 0;
}