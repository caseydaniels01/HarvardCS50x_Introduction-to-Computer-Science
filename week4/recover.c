#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    uint8_t buffer[512];
    int count = 0;
    FILE *pics = NULL;
    char file[8];
    int jpg = 0;

    while (fread(buffer, 1, 512, card))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            jpg = 1;
        }

        if (jpg == 1 && count == 0)
        {
            sprintf(file, "%03i.jpg", count);
            pics = fopen(file, "w");

            if (pics == NULL)
            {
                printf("jpeg file cannot be opened\n");
                return 2;
            }

            fwrite(buffer, 1, 512, pics);
            jpg = 0;
            count++;
        }
        else if (jpg == 1 && count > 0)
        {
            fclose(pics);
            sprintf(file, "%03i.jpg", count);
            pics = fopen(file, "w");

            if (pics == NULL)
            {
                printf("jpeg file cannot be opened\n");
                return 3;
            }

            fwrite(buffer, 1, 512, pics);
            jpg = 0;
            count++;
        }
        else if (count > 0)
        {
            fwrite(buffer, 1, 512, pics);
        }
    }

    fclose(pics);
    fclose(card);
}
