#include "Node.h"
#include "Element.h"

//default constructor
Node::Node(){
    
}

//overloaded coordinate constructor
Node::Node(Element& elmt){
    this->element=elmt;    
}

Node::Node(const Node& orig){
    this->next=orig.next;
}

Node::~Node(){
   delete next;     
}

