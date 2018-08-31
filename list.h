#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"


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

        T front();
        T back();
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other); // Falta implementar
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};

template<class T> List<T>::List()
{

    head=NULL;
    tail=NULL;

    nodes=0;

}


template<typename T> T List<T>::front()
{

    return(head->data); // Falta controlar el caso de lista vacía

}

template<typename T> T List<T>::back()
{

    return(tail->data); // Igual al anterior

}

template<typename T> int List<T>::size()
{
    return nodes;
}

template<typename T> bool List<T>::empty()
{
    bool a=true;
    if(head==NULL) // Esto podría hacerse en una línea: return head == NULL;
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
        head=NULL; // No es necesario
        delete head;
        head=temp;
        temp=NULL; // Esto se podría mejorar, lo podemos hablar en clase
        delete temp; 


    }else{
        head=NULL;
        tail=NULL;
        delete head;
        delete tail; // Esto tendría que hacerse antes de igualar a NULL
    }
    // No estás reduciendo los nodos
}
template<typename T> T List<T>::get(int position)
{
    Node<T>* temp=head;
    T rpta;
    for(int x=0;x!=position;x++)
    {

        rpta=temp->data; // Estás igualando en cada paso, no es muy óptimo
        temp=temp->next;
    }
    /*temp= NULL; 
    delete temp; */ // Esto no es necesario, igual que antes
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
        delete tail; // Esto tendría que hacerse antes de igualar a NULL
    }

    // No estás reduciendo la cantidad de nodos
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

    /*temp=NULL;
    delete temp;*/ // Esto no es necesario


}

template<typename T> void List<T>::clear()
{
    if(!empty())
    {
        while(head!=tail) // Te va a faltar borrar el último elemento
        {
            pop_front();

        }
        head=NULL;
        delete head; // Esto está de más 
        // Falta igualar tail a NULL

    }
    // Deberías igualar la cantidad de nodos a 0


}


template<typename T> void List<T>::print()
{
    Node<T>* temp=new Node<T>; // No es necesario darle new a este puntero temporal
    temp=head;
    while(temp!=tail)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
    cout << tail->data<<endl;
    /*temp=NULL;
    delete temp;*/ // Esto está de más
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
    // Va a faltar el último elemento
    //cout << tail->data<<endl    ;
    /*temp=NULL;
    delete temp;*/ // Esto está de más

    for(int x=nodes;0<x;x--)
    {
        cout << lista[x-1] << endl;
    }
}
template<class T> List<T>::~List()
{
    clear();

}
#endif
