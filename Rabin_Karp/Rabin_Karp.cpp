// Extra Credit Problem #13 for HW #3
// Author: Jake A. Cole, Date: 11/21/2014, Class: Algorithms

//For Visual Studio
//#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <stdio.h> 
#include <stdlib.h> 

void rabinkarp(char *text, char *pattern, int q, int d);

using namespace std;

int main() {
	cout << "Jake A. Cole, Extra Credit Problem #13:" << endl << endl;

	//q is a prime number and d is for proccessing chars
	int q = 71, d = 256;

	//text and different patterns
	char *t = "Fool of a Took! This is a serious journey, not a hobbit walking-party. Throw yourself in next time, and then you will be no further nuisance. - J.R.R. Tolkien, The Fellowship of the Ring";
	char *p1 = "a";
	char *p2 = "it";
	char *p3 = "Took";
	char *p4 = ".";
	char *p5 = "no";
	
	//Calls rabinkarp five times to check for five different patterns
	cout << "The pattern is: " << p1 << endl << endl;
	rabinkarp(t, p1, q, d);
	cout << "The pattern is: " << p2 << endl << endl;
	rabinkarp(t, p2, q, d);
	cout << "The pattern is: " << p3 << endl << endl;
	rabinkarp(t, p3, q, d);
	cout << "The pattern is: " << p4 << endl << endl;
	rabinkarp(t, p4, q, d);
	cout << "The pattern is: " << p5 << endl << endl;
	rabinkarp(t, p5, q, d);

	return 0;
}

//Function rangequery
//Complexity O(m * n)
void rabinkarp(char *text, char *pattern, int q, int d){
	int A = strlen(text);
	int B = strlen(pattern);

	int i = 0, j = 0, x = 0, y = 0, z = 1;

	for (i = 0; i < B - 1; i++) 
		z = (z * d) % q;

	//The initial hash value calculations for the first portion of text
	//and for the pattern
	for (i = 0; i < B; i++)	{
		x = (d * x + pattern[i]) % q;
		y = (d * y + text[i]) % q;
	}

	//Goes through the text and searches for the pattern
	for (i = 0; i <= A - B; i++) {
		if (x == y)	{
			for (j = 0; j < B; j++)	{
				if (text[i + j] != pattern[j])
					break;
			}

			if (j == B) //prints out if a pattern has been found
				cout << "The pattern has been found at: " << i << endl << endl;
		}

		//Calculates the hash value for the next portion of text
		if (i < A - B) {
			y = (d * (y - text[i] * z) + text[i + B]) % q;
			if (y < 0)
				y = (y + q);
		}
	}
}

/*
Jake A. Cole, Extra Credit Problem #13:

The pattern is: a

The pattern has been found at: 8

The pattern has been found at: 24

The pattern has been found at: 47

The pattern has been found at: 57

The pattern has been found at: 65

The pattern has been found at: 100

The pattern has been found at: 136

The pattern is: it

The pattern has been found at: 53

The pattern is: Took

The pattern has been found at: 10

The pattern is: .

The pattern has been found at: 69

The pattern has been found at: 140

The pattern has been found at: 145

The pattern has been found at: 147

The pattern has been found at: 149

The pattern is: no

The pattern has been found at: 43

The pattern has been found at: 121

Press any key to continue . . .
*/
