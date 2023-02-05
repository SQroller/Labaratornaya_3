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

    virtual ~LogElement();

    LogElement(LogElement&);

    LogElement(LogElement&&) noexcept ;

    static LogElement::WritingCleat *redefine(WritingCleat *, int);

    friend ostream& operator<<(ostream&, LogElement&);

    static LogElement::WritingCleat *redefineOneElement(WritingCleat *, int /*размер*/, int /*номер клемы*/);

    void outputStatusCleat(int);

    void operator+(int) const;

    void operator-(int) const;

    LogElement::WritingCleat* addCleat();
};


#endif //UNTITLED1_LOGELEMENT_H
