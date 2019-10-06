/*
Student name: Emily Wang
Student number: 20763516
Date: Nov 30, 2018

SYDE 121 Lab: Assignment 8
Filenames: lab_09_main.cpp, lab_09_box.(cpp/hpp), lab_09_produce.(cpp/hpp)
Project: Assignment 8

Purpose: To implement a class Book that stores information about them and create a class Library that constains a
vector of book instances.
 */

#include <iostream>
#include "lab09_box.hpp"
#include "lab09_produce.hpp"
using namespace std;

void test_fill_the_box();
//PURPOSE: Driver function; checks that the FruitsAndVeggiesBox constructors work
//INPUTS: Nothing
//RETURNS: Nothing

void test_produce();
//PURPOSE: Driver function; checks that the Produce constructors work
//INPUTS: Nothing
//RETURNS: Nothing

void test_comparison_operator();
//PURPOSE: Driver function; checks that the comparison operator works
//INPUTS: Nothing
//RETURNS: Nothing


int main() {
test_produce(); // calls driver that tests produce constructors and print function
test_comparison_operator(); //calls the driver function for comparison operator
test_fill_the_box(); //calls the driver function for box

return 0;

}

void test_produce() {
    Produce p1, p2("Carrots", 1, 1, 1, 2019);
    WinterProduce wp1("Carrots", 1, 1, 1, 2019), wp2("Carrot", 1, 1, 1, 2019);
    SpringProduce sp1("Carrots", 2, 1, 1, 2019), sp2("Carrots", 1, 1, 1, 2019);
    SummerProduce smp1("Carrots", 1, 1, 1, 2019), smp2("Carrots", 1, 1, 1, 2020);
    FallProduce fp1("Carrots", 1, 1, 1, 2019), fp2("Carrots", 1, 1, 1, 2019);

    // test print functions
    p2.print();
    wp1.print();
    sp1.print();
    smp1.print();
    fp1.print();

}
void test_comparison_operator(){

    Produce p1, p2("Carrots", 1, 1, 1, 2019);
    WinterProduce wp1("Carrots", 1, 1, 1, 2019), wp2("Carrot", 1, 1, 1, 2019);
    SpringProduce sp1("Carrots", 2, 1, 1, 2019), sp2("Carrots", 1, 1, 1, 2019);
    SummerProduce smp1("Carrots", 1, 1, 1, 2019), smp2("Carrots", 1, 1, 1, 2020);
    FallProduce fp1("Carrots", 1, 1, 1, 2019), fp2("Carrots", 1, 1, 1, 2019);

    cout << (p1 == p2 ? "p1 and p2 are equal" : "p1 and p2 are not equal") << endl;
    cout << (wp1 == wp2 ? "wp1 and wp2 are equal" : "wp1 and wp2 are not equal") << endl;
    cout << (sp1 == sp2 ? "sp1 and sp2 are equal" : "sp1 and sp2 are not equal") << endl;
    cout << (smp1 == smp2 ? "smp1 and smp2 are equal" : "smp1 and smp2 are not equal") << endl;
    cout << (fp1 == fp2 ? "fp1 and fp2 are equal" : "fp1 and fp2 are not equal") << endl;

    // attempt to compare different types; will not compile
    //cout << (sp1 == fp2 ? "fp1 and fp2 are equal" : "fp1 and fp2 are not equal") << endl;
}

void test_fill_the_box(){
    //testing winter produce of all box sizes
    FruitsAndVeggiesBox empty_box, small_order1(5), medium_order1(10), large_order1(15) ;
    empty_box.fill_the_box(1);
    small_order1.fill_the_box(1);
    medium_order1.fill_the_box(1);
    large_order1.fill_the_box(1);
    empty_box.print();
    cout << endl << "Small order" << endl;
    small_order1.print();
    cout << endl << "Medium order:" << endl;
    medium_order1.print();
    cout << endl<< "Large order:" << endl;
    large_order1.print();

    //testing spring/winter produce of all box sizes
    FruitsAndVeggiesBox spring_winter_box(10);
    spring_winter_box.fill_the_box(3);
    cout << endl << "Spring/winter order" << endl;
    spring_winter_box.print();

    //testing spring produce of all box sizes
    FruitsAndVeggiesBox spring_box(5);
    spring_winter_box.fill_the_box(5);
    cout << endl << "Spring order" << endl;
    spring_box.print();

    //testing summer/spring produce of all box sizes
    FruitsAndVeggiesBox spring_summer_box(6);
    spring_summer_box.fill_the_box(5);
    cout << endl << "Spring/Summer order" << endl;
    spring_summer_box.print();

    //testing summer produce of all box sizes
    FruitsAndVeggiesBox summer_box(7);
    summer_box.fill_the_box(10);
    cout << endl << "Summer order" << endl;
    summer_box.print();

    //testing summer/fall produce of all box sizes
    FruitsAndVeggiesBox summer_fall_box(9);
    summer_fall_box.fill_the_box(5);
    cout << endl << "Summer/fall order" << endl;
    summer_fall_box.print();

    //testing summer produce of all box sizes
    FruitsAndVeggiesBox fall_box(9);
    fall_box.fill_the_box(10);
    cout << endl << "Fall order" << endl;
    fall_box.print();

    //testing summer produce of all box sizes
    FruitsAndVeggiesBox fall_winter_box(11);
    fall_winter_box.fill_the_box(11);
    cout << endl << "Fall/Winter order" << endl;
    fall_winter_box.print();
}