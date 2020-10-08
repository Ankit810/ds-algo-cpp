#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class llist{
  int val;
  llist *next;
public:
  void insertattheend();
  void removefromtheend();
  void delatthebeginning();
  void insertatthebeginning();
  void insertafter();
  void print();
};

llist *start=NULL;

void llist::insertatthebeginning()
{
    cout<<"ENTER THE ELEMENT TO BE INSERTED..."<<endl;
    llist *temp= new llist;
    cin>>temp->val;
    temp->next=NULL;

    if(start==NULL)
    {
        start=temp;
        return;
    }
    else
    {
        temp->next=start;
        start=temp;
        return;
    }

}

void llist::delatthebeginning()
{
    if(start==NULL)
    {
        cout<<"\nNOTHING CAN BE DELETED AS THE GIVEN LIST IS EMPTY..."<<endl;
        return;
    }
    if(start->next==NULL)
    {
        delete start;
        start=NULL;
        return;
    }
    llist *temp= new llist;
    temp=start;
    start=start->next;
    delete temp;
    return;
}

void llist::removefromtheend()
{
    if(start==NULL)
    {
        cout<<"\nLIST IS EMPTY, NOTHING CAN BE DELETED..."<<endl;
        return;
    }
    if (start->next==NULL)
    {
        delete start;
        start=NULL;
    }
    llist *cur=start;
    while((cur->next)->next!=NULL)
    {
        cur=cur->next;
    }
    delete(cur->next);
    cur->next=NULL;
    return;

}

void llist::insertafter()
{
    llist *temp= new llist;

    cout<<"ENTER THE ELEMENT TO BE INSERTED";
    cin>>temp->val;
    temp->next=NULL;
    int num;

    cout<<"ENTER THE NUMBER AFTER WHICH THE GIVEN ELEMENT SHOULD BE INSERTED..."<<endl;
    cin>>num;

    if(start==NULL)
    {

        cout<<"SINCE THE LIST IS EMPTY, DO YOU WANT TO INSERT IT AS THE STARTING ELEMENT?"<<endl;
        cout<<"ENTER 1 FOR YES, 2 FOR NO"<<endl;
        int n;
        switch(n)
        {
            case 1: cout<<"ELEMENT IS SUCCESSFULLY SET AS THE FIRST ELEMENT OF THE GIVEN LIST..."<<endl;
                    start=temp;
                    return;
            case 2: cout<<"RETURNING BACK TO THE MAIN MENU\n";
                    return;
        }
    }

}

void llist::insertattheend()
{
  llist *temp= new llist;
  temp->next=NULL;
  cout<<"ENTER THE VALUE OF THE NODE TO BE INSERTED AT THE END...";
  cin>>temp->val;

  if(start==NULL)
  {
    cout<<"SINCE THE LIST IS EMPTY, THE ENTERED NODE IS THE FIRST NODE..."<<endl;
    start=temp;
    return;
  }
  if(start->next==NULL)
  {
    start->next=temp;
    return;
  }
  llist *cur=start;
  while(cur->next!=NULL)
  {
    cur=cur->next;
  }
  cur->next=temp;
  return;
}

void llist::print()
{
  if(start==NULL)
  {
    cout<<"THE LIST IS EMPTY...";
    return;
  }
  else
  {
    llist *cur=start;
    while(cur->next!=NULL)
    {
      cout<<cur->val<<"-->";
      cur=cur->next;
    }
    cout<<cur->val;
    return;
  }
}

int main()
{
     int n;
  llist l1;
  do{
  cout<<"\n1. INSERT AT THE END...."<<endl;
  cout<<"2. PRINT"<<endl;
  cout<<"3. EXIT"<<endl;
  cout<<"4. REMOVE FROM THE END..."<<endl;
  cout<<"5. DELETE AT THE BEGINNING..."<<endl;
  cout<<"6. INSERT AT THE BEGINNING..."<<endl;
  cout<<"7. INSERT AFTER A PARTICULAR NODE..."<<endl;
  cout<<"ENTER YOUR CHOICE...";


  cin>>n;
  switch(n)
  {
    case 1: cout<<"\nINSERT AT THE END SELECTED..."<<endl;
            l1.insertattheend();
            break;
    case 2: cout<<"\nPRINT SELECTED..."<<endl;
            l1.print();
            break;
    case 3: return 0;
    case 4: cout<<"\nREMOVE FROM THE END SELECTED..."<<endl;
            l1.removefromtheend();
            break;
    case 5: cout<<"\nDELETE AT THE BEGINNING..."<<endl;
            l1.delatthebeginning();
            break;
    case 6: cout<<"\nINSERT AT THE BEGINNING..."<<endl;
            l1.insertatthebeginning();
            break;
    case 7: cout<<"\nINSERT AFTER A PARTICULAR NODE..."<<endl;
            l1.insertafter();
            break;
  }
}while(n!=3);
  return 0;
}
