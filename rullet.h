
#define P 5 //한 게임에서 가능한 동시 배팅 수 설정

int insert(int); //배팅
int dot(int x, int y); //배당 계산
int cal(int a[4], int x, int y); //배당 계산
int dis(int a[4], int x, int y); //선택한 수 표시
void save(int a[4], int b[][7], int s, int db); //선택한 수 저장
int result(int d, int b[][7], int db); //roll에서 나온 수를 비교하는 함수
int m_input();
int reset(int b[][7], int db);
void rullet();