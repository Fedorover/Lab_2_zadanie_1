#include <iostream>
#include <stdlib.h>

#include <string.h>
#include <stdio.h>
#include "train.hpp"
#include "func.hpp"

using namespace std;

int main()
{
    
    train poezd[10];
    setlocale(LC_ALL, "rus");
    int chislo;
    int  note;

    int num;
    
    cout<<"Введите нужное количество обьектов:\n"<<">>";
    cin>>chislo;
    while (1)
    {
        while (1)
        {
            cout << "1 - Ввод данных\n2 - Показать все данные в алфавитном порядке \n3 - Поиск по заданию\n4 - Изменить данные\n5 - Выход\n\n";
            
            cout << "Введите номер\n";
            cin >> num;
            if (num > 5 || num < 1)
            {
                cout << "\nНеккоректно введены данные!Для продолжения нажмите любую кнопку.\n";

                continue;
            }
            break;
        }
        
        switch (num)
        {
            case 1:
                for (int i = 0; i < chislo; i++)
                {
                    while (1)
                    {
                      
                        cin >> poezd[i];
                        try
                        {
                            for (int j = 0; j < chislo; j++)
                            {
                                if ((poezd[i].take_number() == poezd[j].take_number()) && i != j)
                                    throw 7;
                            }
                        }
                        
                        catch (int p)
                        {
                            cout << "Ошибка. данный поездуже существует\n";
                            cout << "\nдля продолжения нажмите любую кнопку\n";
                     
                            continue;
                        }
                        break;
                    }
                }
               cout << "\nдля продолжения нажмите любую кнопку\n";
             
                break;
                
            case 2:
                sort(poezd,chislo);
                disp(poezd,chislo);
               cout << "\nдля продолжения нажмите любую кнопку\n";
             
                break;
                
            case 3: system("cls");
                sort(poezd,chislo);
                search(poezd,chislo);
                cout << "\nдля продолжения нажмите любую кнопку\n";
          
                break;
                
            case 4:
                sort(poezd,chislo);
                
                while (1)
                {
                    disp(poezd,chislo);
                    cout << "Введите нмер редактируемой записи\n";
                    cin >> note;
                    if (note > chislo || note < 1)
                    {
                        cout << "\nНеккоректно введены данные для продолжения введите любую кнопку\n";
                      
                        continue;
                    }
                    break;
                    
                }
                
                while (1)
                {
                  
                    cin >> poezd[note - 1];
                    try
                    {
                        for (int j = 0; j < chislo; j++)
                        {
                            if ((poezd[note - 1].take_number() == poezd[j].take_number()) && ((note - 1) != j))
                                throw 7;
                        }
                    }
                    
                    catch (int p)
                    {
                        cout << "Ошибка. данный поездуже существует\n";
                        cout << "\nдля продолжения нажмите любую кнопку\n";
                      
                        continue;
                    }
                    break;
                }
                cout << "\nдля продолжения нажмите любую кнопку\n";
            
                break;
                
            case 5:
                
                cout << "До свидания\n";
                return 0;
                break;
        }
    }
}

