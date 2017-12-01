#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

FILE* f;

void insert_book();
void search(char*);

int main()
{
    /*int choice,pass,trials=0;
    while(1){
    printf("1.Book Management.\n2.Memeber Management.\n3.Administrator?\n4.Save and exit.");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("1.Insert a book.\n2.Search for a book.\n3.Add a copy.\n4.Delete book.\n5.Back to menu.\n");
            scanf("%d",&choice);
            break;
        case 2:
            printf("1.Register.\n2.Borrow.\n3.Back to menu.\n");
            scanf("%d",&choice);
            choice+=5;
            break;
        case 3:
            printf("Password(1234):");
            scanf("%d",&pass);
            while(pass!=1234){
                printf("Incorrect.\nPassword(1234):");
                trials++;
                if(trials==3){
                    trials=0;
                    break;
                }
            }
            printf("1.Overdue books.\n2.Most popular books.\n3.Back to menu.");
            scanf("%d",&choice);
            choice+=8;
            break;
    }
    if(choice==5||choice==8||choice==11){
        continue;
    }
    }*/
    f=fopen("DB\\Books.txt","a+");
    char kstr[128]="olit";
    search(kstr);

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
    printf("#Copies:");scanf("%d",&b0.copies);
    printf("#RemainingCopies:");scanf("%d",&b0.remCopies);
    fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%s\n",b0.title,b0.author,b0.publisher,b0.isbn,b0.dop,b0.copies,b0.remCopies,b0.ctg);

}

void search(char* kstr){
    int i,i2,check=0;
    char temp[1024];
    while(fgets(temp,1024,f)!= NULL){
        for(i=0;i<strlen(temp);i++){
            if(temp[i]==kstr[0]){
                for(i2=1;i2<strlen(kstr);i2++){
                    if(temp[i+i2]==kstr[i2]){
                        check++;
                    }
                }
            }
            if(check==strlen(kstr)-1){
                    printf("%s",temp);
                    check=0;
                }
        }
    }
}

