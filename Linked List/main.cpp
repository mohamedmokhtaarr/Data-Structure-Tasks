#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};
class Linkedlist{
public:
    Node *head;

    Linkedlist(){
    head = NULL;
    }

    bool isempty(){
    if (head==NULL)
        return true;
    else
        return false;
    }
    void InsertFirst(int newvalue){
             Node* newnode;
            newnode->data = newvalue;

        if (isempty()){
            newnode->next=NULL;
            head=newnode;
        }
        else {
            newnode->next=head;
            head = newnode;
        }
    }
    void Display (){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    }
    int count (){
        int counter;
    Node *temp = head;
    while(temp != NULL){
    counter++;
    temp = temp->next;
    }
    return counter;
    }
    bool isfound (int item){
        bool found = false;
     Node *temp = head;
    while(temp != NULL){
        if (temp->data==item){
            found = true;
            temp = temp->next;
        }
    }
    return found;
    }
    void InsertBefore (int item , int newvalue){
      if (isempty()){
            InsertFirst(newvalue);

      }
       if (isfound()){
        Node *newnode = new Node();
       newnode->data= newvalue;
       Node *temp = head;
        while(temp != NULL && temp->next->data != item){
            temp = temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
       }
       else
        {cout << "item not found"<<endl;}
    }

    void InsertLast(int newvalue){
        if(isempty())
            InsertFirst(newvalue);
        else {

        }
    Node *temp = head;
    while (temp->next != NULL){
            temp=temp->next;
    }
    Node *newnode = new Node ();
    newnode->data=newvalue;
    temp->next=newnode;
    newnode->next=NULL;
    }

    void delete(int item){
    if (isempty())
        {cout << "Error"<<endl;}
        Node *delptr=head;
    if (head->data==item)
    {
                head = head->next;
                delete delptr;

    }
    else {
        Node *prv = NULL;
        delptr=head;
        while(delptr->data!=item){
            prv = delptr;
            delptr=delptr->next;
        }
        prv->next = delptr->next;
        delete delptr;
    }
    }
};

int main()
{
    Linkedlist lst;
    if (lst.isempty())
       {    cout << "The List Is Empty"<<endl;
       }
    else {
        cout << "The List Contains "<< lst.count() <<endl;
        }
        int item ;
        cout<<"Enter Item To insert"<<endl;
        cin >> item;
        lst.InsertFirst(item);
        lst.Display();

       cout<<"Enter Item To insert"<<endl;
        cin >> item;
        lst.InsertFirst(item);
        lst.Display();

        cout<<"Enter Item To insert"<<endl;
        cin >> item;
        lst.InsertFirst(item);
        lst.Display();

        cout << "The List Contains "<< lst.count() <<endl;

        cout<<"Enter Item To search for"<<endl;
        if (lst.isfound(item))
            cout << "Item Is Found" << endl;
        else {
            cout << "Item Not Found"<< endl;
        }

        int newvalue;
        cout <<  "enter the item and new value to insert "<< endl;
        cin >> item >> newvalue;
        lst.InsertBefore(item,newvalue);
       lst.InsertLast(newvalue)
        lst.Display();




    return 0;
}
