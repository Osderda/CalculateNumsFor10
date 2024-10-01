// Calcute.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>  

static std::vector<std::string> maths;
static int tryed_combs = 0;
static int tryed_calcutes = 0;
static int sucess_calcutes = 0;

double op(double a, char op, double b) {
    tryed_calcutes++;
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0;
    default: return 0;
    }
}

void tryMonkeys(const std::vector<int>& nums, double requestNum) {
    std::vector<char> operations = { '+', '-', '*', '/' };

    for (char op1 : operations) {
        for (char op2 : operations) {
            for (char op3 : operations) {
                tryed_combs++;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                // 1. (a op1 b) op2 (c op3 d)
                double result = op(op(nums[0], op1, nums[1]), op2, op(nums[2], op3, nums[3]));
                std::cout << "Deneniyor: " << "(" << nums[0] << " " << op1 << " " << nums[1] << ") " << op2 << " (" << nums[2] << " " << op3 << " " << nums[3] << ") = " << result << "\n";

                if (result == requestNum) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    std::stringstream dataa{};
                    dataa << "(" << nums[0] << " " << op1 << " " << nums[1] << ") " << op2 << " (" << nums[2] << " " << op3 << " " << nums[3] << ") = " << result << "\n";

                    maths.push_back(dataa.str());

                    std::cout << "Bulundu!: " << dataa.str() << std::endl;
                    sucess_calcutes++;
                }

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                // 2. (a op1 (b op2 c)) op3 d
                result = op(op(nums[0], op1, op(nums[1], op2, nums[2])), op3, nums[3]);
                std::cout << "Deneniyor: " << "(" << nums[0] << " " << op1 << " (" << nums[1] << " " << op2 << " " << nums[2] << ")) " << op3 << " " << nums[3] << " = " << result << "\n";
                if (result == requestNum) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    std::stringstream dataa{};
                    dataa << "(" << nums[0] << " " << op1 << " (" << nums[1] << " " << op2 << " " << nums[2] << ")) " << op3 << " " << nums[3] << " = " << result<<"\n";

                    maths.push_back(dataa.str());

                    std::cout << "Bulundu!: " << dataa.str() << std::endl;
                    sucess_calcutes++;
                }

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                // 3. a op1 ((b op2 c) op3 d)
                result = op(nums[0], op1, op(op(nums[1], op2, nums[2]), op3, nums[3]));
                std::cout << "Deneniyor: " << nums[0] << " " << op1 << " ((" << nums[1] << " " << op2 << " " << nums[2] << ") " << op3 << " " << nums[3] << ") = " << result << "\n";
                if (result == requestNum) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    std::stringstream dataa{};
                    dataa << nums[0] << " " << op1 << " ((" << nums[1] << " " << op2 << " " << nums[2] << ") " << op3 << " " << nums[3] << ") = " << result << "\n";

                    maths.push_back(dataa.str());

                    std::cout << "Bulundu!: " << dataa.str() << std::endl;
                    sucess_calcutes++;
                }

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                // 4. (a op1 b op2 c) op3 d
                result = op(op(op(nums[0], op1, nums[1]), op2, nums[2]), op3, nums[3]);
                std::cout << "Deneniyor: " << "(" << nums[0] << " " << op1 << " " << nums[1] << " " << op2 << " " << nums[2] << ") " << op3 << " " << nums[3] << " = " << result << "\n";
                if (result == requestNum) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    std::stringstream dataa{};
                    dataa << "(" << nums[0] << " " << op1 << " " << nums[1] << " " << op2 << " " << nums[2] << ") " << op3 << " " << nums[3] << " = " << result << "\n";

                    maths.push_back(dataa.str());

                    std::cout << "Bulundu!: " << dataa.str() << std::endl;
                    sucess_calcutes++;
                }

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                // 5. a op1 b op2 c op3 d
                result = op(op(op(nums[0], op1, nums[1]), op2, nums[2]), op3, nums[3]);
                std::cout << "Deneniyor: " << nums[0] << " " << op1 << " " << nums[1] << " " << op2 << " " << nums[2] << " " << op3 << " " << nums[3] << " = " << result << "\n";
                if (result == requestNum) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    std::stringstream dataa{};
                    dataa << nums[0] << " " << op1 << " " << nums[1] << " " << op2 << " " << nums[2] << " " << op3 << " " << nums[3] << " = " << result << "\n";

                    maths.push_back(dataa.str());

                    std::cout << "Bulundu!: " << dataa.str() << std::endl;
                    sucess_calcutes++;
                }


            }
        }
    }
}

int main() {
    system("pause");
    std::vector<int> numbers = { 3, 4, 7, 8 }; //ONLY 4 numb (:
    int req = 10;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    
    printf("[!] Hesaplanacak sayilar: ");
    for (size_t i = 0; i < numbers.size(); i++)
    {
        printf("%i.", numbers[i]);
    }
    printf("\n");
    printf("[!] Aranacak Sonuc: %i\n", req);
    Sleep(2100);
    do {
        tryMonkeys(numbers, req);
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    if (sucess_calcutes != 0)
    {
        printf("\n");
        for (size_t i = 0; i < maths.size(); i++)
        {
            printf("[+] %i. Bulunan Hesaplama: %s\n", i+1, maths[i].c_str());
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("[>] %i Adet Cozum Bulundu!\n", sucess_calcutes);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("[!] Cozum Bulunamadı! = %i\n", sucess_calcutes);

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("[>] %i Adet Kombinasyon Denendi!\n", tryed_combs);
    printf("[>] %i Adet Hesaplama Denendi!\n", tryed_calcutes);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause");
    return 0;
}