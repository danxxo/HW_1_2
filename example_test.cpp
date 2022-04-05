#include <gtest/gtest.h>
#include <string>
#include "sorts.cpp"

TEST_F(SortTest, swap) {
    long a = 15;
    long b = 100;
    swap(a, b);
    EXPECT_EQ(a, 100);
    EXPECT_EQ(b, 15);
}
///arr10
TEST_F(SortTest, insertion_10) {
    arr_10;
    Timer time;
    insertion_sort(arr_10.begin(), arr_10.end());
    for (int i = 1; i < arr_10.size(); i++) {
        EXPECT_TRUE(arr_10[i - 1] <= arr_10[i]);
    }
}
TEST_F(SortTest, bubblesort_10) {
    arr_10;
    Timer time;
    bubble_sort(arr_10.begin(), arr_10.end());
    for (int i = 1; i < arr_10.size(); i++) {
        EXPECT_TRUE(arr_10[i - 1] <= arr_10[i]);
    }
}
TEST_F(SortTest, quicksort_10) {
    arr_10;
    Timer time;
    quick_sort(arr_10.begin(), arr_10.end());
    for (int i = 1; i < arr_10.size(); i++) {
        EXPECT_TRUE(arr_10[i - 1] <= arr_10[i]);
    }
}
TEST_F(SortTest, merge10) {
    arr_10;
    Timer time;
    merge_sort(arr_10.begin(), arr_10.end());
    for (int i = 1; i < arr_10.size(); i++) {
        EXPECT_TRUE(arr_10[i - 1] <= arr_10[i]);
    }
}
TEST_F(SortTest, std_sort_10) {
    arr_10;
    Timer time;
    std::sort(arr_10.begin(), arr_10.end());
    for (int i = 1; i < arr_10.size(); i++) {
        EXPECT_TRUE(arr_10[i - 1] <= arr_10[i]);
    }
}
///arr100
TEST_F(SortTest, insertion_100) {
    arr_100;
    Timer time;
    insertion_sort(arr_100.begin(), arr_100.end());
    for (int i = 1; i < arr_100.size(); i++) {
        EXPECT_TRUE(arr_100[i - 1] <= arr_100[i]);
    }
}
TEST_F(SortTest, bubblesort_100) {
    arr_100;
    Timer time;
    bubble_sort(arr_100.begin(), arr_100.end());
    for (int i = 1; i < arr_100.size(); i++) {
        EXPECT_TRUE(arr_100[i - 1] <= arr_100[i]);
    }
}
TEST_F(SortTest, quicksort_100) {
    arr_100;
    Timer time;
    quick_sort(arr_100.begin(), arr_100.end());
    for (int i = 1; i < arr_100.size(); i++) {
        EXPECT_TRUE(arr_100[i - 1] <= arr_100[i]);
    }
}
TEST_F(SortTest, merge100) {
    arr_100;
    Timer time;
    merge_sort(arr_100.begin(), arr_100.end());
    for (int i = 1; i < arr_100.size(); i++) {
        EXPECT_TRUE(arr_100[i - 1] <= arr_100[i]);
    }
}
TEST_F(SortTest, std_sort_100) {
    arr_100;
    Timer time;
    std::sort(arr_100.begin(), arr_100.end());
    for (int i = 1; i < arr_100.size(); i++) {
        EXPECT_TRUE(arr_100[i - 1] <= arr_100[i]);
    }
}
///arr1000
TEST_F(SortTest, insertion_1000) {
    arr_1000;
    Timer time;
    insertion_sort(arr_1000.begin(), arr_1000.end());
    for (int i = 1; i < arr_1000.size(); i++) {
        EXPECT_TRUE(arr_1000[i - 1] <= arr_1000[i]);
    }
}
TEST_F(SortTest, bubblesort_1000) {
    arr_1000;
    Timer time;
    bubble_sort(arr_1000.begin(), arr_1000.end());
    for (int i = 1; i < arr_1000.size(); i++) {
        EXPECT_TRUE(arr_1000[i - 1] <= arr_1000[i]);
    }
}
TEST_F(SortTest, quicksort_1000) {
    arr_1000;
    Timer time;
    quick_sort(arr_1000.begin(), arr_1000.end());
    for (int i = 1; i < arr_1000.size(); i++) {
        EXPECT_TRUE(arr_1000[i - 1] <= arr_1000[i]);
    }
}
TEST_F(SortTest, merge1000) {
    arr_1000;
    Timer time;
    merge_sort(arr_1000.begin(), arr_1000.end());
    for (int i = 1; i < arr_1000.size(); i++) {
        EXPECT_TRUE(arr_1000[i - 1] <= arr_1000[i]);
    }
}
TEST_F(SortTest, std_sort_1000) {
    arr_1000;
    Timer time;
    std::sort(arr_1000.begin(), arr_1000.end());
    for (int i = 1; i < arr_1000.size(); i++) {
        EXPECT_TRUE(arr_1000[i - 1] <= arr_1000[i]);
    }
}
///arr10000
TEST_F(SortTest, insertion_10000) {
    arr_10000;
    Timer time;
    insertion_sort(arr_10000.begin(), arr_10000.end());
    for (int i = 1; i < arr_10000.size(); i++) {
        EXPECT_TRUE(arr_10000[i - 1] <= arr_10000[i]);
    }
}
TEST_F(SortTest, bubblesort_10000) {
    arr_10000;
    Timer time;
    bubble_sort(arr_10000.begin(), arr_10000.end());
    for (int i = 1; i < arr_10000.size(); i++) {
        EXPECT_TRUE(arr_10000[i - 1] <= arr_10000[i]);
    }
}
TEST_F(SortTest, quicksort_10000) {
    arr_10000;
    Timer time;
    quick_sort(arr_10000.begin(), arr_10000.end());
    for (int i = 1; i < arr_10000.size(); i++) {
        EXPECT_TRUE(arr_10000[i - 1] <= arr_10000[i]);
    }
}
TEST_F(SortTest, merge10000) {
    arr_10000;
    Timer time;
    merge_sort(arr_10000.begin(), arr_10000.end());
    for (int i = 1; i < arr_10000.size(); i++) {
        EXPECT_TRUE(arr_10000[i - 1] <= arr_10000[i]);
    }
}
TEST_F(SortTest, std_sort_10000) {
    arr_10000;
    Timer time;
    std::sort(arr_10000.begin(), arr_10000.end());
    for (int i = 1; i < arr_10000.size(); i++) {
        EXPECT_TRUE(arr_10000[i - 1] <= arr_10000[i]);
    }
}
///arr100000
TEST_F(SortTest, insertion_100000) {
    arr_100000;
    Timer time;
    insertion_sort(arr_100000.begin(), arr_100000.end());
    for (int i = 1; i < arr_100000.size(); i++) {
        EXPECT_TRUE(arr_100000[i - 1] <= arr_100000[i]);
    }
}
TEST_F(SortTest, bubblesort_100000) {
    arr_100000;
    Timer time;
    bubble_sort(arr_100000.begin(), arr_100000.end());
    for (int i = 1; i < arr_100000.size(); i++) {
        EXPECT_TRUE(arr_100000[i - 1] <= arr_100000[i]);
    }
}
TEST_F(SortTest, quicksort_100000) {
    arr_100000;
    Timer time;
    quick_sort(arr_100000.begin(), arr_100000.end());
    for (int i = 1; i < arr_100000.size(); i++) {
        EXPECT_TRUE(arr_100000[i - 1] <= arr_100000[i]);
    }
}
TEST_F(SortTest, merge100000) {
    arr_100000;
    Timer time;
    merge_sort(arr_100000.begin(), arr_100000.end());
    for (int i = 1; i < arr_100000.size(); i++) {
        EXPECT_TRUE(arr_100000[i - 1] <= arr_100000[i]);
    }
}
TEST_F(SortTest, std_sort_100000) {
    arr_100000;
    Timer time;
    std::sort(arr_100000.begin(), arr_100000.end());
    for (int i = 1; i < arr_100000.size(); i++) {
        EXPECT_TRUE(arr_100000[i - 1] <= arr_100000[i]);
    }
}
///arr250000
TEST_F(SortTest, insertion_250000) {
    arr_250000;
    Timer time;
    insertion_sort(arr_250000.begin(), arr_250000.end());
    for (int i = 1; i < arr_250000.size(); i++) {
        EXPECT_TRUE(arr_250000[i - 1] <= arr_250000[i]);
    }
}
TEST_F(SortTest, bubblesort_250000) {
    arr_250000;
    Timer time;
    bubble_sort(arr_250000.begin(), arr_250000.end());
    for (int i = 1; i < arr_250000.size(); i++) {
        EXPECT_TRUE(arr_250000[i - 1] <= arr_250000[i]);
    }
}
TEST_F(SortTest, quicksort_250000) {
    arr_250000;
    Timer time;
    quick_sort(arr_250000.begin(), arr_250000.end());
    for (int i = 1; i < arr_250000.size(); i++) {
        EXPECT_TRUE(arr_250000[i - 1] <= arr_250000[i]);
    }
}
TEST_F(SortTest, merge250000) {
    arr_250000;
    Timer time;
    merge_sort(arr_250000.begin(), arr_250000.end());
    for (int i = 1; i < arr_250000.size(); i++) {
        EXPECT_TRUE(arr_250000[i - 1] <= arr_250000[i]);
    }
}
TEST_F(SortTest, std_sort_250000) {
    arr_250000;
    Timer time;
    std::sort(arr_250000.begin(), arr_250000.end());
    for (int i = 1; i < arr_250000.size(); i++) {
        EXPECT_TRUE(arr_250000[i - 1] <= arr_250000[i]);
    }
}
