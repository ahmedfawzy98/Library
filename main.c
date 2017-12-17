#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
typedef struct{
    char title[200];
    char author[200];
    char publisher[200];
    char ibsn[50];
    char dop[50];
    char copies[50];
    char remcopies[50];
    char ctg[100];
}book;
typedef struct{
    int d;
    int m;
    int y;
}date;
typedef struct{
    char isbn[50];
    char userID[50];
    date di;
    date dd;
    date dr;
}borrow;
typedef struct{
    char bnum[50];
    char zone[50];
    char city[50];
}address;
typedef struct{
    char fname[50];
    char lname[50];
    char id[50];
    address adrs;
    char phonenum[50];
    char age[100];
    char email[100];
}member;
FILE*f1;
date add_day(date date1,int n){
    date dd;
    time_t now = time(0);
    struct tm now_tm = *localtime( &now);

    now_tm.tm_mday += n;   // add 50 seconds to the time
    mktime( &now_tm);
    dd.d= now_tm.tm_mday;
    dd.m= now_tm.tm_mon +1;
    dd.y= now_tm.tm_year +1900;
    //printf( "%s\n", asctime( &now_tm));
    return dd;
}
date get_date(){
    time_t rawtime;
    struct tm * timeinfo;
    date md;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    md.d = timeinfo->tm_mday;
    md.m = timeinfo->tm_mon + 1;
    md.y = timeinfo->tm_year +1900;
    return md;
}
void insrt_book()
{
    book b;
    f1=fopen("Bookst.txt","a");
    printf("Enter the info of book\n");
    printf("Title:");gets(b.title);
    printf("Author:");gets(b.author);
    printf("Publisher:");gets(b.publisher);
    printf("ISBN:");gets(b.ibsn);int v=search_book_isbn(b.ibsn,2);if(v==1){printf("This book is already exist\n");bookMgmt();}
    printf("Date of publishing:");gets(b.dop);
    printf("Copies:");gets(b.copies);
    printf("Remaining Copies:");gets(b.remcopies);
    printf("Category:");gets(b.ctg);
    fprintf(f1,"%s,%s,%s,%s,%s,%s,%s,%s\n",b.title,b.author,b.publisher,b.ibsn,b.dop,b.copies,b.remcopies,b.ctg);
    fclose(f1);
}
void search_book_title(char a[50])
{
    f1=fopen("Bookst.txt","r+");
    int i,counter=0,b=0;
    char x[1000],y[100];x[0]='\0';
    char z[1000],r[1000][100];
    fscanf(f1,"%[^\,]",x);
    while(!feof(f1)){
        if(strnicmp(x,a,strlen(a))==0){strcpy(r[counter],x);counter++;}
              fgets(x,1000,f1);
              fscanf(f1,"%[^\,]",x);
  }
    if(!counter){
               printf("Book is not found ");
    }
    else{
        printf("Books with this title (%s):\n",a);
        for(i=0;i<counter;i++){printf("%s\n",r[i]);}}

    fclose(f1);
}
int search_book_isbn(char a[50],int b)
{
    if(strlen(a)==13){
    f1=fopen("Bookst.txt","r+");
    int d=0,co=0;
    char x[1000],y[1000];
    x[0]='\0';
    y[0]='\0';
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(stricmp(x,a)==0){
               if(b==1||b==2||b==3){return 1;}
               int c=3+strlen(y);
               printf("Book info:\n");d=1;
               fseek(f1,-c,1);y[0]='\0';
               fscanf(f1,"%[^\,]",y);printf("Title: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Author: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Publisher: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("ISBN: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Date of publishing: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Copies: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Remaining Copies: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\n]",y);printf("Category: %s\n",y);
               fclose(f1);
               return;
        }
              fseek(f1,1,1);co++;if(co==7){fscanf(f1,"%[^\n]",x);strcat(y,x);fseek(f1,1,1);y[0]='\0';co=-1;}
              else{fscanf(f1,"%[^\,]",x);strcat(y,x);}
  }
    if(!d){
               printf("Book is not found\n");
               fclose(f1);
               return;
    }
  }
  else{printf("Invalid ISBN\n");bookMgmt();}
}
void search_book_author(char a[50])
{
    f1=fopen("Bookst.txt","r+");
    char x[1000],y[1000],z[1000],r[1000][100];x[0]='\0';y[0]='\0';
    int i,counter=0,co=0;
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        fseek(f1,1,1);co++;
        if(strnicmp(x,a,strlen(a))==0){
                int c=2+strlen(y);
                fseek(f1,-c,1);
                fscanf(f1,"%[^\,]",z);
                strcpy(r[counter],z);counter++;
                fgets(x,1000,f1);y[0]='\0';co=0;
        }
              else if(co==2){fgets(x,1000,f1);y[0]='\0';co=0;}
              fscanf(f1,"%[^\,]",x);strcat(y,x);
  }
    if(!counter){
               printf("Book is not found ");
    }
    else{
        printf("Books by author (%s):\n",a);
  for(i=0;i<counter;i++){printf("%s\n",r[i]);}}

    fclose(f1);
}
void search_book_ctg(char a[50])
{
    f1=fopen("Bookst.txt","r+");
    int i,c=0,b=0,counter=0,co=0;
    char x[1000],y[1000],z[1000],r[1000][100];///lazm nezabt el arkam beta3t kol el functions m3 ba3d
    x[0]='\0';y[0]='\0';
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(stricmp(x,a)==0){
                c=7+strlen(y);
                fseek(f1,-c,1);
                fscanf(f1,"%[^\,]",z);
                strcpy(r[counter],z);counter++;
                fgets(x,1000,f1);y[0]='\0';co=0;

        }
              else{fgetc(f1);co++;}
              if(co==8){co=0;y[0]='\0';}
              if(co==7){fscanf(f1,"%[^\n]",x);strcat(y,x);}
              else{fscanf(f1,"%[^\,]",x);strcat(y,x);}
  }
  if(!counter){printf("there is not books in this category\n");}
  else{
  printf("Books in category (%s):\n",a);
  for(i=0;i<counter;i++){printf("%s\n",r[i]);}}
    fclose(f1);
}
void search_member_id(char a[50])
{
    if(strlen(a)==5){
    f1=fopen("Memberst.txt","r+");
    int d=0,co=0;
    char x[1000],y[1000];x[0]='\0';y[0]='\0';
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(stricmp(x,a)==0){printf("This user is already exist\n");membertrn();}
              fseek(f1,1,1);co++;if(co==8){fscanf(f1,"%[^\n]",x);strcat(y,x);fseek(f1,1,1);y[0]='\0';co=-1;}
              else{fscanf(f1,"%[^\,]",x);strcat(y,x);}
    }
  }
    else{printf("Invalid ID\n");membertrn();}
}
void Add_new_copy(char a[50],char b[50], int c)
{
    f1=fopen("Bookst.txt","r+");
    int i,d,m=0,co=0;
    char x[1000],y[1000],h[50];
    strcpy(h,b);
    x[0]='\0';
    y[0]='\0';
    fscanf(f1,"%[^\,]",x);
    while(!feof(f1)){
        if(stricmp(x,a)==0){
                d=1;
                for(i=1;i<=2;i++){
                    fseek(f1,1,1);
                    fscanf(f1,"%[^\,]",x);
                    fseek(f1,1,1);}
                fscanf(f1,"%[^\,]",x);
                fseek(f1,-strlen(x),1);
                if(c==-1){h[0]='\0';m=atoi(x);m--;itoa(m,h,10);}
                if(c==1){h[0]='\0';m=atoi(x);m++;itoa(m,h,10);}
                if(strlen(h)>4){printf("Error!");break;}
                else if(strlen(h)==1){fprintf(f1,"000%s",h);}
                else if(strlen(h)==2){fprintf(f1,"00%s",h);}
                else if(strlen(h)==3){fprintf(f1,"0%s",h);}
                else{fprintf(f1,"%s",h);}
                printf("Copies are updated\n");
                break;
        }
              fseek(f1,1,1);co++;if(co==4){fgets(x,1000,f1);y[0]='\0';co=0;}
              fscanf(f1,"%[^\,]",x);strcat(y,x);
    }


    if(d!=1){
               printf("Book is not found\n");
    }
    fclose(f1);

}

