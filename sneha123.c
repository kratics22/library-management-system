#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

struct book 
{
    char title[50];
    char author[50];
    int id;
    char avbl;
}b;

// FUNCTION 1 TO ADD A BOOK TO THE LIBRARY 

void addBook() 
{
    FILE *fp;
    struct book b;

    fp = fopen("library.txt", "a+");
    system("cls");
    printf("Enter Book Title: ");
    scanf("%*c%[^\n]%*c",b.title);

    printf("Enter Book Author: ");
    scanf("%[^\n]",b.title);
    printf("Enter Book ID: ");
    scanf("%d%*c", &b.id);
    b.avbl='y';

    fwrite(&b, sizeof(struct book), 1, fp);
    fclose(fp);
}


// FUNCTION 2 TO SERARCH  BOOK

void searchbook() {
    FILE *fp;
    struct book b;
    int id, found = 0;

    fp = fopen("library.txt", "r+");
    system("cls");
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct book), 1, fp) == 1) {
        if (b.id == id) {
            printf("\nBook Id\t\tTitle\t\tAuthor\t\tAvability\n");
            printf("%d\t\t%s\t\t%s\t\t%c\n",b.id,b.title,b.author,b.avbl);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
    else{
        printf("Book found successfully\n");
    }

    fclose(fp);
}

// FUNCTION 3 TO  ISSUE BOOK

void issuebook(){
    FILE *fp;
    struct book b;
    int id,n=0;
    fp = fopen("library.txt", "r+");
    system("cls");
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(struct book), 1, fp) == 1)
    
        if (b.id == id && b.avbl == 'y'){
        
            b.avbl = 'n';
            n++;
        }
        
    
    fclose(fp);
    if (n == 1){
    
        printf("Book issued successfully.\n\n");
    }
    else{
    
        printf("book not issued");
    }

}

// FUNCTION 4 TO SUBMIT BOOK 

void submitbook(){
    int days;
    int fine;
    FILE *fp;
    struct book b;
    int id;
    
    fp = fopen("library.txt", "r+");
    system("cls");
    printf("Enter book ID: ");
    scanf("%d", &id);
    fine=(days-7)*2;
    while (fread(&b, sizeof(struct book), 1, fp) == 1)
    {
        if (b.id == id)
        {
            b.avbl = 'y';
        }
    }
    scanf("enter no of days",& days);
    fine=((days-7)*2);
    if(fine>0){
        printf("fine is equals to %d",fine);
    }
    else{
        printf("no fine is required");
    }
    printf("Book ID %d submitted successfully.\n\n", id);
}   

// FUNCTION 5 DELETE BOOK

void deletebook() {
    FILE *fp, *temp;
    struct book b;
    int id, found = 0;

    fp = fopen("library.txt", "r+");
    temp = fopen("temp.txt", "w+");
    system("cls");
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(struct book), 1, fp) == 1) {
        if (b.id != id) {
            fwrite(&b, sizeof(struct book), 1, temp);
        } 
        
        else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

// FUNCTION 6 TO LIST OF BOOKS

void listofbook() {
    FILE *fp;
    struct book b;
    int n=0;

    fp = fopen("library.txt", "r+");
 //   system("cls");
    while (fread(&b, sizeof(struct book), 1, fp) == 1) {
        printf("\nBook Id\t\tTitle\t\tAuthor\t\tAvability\n");
        printf("%d\t\t%s\t\t\t\t%s\t\t\t\t%c\n",b.id,b.title,b.author,b.avbl);


    }

    fclose(fp);
}

// MAIN PROGRAM

int main() {

    int p,x=10;
    while (x!=0)
    {
        printf("Enter The Password");
        scanf("%d",&p);
        if (p==123456)
        {
            printf("\t*Logined Successfully*\t\t\n");
            printf("\n\t\t*WELCOME!*\n");
            int choice;


            while (1) {
                system("cls");
                system("color 2");
               
                printf( "\n\t\t\t\t\tLibrary Management System\n\t\t\t\t\t=========================\n\t\t\t\t1. Add new book\t\t2. Search book\n\t\t\t\t3.Issue book\t\t4.Submit book\n\t\t\t\t5. Delete book\t\t6. List of books\t7. Exit\n\n\t\t\t\tEnter your choice: ");
                scanf("%d", &choice);

                system("cls");
                switch (choice) {
                    case 1:
                        addBook();
                        break;
                    case 2:
                        searchbook();
                        break;
                    case 3:
                        issuebook();
                        break;
                    case 4:
                        submitbook();
                        break;
                    case 5:
                        deletebook();
                        break;
                    case 6:
                        listofbook();
                        break;
                    case 7:
                        printf("\n\t\tTHANK YOU!");
                        exit(0);
                    default:
                        printf("Invalid choice.\n");
                }
            }
            x=0;

        }
        else
        {
            printf("wrong pasword try again");
        }
        printf("\n");
        
    }
    
    

    return 0;
}