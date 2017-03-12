/*
 *		--------------- Hotel Data Base Management System -------------------
 *                      =================================
 *
 *                			  - Shashwat Aggarwal
 *                              355/COE/15
 *                              COE - III
 *                              Netaji Subhas Institute of Technology.
 *
 */


 /*
  *************************     SOURCE - CODE     **************************
  */



//****************************
//      HEADER FILES
//****************************

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;


//****************************
//      Global Variables
//****************************

int ROOMS_BOOKED;	// Global Counter ; max value = 200 rooms.
int ROOMS[201] = {0};

struct _C_{             // Structure to store details of deleted record.
    int room_no;
	int days;
	char name[100];
	char phone[10];
	int age;

};


//****************************
//      CUSTOMER CLASS
//****************************

class Customer
{
	// Data Members.

	struct cust{        // Structure to store details of new record.
	int room_no;
	int days;
	char name[100];
	char phone[10];
	int age;
	}C;

	fstream f1;         // File Stream Object to open Binary Files.

public:

    void create_customer()		// Create A Customer Record.
	{
		for(int i=1;i<=200;i++)
         {   if(ROOMS[i]==0)
            {
                ROOMS[i] = 1;
                C.room_no = i;
                break;
            }
         }

		cout<<"\n\t\tName of The Customer : ";
		cin>>C.name;
	 	cout<<"\n\t\tAge of The Customer : ";
		cin>>C.age;
	 	cout<<"\n\t\tPhone Number:";
		cin>>C.phone;
		cout<<"\n\t\tPeriod of Stay(Days): ";
		cin>>C.days;
		f1.open("Cust.dat",ios::app | ios::binary );
	  	f1.seekg(0,ios::end);
		f1.seekp(0,ios::end);
		f1.write((char*)&C,sizeof(C));
	  	f1.close();

        cout<<"\n\n\n\t\t---------------------------------------\n\n";
        cout<<"\n\t\tRoom Alloted @ Rs.3000/- per day only !!\n\n";
        cout<<"\n\t\t---------------------------------------\n\n";

		fflush(stdin);
        cin.get();
		cout<<"\n\n";
	}


	void show_customer()	// Display ALL Customers Records.
	{
        system("cls");
		f1.open("Cust.dat",ios::in|ios::binary);
		f1.seekg(0,ios::beg);

		cout<<"\n\n\t\t-----------------------------------";
	  	cout<<"\n\n\t\t\tALL CUSTOMER DETAILS\n";
		cout<<"\n\t\t-----------------------------------\n\n";

        while(f1.read((char*)&C,sizeof(C)))
		{
			cout<<"\n\n\t\tName of The Customer : ";
			puts(C.name);
	 		cout<<"\n\t\tRoom Number : ";
			cout<<"R-0"<<C.room_no;
	 		cout<<"\n\n\t\tAge of The Customer : ";
			cout<<C.age;
	 		cout<<"\n\n\t\tPhone Number : ";
			puts(C.phone);
		}

		f1.close();
		fflush(stdin);
        cin.get();
		cout<<"\n\n";
		system("cls");
	}

	void search_customer(char n[],int f)	// Search For A given Customer Details based on Name.
	{

        system("cls");

		f1.open("Cust.dat",ios::in|ios::binary);
		f1.seekg(0,ios::beg);

		if(f)
		{
		cout<<"\n\t\t-----------------------------------";
	  	cout<<"\n\n\t\t\tCUSTOMER DETAILS : \n";
		cout<<"\n\t\t-----------------------------------\n\n";

		}

		int flag=0;
		while(f1.read((char*)&C,sizeof(C)))
		{

			if((strcmp(C.name,n)==0))
			{
				cout<<"\n\t\tName of The Customer : ";
				puts(C.name);
		 		cout<<"\n\t\tRoom Number : ";
                cout<<"R-0"<<C.room_no;
		 		cout<<"\n\n\t\tAge of The Customer : ";
				cout<<C.age;
		 		cout<<"\n\n\t\tPhone Number : ";
				puts(C.phone);
				flag = 1;
				break;
			}
		}

		f1.close();
		if(flag==0)
    		cout<<"\n\n\t\tCustomer does not exist!\n\n";

        fflush(stdin);
        cin.get();
		cout<<"\n\n";
		system("cls");

	}
	void search_customerR(int r)	// Search For A given Customer Details based on Room No.
	{

		f1.open("Cust.dat",ios::in|ios::binary);
		f1.seekg(0,ios::beg);
		cout<<"\n\t\t-----------------------------------";
	  	cout<<"\n\n\t\t\tCUSTOMER DETAILS : \n";
		cout<<"\n\t\t-----------------------------------\n\n";

		int flag=0;
		while(f1.read((char*)&C,sizeof(C)))
		{

			if(C.room_no==r)
			{
				cout<<"\n\t\tName of The Customer : ";
				puts(C.name);
		 		cout<<"\n\t\tRoom Number : ";
                cout<<"R-0"<<C.room_no;
		 		cout<<"\n\n\t\tAge of The Customer : ";
				cout<<C.age;
		 		cout<<"\n\n\t\tPhone Number : ";
				puts(C.phone);
				flag = 1;
				break;
			}
		}
		f1.close();
		if(flag==0)
    		cout<<"\n\n\t\tCustomer does not exist!\n\n";

        fflush(stdin);
        cin.get();
		cout<<"\n\n";
		system("cls");

	}
	void modify_customer()	// Modify A Customer's  Details.
	{
		char n[100];
		cout<<"\n\n\t\tName of Customer Whose Record is to be Modified : ";
		cin>>n;

        system("cls");
		f1.open("Cust.dat",ios::in|ios::out|ios::binary);
		f1.seekg(0,ios::beg);

		int flag=0;
		long pos = f1.tellg();

		while(f1.read((char*)&C,sizeof(C)))
		{
			if((strcmp(C.name,n)==0))
			{
				cout<<"\n\t\tName of The Customer : ";
				cin>>C.name;
	 			cout<<"\n\t\tAge of The Customer : ";
				cin>>C.age;
	 			cout<<"\n\t\tPhone Number : ";
				cin>>C.phone;

				flag = 1;
				f1.seekg(pos);
				f1.write((char*)&C,sizeof(C));
				break;
			}
			pos = f1.tellg();
		}
		f1.close();
		if(flag==0)
    		cout<<"\n\n\t\tCustomer does not exist!\n\n";
        fflush(stdin);
        cin.get();

        system("cls");

	}
    struct _C_ delete_customer()	// Delete a Given Customer Record.
	{
	    _C_ a;
        fstream F("temp.dat",ios::out|ios::binary);
		f1.open("Cust.dat",ios::in|ios::binary);
		f1.seekg(0,ios::beg);
		int flag=0;

