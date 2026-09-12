static int ready;
static int files;

void jroc_vfs_init(void)
{
    ready = 1;
    files = 1;
}

int jroc_vfs_status(void) { return ready; }
int jroc_vfs_count(void) { return files; }
