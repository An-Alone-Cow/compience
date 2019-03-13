#ifndef CALC_FUNC_H
#define CALC_FUNC_H

#include <string>
#include <vector>


class Func {
public:
    std::string name;

    std::string* args;
    int argc;

    Func(std::string name, std::vector<std::string>* args_vec = NULL);
    ~Func();

    int call();
};

#endif //CALC_FUNC_H
