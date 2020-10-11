#include <stdio.h>
#include <malloc.h>
#include<iostream>
using namespace std;
void main() {
	_int8  a[8] = { 25,1,2,3,24,5,6,-7 };
	_int8  b[8] = { 3,16,6,3,4,5,6,0 };
	_int8  c[8] = { 14,8,2,3,-32,5,6,9 };
	_int16 d[8] = { 2,0,-2,8,4,5,6,0 };
	_int16 f[8];
	_asm {

		movq mm0, qword ptr[a]
		movq mm1, qword ptr[b]
		movq mm2, qword ptr[c]
		movq mm3, qword ptr[d]

		punpcklbw mm0, mm0
		punpcklbw mm1, mm1
		punpcklbw mm2, mm2
		psraw     mm0, 8
		psraw     mm1, 8
		psraw     mm2, 8

		pmullw mm1, mm2
		psubsw mm0, mm1
		psubsw mm0, mm3

		movq qword ptr[f], mm0


		movq mm0, qword ptr[a + 4]
		movq mm1, qword ptr[b + 4]
		movq mm2, qword ptr[c + 4]
		movq mm3, qword ptr[d + 8]

		punpcklbw mm0, mm0
		punpcklbw mm1, mm1
		punpcklbw mm2, mm2
		psraw     mm0, 8
		psraw     mm1, 8
		psraw     mm2, 8

		pmullw mm1, mm2
		psubsw mm0, mm1
		psubsw mm0, mm3


		movq qword ptr[f + 8], mm0
		//mov [f], eax

	}
	for (int i = 0; i < 8; i++)
		cout << int(a[i]) << " ";
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << int(b[i]) << " ";
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << int(c[i]) << " ";
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << int(d[i]) << " ";
	cout << endl;
	for (int i = 0; i < 8; i++)
		cout << int(f[i]) << " ";
}
