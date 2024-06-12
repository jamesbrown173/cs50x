
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("height  : ");
    }
    while (height < 1 || height > 8);

    for (int hash_level = 1; hash_level < height + 1; hash_level++)
    {
        int total_single_line_dots = height - hash_level;
        for (int dot_single_line = 0; dot_single_line < total_single_line_dots; dot_single_line++)
        {
            printf(" ");
        }
        for (int single_line = 0; single_line < hash_level; single_line++)
        {
            printf("#");
        }
        printf("  ");
        for (int single_line = 0; single_line < hash_level; single_line++)
        {
            printf("#");
        }

        printf("\n");
    }
}
