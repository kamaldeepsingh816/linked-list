#include<iostream>
using namespace std;
class node{
public:

    int data;
    node*next;
    node*prev;
    node(int d):data(d),next(NULL),prev(NULL){}
};

class doubly_linked_list{

    node*head;
    node* tail;
public:
    doubly_linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_at_front(int d)
    {
        if(head==NULL)
        {
            head=tail=new node(d);
        }
        else{
            node*n=new node(d);
            n->next=head;
            n->next->prev=n;
            head=n;

        }
    }

void print()
{
    node*ptr=head;
    while(ptr)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

void print_reverse()
{
    node*ptr=tail;
    while(ptr)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->prev;
    }
}

void insert_at_end(int d)
{
    if(head==NULL)
        head=tail=new node(d);
    else{
        node*n =new node(d);
        n->prev=tail;
        tail->next=n;
        tail=n;
    }
}

void delete_at_beginning()
{
    if(head==NULL)
        return;
    else
    {
        node*ptr=head;
        head=head->next;
        head->prev=NULL;
        delete ptr;

    }
}

};
int main()
{
    doubly_linked_list l;
    l.insert_at_front(5);
    l.insert_at_front(6);
    l.insert_at_front(7);
    l.insert_at_front(8);
    l.insert_at_front(9);
    l.insert_at_end(12);
    l.insert_at_end(54);
    l.print();
    cout<<endl;
    l.print_reverse();
    l.delete_at_beginning();
    cout<<endl;
    l.print();
}
