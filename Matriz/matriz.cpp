#include "matriz.h"

#include <iostream>

using namespace std;

Matriz::Matriz(){

}

void Matriz::create(const int columns,const int rows){
    this->content = new double*[columns];
    for(int i = 0; i < columns; ++i){
        this->content[i] = new double[rows];
    }
    this->columns = columns;
    this->rows = rows;
}

void Matriz::setElementAt(int column, int row, double value){
    this->content[column][row] = value;
}

double Matriz::elementAt(int column, int row) const{
    return this->content[column][row];
}

void Matriz::sub(const MatrixADT &other){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            this->setElementAt(j,i,(this->elementAt(j,i) - other.elementAt(j,i)));
        }
    }
}

void Matriz::multiplyBy(double k){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            this->setElementAt(j,i,(this->elementAt(j,i) * k));
        }
    }
}

double Matriz::determinant(){
    if(this->columns == 1 && this->rows == 1){
        return this->elementAt(0,0);
    }else{
        if(this->columns == 2 && this->rows == 2){
            return (this->elementAt(0,0)*this->elementAt(1,1) - this->elementAt(0,1)*this->elementAt(1,0));
        }
    }
}

Matriz *Matriz::transpose(){
    Matriz *aux = new Matriz;
    aux->create(this->rows,this->columns);

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            aux->setElementAt(i,j,this->elementAt(j,i));
        }
    }
    return aux;
}

QString Matriz::toString(){
    QString matrizString("");
    int i;
    int j;
    for(i = 0; i < rows; ++i){
        for(j = 0; j < columns; ++j){
            matrizString += QString::number(elementAt(j,i));
            if((i != this->rows-1) || (j != this->columns-1)){
                matrizString.append(" ");
            }
        }
        if(i != this->rows-1 && j != this->columns-1){
            matrizString.append("\n ");
        }
    }
    return matrizString;
}
