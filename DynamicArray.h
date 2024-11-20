#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>
#include <set>

template <class T>
class DynamicArray {
private:
    T* array;               // Указатель на массив
    size_t maxSize;         // Максимальный размер массива
    size_t currentSize;     // Текущий размер массива
    static int objectCount; // Статическое поле для подсчета объектов

public:
    // Конструкторы
    DynamicArray(size_t size = 10);
    DynamicArray(const DynamicArray& other);

    // Деструктор
    ~DynamicArray();

    // Методы
    void input();
    void print() const;

    int findMinIndex() const;
    T productBetweenZeros() const;

    // Перегрузка оператора присваивания
    DynamicArray& operator=(const DynamicArray& other);

    // Перегрузка оператора "!=" для проверки на неравенство
    bool operator!=(const DynamicArray& other) const;

    // Перегрузка унарного оператора "-" для удаления дубликатов
    void operator-();

    // Статический метод для получения количества объектов
    static int getObjectCount();
};

// Определение статического члена
template <class T>
int DynamicArray<T>::objectCount = 0;

// Конструктор
template <class T>
DynamicArray<T>::DynamicArray(size_t size)
        : maxSize(size), currentSize(size) {
    array = new T[maxSize];
    ++objectCount;
}

// Конструктор копирования
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
        : maxSize(other.maxSize), currentSize(other.currentSize) {
    array = new T[maxSize];
    for (size_t i = 0; i < currentSize; ++i) {
        array[i] = other.array[i];
    }
    ++objectCount;
}

// Деструктор
template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
    --objectCount;
}

// Ввод элементов массива
template <class T>
void DynamicArray<T>::input() {
    std::cout << "Введите " << currentSize << " элементов массива:\n";
    for (size_t i = 0; i < currentSize; ++i) {
        std::cin >> array[i];
    }
}

// Вывод элементов массива
template <class T>
void DynamicArray<T>::print() const {
    std::cout << "Элементы массива: ";
    for (size_t i = 0; i < currentSize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Поиск индекса минимального элемента
template <class T>
int DynamicArray<T>::findMinIndex() const {
    if (currentSize == 0) {
        throw std::runtime_error("Массив пуст.");
    }

    int minIndex = 0;
    for (size_t i = 1; i < currentSize; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Вычисление произведения элементов между первым и вторым нулями
template <class T>
T DynamicArray<T>::productBetweenZeros() const {
    int firstZero = -1, secondZero = -1;

    // Найти индексы первых двух нулей
    for (size_t i = 0; i < currentSize; ++i) {
        if (array[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;
            } else {
                secondZero = i;
                break;
            }
        }
    }

    // Если недостаточно нулей
    if (firstZero == -1 || secondZero == -1) {
        throw std::runtime_error("Недостаточно нулей в массиве.");
    }

    // Вычислить произведение
    T product = 1;
    for (int i = firstZero + 1; i < secondZero; ++i) {
        product *= array[i];
    }
    return product;
}

// Перегрузка оператора присваивания
template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    delete[] array;

    maxSize = other.maxSize;
    currentSize = other.currentSize;
    array = new T[maxSize];

    for (size_t i = 0; i < currentSize; ++i) {
        array[i] = other.array[i];
    }

    return *this;
}

// Перегрузка оператора "!=" для проверки на неравенство
template <class T>
bool DynamicArray<T>::operator!=(const DynamicArray& other) const {
    if (currentSize != other.currentSize) {
        return true;
    }

    for (size_t i = 0; i < currentSize; ++i) {
        if (array[i] != other.array[i]) {
            return true;
        }
    }

    return false;
}

// Перегрузка унарного оператора "-" для удаления дубликатов
template <class T>
void DynamicArray<T>::operator-() {
    std::set<T> uniqueElements;
    for (size_t i = 0; i < currentSize; ++i) {
        uniqueElements.insert(array[i]);
    }

    delete[] array;

    currentSize = uniqueElements.size();
    maxSize = currentSize;
    array = new T[maxSize];

    size_t index = 0;
    for (const T& elem : uniqueElements) {
        array[index++] = elem;
    }
}

// Получение количества объектов
template <class T>
int DynamicArray<T>::getObjectCount() {
    return objectCount;
}

#endif // DYNAMICARRAY_H
