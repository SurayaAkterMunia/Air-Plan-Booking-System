
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>
#include<iomanip>



#define size 100

using namespace std;

void clrscr()
{
    system("cls");
}
int uid, userquantity, tquantity;


struct user_head
{
    int count;
    struct users* top;
}*userhead;

struct users
{
      long int password;
      char username[size];
      char phone[size];
      char email[size];
      char start[size];
      char destination[size];
      char plane[size];
      char type[size];
      int price;
      int quantity;
      int flight_time;
      int day;
      int month;
      int year;
      int dep_time;
      struct users *next;
}*new_user;
void create_user()
{
    userhead=new user_head();
    userhead->count=0;
    userhead->top=NULL;
}
struct admin_head
{
    int count;
    struct admins* top;
}*adminhead;

struct admins
{
    long int password;
    char username[size];
    struct admins *next;
}*new_admin;

void create_admin()
{
    adminhead=new admin_head();
    adminhead->count=0;
    adminhead->top=NULL;

}

struct ticket_head
{
    int count;
    struct ticket* top;
}*tickethead;

struct ticket
{
    char start[size];
    char destination[size];
    char plane[size];
    char type[size];
    int price;
    int quantity;
    int id;
    int flight_time;
    int day;
    int month;
    int year;
    int dep_time;
    struct ticket* next;
}*new_ticket;

void create_ticket()
{
    tickethead= new ticket_head();
    tickethead->count=0;
    tickethead->top=NULL;
}

void supermenu();
void administration();
void user();
void cancel_flight();
void add_flight();
void user_signup();
void admin_signup();
void admin_available_flights();
void user_available_flights();
void user_status();
void book_ticket();
void print_user(); //For Test!! Not present in the main code

void supermenu()
{

    int choice;
    cout<<"\n\n\t\t\t\tFLY WITH JACWO\t\t\t\n\n\n\n\n";
    cout<<"\n Press 1 to Log in as User\n";
    cout<<"\n Press 2 to Log in as Admin\n";
    cout<<"\n Press 3 to Sign up as User\n";
    cout<<"\n Press 4 to Sign up as Admin\n";
    cout<<"\n Press 0 to exit\n";
    cout<<"\n Enter your choice:\n";
    cin>>choice;
    switch(choice)
	{
		case 1:
		    clrscr();
            user();
            break;
		case 2:
		    clrscr();
            administration();
            break;

        case 3:
            clrscr();
            user_signup();
            break;
        case 4:
            clrscr();
        	admin_signup();
        	break;
        case 5:
            clrscr;
            print_user();
            system("PAUSE");
            break;

       	case 0:
       		return;
       		break;


		default:
            cout << "\n\n CAUTION!! INVALID CHOICE!!~~~Enter again!!\n\n";
            system("PAUSE");
            break;
	}

}

int main()
{
    create_user();
    create_admin();
    create_ticket();
    supermenu();

return 0;
}

void user_signup()
{
    long int pass;
    char username[size];
    char email[size];
    char phone[size];

    cout<<"\n\n New Username:";
    cin>>username;
    cout<<"\n\n New Password (max. 8 number character):";
    cin>>pass;
    cout<<"\n\n Enter your Email: ";
    cin>>email;
    cout<<"\n\n Enter your Phone number:";
    cin>>phone;
    if(userhead->top==NULL)
    {
        new_user= new users();
        new_user->password= pass;
        strcpy(new_user->username,username);
        strcpy(new_user->email,email);
        strcpy(new_user->phone, phone);
        new_user->next=NULL;
        userhead->top=new_user;

    }
    else
    {
        new_user= new users();
        new_user->password=pass;
        strcpy(new_user->username,username);
        strcpy(new_user->email,email);
        strcpy(new_user->phone, phone);
        new_user->next=userhead->top;
        userhead->top=new_user;

    }
    userhead->count++;
    cout<<"\n\n USER signup SUCCESSFULL!!\n\n";
    system("PAUSE");
    supermenu();



}
void print_user()
{
    int n=1;
    new_user=userhead->top;
    if(userhead->top == NULL)
        cout<<"NO USERS AVAILABLE";
    else
    {
        cout<<"\n\nUSERS:\n\n";
        while(new_user!= NULL)
        {
           cout<<n<<":\n\n";
           cout<<new_user->username<<endl<<endl;
           cout<<new_user->password<<endl<<endl;
           new_user= new_user->next;
           n++;
        }
    }


}
void administration()
{
    long int adminpass;
    char admin[size];
    cout<<"\n\n Enter Username: ";
    cin>>admin;
    cout<<"\n\n Enter Password: ";
    cin>>adminpass;
    if(adminhead->top==NULL)
        cout<<"\n Program Error\n";
    else
    {
        while(new_admin!=NULL)
        {
            if(strcmpi(admin,new_admin->username)==0 && adminpass==new_admin->password)
            {
                clrscr();
                cout<<"\n\n\n\t\t\t\t WELCOME "<<admin<<"\t\t\t\t\n\n\n";
                admin_available_flights();
            }
            else
            {
                cout<<"\n\n Wrong Username or Password!!\n\n";
                system("PAUSE");
                clrscr();
                supermenu();
            }
        }
    }
}