		char n[100];
        cout<<"\n\n\t\tName of Customer Whose Record is to be Deleted : ";
        cin>>n;

		while(f1.read((char*)&C,sizeof(C)))
		{
			if(strcmp(C.name,n)== 0)
			{
				cout<<"\n\n\t\t------ Record of Customer Deleted !!------";
				flag = 1;
				strcpy(a.name , C.name);
                a.age = C.age;
                a.room_no = C.room_no;
                strcpy(a.phone , C.phone);
                a.days = C.days;
			}
			else
			{
				F.write((char*)&C,sizeof(C));
			}

		}
		if(flag==0)
    		{
				cout<<"\n\n\t\tCustomer does not exist!\n\n";
				a.days = -1;
			}
		F.close();
		f1.close();
		remove("Cust.dat");
	  	rename("temp.dat","Cust.dat");
		return a;
	}

};  //------------   END OF CLASS CUSTOMER   --------------



//****************************
//      HOTEL CLASS
//****************************

class Hotel
{
	// Data Members.

	fstream f1;         // File Stream Object to open Binary Files.

public:

	Customer C;

    // Methods.

	void main_menu()		//to Display the main menu.
	{
		int choice;

		while(choice!=5)
		{
            system("cls");

			cout<<"\n\n\n\n\t\t   ************************************";
			cout<<"\n\t\t\t   *** MAIN MENU ***";
			cout<<"\n\t\t   ************************************";
			cout<<"\n\n\n\t\t\t   1. Book A Room.";
			cout<<"\n\t\t\t   2. View Customer Details.";
			cout<<"\n\t\t\t   3. Check Availability of a Room.";
			cout<<"\n\t\t\t   4. Free A Room.";
			cout<<"\n\t\t\t   5. Exit";
			cout<<"\n\n\t\t   Enter Your Choice :\t ";
			cin>>choice;

			switch(choice)
			{
				case 1:		checkin();  // call to Class Methods.
							break;

				case 2: 	Cust();
							break;

                case 3:     check();
                            break;

				case 4:		checkout();
                            break;

				case 5: 	break;

				default:	{   cout<<"\n\n\t\t\tWrong choice.....!!!";
                                cout<<"\n\n\t\tPress any key to continue....!!\n\n\n";
                                fflush(stdin);
                                cin.get();
                                cout<<"\n\n";
                                system("cls");
                            }

			}

		}

	}

	void checkin()			//to book a room : Check if room is free b/w given dates allot room create customer.
	{
            system("cls");

			if(ROOMS_BOOKED > 200)
			{
					cout<<"\n\n\t\tSorry For Inconvience! No More Rooms Available.\n\n";
					return ;
			}
			cout<<"\n\n\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			cout<<"\n\t\tWelcome, We are Pleased to be at Your Service!\n\n";
			cout<<"\n\t\t---------------------------------------------\n\n";
			cout<<"\n\t\tEnter Customer Details :- \n";

			++ ROOMS_BOOKED;
			C.create_customer();

            system("cls");

			return ;
	}


