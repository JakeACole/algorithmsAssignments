// RSA Algorithm for Question 5 on Homework #3
// Author: Jake A. Cole, Date: 10/29/2014, Class: Algorithms

//For Visual Studio
//#include "stdafx.h"

#include <iostream>
#include <cmath>

int exp(int a,  int b, int n);

using namespace std;
// Main Function for the RSA implementation
int main() {
	int p = 0, q = 0, n = 0, e = 0, t = 0, d = 0, C = 0, M = 0, S = 0, quit = 0;

	while ('!') { //infinite loop

		//Has the user input p, q, e, and d as well as a Message M
		cout << "Please enter prime p" << endl;
		cin >> p;
		cout << "Please enter prime q" << endl;
		cin >> q;
		cout << "Please enter an e value" << endl;
		cin >> e;
		cout << "Please enter a Message" << endl;
		cin >> M;
		
		//Calculates the n and t values 
		n = p * q;
		t = (p - 1) * (q - 1);

		//Calculates a d value
		int k = 1, g;
		while ('!') {			
			g = (e * k - 1) % t;
			if (g == 0) {
				d = k;
				break;
			}
			k++;
		}
			
		C = exp(M, e, n); //To encode the original message
				
		S = exp(C, d, n); //To decode the encrypted message
				
		cout << endl << "Prime p: " << p << endl; //Prints the output
		cout << "Prime q: " << q << endl;
		cout << "n: " << n << endl;
		cout << "e: " << e << endl;
		cout << "t: " << t << endl;
		cout << "d: " << d << endl;
		cout << "M: " << M << endl;
		cout << "C: " << C << endl;
		cout << "M': " << S << endl;

		cout << endl << "Enter -1 to quit" << endl;
		cin >> quit;

		if (quit == -1) break; //breaks out of infinite loop
	}
}

// Modular Exponentiation Function 
int exp(int a, int b, int n) {
	int prod = 1;	
	a = a % n;
	while (b > 0) {
		if ((b % 2) == 1)
			prod = (prod * a) % n;
		b = (b / 2);
		a = (a * a) % n;
	}
	return prod;
}

/*
Please enter prime p
11
Please enter prime q
29
Please enter an e value
13
Please enter a Message
35

Prime p: 11
Prime q: 29
n: 319
e: 13
t: 280
d: 237
M: 35
C: 63
M': 35

Enter -1 to quit
-1
*/
