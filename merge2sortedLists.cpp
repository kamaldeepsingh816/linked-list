/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(headA==NULL)
        return headB;
    else if(headB==NULL)
        return headA;
    else 
    {
        Node*newHead;
        Node*temp1=headA;
        Node*temp2=headB;
        if(headA->data<headB->data)
        {
            newHead=headA;
            newHead->next=MergeLists(headA->next,headB);
        }
        if(headB->data<headA->data)
        {
            newHead=headB;
            newHead->next=MergeLists(headB->next,headA);
        }
        return newHead;
    }
    
    
        
}
