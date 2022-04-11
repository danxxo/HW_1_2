#include <algorithm>
#include <random>
#include <gtest/gtest.h>
#include <array>
#include <chrono>

///создание массивов разных рамзеров внутри тестов
class SortTest : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        auto gen = [this]() {
            return number_distance(mercenne_engine);
        };
        arr_10.resize(10);
        arr_100.resize(100);
        arr_1000.resize(1000);
        arr_10000.resize(10000);
        arr_100000.resize(100000);
        arr_250000.resize(250000);
        std::generate(arr_10.begin(), arr_10.end(), gen);
        std::generate(arr_100.begin(), arr_100.end(), gen);
        std::generate(arr_1000.begin(), arr_1000.end(), gen);
        std::generate(arr_10000.begin(), arr_10000.end(), gen);
        std::generate(arr_100000.begin(), arr_100000.end(), gen);
        std::generate(arr_250000.begin(), arr_250000.end(), gen);
    }

    void TearDown() override {
        Test::TearDown();
    }

public:
    std::vector<int> arr_10;
    std::vector<int> arr_100;
    std::vector<int> arr_1000;
    std::vector<int> arr_10000;
    std::vector<int> arr_100000;
    std::vector<int> arr_250000;
    std::vector<void *> arrays{&arr_10, &arr_100, &arr_1000, &arr_10000, &arr_10000, &arr_250000};
//
private:
    std::random_device rnd_device;
    std::mt19937 mercenne_engine{rnd_device()};
    std::uniform_int_distribution<int> number_distance{1, 1000000};
};

///класс секундомера
class Timer {
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<int64_t, std::nano> duration = end - start;
        std::cout << "time : " << duration.count() << " nanosec" << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point start, end;
};


///свап
template<typename T>
void swap(T &num1, T &num2) {
    T k = num1;
    num1 = num2;
    num2 = k;
};

///insertion already using iterators
template<typename Iterator>
void insertion_sort(Iterator begin, Iterator end) {
    for (Iterator i = begin + 1; i < end; i++) {
        Iterator j = i;
        while (j > begin && *(j - 1) > *j) {
            swap(*(j - 1), *j);
            j--;
        }
    }
}

//void merge_sort(int* array, size_t size){
//
//}

///bubble_sort already using Iterators
template<typename Iterator>
void bubble_sort(Iterator begin, Iterator end) {
    if (std::distance(begin, end) <= 1) return;
    bool bubble_condition = true;
    while (bubble_condition) {
        bubble_condition = false;
        for (Iterator runner = begin; runner + 1 < end; runner++) {
            if (*runner > *(runner + 1)) {
                swap(*runner, *(runner + 1));
                bubble_condition = true;
            }
        }
        end--;
    }
}

///quick_sort already using Iterators
template<typename Iterator>
void quick_sort(Iterator begin, Iterator end) {
    size_t size = std::distance(begin, end);
    if (size <= 1) return;
    int central_num = *(begin + size / 2);
    Iterator another_begin = begin, another_end = end - 1;
    while (another_begin <= another_end) {
        while (*another_begin < central_num) another_begin++;
        while (*another_end > central_num) another_end--;
        if (another_begin <= another_end) {
            swap(*another_begin, *another_end);
            another_begin++;
            another_end--;
        }
    }
    if (begin < another_end) quick_sort(begin, another_end + 1);
    if (another_begin < end) quick_sort(another_begin, end);
}

///merge using Iterators
template<typename Iterator>
void merge_sort(Iterator begin, Iterator end) {
    size_t size = std::distance(begin, end);
    if (size > 1) {
        size_t left_size = size / 2;
        size_t right_size = size - left_size;
        Iterator sep = begin;
        std::advance(begin, left_size);
        merge_sort(sep, begin);
        merge_sort(begin, end);
        std::advance(begin, -left_size);
        size_t lindex = 0, rindex = left_size, index = 0;
        Iterator *tmp_array = new Iterator[size];
        while (lindex < left_size || rindex < size) {
            std::advance(begin, lindex);
            Iterator lin = begin;
            std::advance(begin, -lindex);
            std::advance(begin, rindex);
            Iterator rin = begin;
            std::advance(begin, -rindex);
            if (*lin < *rin) {
                std::advance(begin, lindex);
                tmp_array[index++] = begin;
                std::advance(begin, -lindex);
                ++lindex;
            } else {
                std::advance(begin, rindex);
                tmp_array[index++] = begin;
                std::advance(begin, -rindex);
                ++rindex;
            }
            if (lindex == left_size) {
                for (size_t i = rindex; i < size; i++) {
                    std::advance(begin, i);
                    tmp_array[index++] = begin;
                    std::advance(begin, -i);
                }
                break;
            }
            if (rindex == size) {
                for (size_t i = lindex; i < left_size; i++) {
                    std::advance(begin, i);
                    tmp_array[index++] = begin;
                    std::advance(begin, -i);
                }
                break;
            }
        }
        std::vector<typeof(*begin)> tmp_array2;
        tmp_array2.resize(size);
        for (int i = 0; i < size; ++i)
            tmp_array2[i] = *tmp_array[i];
        for (auto i = 0; i < size; ++i) {
            std::advance(begin, i);
            *begin = tmp_array2[i];
            std::advance(begin, -i);
        }
        delete[] tmp_array;
    }
}

///функция которая берет опорное число и разбивает массив на две части
///слева то что меньше опоры, справа то что больше
template<typename T>
int partition(T &array, int low, int high) {

    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

///функция быстрой сортировки используя в кач-ве аргументов массив и два крайних числа
template<typename T>
void quicksort(T &array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

///функция которая берет число стоящему на position_min и ставит его на позицию final_position_min
///смещая все числа впереди указанного на 1 позицию вперед
template<typename T>
void min_to_up__others_down(T &array, int position_min, int final_position_min) {
    int i = position_min;
    typeof(array[i]) min = array[i];
    int j = final_position_min;
    i--;
    while (i >= j) {
        array[i + 1] = array[i];
        i--;
    }
    array[j] = min;
}

///puziryok
template<typename T>
void puzir_sort(T &array, size_t size) {
    ///ищем максимальное число чтобы избежать проблем с минимальным
    typeof(array[size - 1]) max = array[0];
    for (int k = 0; k < size - 1; k++) {
        if (size == 1) break;
        if ((array[k] <= array[k + 1]) && (max <= array[k + 1])) max = array[k + 1];
    }
    typeof(max) min = max + 1;
    int min_pos = 0;
    int j = 0;
    int i = 0;
    ///реализация бабл сорт
    while (j < size) {
        while (i < size) {
            if (array[i] < min) {
                min = array[i];
                min_pos = i;
            }
            i++;
        }
        min_to_up__others_down(array, min_pos, j);
        min = max + 1;
        min_pos = 0;
        i = j + 1;
        j++;
    }
}

///insertion already using array and size
template<typename T>
void insertion_sort_array_size(T &array, size_t size) {
    int i, j;
    typeof(array[size - 1]) key;
    for (i = 1; i < size; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
    }
}
