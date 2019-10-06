//
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

#include "lab09_box.hpp"
#include "lab09_produce.hpp"

using namespace std;

// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100 /* in grams */, FruitsAndVeggiesBox::MAX_DAY = 31 /* not checking for Feb 31st */;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2 /* 2019 and 2020 as valid */;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2019;

FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0) {}

FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) :
        order_size(new_order_size) {}

void FruitsAndVeggiesBox::print() {
    // TODO: complete method definition here
    for (int index = 0; index < winter_produce.size(); index++)
        winter_produce[index].print();

    for (int index = 0; index < spring_produce.size(); index++)
        spring_produce[index].print();

    for (int index = 0; index < summer_produce.size(); index++)
        summer_produce[index].print();

    for (int index = 0; index < fall_produce.size(); index++)
        fall_produce[index].print();
    // print each vector separately by invoking class-specific print()
}

int FruitsAndVeggiesBox::size() {
    int cur_size = 0;

    // TODO: complete method definition here
    cur_size += winter_produce.size();
    cur_size += spring_produce.size();
    cur_size += summer_produce.size();
    cur_size += fall_produce.size();

    // add the number of items already inserted

    return cur_size;
}

void FruitsAndVeggiesBox::empty_the_box() {
    // TODO: complete method definition here
        winter_produce.clear();
        spring_produce.clear();
        summer_produce.clear();
        fall_produce.clear();

    // empty the box if some items already inserted
}

void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {
    // TODO: complete method definition here

    // step0. initialize corresponding variables
    ifstream my_ifstream; // create ifstream instance
    string item;

    // step1. open the corresponding file
    my_ifstream.open(file_name);
    if (!my_ifstream.fail()) {
        // step2. load the values from the file
        while (!my_ifstream.eof()){
            getline(my_ifstream, item);
            if (item.size() > 0)
                return_vector.push_back(item);
        }
        // step3. close the file
        my_ifstream.close();
    }
}

void FruitsAndVeggiesBox::load_up_produce_names() {
    // TODO: complete method definition here

    // load up the four files one at a time
    file_to_vector(winter_produce_names, WINTER_FILE);
    file_to_vector(spring_produce_names, SPRING_FILE);
    file_to_vector(summer_produce_names, SUMMER_FILE);
    file_to_vector(fall_produce_names, FALL_FILE);

    // uncomment the following to check what names were loaded
    // print_loaded_names();
}

void FruitsAndVeggiesBox::print_loaded_names() {
    // TODO: complete method definition here
    for (int index = 0; index < winter_produce_names.size(); ++index)
        cout << winter_produce_names[index] <<endl;

    for (int index = 0; index < spring_produce_names.size(); ++index)
        cout << spring_produce_names[index] <<endl;

    for (int index = 0; index < summer_produce_names.size(); ++index)
        cout << summer_produce_names[index] <<endl;

    for (int index = 0; index < fall_produce_names.size(); ++index)
        cout << fall_produce_names[index] <<endl;

    // print each vector separately by listing each group of names separately
}

