#include <iostream>
#include <fstream>



int main(int ac,char **av)
{
    std::string line;
   if(ac == 1)
   {
     std::istream db_file(av[1]);
     if(db_file)
     {
        std::getline(db_file,line);
        parse(line);

     }
   }
}