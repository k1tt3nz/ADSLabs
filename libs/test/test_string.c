#include "string/StringForm4.h"
#include <string.h>

void test_string_WriteToStr_1(){
    string1 str;
    char *s = "qwerty";

    WriteToStr(str,s);
    string1 expected = {{"qwerty",6}};

    assert(Comp(str,expected) == 0);
}

void test_string_WriteToStr_2(){
    string1 str = {"fhriqsd",7};
    char *s = "qwerty";

    WriteToStr(str,s);
    string1 expected = {{"qwerty",6}};

    assert(Comp(str,expected) == 0);
}

void test_string_WriteToStr(){
    test_string_WriteToStr_1();
    test_string_WriteToStr_2();

    printf("test_string_WriteToStr passed\n");
}

void test_string_WriteFromStr_1(){
    string1 str = {"qwerty",6};
    char s[10];

    WriteFromStr(s,str);
    char expected = "qwerty";

    assert(strcmp(str,s) == 0);
}

void test_string_WriteFromStr_2(){
    string1 str = {"qwerty",6};
    char s[2] = "gg";

    WriteFromStr(s,str);
    char expected = "qwerty";

    assert(strcmp(str,s) == 0);
}

void test_string_WriteFromStr(){
    test_string_WriteFromStr_1();
    test_string_WriteFromStr_2();

    printf("test_string_WriteFromStr passed\n");
}

void test_string_Delete_1(){
    string1 st = {"qwerty",6};

    Delete(st,3,3);
    string1 expected = {"qwe",3};

    assert(Comp(st,expected) == 0);
}

void test_string_Delete_2(){
    string1 st = {"qwerty",6};

    Delete(st,0,3);
    string1 expected = {"rty",3};

    assert(Comp(st,expected) == 0);
}

void test_string_Delete(){
    test_string_Delete_1();
    test_string_Delete_2();

    printf("test_string_Delete passed\n");
}

void test_string_Insert_1(){
    string1 st = {"abcdjddf",8};
    string1 subS = {"LJ",2};
    string1 expected = {"aLJbcdjddf",10};

    Insert(subS,st,0);

    assert(Comp(st,expected) == 0);
}

void test_string_Insert_2(){
    string1 st = {"abcdjddf",8};
    string1 subS = {"LJ",2};
    string1 expected = {"abcLJdjddf",10};

    Insert(subS,st,2);

    assert(Comp(st,expected) == 0);
}

void test_string_Insert(){
    test_string_Insert_1();
    test_string_Insert_2();

    printf("test_string_Insert passed\n");
}

void test_string_Concat_1(){
    string1 st = {"qwe",3};
    string1 subS = {"rty",3};
    string1 expected = {"qwerty",6};

    string1 resS;
    Concat(st,subS,resS);

    assert(Comp(resS,expected) == 0);
}

void test_string_Concat_2(){
    string1 st = {"qwerty",8};
    string1 subS = {"42",2};
    string1 expected = {"qwerty42",8};

    string1 resS;
    Concat(st,subS,resS);

    assert(Comp(resS,expected) == 0);
}

void test_string_Concat(){
    test_string_Concat_1();
    test_string_Concat_2();

    printf("test_string_Concat passed\n");
}

void test_string_Copy_1(){
    string1 s = {{" abcgdeis ", 8}};
    string1 subS = {{" s657n ", 5}};
    string1 expected = {{" cgde ", 4}};

    Copy (s, 2 , 4 , subS ) ;

    assert ( Comp (subS , expected ) == 0) ;
}

void test_string_Copy_2(){
    string1 s = {{" abcgdeis ", 8}};
    string1 subS = {{" s657n ", 5}};
    string1 expected = {{" bc ", 2}};

    Copy (s, 1 , 2 , subS ) ;

    assert ( Comp (subS , expected ) == 0) ;
}

void test_string_Copy(){
    test_string_Copy_1();
    test_string_Copy_2();

    printf("test_string_Copy passed\n");
}

void test_string_Length_1(){
    string1 s = {"qwerty",6};

    assert(Length(s) == 6);
}

void test_string_Length(){
    test_string_Length_1();

    printf("test_string_Length passed\n");
}

void test_string_Pos_1(){
    string1 s = {{"Hello World", 11}};
    string1 expected = {{"Hello", 5}};

    size_t controlPos = 1;
    assert(Pos(expected,s) == controlPos);
}

void test_string_Pos_2(){
    string1 s = {{"Hello World", 11}};
    string1 expected = {{"dsa", 5}};

    size_t controlPos = 0;
    assert(Pos(expected,s) == controlPos);
}

void test_string_Pos(){
    test_string_Pos_1();
    test_string_Pos_2();

    printf("test_string_Pos passed\n");
}

void TEST(){
    test_string_WriteToStr();
    //test_string_WriteFromStr();
    test_string_Delete();
    test_string_Insert();
    test_string_Concat();
    test_string_Copy();
    test_string_Length();
    test_string_Pos();
}
