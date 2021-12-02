

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mat[20][20][20],states[20],trans[3]={'0','1','e'},stack[100],epsilon[20][20];
int numst,numtra=3,i=0,y,top=0;
char dummy;
char generated[20][20];
char ans[50];
void findep(char state);
int findindex(char state);
void findepsilon();
void nfa2dfa();
void printepsilon(char ch[],int i);
int present();
void printanswer();
void main()
{
  printf("Enter the states:");
  scanf("%s",states);
  numst=strlen(states);
  for(i=0;i<numst;i++)
  {
   printf("Enter transition under %c : ",states[i]);
   for(int j=0;j<numtra;j++)
   { scanf("%s",mat[i][j]); }
  }
  printf("0 1 e\n");
  for(i=0;i<numst;i++)
  {
   printf("%c ",states[i]);
   for(int j=0;j<numtra;j++)
    printf("%s ",mat[i][j]);
   printf("\n");
  }
  findepsilon();
  printf("\n Epsilon Closure\n");
  for(i=0;i<numst;i++)
   printf("%c: %s \n",states[i],epsilon[i]);
  printf("\n DFA \n");
  nfa2dfa();
  }
  void findepsilon()
  {
   char temp[2];
   for(y=0;y<numst;y++)
   {
    temp[0]=states[y];
    temp[1]='\0';
    strcat(epsilon[y],temp);
    findep(states[y]);
    }
  }
  int findindex(char state)
  {
   for(i=0;i<numst;i++)
    if(states[i]==state)
     return i;
    return -1;
  }
  void findep(char state)
  {
   char eps[20];
   int ind=findindex(state);
   if(ind!=-1)
   {
    strcpy(eps,mat[ind][2]);
    if(strcmp(eps,"-")!=0)
    {
     strcat(epsilon[y],eps);
     int num=strlen(eps);
     for(int x=0;x<num;x++)
      findep(eps[x]);
    }
   }
  }
  void nfa2dfa()
  {
   char temp[20];
   printf("   0   1\n");
   printf("A: ");
   strcpy(generated[top++],epsilon[0]);
   strcpy(temp,epsilon[0]);
   printepsilon(temp,0);
   printepsilon(temp,1);
   for(int xy=1;xy<top;xy++)
   {
   printf("\n%c :",xy+'A');
   strcpy(temp,generated[xy]);
   printepsilon(temp,0);
   printepsilon(temp,1);
   }
   printf("\n");
  }
  void printanswer(char ch[])
  {
   int flag=0;
   for(int i=0;i<top;i++)
   {
    if(strcmp(ch,generated[i])==0)
    {
     printf("%c",i+'A');
     flag=1;
     break;
    }
   }
   if(flag==0)
    printf("%c",top+'A');
  }
  void printepsilon(char ch[],int off)
  {
   char temp[20]=" ",temp1[20]=" ",tt;
   int f1=0,index1=-1;
   for(int i=0;i<strlen(ch);i++)
   {
   int index=findindex(ch[i]);
   if(strcmp(mat[index][off],"-")!=0)
   {
   strcat(temp1,mat[index][off]);
   if(strlen(temp1)>1)
   {
   for(int xyz=0;xyz<strlen(temp1);xyz++)
   {
   tt=temp1[xyz];
   index1=findindex(tt);
   strcat(temp,epsilon[index1]);
   }
   }
   else
   {
    tt=temp1[0];
    index1=findindex(tt);
    strcat(temp,epsilon[index1]);
    f1++;
   }
   }
   strcpy(temp1," ");
   }
   printanswer(temp);
   printf("\t");
   if(present(temp)==0)
   {
   strcpy(generated[top++],temp);
   }
   strcpy(temp,"");
   f1=0;
   strcpy(temp1,"");
   }
   int present(char new[])
   {
    for(int i=0;i<top;i++)
    {
     if(strcmp(new,generated[i])==0)
     return 1;
    }
    return 0;
   }
   

