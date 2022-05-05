//
//  Algo_FastTests.m
//  Algo FastTests
//
//  Created by Blotenko on 04.05.2022.
//
#import "alogorithms.hpp"
#import <XCTest/XCTest.h>


@interface Algo_FastTests : XCTestCase

@end

@implementation Algo_FastTests

- (void)testquickSort {
    algorithm* al = new algorithm( new class quickSort);
    int* p = new int[5,8,2,6,9,4,10];
    quickSort(p, 7);
    int* data = new int[2,4,5,6,8,9,10];
 XCTAssertEqual(*data, *p); // calling Adder class function
}

- (void)testinsertionSort {
    algorithm* al = new algorithm( new class quickSort);
    int* p = new int[5,8,2,6,9,4,10];
    insertionSort(p, 7);
    int* data = new int[2,4,5,6,8,9,10];
 XCTAssertEqual(*data, *p); // calling Adder class function
}

- (void)testmergeSort {
    algorithm* al = new algorithm( new class quickSort);
    int* p = new int[5,8,2,6,9,4,10];
    mergeSort(p, 7);
    int* data = new int[2,4,5,6,8,9,10];
 XCTAssertEqual(*data, *p); // calling Adder class function
}

- (void)testbubbleSort {
    algorithm* al = new algorithm( new class quickSort);
    int* p = new int[5,8,2,6,9,4,10];
    bubbleSort(p, 7);
    int* data = new int[2,4,5,6,8,9,10];
 XCTAssertEqual(*data, *p); // calling Adder class function
}

@end
