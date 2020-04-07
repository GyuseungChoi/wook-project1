#include "consume.h"

void create_record() ; // 지출내용을 입력하는 함수
void content_read_record() ; // 특정 지출내용(content) 검색시 상세정보 출력 함수
void part_read_record() ; // 특정 범주, 월, 날짜 입력시 해당정보 출력 함수
void all_read_record() ; // 모든 소비리스트를 출력해주는 함수
void report_read_record() ; // 월별 지출금액, 총 지출금액 보고서
void price_arrangement() ; // 총 지출내용 중 비싼금액부터 싼금액까지 정렬 보고서
//void content_update_record() ; // 특정 지출내용의 카테고리, 가격, 날짜를 수정하는 함수
//void part_update_record() ; // 특정 범주, 월, 날짜의 내용 입력시 해당정보를 전부 수정하는 함수
//void content_delete_record() ; // 특정 지출에 관한 모든 정보를 삭제하는 함수
//void part_delete_record() ; // 특정 범주, 월, 날짜의 내용을 모두 삭제하는 함수

int main() {
	int menu ;
	while(1){
		printf("\nMenu :  1.기록하기       2.확인(소비내용)    3.확인(조건부)   4.소비리스트") ;
		printf("\n\t5.소비보고서     6.정렬(높은 가격순) 7.수정(특정내용) 8.수정(조건부)") ;
		printf("\n\t9.삭제(특정물품) 10.삭제(조건부)     11.저장하기      12.불러오기      0.끝내기	 > ") ;
		scanf("%d", &menu) ;
		printf("\n") ;
		switch(menu) {
			case 1:
				create_record() ;
				break ;
			case 2:
				content_read_record() ;
				break ;
			case 3:
				part_read_record() ;
				break ;
			case 4:
				all_read_record() ;
				break ;	
			case 5:
				report_read_record() ;
				break ;
			case 6:
				price_arrangement() ;
				break ;
			case 0:
			default:
				return 0;
		}
	}
	return 0;
}

void create_record() {
	T_Record* consume[MAX_CONSUME] ;
	char content[20], category[20] ;
	int price, month, day ;

	if(c_count(consume) == MAX_CONSUME) {
		printf("There is no space!\n") ;
		return ;
	}
	printf("Content > ") ;
	scanf("%s" , content) ;
	printf("Price > ") ;
	scanf("%d" , &price) ;
	if(price < 0){
		printf("다시 입력하시오\n") ;
		return ;
	}
	printf("Category > ") ;
	scanf("%s" , category ) ;
	printf("Month > ") ;
	scanf("%d" , &month) ;
	if(month < 1 || month > 12){
		printf("다시 입력하시오\n") ;
		return ;
	}
	printf("Day > ") ;
	scanf("%d" , &day) ;
	if(day < 1 || day > 31){
		printf("다시 입력하시오\n") ;
		return ;
	}
	c_create(content, price, category, month, day) ;
}

void content_read_record() {
	char content[20] ;

	printf("소비내용 입력 > ") ;
	scanf("%s", content) ;

	T_Record* consume = c_search_by_content(content);

	if(c_search_by_content(content)) {
		c_getprice(consume) ;
		printf("Price : %d원\n", consume->price) ;
		c_getcategory(consume) ;
		printf("Category : %s\n", consume->category) ;
		c_getmonth(consume) ;
		c_getday(consume) ;
		printf("Date : %d월 %d일\n", consume->month, consume->day) ;

		return ;
	}
	printf("존재하지 않는 내용입니다.\n") ;
}

void part_read_record() {
	int menu, m, d;
	char ct[20] ;

	while(1){
		printf("\n어느 정보를 검색하시겠습니까?\n") ;
		printf("1.Category 2.Month 3.Day 0.Exit > ") ;
		scanf("%d", &menu) ;
	switch(menu) {
		case 1:
			printf("Category > ") ;
			scanf("%s", ct) ;
			c_search_category(ct) ;			

			break ;
		case 2:
			printf("Month > ") ;
			scanf("%d", &m) ;
			c_search_month(m) ;
	
			break ;
		case 3:
			printf("Month > ") ;
			scanf("%d", &m) ;
			printf("Day > ") ;
			scanf("%d", &d) ;
			c_search_day(m, d) ;
			
			break ;
		case 0:
		default:
			return ;
		}
	}
}

void all_read_record() {
	printf("소비리스트\n") ;
	int size = c_count() ;
	T_Record* records[MAX_CONSUME] ;
	c_get_all(records) ;
	for (int i = 0 ; i < size ; i ++) {
		T_Record* p = records[i] ;
		printf("%d. %s\n", i+1, c_to_string(p)) ;
	}
}

void price_arrangement() {
	printf("ㅡ높은 가격순 정렬ㅡ\n") ;
	descending_order() ;
}

void report_read_record() {
	printf("ㅡ월별/총 소비금액 보고서ㅡ\n") ;
	int m, sum, a_sum ;
	a_sum = 0 ;
	for(m = 1 ; m < 13 ; m++) {
		sum = month_sum(m, 0) ;
		printf("%d월 소비액 : %d월\n", m, sum) ;
		a_sum += sum ;
	}

	printf("\n총 소비액 : %d원\n", a_sum) ;
}
