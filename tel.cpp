//list of header file

#include<stdio.h>   //
#include<conio.h>   //
#include <string.h> //
#include<stdlib.h>  //
#include<windows.h> //
#include<process.h> //
#include<time.h> 	//for time

//list of functions
void welcome(void);				//welcome function
void login(void);				//sub menu funcation
void menu();
void time(void); 				//time function
void insert_customer_rec();		//insert records function
void view_customer_rec();		//view records function
void search_customer_rec();		//search records menu function
void search_customer_by_id();	//searech records by customer ID function
void search_customer_by_name();	//search records by name function
void modify_customer_rec();	    //modify customer record function
void delete_customer_rec();		//delete customer record function
void prepare_customer_bill();   //prepare customer bill
void set_password();			//change password function
void exit();					//exit function


//list of global variable
FILE *fp,*fptr;

//structure for password
struct password
{
	char pass[30];
};
struct password pw;
//structure for customers details
struct customer
{
int cID;
char cName[20];
char add[30];
long int phNo;
char email[30];
long int total_calls;
long int total_amount;
};
struct customer cu;

COORD coord = {0, 0}; 
COORD max_res,cursor_size;

void gotoxy (int x, int y) //for space of row and coloum
{
        coord.X = x; coord.Y = y; 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds) //for late printing
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

main() //main function
{
	welcome();
	password();
	menu();
	
}

/////////////////////////////////////////////////////////////////////////////////////////

void login(void)  //main function
{
	password();
};
/////////////////////////////////////////////////////////////////////////////////////////

void welcome()
{
		printf(" \n \n \n \n \n \n \n "); 
	printf(" \t  \t  \t * * * * * * * * * * * * * * * * * * * * * * * * * * \t \n"); 
	printf(" \t  \t        *  \t \t \t \t \t \t    * \n"); 
	printf(" \t  \t        * \t \t * -> WELCOME TO <- * \t \t    *  \n"); 
	printf(" \t  \t        * \t \t \t \t \t \t    * \n"); 
	printf(" \t  \t        * \t \t      TELEPHONE \t \t    *  \n"); 
	printf(" \t  \t        * \t \t \t \t \t \t    *  \n"); 
	printf(" \t  \t        * \t \t   BILLING SYSTEM \t \t    *  \n"); 
	printf(" \t  \t        *  \t \t \t \t \t \t    *  \n"); 
	printf("\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * *  \t \n"); 
	printf("\n"); 
	printf(" \n \t \t \t  Press Any Key To Continue... "); 
	getch(); 
}
void menu()
{
	system("cls");
	int choice;
	label:
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Enter a : to Insert New Customer Record");
	gotoxy(30,10);
	printf("Enter b : to Display All Customer Record");
	gotoxy(30,11);
	printf("Enter c : to Modify Customer Record");
	gotoxy(30,12);
	printf("Enter d : to Delete Customer Record");
	gotoxy(30,13);
	printf("Enter e : to Search Customer Record");
	gotoxy(30,14);
	printf("Enter f : to Prepare bill");
	gotoxy(30,15);	
	printf("Enter g : Change Administration Password");
	gotoxy(30,16);
	printf("Enter h : to Exit program");
	gotoxy(30,17);
	printf("================================================");
	gotoxy(30,18);
	printf(">Your Choice[a-h]");
	gotoxy(30,29);
	printf("================================================");
	gotoxy(30,20);
	time();
	gotoxy(30,21);
	printf("================================================");
	gotoxy(30,23);
	printf(">Enter your choice: ");
	
switch(getch())
	{
	case 'a':
	insert_customer_rec();
	break;
	case 'b':
	view_customer_rec();
	break;
	case 'c':
	modify_customer_rec();
	break;
	case 'd':
	delete_customer_rec();
	break;
	break;
	case 'e':
	search_customer_rec();
	break;
	case 'f':
	prepare_customer_bill();
	break;
	case 'g':
	set_password();
	break;
	case 'h':
	exit();
	default:

	printf("Wrong choice");
	getch();
	system("cls");
}
goto label;
}
/////////////////////////////////////////////////////////////////////////////////////////

