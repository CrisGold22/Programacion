#include <iostream>
#include <cmath>

using namespace std;


void merge(int *array, int left, int mid, int right){
    int p, q;

    int longitud1 = (mid + 1) - left;
    int longitud2 = right - mid;

    int array1[longitud1 + 1];
    int array2[longitud2 + 1];

    array1[longitud1] = 99999999;
    array2[longitud2] = 99999999;

    for(int i = left ; i < mid + 1 ; i++){
        array1[i - left] = array[i];
    }
    for(int i= mid +1; i <= right ; i++){
        array2[i - (mid + 1)] = array[i];
    }

    p = q = 0;
    
    for(int i=left ; i <= right ; i++){
        if(array1[p]<array2[q]){
            array[i] = array1[p++];
        }
        else{
            array2[i] = array2[q++];
        }
    }
}

void mergeSort(int *array, int left, int right){

    if(left>=right){
        return;
    }

    int mid = (left + right)/2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);

}

int main(){

    int array[] = {1, 5, 3, 4, 2, 6};

    for(int i=0 ; i < 6 ; i++){
        cout<<array[i]<<endl;
    }
    cout<<endl;

    mergeSort(array, 0, 6-1); 

    for(int i=0 ; i < 6 ; i++){
        cout<<array[i]<<endl;
    }
    cout<<endl;
    
    return 0;
}