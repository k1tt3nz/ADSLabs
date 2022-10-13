#if !defined STRING_FORM_4_H
#define STRING_FORM_4_H

//Операция прошла успешно
static const int STR_SUCCESSFUL = 0;

//Выход за границу максимально разрешенного размера строки
//при вводе в нее данных
static const int STRING_INPUT_ERROR = -1;

//Выход за границу максимально разрешенного размера строки
//при вставке данных из одной строки в другую
static const int STRING_INSERT_ERROR = -2;

//Попытка вставить элемент на место которое не существует
static const int STRING_NO_PLACE = -3;

//Выход за границу максимально разрешенного размера строки
//при склеивании в нее данных
static const int STRING_CONCATEN_ERROR = -4;

//Ошибка поиска в меньшей строки большей подстроки
static const int STRING_POS_ERROR = -5;

int STRING_ERROR;

#define MAX_L 1024

typedef struct str {
    char s[MAX_L];
    size_t N;
}str;

typedef str string1 [2];

//Запись данных в строку st из строки s.
//Строка s заканчивается нулевым символом '\0'
void WriteToStr(string1 st,const char* s);

//Запись данных в строку s из строки st.
//Строка s заканчивается нулевым символом '\0'.
void WriteFromStr(char* s, string1 st);

//Ввод строки s с клавиатуры.
void InputStr(string1 st);

//Вывод строки s на экран монитора.
void OutputStr(string1 st);

//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2);

//Удаляет count символов из строки s
//начиная с позиции index
void Delete(string1 s, size_t Index, size_t Count);

//Вставляет подстроку subS в строку st
//начиная с позиции index
void Insert(string1 Subs, string1 s, size_t Index);

//Выполняет конкатенацию строк s1 и s2 результат помещает в sRez
void Concat(string1 s1, string1 s2, string1 srez);

//Записывает count символов в строку subS из строки s
//начиная с позиции index
void Copy(string1 s, size_t Index, size_t Count, string1 Subs);

//Возвращает текущую длинну строки s
unsigned Length(string1 s);


//Возвращает позицию, начиная
//с которой в строке s располагается подстрока SubS.
unsigned Pos(string1 SubS, string1 s);

#include "string.c"

#endif // !STRING_FORM_4_H
