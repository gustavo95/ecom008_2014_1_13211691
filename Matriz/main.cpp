#include "matriz.h"

#include <iostream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    Matriz m;
    m.create(2,2);
    m.setElementAt(0,0,1.0);
    m.setElementAt(1,0,2.0);
    m.setElementAt(0,1,3.0);
    m.setElementAt(1,1,4.0);
    qDebug() << m.toString() << endl;

    Matriz n;
    n.create(2,2);
    n.setElementAt(0,0,0.0);
    n.setElementAt(1,0,2.0);
    n.setElementAt(0,1,1.0);
    n.setElementAt(1,1,-1.0);
    qDebug() << n.toString() << endl;

    m.sub(n);
    qDebug() << m.toString() << endl;

    m.multiplyBy(2.0);
    qDebug() << m.toString() << endl;

    cout << n.determinant() << endl << endl;

    Matriz *a = new Matriz;
    a = m.transpose();
    qDebug() << a->toString() << endl;
    delete(a);

    return 0;
}
