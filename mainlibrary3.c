#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


struct date{
int year;
int month;
int day;
};
struct book{
char name[30];
char auther[30];
int id;
int count;
int total_issue;
}b[500];
struct person{
char name[30];
char family[30];
int birthyear;
struct date raft[5];
struct date bargasht[5];
struct book my_book[5];
int membership_code;
}p[100];
void sort_members(void){
struct person temp;
int i,j;	
for(i=99;i>=0;i--){
for(j=0;j<i;j++){
if(p[j].membership_code>p[j+1].membership_code)	
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;	
}
}	
}	
}
int continu_e(void){
char s[4];	
printf("\nDo you want to continue in this case?(yes or no)");	
scanf("%s",s);
if(strcmp(s,"no")==0)
return 0;
else if(strcmp(s,"yes")==0)
return 1;	
//else
//printf("invalid key");
	
}
void show_menu(void )
{
printf("1)add new member\n2)add new book\n3)borrow\n4)show borrowed book\n5)give back borrowed book\n6)show memberships\n7)show list of books\n8)save information\n9)exit");
}
int find_free(void)
{
int i;
for(i=0;i<100;i++)
{
if(p[i].name[0]=='\0')
return i;	
}
return -1;
}
int find_free_book(void)
{
int i;
for(i=0;i<500;i++)
{
if(b[i].name[0]=='\0')
return i;	
}
return -1;
}
void show(int *count_person,int *count_borrowed_book){
system("cls");
time_t orig_format;
time(&orig_format);
printf ("\nIran's time and date is %s",asctime(localtime(&orig_format)));
printf("number of all memberships is:%d\tnumber of all borrowed books is:%d\n",*count_person,*count_borrowed_book);
}
void add_new_member(int *count_person){
int i,j,what=1;
//char s[4];
while(what){
	
i=find_free();
if (i==-1){

printf("capacity of library is full");
//system("cls");
}
else{

printf("\nenter your name:");
scanf("%s",p[i].name);
printf("\nenter your family:");
scanf("%s",p[i].family);
printf("\nenter your birthyear:");
scanf("%d",&p[i].birthyear);
p[i].membership_code=i+1;
for(j=0;j<5;j++)
{
p[i].my_book[j].name[0]='\0';
}
printf("you are logged in and your membership number is:%d",p[i].membership_code);
(*count_person)++;
}
what=continu_e();
}
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");

}
void add_new_book(void){
int i,j,same=0,what=1;
char auther[30],name[30];
while(what){
printf("\nenter name of book:");
scanf("%s",name);
printf("\nenter name of auther:");
scanf("%s",auther);
for(i=0;i<500;i++)
{
if(strcmp(name,b[i].name)==0)
{
if(strcmp(auther,b[i].auther)==0){

same=1;
j=i;
}	
}
}
if(same==0)	
{
i=find_free_book();
if (i==-1){

printf("capacity of library for adding new book is full");
}
else{
strcpy(b[i].name,name);
strcpy(b[i].auther,auther);
printf("\nenter book's id:");
scanf("%d",&b[i].id);	
	
}
}
else
b[j].count++;
same=0;
what=continu_e();
}
for(i=0;i<500;i++)
b[i].total_issue=b[i].count;
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");
}
void show_borrowed_book(void){
	int code,i,j;
	char s[4];
printf("\nenter your membershipcode to see your list of book:");
scanf("%d",&code);
for(i=0;i<100;i++){
if(p[i].membership_code==code)
{
for(j=0;j<5;j++){
if(p[i].my_book[j].name[0]!='\0')
printf("\nname:%s,auther:%s",p[i].my_book[j].name,p[i].my_book[j].auther);	
}
}	
}
printf("\ndo you want to exit from this case(yes or no)?");
scanf("%s",s);  
if(strcmp(s,"yes")==0){
printf("\nplease wait 5 seconds");	
sleep(5); 
system("cls");
}
else if(strcmp(s,"no")==0){

printf("\nso after 1 minute first page will automaticlly open for you");
sleep(60); 
system("cls");}
}

