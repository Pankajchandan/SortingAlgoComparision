#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();
    
    static long copy_count;
    static long destructor_count;
    static long get_copy_count(){return copy_count;}
    static long get_destructor_count(){return destructor_count;}
    static void reset(){copy_count=0;destructor_count=0;}
    long get_value() const;
    
    friend bool operator > (const Element& el1, const Element& el2);
    friend bool operator < (const Element& el1, const Element& el2);
    friend bool operator == (const Element& el1, const Element& el2);
    friend ostream& operator <<(ostream& out, const Element& el1);

private:
    long value;
};

#endif /* DATA_H_ */
