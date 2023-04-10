#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

Multime::Multime() {
	this->size = 0;
    this->max_size = 10;
    this->elements = new TElem[this->max_size];
}


bool Multime::adauga(TElem elem) {
	for(int i=0;i<size;i++)
        if(this->elements[i] == elem)
            return false;
    if(size == max_size){
        max_size *= 2;
        TElem *new_elements = new TElem[max_size];
        for (int i = 0; i < size; ++i)
            new_elements[i] = this->elements[i];
        delete []this->elements;
        elements = new_elements;
    }
    this->elements[this->size++] = elem;
    return true;
}


bool Multime::sterge(TElem elem) {
    for (int i = 0; i < size; ++i) {
        if(elements[i] == elem){
            for(int j=i+1;j<size;j++)
                elements[j-1] = elements[j];
            size--;
            return true;
        }
    }
    return false;
}


bool Multime::cauta(TElem elem) const {
    for(int i=0;i<size;++i)
        if (elements[i] == elem)
            return true;
    return false;
}


int Multime::dim() const {
    return size;
}

bool Multime::vida() const {
    return size == 0;
}

int Multime::diferentaMaxMin() const {
    if(Multime::vida() == 1){
        return -1;
    }
    int min = this->elements[0], max = this->elements[0];
    for(int i=1;i<size;i++)
    {
        if(min>this->elements[i])
            min = this->elements[i];
        if(max<this->elements[i])
            max = this->elements[i];
    }
    return max-min;
}

Multime::~Multime() {
	delete []this->elements;
}


IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

