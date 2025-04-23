#include <iostream>

static void uppercase(char *str)
{
    while(*str)
    {
        std::cout << (char)toupper(*str);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        while(i < argc)
        {
            uppercase(argv[i]);
            i++;
        }
        std::cout << std::endl;
    }
}