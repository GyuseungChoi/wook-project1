# project1
▶create_record ▶ 해당 기능은 consume 구조체의 내용을 각각 scanf로 받아서 이 내용을 한 리스트로 만들어주는
함수(c_create)를 이용하여 구현하였습니다.
▶content_read_ record ▶ 해당 기능은 consume의 content값을 입력 받아서, 입력한 content의 index와 리스트의
index와 일치하였을때, 그 index의 모든 정보를 출력하는 방식으로 구현하였습니다.
▶part_read_record ▶ 해당 기능은 switch문을 이용해 category와 month, day를 선택하게 했고, 선택 후 위와 같은
방법으로 해당 index를 찾는데, 이때는 일치하는 모든 정보를 출력해주어야 하기 때문에, 해당 리스트의 size를 얻어
끝까지 가면서 일치할 때마다 출력하는 방식으로 구현하였습니다.
▶all_read_record ▶ 해당 기능은 모든 리스트의 내용을 문자열로 나타내주도록(get_string) 구현하였습니다.
▶report_read_record ▶ 해당 기능은 월 별 지출금액을 알려주는 함수를 만든 후(해당 월의 지출금액의 sum을 구함) 월 별 지출금액을 나타내준 후, 월 별 지출금액의 sum을 구하여 전체 지출금액을 나타내주도록 구현하였습니다.
▶price_arrangement ▶ 해당 기능은 for문을 사용하여 가격이 낮으면 한칸씩 뒤로 가도록 하여 높은 가격순부터
앞에 나오도록 구현하였습니다. 이때 이 기능은 함수를 사용하여 구현하였습니다.
▶content_update_record ▶ 해당 기능은 바꾸고 싶은 content의 내용을 입력 받고, 바꿀 content의 내용을 입력 받은 후, 이 값을 update 함수에서 뒤의 내용을 앞의 내용으로 바꿔주도록 구현하였습니다.
▶part_update_record ▶ 해당 기능은 switch문을 이용해 category와 month,day를 선택하게 했고, 선택 후 위와 같은 방법으로 바꾸고 싶은 내용과 바꿀 내용을 입력 받아, update 함수에서 해당 내용을 바꿔주도록 구현하였습니다.
▶content_delete_record ▶해당 기능은 지우고 싶은 content의 내용을 입력 받아, delete함수를 통해 해당 내용을 지우도록 구현하였습니다.
▶part_delete_record ▶해당 기능은 switch문을 이용해 category와 month,day를 선택하게 했고, 선택 후 지우고 싶은 내용을 입력 받아 해당 내용이 있는 모든 내용을 지우도록 구현하였습니다.
※ delete함수에서는 조각모음을 사용하여 새로 입력하였을 때, 해당 리스트 뒤에 입력 받도록 구현하였습니다.
▶file_load ▶해당 기능은 “consume.txt”파일로부터 파일의 내용이 없을 때까지 내용을 입력받아 c_create 함수를 이용해 리스트를 만들어 냈습니다.
▶file_save ▶해당 기능은 현재 consume에 있는 데이터를 for문으로 해당 리스트의 size까지 반복문을 돌며 각각의 구조체 내용을 입력 받아 txt파일을 만들도록 구현하였습니다.

Make 방법은 가장 일방적이게 구현하였습니다.(윈도우환경)

Make main.exe 실행파일 생성

Make main.exe_debug 디버깅 실행파일 생성

Make clean 실행파일 삭제
