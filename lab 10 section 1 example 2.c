#include<stdio.h>
 int sum(int n){
	if(n==0){
		return 0;
	}
	else
	{
		return n + sum(n-1);
	}
	
 }
 int main(){
 	int num=5;
 	printf("sum of the numbers from 1 to %d is %d\n",num,sum(num));
 	return 0;
 }