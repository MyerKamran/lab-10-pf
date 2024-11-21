#include<stdio.h>
void fun(int n)
{
	if(n<=0){
		return ;
	}
	else{
		fun(n-1);
		printf("%d\t", n);
	}
}
	 int main()
	 {
	 	fun(3);
		return 0;
	 }
