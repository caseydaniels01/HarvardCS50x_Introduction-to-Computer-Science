#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = ((image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtGreen= round(avg);
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            if(sRed > 255)
            {
                sRed = 255;
            }

            int sGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            if(sGreen > 255)
            {
                sGreen = 255;
            }

            int sBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if(sBlue > 255)
            {
                sBlue = 255;
            }

            image[i][j].rgbtGreen= sGreen;
            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtBlue = sBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
            if(width % 2 == 0) //even
            {
                for (int j = 0; j < width / 2; j++)
                {
                    int tempRedEven = image[i][j].rgbtRed;
                    int tempGreenEven = image[i][j].rgbtGreen;
                    int tempBlueEven = image[i][j].rgbtBlue;

                    image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
                    image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

                    image[i][width - j - 1].rgbtGreen = tempGreenEven;
                    image[i][width - j - 1].rgbtRed = tempRedEven;
                    image[i][width - j - 1].rgbtBlue = tempBlueEven;
                }
            }
          else
            {
                for (int j = 0; j < width / 2; j++)
                {
                    int tempRedEven = image[i][j].rgbtRed;
                    int tempGreenEven = image[i][j].rgbtGreen;
                    int tempBlueEven = image[i][j].rgbtBlue;

                    image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
                    image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

                    image[i][width - j - 1].rgbtGreen = tempGreenEven;
                    image[i][width - j - 1].rgbtRed = tempRedEven;
                    image[i][width - j - 1].rgbtBlue = tempBlueEven;
                }
            }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        BYTE rgbtGreen;
        BYTE rgbtRed;
        BYTE rgbtBlue;
    } temp;

    temp tempImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tempImage[i][j].rgbtRed = image[i][j].rgbtRed;
            tempImage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    image[0][0].rgbtGreen = round((tempImage[0][0].rgbtGreen + tempImage[0][1].rgbtGreen + tempImage[1][0].rgbtGreen + tempImage[1][1].rgbtGreen) / 4.0);
    image[0][0].rgbtRed = round((tempImage[0][0].rgbtRed + tempImage[0][1].rgbtRed + tempImage[1][0].rgbtRed + tempImage[1][1].rgbtRed) / 4.0);
    image[0][0].rgbtBlue = round((tempImage[0][0].rgbtBlue + tempImage[0][1].rgbtBlue + tempImage[1][0].rgbtBlue + tempImage[1][1].rgbtBlue) / 4.0);

    image[height][width].rgbtGreen = round((tempImage[height][width].rgbtGreen + tempImage[height-1][width].rgbtGreen + tempImage[height][width-1].rgbtGreen + tempImage[height-1][width-1].rgbtGreen) / 4.0);
    image[height][width].rgbtRed = round((tempImage[height][width].rgbtRed + tempImage[height-1][width].rgbtRed + tempImage[height][width-1].rgbtRed + tempImage[height-1][width-1].rgbtRed) / 4.0);
    image[height][width].rgbtBlue = round((tempImage[height][width].rgbtBlue + tempImage[height-1][width].rgbtBlue + tempImage[height][width-1].rgbtBlue + tempImage[height-1][width-1].rgbtBlue) / 4.0);

    image[0][width].rgbtGreen = round((tempImage[0][width].rgbtGreen + tempImage[1][width].rgbtGreen + tempImage[0][width-1].rgbtGreen + tempImage[1][width-1].rgbtGreen) / 4.0);
    image[0][width].rgbtRed = round((tempImage[0][width].rgbtRed + tempImage[1][width].rgbtRed + tempImage[0][width-1].rgbtRed + tempImage[1][width-1].rgbtRed) / 4.0);
    image[0][width].rgbtBlue = round((tempImage[0][width].rgbtBlue + tempImage[1][width].rgbtBlue + tempImage[0][width-1].rgbtBlue + tempImage[1][width-1].rgbtBlue) / 4.0);

    image[height][0].rgbtGreen = round((tempImage[height][0].rgbtGreen + tempImage[height][1].rgbtGreen + tempImage[height-1][0].rgbtGreen + tempImage[height-1][1].rgbtGreen) / 4.0);
    image[height][0].rgbtRed = round((tempImage[height][0].rgbtRed + tempImage[height][1].rgbtRed + tempImage[height-1][0].rgbtRed + tempImage[height-1][1].rgbtRed) / 4.0);
    image[height][0].rgbtBlue = round((tempImage[height][0].rgbtBlue + tempImage[height][1].rgbtBlue + tempImage[height-1][0].rgbtBlue + tempImage[height-1][1].rgbtBlue) / 4.0);

    for (int q = 1; q < (height - 1); q++)
    {
        image[q][0].rgbtGreen = round((tempImage[q][0].rgbtGreen + tempImage[q-1][0].rgbtGreen + tempImage[q+1][0].rgbtGreen + tempImage[q][1].rgbtGreen + tempImage[q-1][1].rgbtGreen + tempImage[q+1][1].rgbtGreen) / 6.0);
        image[q][0].rgbtRed = round((tempImage[q][0].rgbtRed + tempImage[q-1][0].rgbtRed + tempImage[q+1][0].rgbtRed + tempImage[q][1].rgbtRed + tempImage[q-1][1].rgbtRed + tempImage[q+1][1].rgbtRed) / 6.0);
        image[q][0].rgbtBlue = round((tempImage[q][0].rgbtBlue + tempImage[q-1][0].rgbtBlue + tempImage[q+1][0].rgbtBlue + tempImage[q][1].rgbtBlue + tempImage[q-1][1].rgbtBlue + tempImage[q+1][1].rgbtBlue) / 6.0);

        //image[q][width+1].rgbtGreen = round((tempImage[q][width].rgbtGreen + tempImage[q-1][width].rgbtGreen + tempImage[q+1][width].rgbtGreen + tempImage[q][width-1].rgbtGreen + tempImage[q-1][width-1].rgbtGreen + tempImage[q+1][width-1].rgbtGreen) / 6.0);
        //image[q][width+1].rgbtRed = round((tempImage[q][width].rgbtRed + tempImage[q-1][width].rgbtRed + tempImage[q+1][width].rgbtRed + tempImage[q][width-1].rgbtRed + tempImage[q-1][width-1].rgbtRed + tempImage[q+1][width-1].rgbtRed) / 6.0);
        //image[q][width+1].rgbtBlue = round((tempImage[q][width].rgbtBlue + tempImage[q-1][width].rgbtBlue + tempImage[q+1][width].rgbtBlue + tempImage[q][width-1].rgbtBlue + tempImage[q-1][width-1].rgbtBlue + tempImage[q+1][width-1].rgbtBlue) / 6.0);
    }

    for (int k = 1; k < (width - 1); k++)
    {
        image[0][k].rgbtGreen = round((tempImage[0][k].rgbtGreen + tempImage[0][k-1].rgbtGreen + tempImage[0][k+1].rgbtGreen + tempImage[1][k].rgbtGreen + tempImage[1][k-1].rgbtGreen + tempImage[1][k+1].rgbtGreen) / 6.0);
        image[0][k].rgbtRed = round((tempImage[0][k].rgbtRed + tempImage[0][k-1].rgbtRed + tempImage[0][k+1].rgbtRed + tempImage[1][k].rgbtRed + tempImage[1][k-1].rgbtRed + tempImage[1][k+1].rgbtRed) / 6.0);
        image[0][k].rgbtBlue = round((tempImage[0][k].rgbtBlue + tempImage[0][k-1].rgbtBlue + tempImage[0][k+1].rgbtBlue + tempImage[1][k].rgbtBlue + tempImage[1][k-1].rgbtBlue + tempImage[1][k+1].rgbtBlue) / 6.0);

        //image[height+1][k].rgbtGreen = round((tempImage[height][k].rgbtGreen + tempImage[height][k-1].rgbtGreen + tempImage[height][k+1].rgbtGreen + tempImage[height-1][k].rgbtGreen + tempImage[height-1][k-1].rgbtGreen + tempImage[height-1][k+1].rgbtGreen) / 6.0);
        //image[height+1][k].rgbtRed = round((tempImage[height][k].rgbtRed + tempImage[height][k-1].rgbtRed + tempImage[height][k+1].rgbtRed + tempImage[height-1][k].rgbtRed + tempImage[height-1][k-1].rgbtRed + tempImage[height-1][k+1].rgbtRed) / 6.0);
        //image[height+1][k].rgbtBlue = round((tempImage[height][k].rgbtBlue + tempImage[height][k-1].rgbtBlue + tempImage[height][k+1].rgbtBlue + tempImage[height-1][k].rgbtBlue + tempImage[height-1][k-1].rgbtBlue + tempImage[height-1][k+1].rgbtBlue) / 6.0);
    }

    for (int e = 1; e < (height - 1); e++)
    {
        //image[e][width].rgbtGreen = round((tempImage[q][0].rgbtGreen + tempImage[q-1][0].rgbtGreen + tempImage[q+1][0].rgbtGreen + tempImage[q][1].rgbtGreen + tempImage[q-1][1].rgbtGreen + tempImage[q+1][1].rgbtGreen) / 6.0);
        //image[e][width].rgbtRed = round((tempImage[q][0].rgbtRed + tempImage[q-1][0].rgbtRed + tempImage[q+1][0].rgbtRed + tempImage[q][1].rgbtRed + tempImage[q-1][1].rgbtRed + tempImage[q+1][1].rgbtRed) / 6.0);
        //image[e][width].rgbtBlue = round((tempImage[q][0].rgbtBlue + tempImage[q-1][0].rgbtBlue + tempImage[q+1][0].rgbtBlue + tempImage[q][1].rgbtBlue + tempImage[q-1][1].rgbtBlue + tempImage[q+1][1].rgbtBlue) / 6.0);

        image[e-1][width].rgbtGreen = 42;
        image[e-1][width].rgbtRed = 42;
        image[e-1][width].rgbtBlue = 42;
    }


    /*for (int i = 1; i < (height - 1); i++)
    {
        for (int j = 1; j < (width - 1); j++)
        {
            image[i][j].rgbtGreen = round((tempImage[i+1][j-1].rgbtGreen + tempImage[i+1][j].rgbtGreen + tempImage[i+1][j+1].rgbtGreen + tempImage[i][j-1].rgbtGreen + tempImage[i][j].rgbtGreen + tempImage[i][j+1].rgbtGreen + tempImage[i-1][j-1].rgbtGreen + tempImage[i-1][j].rgbtGreen + tempImage[i-1][j+1].rgbtGreen) / 9.0);
            image[i][j].rgbtRed = round((tempImage[i+1][j-1].rgbtRed + tempImage[i+1][j].rgbtRed + tempImage[i+1][j+1].rgbtRed + tempImage[i][j-1].rgbtRed + tempImage[i][j].rgbtRed + tempImage[i][j+1].rgbtRed + tempImage[i-1][j-1].rgbtRed + tempImage[i-1][j].rgbtRed + tempImage[i-1][j+1].rgbtRed) / 9.0);
            image[i][j].rgbtBlue = round((tempImage[i+1][j-1].rgbtBlue + tempImage[i+1][j].rgbtBlue + tempImage[i+1][j+1].rgbtBlue + tempImage[i][j-1].rgbtBlue + tempImage[i][j].rgbtBlue + tempImage[i][j+1].rgbtBlue + tempImage[i-1][j-1].rgbtBlue + tempImage[i-1][j].rgbtBlue + tempImage[i-1][j+1].rgbtBlue) / 9.0);
        }
    }*/

    return;
}
