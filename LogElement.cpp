//
// Created by coola on 29.01.2023.
//

#include "LogElement.h"
#include "string"

using namespace std;

LogElement::LogElement() {
    this->size = 0;
    this->array = nullptr;
}

LogElement::LogElement(int size) : size(size) {
    this->size = size;
    array = realloc(array, 0, size);
    fillMass(array, size);
}

LogElement::LogElement(int size, char **array) {
    this->size = size;
    this->array = toWritingCleat(size, array);
}

LogElement::WritingCleat *LogElement::realloc(WritingCleat *mass, int oldSize, int newSize) {
    auto *arr = new WritingCleat[newSize];
    for (int i = 0; i < oldSize; i++) {
        arr[i] = mass[i];
    }
    if (oldSize != 0) delete[] mass;
    size = newSize;
    return arr;
}

LogElement::WritingCleat *LogElement::fillMass(WritingCleat *mass, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Write arguments of cleat" << "\n";
        WritingCleat elementCleat{};
        cout << "1.Write type of cleat( 1 or 2):\n"
                "1 - input\n"
                "2 - output\n";
        while (true) {
            cin >> elementCleat.tip;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Incorrect value. Enter argument again:\n";
            } else if (elementCleat.tip != 1 && elementCleat.tip != 2) {
                cout << "Incorrect value. Enter argument again:\n";
            } else break;
        }
        cout << "2.Write count of connections cleat:\n"
                "For input cleat 0-1 connections\n"
                "For output cleat 0-3 connections\n";
        while (true) {
            cin >> elementCleat.countConnection;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Incorrect value. Enter argument again:\n";
            } else if ((elementCleat.tip == 1 && elementCleat.countConnection <= 1) ||
                       (elementCleat.tip == 2 && elementCleat.countConnection <= 3)) {
                break;
            } else
                cout << "Incorrect value. Enter argument again:\n";
        }
        cout << "3.Write status of cleat:\n"
                "Status only 0,1 or X (non defined)\n";
        while (true) {
            cin >> elementCleat.statSignal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Incorrect value. Enter argument again:\n";
            } else if (elementCleat.statSignal != '0' && elementCleat.statSignal != '1' &&
                       elementCleat.statSignal != 'X') {
                cout << "Incorrect value. Enter argument again:\n";
            } else break;
        }
        mass[i] = elementCleat;
    }
    return mass;
}

LogElement::WritingCleat *LogElement::redefine(LogElement::WritingCleat *mass, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Write new status of signal cleat number " << i + 1 << ":" << "\n";
        while (true) {
            cin >> mass[i].statSignal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Incorrect value. Enter argument again:\n";
            } else if (mass[i].statSignal != '0' && mass[i].statSignal != '1' &&
                       mass[i].statSignal != 'X') {
                cout << "Incorrect value. Enter argument again:\n";
            } else break;
        }
    }
    return mass;
}

void LogElement::outputMass() const {
    cout<<"###\n";
    for (int i = 0; i < size; ++i) {
        cout << "Cleat number " << i + 1 << "\n";
        cout << "Type: " << array[i].tip << "\n";
        cout << "Count of connections: " << array[i].countConnection << "\n";
        cout << "Status signal: " << array[i].statSignal << "\n";
    }
    cout<<"###\n";
}

LogElement::WritingCleat *LogElement::redefineOneElement(LogElement::WritingCleat *mass, int count, int number) {
    if (number - 1 <= count) {
        cout << "Write new status of signal cleat number:\n";
        while (true) {
            cin >> mass[number].statSignal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Incorrect value! Enter argument again:\n";
            } else if (mass[number].statSignal != '0' && mass[number].statSignal != '1' &&
                       mass[number].statSignal != 'X') {
                cout << "Incorrect value! Enter argument again:\n";
            } else break;
        }
    } else {
        cout << "Cleat number " << number << " is not real!!!";
    }
    return mass;
}

