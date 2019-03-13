#include <iostream>

#include "func.h"


extern bool error;

Func::Func(std::string name, std::vector<std::string>* args_vec) {
    this->name = name;

    if (args_vec) {
        this->args = new std::string[args_vec->size()];
        for (int i = 0; i < args_vec->size(); i++)
            this->args[i] = (*args_vec)[i];
    } else {
        this->args = NULL;
        this->argc = 0;
    }
}

Func::~Func() {
    if (this->args) {
        delete this->args;
    }
}

int Func::call() {
    if (this->name == "input") {
        int result = 0;
        std::cin >> result;

        return result;
    }

    error = true;
    return 0;
}
