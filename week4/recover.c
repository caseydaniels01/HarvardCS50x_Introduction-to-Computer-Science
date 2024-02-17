#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

    while (fread(buffer, 1, 512, card) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(file, "%03i.jpg", count);
                pics = fopen(file, "w");
                if (pics == NULL)
                {
                    printf("jpeg file cannot be opened\n");
                    return 2;
                }
                fwrite(buffer, sizeof(buffer), 512, pics);
                fclose(pics);
                count++;
        }
    }
    fclose(pics);
    fclose(card);
}