void LogElement::outputStatusCleat(int number) {
    cout<<"###\n";
    if (number + 1 <= size) {
        cout << "Cleat number " << number + 1 << "\n";
        cout << "Type: " << array[number].tip << "\n";
        cout << "Count of connections: " << array[number].countConnection << "\n";
        cout << "Status signal: " << array[number].statSignal << "\n";
    } else {
        cout << "Cleat number " << number << " is not real!!!";
    }
    cout<<"###\n";
}

LogElement::WritingCleat *LogElement::toWritingCleat(int number, char **array) {
    auto *structureMassiv = new WritingCleat[number];
    for (int i = 0; i < number; ++i) {
        structureMassiv[i].tip = array[i][0] - '0';
        structureMassiv[i].countConnection = array[i][1] - '0';
        structureMassiv[i].statSignal = array[i][2];
    }
    return structureMassiv;
}

void LogElement::plusCountOfCon(int number) const {
    while (number - 1 < 0 || number - 1 > size) {
        cout << "Number of cleat is invalid!!!";
        cin >> number;
    };
    cout << "Cleat of " << number << " number!:\n";
    if (array[number - 1].tip == 1) {
        cout << "Cleat is input.\n";
        cout << "Count of connections: " << array[number - 1].countConnection << "\n";
        if (array[number - 1].countConnection == 1) {
            cout << "Count of connection is max(1)\n";
        } else {
            array[number - 1].countConnection++;
        }
    } else if (array[number - 1].tip == 2) {
        cout << "Cleat is output.\n";
        cout << "Count of connections: " << array[number - 1].countConnection << "\n";
        if (array[number - 1].countConnection == 3) {
            cout << "Count of connection is max(3)\n";
        } else {
            array[number - 1].countConnection++;
        }
    }
}

void LogElement::minusCountOfCon(int number) const {
    while (number - 1 < 0 || number - 1 > size) {
        cout << "Number of cleat is invalid!!!";
        cin >> number;
    };
    cout << "Cleat of " << number << " number!:\n";
    if (array[number - 1].tip == 1) {
        cout << "Cleat is input.\n";
        cout << "Count of connections: " << array[number - 1].countConnection << "\n";
        if (array[number - 1].countConnection == 0) {
            cout << "Count of connection is max(1)\n";
            array[number - 1].statSignal = 'X';
        } else {
            array[number - 1].countConnection--;
        }
    } else if (array[number - 1].tip == 2) {
        cout << "Cleat is output.\n";
        cout << "Count of connections: " << array[number - 1].countConnection << "\n";
        if (array[number - 1].countConnection == 0) {
            cout << "Count of connection is max(1)\n";
            array[number - 1].statSignal = 'X';
        } else {
            array[number - 1].countConnection--;
        }
    }
}

LogElement::WritingCleat *LogElement::addCleat() {
    array = realloc(array, size, size + 1);
    cout << "Write arguments of cleat" << "\n";
    cout << "1.Write type of cleat( 1 or 2):\n"
            "1 - input\n"
            "2 - output\n";
    while (true) {
        cin >> array[size - 1].tip;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Incorrect value. Enter argument again:\n";
        } else if (array[size - 1].tip != 1 && array[size - 1].tip != 2) {
            cout << "Incorrect value. Enter argument again:\n";
        } else break;
    }
    cout << "2.Write count of connections cleat:\n"
            "For input cleat 0-1 connections\n"
            "For output cleat 0-3 connections\n";
    while (true) {
        cin >> array[size - 1].countConnection;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Incorrect value. Enter argument again:\n";
        } else if ((array[size - 1].tip == 1 && array[size - 1].countConnection <= 1) ||
                   (array[size - 1].tip == 2 && array[size - 1].countConnection <= 3)) {
            break;
        } else
            cout << "Incorrect value. Enter argument again:\n";
    }
    cout << "3.Write status of cleat:\n"
            "Status only 0,1 or X (non defined)\n";
    while (true) {
        cin >> array[size - 1].statSignal;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Incorrect value. Enter argument again:\n";
        } else if (array[size - 1].statSignal != '0' && array[size - 1].statSignal != '1' &&
                   array[size - 1].statSignal != 'X') {
            cout << "Incorrect value. Enter argument again:\n";
        } else break;
    }
    return array;
}

