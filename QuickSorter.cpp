#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    if (left >= right) {
        return;
    }


    int part = partition(left, right,this->choose_pivot(left,right));
    
   
        quicksort(left, part - 1);
  
        quicksort(part + 1, right);
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && ((data[i] < pivot)||(data[i]==pivot))) {
            i++;
            this->compare_count++;
        }

        while(i <= j && data[j] > pivot) {
            j--;
            this->compare_count++;
        }

        if (i < j) {
            swap(i,j);
        }
    }
    swap(i - 1,left);
    return i - 1;  
}