void admin_available_flights()
{
    int t=1;
    int choice;
    new_ticket=tickethead->top;
    if(tickethead->top == NULL)
        cout<<"\n\n NO Ticket AVAILABLE!!!\n\n";
    else
    {
        cout<<"\n\n Flights:\n\n";
        while(new_ticket!= NULL)
        {

           cout<<t<<":\n";
           cout<<"\n Ticket ID: "<<new_ticket->id<<endl<<endl;
           cout<<"\n From: "<<new_ticket->start<<endl<<endl;
           cout<<"\n To: "<<new_ticket->destination<<endl<<endl;
           cout<<"\n Flight Date: "<<new_ticket->day<<"/"<<new_ticket->month<<"/"<<new_ticket->year<<endl<<endl;
           cout<<"\n Flight Time: "<<new_ticket->flight_time<<endl<<endl;
           cout<<"\n Departure Time: "<<new_ticket->dep_time<<endl<<endl;
           cout<<"\n Carrier: "<<new_ticket->plane<<endl<<endl;
           cout<<"\n Price:"<< new_ticket->price<<endl<<endl;
           cout<<"\n Available seats:"<< new_ticket->quantity<<endl<<endl;
           new_ticket= new_ticket->next;
           t++;
        }
    }


        cout<<"\n\n\n\n";
        system("PAUSE");
        clrscr();
        cout<<"\n\n ADD TICKETS??\n\n 1=Yes\n 0=NO\n\n";
        cin>>choice;
        if(choice==1)
        {
        clrscr();
        add_flight();
        }
        if(choice==0)
        {
        clrscr();
        supermenu();
        }

    }

void user()
{
    long int userpass;
    char usern[size];
    cout<<"\n\n Enter Username: ";
    cin>>usern;
    cout<<"\n\n Enter Password: ";
    cin>>userpass;
    if(userhead->top==NULL)
    {
        cout<<"\n\n Signup As A user Today!!\n\n";
        system("PAUSE");
        clrscr();
        supermenu();
    }
    else
    {
        while(new_user!=NULL)
        {
            if(strcmpi(usern,new_user->username)==0 && userpass==new_user->password)
            {
                clrscr();
                cout<<"\n\n\n\t\t\t\t WELCOME "<<usern<<"\t\t\t\t\n\n\n";
                cout<<"\n Press 1 to see your Booking Status\n\n";
                cout<<" Press 2 to see Available Flights:";
                cout<<"\n\n Press 3 to go Back to Main Menu!";
                int choice;
                cin>>choice;
                switch(choice)
                {
                case 1:
                    clrscr();
                    user_status();
                    break;
                case 2:
                    clrscr();
                    user_available_flights();
                    break;
                case 3:
                    clrscr();
                    supermenu();
                    break;


                default:
                    cout<<"\n\n Wrong Choice!!\n\n Log in Again to continue";
                    system("PAUSE");
                    supermenu();
                    break;


                }

            }
            else
            {
                cout<<"\n\n Wrong Username or Password!!\n\n";
                system("PAUSE");
                supermenu();
            }
        }
    }
}

