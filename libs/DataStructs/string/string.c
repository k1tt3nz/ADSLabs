#include "StringForm4.h"

#include <stdio.h>
#include <assert.h>
#include <ctype.h>


void WriteToStr(string1 st, const char *s){
    size_t i = 0;
    while (s[i] != '\0') {
        st->s[i] = s[i];
        i++;
    }

    st->N = i;
    st->s[i++] = '\0';

    if(i == MAX_L){
        STRING_ERROR = STRING_INPUT_ERROR;
        assert(STRING_ERROR == -1);
    }
}

void WriteFromStr(char* s, string1 st){
    size_t i = 0;
    while (st->s[i] != '\0'){
        s[i] = st->s[i];
        i++;
    }

    st->N = i;
    s[i] = '\0';
}

void InputStr(string1 st){
    char ch = getchar();
    size_t i = 0;

    while ((ch != EOF && !iscntrl(ch)) && (i < MAX_L)){
        st->s[i] = ch;
        i++;
        ch = getchar();
    }

    st->N = i;
    st->s[++i] = '\0';

    if((i == MAX_L ) && (ch != EOF && !iscntrl(ch))){
        STRING_ERROR = STRING_INPUT_ERROR ;
        assert(STRING_ERROR == -1);
    } else{
        STRING_ERROR = STR_SUCCESSFUL;
    }
}


void OutputStr(string1 st){
    size_t i = 0;
    while (st->N != i){
        putchar(st->s[i]);
        i++;
    }
}

int Comp(string1 s1, string1 s2){
    if(s1->N > s2->N)
        return 1;
    else if(s1->N < s2->N)
        return -1;
    else{
        int i = 0;
        while ((s1 ->s[i] == s2->s[i]) && (i < s1 ->N)){
            i++;
        }

        if((i == s1->N) && (i == s2->N)){
            STRING_ERROR = STR_SUCCESSFUL ;
            return 0;
        }

        if(s1->s[i] > s2->s[i]){
            STRING_ERROR = STR_SUCCESSFUL ;
            return 1;
        }
    }
}


void Delete(string1 st, size_t Index, size_t Count){
    for (int i = Index; i < st->N; ++i) {
        st->s[i] = st->s[i + Count];
    }

    st->s[st->N - Count] = '\0';
    st->N -= Count;
}
void Insert(string1 SubS, string1 st, size_t Index){
    if(Index > st->N)
        STRING_ERROR = STRING_NO_PLACE ;
    else if((SubS->N + st->N > MAX_L))
        STRING_ERROR = STRING_INSERT_ERROR ;
    else{
        size_t i = st->N + 1;
        while (i >= Index){
            st->s[i + SubS->N] = st->s[i];
            i--;
        }

        i = Index;
        size_t j = 0;

        while (j < SubS->N){
            st->s[i] = SubS->s[i];
            i++;
            j++;
        }

        st->N += SubS->N;
    }

    assert(STRING_ERROR == (-3 || -2));
}
void Concat(string1 s1, string1 s2, string1 sRez){
    if(s1->N + s2->N > sRez->N)
        STRING_ERROR = STRING_CONCATEN_ERROR;

    for (int i = 0; i < s1->N; ++i)
        sRez->s[i] = s1->s[i];

    size_t i = s1->N;
    for (int j = 0; j < s2->N; ++j)
        sRez->s[j + i] = s2->s[j];

    sRez->N = s1->N + s2->N;
    sRez->s[sRez->N] = '\0';

    assert(STRING_ERROR == -4);
}
void Copy(string1 s, size_t Index, size_t Count, string1 Subs){
    if(Count > MAX_L || Index + Count + s->N)
        STRING_ERROR = STRING_NO_PLACE ;
    else{
        size_t i = 0;
        size_t rBoard = Index + Count;

        while (Index < rBoard){
            Subs->s[i] = s->s[Index];
            i++;
            Index++;
        }
        Subs->N = i;
    }
    assert(STRING_ERROR == -3);
}
size_t Length(string1 s){
    return s->N;
}

size_t Pos(string1 subS, string1 s){
    size_t lens = s->N;
    size_t lensSubS = subS->N;
    size_t returnLen = lens - lensSubS;

    if(lens  < lensSubS){
        STRING_ERROR = STRING_POS_ERROR;
        assert(STRING_ERROR == -5);
    }

    for (size_t i = 0; i < returnLen; ++i) {
        size_t j = 0;
        while ((j < lensSubS ) && (s->s[i + j] == subS ->s[j])){
            ++j;
            if(j == subS->N)
                return i + 1;
        }
    }

    return 0;
}