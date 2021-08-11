// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../include/solve_dlt.h"

int main()
{
	
	double dst_pts[4][2] = { {0, 0}, {8.000000,  0.000000}, {0.000000,   8.000000}, {8.000000,   8.000000} };
	double src_pts[4][2] = { {46.433670, -540.986450}, {56.608696,  -533.575256}, {38.550194, - 531.213562}, {48.718105, - 523.787170} };
	solve_dlt(src_pts, dst_pts);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
