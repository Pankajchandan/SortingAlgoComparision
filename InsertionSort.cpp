#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    int firstOutOfOrder, location;
    for (firstOutOfOrder = 1; firstOutOfOrder < data.size(); firstOutOfOrder++){
           Element temp=data[0];
           compare_count++;
           if (data[firstOutOfOrder] < data[firstOutOfOrder - 1]){
                temp = data[firstOutOfOrder];
                location = firstOutOfOrder;
                do
                {   compare_count++;
                    data[location] = data[location - 1];
                    move_count++;
                    location--;
                }while (location > 0 && data[location - 1] > temp);
                data[location] = temp;
            }
        }
}
