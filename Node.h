#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    Node();
    Node(Element& elmt);
    Node(const Node& orig);
    virtual ~Node();
    
   // Public pointer to the next node in the list.
    Node *next;
    Element element;
};

#endif /* NODE_H_ */



