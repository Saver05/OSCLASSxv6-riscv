#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int num_pages = 32;
    char *pages = sbrk(num_pages * 4096);
    uint accessBitmap = 0;

    // Access only even-numbered pages
    for (int i = 0; i < num_pages; i += 2) {
        pages[i * 4096] = 'A';
    }
    if (pgaccess(pages, num_pages, &accessBitmap) < 0) {
        printf("pgaccess failed\n");
        exit(1);
    }
    for (int i = 0; i < num_pages; i++) {
        int accessed = (accessBitmap >> i) & 1;
        printf("Page %d, accessed: %d\n", i, accessed);
    }
    exit(0);
}
