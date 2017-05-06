#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string) //http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/

{
   
    static constexpr int gap_sequence[] = {9841,3280,1093,364,121,40,13,4,1} ;

    for( int gap : gap_sequence ) if( gap < data.size() )
    {
        int j;
         for (int i = gap; i < data.size(); ++i)
         {
          
            for (j = i; j >= gap && data[i] < data[j - gap]; j -= gap)
             {
                 this->compare_count++;
                 data[j] = data[j - gap];
             }
            swap(i,j);
         } 
    }
}
