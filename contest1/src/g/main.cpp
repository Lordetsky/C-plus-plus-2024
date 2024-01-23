#include <iostream>


int main()
{
    char **arr;
    int rows = 6, columns = 16;
    char arr_column[columns] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char arr_rows[rows] = {'2', '3', '4', '5', '6', '7'};
    rows++, columns++;
    arr = new char * [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new char [columns];

    for (int i = 1; i < columns; i++) {
        arr[0][i] = arr_column[i - 1];
    }
    for (int i = 1; i < rows; i++) {
        arr[i][0] = arr_rows[i - 1];
    }

    int counter = 32, counter_end = 128;
    for (int i = 1; i < rows; i++){
        for (int j = 1; j < columns; j++){
            if (counter < counter_end) {
                arr[i][j] = static_cast<int>(counter);
                counter++;
            }
            else break;
        }
    }

    int row_counter = 0, column_counter = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++) {
            if (i == 0 && j == 0)
                std::cout << '\t';
            else if (i == rows - 1 && j == columns - 1)
                break;
            else
                std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    delete[] arr;
    return 0;
}