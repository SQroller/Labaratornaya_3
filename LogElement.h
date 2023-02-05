//
// Created by coola on 29.01.2023.
//

#ifndef UNTITLED1_LOGELEMENT_H
#define UNTITLED1_LOGELEMENT_H

#include <iostream>

using namespace std;

class LogElement {
private:
    int size;
    struct WritingCleat {
        int tip;
        int countConnection;
        char statSignal;
    };
    WritingCleat *array{};

    WritingCleat *realloc(WritingCleat *, int, int);

    static WritingCleat *fillMass(WritingCleat *, int);

public:
    LogElement();

    static LogElement::WritingCleat *toWritingCleat(int, char **);

    explicit LogElement(int);

    LogElement(int, char **);

    static LogElement::WritingCleat *redefine(WritingCleat *, int);

    void outputMass() const;

    static LogElement::WritingCleat *redefineOneElement(WritingCleat *, int /*размер*/, int /*номер клемы*/);

    void outputStatusCleat(int);

    void plusCountOfCon(int) const;

    void minusCountOfCon(int) const;

    LogElement::WritingCleat* addCleat();
};


#endif //UNTITLED1_LOGELEMENT_H
