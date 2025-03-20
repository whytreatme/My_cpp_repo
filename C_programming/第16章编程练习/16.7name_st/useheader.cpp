#include<stdio.h>

#include"names_st.h"


int main()
{
	names candidate;

	get_names(&candidate);
	printf_s("Let's welcome ");
	show_names(&candidate);
	printf_s(" to this program!\n");
	return 0;
}