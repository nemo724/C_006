#include <stdio.h>
#include <stdbool.h>

void storage_pi(int*,double , double*);//라이프니츠 원주율 공식에서 ()안에 누적된 값을 매개변수로 받고 *4로 파이를 구해 테이블에 기록하는 함수 


void storage_pi(int *index,double pi ,double*report_pi)
{report_pi[*index]=4*pi;
*index += 1;}



int main(void)
{bool minus = false;//현재 더할 항의 부호가 -인가를 판단하는 변수
double pi = 0;//라이프니츠 원주율 공식에서 n항까지의 누적 결과를 담는 변수
double report_pi[15] = { 0 };//선두의 10개,끝의 5개의 파이 값을 기록하는 테이블








return 0 ;
}