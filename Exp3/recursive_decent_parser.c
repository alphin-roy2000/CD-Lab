#include<stdio.h>
#include<string.h>
#include<ctype.h>
void E();
void T();
void F();
void Eprime();
void Tprime();
char input[10];
int i,error;
void main(){
	i=0;
	error=0;
	printf("\n Enter the arithmetic expression :- ");
	scanf("%s",input);
	printf("%s",input);
	E();
	if(strlen(input)==i&&error==0)
		printf("\nACCEPTED :)\n");
	else
		printf("\nREJECTED :(\n");
	}
void E(){
	T();
	Eprime();
	}
void Eprime(){
	if(input[i]=='+' || input[i] == '-' ){
		i++;
		T();
		Eprime();
	}}
void T(){
	F();
	Tprime();
	}
void Tprime(){
	if(input[i]=='*' || input[i] == '/'){
		i++;
		F();
		Tprime();
	}
	}
void F(){
	if(isalnum(input[i]))
		i++;
	else if(input[i]=='('){
		i++;
		E();
		if(input[i]==')')
			i++;
		else
			error=1;
	}
	else
		error=1;
	}
		