void user_status()
{
    long int userpass;
    char usern[size];
    cout<<"\n\n Enter Username: ";
    cin>>usern;
    cout<<"\n\n Enter Password: ";
    cin>>userpass;

    cout<<"\n\n\t\t\t\t WELCOME "<<usern<<"\t\t\t\t\n\n\n";
    long int totalexpend;

    new_user=userhead->top;

        while(new_user!= NULL)
        {
            if(strcmpi(usern, new_user->username)==0)
            {
                cout<<"\n\n Dear "<<usern<<",\n\n";
           cout<<"\n\n You Have Booked This Ticket: \n\n";
           cout<<"Your Username: "<<new_user->username<<endl<<endl;
           cout<<"\n\n From: "<<new_user->start;
           cout<<"\n\n To: "<<new_user->destination;
           cout<<"\n\n Carrier: "<<new_user->plane;
           cout<<"\n\n Date: "<<new_user->day<<"/"<<new_user->month<<"/"<<new_user->year;
           cout<<"\n\n Flight Time: "<<new_user->flight_time;
           cout<<"\n\n Departure Time: "<<new_user->dep_time;
           cout<<"\n\n Flight Type: "<<new_user->type;
           cout<<"\n\n Ticket Price: "<<new_user->price;
           totalexpend=new_user->price*new_user->quantity;
           cout<<"\n\n Quantity of Seat booked: "<<new_user->quantity<<endl<<endl;
           cout<<" Total Expenditure: "<<totalexpend<<endl<<endl;
           new_user=new_user->next;
            }
        }

        cout<<"\n\n\n RETURN TO MAIN MENU!!\n\n\n";
        system("PAUSE");
        clrscr();
        supermenu();
    }
void user_available_flights()
{
    char from[size], to[size];
    cout<<"\n\n\n To Book a Ticket Please type your Present Location & Where you want to go:\n\n\n";
    cout<<" Present Location:";
    cin>>from;
    cout<<" Destination:";
    cin>>to;
    int t=1;
    int choice;
    new_ticket=tickethead->top;
    if(tickethead->top == NULL)
    {
        cout<<"\n\n NO Tickets AVAILABLE!!!\n\n\n";
        system("PAUSE");
        clrscr();
        supermenu();
    }
    else
    {
        cout<<"\n\n Available Flights:\n\n";
        while(new_ticket!= NULL)
        {
            if(strcmpi(from, new_ticket->start)==0 && strcmpi(to, new_ticket->destination)==0)
            {
                cout<<"\n===========================================================================================================================================================================================\n\n";
           cout<<t<<":\n";
           cout<<"\n Ticket ID: "<<new_ticket->id<<endl<<endl;
           cout<<"\n From: "<<new_ticket->start<<endl<<endl;
           cout<<"\n To: "<<new_ticket->destination<<endl<<endl;
           cout<<"\n Flight Date: "<<new_ticket->day<<"/"<<new_ticket->month<<"/"<<new_ticket->year<<endl<<endl;
           cout<<"\n Flight Time: "<<new_ticket->flight_time<<endl<<endl;
           cout<<"\n Departure Time: "<<new_ticket->dep_time<<endl<<endl;
           cout<<"\n Carrier: "<<new_ticket->plane<<endl<<endl;
           cout<<"\n Price:"<< new_ticket->price<<endl<<endl;
           cout<<"\n Available seats:"<< new_ticket->quantity<<endl<<endl;
           new_ticket= new_ticket->next;
           t++;
            }

        }
    }


        cout<<"\n\n\n\n";

        cout<<"\n Memorize a ticket ID to Book.\n\n\n";
        system("PAUSE");
        clrscr();
        cout<<"\n\n Want to Book a ticket?\n\n 1)YES\n\n 2)NO";
        cin>>choice;
        switch(choice)
        {
        case 1:
            clrscr();
            book_ticket();
            break;
        case 2:
            clrscr();
            cout<<"\n\n Please Log in Again to continue\n\n";
            user();
            break;
        default:
            cout<<"\n\n\n INVALID KEY \n\n\n";
            system("PAUSE");
            clrscr();
            supermenu();
        }

}

