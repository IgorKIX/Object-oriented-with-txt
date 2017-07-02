#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include"data.h"
#include"container.h"

using namespace std;

void pobierz(struct Container *everyone)
{
    Data customer;

    float changef;
    string change;
    string change2;
    string space;
    char lack[] = {"LACK"};

    string allPurpose;

    fstream file;
    fstream file2;
    file.open("data.txt", ios::in);
    file2.open("operations.txt", ios::in);
    if(file.good()==true && file2.good()==true)
    {
        while(!file.eof())
        {
            getline(file, allPurpose);
            fflush(stdin);
            customer.set_iban(allPurpose);
            getline(file, allPurpose, ' ');
            fflush(stdin);
            customer.set_name(allPurpose);
            getline(file, allPurpose);
            fflush(stdin);
            customer.set_surname(allPurpose);
            getline(file, change);
            fflush(stdin);
            changef = atof(change.c_str());
            customer.set_balance(changef);
            getline(file, space);
            fflush(stdin);
            file2>>change2;
            if(change2!=lack)
            {
                getline(file2, change);
                fflush(stdin);
                changef = atof(change.c_str());
            }
            else
            {
                changef = 0;
            }
            everyone->add(customer, change2, changef);
            //customer.wyswietl();
        }
    }
    else
    {
        cout<<"Error during opening file.";
    }
    file.close();
    file2.close();
}
int main()
{
    Container everyone;

    pobierz(&everyone);
    everyone.view();
    everyone.change_account_balance();
    everyone.view();
    everyone.move_to_file();

    return 0;
}
