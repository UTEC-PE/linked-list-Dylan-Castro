#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"
<<<<<<< HEAD

=======
>>>>>>> e63fce39b868a6f83ef2bb52272892bc15f303b7

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List();

<<<<<<< HEAD
        T front();
        T back();
=======
        int front();
        int back();
>>>>>>> e63fce39b868a6f83ef2bb52272892bc15f303b7
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
<<<<<<< HEAD

template<class T> List<T>::List()
{

    head=NULL;
    tail=NULL;

    nodes=0;

}


template<typename T> T List<T>::front()
{

    return(head->data);

}

template<typename T> T List<T>::back()
{

    return(tail->data);

}

template<typename T> int List<T>::size()
{
    return nodes;
}

template<typename T> bool List<T>::empty()
{
    bool a=true;
    if(head==NULL)
    {
        return a;
    }else{
        return !a;
    }

}

template<typename T> void List<T>::push_front(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data=value;

    if (head==NULL)
    {

        tail=temp;

    }
    temp->next=head;
    head=temp;
    nodes++;
    temp=NULL;
    delete temp;



}
template<typename T> void List<T>::pop_front()
{
    if(head!=tail)
    {
        Node<T>* temp=head;

        temp=head->next;
        head=NULL;
        delete head;
        head=temp;
        temp=NULL;
        delete temp;


    }else{
        head=NULL;
        tail=NULL;
        delete head;
        delete tail;
    }
}
template<typename T> T List<T>::get(int position)
{
    Node<T>* temp=head;
    T rpta;
    for(int x=0;x!=position;x++)
    {

        rpta=temp->data;
        temp=temp->next;
    }
    temp= NULL;
    delete temp;
    return rpta;

}

template<typename T> void List<T>::pop_back()
{

    if(head!=tail)
    {
        Node<T>* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        tail=NULL;
        delete tail;
        tail=temp;
        temp=NULL;
        delete temp;


    }else{
        head=NULL;
        tail=NULL;
        delete head;
        delete tail;
    }
}

template<typename T> void List<T>::push_back(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data=value;
    temp->next=NULL;
    nodes++;
    if (head==NULL)
    {

        head=temp;
    }else{

        tail->next=temp;
    }
    tail=temp;

    temp=NULL;
    delete temp;


}

template<typename T> void List<T>::clear()
{
    if(!empty())
    {
        while(head!=tail)
        {
            pop_front();

        }
        head=NULL;
        delete head;

    }



}


template<typename T> void List<T>::print()
{
    Node<T>* temp=new Node<T>;
    temp=head;
    while(temp!=tail)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
    cout << tail->data<<endl;
    temp=NULL;
    delete temp;
}
template<typename T> void List<T>::print_reverse()
{
    T lista[nodes];
    Node<T>* temp=head;
    int aux=0;
    while(temp!=tail)
    {
        //cout<<temp->data<<endl;
        lista[aux]=temp->data;
        aux++;
        temp=temp->next;

    }
    //cout << tail->data<<endl    ;
    temp=NULL;
    delete temp;

    for(int x=nodes;0<x;x--)
    {
        cout << lista[x-1] << endl;
    }
}
template<class T> List<T>::~List()
{
    clear();

}
=======
>>>>>>> e63fce39b868a6f83ef2bb52272892bc15f303b7
#endif
