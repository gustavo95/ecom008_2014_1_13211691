#ifndef FILA_H
#define FILA_H

#include "queue.h"
#include "link.h"

template <typename E>
class fila : public Queue<E>
{
public:
    Link<E> *head ;
    Link<E> *tail ;
    int size;
    fila(){
        this->head=0;
        this->tail=0;
        this->size=0;
    }

    fila(const fila&){
        this->head=0;
        this->tail=0;
        this->size=0;
    }

    void clear(){
        Link<E> *aux = this->head;
        for(int i = 0; i < this->size; ++i){
            Link<E> *linkRemove = aux;
            aux = aux->next;
            delete(linkRemove);
        }
        this->size=0;
    }

    void enqueue(const E& it){
        Link<E>* linkNew = new Link<E>(it, 0);
        if(this->size == 0){
            this->head = linkNew;
            this->tail = linkNew;
        }
        else{
            this->tail->next = linkNew;
            this->tail = this->tail->next;
        }
        this->size++;
    }

    E dequeue(){
        E it = this->head->element;
        if(this->size != 1){
            this->head = this->head->next;
        }
        else{
            this->head = 0;
            this->tail = 0;
            this -> size = 0;
        }

        this->size--;
        return it;
    }


    const E& frontValue() const
    {
        return this->head->element;
    }
    int length() const
    {
        return this->size;
    }

};

#endif // FILA_H
