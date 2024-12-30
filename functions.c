#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//logic ham
void printMenu(){
	system("cls");
	printf("***QUAN LY THU VIEN***\n");
	printf("\n");
	printf("\t-Menu-\n");
	printf("1.Nhap so luong va thong tin sach\n");
	printf("2.Hien thi sach\n");
	printf("3.Them sach\n");
	printf("4.Sua thong tin sach\n") ;
	printf("5.Xoa sach\n");
	printf("6.Tim kiem sach theo ten \n");
	printf("7.Sap xep theo gia tien\n");
	printf("8.Thoat\n");
} 
void format(char *name){
	size_t len=strlen(name);
	int newword=1;
	int i;
	for(i=0;i<len;i++){
		if(isspace(*(name+i))){
			newword=1;
		}
		else if(newword==1){
			*(name+i)=toupper(*(name+i));
			newword=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}

void libraryInput(struct Book **book,int *n){
	system("cls");
	if(*book!=NULL){
		free(*book);
	}
	
	printf("Enter the number of books :");
	scanf("%d",n);
	if(*n<1){
		printf("Invalid number of book !\n");
		exit(1);
	}
	getchar();
	*book=(struct Book*)malloc(*n*sizeof(struct Book));
	if(*book==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	int i;
	for (i=0;i<*n;i++){
		printf("Enter book %d-N:\n",i+1);
		printf("Enter book ID: ");
		scanf("%d", &(*book)[i].bookId);
		getchar(); 
		printf("Enter title book :");
		fgets((*book)[i].title,30,stdin);
		(*book)[i].title[strcspn((*book)[i].title,"\n")]='\0';
		format((*book)[i].title);
		printf("Enter price book:");
		scanf("%d",&(*book)[i].price);
		getchar();
		printf("Enter author book:");
		fgets((*book)[i].author,30,stdin);
		(*book)[i].author[strcspn((*book)[i].author,"\n")]='\0';
		format((*book)[i].author);
		printf("Enter publication date (dd mm yyyy): ");
        scanf("%d %d %d", &(*book)[i].publication.day, &(*book)[i].publication.month, &(*book)[i].publication.year);
		getchar();
		printf("\n");
		
	}
	
}

void showLibrary(struct Book *book, int n) {
	system("cls");
    printf("--------LIBRARY--------\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("| Book ID    | Title                        | Price           | Author                       | Publication Date    |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("| %-10d | %-28s | %-15d | %-28s | %02d/%02d/%04d          |\n", 
               book[i].bookId, 
               book[i].title, 
               book[i].price, 
               book[i].author,
               book[i].publication.day, 
               book[i].publication.month, 
               book[i].publication.year);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }
}

void updateBook(struct Book *book,int n){
	system("cls");   
	int flag=0;
	int i;
	int bookId;
	do{
	printf("Enter the ID of book:",n);
	scanf("%d",&bookId);
	getchar();
	flag=0;
	for(i=0;i<n;i++){
		if(book[i].bookId==bookId){
			flag=1;	
			printf("Update book:\n");
			printf("Update title of book :");
			fgets(book[i].title,30,stdin);
			book[i].title[strcspn(book[i].title,"\n")]='\0';
			format(book[i].title);
			printf("Enter price of book:");
			scanf("%d",&book[i].price);
			getchar();
			printf("Enter author book:");
			fgets(book[i].author,30,stdin);
			book[i].author[strcspn(book[i].author,"\n")]='\0';
			format(book[i].author);
			printf("Update book successfully!\n");
			break;
		}
	}
	if(flag==0){
		printf("This book does not exist!\n");
	}
	} while (flag==0);
}


