#include "lista.h"
#include <QDebug>
int main()
{
    Lista<int> *test = new Lista<int>();

    test->moveToStart();
    test->insert(3);
    test->insert(2);
    test->insert(1);
    test->append(4);

    test->moveToEnd();
    test->remove();
    test->moveToStart();
    test->next();
    test->remove();

    qDebug() << test->head->element << endl;
    qDebug() << test->head->next->element << endl;
    qDebug() << test->tail->element  << endl;

    test->moveToPos(0);
    qDebug() << test->getValue();

    test->clear();
    return 0;
}
