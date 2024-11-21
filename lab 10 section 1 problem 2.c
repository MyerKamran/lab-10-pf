#include<stdio.h>
#include<string.h>
void reversestring(char str[] , int start , int end ){
	if(start >= end){
		return;
	}
	char temp = str[start];
	str[start]=str[end];
	str[end]=temp;
}
int main()
{
	char str[100];
	printf("enter a string");
	fgets(str , sizeof(str) , stdin);
	str[strcspn(str , "\n" )] = 0;
	int length = strlen(str);
	reversestring(str, 0, length-1);
	printf("Reversed string is : %s\n", str);
	
	return 0;
}