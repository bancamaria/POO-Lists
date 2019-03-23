#include <iostream>
#include "List.h"
#include <assert.h>

using namespace std;

///copy-constructor
List::List(const List &object){
    first = last = NULL;
    if(object.first == NULL)
        return;
    pNode currentNode = object.first;
    do{
        addNode(currentNode->value);
        currentNode = currentNode->next;
    }while(currentNode != object.first);
}
///Destructor
List::~List(){this->reset
///First element getter
List::pNode List::getfirst(){return first;}
///Last element getter
List::pNode List::getlast(){return last;}

///function for adding a node anywhere in the list
void List::addNode(int n){
    node *tmp = new node;
    assert(tmp != NULL);
    tmp->value = n;
    tmp->next = NULL;
    if(first == NULL){
        first = tmp;
        last = tmp;
        last->next = first;
    }
    else{
        last->next = tmp;
        last = last->next;
        last->next = first;
    }
}

///function for displaying the list
void List::show(ostream& out, pNode current) const{
   if(current == NULL){
        out << "NULL \n";
        return;
    }
    out << current->value << ' ';
    current = current->next;
    if(current != first)
        show(out, current);
}

///function for deleting an element
void List::deleteNode(int val){
    if(first == NULL)
        return;
    pNode currentNode, previousNode;
    if(first->value == val){
        currentNode = first;
        first = first->next;
        last->next = first;
        delete currentNode;
    }
    else{
        previousNode = first;
        while(previousNode->next->value != val){
            previousNode = previousNode->next;
            if(previousNode == first)
                break;
        }
        currentNode = previousNode->next;
        previousNode->next = currentNode->next;
        if(currentNode == last){
            last = previousNode;
            last->next = first;
        }
        delete currentNode;
    }
}

void List::reset(){
    if(first == NULL)
        return;
    while(first != last){
        pNode currentNode = first;
        first = first->next;
        last->next = first;
        delete currentNode;
    }
    delete first;
    first = last = NULL;
}

///function for searching an element
List::pNode List::searching(int x) const{
    if(first->next == NULL)
        return NULL;
    List::pNode current = first->next;
    while(current->value != x){
        current = current->next;
        if(current == first)
            return NULL;
    }
    return current;
}

///function for counting up the elements
int List::size() const{
    int nr = 0;
    if(first == NULL)
        return nr;
    pNode currentNode = first;
    do{
        nr++;
        currentNode = currentNode->next;
    }
    while(currentNode != first);
    return nr;
}

///function to access element at position x from start; starting from 0; operator[] overload
List::pNode List::operator[](int x) const{
    if(x >= size())
        return NULL;
    int poz = 0;
    pNode currentNode = first;
    while(poz < x){
        ++poz;
        currentNode = currentNode->next;
    }
    return currentNode;
}

///operator= overload
List List::operator=(const List& object){
    if(this == &object)
        return *this;
    reset();
    if(object.first == NULL)
        return *this;
    pNode currentNode = object.first;
    do{
        addNode(currentNode->value);
        currentNode = currentNode->next;
    }
    while(currentNode != object.first);
    return *this;
}

///operator+ overload
List List::operator+(const List& object) const{
    if(object.first == NULL)
        return *this;
    List Reunion = *this;
    pNode currentNode = object.first;
    do{
        Reunion.addNode(currentNode->value);
        currentNode = currentNode->next;
    }
    while(currentNode != object.first);
    return Reunion;
}

///function to calculate the sum of the elements
int List::elementSum() const{
    int sum = 0;
    if(first == NULL)
        return sum;
    pNode currentNode = first;
    do{
        sum += currentNode->value;
        currentNode = currentNode->next;
    }
    while(currentNode != first);
    return sum;
}

///operator<< overload for printing
ostream& operator<<(ostream& out, const List& object){
    object.show(out, object.first);
    out << '\n';
    return out;
}

///operator>> overload for reading
istream& operator>>(istream& in, List& object){
    int elementNo;
    in >> elementNo;
    for(int i = 0; i < elementNo; i++){
        int element;
        in >> element;
        object.addNode(element);
    }
    return in;
}

///operator< overload using sum-comparison
bool List::operator<(const List &object) const{
    if(this->elementSum() < object.elementSum())
        return true;
    return false;
}

///operator> overload using sum-comparison
bool List::operator>(const List &object) const{
    if(this->elementSum() > object.elementSum())
        return true;
    return false;
}

///operator* overload; scalar multiplication
List List::operator*(int number){
    if(first == NULL)
        return *this;
    List multiplication = *this;
    pNode currentNode = multyplication.first;
    do{
        currentNode->value = currentNode->value * number;
        currentNode = currentNode->next;
    }while(currentNode != multiplication.first);
    return multiplication;
}

///function to mirror the list (a b c -> c b a)
void List::mirror(){
    for(int i = 0; i < size() / 2; i++)
        swap((*this)[i]->value, (*this)[size() - i - 1]->value);
}

///function to get the maximum element
List::pNode List::maxim(List &object) const{
    List::pNode maxim = object[0];
    for(int i = 0; i < object.size(); i++)
        if(object[i]->value > maxim->value)
            maxim = object[i];
    return maxim;
}

///function to get the minimum element
List::pNode List::minim(List &object) const{
    List::pNode minim = object[0];
    for(int i = 0; i < object.size(); i++)
        if(object[i]->value < minim->value)
            minim = object[i];
    return minim;
}

