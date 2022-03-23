#include <iostream>
    
using namespace std;
    
const int MAXN = 10;
    
template <class Random>
void troca(Random &a, Random &b) {
    Random aux = a;
    a = b;
    b = aux;
}
    
template <class RandomAccessIterator>
void heapify(RandomAccessIterator primeiro, RandomAccessIterator ultimo, int index) {
    int len = ultimo - primeiro;
    int left = index*2+1;
    int right = index*2+2;
    int greater = left;

    if(right < len && primeiro[left] < primeiro[right])
        greater = right;
    
    if(left < len && primeiro[greater] > primeiro[index]) {
        troca(primeiro[greater],primeiro[index]);
        heapify(primeiro, ultimo, greater);
    }
}

template <class RandomAccessIterator>
void heap(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro - 1;
    for(int i=len/2; i>=0; i--) {
        heapify(primeiro, ultimo, i);
    }
}

template <class RandomAccessIterator>
void heapSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    heap(primeiro,ultimo);
    for(int i=len-1; i>0; i--){
        ultimo--;
        troca(primeiro[i],primeiro[0]);
        heapify(primeiro,ultimo,0);
    }
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//COMPARER
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

template <class RandomAccessIterator, class Compare>
void heapify(RandomAccessIterator primeiro, RandomAccessIterator ultimo, int index, Compare comparer) {
    int len = ultimo - primeiro;
    int left = index*2+1;
    int right = index*2+2;
    int able = left;

    if(right < len && comparer(primeiro[right],primeiro[left]))
        able = right;
    
    if(left < len && comparer(primeiro[able],primeiro[index])) {
        troca(primeiro[able],primeiro[index]);
        heapify(primeiro, ultimo, able, comparer);
    }
}

template <class RandomAccessIterator, class Compare>
void heap(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare comparer) {
    int len = ultimo - primeiro - 1;
    for(int i=len/2; i>=0; i--) {
        heapify(primeiro, ultimo, i, comparer);
    }
}

template <class RandomAccessIterator, class Compare>
void heapSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare comparer) {
    int len = ultimo - primeiro;
    heap(primeiro,ultimo,comparer);
    for(int i=len-1; i>0; i--){
        ultimo--;
        troca(primeiro[i],primeiro[0]);
        heapify(primeiro,ultimo,0,comparer);
    }
}

int maior(int &a, int &b) {
    return a > b;
}
    
int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};
    
    heapSort(vetorTeste, vetorTeste+MAXN,maior);
    
    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";
    
    return 0;
}