#include"data.h"

using namespace std;

string Data::return_name()
{
    return name;
}

string Data::return_iban()
{
    return iban;
}

string Data::return_surname()
{
    return surname;
}

float Data::return_balance()
{
    return account_balance;
}

void Data::set_name(string _name)
{
    name = _name;
}

void Data::set_iban(string _iban)
{
    iban = _iban;
}

void Data::set_surname(string _surname)
{
    surname = _surname;
}

void Data::set_balance(float _balance)
{
    account_balance = _balance;
}

void Data::view()
{
    cout<<name<<endl<<surname<<endl<<iban<<endl<<account_balance<<endl;
}
