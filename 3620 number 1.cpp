#include <iostream>
#include "stdafx.h"
using namespace std;

/*declare a class CircNode
p is considered the head node */

class CircNode{
    public:
    int data
    CircNode *Next;
}
/*declare the class ClassCircList and set the methods*/
class ClassCircList{
    public:
    void InsertElements(int data);
    void DisplayElements();
}

void ClassCircList::InsertElements(int data){
    CircNode *temp = new CircNode();
    temp->data= data;

    if (p==NULL){
        p =temp;
        temp->Next = p;
    
    }
}

/*if there are elements in the list and set the new node at the end of the list*/

else{
    temp-> Next = p->Next;
    p->Next = temp;
    p=temp;
}

void ClassCircList::DisplayElements(){
    CircNode *temp= new CircNode();
    if(p==NULL){
        cout<<"There are no elements in the list."<<endl;
        return;
    }
    temp = p-> Next;
    cout<<"\n Elements in the list are: ";
    while (temp! =p){
        cout<< temp->data<<"->";
        temp = temp-> Next;
    }
 cout<<p->data;
/*End of displayelements method*/
}

void main(){
    int i, choice, n, element, pos;
    ClassCircuitList objCircular;
    p= NULL;
    cout<<"Enter number of elements to be inserted in Circular Linked list: ";
    cin>>n;
    while(i){
        cin>>element;
        objCircular.InsertElements(element:);
        i++;
    }
 cout<<"Current elements in the linkedlist are: \n";
 objCircular.DisplayElements();
 getch();
}