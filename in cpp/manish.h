#ifndef MANISH_H_INCLUDED
#define MANISH_H_INCLUDED
//ALL THE DATA(DATA FIELD) ARE IN INTEGERS.
//IF YOU WANT TO HAVE ANOTHER DATA TYPE OR MULTIPLE DATA FIELDS, YOU CAN CHANGE AS REQUIRED.
//TY.
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

class LinkedList        //EVERYTHING FOR LINKED LIST
{
    struct NodeForLinkedList     //Creating a node of linked list
    {
        int data;
        NodeForLinkedList* link;
    };
    NodeForLinkedList* head = NULL;  //defining Head pointer for linked list
    public:
    void LLInsertAtEnd(int number)    //function to insert node at end of linked list
    {
        NodeForLinkedList* temp = new NodeForLinkedList;
        temp->data = number;
        temp->link = NULL;
        if(head == NULL)
            head = temp;
        else
        {
            NodeForLinkedList* apple = head; //all the name of fruits are secondary temporary variables
            while(apple->link != NULL)
                apple = apple->link;
            apple->link = temp;
        }
    }
    void LLInsertAtBegining(int number)   //to insert at the begining of linked list
    {
        NodeForLinkedList* temp = new NodeForLinkedList;
        temp->data = number;
        temp->link = NULL;
        if (head == NULL)
            head = temp;
        else
        {
            temp->link = head;
            head = temp;
        }
    }
    void LLInsertAtNthPosition(int number, int pos)   //to insert at the nth position in linked list
    {
        NodeForLinkedList* temp = new NodeForLinkedList;
        temp->data = number;
        temp->link = NULL;
        NodeForLinkedList* mango = head;
        if(pos == 1)
        {
            temp->link = head;
            head = temp;
        }
        else
        {
            for(int i=1;i<pos-1;i++)
                mango = mango->link;
            temp->link = mango->link;
            mango->link = temp;
        }
    }
    void LLDelete(int pos)    //to delete a node in linked list
    {
        NodeForLinkedList* temp = head;
        if(pos==1)
        {
            head = temp->link;
        }
        for(int i=0;i<pos-2;i++)
        {
            temp = temp->link;
        }
        NodeForLinkedList* grape = temp->link;
        temp->link = grape->link;
    }
    void LLPrint()    // to print the linked list
    {
        NodeForLinkedList* temp1 = head;
        while(temp1 != NULL)
        {
            cout<<"Data are "<<temp1->data<<"\n";
            temp1=temp1->link;
        }
        delete(temp1);
    }
    void LLReverse()  //to reverse a linked list using loop
    {
        NodeForLinkedList* next = NULL;
        NodeForLinkedList* prev = NULL;
        NodeForLinkedList* current = head;
        while(current != NULL)
        {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        head = prev;
        delete(next);
        delete(prev);
        delete(current);
    }
    void LLSort ()    //for sorting a linked list
    {
        NodeForLinkedList* temp = head;
        for( ; temp->link != NULL ; temp = temp->link)
            for(NodeForLinkedList* watermelon = temp->link ; watermelon->link != NULL ; watermelon = watermelon->link)
                if(temp->data > watermelon->data)
                {
                    int temp1 = watermelon->data;
                    watermelon->data = temp->data;
                    temp->data = temp1;
                }
    }
};

class Stack     //BASIC FUNCTION FOR STACK IMPLEMENTED AS LINKEDLIST
{
    struct node     //node for stack
    {
        long int data;
        node* link;
    };
    node* head = NULL;
public:
    void SPush(int number)      //PUSH FUNCTION FOR STACK
{
    node* temp = new node;
    temp->data = number;
    temp->link = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        temp->link = head;
        head = temp;
    }
}
void SPop()     //POP FUNCTION FOR STACK
{
    node* temp = head;
    head = temp->link;
}
int STop()      //TOP FUNCTION FOR STACK returns the top most INTEGER.
{
    node* temp = head;
    return temp->data;
}
bool SEmpty()       //CHECK WHETHER STACK IS EMPTY OR NOT returns true or false
{
    if(head == NULL)
        return true;
    else
        return false;
}
void SReverse()     //FOR REVERSE THE STACK (basically reversing a linked list
{
    node* next = NULL;
    node* prev = NULL;
    node* current = head;
    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    delete(next);
    delete(prev);
    delete(current);
}
void SPrint()       //PRINTING A LINKED LIST (basically printing a linked list
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<"Data are "<<temp->data<<endl;
        temp = temp->link;
    }
}
int SLength()
{
    node* temp = head;
    int countt = 0;
    while(temp != NULL)
    {
        countt++;
        temp = temp->link;
    }
    return countt;
}
};

#endif // MANISH_H_INCLUDED
