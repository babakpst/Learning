

// Linked list
// Babak Poursartip

#include <iostream>

struct node{
  int data;
  node* next;
};


node* insert(node* head, int data, int n){
  
  std::cout << " inserting " << data << std::endl;
  node* temp1 = new node();
  temp1->data= data;
  temp1->next=NULL;
  if (n == 1 ){
    temp1->next= head;
    head = temp1;
    std::cout << " head done " << std::endl;
    return head; 
  }

  node* temp2 = head;
  for (int i = 0; i< n-2; i++){
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
  return head; 
}

void print(node* head){
  node* temp= head;
  std::cout << " linked list: " <<  std::endl;
  while(temp->next != NULL){
    std::cout << " " << temp->data << std::endl;
  }
std::cout << " End  linked list. " << std::endl;
}

int main(){

  node* head;
  head = NULL;

  head = insert(head, 2,1);
  //print(head);  
  head = insert(head, 3,2);
  //print(head);  
  //head = insert(head, 4,3);
  //print(head);  
  //head = insert(head, 5,4);
  //print(head);

  
  return 0;
}