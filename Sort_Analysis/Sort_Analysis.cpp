// Extra Credit Problem #1 for HW #1
// Author: Jake A. Cole, Date: 11/21/2014, Class: Algorithms

//For Visual Studio
//#include "stdafx.h"

#include <iostream>

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define K 10000

void unhsort(int* unhsa, int n);
void insertionsort(int* isa, int n);
void mergesort(int* msa, int l, int r);
void merge(int* msa, int l, int r);

using namespace std;

int main() {
	cout << "Jake A. Cole, Extra Credit Problem #1:" << endl;

	int q = 0, i = 0, n = K, ra[K], rb[K], rc[K];
	double t = 0;
	clock_t start, finish;

	srand(time(NULL)); //seed RNG

	//fills the array with random integers
	while (i < n) { 
		q = rand() % 100 + 1;
		ra[i] = q;
		rb[i] = q;
		rc[i] = q;
		i++;	
	}

	//Calculates how fast UNH sort will be
	start = clock();
	unhsort(ra, n);
	finish = clock();

	t = (finish - start);
	cout << "finished UNH Sort in: " << t / 1000 <<" seconds" << endl;

	//Calculates how fast Insertion Sort will be
	start = clock();
	insertionsort(rb, n);
	finish = clock();

	t = (finish - start);
	cout << "finished Insertion Sort in : " << t / 1000 << " seconds" << endl;

	//Calculates how fast Merge Sort will be
	start = clock();
	mergesort(rc, 0, n-1);
	finish = clock();

	t = (finish - start);
	cout << "finished Merge Sort in: " << t / 1000 << " seconds" << endl;

	return 0;
}

//Function unhsort
//Complexity O(n^2)
void unhsort(int* unhsa, int n) {
	for (int i = n - 1; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			if (unhsa[j] > unhsa[j+1]) 
				swap(unhsa[j], unhsa[j+1]);
		}
	}
}

//Function insertionsort
//Complexity O(n^2)
void insertionsort(int* isa, int n) {
	int a, b;
	for (a = 1; a < n; a++) {
		b = a;
		while (b > 0 && isa[b-1] > isa[b]) {
			swap(isa[b], isa[b-1]);
			b--;
		}
	}
}

//Function mergesort
//Complexity O(nlogn)
void mergesort(int* msa, int l, int r) {
	if (l < r) {
		int m = ((l+r)/2);
		mergesort(msa, l, m);
		mergesort(msa, m + 1, r);
		merge(msa, l, r);
	}
}

//Function merge, part of mergesort
void merge(int* msa, int l, int r) {
	int m = ((l+r)/2);
	int one = 0;
	int two = l;
	int three = m + 1;

	int t[K]; //temp array

	while (two <= m && three <= r) {
		if (msa[two] < msa[three])
			t[one++] = msa[two++];
		else
			t[one++] = msa[three++];
	}

	while (two <= m)
		t[one++] = msa[two++];

	while (three <= r)
		t[one++] = msa[three++];

	for (int i = l; i <= r; i++)
		msa[i] = t[i-l];
}

/*
Jake A. Cole, Extra Credit Problem #1:
finished UNH Sort in: 2.583 seconds
finished Insertion Sort in : 2.381 seconds
finished Merge Sort in: 0.015 seconds
Press any key to continue . . .

Jake A. Cole, Extra Credit Problem #1:
finished UNH Sort in: 2.566 seconds
finished Insertion Sort in : 2.385 seconds
finished Merge Sort in: 0.015 seconds
Press any key to continue . . .

Jake A. Cole, Extra Credit Problem #1:
finished UNH Sort in: 2.569 seconds
finished Insertion Sort in : 2.364 seconds
finished Merge Sort in: 0.015 seconds
Press any key to continue . . .

Jake A. Cole, Extra Credit Problem #1:
finished UNH Sort in: 2.555 seconds
finished Insertion Sort in : 2.347 seconds
finished Merge Sort in: 0.014 seconds
Press any key to continue . . .

Jake A. Cole, Extra Credit Problem #1:
finished UNH Sort in: 2.574 seconds
finished Insertion Sort in : 2.405 seconds
finished Merge Sort in: 0.014 seconds
Press any key to continue . . .
*/

