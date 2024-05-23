#include <iostream>

using namespace std;

void buscarMenor(int *array, int left, int right, int &menor){
    if(left >= right){
        return ;
    }

    int mid = (left + right)/2;

    if(array[mid] < menor){
        menor = array[mid];
    }
    buscarMenor(array, left, mid, menor);
    buscarMenor(array, mid + 1, right, menor);
}

int main(){

    int array[8] = {3, 4, 6, 3, 5, 2, 2, 5};
    int menor = 9999999;
    buscarMenor(array, 0, 8-1, menor);
    cout<<menor<<endl;

    return 0;
}