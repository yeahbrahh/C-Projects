#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



int count = 0;

void read_lines(const char *target)
{
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
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


void n_read_lines(const char *target)
{
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
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

void c_read_lines(int count)
{     
    printf("%i\n", count);

}


void invert_match() 
{

}

void check_flags(char *flags[])
{
    if (flags == NULL) 
    {
        return;
    }
    printf("%s",  flags);
    for (int i = 1; flags[i] != '\0'; i++)
        switch (flags[i] != '\0') 
        {
            case 'n':
            print_line_nums();
            i++;

            case 'c':            
            print_count();
            i++;

            case 'v':
            invert_match();
            i++;
        }
}


int main(const int argc, char *argv[])
{

    if (argc > 2 || argc < 1)
    {
        fprintf(stderr, "Incorrect number of arguments, expected 2; got %i\n ", argc);
    }
    if (argv[1] != NULL)
    {
        fprintf(stderr, "Invalid argument (NULL)\n");
    }

    char *arg = argv[1];
    char first = *arg;

    if (first == '-')
    {
        check_flags(argv[1]);
        
    }
    else {
        read_lines(argv[1]);

    }


}