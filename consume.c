#include "consume.h"
//#define DEBUG

T_Record* consume[MAX_CONSUME] ;
int _count = 0 ;

int c_first_available(){
   int i ;
   for (i = 0 ; i < MAX_CONSUME ; i++) {
	if (consume[i] == NULL)
	return i ;
   }
   return -1 ;
}

int c_is_available(){
   int i ;
   for (i = 0 ; i < MAX_CONSUME ; i++) {
	if (consume[i] == NULL)
	return 1 ;
   }
   return 0 ;
}

void c_create(char* c, int p, char* ct, int m, int d){
   int index = c_first_available() ;
   consume[index] = (T_Record *) malloc(sizeof(T_Record)) ;
   T_Record* a = consume[index] ;
   strcpy(a->content, c) ;
   a->price = p ;
   strcpy(a->category, ct) ;
   a->month = m ;
   a->day = d ;
   _count++ ;
#ifdef	DEBUG
	printf("[DEBUG] consume activity create %s \n", a->content) ;
#endif
}

int c_count(){
   return _count ;
}

char* c_to_string(T_Record* p){
   static char str[80] ;
   sprintf(str, "[%s] %d원 - %s - %d월 %d일",
	   p->content, p->price, p->category, p->month, p->day) ;
#ifdef	DEBUG
	printf("[DEBUG] make string content : %s, category : %s\n", p->content, p->category) ;
#endif
   return str ;
}

void c_get_all(T_Record* a[]){
   int i, c = 0 ;
   for (i = 0 ; i < MAX_CONSUME ; i++) {
	if(consume[i]){
	   a[c] = consume[i] ;
	   c++ ;
	}
   }
}

T_Record* c_search_by_content(char* c){
   int i ;
   for (i=0 ; i<MAX_CONSUME ; i++) {
	if(consume[i] && strcmp(consume[i]->content, c) == 0) return consume[i] ;
   }
   return NULL ;
}

char* c_getcontent(T_Record* p){
#ifdef	DEBUG
	printf("[DEBUG] get content %s\n", p->content) ;
#endif
   return p->content ;
}

int c_getprice(T_Record* p) {
#ifdef DEBUG
	printf("[DEBUG] get price %d\n", p->price) ;
#endif
   return p->price ;
}

char* c_getcategory(T_Record* p) {
#ifdef DEBUG
	printf("[DEBUG] get category %s\n", p->category) ;
#endif
   return p->category ;
}

int c_getmonth(T_Record* p) {
#ifdef DEBUG
	printf("[DEBUG] get month %d\n", p->month) ;
#endif
   return p->month ;
}

int c_getday(T_Record* p) {
#ifdef DEBUG
	printf("[DEBUG] get day %d\n", p->day) ;
#endif
   return p->day ;
}

int month_sum(int mon, int sum) {
   T_Record* m_sum[MAX_CONSUME] ;
   c_get_all(m_sum) ;
   int size = c_count() ;

   for(int i = 0 ; i < size ; i++) {
	if(m_sum[i] && m_sum[i]->month == mon) {
		sum += m_sum[i]->price ;
	}
   }
#ifdef DEBUG
	printf("[DEBUG] month %d, total %d\n", mon, sum) ;
#endif
   return sum ;
}

void c_search_category(char* ct) {
   T_Record* consume[MAX_CONSUME] ;
   c_get_all(consume) ;
   int size = c_count() ;

   for(int i = 0 ; i < size ; i++) {
	if(consume[i] && strcmp(consume[i]->category, ct) == 0) {
		T_Record* p = consume[i] ;
		printf("%d. %s\n", i+1, c_to_string(p)) ;
		#ifdef DEBUG
			printf("[DEBUG] get a search, category %s\n", p->category) ;
		#endif
	}
   }
}

