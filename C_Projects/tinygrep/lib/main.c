#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>

int count = 0;

bool case_insensitive = false;

bool print_line_nums = false;

bool print_matches = false;

void read_lines(FILE *fp, char *target)
{
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        int found = 0;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            int j = 0;

            while (buffer[i + j] != '\0' && target[j] != '\0' && buffer[i + j] == target[j])
            {
                j++;
            }
            if (target[j] == '\0')
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            printf("%s\n", buffer);
            count++;
        }
    }


}



int main(const int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Wrong number of arguments, Expected: 3+\n Actual: %d\n", argc);

    }

    char *target = argv[1];
    
    FILE *file = fopen(argv[2], "r");

    if (file == NULL)
    {
        printf("File is NULL");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "-i") == 0)
            {
                case_insensitive = true;

            }
            if (strcmp(argv[i], "-n") == 0)
            {
                print_line_nums = true;
            }

            if (strcmp(argv[i], "-c") == 0)
            {
                print_matches = true;
            }
        }
    }
    read_lines(file, target);

    fclose(file);

    return 0;





}