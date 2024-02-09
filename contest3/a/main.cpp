#include <iostream>
#include <fstream>
#include <vector>


//void TryToOpen(){
//    std::ifstream file;
//    file.open("/Users/senya/CLionProjects/C-plus-plus-2024/contest3/a/input.txt");
//
//    if (file.is_open()) std::cout << "Open";
//    else std::cout << "Not working";
//
//    file.close();
//}

std::vector<int> CheckText(std::ifstream &file){
    int count_letter = 0, count_words = 0, count_lines = 0, counter = 0;
    std::string str;

    while(std::getline(file, str)){
        count_lines++;
        if (!str.empty()) {
            for (char c : str) {
                if (isalpha(c)) {
                    count_letter++;
                    counter++;
                }
                else if (c == ' ' and counter > 0) {
                    count_words++;
                    counter = 0;
                }
            }

            if (counter > 0) {
                count_words++;
                counter = 0;
            }
        }

    }

    std::vector<int> ans = {count_letter, count_words, count_lines};
    return ans;
}

int main()
{
    std::ifstream file("input.txt");
    std::vector<int> ptr (CheckText(file));

    std::cout << "Input file contains:" << '\n'
              << ptr[0] << " letters" << '\n'
              << ptr[1] << " words" << '\n'
              << ptr[2] << " lines";

    file.close();
    return 0;
}