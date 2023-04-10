#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
    this->pozitie_curenta = 0;
}


void IteratorMultime::prim() {
    this->pozitie_curenta = 0;
}


void IteratorMultime::urmator() {
    if(this->valid())
        this->pozitie_curenta++;
    else
        throw("iterator invalid");
}


TElem IteratorMultime::element() const {
    if(this->valid())
        return this->multime.elements[pozitie_curenta];
    else
        throw("iterator invalid");
}

bool IteratorMultime::valid() const {
	if(this->pozitie_curenta == this->multime.size)
        return false;
    return true;
}
