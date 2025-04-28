#include <iostream>
#include <fstream>


static int replace(char **argv, std::string &str)
{
    std::ofstream   outfile;
    int             pos;
    int             i = 0;

    outfile.open((std::string(argv[1]) + ".replace").c_str());
    if (outfile.fail())
        return (std::cout << "Program failed!" << std::endl, 1);
    while (i < (int)str.size())
    {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i)
        {
            outfile << argv[3];
            i += std::string(argv[2]).size();
        }
        else
        {
            outfile << str[i];
            i++;
        }
    }
    outfile.close();
    return (0);
}
int main(int argc, char **argv)
{
    std::ifstream   infile;
    std::string     str;
    char            c;

    if (argc != 4)
        return (std::cout << "Invalid arguments!" << std::endl, 1);
    infile.open(argv[1]);
    if (infile.fail())
        return (std::cout << "Invalid file!" << std::endl, 1);
    while (!infile.eof() && infile >> std::noskipws >> c)
        str += c;
    infile.close();
    return (replace(argv, str));
}