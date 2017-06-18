#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int d):data(d),next(NULL){}

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }

};
class LinkedList{
public:

    node*head,*tail;

    LinkedList()
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
        else
        {
              node* n=new node(d);
              n->next=head;
              head=n;
        }
    }

    void insert_at_tail(int d)
    {
       if(head==NULL)
       {
           head=tail=new node(d);
       }

       node*n=new node(d);
       tail->next=n;
       tail=n;
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

node*search(int d)
{
    node*ptr=head;
    while(ptr)
    {
        if(ptr->data==d)
        {
            return ptr;
        }
        else
            ptr=ptr->next;
    }

    return NULL;
}
void delete_at_front()
{
    node*ptr=head;
    head=head->next;
    ptr->next=NULL;
    delete ptr;
}

void delete_at_tail()
{
    node*prev=head;
    while(prev->next!=tail)
    {
        prev=prev->next;

    }
    delete tail;
    prev->next=NULL;
    tail=prev;

}
int getLength()
{
    int l=0;
    node*ptr=head;
    while(ptr)
    {
        ptr=ptr->next;
        l++;
    }

    return l;
}
void delete_in_middle(int p)
{
    if(p==0)
    {
        delete_at_front();
    }
    else if(p>=getLength())
    {
        delete_at_tail();
    }
    else{
        node*ptr=head;
        for(int i=1;i<p;i++)
        {
            ptr=ptr->next;
        }

        node*n=ptr->next;
        ptr->next=n->next;
        n->next=NULL;
        delete n ;
    }
}
node* middle_of_list()
{

    if(head==NULL&&head->next==NULL)
        return head;

        node*slow =head;
        node*fast=head->next;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }


    return slow;
}

void delete_mid_element()
{
    node*prev=head;
    while(prev->next!=middle_of_list())
    {
        prev=prev->next;
    }
    node*temp=prev->next;
    prev->next=prev->next->next;
    temp->next=NULL;
    delete temp;
}

void  reverse_list()
{
    if(head==NULL||head->next==NULL)
        return ;
    node*prev=NULL;
    node*current=head;
    node*next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    head=prev;
}
void bubble_sort()
{
    int n=getLength();

    for(int i=0;i<=n-2;i++)
    {
        node*prev=NULL;
        node*current=head;
        node*N;

        while(current!=NULL&&current->next!=NULL)
        {
            if(current->data>current->next->data)
            {
            if(prev==NULL)
            {
                N=current->next;
                current->next=N->next;
                N->next=current;
                prev=N;
                head=N;
            }
            else{
                N=current->next;
                current->next=N->next;
                N->next=current;
                prev->next=N;
                prev=N;
            }
            }
            else
            {
                prev=current;
                current=current->next;

            }
        }
    }
}

void rec_bubble_sort(node*head,int j,int n)
{
    node*current=head;
    if(n==1)
        return;
    if(j==n-1)
        return rec_bubble_sort(head,0,n-1);
    if(current->data>current->next->data)
    {

    }
}
void remove_duplicates()
{
    if(head==NULL||head->next==NULL)
    {
        return;
    }

    else
    {
        node* current=head;
        while(current!=NULL&&current->next!=NULL)
        {
            if(current->data==current->next->data)
            {
                node*ptr=current->next;
                current->next=current->next->next;
                ptr->next=NULL;
                delete ptr;
            }
            else
                current=current->next;
        }
    }
}

node* merge(node*a,node*b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node*newhead;
    if(a->data<b->data)
    {
        newhead=a;
        newhead->next=merge(a->next,b);
    }
    else
    {
        newhead=b;
        newhead->next=merge(a,b->next);
    }

    return newhead;

}
};
int  main()
{
    LinkedList l;
    l.insert_at_front(2);
    l.insert_at_front(4);
    l.insert_at_front(6);
    l.insert_at_front(8);
    l.insert_at_front(10);
    l.insert_at_front(12);
    l.bubble_sort();
    LinkedList l1;
    l1.insert_at_front(1);
    l1.insert_at_front(3);
    l1.insert_at_front(5);
    l1.insert_at_front(7);
    l1.insert_at_front(9);
    l1.bubble_sort();
        l.print();
    cout<<endl;
    l1.print();
    cout<<endl;

    LinkedList l2;
    l2.head=l2.merge(l.head,l1.head);
     l2.print()

    ;

}
