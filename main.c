#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "login.c"


int main() {
    setlocale(LC_ALL, "");

    login();

    return 0;
}
