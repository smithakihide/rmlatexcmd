#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <experimental/filesystem>

namespace nfs = std::experimental::filesystem;

int main(int32_t argc, char* argv[])
{
    std::cout << "this is a program to remove the all comments in latex files with recursively resolving input commands\n";
    std::cout << "version 0.1\n\n";
    if(argc < 2)
    {
        std::cout << "set a file name\n";
        return -1;
    }

    std::string filename = argv[1];

    std::fstream fs;
    size_t filesize = nfs::file_size(filename);
    std::cout << "the file size of " << filename << " is " << filesize << "\n";
    fs.open(filename, std::ios::in | std::ios::binary);
    if(!fs.is_open())
    {
        std::cout << "cannot open the file of " << filename << "\n";
    }
    std::vector<char> data(filesize);
    fs.read(data.data(), filesize);
    fs.close();

    class CCmd{
        public:
        CCmd(std::vector<char>, )
        std::vector<char> s_cmd;
        std::function<void()> f_cmd;
        int64_t c_cmd;
    }

    std::vector<CCmd> vCmd;

    for(int64_t i =0;i<data.size();i++)
    {

        if(data[i] == )
    }
}