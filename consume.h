#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define DEBUG

#define MAX_CONSUME 100

typedef struct consume
{
	char content[40] ;
	int price ;
	char category[20] ;
	int month ;
	int day ;
} T_Record ;

int c_first_available() ;
int c_is_available() ;
void c_create(char* c, int p, char* ct, int m, int d) ;
int c_count();
T_Record* c_search_by_content(char* c) ;
void c_get_all(T_Record* a[]) ;
char* c_to_string(T_Record* p) ;
char* c_getcontent(T_Record* p) ;
int c_getprice(T_Record* p) ;
char* c_getcategory(T_Record* p) ;
int c_getmonth(T_Record* p) ;
int c_getday(T_Record* p) ;
int month_sum(int mon, int sum) ;
void c_search_category(char* ct) ;
void c_search_month(int m) ;
void c_search_day(int m, int d) ;
void descending_order() ;
void c_update(T_Record* p, int price, char* ct, int m, int d) ;
void c_update_category(char* ct, char* ct2) ;
void c_update_month(int m, int m2) ;
void c_update_day(int m, int d, int m2, int d2) ;
void c_delete(T_Record* p) ;
void c_delete_category(char* ct) ;
void c_delete_month(int m) ;
void c_delete_day(int m, int d) ;
void all_delete(T_Record* p) ;
void c_init();
char* c_to_string_save(T_Record* p);
