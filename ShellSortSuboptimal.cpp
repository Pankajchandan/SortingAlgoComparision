#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shell sort algorithm.
 * @throws an exception if an error occurred.
 */
//http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
  int j;
 
  for (int gap = data.size() / 2; gap > 0; gap /= 2)
  {
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
