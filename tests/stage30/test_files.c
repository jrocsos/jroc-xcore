#include <assert.h>
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("release/1.0/version.txt", "r");

    assert(f != NULL);

    fclose(f);

    return 0;
}
