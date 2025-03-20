#include <iostream>
#include"golf.h"

int main()
{
    Golf ann("Ann Birdfree", 24);
   
    ann.showgolf();

    Golf men[3] = { };
   
    for (int i = 0; i < 3; i++)
        men[i].showgolf();

    for (int i = 0; i < 3; i++)
        men[i].handicap((i + 1) * 6);

    for (int i = 0; i < 3; i++)
        men[i].showgolf();

    return 0;
}
