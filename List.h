#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
using namespace std;

///creating a class for the list
class List
{
    ///declaring a structure for node elements
    struct node{
        int value;
        node *next;
    }*first, *last;

public:
    ///public type for accessing node elements
    typedef node* pNode;

    ///initializing the first and last element with NULL
    List(): first(NULL), last(NULL) {}

    ///copy-constructor + destructor
    List(const List &object);
    ~List();

    ///function for adding a node anywhere in the list
    void addNode(int n);
    pNode getfirst() const;
    pNode getlast() const;

    ///function for displaying the list
    void show(ostream& out, pNode first) const;

    ///function for deleting an element
    void deleteNode(int val);
    void reset();

    ///function for searching an element
    pNode searching(int x) const;

    ///function for counting the elements
    int size() const;

    ///operator overloading
    pNode operator[](int x) const;
    List operator=(const List& object);
    List operator+(const List& object) const;
    List operator*(int number);
    bool operator<(const List& object) const;
    bool operator>(const List& object) const;
    friend ostream& operator<<(ostream& out, const List& object);
    friend istream& operator>>(istream& in, List& object);

    ///function for calculating the sum of the elements
    int elementSum() const;

    ///function for mirror
    void mirror();

    ///functions for minimum and maximum
    pNode maxim() const;
    pNode minim() const;


};
#endif // LIST_H_INCLUDED
