#ifndef MATRIZ_H
#define MATRIZ_H

#include "MatrixADT.h"

class Matriz : public MatrixADT
{
public:
    Matriz();
    void create(int columns, int rows);
    void setElementAt(int column, int row, double value);
    double elementAt(int column, int row) const;
    void sub(const MatrixADT &other);
    void multiplyBy(double k);
    double determinant();
    Matriz *transpose();
    QString toString();
    double **content;
private:
    int columns;
    int rows;
};

#endif // MATRIZ_H
