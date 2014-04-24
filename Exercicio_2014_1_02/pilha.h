#ifndef PILHA_H
#define PILHA_H

#include "stack.h"

template <typename E>
class pilha : public Stack<E>
{
public:
    E * cell;
    int size;
    int full;

    pilha(const pilha<E>&){
        this->size = 0;
        this->cell = new E[5];
        this->full = 5;
    }

    pilha(){
        this->size = 0;
        this->cell = new E[5];
        this->full = 5;
    }

    void clear(){
        delete(cell);
        this->cell = new E[5];
        this->full = 5;
        this->size = 0;
    }

    void push(const E &it){
        if(this->size < this->full){
            this->cell[this->size] = it;
        }
        else{
            this->cell = (E *) realloc(cell, (this->full + 3)*sizeof(E));
            this->cell[this->size] = it;
            this->full = this->full + 3;
        }
        this->size++;
    }

    E pop(){
        if(this->size != 0){
            this->size--;
        }
        return this->cell[this->size];
    }

    const E& topValue() const{
        return this->cell[this->size - 1];
    }

    int length() const{
        return this->size;
    }
};

#endif // PILHA_H
