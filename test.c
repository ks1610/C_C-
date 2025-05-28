#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("testing...\n");

    const char* s = getenv("HOME"); //Access varriable enviroment

    // If the environment variable doesn't exist, it returns NULL
    printf("HOME :%s\n", (s != NULL) ? s : "getenv returned NULL"); //Print the home part

    printf("end test\n");
}