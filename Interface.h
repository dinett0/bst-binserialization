#pragma once
#include "Header.h"
#include "BST.h"

class BinInterface
{
    BST HT;
    string fileName;

public:
    BinInterface(BST CBT, string fileName) {
        this->HT = CBT;
        this->fileName = fileName;
    }

    void binToBST() {
        fstream move(fileName, ios::binary | ios::out | ios::in);
        if (!move.good()) {
            cout << "Cant open the file\n";
        }

        LibraryTicket x;
        int i = 0;

        while (move.read((char*)&x, sizeof(LibraryTicket)))
        {
            HT.insert(x.number, i);
            i++;
        }
    }

    void show() {
        HT.display();
    }

    int erase(int key) {
        if (HT.erase(key) < 0) {
            return 1;
        }
        removeBinRecord(erase(key), fileName);
        return 0;
    }

    int getRecord(int key, LibraryTicket& x) {
        if (HT.search(key) == nullptr)
        {
            return 1;
        }
        randomAccess(HT.search(key)->index, fileName, x);
        return 0;
    }
};