#include "QuickSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    int mid = (left+right)/2;
    if (data[left] > data[mid]) {
        if (data[mid] > data[right]) {
            swap(mid,left);    
        } 
        else if (data[left] > data[right]) {
            swap(right,left);   
        } 
        else {
            swap(left,left);
        }
    } 
    else {
        if (data[left] > data[right]) {
            swap(mid,left);  
        } 
        else if (data[mid] > data[right]) {
            swap(right,left);   
        } 
        else {
            swap(right,left);  
        }
    }
    return data[left];
   
}
