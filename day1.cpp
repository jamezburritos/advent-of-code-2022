#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;

#include <string>
using std::string;

int max_sum(const string path)
{
    int max = 0;
    int sum = 0;
    string line;

    ifstream file;
    file.open(path);

    while (file) {
        std::getline(file, line);

        if (line.empty()) {
             if (sum > max) max = sum;
             sum = 0;
        } else {
            sum += std::stoi(line);
        }
    }

    file.close();
    return max;
}

int top3_sum(const string path)
{
    int first = 0;
    int second = 0;
    int third = 0;

    int sum = 0;
    string line;

    ifstream file;
    file.open(path);

    while (file) {
        std::getline(file, line);

        if (line.empty()) {
            if (sum > first) {
                second = first;
                third = second;
                first = sum;
            } else if (sum > second) {
                third = second;
                second = sum;
            } else if (sum > third) {
                third = sum;
            }

            sum = 0;
        } else {
            sum += std::stoi(line);
        }
    }

    file.close();
    return first + second + third;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "usage: " << argv[0] << "<filename>" << '\n';
        return EXIT_FAILURE;
    }

    cout << top3_sum(argv[1]) << '\n';
}
