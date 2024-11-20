#include <iostream>
#include "DynamicArray.h"

int main() {
    try {
        // Создание первого массива для целых чисел
        DynamicArray<int> intArray1(5);
        intArray1.input();
        intArray1.print();

        // Создание второго массива для целых чисел
        DynamicArray<int> intArray2(5);
        intArray2.input();
        intArray2.print();

        // Проверка на неравенство
        if (intArray1 != intArray2) {
            std::cout << "Массивы intArray1 и intArray2 не равны." << std::endl;
        } else {
            std::cout << "Массивы intArray1 и intArray2 равны." << std::endl;
        }

        // Тестирование оператора присваивания
        DynamicArray<int> intArray3;
        intArray3 = intArray1;
        std::cout << "\nСодержимое intArray3 после присваивания intArray1:" << std::endl;
        intArray3.print();

        // Тестирование методов findMinIndex и productBetweenZeros для intArray1
        std::cout << "Индекс минимального элемента в intArray1: " << intArray1.findMinIndex() << std::endl;

        try {
            std::cout << "Произведение элементов между первыми двумя нулями в intArray1: "
                      << intArray1.productBetweenZeros() << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }

        // Удаление дубликатов из первого массива
        -intArray1;
        std::cout << "\nintArray1 после удаления дубликатов:" << std::endl;
        intArray1.print();

        // Проверка количества созданных объектов
        std::cout << "Количество созданных объектов класса с типом int: " << DynamicArray<int>::getObjectCount() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
