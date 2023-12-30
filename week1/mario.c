#include <stdio.h>

int main(void)
{

    int height;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    switch (height)
    {
        case 1:
            printf("#  #\n");
            break;

        case 2:
            printf(" #  #\n");
            printf("##  ##\n");
            break;

        case 3:
            printf("  #  #\n");
            printf(" ##  ##\n");
            printf("###  ###\n");
            break;

        case 4:
            printf("   #  #\n");
            printf("  ##  ##\n");
            printf(" ###  ###\n");
            printf("####  ####\n");
            break;

        case 5:
            printf("    #  #\n");
            printf("   ##  ##\n");
            printf("  ###  ###\n");
            printf(" ####  ####\n");
            printf("#####  #####\n");
            break;

        case 6:
            printf("     #  #\n");
            printf("    ##  ##\n");
            printf("   ###  ###\n");
            printf("  ####  ####\n");
            printf(" #####  #####\n");
            printf("######  ######\n");
            break;

        case 7:
            printf("      #  #\n");
            printf("     ##  ##\n");
            printf("    ###  ###\n");
            printf("   ####  ####\n");
            printf("  #####  #####\n");
            printf(" ######  ######\n");
            printf("#######  #######\n");
            break;

        case 8:
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
            printf("  ######  ######\n");
            printf(" #######  #######\n");
            printf("########  ########\n");
            break;
    }

    return 0;
}