void time(void) //time funcation
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Date and Time: %s", asctime (timeinfo) );
}

/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////

void insert_customer_rec() //insert record function
{
	fp=fopen("customers.dat","a+");
	int c;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,7);
	printf("Enter Customer Details");
	gotoxy(30,9);
	printf("Enter customer ID : ");
	scanf("%d",&cu.cID);
	gotoxy(30,10);
	printf("Enter Customer Name: ");
	scanf("%s",cu.cName);
	gotoxy(30,11);
	printf("Enter Customer Address: ");
	scanf("%s",cu.add);
	gotoxy(30,12);
	printf("Enter Customer Phone No: ");
	scanf("%ld",&cu.phNo);
	gotoxy(30,13);
	printf("Enter Customer Email: ");
	scanf("%s",cu.email);
	fwrite(&cu,sizeof(cu),1,fp);
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,8);
	printf("Customers record added successfully");
	fclose(fp);
	getch();
	view_customer_rec();
}

/////////////////////////////////////////////////////////////////////////////////////////

void modify_customer_rec() //modify record function
{
	fp=fopen("customers.dat","r+");
	int mid,flag=0,size;
	system("cls");
	size=sizeof(cu);
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Enter id to modify record: ");
	scanf("%d",&mid);
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
		if(mid==cu.cID)
		{
			flag=1;
			gotoxy(30,10);
			printf("Record Matched");
			gotoxy(30,12);
			printf("ID: %d",cu.cID);
			gotoxy(30,13);
			printf("Name: %s",cu.cName);
			gotoxy(30,14);
			printf("Address: %s",cu.add);
			gotoxy(30,15);
			printf("Phone No: %ld",cu.phNo);
			gotoxy(30,16);
			printf("Email: %s",cu.email);
			gotoxy(30,17);
			printf("Enter Data To Modify Record");
			gotoxy(30,19);
			printf("Name: ");
			scanf("%s",cu.cName);
			gotoxy(30,20);
			printf("Address: ");
			scanf("%s",cu.add);
			gotoxy(30,21);
			printf("Phone No: ");
			scanf("%ld",&cu.phNo);
			gotoxy(30,22);
			printf("Email: ");
			scanf("%s",cu.email);
			gotoxy(30,24);
			printf("Record Modified");
			break;
		}
}
			fseek(fp,-size,1);
			fwrite(&cu,sizeof(cu),1,fp);
			fclose(fp);
			getch();
			system("cls");
	
	if(flag==0)
	{
		gotoxy(30,12);
		printf("Record not found");
		getch();
	}

}

/////////////////////////////////////////////////////////////////////////////////////////

void view_customer_rec() //view record function
{ 
	fp=fopen("customers.dat","r");
	system("cls");
	int flag=0;
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Displaying Customers Details");
	gotoxy(30,10);
	printf("ID\tName\tAddress\t\tPhone\t\tEmail\n");
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
		flag=1;
		printf("\t\t\t\t%d\t%s\t%s\t%ld\t%s\n",cu.cID,cu.cName,cu.add,cu.phNo,cu.email);
}
if(flag==0)
{
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Record Not Found\n");
}
	fclose(fp);
	getch();
	system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////

void search_customer_rec() //search record menu function
{
	again:
	fp=fopen("customers.dat","r");
	char sname[10];
	int flag=0,choice;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Enter 1: to Search Customer By Name");
	gotoxy(30,10);
	printf("Enter 2: to Search Customer By ID");
	gotoxy(30,11);
	printf("Enter 3: to go back");
	gotoxy(30,12);
	printf("Enter Your Choice: ");
	switch(getch())
	{
		case '1':
			search_customer_by_name();
		break;
		case '2':
			search_customer_by_id();
		break;
		case '3':
			menu();
		break;
		
		default:
			printf("Wrong choice");
			getch();
			system("cls");
}
goto again;
}

