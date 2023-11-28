#include <iostream>
#include "Header.h"
#include "BST.h"
#include "Interface.h"
#include <chrono>
using namespace std;

int main() {


	createBinary("pool.txt", "pool.bin");

	BST COCK;
	BinInterface Interface(COCK, "pool.bin");
	Interface.binToBST();

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	LibraryTicket x;
	Interface.getRecord(80879, x);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;
}