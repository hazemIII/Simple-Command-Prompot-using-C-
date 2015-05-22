/* 
 * File:   main.cpp
 * Author: hazem
 *
 * Created on March 7, 2015, 11:01 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "Undefined Command";
        return 0;
    }        //    else if(argc==2)
        //    {cout<<"Incorrect Number of Argument"; // if the command not exist
        //    return 0;
        //    }

    else if (!strcmp(argv[1], "print")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = 2; i <= (argc - 1); i++) {
            cout << argv[i] << ' ';
        }
        //          cout<<argv[(argc-1)];

    } else if (!strcmp(argv[1], "reverse")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = (argc - 1); i >= 2; i--) {
            cout << argv[i] << ' ';
        }
        //          cout<<argv[(argc-1)];

    } else if (!strcmp(argv[1], "upper")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = 2; i <= (argc - 1); i++) {
            string sent = argv[i];
            for (string::iterator i = sent.begin(); i != sent.end(); i++) {
                *i = toupper(*i);

            }
            if (i < (argc - 1))
                cout << sent << ' ';
            else
                cout << sent; //you do not need this so remove!
        }
    } else if (!strcmp(argv[1], "shuffle")) {
        if (argc == 2 || argc >= 4) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }

        for (int i = 2; i <= (argc - 1); i++) {
            string sent = argv[i];
            for (int j = 1; j <= (sent.length() - 1); j = j + 2)
                swap(sent[j], sent[j - 1]);
            cout << sent;
        }


    } else if (!strcmp(argv[1], "shuffleStatement")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = 2; i <= (argc - 1); i = i + 2) {
            string temp = argv[i];
            argv[i] = argv[i + 1];
            if (i != (argc - 1))
                cout << argv[i] << ' ' << temp << ' ';
            else
                cout << temp << ' ';
        }
    } else if (!strcmp(argv[1], "delete")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }

        string dig = argv[2];
        if (!isdigit(dig[0]) && dig[0] != '+' || atoi(argv[2])==0) {
            cout << "Incorrect Data Type";
            return 0;
        }
        int index = atoi(argv[2]); //use is digit to handle the error
        if (atoi(argv[2])>(argc - 3)) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }

        for (int i = 3; i <= (argc - 1); i++) {
            if (i == index + 2)
                continue;
            else
                cout << argv[i] << ' ';
        }
    }
    else if (!strcmp(argv[1], "middle")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        //             string dig = argv[2];
        //          if(!isdigit(dig[0])&&dig[0]!='-'){
        //              cout<<"Incorrect Data Type";
        //              return 0;
        //          }
        if (argc % 2 == 0) {

            cout << argv[(argc / 2)] << ' ' << argv[(argc / 2) + 1];
        } else {

            cout << argv[(argc / 2) + 1];
        }

    } else if (!strcmp(argv[1], "add")) {
        if (argc == 2) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = 2; i <= (argc - 1); i++) {
            string dig = argv[i];
            for (int j = 0; j <= dig.length() - 1; j++) {
                if (!isdigit(dig[j]) && dig[j] != '-'&& dig[j]!='+') {
                    cout << "Incorrect Data Type";
                    return 0;
                }
            }
        }
        int Tadd[(argc - 2)];
        for (int i = 2; i <= (argc - 1); i++) {
            Tadd [i - 1] = atoi(argv[i]);
        }
        int sum = 0;
        for (int i = 1; i <= (argc - 2); i++) {
            sum = sum + Tadd[i];
        }
        cout << sum;

    } else if (!strcmp(argv[1], "random")) {
        if (argc < 6) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }
        for (int i = 2; i <= (argc - 1); i++) {
            string dig = argv[i];
            for (int j = 0; j <= dig.length() - 1; j++) {
                if (!isdigit(dig[j]) && dig[0]!='-' && dig[0]!= '+') {
                    cout << "Incorrect Data Type";
                    return 0;
                }
            }
        }
        if (argc != 6) {
            cout << "Incorrect Number of Arguments";
            return 0;
        }

        int seed = atoi(argv[5]);
        if(seed<0){
            cout<<"Incorrect Data Type";
            return 0;
        }
        int max = atoi(argv[4]);
        int min = atoi(argv[3]);
        if (min > max) {
            cout << "Incorrect Data Type";
            return 0;
        }
        int random;
        int length = atoi(argv[2]);
        if(length<=0){ // negative length check
            cout<<"Incorrect Data Type";
            return 0;
        }
        srand(seed);

        for (int i = 1; i <= length; i++) {
            random = (rand() % (max - min + 1)) + min;
            cout << random << ' ';
        } //(rand() % (nHigh - nLow + 1)) + nLow;
    } else
        cout << "Undefined Command";



    return 0;
}

