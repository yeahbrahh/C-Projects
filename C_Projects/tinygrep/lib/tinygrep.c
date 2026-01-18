#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>

int count = 0;
int line_number = 0;

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
            
            line_number++;
            
            if (target[j] == '\0')
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            count++;

            if (!print_matches)
            {
                if (print_line_nums)
                {
                    printf("%i: %s", line_number, buffer);
                }
            }
            else
            {
                printf("%s", buffer);
            }
        }
    }


}



int main(const int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Wrong number of arguments, Expected: 3+\n Actual: %d\n", argc);

    }

    char *target = NULL;
    char *filename = NULL;

    for (int i = 1; i < argc; i++)
{
    if (argv[i][0] == '-')
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            case_insensitive = true;
        }
        else if (strcmp(argv[i], "-n") == 0)
        {
            print_line_nums = true;
        }
        else if (strcmp(argv[i], "-c") == 0)
        {
            print_matches = true;
        }
    }
    else if (target == NULL)
    {
        target = argv[i];
    }
    else if (filename == NULL)
    {
        filename = argv[i];
    }
}

        
    if (target == NULL || filename == NULL )
    {
        printf("Search failed. \n");
        return 1;
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    
    read_lines(file, target);

    fclose(file);
}