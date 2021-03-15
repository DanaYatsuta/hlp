#include <iostream>
#include "rational.h"

#define MAX_CHOICE '4'

int main()
{
    setlocale(LC_CTYPE, "rus");

    rational a = rational(1, 2);
    rational b = rational(3, 4);

    bool running = true;
    bool values_updated = true;
    int choice;

    while(running)
    {
        if (values_updated)
        {
            std::cout << "a: " << a << " (" << (double)a << ")" << std::endl <<
                         "b: " << b << " (" << (double)b << ")" << std::endl;
            values_updated = !values_updated;
        }

        std::cout << "1. Сумма a и b." << std::endl <<
                     "2. Сумма a и целого числа." << std::endl <<
                     "3. Прибавить b к a " << std::endl <<
                     "4. Прибавить целое число к a" << std::endl <<
                     "0. Выход" << std::endl;

        do
            choice = getchar();
        while (choice < '0' || choice > MAX_CHOICE );

        switch(choice)
        {
        case '1':
            {
                rational sum = a + b;
                std::cout << "a + b: " << sum << std::endl;
                break;
            }

        case '2':
            {
                int integer;
                std::cout << "Введите целое число: ";
                std::cin >> integer;

                while(std::cin.fail())
                {
                    std::cout << "Ошибка ввода, попробуйте еще раз: ";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    std::cin >> integer;
                }

                rational sum_with_int = a + integer;

                std::cout << "a + " << integer << ": " << sum_with_int << std::endl;
                break;
            }
        case '3':
            {
                a += b;
                values_updated = true;
                break;
            }
        case '4':
            {
                int integer;
                std::cout << "Введите целое число: ";
                std::cin >> integer;

                while(std::cin.fail())
                {
                    std::cout << "Ошибка ввода, попробуйте еще раз: ";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    std::cin >> integer;
                }

                a += integer;
                values_updated = true;
                break;
            }
        case '0':
            running = false;
        }
    }

    return 0;
}