void delete_book(char a[50])
{
    f1=fopen("Bookst.txt","r");
    FILE *f2=fopen("Test.txt","w");
    char x[1000];
    int y;
    if(strlen(a)!=13){fclose(f2);remove("Test.txt");printf("ISBN Error!");return;}
    while(fgets(x,1000,f1)!=NULL){
        if(strstr(x,a)!=NULL){y=1;continue;}
        else{fprintf(f2,"%s",x);}
        }
        if(y!=1){
                fclose(f1);fclose(f2);remove("Test.txt");
                printf("Book is not found\n");
        }
        else{
            fclose(f1);fclose(f2);
            int d=remove("Bookst.txt");
            int r=rename("Test.txt","Bookst.txt");
            if(d==0&&r==0){printf("Book is deleted\n");}
        }
}
void Borrow_book()///lazm nehandlha bel main function n5aleh ye search w ba3deen ya5d el isbn w ykml borrowing
{
    borrow a; date b,c;
    printf("Enter ISBN:");scanf("%s",a.isbn);
    printf("Enter ID:");scanf("%s",a.userID);
    b=get_date();
    a.di.d = b.d;a.di.m = b.m;a.di.y = b.y;
    c=add_day(b,7);
    a.dd.d = c.d;a.dd.m = c.m;a.dd.y = c.y;
    FILE *f3=fopen("borrow.txt","a");
    int v=search_book_isbn(a.isbn,1);
    if(v==1){///n7t hena printf n2ol if v!=1 yeb2a el book borrowed asla wla eih?
        fprintf(f3,"%s,%s,%d%/%d/%d,%d/%d/%d,%d/%d/%d\n",a.isbn,a.userID,a.di.d,a.di.m,a.di.y,
                a.dd.d,a.dd.m,a.dd.y);
        Add_new_copy(a.isbn," ",-1);
        printf("Book is borrowed\n");
    }
    fclose(f3);
}
void return_book(char a[50])
{
    FILE *f1=fopen("borrow.txt","r");
    FILE *f2=fopen("return.txt","w");
    char x[1000];
    int y;
    while(fgets(x,1000,f1)!=NULL){
        if(strstr(x,a)!=NULL){y=1;continue;}
        else{fprintf(f2,"%s",x);}
        }
        if(y!=1){
                fclose(f1);fclose(f2);remove("return.txt");
                printf("Book is not found");
        }
        else{
            fclose(f1);fclose(f2);
            int d=remove("borrow.txt");
            int r=rename("return.txt","borrow.txt");
            if(d==0&&r==0){printf("Book is returned.\n");}
            Add_new_copy(a," ",1);
        }
}
void insrt_member()
{
    member m;
    FILE *f1=fopen("Memberst.txt","a");
    printf("Enter member's info\n");
    printf("first name:");gets(m.fname);
    printf("last name:");gets(m.lname);
    printf("Age:");gets(m.age);
    printf("ID:");gets(m.id);search_member_id(m.id);
    printf("building number:");gets(m.adrs.bnum);
    printf("zone:");gets(m.adrs.zone);
    printf("City:");gets(m.adrs.city);
    printf("phone number:");gets(m.phonenum);
    printf("Email:");gets(m.email);
    fprintf(f1,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",m.lname,m.fname,m.id,m.adrs.bnum,m.adrs.zone,m.adrs.city,m.phonenum,m.age,m.email);
    fclose(f1);
}
void delete_member(char a[50])
{
    FILE *f1=fopen("Memberst.txt","r");
    FILE *f2=fopen("Test.txt","w");
    char x[1000];
    int y;
    if(strlen(a)!=5){fclose(f2);remove("Test.txt");printf("ID Error!\n");return;}
    while(fgets(x,1000,f1)!=NULL){
        if(strstr(x,a)!=NULL){y=1;continue;}
        else{fprintf(f2,"%s",x);}
        }
        if(y!=1){
                fclose(f1);fclose(f2);remove("Test.txt");
                printf("Member is not found\n");
        }
        else{
            fclose(f1);fclose(f2);
            int d=remove("Memberst.txt");
            int r=rename("Test.txt","Memberst.txt");
            if(d==0&&r==0){printf("Member is deleted\n");}
        }
}

void gb(int n){
   if (n==1){
        clrscr2();
        bookMgmt();
   }
}
void clrscr2(){
    system("@cls||clear");
}
void addcpy(){

}
void bookMgmt(){
     char a[50],b[50];
    printf("****************************************\n");
    printf("**          Book Management           **\n");
    printf("****************************************\n\n");
    printf("|| 1. Insert book\n|| 2. Search book\n|| 3. Add new copy\n|| 4. Delete\n|| 5. Main Menu\n");
    int c;
    scanf("%d",&c);
    if(c ==0){return;};
    switch(c){

        case 1:
            clrscr2();
            getc(stdin);
            insrt_book();
        case 2:

            clrscr2();
            bbsearch();
        case 3:

            clrscr2();
            printf("Enter ISBN of the book:");scanf("%s",a);
            printf("enter the new number of copies:");scanf("%s",b);
            Add_new_copy(a,b,0);
            bookMgmt();
        case 4:
            clrscr2();
            printf("Enter ISBN of the book:");scanf("%s",a);
            delete_book(a);
            bookMgmt();
        case 5:
            clrscr2();
            main();
            break;
    }

}
void bbsearch(){
    char a[50];
    printf("****************************************\n");
    printf("**            Search Book             **\n");
    printf("****************************************\n");
    printf("|| 1. Search by ISBN\n|| 2. Search by Title\n|| 3. Search by Category\n|| 4. Search by Author\n|| 5. Back\n|| 6. Main Menu\n");
    int c;
    scanf("%d",&c);getc(stdin);
    if(c ==0){return;};
    switch(c){

        case 1:
            clrscr2();
            printf("Enter the ISBN of the book:");gets(a);
            search_book_isbn(a,0);
            bbsearch();
        case 2:
            clrscr2();
            printf("Enter the title (or part of it) of the book:");gets(a);
            search_book_title(a);
            bbsearch();
        case 3:
            clrscr2();
            printf("Enter the category of the book:");gets(a);
            search_book_ctg(a);
            bbsearch();
        case 4:
            clrscr2();
            printf("Enter author's name:");gets(a);
            search_book_author(a);
            bbsearch();
        case 5:
            gb(1);
        case 6:
            clrscr2();
            main();
    }
}
void membertrn(){
    printf("*****************************************\n");
    printf("**         Member Transactions         **\n");
    printf("***************************************\n\n");
    printf("|| 1. Register\n|| 2. Borrow\n|| 3. Return\n|| 4. Remove Member\n|| 5. Main Menu\n");
    int c;char a[50];
    scanf("%d",&c);getc(stdin);
    if(c ==0){return;};
    switch(c){
        case 1:
            clrscr2();
            insrt_member();
            membertrn();
        case 2:
            clrscr2();
            Borrow_book();
            membertrn();
        case 3:
            clrscr2();
            printf("Enter the ISBN of the book:");gets(a);
            return_book(a);
            membertrn();
        case 4:
            clrscr2();
             printf("Enter the ID of member:");gets(a);
             delete_member(a);
            membertrn();
        case 5:
            clrscr2();
            main();
    }
}
void copyfile(char *source,char *destination)
{
    FILE*f8=fopen(source,"r");
    FILE*f9=fopen(destination,"w");
    char x[1000];
    while(!feof(f8)){
             fgets(x,1000,f8);
             fprintf(f9,"%s",x);x[0]='\0';
        }
    fclose(f8);fclose(f9);
}
int main()
{
    copyfile("Books.txt","Bookst.txt");
    copyfile("Members.txt","Memberst.txt");
    copyfile("borrow.txt","borrowt.txt");
    int c=0;
    printf("        ****************************************\n");
    printf("        ||          Library System            ||\n");
    printf("        ****************************************\n");
    printf("Main Menu \n\n");
    printf("|| 1. Book Management\n|| 2. Member Transactions\n|| 3. Administrative Actions\n|| 4. Save\n|| 5. Save and exit\n|| 6. Exit without saving\n");
    scanf("%d",&c);
    if(c ==0){return;};///printf("Thank you\n"); ????
    switch(c){
        case 1:
            clrscr2();
            bookMgmt();
        case 2:
            clrscr2();
            membertrn();
        case 3:
       //     admin();
        case 4:
       //     save();
        case 5:
        //    exit_save();
        case 6:;
          //  exit_no_save();
        //case else:
         //   printf("Invalid choice!");
    }
    ///return 0;
}
