#include <iostream>
#include "Algorithms.h"

namespace {
    void print(vector<int> arr)
    {
        for(auto i:arr )
            cout<<i<<" ";
        cout<<endl;
    }
}


using namespace Algorithms;
int main() {
    std::cout << "Binary Search Variants !!!!!" << std::endl;

    vector<int> arr{1,3,4,6,8,8,8,99,100,563,566,888};
    int index = BinarySearch::binanrySearch(arr, 100);
    cout<<index<<endl;

    index = BinarySearch::findIndexToInsert(arr, 0);
    cout<<index<<endl;
    index = BinarySearch::findIndexToInsert(arr, 5);
    cout<<index<<endl;
    index = BinarySearch::findIndexToInsert(arr, 566);
    cout<<index<<endl;

    index = BinarySearch::firstOccurance(arr, 8);
    cout<<index<<endl;
    index = BinarySearch::firstOccurance(arr, 899);
    cout<<index<<endl;

    vector<int> elements = BinarySearch::kCloestElements(arr, 0, 4);
    print(elements);
    elements = BinarySearch::kCloestElements(arr, 999, 4);
    print(elements);
    elements = BinarySearch::kCloestElements(arr, 567, 4);
    print(elements);
    elements = BinarySearch::kCloestElements(arr, 2, 4);
    print(elements);
    elements = BinarySearch::kCloestElements(arr, 9, 1);
    print(elements);

    vector<int> arrR{100,563,566,888,3,4,6,8,8,8,99};
    int smallest = BinarySearch::smallestInRotatedArray(arrR);
    cout<<smallest<<endl;
    smallest = BinarySearch::smallestInRotatedArray(arr);
    cout<<smallest<<endl;
    return 0;
}
