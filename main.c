#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char title[256];
    char author[128];
    char publisher[128];
    char isbn[18];
    char dop[11];
    int copies;
    int remCopies;
    char ctg[32];
    }book;

FILE* fpointer;

void insert_book();

int main()
{
    //book b1={"Programming","Ahmed","Eagle","1234567890123","11/09/2012",1000,500,"Computer science"};
    fpointer=fopen("C:\\Users\\Mido\\Desktop\\K\\Programming\\Labs\\3\\Files\\Library\\Books.txt","a+");
    insert_book();
    return 0;
}

void insert_book(){
    book b0;
    printf("Title:");gets(b0.title);
    printf("Author:");gets(b0.author);
    printf("Publisher:");gets(b0.publisher);
    printf("ISBN:");gets(b0.isbn);
    printf("Date of publication:");gets(b0.dop);
    printf("Category:");gets(b0.ctg);
    printf("#Copies:");scanf("%d *[^\n]",&b0.copies);
    printf("#RemainingCopies:");scanf("%d",&b0.remCopies);
    //char* test[10];
    //gets(test);
    //scanf("%s %s %s %s %s %d %d %s",b0.title,b0.author,b0.publisher,b0.isbn,b0.dop,&b0.copies,&b0.remCopies,b0.ctg);
    fprintf(fpointer,"%s,%s,%s,%s,%s,%d,%d,%s\n",b0.title,b0.author,b0.publisher,b0.isbn,b0.dop,b0.copies,b0.remCopies,b0.ctg);

}
