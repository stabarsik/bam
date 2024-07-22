#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string line;
    std::string directory;
    std::string cutdir;
    std::vector<std::string> temp;

    while (std::getline(std::cin, line))
    {
        temp.clear();
        directory = line;
        cutdir = "";
        for (auto it = line.begin(); it != line.end(); ++it)
        {
            if (*it == '_') {
                temp.push_back(cutdir);
                it = line.insert(it, '/');
				it++;
                while(it != line.end() && *it == '_') {
                    cutdir += *it;
                    it++;
                }
                if (it == line.end()) break;
            }
            cutdir += *it;
        }
        temp.push_back(directory);
        temp.push_back(line);
        std::reverse(temp.begin(), temp.end()); // Reverse the arguments
        for (const auto &arg : temp)
        {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}