//
// Created by coola on 26.01.2023.
//

#include "LogElement.h"

    LogElement::LogElement() {
        this->count = 0;
    }

    LogElement::LogElement(int count) : count(count) {
        this->count = count;
    }

    void LogElement::setCount(int count) {
        LogElement::count = count;
    }

    int LogElement::getCount() const {
        return count;
    }
