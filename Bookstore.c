typedef struct
{
int id;
char bname[50];
char authname[50];
float bprice;
int stock;
}binfo;

#include<stdio.h>
#include<conio.h>
#include<string.h>

void welcomeMessage()
{
printf("\n\n\n\n\n");
printf("\n\t\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t\t\t                    = WELCOME =");
printf("\n\t\t\t                      = TO =");
printf("\n\t\t\t                     = BOOK =");
printf("\n\t\t\t                    = STORE =");
printf("\n\t\t\t                  = MANAGEMENT =");
printf("\n\t\t\t                    = SYSTEM =");
printf("\n\t\t\t     =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\n\n\n\t\t\t Enter any key to continue.....");
getch();
}

void addbook()
{
char name[50],authname[50];
binfo addbook={0};
FILE *data=NULL;
system("cls");
printf("\t\t\t\tADD BOOK\n");
data=fopen("data.bin","ab+");
if(data==NULL)
{
printf("File cant be opened");
}
printf("File is now opened\n");
printf("Enter the Book ID: ");
fflush(stdin);
scanf("%d",&addbook.id);
printf("Enter the Book Name: ");
fflush(stdin);
fgets(addbook.bname,50,stdin);
printf("Enter the Author Name: ");
fflush(stdin);
fgets(addbook.authname,50,stdin);
printf("Enter the Price of the Book: ");
scanf("%f",&addbook.bprice);
printf("Enter the number of Books: ");
scanf(" %d",&addbook.stock);
printf("Book Added Successfully\n");
fwrite(&addbook,sizeof(addbook),1,data);
fclose(data);
}

void searchbyid()
{
int found=0,x;
binfo addbook={0};
FILE *data=NULL;
printf("Enter the book id: ");
scanf("%d",&x);
data=fopen("data.bin","rb");
if(data==NULL)
{
printf("File cant be opened");
}
while(fread(&addbook,sizeof(addbook),1,data))
{
if(addbook.id==x)
{
found=1;
break;
}
}
if(found!=0)
{
printf("Book Found");
printf("\n");
printf("\nBook id: %d",addbook.id);
printf("\nBook Name: %s",addbook.bname);
printf("Author Name: %s",addbook.authname);
printf("Price :%.2f",addbook.bprice);
printf("\nBooks in stock: %d\n",addbook.stock);
}
else
{
printf("Book not found ");
}
fclose(data);
}

void searchbybname()
{
int found=0;char bookname[25];
binfo addbook={0};
FILE *data=NULL;
data=fopen("data.bin","rb");
if(data==NULL)
{
printf("File cant be opened");
}
printf("Enter the Book Name: ");
fflush(stdin);
fgets(bookname,13,stdin);
while(fread (&addbook, sizeof(addbook), 1, data))
{
if(!strcmp(addbook.bname,bookname))
{
found=1;
break;
}
}
if(found)
{
printf("Book Found");
printf("\n");
printf("\nBook id: %d",addbook.id);
printf("\nBook Name: %s",addbook.bname);
printf("Author Name: %s",addbook.authname);
printf("Price :%.2f",addbook.bprice);
printf("\nBooks in stock: %d\n",addbook.stock);
}
else
{
printf("Book not found ");
}
fclose(data);
}

void searchbyauthname()
{
char authname[25];int found=0;
binfo addbook={0};
FILE *data=NULL;
data=fopen("data.bin","rb");
if(data==NULL)
{
printf("File cant be opened");
}
printf("Enter the Author Name: ");
fflush(stdin);
fgets(authname,13,stdin);
while(fread (&addbook,sizeof(addbook),1,data))
{
if(strcmp(addbook.authname,authname)==0)
{
found=1;
break;
}
}
if(found!=0){
printf("Book Found");
printf("\n");
printf("\nBook id: %d",addbook.id);
printf("\nBook Name: %s",addbook.bname);
printf("Author Name: %s",addbook.authname);
printf("Price :%.2f",addbook.bprice);
printf("\nBooks in stock: %d\n",addbook.stock);
}
else
{
printf("No book found ");
}
fclose(data);
}
void searchbook()
{
int ch=0;
system("cls");
printf("\t\t\t\tBOOK SEARCH");
printf("\n");
printf("\n1. Search by Book Name ");
printf("\n2. Search by Author Name ");
printf("\n3. Search by id ");
printf("\nEnter your choice --> ");
scanf("%d",&ch);
switch(ch)
{
case 1:
searchbybname();
break;
case 2:
searchbyauthname();
break;
case 3:
searchbyid();
break;
default:
printf("Enter a valid choice");
searchbook();
}
}

