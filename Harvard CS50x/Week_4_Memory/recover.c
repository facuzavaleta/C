#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for only 1 argument-line command
    if (argc != 2)
    {
        printf("Usage: ./recover <picture>.jpg\n");
        return 1;
    }

    // Open file
    char *input_file = argv[1];
    FILE *input_pointer = fopen(input_file, "r");

    if (input_pointer == NULL)
    {
        printf("Error: cannot open %s.\n", input_file);
        return 2;
    }
    // Variables
    BYTE buffer[512];
    int count = 0;
    FILE *img_pointer = NULL;
    char filename[8];

    // Repeat until all the card is readed
    while (fread(&buffer, 512, 1, input_pointer) == 1)
    {
        // If start new JPEG read
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not first, close previous
            if (!(count == 0))
            {
                fclose(img_pointer);
            }
            // Initialize file
            sprintf(filename, "%03i.jpg", count);
            img_pointer = fopen(filename, "w");
            count++;
        }
        // If JPEG found, write in file
        if (!(count == 0))
        {
            fwrite(&buffer, 512, 1, img_pointer);
        }
    }
    fclose(input_pointer);
    fclose(img_pointer);

    return 0;
}