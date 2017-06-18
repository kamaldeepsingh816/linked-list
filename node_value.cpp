/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    int total_count=0;
    Node*temp=head;
    while(temp->next!=NULL)
    {
        total_count++;
        temp=temp->next;
    }
    Node*ptr=head;
    for(int i=total_count;i>positionFromTail;i--)
    {
        ptr=ptr->next;
    }
    return ptr->data;
    
}
