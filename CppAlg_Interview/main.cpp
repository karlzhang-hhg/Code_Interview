/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: kungangzhang
 *
 * Created on March 8, 2019, 3:13 PM
 */

#include <cstdlib>
#include <iostream>
#include "Int_Weride_20190307.hpp"

/*
 *
 */
int main(int argc, char** argv) {
    const string fname0="int_weride_test0.txt";
    cout<<OPLen(fname0)<<endl;

    const string fname1="int_weride_test1.txt";
    cout<<OPLen(fname1)<<endl;

    const string fname2="int_weride_test2.txt";
    cout<<OPLen(fname2)<<endl;

    const string fname3="int_weride_test3.txt";
    cout<<OPLen(fname3)<<endl;

    return 0;
}
