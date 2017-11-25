// Set.cpp: implementation of the CSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ctime>
#include "Set.h"
#include "Nodo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSet::CSet(){
    band = false;
}

CSet::~CSet(){

}

CSet& CSet::operator = (CSet &l){
    this->destruyeLista();
    this->AddHead(&l);
    return *this;
}

void CSet::creaLista(int numeros){
    band = true;
    CNodo *nodo, *ant;
    int num;
    POSITION pos1 = this->GetHeadPosition();
    
    while(numeros--){
        num = rand()%10;
        nodo = new CNodo(num);
        pos1 = this->GetHeadPosition();
        if(nodo){
            if(this->GetCount() == 0 || ((CNodo*)this->GetHead())->n > num){
                this->AddHead(nodo);
            }
            else{
                ant = ((CNodo*)this->GetAt(pos1));
                while(pos1 && ant->n < num){
                    ant = (CNodo*)this->GetNext(pos1);
                }
                if(!pos1){
                    if(num > ant->n){
                        this->AddTail(nodo);
                    }
                    else{
                        if(num != ant->n){
                            pos1 = this->GetTailPosition();
                            this->InsertBefore(pos1, nodo);
                        }
                    }
                }
                else{
                    if(ant->n != num){
                        ant = (CNodo*)this->GetPrev(pos1);
                        this->InsertBefore(pos1, nodo);
                    }
                }
            }
        }
    }
}

CSet& CSet::operator !(){ //complemento
    CSet *comp = new CSet();
    CNodo *nodo, *aux;
    CString cad;
    POSITION pos = this->GetHeadPosition();

    int i = 0;
    //int mayor = ((CNodo*)this->GetTail())->n;

    while(pos){
        nodo = (CNodo*)this->GetNext(pos);
        while(i != nodo->n){
            aux = new CNodo(i);
            comp->AddTail(aux);
            i++;
        }
        i++;
    }

    return *comp;
}

CSet& CSet::operator ^(const CSet &l){ //intersección
    CSet *inter = new CSet();
    CNodo *nodo, *a, *b;

    POSITION pos1 = this->GetHeadPosition();
    POSITION pos2 = l.GetHeadPosition();

    a = (CNodo*)this->GetNext(pos1);
    b = (CNodo*)l.GetNext(pos2);

    while(pos1 || pos2){
        if(a->n < b->n){
            a = (CNodo*)this->GetNext(pos1);
        }
        else{
            if(a->n > b->n){
                b = (CNodo*)l.GetNext(pos2);
            }
            else{
                nodo = new CNodo(a->n); //(b->n)
                inter->AddTail(nodo);
                a = (CNodo*)this->GetNext(pos1);
                b = (CNodo*)this->GetNext(pos2);
            }
        }
    }
    if(a->n == b->n){
        nodo = new CNodo(a->n);
        inter->AddTail(nodo);
    }

    return *inter;
}

CSet& CSet::operator +(CSet &s){ // unio
    CNodo *nodo, *ant;
    
    POSITION pos1;
    POSITION pos2 = s.GetHeadPosition();
   
   
    int numeros = s.GetCount();
    int num;

    while(numeros--){
        nodo = (CNodo*)s.GetNext(pos2);
        pos1 = this->GetHeadPosition();
        num = nodo->n;
        if(nodo){
            if(this->GetCount() == 0 || ((CNodo*)this->GetHead())->n > num){
                this->AddHead(nodo);
            }
            else{
                ant = ((CNodo*)this->GetAt(pos1));
                while(pos1 && ant->n < num){
                    ant = (CNodo*)this->GetNext(pos1);
                }
                if(!pos1){
                    if(num > ant->n){
                        this->AddTail(nodo);
                    }
                    else{
                        if(num != ant->n){
                            pos1 = this->GetTailPosition();
                            this->InsertBefore(pos1, nodo);
                        }
                    }
                }
                else{
                    if(ant->n != num){
                        ant = (CNodo*)this->GetPrev(pos1);
                        this->InsertBefore(pos1, nodo);
                    }
                }
            }
        }
    }
    return *this;
}


void CSet::destruyeLista(){
    CNodo *aux;
    POSITION pos;
    if(band){
        pos = this->GetHeadPosition();
        while(pos){
            aux = (CNodo*)this->GetNext(pos);
            delete(aux);
        }
    }
    this->RemoveAll();
}
