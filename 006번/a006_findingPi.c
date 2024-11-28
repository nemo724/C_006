#include <stdio.h>
#include <stdbool.h>

void storage_pi(int*,double , double*);//라이프니츠 원주율 공식에서 ()안에 누적된 값을 매개변수로 받고 *4로 파이를 구해 테이블에 기록하는 함수 
void calculate_pi(double*, bool*,double*);//라이프니츠 원주율 공식의 누적값을 계산하는 함수
void print_pi(double*);//원주율의 값을 기록한 테이블을 출력하는 함수

void storage_pi(int *index,double pi ,double*report_pi)
{report_pi[*index]=4 * pi;
*index += 1;}



void calculate_pi(double* pi, bool* minus,double * report_pi)
{int table_index = 0;
for (int i = 1; i <= 10000; i += 2)
	{if (*minus == false)
		{*pi += 1.0 / i;
		*minus = true;//현재 항이 -가 아니면 다음 항은 -	
		if (i < 20 || i>10000 - 10)//i가 2씩 증가하기에 상위 10개는 2*10로 20미만의 홀수 10개 되어야 하고 하위 5개는 2*5=10 10000-10dls 9991,3,5,7,9 이렇게 5개가 담김
		{storage_pi(&table_index,*pi,report_pi); }
		}

		else if (*minus == true)
		{*pi -= 1.0 / i;
		*minus = false;//현재 항이 -라면면 다음 항은 +	
		if (i < 20 || i>10000 - 10)//위와 동일
		{storage_pi(&table_index,*pi,report_pi); }
		}
	}
}


void print_pi(double* report_pi)
{for(int i=0;i<15;i++)
	{if(i==0){printf("1번 항부터 10번항 까지의 각 누적결과에 따른 원주율들\n"); }
	else if(i==10) { printf("마지막 항의 앞에 4개와 마지막 항의 각 누적결과에 따른 원주율들\n"); }
	printf("pi = %.18f\n",report_pi[i]);}
}





int main(void)
{bool minus = false;//현재 더할 항의 부호가 -인가를 판단하는 변수
double pi = 0;//라이프니츠 원주율 공식에서 n항까지의 누적 결과를 담는 변수
double report_pi[15] = { 0 };//선두의 10개,끝의 5개의 파이 값을 기록하는 테이블
calculate_pi(&pi, &minus, report_pi);
print_pi(report_pi);






return 0 ;
}