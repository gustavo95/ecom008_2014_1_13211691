#ifndef MATRIXADT_H
#define MATRIXADT_H

#include <QString>

class MatrixADT {
public:
	// Construtor default
    MatrixADT() {}
	// Criar nova matriz
    virtual void create(int columns, int rows) = 0;
	// Setar valor do elemento
    virtual void setElementAt(int column, int row, double value) = 0;
	// Retorn: elemento
    virtual double elementAt(int column, int row) const = 0;
    // Subtracao da matriz
    virtual void sub(const MatrixADT & other) = 0;
	// Multiplicar a matriz
    virtual void multiplyBy(double k) = 0;
	// Retorn: determinante
    virtual double determinant() = 0;
	// Retorn: matriz transposta
    virtual MatrixADT * transpose() = 0;
	// Imprimir a matriz
    virtual QString toString() = 0;
};

#endif // MATRIXADT_H
