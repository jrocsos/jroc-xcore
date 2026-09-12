#include <assert.h>
#include <sys/stat.h>

static int exists(const char *path)
{
    struct stat st;
    return stat(path, &st) == 0;
}

int main(void)
{
    assert(exists("xcore"));
    assert(exists("storage"));
    assert(exists("network"));
    assert(exists("security"));
    assert(exists("userspace"));
    assert(exists("desktop"));
    assert(exists("frontend"));
    assert(exists("backend"));

    return 0;
}