/////////////////////////////////////////////////////////////////////////////////////////

void search_customer_by_name() //search record by name function
{
	fp=fopen("customers.dat","r");
	char sname[10];
	int flag=0;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Search Customer By Name");
	gotoxy(30,10);
	
	printf("Enter name : ");
	scanf("%s",sname);
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
	if(strcmp(cu.cName,sname)==0)
	{
	flag=1;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Record Found");
	gotoxy(30,10);
	printf("Id : %d\n",cu.cID);
	gotoxy(30,11);
	printf("Name : %s\n",cu.cName);
	gotoxy(30,12);
	printf("Address : %s\n",cu.add);
	gotoxy(30,13);
	printf("Phone No : %ld\n",cu.phNo);
	gotoxy(30,14);
	printf("Email : %s\n",cu.email);
	getch();
	system("cls");
	menu();
}
}
if(flag==0)
{
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Record not found");
	getch();
	menu();
} 
fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////

void search_customer_by_id() //search record by ID function
{
	fp=fopen("customers.dat","r");
	int cid;
	int flag=0;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Search Customer By ID");
	gotoxy(30,10);
	
	printf("Enter ID : ");
	scanf("%d",&cid);
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
	if(cu.cID==cid)
	{
	flag=1;
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf( "Record Found");
	gotoxy(30,10);
	printf("Id : %d\n",cu.cID);
	gotoxy(30,11);
	printf("Name : %s\n",cu.cName);
	gotoxy(30,12);
	printf("Address : %s\n",cu.add);
	gotoxy(30,13);
	printf("Phone No : %ld\n",cu.phNo);
	gotoxy(30,14);
	printf("Email : %s\n",cu.email);
	getch();
	system("cls");
	menu();
}
}
if(flag==0)
{
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf(	"Record not found");
	getch();
	menu();
}
fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////

void delete_customer_rec() //delete record function
{
	system("cls");
	fp=fopen("customers.dat","r+");
	int did,flag=0;
	fptr=fopen("temp.dat","w+");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Delete Record By Customer ID");
	gotoxy(30,10);
	printf("Enter Customer ID: ");
	scanf("%d",&did);
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
		if(did==cu.cID)	
	{
	flag=1;
	}
	if(did!=cu.cID)
	{
	fwrite(&cu,sizeof(cu),1,fptr);
	}
	}
	if(flag==1)
	{
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");	
	gotoxy(30,9);
	printf("Customer Record Deleted Successfully");
	getch();
	}
	else
	{	
	system("cls");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf(	  "Record not found"  );
	getch();
	}
	fclose(fp);
	fclose(fptr);
	remove("customers.dat");
	rename("temp.dat","customers.dat");
}

/////////////////////////////////////////////////////////////////////////////////////////

