#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *f1 = fopen("lista1.dat", "rb");
    FILE *f2 = fopen("lista2.dat", "rb");
    FILE *f3 = fopen("lista3.dat", "wb");

    unsigned int size = sizeof(int);

    int v1;
    int v2;

    size_t r1;
    size_t r2;

    r1 = fread(&v1, size, 1, f1);
    r2 = fread(&v2, size, 1, f2);

    while(r1 == 1 || r2 == 1)
    {
        if(r1 == 1 && r2 == 0)
        {
            fwrite(&v1, size, 1, f3);
            r1 = fread(&v1, size, 1, f1);
            continue;
        }
        else if(r1 == 0 && r2 == 1)
        {
            fwrite(&v2, size, 1, f3);
            r2 = fread(&v2, size, 1, f2);
            continue;
        }

        if(v1 < v2)
        {
            fwrite(&v1, size, 1, f3);
            r1 = fread(&v1, size, 1, f1);
        }
        else
        {
            fwrite(&v2, size, 1, f3);
            r2 = fread(&v2, size, 1, f2);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}