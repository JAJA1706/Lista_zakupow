#ifndef PURCHASES_H
#define PURCHASES_H
#include "Cost.h"
#include <forward_list>

class Purchases
{
    private:
        forward_list<Cost> costList;
        forward_list<Cost>::iterator iter;
        friend void shell();

    public:

        void howMuchForPeriod();
        void howMuchForGroupOfProducts();
        void whereBuy();
};

#endif
