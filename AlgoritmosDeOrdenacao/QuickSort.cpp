#include <iostream>

using namespace std;

const int MAXN = 10;

template <class Random>
void troca(Random &a, Random &b) {
    Random aux = a;
    a = b;
    b = aux;
}

template <class RandomAcessIterator>
void pickPivot(RandomAcessIterator primeiro, RandomAcessIterator ultimo) {
    int len = ultimo-primeiro;
    if(len < 3) return;
    int mid = len/2;
    int j[3] = {0,mid,len-1};

    for(int i=1; i <3; i++) {
        int k = i;
        while(k && primeiro[j[k]] < primeiro[j[k-1]]){
            troca(primeiro[j[k]],primeiro[j[k-1]]);
            k--;
        }
    }

    troca(primeiro[mid], primeiro[len-1]);
}

template <class RandomAccessIterator>
void partition(RandomAccessIterator primeiro, RandomAccessIterator ultimo, int &index) {
    int len = ultimo - primeiro;
    pickPivot(primeiro,ultimo);
    int &pivot = primeiro[len-1];

    for(int i=0; i < len-1; i++) {
        if(primeiro[i] < pivot) {
            troca(primeiro[i], primeiro[index]);
            index++;
        }
    } troca(pivot,primeiro[index]);
}

template <class RandomAccessIterator>
void quickSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    int index = 0;

    if(len > 1) {
        partition(primeiro,ultimo, index);
        quickSort(primeiro,primeiro+index);
        quickSort(primeiro+ ++index, ultimo);
    }
}

//============================================================================================================================
//============================================================================================================================
//============================================================================================================================
//                                                   COMPARER
//============================================================================================================================
//============================================================================================================================
//============================================================================================================================

template <class RandomAccessIterator, class Compare>
void partition(RandomAccessIterator primeiro, RandomAccessIterator ultimo, int &index, Compare Comparer) {
    int len = ultimo - primeiro;
    pickPivot(primeiro,ultimo);
    int &pivot = primeiro[len-1];

    for(int i=0; i < len-1; i++) {
        if(Comparer(primeiro[i],pivot)) {
            troca(primeiro[i], primeiro[index]);
            index++;
        }
    } troca(pivot,primeiro[index]);
}

template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo - primeiro;
    int index = 0;

    if(len > 1) {
        partition(primeiro,ultimo,index,Comparer);
        quickSort(primeiro, primeiro+index,Comparer);
        quickSort(primeiro+ ++index, ultimo,Comparer);
    }
}

int maior(int &a, int &b) {
    return a > b;
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    quickSort(vetorTeste, vetorTeste+MAXN);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}