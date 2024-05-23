#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int contador(int *array, int left, int mid, int right){

    int izquierda = 0, derecha = 0;

    for(int i=mid; i > left ; i--){
        if(array[i] > array[i-1]){
            izquierda++;
        }
        else{
            break;
        }
    }

    for(int i=mid + 1; i < right ; i++){
        if(array[i + 1] > array[i]){
            derecha++;
        }
        else{
            break;
        }
    }
    return derecha + izquierda;
}

int function(int *array, int left, int right){

    if(left == right){
        return 1;
    }
    int mid = (left + right)/2;

    int izquierda = function(array, left, mid);
    int derecha = function(array, mid + 1, right);

    int valor = contador(array, left, mid, right);

    return max(valor,max(izquierda, derecha));
}

int main(){

    ifstream archivo("datos.txt", ios::in);
    if(not archivo.is_open()){
        cout<<"ERROR datos.txt"<<endl;
        exit(1);
    }

    int casos; archivo>>casos;
    int array[casos]{};

    for(int i=0 ; i<casos; i++){
        archivo>>array[i];
    }

    int cuenta = function(array, 0, casos -1);

    cout<<cuenta<<endl;

    return 0;
}