int find_place_book(int j)
{
int i;
for( i=0;i<5;i++){
if(p[j].my_book[i].name[0]=='\0')
return i;	
	
}
return -1;	
}
calculate_bargasht(int yearr,int monthr,int dayr,int *yearb,int *monthb,int *dayb){
*dayb=dayr+7;
*monthb=monthr;
*yearb=yearr;
if(*dayb>=31){
if(1<=monthr&&monthr<=6){
*dayb=*dayb-31;
*monthb=monthr+1;	
}
else if(7<=monthr&&monthr<12)	{
*dayb=*dayb-30;
*monthb=monthr+1;

}	
else if(monthr==12)	{
*dayb=*dayb-29;
*monthb=monthr+1;
if(*monthb>12)
{
*monthb=1;
*yearb=*yearb+1;	
}
}
}
}
void show_list_books(void ){
int i;
for(i=0;i<500;i++)
{
if(b[i].name[0]!='\0')
printf("\nname of book:%s\tauther of book:%s\tnumber of book(exist in library and not borrowed):%d\n",b[i].name,b[i].auther,b[i].count);	
	
}
}
void borrow_book(int *count_borrowed_book){
int no,i,f,j=-1,found=0,k,what;
char name[30],auther[30];
while(what){

printf("\nenter your membership code:");
scanf("%d",&no);
for(i=0;i<100;i++)
{
if(p[i].membership_code==no){
j=i;
break;
}	
}
if(j==-1)
{
printf("\nyou have entered a wrong code");
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");	
}
else
{
k=find_place_book(j);
if(k==-1){

printf("\nyou cannot borrow more than 5 books ");
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");

}
else{
show_list_books();	
printf("enter name of book that you want to borrow:");
scanf("%s",name);
printf("enter auther of book:");
scanf("%s",auther);
for(i=0;i<500;i++)
{
if (strcmp(b[i].name,name)==0)
{
if(strcmp(b[i].auther,auther)==0)
{
found=1;
f=i;	
	
	}	
}
}
if(found==0){
printf("\nyour book doesnt exist in list!");
	printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");
}
else if(b[f].count==0){

printf("\n sorry!already other people have borrowed all books with this name. Try later");
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");
}
else{
strcpy(p[j].my_book[k].name,name);	
strcpy(p[j].my_book[k].auther,auther);
p[j].my_book[k].id=b[f].id;	
b[f].count--;
(*count_borrowed_book)++;
printf("\nenter year of raft:");
scanf("%d",&p[j].raft[k].year);
printf("\nenter month of raft:");
scanf("%d",&p[j].raft[k].month);
printf("\nenter day of raft:");
scanf("%d",&p[j].raft[k].day);
calculate_bargasht(p[j].raft[k].year,p[j].raft[k].month,p[j].raft[k].day,&p[j].bargasht[k].year,&p[j].bargasht[k].month,&p[j].bargasht[k].day);
printf("\ndate of bargasht is %d/%d/%d",p[j].bargasht[k].year,p[j].bargasht[k].month,p[j].bargasht[k].day);
}
}	
	
}
what=continu_e();
}
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");
}
void give_back_book(int *count_borrowed_book){
int code,id,what=1,month,day,year;
int i,j=-1,k=-1;
while(what){
printf("enter your membership code:");
scanf("%d",&code);
for(i=0;i<100;i++){
if(p[i].membership_code==code)
j=i;	
}
if(j==-1)
printf("\nuser not found!!");
else{
printf("\nenter id of book that you want to give back please:");
scanf("%d",&id);
for(i=0;i<5;i++)
{
if(p[j].my_book[i].id==id)
k=i;	
}
if(k==-1)
printf("\nyou have not borrowed a book with this id!");
else{
for(i=0;i<500;i++)
if(b[i].id==id){
b[i].count++;	
}
p[j].my_book[k].name[0]='\0';
count_borrowed_book--;
printf("enter date that you gived back book:\nenter year:");
scanf("%d",&year);
printf("\nenter month:");
scanf("%d",&month);
printf("\nenter day:");
scanf("%d",&day);
printf("\ndeterminated time (for giving back book)is:%d/%d/%d",p[j].bargasht[k].year,p[j].bargasht[k].month,p[j].bargasht[k].day);
if(year>p[j].bargasht[k].year||(month>p[j].bargasht[k].month&&year>=p[j].bargasht[k].year&&day>=p[j].bargasht[k].day)||
(year==p[j].bargasht[k].year&&month>p[j].bargasht[k].month)||(month>=p[j].bargasht[k].month&&year>=p[j].bargasht[k].year&&day>p[j].bargasht[k].day))
printf("\nyou are late to give back book !!");

}
}
j=-1,k=-1;
what=continu_e();
}
printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");
}

void show_memberships(void){
register int i;
char s[4];
sort_members();
for(i=0;i<100;i++)
{
if(p[i].name[0]!='\0')
printf("\nname & family:%s %s\tmembership code:%d",p[i].name,p[i].family,p[i].membership_code);
	
}
printf("\ndo you want to exit from this case(yes or no)?");
scanf("%s",s);  
if(strcmp(s,"yes")==0){
printf("\nplease wait 5 seconds");	
sleep(5); 
system("cls");
}
else if(strcmp(s,"no")==0){

printf("\nso after 1 minute first page will automaticlly open for you");
sleep(60); 
system("cls");

}
}

