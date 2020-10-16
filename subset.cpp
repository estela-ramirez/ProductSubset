#include <iostream>
#include<set>
using namespace std;



// Exercise 2

//helper method for findSubset method
void insertionSort(int* arr, int n)  
{  
    
    int insertIndex, key, probeIndex;  
    for (insertIndex = 1; insertIndex < n; insertIndex++) 
    {  
        key = arr[insertIndex];  
        probeIndex = insertIndex - 1;  
  
        while (probeIndex > 0 && arr[probeIndex-1] < key) 
        {  
            arr[probeIndex + 1] = arr[probeIndex];  
            probeIndex = probeIndex - 1;  
        }  
        arr[probeIndex + 1] = key;  
    }  
} 


/* Given an array A of n integers and an integer s, find a subset of the integers in A such that their product is s. 

Asymptotic complexity:
O(n^2)
Θ(n^2)
Ω(n^2) */

set<int> findSubset(int arr[], int size, int s){
    set<int> multiples;
    set<int> returnSet;
    int * sortedMultiples;
    int length, index = 0;
    int copy = s;

    
    for (int i = 0; i < size; i++){
        int num = arr[i];
        if (s%num == 0){             // only if it's a multiple
            multiples.insert(num);
        }
    }
    
    
    // create array of multiples
    length = multiples.size();
    sortedMultiples = new int[length];
    
    
    for(auto it = multiples.begin(); it != multiples.end(); ++it){
        sortedMultiples[index] = *it;
        ++index;
    }
    

    //sort array
    insertionSort(sortedMultiples, length);
   
   
   // find subSet
    for (int i = 0; i < length; ++i){
        copy = s;
        for (auto j = i; j < length; ++j){
            int num = sortedMultiples[j];
            if (num!= 0 && copy% num == 0){
                copy = copy/(num);
                returnSet.insert(num);
                
                if (copy == 1){
                    delete[] sortedMultiples;
                    return returnSet;
                }
                
            }
           
        }
        returnSet.clear();
    }
    
    delete[] sortedMultiples;
    return returnSet;
}


///////////////////////////// del 
int main()
{
    int test[5] = {5,2,-1,4, 10};
    set<int> subSet = findSubset(test, 5, -20);
    if (subSet.size() != 0){
        for (auto it = subSet.begin(); it != subSet.end(); ++it){
            cout << *it << ", ";
        }
    }else{
        cout << "empty" << endl;
    }
    
    return 0;
}