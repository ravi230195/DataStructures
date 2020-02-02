//
// Created by ravi on 2/1/20.
//
#include "Algorithms.h"
using namespace Algorithms;


int BinarySearch::binanrySearch(vector<int> arr, int ele) {
    int start = 0;
    int end = arr.size();
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] > ele)
            end = mid - 1;
        else if(arr[mid] < ele)
            start = mid + 1;
        else
            return mid;
    }
    return -1;
}

int BinarySearch::findIndexToInsert(vector<int> arr, int ele) {
    int start = 0;
    int end = arr.size();
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] > ele)
        {
            if (mid == 0 || arr[mid-1] < ele)
                return mid;
            else
                end = mid - 1;
        }
        else if (arr[mid] < ele)
        {
            if (mid == arr.size()-1 || arr[mid+1] > ele)
                return mid+1;
            else
                start = mid + 1;
        }
        else
            return mid;

    }
}


int BinarySearch::firstOccurance(vector<int> arr, int ele) {
    int start = 0;
    int end = arr.size();
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] > ele)
            end = mid - 1;
        else if (arr[mid] < ele)
            start = mid + 1;
        else
        {
            if (arr[mid] != arr[mid-1])
                return mid;
            else
                end = mid -1;
        }
    }
    return -1;
}

vector<int> BinarySearch::kCloestElements(vector<int> arr, int ele, int k) {
    int index = BinarySearch::findIndexToInsert(arr, ele);

    vector<int> result;
    if (index == 0){
        while(k>0)
        {
            result.push_back(arr[--k]);
        }
    }
    else if (index == arr.size()){
        while(k>0)
        {
            result.push_back(arr[--index]);
            k--;
        }
    }
    else {
        int i = index - 1;
        int j = index;
        while (i >= 0 && j < arr.size() && k>0) {
            if (abs(arr[i]-ele)< abs(arr[j]-ele))
            {
                result.push_back(arr[i]);
                i--;
            } else{
                result.push_back(arr[j]);
                j++;
            }
            k--;
        }
        if(k == 0)
            return result;
        else if(i >= 0)
        {
            while(k>0)
            {
                result.push_back(arr[i]);
                i--;
                k--;
            }
        } else{
            while(k>0)
            {
                result.push_back(arr[j]);
                j++;
                k--;
            }
        }
    }
    return result;
}

int BinarySearch::smallestInRotatedArray(vector<int> arr) {
    int start = 0;
    int end = arr.size();
    int high = arr[end-1];
    while(start <= end) {
        int mid = start + (end - start) / 2;
        //cout<<mid<<endl;
        if ((mid == 0 || (mid>0 && arr[mid-1] > arr[mid])))
            return arr[mid];
        else if (arr[mid] < high){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1; //error case
}