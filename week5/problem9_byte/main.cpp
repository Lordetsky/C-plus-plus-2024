///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to copy a binary file to another file in reverse byte order.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

void createBinaryFile(const std::string& filePath) {
    // Открываем файл для записи в бинарном режиме
    std::ofstream file(filePath, std::ios::binary);

    // Проверяем, открылся ли файл успешно
    if (!file) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    // Генерируем некоторые данные (можете изменить по своему усмотрению)
    unsigned char data[] = {0x41, 0x42, 0x43, 0x44, 0x45}; // Пример данных

    // Записываем данные в файл
    file.write(reinterpret_cast<char*>(data), sizeof(data));

    // Закрываем файл
    file.close();

    std::cout << "Binary file created successfully: " << filePath << std::endl;
}

void reverseCopyBinaryFile(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream file (inputFilePath, std::ios::in | std::ios::binary);
    std::ofstream up_file (inputFilePath, std::ios::out | std::ios::binary);

    char x;
    while(file.read((char*) &x, sizeof(x))) {
        up_file.write((char *) &x, sizeof(x));
    }

    file.close();
    up_file.close();
}

static std::vector<char> ReadAllBytes(char const* filename)
{
    std::ifstream ifs(filename, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);

    return result;
}

int main(){
    createBinaryFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/cmake-build-debug/input.bin");

    std::vector<char> arr = ReadAllBytes("/Users/senya/CLionProjects/C-plus-plus-2024/week5/cmake-build-debug/input.bin");
    for (auto el : arr) std::cout << el;

    std::cout << '\n';

    reverseCopyBinaryFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/cmake-build-debug/input.bin",
                          "/Users/senya/CLionProjects/C-plus-plus-2024/week5/cmake-build-debug/output.bin");

    arr = ReadAllBytes("/Users/senya/CLionProjects/C-plus-plus-2024/week5/cmake-build-debug/output.bin");
    for (auto el : arr) std::cout << el;

    return 0;
}



//using namespace std;
//struct Student {
//    int roll_no;
//    std::string name;
//};
//
//int main() {
//     ofstream wf("student.dat", ios::out | ios::binary);
//     if(!wf) {
//           cout << "Cannot open file!" << endl;
//           return 1;
//         }
//     Student wstu[3];
//     wstu[0].roll_no = 1;
//     wstu[0].name = "Ram";
//     wstu[1].roll_no = 2;
//     wstu[1].name = "Shyam";
//     wstu[2].roll_no = 3;
//     wstu[2].name = "Madhu";
//     for(int i = 0; i < 3; i++)
//       wf.write((char *) &wstu[i], sizeof(Student));
//     wf.close();
//     if(!wf.good()) {
//           cout << "Error occurred at writing time!" << endl;
//           return 1;
//         }
//     cout<<"Student's Details:"<<endl;
//     for(int i=0; i < 3; i++) {
//           cout << "Roll No: " << wstu[i].roll_no << endl;
//           cout << "Name: " << wstu[i].name << endl;
//           cout << endl;
//         }
//     return 0;
//}