	void Cust()			// Details of Customers.
	{
        system("cls");

        if(ROOMS_BOOKED <= 0 )
			{
					cout<<"\n\n\tInvalid Operation . No Information Available. Data Base is Empty! \n\n\n";
					return;
			}

		int c;
		do
		{

            cout<<"\n\t\t************************************";
			cout<<"\n\t\t\tCustomer Details ";
            cout<<"\n\t\t************************************";
            cout<<"\n\n\n\t\t1. Modify a Record\n";
            cout<<"\n\t\t2. Search for a Record\n";
            cout<<"\n\t\t3. Show All Records\n";
            cout<<"\n\t\t4. Return To Main Menu\n";
            cout<<"\n\n\t\tEnter Your Choice :\t ";
			cin>>c;
	       switch(c)
	       {
		    case 1:
                {
                    C.modify_customer();
                    break;
                }
		    case 2:
                {
                    cout<<"\n\t\tEnter Name of Customer to Search for :  ";
                    char name[30];
                    cin>>name;
                    C.search_customer(name,1);
                    break;
                }
		    case 3:
                {
                    C.show_customer()	;
                    break;
                }
			case 4:
                {
                    cout<<endl;
                    break;
                }
            }
        }while(c!=4);//END OF WHILE

	}
    void check()
    {
        system("cls");

        int r;
        cout<<"\n\t\tEnter The Room to Check for : ";
        cin >> r;
        if(r>=1 && r<=200)
            {

                if(ROOMS[r] == 0)
                    cout<<"\n\t\tRoom is Empty!\n\n";
                else
                {
                    cout<<"\n\t\tRoom is FULL!\n\n";
                    C.search_customerR(r);
                }
            }
        else
            cout<<"\n\t\tNo Such Room Exists!\n\n";

        fflush(stdin);
        cin.get();
    }


	void checkout()	// Delete Record , Free Room , Generate Bill.
	{
        system("cls");

			if(ROOMS_BOOKED <= 0 )
			{
					cout<<"\n\n\t\tInvalid Operation . No room has been booked. \n\n\n";
					return;
			}

            cout<<"\n\n\t\t\tDeallocating Room\n\n";
            cout<<"\t\t------------------------------------";

			_C_ d = C.delete_customer();
			if(d.days == -1)
				{
					return;
				}
            cout<<"\n\n\n\t\tThank You for staying. Please Visit Again.";
			cout<<"\n\n\t\t-------------------------------------------";

            -- ROOMS_BOOKED;
			ROOMS[d.room_no] = 0;   // Room Free

			cout<<"\n\n\t\tGenerating Bill...\n\n";
			cin.get();
			Bill(d);
	}

	void Bill(struct _C_ a)     // Function To Generate Bill.
	{
        system("cls");

		cout<<"\n\n   ========================================================================\n\n";
		cout<<"\n\n   ----------------------------------BILL----------------------------------\n\n";
		cout<<"\n\n   ========================================================================\n\n";
		cout<<"\n\n\t\tName of The Customer : ";
        puts(a.name);
        cout<<"\n\t\tRoom No. of The Customer : ";
        cout<<a.room_no;
        cout<<"\n\n\t\tAge of The Customer : ";
        cout<<a.age;
        cout<<"\n\n\t\tPhone Number : ";
        puts(a.phone);
		cout<<"\n\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"\n      -------- Total Bill : -------- Rs. "<<3000*a.days<<" only. -------- \n\n";
		cout<<"\n \t Press Enter to Proceed! ";
		cin.get();
		cout<<"\n\n";
		return;
	}
};	 //------------   END OF CLASS HOTEL   --------------



//****************************
//          MAIN
//****************************
int main()
{
    // System function under lib : stdlib.h

	system("COLOR F0");     // Set Color of CMD to (WHITE,BLACK)
	system("cls");          // Clear Screen.

    cout<<"\n\n\n\n    ---------------- Hotel Data Base Management System ----------------";
	cout<<"\n\n\n\n\t\t                         Shashwat Aggarwal";
	cout<<"\n\n\t\t                         355/COE/15";
	cout<<"\n\n\t\t                         COE - III";
    cout<<"\n\n\t\t                         355/COE/15";
    cin.get();

	system("cls");

	Hotel admin;    // Object of Class Hotel

	cout<<"\n\n\n\n\n\n\n\n\n\t\t ----------------- WELCOME ------------------";
	cin.get();

    /*
     *  Check For Previously Stored Records!
     */
    fstream f;

    f.open("ROOMS.txt",ios::in);
    f>>ROOMS_BOOKED;
    for(int i=1;i <= 200 ; i++)
        f>>ROOMS[i];
    f.close();

    //-----------------------

	/*
	 **********************
      Call To Main Menu :-
	 **********************
	 */

        admin.main_menu();
        system("cls");

    //-----------------------

    /*
     *  UPDATE ROOM RECORDS.
     */

    f.open("ROOMS.txt",ios::out);
    cout<<ROOMS_BOOKED;
    f<<ROOMS_BOOKED<<"\n";
    for(int i=1;i <= 200 ; i++)
        f<<ROOMS[i]<<"\n";
	f.close();

	return 0;
}
// -----------  END OF MAIN FUNCTION -------------
