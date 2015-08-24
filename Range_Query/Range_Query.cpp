// Extra Credit Problem #3 for HW #1
// Author: Jake A. Cole, Date: 11/21/10014, Class: Algorithms

//For Visual Studio
//#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

#define K 10

void rangequery(int* R);
void countingsort(int* A, int n);

using namespace std;

int main() {
	cout << "Jake A. Cole, Extra Credit Problem #3:" << endl;

	int q = 0, i = 0, n = 100, Ar[100];
	
	srand(time(NULL)); //seed RNG

	//fills the array with random integers from 1 to 9
	while (i < n) {
		q = rand() % (K - 1) + 1;
		Ar[i] = q;
		i++;
	}

	countingsort(Ar, n);
	return 0;
}

//Function rangequery
//Complexity O(1)
void rangequery(int* R) {
	int min = 0, max = 0, range = 0;

	for (int i = 1; i < K; i++)
		R[i] = R[i - 1] + R[i];

	while ('!'){
		cout << "Please enter a range query with a min and max value: " << endl;
		cout << "Enter -1 to break out" << endl;
		cin >> min;

		if (min < 0)
			break;

		while (min > K - 1) {
			cout << "Please enter a valid min value " << endl;
			cin >> min;
		}

		cin >> max;

		while (max > K - 1 || max < 0) {
			cout << "Please enter a valid max value" << endl;
			cin >> max;
		} 

		if (min == 1) {
			range = R[max];
		}

		else {
			range = R[max] - R[min];
		}

		cout << "This is the sum of the range: " << range << endl;
	}
}

//Function countingsort
//Complexity O(n+k)
void countingsort(int* A, int n) {
	int B[100];
	int C[K];
	int sum = 0;

	for (int i = 0; i < K; i++) {
		C[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		C[A[j]] = C[A[j]] + 1;
	}
	
	for (int j = 1; j < K; j++) {
		cout << endl << "Number " << j << " " << " " << C[j] << endl;
		sum = sum + C[j];
	}

	cout << "The sum is: " << sum << endl << endl;

	rangequery(C);
}

/*
Jake A. Cole, Extra Credit Problem #3:

Number 1  14

Number 2  11

Number 3  10

Number 4  10

Number 5  13

Number 6  8

Number 7  8

Number 8  12

Number 9  14
The sum is: 100

Please enter a range query with a min and max value:
Enter -1 to break out
1
9
This is the sum of the range: 100
Please enter a range query with a min and max value:
Enter -1 to break out
2
7
This is the sum of the range: 49
Please enter a range query with a min and max value:
Enter -1 to break out
3
4
This is the sum of the range: 10
Please enter a range query with a min and max value:
Enter -1 to break out
5
8
This is the sum of the range: 28
Please enter a range query with a min and max value:
Enter -1 to break out
-1
Press any key to continue . . .

Jake A. Cole, Extra Credit Problem #3:

Number 1  11

Number 2  11

Number 3  9

Number 4  14

Number 5  12

Number 6  17

Number 7  12

Number 8  6

Number 9  8
The sum is: 100

Please enter a range query with a min and max value:
Enter -1 to break out
1
9
This is the sum of the range: 100
Please enter a range query with a min and max value:
Enter -1 to break out
2
8
This is the sum of the range: 70
Please enter a range query with a min and max value:
Enter -1 to break out
4
7
This is the sum of the range: 41
Please enter a range query with a min and max value:
Enter -1 to break out

Jake A. Cole, Extra Credit Problem #3:

Number 1  20

Number 2  16

Number 3  14

Number 4  8

Number 5  7

Number 6  5

Number 7  10

Number 8  11

Number 9  9
The sum is: 100

Please enter a range query with a min and max value:
Enter -1 to break out
1
9
This is the sum of the range: 100
Please enter a range query with a min and max value:
Enter -1 to break out
2
7
This is the sum of the range: 44
Please enter a range query with a min and max value:
Enter -1 to break out
3
4
This is the sum of the range: 8
Please enter a range query with a min and max value:
Enter -1 to break out
*/

