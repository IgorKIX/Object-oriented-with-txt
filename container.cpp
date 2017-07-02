#include"container.h"
#include<iostream>
#include<fstream>

using namespace std;

Container::Container()
{
    head = NULL;
    counter = 0;
}

Container::~Container()
{
    while(head!=NULL)
    {
        Node *killer = head;
        head = head -> next;
        delete killer;
    }
}

void Container::add(Data _a, string _change, float _change_to)
{
    Node *p = new Node(_a, _change, _change_to);

    if(counter == 0)
    {
        head = p;
    }
    else
    {
        string surname1 = p->a.return_surname();
        string surname2 = head->a.return_surname();
        if(surname1 < surname2)
        {
            p->next = head;
            head = p;
        }
        else
        {
            Node *pred = NULL;
            Node *succ = head;
            while(surname1 > surname2 && succ!=NULL)
            {
                pred = succ;
                succ = succ->next;
                if(succ==NULL) break;
                surname2 = succ->a.return_surname();
            }
            pred -> next = p;
            p -> next = succ;
        }
    }
    counter++;
}

void Container::view()
{
    Node *p = head;

    while(p!=NULL)
    {
        cout<<p->a.return_surname()<<endl;
        cout<<p->a.return_name()<<endl;
        cout<<p->a.return_balance()<<endl;
        cout<<p->a.return_iban()<<endl<<endl;

        p = p -> next;
    }
}

void Container::move_to_file()
{
    Node *p = head;
    fstream file;
    file.open("results.txt", ios::out);

    while(p!=NULL)
    {
        file<<p->a.return_surname()<<" ";
        file<<p->a.return_name()<<endl;
        file<<p->a.return_balance()<<endl;
        file<<p->a.return_iban()<<endl<<endl;

        p = p -> next;
    }
    file.close();
}

void Container::change_account_balance()
{
    Node *p = head;

    float balance;

    while(p!=NULL)
    {
        balance = p->a.return_balance();

        if(p->change=="RECOGNITION")
        {
            p->a.set_balance(balance+p->change_in_account);
        }
        if(p->change=="CHARGE")
        {
            p->a.set_balance(balance-p->change_in_account);
        }
        p = p->next;
    }
}
