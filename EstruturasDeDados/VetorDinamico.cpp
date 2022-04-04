#include <iostream>
#include <cstring>

using namespace std;

template <typename tipo>
class vetor {
private:
    int length;
    tipo *vetorDinamico;
    int index;

public:
    explicit vetor(int length=2){
        this->index = 0;
        this->length = length;
        vetorDinamico = new tipo[length]{0};
    }

    ~vetor() {
        delete [] vetorDinamico;
    }

    int size() {return index;}

    int capacity() {return length;}

    void resize(int length) {
        this->length = length;
        vetorDinamico = (tipo*)realloc(vetorDinamico,length*(sizeof(tipo)));
        memset(vetorDinamico+index,0,(length-index)*sizeof(tipo));
    }

    void push(tipo element) {
        if(index >= length) resize(2*length);
        vetorDinamico[index] = element;
        index++;
    }

    void pop() {
        if(index>0)index--;

    }

    tipo front() {
        return vetorDinamico[0];
    }

    tipo back() {
        return vetorDinamico[index-1];
    }

    tipo at(int i) {
        return vetorDinamico[i];
    }

    bool empty() {
        return index == 0;
    }

    tipo* begin() {
        return vetorDinamico;
    }

    tipo* end() {
        return vetorDinamico+index;
    }

    tipo operator [] (int i) {
        return vetorDinamico[i];
    }
};

int main() {
    vetor<int> meuVetor;

    meuVetor.push(1);
    meuVetor.push(2);
    meuVetor.push(3);
    meuVetor.push(4);
    meuVetor.push(5);

    for(int i=0; i < meuVetor.capacity(); i++) {
        cout << meuVetor[i] << " ";
    }

    cout << endl;
    meuVetor.resize(2);

    for(int i=0; i < meuVetor.capacity(); i++) {
        cout << meuVetor.at(i) << " ";
    }

    return 0;
}