#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "func.hpp"

using namespace std;

class train
{
private:
    
    char* title;
    
    int time;
    
    int number;
    
public:
    
    void set_title(char* data);
    
    void set_time(int data);
    
    void set_number(int data);
    
    void get_title(void);
    
    void get_time(void);
    
    void get_number(void);
    
    train();
    
    train(char* data_title, int data_time, int data_number);
    
    ~train();
    
    train(const train& src);
    
    train& operator=(const train& src);
    
    friend ostream& operator<<(ostream& os, train& obj);
    
    friend istream& operator>>(istream& stream, train& obj);
    
    char* take_title(void);
    
    int take_time(void);
    
    int take_number(void);
    
    friend void sort(train obj[], int chislo);
    
    friend void disp(train obj[], int chislo);
    
    friend void search(train obj[], int chislo);
    
    
    
};




