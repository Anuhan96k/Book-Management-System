//A Book Management System is required to efficiently organize and manage information about books. 
//The system should support various operations, including adding, removing, searching, updating, and 
//displaying book records based on attributes such as Book ID, Book Name, Author Name, Category, Price, and Rating.
// Additionally, the system should provide the capability to show details of books written by a specific author, display the
// top 3 books based on price and rating, and access information about all the books in the database.
//Key Requirements:
//////•Add Book: The system should allow users to add new books with their attributes, including Book ID, Book Name, Author Name, Price, and Rating.

/////•Remove Book: Users should be able to remove books from the system, ensuring that associated data is deleted 
//while preserving data integrity. (by id)

//////•Search Book: The system should facilitate book retrieval by both Book ID and Book Name, enabling users to quickly access book details.

//////•Show Author's Books: Users should be able to retrieve a list of books written by a specific author, helping readers explore an author's works.

/////•Show Category's Books: Users should be able to retrieve a list of books of specified category, helping readers explore an author's works.

/////•Update Book Data: Users must have the ability to update a book's Price and Rating, providing a means for keeping book information accurate and up-to-date.

/////•Display Sorted Books: The system should provide a feature to display the sorted books based on price and rating, allowing users to see the highest/lowest- priced and highest/lowest- rated books in the collection.

/////•Display All Books: The system should offer the option to display details of all the books in the database, enabling users to access the complete list of books.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book {
    int bid;
    char bname[50];
    char aname[50];
    char category[50];
    float price;
    int rating;
} Book;

void display(Book*, int);
void store(Book*, int);
Book* add(Book*, int*);
int searchBook(Book*, int);
int searchByName(Book*, int,char *);
void showByAname(Book*, int);
int updateBookData(Book*, int);
int searchById(Book*, int);
void showByCategory(Book*, int);
void DisplaySortedBooks(Book*, int);
void sortByHighestPrice(Book*, int);
void sortByHighestRating(Book*, int);
void removeBook(Book*, int*);
void displayTopThree(Book *,int );


