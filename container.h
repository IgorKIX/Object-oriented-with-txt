#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

#include"data.h"

using namespace std;

struct Container
{
private:
    struct Node
    {
        Data a;
        float change_in_account;
        string change;
        Node *next;
        Node(Data _a, string _change, float _change_in_account, Node *_next = NULL)
        {
            a = _a;
            change = _change;
            change_in_account = _change_in_account;
            next = _next;
        }
    };
    Node *head;
    int counter;
public:
    Container();
    ~Container();
    void add(Data _a, string _change, float _change_to);
    void view();
    void change_account_balance();
    void move_to_file();
};

#endif // KONTENER_H_INCLUDED
