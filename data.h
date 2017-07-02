#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include<iostream>
using namespace std;

struct Data
{
private:
    string name;
    string surname;
    string iban;
    float account_balance;
public:
    string return_name();
    string return_iban();
    string return_surname();
    float return_balance();
    void set_name(string _name);
    void set_iban(string _iban);
    void set_surname(string _surname);
    void set_balance(float _balance);
    void view();



};


#endif // DANE_H_INCLUDED
