#include <gtest/gtest.h>
#include <string>
#include "sorts.cpp"


TEST_F(SortTest, swap){
    long a = 15;
    long b = 100;
    swap(a,b);
    EXPECT_EQ(a,100);
    EXPECT_EQ(b,15);
}

TEST_F(SortTest, insertion_10){
    arr_10;
    size_t vec_size = arr_10.size();
    insertion_sort(arr_10, vec_size);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10[i-1] <= arr_10[i]);
    }
}

TEST_F(SortTest, insertion_10000){
    arr_10000;
    size_t vec_size = arr_10000.size();
    insertion_sort(arr_10000, vec_size);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10000[i-1] <= arr_10000[i]);
    }
}
TEST_F(SortTest, bubblesort_10){
    arr_10;
    size_t vec_size = arr_10.size();
    puzir_sort(arr_10, vec_size);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10[i-1] <= arr_10[i]);
    }
}
TEST_F(SortTest, bubblesort_10000){
    arr_10000;
    size_t vec_size = arr_10000.size();
    puzir_sort(arr_10000, vec_size);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10000[i-1] <= arr_10000[i]);
    }
}

TEST_F(SortTest, quicksort_10){
    arr_10;
    size_t vec_size = arr_10.size();
    quicksort(arr_10, 0, arr_10.size() - 1);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10[i-1] <= arr_10[i]);
    }
}
TEST_F(SortTest, quicksort_10000){
    arr_10000;
    size_t vec_size = arr_10.size();
    quicksort(arr_10, 0, arr_10.size() - 1);
    for(int i = 1; i < vec_size; i++){
        EXPECT_TRUE(arr_10[i-1] <= arr_10[i]);
    }
}
TEST_F(SortTest, merge10){
    arr_10;
    merge_sort(arr_10.begin(), arr_10.end());
    for(int i = 1; i < arr_10.size(); i++){
        EXPECT_TRUE(arr_10[i-1] <= arr_10[i]);
    }
}
