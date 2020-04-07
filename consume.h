#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSUME 20

typedef struct consume
{
   char content[20] ; // 지출물품
   int price ; // 지출금액
   char category[20] ; // 지출범주
   int month ; // 지출 월
   int day ; // 지출 일
} T_Record ;

int c_first_available() ; // 처음에 추가할 수 있는가?
int c_is_available() ; // 현재 리스트에 추가할 공간이 있는가?
void c_create(char* c, int p, char* ct, int m, int d) ; // 지출정보를 만드는 함수
int c_count(); // 리스트 안의 지출횟수를 알려주는 함수
T_Record* c_search_by_content(char* c) ; // 해당 물품의 index를 알려주는 함수
void c_get_all(T_Record* a[]) ; // 리스트의 모든 지출정보를 배열로 가져오는 함수
char* c_to_string(T_Record* p) ; // 해당 지출정보를 글로 나타내주는 함수
char* c_getcontent(T_Record* p) ; // 지출물품을 가져오는 함수
int c_getprice(T_Record* p) ; // 지출금액을 가져오는 함수
char* c_getcategory(T_Record* p) ; // 지출범주를 가져오는 함수
int c_getmonth(T_Record* p) ; // 지출 월을 가져오는 함수
int c_getday(T_Record* p) ; // 지출 일을 가져오는 함수
int month_sum(int mon, int sum) ; // 월별 지출금액을 알려주는 함수
void c_search_category(char* ct) ; // 해당 범주의 지출정보를 알려주는 함수
void c_search_month(int m) ; // 해당 월의 지출정보를 알려주는 함수
void c_search_day(int m, int d) ; // 해당 날짜의 지출정보를 알려주는 함수
void descending_order() ; // 리스트의 지출금액 내림차순으로 알려주는 함수

void c_content_update(T_Record* c, int p, char* ct, int m, int d) ; // 특정 지출내용 수정
void c_category_update(T_Record* c, char* c, int p, char* ct, int m, int d) ; // 해당 범주 모두 수정
void c_month_update(T_Record* c, char* c, int p, char* ct, int m, int d) ; // 해당 월 모두 수정
void c_day_update(T_Record* c, char* c, int p, char* ct, int m, int d) ; // 해당 날짜 모두 수정

void c_delet(T_Record* c) ; // 특정 지출내용 삭제
void c_category_delete(T_Record* c, char* ct) ; // 해당 범주 모두 삭제
void c_month_delete(T_Record* c, int m) ; // 해당 월 모두 삭제
void c_day_delete(T_Record* c, int m, int d) ; // 해당 날짜 모두 삭제
