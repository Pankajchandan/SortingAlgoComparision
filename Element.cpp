#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    this->value=other.value;
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */

long Element::copy_count=0;
long Element::destructor_count=0;

long Element::get_value() const { return value; }

bool operator > (const Element& el1, const Element& el2){
    if(el1.get_value()>el2.get_value())
        return true;
    else
        return false;
}

bool operator < (const Element& el1, const Element& el2){
    if(el1.get_value()<el2.get_value())
        return true;
    else
        return false;
}

bool operator == (const Element& el1, const Element& el2){
    if(el1.get_value()==el2.get_value())
        return true;
    else
        return false;
}

ostream& operator <<(ostream& out, const Element& el1){
    cout<<el1.get_value();
    return out;
}
