#ifndef LISTA_H
#define LISTA_H

#include "list.h"
#include "link.h"

template <typename E>
class Lista : public List<E>
{
public:
    Link<E> *head;
    Link<E> *tail;
    int current;
    int size;

    Lista(){
        this->head = 0;
        this->tail = 0;
        this->current = 0;
        this->size = 0;
    }

    Lista(const Lista&){
        this->head = 0;
        this->tail = 0;
        this->current = 0;
        this->size = 0;
    }

    ~Lista(){
        delete(this);
    }

    void clear(){
        Link<E> *aux = new Link<E>;
        aux = this->head;
        for(int i = 0; i < this->size; ++i, aux = aux->next){
            Link<E> *linkRemove = new Link<E>;
            delete(linkRemove);
        }
        this->current = 0;
        this->size = 0;
    }

    void insert(const E& item){
        Link<E> *newLink = new Link<E>(item);
        Link<E> *aux = new Link<E>;

        if(this->size == 0){
            this->head = newLink;
            this->tail = newLink;
        }
        else{
            if(this->current == 0){
                newLink->next = this->head;
                this->head = newLink;
            }
            else{
                for(int i = 0; i < this->current; ++i, aux = aux->next){
                    newLink->next=aux->next;
                    aux->next=newLink;
                }
            }
        }
        this->size++;
    }

    void append(const E &item){
        Link<E> *newLink = new Link<E>(item);
        this->tail->next = newLink;
        this->tail = newLink;
        this->size++;
    }

    E remove(){
        E element;
        Link<E> *linkRemove = new Link<E>;
        Link<E> *aux = new Link<E>;

        if (this->current == 0){
            linkRemove = this->head;
            this->head = linkRemove->next;
            element = linkRemove->element;
            delete(linkRemove);
            return element;
        }
        else{
            aux = this->head;
            if (this->current == this->size - 1){
                for(int i = 0; i < this->current; ++i, aux = aux->next){
                    if(aux->next == this->tail){
                        linkRemove = this->tail;
                        element = this->tail->element;
                        this->tail = aux;
                        delete(linkRemove);
                        return element;
                    }
                }

            }
            else{
                for(int i = 0; i < this->current; ++i, aux = aux->next){
                    if(i == this->current - 1){
                        linkRemove = aux->next;
                        element = linkRemove->element;
                        aux->next = aux->next->next;
                        delete(linkRemove);
                        return element;
                    }
                }
            }
        }
       this->size--;
    }

    void moveToStart(){
        this->current = 0;
    }

    void moveToEnd(){
        this->current = this->size - 1;
    }

    void prev(){
        if(this->current != 0){
            this->current--;
        }
    }

    void next(){
        if(this->current != this->size - 1){
            this->current++;
        }
    }

    int length() const{
        return this->size;
    }

    int currPos() const{
        return this->current;
    }

    void moveToPos(int pos){
        this->current = pos;
    }

    const E &getValue() const{
        Link<E> *aux = new Link<E>;
        aux = this->head;
        for(int i = 0; i <= this->current; ++i, aux = aux->next)
        {
            if(i == this->current)
            {
                return aux->element;
            }
        }
    }

    void bubbleSort()
        {

            for(int j=0; j<this->size-1;j++)
            {
                Link<E> *aux1 = this->head;
                for(int i = 0; i < this->size - 1; ++i)
                {
                    Link<E> *aux2 = aux1->next;
                    if(aux1->element > aux2->element)
                    {
                        int aux = aux1->element;
                        aux1->element = aux2->element;
                        aux2->element = aux;
                    }
                    aux1 = aux1->next;
                }
            }
        }
};

#endif // LISTA_H
