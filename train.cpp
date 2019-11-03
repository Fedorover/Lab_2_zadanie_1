#include "train.hpp"

#include <stdlib.h>



#include <stdio.h>

using namespace std;


void train::set_title(char* data)

{
    
    long int size = dlina(data);
    
    delete[] title;
    
    title = NULL;
    
    title = new char[size + 1];
    
    copy(title, data);
    
    return;
    
}

void train::set_time(int data)

{
    
   
    
    time = 0;
    
    time=data;
    
    return;
    
}

void train::set_number(int data)

{
    
    number = 0;
    
    number = data;
    
    return;
    
}

void train::get_title(void)

{
    
    cout << " Название пункта назначения: " << title << "\n";
    
    return;
    
}

void train::get_time(void)

{
    
    cout << " Время отправления: " << time << "\n";
    
    return;
    
}

void train::get_number(void)

{
    
    cout << "Номер поезда: " << number << "\n";
    
    return;
    
}

train::train()

{
    title = new char[2];
    
    *(title  + 0) = ' ';
    
    *(title + 1) = '\0';
    
    
    time  = 0;
    
    number = 0;
    
}

train::~train()

{
    
    delete[] title;
    
    title = NULL;
    
  
    
    time = 0;
    
    number = 0;
    
}

istream& operator>>(istream& stream, train& obj)

{

    char str1[100];
    char str[100];
    int data_number;
    int data_time;
    
    gets(str1);
    obj.set_title(str1);
    while (1)
    {
        cout << "Введите название пункта назначения\n";
        gets(str);
        
        
        if (test(str) == false)
        {
            cout << "\nНеккоректно введены данные.Попробуйте снова\n";

            system("cls");
            continue;
        }
        break;
    }
    obj.set_title(str);
    
    
    
    
    while (1)
    {
        cout << "Введите время отправление:\n";
        cin >> data_time;
        
        break;
        
    }
    obj.set_time(data_time);
    
    
    while (1)
    {
        cout << "Введите номер поезда:\n";
        cin >> data_number;
        break;
        
    }
    
    obj.set_number(data_number);
    return stream;
    
}

ostream& operator<<(ostream& stream, train& obj)
{
    obj.get_title();
    obj.get_time();
    obj.get_number();
    return stream;
}

char* train::take_title(void)
{
    return title;
}

 int train::take_time(void)
{
    return time;
}

train::train(const train & src)
{
    if (title)
    {
        delete[] title;
        title = NULL;
    }
    
   
    
    long int size = dlina(src.title);
    title = new char[size + 1];
    copy(title, src.title);

    time = src.time;
    
    number = src.number;
}

train& train::operator=(const train& src)
{
    if (title)
    {
        delete[] title;
        title = NULL;
    }

    long int size = dlina(src.title);
    title = new char[size + 1];
    copy(title, src.title);
   
    time = src.time;
  
    number = src.number;
    return *this;
}

int train::take_number(void)
{
    return number;
}

train::train(char* data_title, int data_time, int data_number)
{
    long int size = dlina(data_title);
    title = NULL;
    title = new char[size + 1];
    copy(title, data_title);
   
    time = data_time;
   
    number = data_number;
}
void disp(train obj[], int chislo)
{
    int count = 1;
    cout << "\t\t\t\tВся информация:\n\n";
    for (int i = 0; i < chislo; i++)
    {
        if (*obj[i].take_title() == ' ' && obj[i].take_time() == ' ' && obj[i].take_number() == 0)
            continue;
        cout << "***** " << count << " *****\n";
        count++;
        cout << obj[i];
        cout << "\n\n";
    }
    return;
}
void search(train obj[], int chislo) {
    int srok;
    cout << "Введите заданное время, после которого должны отправляться поезда: \n";
    cin >> srok;
    
   
    int i;
    int flag = 0;
    for (i = 0; i < chislo; ++i) {
        if (srok <= obj[i].take_time()) {
            flag++;
            cout << obj[i] << "\n\n";
        }
        
    }
    if (flag == 0)
        cout << "Таких поездов нет\n";
    return;
    
}

