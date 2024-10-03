//
// Created by saver05 on 10/3/24.
//

#include "user.h"
#include "kernel/types.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: getfilenum pid...\n");
    exit(1);
  }
    int result = getfilenum(atoi(argv[1]));
    printf("%d\n", result);
    exit(0);
}