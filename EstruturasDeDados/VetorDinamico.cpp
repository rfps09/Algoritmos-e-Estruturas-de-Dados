#include <iostream>

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

    void reserve(int length) {
        if(index > length) index = length;
        this->length = length;
        tipo *aux = new tipo[length]{0};
        for(int i=0; i<index; i++)
            aux[i]=vetorDinamico[i];
        delete [] vetorDinamico;
        vetorDinamico = aux;
        if(vetorDinamico == NULL) throw invalid_argument("Deu beyblade");
    }

    void resize(int length) {
        if(length > 0) index = length;
        if(length > this->length) {
            while(this->length < length) this->length *=2;
            reserve(this->length);
        }
    }

    void push(tipo element) {
        if(index >= length) reserve(2*length);
        vetorDinamico[index] = element;
        index++;
    }

    void pop() {
        if(index == 0) throw invalid_argument("Ta errado isso ai doidao");
        if(index>0)index--;
    }

    tipo front() {
        if(index == 0) throw invalid_argument("num vai da nao doidao");
        return vetorDinamico[0];
    }

    tipo back() {
        if(index == 0) throw invalid_argument("num vai da nao doidao");
        return vetorDinamico[index-1];
    }

    tipo at(int i) {
        if(i < 0 || i >= index) throw invalid_argument("Ta perdidinho no pagode");
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
        if(i < 0 || i >= index) throw invalid_argument("Ta perdidinho no pagode");
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

    for(int i=0; i < meuVetor.size(); i++) {
        cout << meuVetor[i] << " ";
    }

    cout << endl;
    meuVetor.resize(10);

    for(int i=0; i < meuVetor.size(); i++) {
        cout << meuVetor[i] << " ";
    }

    cout << endl;
    meuVetor.push(10);
    meuVetor.push(11);
    meuVetor.push(12);


    for(int i=0; i < meuVetor.size(); i++) {
        cout << meuVetor[i] << " ";
    }

    return 0;
}