int main() 
{
    int s = 4;
    
    Book *b = (Book*)malloc(sizeof(Book) * s);
    
    if (b == NULL) 
	{
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    store(b, s);//hardcoded

    int choice;
    do {
        printf("\n\n********** Book Management System **********\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Show Author's Books\n");
        printf("5. Show Category's Books\n");
        printf("6. Update Book Data\n");
        printf("7. Display Sorted Books\n");
        printf("8. Display All Books\n");
        printf("9.Display Top3 Books\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after input

        switch (choice) 
		{
            case 1:
                b = add(b, &s);
                break;
            case 2:
                removeBook(b, &s);
                break;
            case 3: {
                int p = searchBook(b, s);
                if (p != -1) {
                    printf("\n..............* Book Details *.................\n");
                    printf("-----------------------------------------\n");
                    printf("Book id: %d\n", b[p].bid);
                    printf("Book name: %s\n", b[p].bname);
                    printf("Book author: %s\n", b[p].aname);
                    printf("Book price: %.2f\n", b[p].price);
                    printf("Book category: %s\n", b[p].category);
                    printf("Book rating: %d\n", b[p].rating);
                    printf("------------------------------------------\n");
                } else {
                    printf("\nBook Not Found!");
                }
                break;
            }
            case 4:
                showByAname(b, s);
                break;
            case 5:
                showByCategory(b, s);
                break;
            case 6:
                updateBookData(b, s);
                break;
            case 7:
                DisplaySortedBooks(b, s);
                break;
            case 8:
                display(b, s);
                break;
            case 9:
            	 displayTopThree(b,s);
            	 break;
            case 10:
                printf("Exiting the program...\n");
                break;
          
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

    free(b);
    return 0;
}


void store(Book *b, int n) 
{
    b[0].bid = 1;
    strcpy(b[0].bname, "Can't Hurt Me");
    strcpy(b[0].aname, "David Goggins");
    strcpy(b[0].category, "motivational");
    b[0].price = 5000;
    b[0].rating = 1;

    b[1].bid = 2;
    strcpy(b[1].bname, "OnePiece");
    strcpy(b[1].aname, "Eichiro Oda");
    strcpy(b[1].category, "Manga");
    b[1].price = 2000;
    b[1].rating = 5;
    
    b[2].bid = 3;
    strcpy(b[2].bname, "42 Rules of Life");
    strcpy(b[2].aname, "Jordan Peterson");
    strcpy(b[2].category, "Motivational");
    b[2].price = 11240;
    b[2].rating = 1;
    
      b[3].bid = 4;
    strcpy(b[3].bname, " Hurt Me");
    strcpy(b[3].aname, "David Goggins");
    strcpy(b[3].category, "motivational");
    b[3].price = 5000;
    b[3].rating = 1;

}

Book* add(Book *b, int *s)
{
    int n;
    printf("Enter how many books you want to add: ");
    scanf("%d", &n);
     
    b = (Book*)realloc(b, sizeof(Book) * (*s + n));
    
    if (b == NULL) 
	{
        printf("Memory allocation failed.\n");
        exit(1);
    }
	int i;
    for ( i = *s; i < *s + n; i++) 
	{
        printf("Enter book id: ");
        scanf("%d", &b[i].bid);
        printf("Enter book name: ");
        scanf("%s", b[i].bname);
        printf("Enter book author: ");
        scanf("%s", b[i].aname);
        printf("Enter book price: ");
        scanf("%f", &b[i].price);
        getchar();
        printf("Enter category of book: ");
        scanf("%s", b[i].category);
        printf("Enter book rating (from 1 to 5): ");
        scanf("%d", &b[i].rating);
        
    }
    *s += n;
    return b;
}

void display(Book* b, int s)
{
	int i;
    for ( i = 0; i < s; i++)
	{
        printf("\n..............* Book Details *.................\n");
        printf("-----------------------------------------\n");
        printf("Book id: %d\n", b[i].bid);
        printf("Book name: %s\n", b[i].bname);
        printf("Book author: %s\n", b[i].aname);
        printf("Book price: %.2f\n", b[i].price);
        printf("Book category: %s\n", b[i].category);
        printf("Book rating: %d\n", b[i].rating);
        printf("------------------------------------------\n");
    }
}

int searchById(Book *b ,int s)
{
	int id;
        printf("Enter Book ID: ");
        scanf("%d", &id);
        int i;
        int found=0;
        for ( i = 0; i < s; i++)
		{
			
	        if (b[i].bid == id)
			 {
			 	found=1;
	             return i;
	             
	         }
        }     
		if(found!=1)
		{
			printf("\nBook Not Found");
		} 
}

int searchByName(Book *b,int s,char*name)
{
	 
        int i;
       int found=0;
        for ( i = 0; i < s; i++) 
		{	 
            if (strcasecmp(name, b[i].bname) == 0) 
			{
				found=1;
				return i;
            }
        }
        if(found!=1)
        {
        	return -1;
		}
}

int searchBook(Book *b, int s)
{
    int ch;
    printf("1. To search book by ID\n2. To search book by name\n");
    scanf("%d", &ch);
	fflush(stdin);   
    if (ch == 1) 
	{
        return searchById(b,s);
        
    }
	else if (ch == 2) 
	{
		char name[20];
        printf("Enter name of book: ");
		gets(name);
		       
	   return searchByName(b,s,name);
    } 
	else 
	{
        printf("Invalid choice\n"); 
        return -1;
    }
}


void showByAname(Book *b, int s)
{
    char aname[50];
    int count = 0;
    printf("Enter author name of book: ");
	gets(aname);
//    fflush(stdin);
    int i;
    	 
    for ( i = 0; i < s; i++) 
	{
        if (strcasecmp(aname, b[i].aname) == 0)
		{
            count = 1;
            printf("\n---------------------------------------------\n");
            printf("Book id: %d\n", b[i].bid);
            printf("Book name: %s\n",b[i].bname);
            printf("\n---------------------------------------------\n");
        }
       
    }
    if (count != 1)
	{
        printf("Book not found for entered author name: %s\n", aname);
    }
}

int updateBookData(Book *b,int s)
{
	 int ch;
    printf("1. To update book by ID\n2. To update book by name\n");
    scanf("%d", &ch);
    getchar();
    if (ch == 1) 
	{
       	int p= searchById(b,s );
		  if(p!=-1)
		  {
		  	 printf("\n..............* Book Details *.................\n");
		        printf("-----------------------------------------\n");
		        printf("Book id: %d\n", b[p].bid);
		        printf("Book name: %s\n", b[p].bname);
		        printf("Book author: %s\n", b[p].aname);
		        printf("Book price: %.2f\n", b[p].price);
		        printf("Book category: %s\n", b[p].category);
		        printf("Book rating: %d\n", b[p].rating);
		        printf("------------------------------------------\n");
		        
		        
		        printf("Enter New Price to Update:");
		        scanf("%f",&b[p].price);
		         
				printf("Enter New Rating to Update:");
		        scanf("%d",&b[p].rating);
		        
				 printf("\nNew Price and Ratings are updated...");

		        
		  }
		  else
		  {
		  	printf("\nBook Not Found!\nEnter valid Book ID");
		  }
	}
	 else if (ch == 2) //wrong
	 {
	 	char name[50];
	 	printf("Enter Book Name:");
	 	gets(name);
	 	
	   	int p= searchByName(b,s,name);
		  if(p!=-1)
		  {
		  	 printf("\n..............* Book Details *.................\n");
		        printf("-----------------------------------------\n");
		        printf("Book id: %d\n", b[p].bid);
		        printf("Book name: %s\n", b[p].bname);
		        printf("Book author: %s\n", b[p].aname);
		        printf("Book price: %.2f\n", b[p].price);
		        printf("Book category: %s\n", b[p].category);
		        printf("Book rating: %d\n", b[p].rating);
		        printf("------------------------------------------\n");
		        
		        
		        printf("Enter New Price to Update:");
		        scanf("%f",&b[p].price);
		         
				printf("Enter New Rating to Update:");
		        scanf("%d",&b[p].rating);
		         printf("\nNew Price and Ratings are updated...");
   		 } 
   	}
	else
	 {
        printf("Invalid choice\n");
        
        
    }

}

void showByCategory(Book *b,int s)
{
	char category[20];
	printf("\nenter category of Book:");
	scanf("%s",&category);
	int found=0,sno=1;
	int i;
	for(i=0;i<s;i++)
	{
		if(strcasecmp(category,b[i].category)==0)
		{
			found=1;
			printf("\n%d]\tBook ID:%d",sno,b[i].bid);
			printf("\n\tBook Name:%s\n",b[i].bname);

			
		}
	}
	if(found!=1)
	{
		printf("Entered Category Books Not Found !");
	}
   
}


void sortByHighestPrice(Book* b, int s)
{
    int i, j;
    for (i = 0; i < s - 1; i++)
	{
        for (j = 0; j < s - i - 1; j++)
		 {
            if (b[j].price < b[j + 1].price) 
			{
                // Swap the books
                Book temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    
}
void sortByHighestRating(Book *b,int s)
{
	int i,j;
	Book temp;
	for(i=0;i<s-1;i++)
	{
		for(j=0;j<s-i-1;j++)
		{
			if(b[j].rating<b[j+1].rating)
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
		
	}
}



void DisplaySortedBooks(Book*b,int s)
{
	int choice;
	printf("\nEnter 1 to sort by price(highest to lowest)\nEnter 2 to sort by rating (highest to lowest)");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		sortByHighestPrice(b,s);
		printf("\nBooks Are sorted as per your request...");
		display(b,s);
		
	}
	else if(choice==2)
	{
		sortByHighestRating(b,s);
		printf("\nBooks Are sorted as per your request...");
		display(b,s);
	}
		
}

void removeBook(Book *b, int *s) 
{
    int id;
    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    int i, j;
    int found = 0;
    
    for (i = 0; i < *s; i++) 
	{
        if (b[i].bid == id)
		{
            found = 1;
            // Shift books to remove the target book
            
            for (j = i; j < *s - 1; j++)
			{
                b[j] = b[j + 1];
            }
            // Decrease the size of the array
            *s -= 1;

            printf("Book with ID %d removed successfully.\n", id);
            break;
        }
    }
    
    if (found!=1)
	{
        printf("No book found with ID %d.\n", id);
    }
}

void displayTopThree(Book *b,int s)
{
	int choice;
	printf("\nEnter 1 to display top 3 by price(highest to lowest)\nEnter 2 to display top 3 by rating(highest to lowest):");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		sortByHighestPrice(b,s);
		printf("\nBooks Are sorted as per your request...");
		int i;
	    for(i=0;i<3;i++)
	    {
	    	 printf("\n..............* Book Details *.................\n");
		        printf("-----------------------------------------\n");
		        printf("Book id: %d\n", b[i].bid);
		        printf("Book name: %s\n", b[i].bname);
		        printf("Book author: %s\n", b[i].aname);
		        printf("Book price: %.2f\n", b[i].price);
		        printf("Book category: %s\n", b[i].category);
		        printf("Book rating: %d\n", b[i].rating);
		        printf("------------------------------------------\n");
		}
		
	}
	else if(choice==2)
	{
		sortByHighestRating(b,s);
		printf("\nBooks Are sorted as per your request...");
		int i;
		 for(i=0;i<3;i++)
	    {
	    	 printf("\n..............* Book Details *.................\n");
		        printf("-----------------------------------------\n");
		        printf("Book id: %d\n", b[i].bid);
		        printf("Book name: %s\n", b[i].bname);
		        printf("Book author: %s\n", b[i].aname);
		        printf("Book price: %.2f\n", b[i].price);
		        printf("Book category: %s\n", b[i].category);
		        printf("Book rating: %d\n", b[i].rating);
		        printf("------------------------------------------\n");
		}
		
	}
}


