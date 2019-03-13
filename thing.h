#ifndef CALC_THING_H
#define CALC_THING_H

#include<string>

#include "func.h"


class Thing {
public:
    char type;
    Thing *l;
    Thing *r;

    std::string str;
    Func *func;

    Thing(std::string str);

    Thing(Func *func);

    Thing(char type, Thing *l, Thing *r);

    int eval();
};

#endif
