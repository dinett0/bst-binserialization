//#pragma once
//
//#include "Binary.h"
//#include "BST.h"
//
//class BinInterface
//{
//    BST HT;
//    string fileName;
//
//public:
//    BinInterface(BST CBT, string fileName) {
//        this->HT = CBT;
//        this->fileName = fileName;
//    }
//
//    void binToBST() {
//        fstream move(fileName, ios::binary | ios::out | ios::in);
//        if (!move.good()) {
//            cout << "Cant open the file\n";
//        }
//
//        LibraryTicket x;
//        int i = 0;
//
//        while (move.read((char*)&x, sizeof(LibraryTicket)))
//        {
//            HT.insert(x.number, i);
//            i++;
//        }
//    }
//
//    int erase(int key) {
//        Node* p = HT.erase(key);
//        if (p == nullptr)
//        {
//            return 1;
//        }
//        removeBinRecord(p->index, fileName);
//        return 0;
//    }
//
//    int getRecord(int key, LibraryTicket& x) {
//        Node* p = HT.search(key);
//        if (p == nullptr) {//if record doesnt exist return false
//            return 1;
//        }
//        else
//        {
//            randomAccess(p->index, fileName, x);
//            return 0;
//        }
//    }
//};