void prepare_customer_bill()
{
	system("cls");
	fp=fopen("customers.dat","r");
	int bid,flag=0,size;
	int taxinvoiceNo;
	int calls;
	float tamt;
	char ptype[30];
	system("cls");
	size=sizeof(cu);
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Enter Customer id to prepare bill: ");
	scanf("%d",&bid);
	while(fread(&cu,sizeof(cu),1,fp)==1)
	{
		if(bid==cu.cID)
		{
			flag=1;
			gotoxy(30,10);
			printf( "Record Match" );
			gotoxy(30,12);
			printf("Enter Data To prepare bill");
			gotoxy(30,13);
			printf("Tax Invoice No: ");
			scanf("%d",&taxinvoiceNo);
			gotoxy(30,14);
			printf("Total Calls: ");
			scanf("%d",&calls);
			gotoxy(30,15);
			printf("Payment Type(cheque or cash): ");
			scanf("%s",ptype);
			if(calls<=100)
				tamt=200;
			else if(calls>100 && calls<150)
				tamt=200+(calls-100)*0.70;
			else if(calls>=150 && calls<=200)
				tamt=200+50*0.70+(calls-150)*0.60;
			else if(calls>=200 && calls<=250) 
			    tamt=200+50*0.70+50*0.60+(calls-200)*0.50;
		    else
		        tamt=200+50*0.70+50*0.60+50*0.50+(calls-250)*0.40;
					
			system("cls");
			gotoxy(30,6);
			printf("===================Administration Menu======================");
			gotoxy(30,9);
			printf( "bill prepared successfully" );
			gotoxy(50,11);
			printf( "TELEPHONE BILLING SYSTEM" );
			gotoxy(30,13);
			printf("Tax InvoiceNo: %d",taxinvoiceNo);
			gotoxy(30,14);
			printf("Customer ID: %d",cu.cID);
			gotoxy(60,13);
			time();
			gotoxy(30,15);
			printf("Customer Name: %s",cu.cName);
			gotoxy(30,16);
			printf("Customer Address: %s",cu.add);
			gotoxy(30,17);
			printf("Customer Phone: %ld",cu.phNo);
			gotoxy(30,18);
			printf("Customer Email: %d",cu.email);
			gotoxy(30,19);
			printf("Payment Mode: %s",ptype);
			gotoxy(30,20);
			printf("Totals Calls:\t\t\t\t\t\t    %d",calls);
			gotoxy(30,21);
			printf("---------------------------------------------------------------------");
			gotoxy(30,22);
			printf("Total Amount(tax included):\t\t\t\t    %f",tamt);
			gotoxy(30,24);
			printf("Received %f in %s Thanks",tamt,ptype);
			getch();
			system("cls");
		}
}
	
	if(flag==0)
	{
	
		gotoxy(30,12);
		printf( "Record not found" );
		getch();
	}
	fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////

void set_password() //change password
{
	system("cls");
	char opass[20],npw[20],cpw[20];
	fp=fopen("password.dat","r+");
	gotoxy(30,6);
	printf("=============Administration Menu================");
	gotoxy(30,9);
	printf("Set New Password");
	gotoxy(30,10);
	printf("Enter Old Password : ");
	scanf("%s",opass);
	fread(&pw,sizeof(pw),1,fp);
	if(strcmp(pw.pass,opass)==0)
	{	
		rewind(fp);
		gotoxy(30,13);
		printf("Enter New Password : ");
		scanf("%s",pw.pass);
		gotoxy(30,14);
		printf("Enter Conform Password : ");
		scanf("%s",cpw);
		fclose(fp);
		if(strcmp(pw.pass,cpw)==0)
		{ 	fp=fopen("password.dat","w");
			fwrite(&pw,sizeof(pw),1,fp);
			gotoxy(30,15);
			printf(  "change password successfully"   );
			
			fclose(fp);
			getch();
			login();
		}
		else 
		{
			gotoxy(30,14);
			printf(  "Confirm password didnot match"   );
			getch();
			set_password();
			}
}else {
			gotoxy(30,14);		
			printf(  "old password didnot match"   );
			getch();
			set_password();
}

}

/////////////////////////////////////////////////////////////////////////////////////////

void exit(void) //exit function
{
	system("cls");

		gotoxy(30,9);
		delay(600);
		printf("Developed By: ");
		gotoxy(30,11);
		delay(600);
		printf(   "1. Shishir Pandey");
		gotoxy(30,12);
		delay(600);
		printf("2. Abishekh Nepal");
		gotoxy(30,13);
		delay(600);
		printf("3. Rajan Gaire");
		gotoxy(30,14);
		delay(600);
		printf("4. Ashok Rimal");
		gotoxy(30,16);
		delay(600);
		printf( "*****Happy Coding*****"  );
		printf("\nExiting in 5 second...........");
		delay(600);
		printf("\nExiting in 4 second..........");
		delay(600);
		printf("\nExiting in 3 second.........");
		delay(600);
		printf("\nExiting in 2 second........");
		delay(600);
		printf("\nExiting in 1 second.......");
		exit(0);
}

