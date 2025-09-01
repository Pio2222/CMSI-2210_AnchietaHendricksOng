#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {
    char user_name[20];

    printf("Please enter your name: ");
    gets(user_name);

    printf( "\n\nHello and have a very very nice day %s!!!\n\n", user_name);
}
