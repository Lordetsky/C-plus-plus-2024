///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Read a single integer n from the file. In another file, write a matrix filled 
/// in the following way:
/// 1   2   3   4
/// 8   7   6   5
/// 9   10  11  12
/// 16  15  14  13
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 

void createMatrix(const std::string& filePath, int size){
    std::ofstream file(filePath);

    std::vector<std::vector<int>> matrix;
    std::vector<int> row;

    for (int i = 0; i < size; i++){
        matrix.push_back(row);

        for (int j = 0; j < size; j++) matrix[i].push_back(i * size + j + 1);
    }

    for (auto num : matrix){
        for (int j = 0; j < size; j++){
            file << num[j] << '\t';
        }
        file << '\n';
    }

    file.close();
}

int main() {
    std::ifstream file("/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem3_matrix/input.txt");
    std::string n;
    file >> n;
    file.close();

    createMatrix("/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem3_matrix/file.txt",
                 std::stoi(n));
    return 0;
}