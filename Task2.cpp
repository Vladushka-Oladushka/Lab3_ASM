#include <iostream>
#pragma warning( disable : 4731 )
//симметричность числа
using namespace std;

void test(int* a, int n)
{
	int res;
	int adress;
	int maxnum;
	__asm
	{
		mov ebx, a
		xor esi, esi
		mov ecx, n
		xor eax, eax
		xor edx, edx
		xor edi, edi
		xor ebp, ebp
	beg:
		cmp edi, ebp
		jg resi
		xor edi, edi
		mov eax, edx
	beg_:
		mov edx, [ebx][esi*4]
		inc esi
		cmp edx, eax
		je acc
		loop beg
		jmp exit_
	acc:
		inc edi
	    loop beg_
	resi:
		mov ebp, edi
		jmp beg
	exit_:
		mov ebx, a
		xor esi, esi
		mov ecx, n
		xor eax, eax
		xor edx, edx
		xor edi, edi
	search_index:
		cmp edi, ebp
		je everything_found
		mov eax, edx
	begsearch :
		mov edx, [ebx][esi * 4]
		inc esi
		cmp edx, eax
		je accum
		loop search_index
	accum :
		inc edi
		loop begsearch
	everything_found:
		inc ebp
		mov res, ebp
		sub esi, edi
		dec esi
		mov adress, esi
	}
	cout << endl << "Maximum number of equal elements in a row is " << res << " and it begins at adress " << adress << endl;
}

int main()
{
	int a[7] = { 1, 2, 2, 3, 3, 3, 4 };
	test(a, 7);
	/*test(1234321);
	test(123321);
	test(1221);
	test(12345678);
	test(1488);
	test(228);
	test(1337);*/

	return 0;
}