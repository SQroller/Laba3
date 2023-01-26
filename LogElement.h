//
// Created by coola on 26.01.2023.
//

#ifndef LABA3_LOGELEMENT_H
#define LABA3_LOGELEMENT_H

#include "iostream"

using namespace std;

class LogElement {

public:
    LogElement();

    explicit LogElement(int count);

    void setCount(int count);

    int getCount() const;

    struct WritingCleat {
        int tip;
        int countConnection;
        char statSignal;
    };

    WritingCleat *createMass() {
        WritingCleat *result[count];
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
            result[i] = &elementCleat;
        }
        return *result;
    }

    WritingCleat *pereoprArray(WritingCleat *array) const {
        for (int i = 0; i < count; ++i) {
            cout << "Write status of signal cleat:\n";
            while (true) {
                cin >> array[i].statSignal;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Incorrect value. Enter argument again:\n";
                } else if (array[i].statSignal != '0' && array[i].statSignal != '1' &&
                           array[i].statSignal != 'X') {
                    cout << "Incorrect value. Enter argument again:\n";
                } else break;
            }
        }
        return array;
    }

    void pereoprArrayTrue() {
        pereoprArray(createMass());
    }

    WritingCleat* output(WritingCleat* array) const {
        for (int i = 0; i < count; ++i) {
            cout << "Cleat number " << i + 1 << "\n";
            cout << "Type: " << array[i].tip << "\n";
            cout << "Count of connections: " << array[i].countConnection << "\n";
            cout << "Status signal: " << array[i].statSignal << "\n";
        }
        return array;
    }

    void outputTrue(){
        output(createMass());
    };

private:
    int count;
};

#endif //LABA3_LOGELEMENT_H
