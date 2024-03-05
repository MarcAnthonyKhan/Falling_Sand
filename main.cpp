#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>     // For std::this_thread::sleep_for
#include <chrono>     // For std::chrono::milliseconds

using namespace std;

const int ROWS{30};
const int COLS{100};


std::vector<string> border(COLS+2, "=");

void printBorder() {
    for (auto i: border) cout << i;
    std::cout << std::endl;
}

void printGrid(std::vector<std::vector<string>> arr){
    printBorder();

    // Printing the array (optional)
    for (int i = 0; i < ROWS; ++i) {
        std::cout << "|";
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << "|";
        std::cout <<  std::endl;
    }

    printBorder();
}

void clearScreen(){
    std::cout << "\033[2J\033[H"; // Clear screen
}

std::pair<int, int> returnPosition(int num){
    int f{0};
    while (num > COLS){
        num -= COLS;
        f++;
    }
    int s{num};
    std::pair<int, int> output(f,s);
    return output;
}

int main(){

    int frames = 50;

    // Create a 2D vector of zeros with dimensions 50x100
    std::vector<std::vector<string>> arr(ROWS, std::vector<string>(COLS, " "));

    std::string sand = ".";
    
    while(frames > 0){
        printGrid(arr);
        cout << "Frames: " << frames << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        clearScreen();
        frames--;
    }

    return 0;
}