#include <stdio.h>
#include <stdlib.h>
 
#include <stdint.h>

int main(int argc, char *argv[])
{

  // Accept a single command-line argument
  if (argc != 2)
  {
    printf("Usage: ./recover <File to recover>\n");
    return 1;
  }

  // Open the memory card
  FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    FILE *img = NULL  ; 
    char filename[8]; // Buffer to store filenames
    int file_count = 0; // Counter for filenames
 
  // While there's still data left to read from the memory card
  while (fread(buffer, 1, 512, card) == 512)
    {
      
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
      {
        // If we already have an open file, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new filename
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create output JPEG %s\n", filename);
                return 1;
            }

             file_count++;
        }

        // If a file is open, write the buffer to the file
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the memory card file
    fclose(card);

    printf("Running \n"); 
    return 0;
}
