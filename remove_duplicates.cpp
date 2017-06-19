/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if(head==NULL)
        return head;
    else
    {
        Node*temp=head;
        while(temp&&temp->next)
        {
            if(temp->data==temp->next->data)
            {
                Node*ptr=temp->next;
                temp->next=ptr->next;
                ptr->next=NULL;
                delete ptr;
              
                
            }
            else
                
              temp=temp->next;
           
        }
        
        return head;
    }
}
