#include <iostream>

using namespace std;
class Node {
    public:
int data;
Node* next;
Node (){
data =0;
next= NULL;
}
};

class Stack {
Node *top;

public :
    Stack (){
    top = NULL;
    }
    bool isEmpty (){
    if (top== NULL )
        return true ;
        else {
            return false ;
        }
    }
    bool isFull(){
    Node *ptr= new Node ();
    if  (ptr==NULL)
        cout << "The stack is full , we cannot add any items"<< endl;
    }
    void  push (int item){
        Node*newnode = new Node();
        newnode->data=  item;
        if (isEmpty()){

        newnode->next = NULL;
        top=newnode;}
            else {

        newnode->next= top;
        top = newnode;

        }

    }
    int pop () {
        int value;
        Node* delptr = top;
        value = top->data;
        top= top->next;
        delete delptr;
        return value;
    }
    void display (){
        Node* temp = top;
        while (temp!=NULL)  {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }

    int peek (){
    return top->data;
    }
    int count (){
        int counter = 0;
        Node* temp = top;
        while (temp!=NULL)  {
        counter++;
            temp=temp->next;
        }
            return counter;
                }
    bool isFound(int item){
     bool found = false;
      Node* temp = top;
        while (temp!=NULL)  {
            if (temp->data==item)
                found = true;
            temp = temp->next;

        }
        return found ;

     }


};

int main()
{
    Stack s;

    int item ;
    for (int i=0 ; i<3;i++){
        cout << "enter items to push "<< endl;
        cin>> item;
        s.push(item);
        s.display();
    }
    cout << s.pop()<< " was deleted from the stack"<<endl;
    s.display();
    cout << s.pop()<< " was deleted from the stack"<<endl;
    s.display();
    cout << "Enter irem to search for"<<endl;
    cin >> item ;
    s.isFound(item);
    if (s.isFound(item))
        cout << "Is Found"<< endl;
    else {
        cout << "Not Found"<<endl;
    }

    return 0;
}