void book_ticket()
{
    long int userpass;
    char usern[size];

    new_ticket=tickethead->top;
    new_user=userhead->top;
    char start[size];
    char destination[size];
    char plane[size];
    char type[size];
    int price;
    int quantity;
    int id;
    int flight_time;
    int day;
    int month;
    int year;
    int dep_time;

    cout<<"\n\n\t\t\t Ticket Booking \t\t\t\n\n\n\n";
    cout<<"Enter Ticket ID: ";
    cin>>uid;
    cout<<"\n\n How many of this ticket you want to book?";
    cin>>userquantity;
    clrscr();
    cout<<"\n\n\n\n Type your Username and Password to Confirm:\n\n";
    cout<<" Username:";
    cin>>usern;
    cout<<"\n\n Password:";
    cin>>userpass;

    while(new_ticket!=NULL)
    {
        if(uid==new_ticket->id)
        {
            day=new_ticket->day;
            month=new_ticket->month;
            year=new_ticket->year;
            strcpy(start,new_ticket->start);
            strcpy(destination,new_ticket->destination);
            strcpy(type,new_ticket->type);
            strcpy(plane,new_ticket->plane);
            flight_time=new_ticket->flight_time;
            dep_time=new_ticket->dep_time;
            price=new_ticket->price;
            new_ticket->quantity=new_ticket->quantity-userquantity;
            new_ticket=new_ticket->next;

        }
    }

    while(new_user!=NULL)
    {
        if(strcmpi(usern, new_user->username)==0 && userpass==new_user->password)

            {
                new_user->day=day;
            new_user->month=month;
            new_user->year=year;
            strcpy(new_user->plane,plane);
            new_user->price=price;
            strcpy(new_user->type,type);
            strcpy(new_user->start,start);
            strcpy(new_user->destination,destination);
            new_user->flight_time=flight_time;
            new_user->dep_time=dep_time;
            new_user->quantity=userquantity;
            new_user=new_user->next;
                cout<<"\n\n\n Ticket Booking Success!!\n\n\n";
                cout<<" \n\n Log in and see your status\n\n\n";


            }

    }


    system("PAUSE");
    user_status();


}
void admin_signup()
{
    long int pass;
    char name[size];
    cout<<"\n\n New Username:";
    cin>>name;
    cout<<"\n\n New Password (max. 8 number character):";
    cin>>pass;
    if(adminhead->top==NULL)
    {
        new_admin= new admins();
        new_admin->password= pass;
        strcpy(new_admin->username,name);
        new_admin->next=NULL;
        adminhead->top=new_admin;

    }
    else
    {
        new_admin= new admins();
        new_admin->password=pass;
        strcpy(new_admin->username,name);
        new_admin->next=adminhead->top;
        adminhead->top=new_admin;

    }
    userhead->count++;
    cout<<"\n Sign UP successfull!!\n";
    system("PAUSE");
    clrscr();
    supermenu();

}




void add_flight()
{
    int price, id, stime, dtime, d, m, y;
    char from[size];
    char to[size];
    char  type[size], aeroplane[size];
    cout<<"\n\n Ticket ID: ";
    cin>>id;
    cout<<" \n\n Flight type: ";
    cin>>type;
    cout<<"\n\n Starts From?: ";
    cin>>from;
    cout<<"\n\n Destination?: ";
    cin>>to;
    cout<<"\n\n Carrier?: ";
    cin>>aeroplane;
    cout<<"\n\n  Flight Date? (DD <space> MM <space> YYYY): ";
    cin>>d>>m>>y;
    cout<<"\n\n Flight Time?: ";
    cin>>stime;
    cout<<"\n\n Departure time?: ";
    cin>>dtime;
    cout<<"\n\n Ticket Price: ";
    cin>>price;
    cout<<"\n\n Available seats: ?";
    cin>>tquantity;
    if(tickethead->top==NULL)
    {
        new_ticket= new ticket();
        new_ticket->flight_time= stime;
        new_ticket->dep_time= dtime;
        new_ticket->day= d;
        new_ticket->month= m;
        new_ticket->year= y;
        new_ticket->price=price;
        new_ticket->id=id;
        new_ticket->quantity=tquantity;
        strcpy(new_ticket->type, type);
        strcpy(new_ticket->start,from);
        strcpy(new_ticket->destination,to);
        strcpy(new_ticket->plane,aeroplane);
        new_ticket->next=NULL;
        tickethead->top=new_ticket;

    }
    else
    {
        new_ticket= new ticket();
        new_ticket->flight_time= stime;
        new_ticket->dep_time= dtime;
        new_ticket->day= d;
        new_ticket->month= m;
        new_ticket->year= y;
        new_ticket->price=price;
        new_ticket->id=id;
        new_ticket->quantity=tquantity;
        strcpy(new_ticket->type, type);
        strcpy(new_ticket->start,from);
        strcpy(new_ticket->destination,to);
        new_ticket->next=tickethead->top;
        tickethead->top=new_ticket;

    }
    tickethead->count++;

}
