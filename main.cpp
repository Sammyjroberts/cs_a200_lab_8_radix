/*
 Roberts, Sammy
 CS A200
 November 11, 2016
 
 Lab 8
 */

#include <iostream>
#include <cmath>
#include <algorithm>

int getCurrentDigit(const int value, const int place);

//Number of Keys in the integers, I.E. 123 has 3 1234 has 4
const int NUM_KEYS = 3;
//number of elements in the array
const int NUM_ELEMS = 8;

int main(int argc, const char * argv[]) {
    
    //starting values
    int arr[NUM_ELEMS] = {123,312,400,111,211,555,622,545};
    //array we use to swap
    int arr2[NUM_ELEMS] = {0,0,0,0,0,0,0,0};
    
    for(int k =0; k < NUM_KEYS; k++) {
        int count[10] = {0,0,0,0,0,0,0,0,0,0};
        // find how many of each digit
        for(auto x : arr) {
            count[getCurrentDigit(x, k)] += 1;
        }
        //populate indexes for the new array
        for(int i =1; i < 10; i++) {
            count[i] += count[i-1];
        }
        //emplace indexes
        for(int j = NUM_ELEMS-1; j >=0; j--) {
            int index = getCurrentDigit(arr[j],k);
            count[index]--;
            arr2[count[index]] = arr[j];
        }
        //swap, could be dont with pointers to make more efficent
        std::copy(arr2, arr2+NUM_ELEMS, arr);
    }
    //print result
    for(auto x : arr) {
        std::cout << x << std::endl;
    }
    
}
int getCurrentDigit(const int value, const int place) {
    return (int)(value / pow(10, place)) % 10;
}
