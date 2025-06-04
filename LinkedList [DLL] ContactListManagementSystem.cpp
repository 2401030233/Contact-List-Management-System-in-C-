# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
int listSize=0;  //global variable for O(1) time complexity
struct Node
{
    Node *prev;
    int contactID;
    string contactName;
    double phone;
    string email;
    Node *next;
} *head=nullptr, *rear=nullptr;
void createNode (int id, string c, double p, string e)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->contactID=id;
    temp->contactName=c;
    temp->phone=p;
    temp->email=e;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nContact with required data created at position : "<<listSize<<endl;
}
void displayContactListForward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact List is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying contacts (Forward) : ";
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->contactID<<", "<<temp->contactName<<", "<<temp->phone<<", "<<temp->email<<" ] -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void displayContactListBackward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact List is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying contacts (Backward) : ";
        Node *temp=rear;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->contactID<<", "<<temp->contactName<<", "<<temp->phone<<", "<<temp->email<<" ] -> ";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
}
void insert_first (int x, string s, double p, string e)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->contactID=x;
    temp->contactName=s;
    temp->phone=p;
    temp->email=e;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    listSize++;
    cout<<"\nContact with required data inserted at first..\n";
}
void insert_last (int x, string s, double p, string e)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->contactID=x;
    temp->contactName=s;
    temp->phone=p;
    temp->email=e;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nContact with required data inserted at last..\n";
}
void insert_specified (int pos, int x, string s, double p, string e)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for insertion of node!\n";
    }
    else
    {
        if (pos==1)
        {
            insert_first (x, s, p, e);
        }
        else if (pos>1 && pos<=listSize)
        {
            Node *temp=new Node (), *n=head->next, *p=head;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            p->next=temp;
            temp->prev=p;
            temp->next=n;
            n->prev=temp;
            listSize++;
            cout<<"\nInserted contact with required data at position : "<<pos<<endl;
        }
        else if (pos==listSize+1)
        {
            insert_last (x, s, p, e);
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_first ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact list is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        listSize--;
        cout<<"\nDeleted the only contact!\n";
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        temp=nullptr;
        listSize--;
        cout<<"\nDeleted first contact!\n";
    }
}
void delete_last ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact list is empty!\nNothing to delete!\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        listSize--;
        cout<<"\nDeleted the only contact!\n";
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        rear->next=nullptr;
        delete temp;
        temp=nullptr;
        listSize--;
        cout<<"\nDeleted last contact!\n";
    }
}
void delete_specified (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user of deletion of node!\n";
    }
    else
    {
        if (pos==1)
        {
            delete_first ();
        }
        else if (pos>1 && pos<listSize)
        {
            Node *temp=nullptr, *n=head->next, *p=head;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            delete temp;
            temp=nullptr;
            listSize--;
            cout<<"\nDeleted contact at position : "<<pos<<endl;
        }
        else if (pos==listSize)
        {
            delete_last ();
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void searchContactByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact List is empty!\nNothing to search for\n";
    }
    else
    {
        bool flag=0;
        Node *temp=head;
        int i=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->contactID==id)
            {
                flag=1;
                cout<<"\nContact with ID : "<<id<<" found at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nContact NOT found!\n";
        }
    }
}
void searchContactByPosition (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (head==nullptr)
        {
            cout<<"\nALERT : Contact list is empty!\nNothing to search for\n";
        }
        else
        {
            bool flag=0;
            Node *temp=head;
            int i=0;
            while (temp!=nullptr)
            {
                i++;
                if (i==pos)
                {
                    flag=1;
                    cout<<"\nContact with ID : "<<temp->contactID<<" found at position : "<<pos<<endl;
                    break;
                }
                temp=temp->next;
            }
        }
    }
}
void deleteContactByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Contact List is empty!\nNothing to delete\n";
    }
    else
    {
        int i=0;
        bool flag=0;
        Node *temp=head;
        while (temp!=nullptr)
        {
            i++;
            if (temp->contactID==id)
            {
                flag=1;
                delete_specified (i);
                break;
            }
            temp=temp->next;
        }
    }
}
void displayMenu ()
{
    cout<<"\n===================================== [Contact List ] ===================================== \n";
    cout<<"\n1.Create Contact\t   2.Display Contacts (Forward)\t";
    cout<<"    3.Display Contacts (Backward)\n4.Insert at first\t   5.Insert at last\t";
    cout<<"            6.Insert at specified position\n7.Delete first contact\t   8.Delete last contact\t";
    cout<<"    9.Delete pos specified contact\n10.Search contact by ID\t   11.Search contact by position";
    cout<<"    12.Delete contact by ID\n13.Count contact\t   14.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    cout<<fixed<<setprecision (0);
    int ch, pos, id;
    string s, e;
    double p;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput contactID : ";
            cin>>id;
            cout<<"\nInput contact Name : ";
            cin>>s;
            cout<<"\nInput email : ";
            cin>>e;
            cout<<"\nInput phone no. : ";
            cin>>p;
            createNode (id, s, p, e);
            break;
        case 2:
            displayContactListForward ();
            break;
        case 3:
            displayContactListBackward ();
            break;
        case 4:
            cout<<"\nInput contactID : ";
            cin>>id;
            cout<<"\nInput contact Name : ";
            cin>>s;
            cout<<"\nInput email : ";
            cin>>e;
            cout<<"\nInput phone no. : ";
            cin>>p;
            insert_first (id, s, p, e);
            break;
        case 5:
            cout<<"\nInput contactID : ";
            cin>>id;
            cout<<"\nInput contact Name : ";
            cin>>s;
            cout<<"\nInput email : ";
            cin>>e;
            cout<<"\nInput phone no. : ";
            cin>>p;
            insert_last (id, s, p, e);
            break;
        case 6:
            cout<<"\nInput position at which contact is to be inserted : ";
            cin>>pos;
            cout<<"\nInput contactID : ";
            cin>>id;
            cout<<"\nInput contact Name : ";
            cin>>s;
            cout<<"\nInput email : ";
            cin>>e;
            cout<<"\nInput phone no. : ";
            cin>>p;
            insert_specified (pos, id, s, p, e);
            break;
        case 7:
            delete_first ();
            break;
        case 8:
            delete_last ();
            break;
        case 9:
            cout<<"\nInput position of contact to be deleted : ";
            cin>>pos;
            delete_specified (pos);
            break;
        case 10:
            cout<<"\nInput ID of contact to be searched : ";
            cin>>id;
            searchContactByID (id);
            break;
        case 11:
            cout<<"\nInput position of contact to be searched : ";
            cin>>pos;
            searchContactByPosition (pos);
            break;
        case 12:
            cout<<"\nInput ID of contact to be deleted : ";
            cin>>id;
            deleteContactByID (id);
            break;
        case 13:
            cout<<"\nSize of contact List : "<<listSize<<endl;
            break;
        case 14:
        {
            if (head==nullptr)
            {
                cout<<"\nContact list is already empty!\n";
            }
            else
            {
                Node *temp=head;
                while (temp!=nullptr)
                {
                    Node *nxt=temp->next;
                    delete temp;
                    temp=nullptr;
                    temp=nxt;
                }
                cout<<"\nAll contacts deleted!\n";
            }
            cout<<"\n======[ Exiting the program... ]======\n";
            exit (0);
            break;
        }
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=14);
    return 0;
}
