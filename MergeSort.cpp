#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    LinkedList list1,list2;
    if(list.get_head()==nullptr||list.get_head()->next==NULL)
        return;
    else{
        list.split(list1,list2);
        mergesort(list1);
        mergesort(list2);
        merge(list,list1,list2);
    }
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)

{
    
    LinkedList buff;
    
    while(!(sublist1.get_head()==nullptr  || sublist2.get_head()==nullptr)){
        if((sublist1.get_head()->element.get_value()<sublist2.get_head()->element.get_value())||
            (sublist1.get_head()->element.get_value()==sublist2.get_head()->element.get_value()))
        {
            this->compare_count++;
            this->move_count++;
            buff.add(sublist1.remove_head());
        }
        else 
        {
            this->compare_count++;
            this->move_count++;
            buff.add(sublist2.remove_head());
        }
    }
    if(sublist1.get_head()==nullptr){
        buff.concatenate(sublist2);
        this->move_count+=sublist2.get_size();
    }
    else if(sublist2.get_head()==nullptr){
        buff.concatenate(sublist1);
        this->move_count+=sublist1.get_size();
    }
    else{
        
    }

    list.set(buff.get_head(),buff.get_tail(),buff.get_size());
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
