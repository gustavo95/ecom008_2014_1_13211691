#ifndef LINK_H
#define LINK_H

template <typename E> class Link {
public:
E element;
Link *next;

Link(const E& elemval, Link* nextval = 0){
    this->element = elemval;
    this->next = nextval;
    }

Link(Link* nextval = 0) {
    this->next = nextval;
    }
};

#endif // LINK_H
