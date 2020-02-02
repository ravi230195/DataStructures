//
// Created by ravi on 2/1/20.
//

#ifndef ALGORITHMS_ALGORITHMS_H
#define ALGORITHMS_ALGORITHMS_H

#include <iostream>
#include <vector>
using namespace std;
namespace Algorithms
{
    class BinarySearch {
    public:
        static int binanrySearch(vector<int> arr, int ele);
        // index where the given element can be inserted in the array.
        static int findIndexToInsert(vector<int> arr, int ele);
        //Find the first occurance of the element int he sorted array, with duplicates;
        static int firstOccurance(vector<int> arr, int ele);
        //Find the k closest elements in the sorted array;
        static  vector<int> kCloestElements(vector<int> arr, int ele, int k);
        // Find smallest element in the sorted array which is rotated by a value.
        // arr = [1,3,4,5,6,7], arr =[7,8,9,1,2,3]
        static int smallestInRotatedArray(vector<int> arr);
    };
};
#endif //ALGORITHMS_ALGORITHMS_H