void show_all_books(void){
int i;
char s[4];
for(i=0;i<500;i++)
{
if(b[i].name[0]!='\0'){

printf("\nbook:%s\nauther:",b[i].name);
puts(b[i].auther)	;
printf("id:%d",b[i].id);
printf("\ntotal issue:%d**issue not borrowed:%d",b[i].total_issue,b[i].count);
printf("\n*********************");
}
}	
printf("\n\ndo you want to exit from this case(yes or no)?");
scanf("%s",s);  
if(strcmp(s,"yes")==0){
printf("\nplease wait 5 seconds");	
sleep(5); 
system("cls");
}
else if(strcmp(s,"no")==0){

printf("\nso after 1 minute first page will automaticlly open for you");
sleep(60); 
system("cls");

}
}

void free_book(void){
register int i;
	for(i=0;i<500;i++){
b[i].name[0]='\0';
b[i].count=1;}

}
void free_person(void){
register int i,j;
	for(i=0;i<100;i++)
{
p[i].name[0]='\0';
p[i].membership_code=0;
for(j=0;j<5;j++)
p[i].my_book[j].name[0]='\0';
}
	
}

void load_file(int *count_person,int *count_borrowed_book){
FILE *fmember,*fbook,*ftotal;//fmember:file to save members information & fbook:file to save book information & ftotal:file to save totall borrowed books & total members
   register int i,j;
   ftotal=fopen("E:total.dat","r+b");
   if(!ftotal){
     printf("\ncannot open file press a key ");
     getch();
   }
   fbook=fopen("E:bokfile.dat","r+b");
   if(!fbook){
     printf("\ncannot open file press a key ");
     getch();
   }
   
   fmember=fopen("E:mmberfile.dat","r+b");
   if(!fmember){
     printf("\ncannot open file press a key ");
     getch();
   }
     fread(count_borrowed_book,sizeof(int),1,ftotal) ;
    fread(count_person,sizeof(int),1,ftotal) ;
   for(i=0;i<500;i++){
     fread(&b[i],sizeof(struct book),1,fbook);
     }
     for(j=0;j<100;j++){
       fread(&p[j],sizeof(struct person),1,fmember);
     }
     fclose(fbook);
     fclose(fmember);
 }
void save(int *count_person,int *count_borrowed_book)
{
FILE *fbook,*fmember,*ftotal;
   register int i,j;
   ftotal=fopen("E:total.dat","w+b");
   if(!ftotal){
     printf("\ncannot open file press a key ");
     getch();
   }
   fbook=fopen("E:bokfile.dat","w+b");
   if(!fbook){
     printf("\ncannot open file press any key to continue...");
     getch();
   }
   fmember=fopen("E:mmberfile.dat","w+b");
      if(!fmember){
     printf("\ncannot open file press any key to continue...");
     getch();
   }
   fwrite(count_borrowed_book,sizeof(int),1,ftotal) ;
    fwrite(count_person,sizeof(int),1,ftotal) ;
   for(i=0;i<500;i++){
     if(b[i].name[0])
     fwrite(&b[i],sizeof(struct book),1,fbook);
     }
     for(j=0;j<100;j++){
       if(p[j].name[0])
       fwrite(&p[j],sizeof(struct person),1,fmember);
       }
	    fclose(ftotal);    
         fclose(fbook);
     fclose(fmember);
     
     printf("\ninformations have saved!!!!");
     printf("\nplease wait 5 seconds");
sleep(5); 
system("cls");

}	

int main()
{
int count_borrowed_book=0;
int count_person=0;	
int i,j,choice;
free_book();
free_person();
load_file(&count_person,&count_borrowed_book);
for( ;	; )
{
show(&count_person,&count_borrowed_book);//show time & date & total borrowedbooks & total members 
show_menu();
printf("\nplease choose (1-9):");
scanf("%d",&choice);
switch(choice)
{
case 1:
add_new_member(&count_person);
break;
case 2:
add_new_book();
break;
case 3:
borrow_book(&count_borrowed_book);
break;
case 4:
show_borrowed_book();
break;
case 5:
give_back_book(&count_borrowed_book);
break;
case 6:
show_memberships();
break;
case 7:
show_all_books();
break;
case 8:
save(&count_person,&count_borrowed_book);
break;
case 9:
exit(0);
break;
default:
printf("\ninvalid choice!!!");
break;
}}
return 0;
}

