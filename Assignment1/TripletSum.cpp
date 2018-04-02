#include "TripletSum.h"

// The Following Algorithm has been used:
// Sort the array and iterate the array from left to right
// For each Current Element of the array Try to find the rest of the
// Two Elements using Two Pointer Technique. 

bool TripletSum::checkTargetSum()
{
    // return false if the size is less than 3
    if ( data.size() < 3 )
    {
        return false;
    }
	
    sort(data.begin(), data.end());

    // Iterate the vector from light to right
    for ( int fixedIndex = 0; fixedIndex < data.size() - 2; ++fixedIndex )
    {
        int leftIndex = fixedIndex + 1, rightIndex = data.size() - 1;

        // Sum might overflow, so use long long
        long long int currentSUm = data[fixedIndex] + data[leftIndex] + data[rightIndex];

        while ( leftIndex < rightIndex )
        {
            // If currentSum is equal to targetSum store the values and retur true
            if ( currentSUm == targetSum )
            {
                firstElement  = data[fixedIndex];
                secondElement = data[leftIndex];
                thirdElement  = data[rightIndex];

                return true;
            }

            // If currentSum if less than targetSum then increment leftIndex since we need
            // larger value (data is sorted)
            else if ( currentSum < targetSum )
            {
                ++leftIndex;
            }

            // If currentSum if greater than targetSum then decrement rightIndex since we need
            // smaller value (data is sorted)
            else
            {
                --rightIndex;
            }
        }
    }

    // return false if the targetSum does not exist
    return false;
}
