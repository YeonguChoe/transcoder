#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    const char *filename = argv[1];

    // open file
    FILE *f = fopen(filename, "rb");

    // CPU Buffer
    size_t buffer_size = (1024 * 1024) * 100;
    unsigned char *buffer = (unsigned char *)malloc(buffer_size);

    // read file to a buffer
    size_t read = fread(buffer, 1, buffer_size, f);

    printf("%s", buffer);

    // deallocate CPU buffer
    free(buffer);

    // close file
    fclose(f);

    return 0;
}