void FruitsAndVeggiesBox::assign_seasons(int current_month) {
    // remove previously set seasons
    produce_seasons.clear();
    // insert corresponding seasons based on specified rules
    switch (current_month) {
        case JAN:
            produce_seasons.push_back(WINTER);
            break;
        case FEB:
        case MAR:
            produce_seasons.push_back(WINTER);
            produce_seasons.push_back(SPRING);
            break;
        case APR:
            produce_seasons.push_back(SPRING);
            break;
        case MAY:
        case JUN:
            produce_seasons.push_back(SPRING);
            produce_seasons.push_back(SUMMER);
            break;
        case JUL:
            produce_seasons.push_back(SUMMER);
            break;
        case AUG:
        case SEP:
            produce_seasons.push_back(SUMMER);
            produce_seasons.push_back(FALL);
            break;
        case OCT:
            produce_seasons.push_back(FALL);
            break;
        case NOV:
        case DEC:
            produce_seasons.push_back(FALL);
            produce_seasons.push_back(WINTER);
            break;
    }
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
    // generate random values for the current produce item
    rand_item = rand() % vector_size; // random item name
    rand_weight = rand() % MAX_WEIGHT + 1; rand_day = rand() % MAX_DAY + 1;
    rand_month = rand() % MAX_MONTH + 1; rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
    // TODO: complete method definition here

    // step0. initialize corresponding variables
    bool is_unique = true;
    WinterProduce wp;

    // step1. keep repeating this until a unique item is generated

do {
    // step1.1. generate random values for the winter produce item
    generate_random_value(winter_produce_names.size());

    // step1.2. create a new WinterProduce instance with the matching values
    wp = WinterProduce(winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

    // step1.3. iterate through the winter produce vector to check if the item is unique
    for (int i = 0; i < winter_produce.size(); i++) {
        if (winter_produce[i] == wp) {
        is_unique=false;
        }
    }
}while (!is_unique);
    winter_produce.push_back(wp);  // step2. once a unique item is generated, store it into the vector
}

void FruitsAndVeggiesBox::handle_spring_item() {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    bool is_unique = true;
    SpringProduce sp;

    do {
        // step1.1. generate random values for the spring produce item
        generate_random_value(spring_produce_names.size());

        // step1.2. create a new SpringProduce instance with the matching values
        sp = SpringProduce(spring_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the spring produce vector to check if the item is unique
        for (int i = 0; i < spring_produce.size(); i++) {
            if (spring_produce[i] == sp) {
                is_unique = false;
            }
        }
    }while (!is_unique);
    spring_produce.push_back(sp);  // step2. once a unique item is generated, store it into the vector
}

void FruitsAndVeggiesBox::handle_summer_item() {
    // TODO: complete method definition here

    // step0. initialize corresponding variables
    bool is_unique = true;
    SummerProduce sum_p;
    do {
        // step1.1. generate random values for the spring produce item
        generate_random_value(summer_produce_names.size());

        // step1.2. create a new SummerProduce instance with the matching values
       sum_p =SummerProduce(summer_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the summer produce vector to check if the item is unique
        for (int i = 0; i < summer_produce.size(); i++) {
            if (summer_produce[i] == sum_p) {
                is_unique=false;
            }
        }
    }while (!is_unique);
    summer_produce.push_back(sum_p);  // step2. once a unique item is generated, store it into the vector
}

void FruitsAndVeggiesBox::handle_fall_item() {
    // TODO: complete method definition here

    // step0. initialize corresponding variables
    bool is_unique = true;
    FallProduce fp;
    do {
        // step1.1. generate random values for the spring produce item
        generate_random_value(fall_produce_names.size());

        // step1.2. create a new FallProduce instance with the matching values
       fp = FallProduce(fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

        // step1.3. iterate through the fall produce vector to check if the item is unique
        for (int i = 0; i < fall_produce.size(); i++) {
            if (fall_produce[i] == fp) {
                is_unique=false;
            }
        }
    }while (!is_unique);
    fall_produce.push_back(fp);  // step2. once a unique item is generated, store it into the vector
}

void FruitsAndVeggiesBox::insert_unique_item() {
    // TODO: complete method definition here

    // step1. randomly generate a unique produce item

    // step1.1. randomly select a season from available seasons
    rand_season = rand() % produce_seasons.size();

    // step1.2. insert a new unique item with random values into the box
    switch (produce_seasons[rand_season]) {
        case WINTER:
            // step1.3a. insert winter produce item
            handle_winter_item();

            break;

        case SPRING:
            // step1.3b. insert spring produce item
            handle_spring_item();

            break;

        case SUMMER:
            // step1.3c. insert summer produce item
            handle_summer_item();

            break;

        case FALL:
            // step1.3d. insert fall produce item
            handle_fall_item();

            break;
    }
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {
    // TODO: complete method definition here

    // step0. set the randomization seed

    srand(time(0));

    // step1. remove all items if some already inserted

    empty_the_box();

    // step2. load up produce names

    load_up_produce_names();

    // step3. decide which seasons are current

    assign_seasons(current_month);

    // step4. insert matching unique items based on the current seasons
    for (int i=0; i<order_size; i++){
        insert_unique_item();
    }
}