void c_search_month(int m) {
   T_Record* consume[MAX_CONSUME] ;
   c_get_all(consume) ;
   int size = c_count() ;

   for(int i = 0 ; i < size ; i++) {
	if(consume[i] && consume[i]->month == m) {
		T_Record* p = consume[i] ;
		printf("%d. %s\n", i+1, c_to_string(p)) ;
		#ifdef DEBUG
			printf("[DEBUG] get a search, month %d\n", p->month) ;
		#endif
	}
   }
}

void c_search_day(int m, int d) {
   T_Record* consume[MAX_CONSUME] ;
   c_get_all(consume) ;
   int size = c_count() ;

   for(int i = 0 ; i < size ; i++) {
	if(consume[i] && consume[i]->month == m && consume[i]->day == d) {
		T_Record* p = consume[i] ;
		printf("%d. %s\n", i+1, c_to_string(p)) ;
		#ifdef DEBUG
			printf("[DEBUG] get a search, data %d / %d\n", p->month, p->day) ;
		#endif
	}
   }
}

void descending_order() {
   T_Record* records[MAX_CONSUME] ;
   T_Record* tmp[MAX_CONSUME] ;
   c_get_all(records) ;
   int size ;
   size = c_count() ;

	for(int i = 0 ; i < size ; i++) {
	   for(int j = 0 ; j < size-i-1 ; j++) {
		if(records[j]->price < records[j+1]->price) {
		   tmp[j] = records[j] ;
		   records[j] = records[j+1] ;
		   records[j+1] = tmp[j] ;
		}
	   }
	}

	printf("높은 가격순 정렬\n") ;
	for(int k = 0 ; k < size ; k++) {
	   T_Record* p = records[k] ;
	   printf("%d. %s\n", k+1, c_to_string(p)) ;
	}
}

void c_update(T_Record* p, int price, char* ct, int m, int d) {
	p->price = price ;
	strcpy(p->category, ct) ;
	p->month = m ;
	p->day = d ;
}

T_Record* c_search_by_category(char* ct) {
	int i ;
	for(i = 0 ; i < MAX_CONSUME ; i++) {
		if(consume[i] && strcmp(consume[i]->category, ct) == 0) return consume[i] ;
	}
	return NULL ;
}

void c_update_category(char* ct, char* ct2) {
	T_Record* consume[MAX_CONSUME] ;
	c_get_all(consume) ;
	int size = c_count() ;

	for(int i = 0 ; i < size ; i++) {
		if(consume[i] && strcmp(consume[i]->category, ct) == 0){
			T_Record* p = c_search_by_category(ct) ;
			c_getcategory(p) ;
			strcpy(p->category, ct2) ;
		}
	}
}

T_Record* c_search_by_month(int m) {
	int i ;
	for(i = 0 ; i < MAX_CONSUME ; i++) {
		if(consume[i] && consume[i]->month == m) return consume[i] ;
	}
	return NULL ;
}

void c_update_month(int m, int m2) {
	T_Record* consume[MAX_CONSUME] ;
	c_get_all(consume) ;
	int size = c_count() ;

	for(int i = 0 ; i < size ; i++) {
		if(consume[i] && consume[i]->month == m) {
			T_Record* p = c_search_by_month(m) ;
			c_getmonth(p) ;
			p->month = m2 ;
		}
	}
}

T_Record* c_search_by_day(int m, int d) {
	int i ;
	for(i = 0 ; i < MAX_CONSUME ; i++) {
		if(consume[i] && ((consume[i]->month == m)&&(consume[i]->day == d)))  return consume[i] ;
	}
	return NULL ;
}

void c_update_day(int m, int d, int m2, int d2) {
	T_Record* consume[MAX_CONSUME] ;
	c_get_all(consume) ;
	int size = c_count() ;

	for(int i = 0 ; i < size ; i++) {
		if(consume[i] && ((consume[i]->month == m)&&(consume[i]->day == d))) {
			T_Record* p = c_search_by_month(m) ;
			c_getmonth(p) ;
			p->month = m2 ;
			T_Record* p2 = c_search_by_day(m, d) ;
			c_getday(p) ;
			p->day = d2 ;
		}
	}
}