void updatebook()
{
int up,x,found=0,s;float updp;
binfo addbook={0};
FILE *data;
FILE *temp;
temp=fopen("temp.bin","wb+");
data=fopen("data.bin","rb");
if(data==NULL)
{
printf("File cant be opened");
exit(1);
}
system("cls");
printf("\t\t\t\t\tUpdate\n");
printf("Enter the book id you want to update: ");
scanf("%d",&up);
while(fread(&addbook,sizeof(addbook),1,data))
{
if(addbook.id==up)
{
found=1;
break;
}
}
if(found!=0)
{
printf("Book Found");
printf("\n");
printf("\nBook id: %d",addbook.id);
printf("\nBook Name: %s",addbook.bname);
printf("Author Name: %s",addbook.authname);
printf("Price :%.2f",addbook.bprice);
printf("\nBooks in stock: %d\n",addbook.stock);
}
else
{
printf("Book not found ");
}
fclose(temp);
fclose(data);
temp=fopen("temp.bin","wb");
data=fopen("data.bin","rb");
while(fread(&addbook,sizeof(addbook),1,data))
{
if (addbook.id!=up)
{
fwrite(&addbook, sizeof(addbook), 1, temp);
}
else
{
printf("\n\nSelect the field you want to update --");
printf("\n\n1. Update the Price");
printf("\n2. Update Stock");
printf("\n3. Exit");
printf("\nEnter your choice -->");
scanf("%d",&x);
switch(x)
{
case 1:
printf("Enter the new price: ");
scanf("%f",&addbook.bprice);
break;
case 2:
printf("\nEnter the new no of books: ");
scanf("%d",&addbook.stock);
break;
case 3:
printf("Exiting\n");
break;
default:
printf("Invalid Selection");
break;
}
fwrite(&addbook,sizeof(addbook),1,temp);
}
}
fclose(temp);
fclose(data);
temp=fopen("temp.bin","rb");
data=fopen("data.bin","wb");
while (fread(&addbook, sizeof(addbook), 1, temp))
{
fwrite(&addbook, sizeof(addbook), 1, data);
}
fclose(data);
fclose(temp);
sleep(1);
system("cls");
if(x!=3)
{
printf("RECORD UPDATED");
}
}

void delno()
{
binfo addbook;
FILE *data={0};
FILE *temp={0};
data=fopen("data.bin","wb");
temp=fopen("temp.bin","rb");
while(fread(&addbook,sizeof(addbook),1,temp))
{
fwrite(&addbook,sizeof(addbook),1,data);
}
fclose(data);
fclose(temp);
}
void menu();

void delbook()
{
int delid,found=0;char bd;
binfo addbook;
FILE *data={0};
FILE *temp={0};
data=fopen("data.bin","rb");
system("cls");
printf("\t\t\t\t\tDELETION");
printf("\n\n");
printf("\nEnter the Book Id you want to delete: ");
scanf("%d",&delid);
while(fread(&addbook,sizeof(addbook),1,data))
{
if(addbook.id==delid)
{
found=1;
break;
}
}
if(found)
{
printf("Book Found");
printf("\n");
printf("\nBook id: %d",addbook.id);
printf("\nBook Name: %s",addbook.bname);
printf("Author Name: %s",addbook.authname);
printf("Price :%.2f",addbook.bprice);
printf("\nBooks in stock: %d\n",addbook.stock);
}
else
{
printf("Book not found ");
}
fclose(data);
data=fopen("data.bin","rb");
temp=fopen("temp.bin","wb");
while(fread(&addbook,sizeof(addbook),1,data))
{
if(addbook.id!=delid)
{
fwrite(&addbook,sizeof(addbook),1,temp);
}
else
{
printf("Are you sure you want to delete this record?");
printf("\nPress y for yes and n for no --> ");
scanf(" %c",&bd);
switch(bd)
{
case 'y':
system("cls");
printf("Record has been deleted");
fclose(data);
fclose(temp);
delno();
break;
case 'n':
system("cls");
printf("Record has not been deleted");
fwrite(&addbook,sizeof(addbook),1,temp);
fclose(data);
fclose(temp);
delno();
sleep(1);
system("cls");
menu();
break;
default:
printf("Invalid Selection");
break;
}
}
}
}
void menu()
{
int choice=0;
printf("\t\t\t\tMAIN MENU");
do
{
printf("\n\n1. Add Books");
printf("\n2. Search Books");
printf("\n3. Update Books");
printf("\n4. Delete Books");
printf("\n5. Exit");
printf("\nEnter the choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
addbook();
break;
case 2:
searchbook();
break;
case 3:
updatebook();
break;
case 4:
delbook();
break;
case 5:
printf("Exiting\n");
sleep(1);
system("cls");
exit(1);
break;
default:
printf("Enter a valid input");
}
}
while(choice!=5);
}

void login()
{
int L=1,i,cout=2;
char c[25],m[25],ch;
system("cls");
printf("\t\t\t\t\tLOGIN PAGE\n\n");
do
{
printf("\n\n\n\t\tEnter your Username:");
gets(c);
printf("\n\t\tEnter the Password:");
for(i=0;i<8;i++)
{
ch = getch();
if(ch==13)
{
break;
}
m[i] = ch;
printf("*");
}
m[i]='\0';
if((!strcmp(c,"admin")) && (!strcmp(m,"admin")))
{
system("cls");
printf("\n\nWelcome! ");
printf("\nYou are Successfully Logged in ");
printf("\nPress any key to Continue ....");
getch();
system("cls");
menu();
}
else
{
printf("\n\n\t\tLogin Failed \n\t\tEnter Again Username & Password\n");
printf("\t\tYou have %d chances left",cout);
sleep(1);
system("cls");
L++;
cout--;
}
}
while(L<=3);
    if(L>3)
    {
        printf("\t\t\t\tLogin Failed");
        printf("\n\t\t\t\tSorry,Unknown User.");
        sleep(1);
        system("cls");
    }

}

void main()
{
system("cls");
welcomeMessage();
login();
getch();
}