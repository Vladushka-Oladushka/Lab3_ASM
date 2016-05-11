#include <iostream>
#pragma warning( disable : 4731 )
//множества
using namespace std;

void test(int* a, int* b, int n)
{
	int test_a, test_b;
	int* intersection = new int[n];
	int* addition = new int[n];
	int* subdiv = new int[n];
	__asm
	{
		mov eax, b
		mov ebx, a
		mov ecx, n
		xor esi, esi
		mov esi, n
		dec esi
	beg:
		mov edx, [eax]
		and edx, [ebx][esi * 4]
		mov intersection[esi], edx
		mov edx, [eax][esi * 4]
		or edx, [ebx][esi * 4]
		mov addition[esi], edx
		mov edx, [eax][esi * 4]
		xor edx, [ebx][esi * 4]
		and edx, [ebx][esi * 4]
		mov subdiv[esi], edx
		dec esi
		loop beg
	}
	cout << endl << "Result of addition: ";
	for (int i = 0; i < n; i++)
		cout << addition[i] << " ";
	cout << endl << "Result of subdivision: ";
	for (int i = 0; i < n; i++)
		cout << subdiv[i] << " ";
	cout << endl << "Result of intersection: ";
	for (int i = 0; i < n; i++)
		cout << intersection[i] << " ";
	
}

int main()
{
	int a[4] = { 1, 1, 0, 1 };
	int b[4] = { 1, 0, 0, 1 };
	test( a, b, 4);
	/*test(123321);
	test(1221);
	test(12345678);
	test(1488);
	test(228);
	test(1337);*/

	return 0;
}