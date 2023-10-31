
#include <windows.h>
#include <stdio.h>



int main ()
{
    int k;
    HANDLE console;
    console = GetStdHandle (STD_OUTPUT_HANDLE);
    for (k=1 ; k<=255 ; k++ )
    {
    SetConsoleTextAttribute(console , k);
    printf ("hello world   %d\n" , k);
    }
    return 0;
}
