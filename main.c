#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void insrt_book(book b)
{
    FILE *f1=fopen("Books.txt","a");
    printf("Enter the info of book\n");
    printf("Title:");gets(b.title);
    printf("Author:");gets(b.author);
    printf("Publisher:");gets(b.publisher);
    printf("ISBN:");gets(b.ibsn);
    printf("Date of publishing:");gets(b.dop);
    printf("Copies:");gets(b.copies);
    printf("Remaining Copies:");gets(b.remcopies);
    printf("Category:");gets(b.ctg);
    fprintf(f1,"%s,%s,%s,%s,%s,%s,%s,%s,\n,",b.title,b.author,b.publisher,b.ibsn,b.dop,b.copies,b.remcopies,b.ctg);
    fclose(f1);
}
void search_book_title(char a[50])
{
    FILE *f1=fopen("Books.txt","r+");
    char x[1000],y[100];
    x[0]='\0';
    fseek(f1,0,0);
    fscanf(f1,"%[^\,]",x);
    while(!feof(f1)){
        if(strncmp(x,a,strlen(a))==0){
               printf("Book info:\n");
               fseek(f1,-strlen(x),1);
               fscanf(f1,"%[^\,]",y);printf("Title: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Author: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Publisher: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("ISBN: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Date of publishing: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Copies: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Remaining Copies: %s\n",y);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",y);printf("Category: %s",y);fseek(f1,1,1);
               break;
        }
              x[0]='\0';
              fseek(f1,1,1);
              fscanf(f1,"%[^\,]",x);
  }
    if(strcmp(x,a)==1){
               printf("Book is not found ");
    }
    fclose(f1);
}
void search_book_isbn(char a[50])
{
    FILE *f1=fopen("Books.txt","r+");
    char x[1000],y[1000],z[100];
    x[0]='\0';
    y[0]='\0';
    fseek(f1,0,0);
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(strcmp(x,a)==0){
                int c=3+strlen(y);
               printf("Book info:\n");
               fseek(f1,-c,1);
               fscanf(f1,"%[^\,]",z);printf("Title: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Author: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Publisher: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("ISBN: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Date of publishing: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Copies: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Remaining Copies: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Category: %s",z);fseek(f1,1,1);
               break;
        }
              x[0]='\0';
              fseek(f1,1,1);
              fscanf(f1,"%[^\,]",x);
              strcat(y,x);
              if(x[0]=='\n'){y[0]='\0';}
  }
    if(strcmp(x,a)!=0){
               printf("Book is not found ");
    }
    fclose(f1);
}
void search_book_author(char a[50])
{
    FILE *f1=fopen("Books.txt","r+");
    char x[1000],y[1000],z[100];
    x[0]='\0';
    y[0]='\0';
    fseek(f1,0,0);
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(strcmp(x,a)==0){
                int c=1+strlen(y);
               printf("Book info:\n");
               fseek(f1,-c,1);
               fscanf(f1,"%[^\,]",z);printf("Title: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Author: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Publisher: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("ISBN: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Date of publishing: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Copies: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Remaining Copies: %s\n",z);fseek(f1,1,1);
               fscanf(f1,"%[^\,]",z);printf("Category: %s",z);fseek(f1,1,1);
               break;
        }
              x[0]='\0';
              fseek(f1,1,1);
              fscanf(f1,"%[^\,]",x);
              strcat(y,x);
              if(x[0]=='\n'){y[0]='\0';}
  }
    if(strcmp(x,a)!=0){
               printf("Book is not found ");
    }
    fclose(f1);
}
void search_book_ctg(char a[50])
{
    FILE *f1=fopen("Books.txt","r+");
    int i,counter=0;
    char x[1000],y[1000];
    char* z[1000];
    x[0]='\0';
    y[0]='\0';
    fseek(f1,0,0);
    fscanf(f1,"%[^\,]",x);
    strcat(y,x);
    while(!feof(f1)){
        if(strcmp(x,a)==0){
                int c=7+strlen(y);
                fseek(f1,-c,1);
                z[counter]=(char*)malloc(50);
                fscanf(f1,"%[^\,]",z[counter]);
                counter++;
        }
              x[0]='\0';
              fseek(f1,1,1);
              fscanf(f1,"%[^\,]",x);
              strcat(y,x);
              if(x[0]=='\n'){y[0]='\0';}
  }
  printf("Books in category (%s):\n",a);
  for(i=0 ; i<=counter ; i++){printf("%s\n",z[i]);}
    fclose(f1);
}
int main()
{
    ///FILE *f1=fopen("Books.txt","r+");
    ///book b1;
    ///insrt_book(b1);
    char a[50],b[50];
    gets(a);///gets(b);
    search_book_ctg(a);
    ///Add_new_copy(a,b);
    return 0;
}
