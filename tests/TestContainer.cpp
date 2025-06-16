//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../MyContainer.hpp"

using merchav::MyContainer;
TEST_CASE("Add") {
    MyContainer mc = MyContainer();
    mc.add(6);
    mc.add(5);
    
    CHECK(mc.get(0) == 6);
    CHECK(mc.get(1) == 5);

}

TEST_CASE("size") {
    MyContainer mc = MyContainer();
    mc.add(6);
    CHECK(mc.size() == 1);
    mc.add(4);
    CHECK(mc.size() == 2);

}


TEST_CASE("remove") {
    MyContainer mc = MyContainer();
    mc.add(1);
    mc.add(2);
    mc.add(3);
    mc.add(4);
    mc.add(4);
    mc.add(6);
    mc.add(7);

    mc.remove(1);
    CHECK(mc.get(0)==2);
    
    mc.remove(4);
    CHECK(mc.size()==4);
    
    mc.remove(7);
    //CHECK(mc.size()==3);
    CHECK(mc.get(2)==6);

    mc = MyContainer();
    mc.add(1);
    mc.add(2);
    mc.add(3);
    int i=1;
    for (auto it = mc.begin(); it!=mc.end(); ++it){
        CHECK(*it == i);
        i++;
    }
}