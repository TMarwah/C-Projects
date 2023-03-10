#include "minFunc.h"

const int * min(const int arr[], int arrSize){
    if (arrSize <= 1){
        //size one array means first element is min, return the pointer to it
        return arr;
    }
    else{
        //set min val to be the pointer of the last val
        const int *m = min(arr, arrSize - 1);
        //if current last val is less than previous min, reassign new m to be the address of that val
        if(arr[arrSize-1] < *m){
            return &arr[arrSize-1];
        }
        else{
        //otherwise set *m to be m once again.
            return m;
        }
    }
}