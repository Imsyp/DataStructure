#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)   //num개의 원반을 from에서 by를 거쳐서 to로 이동
{
    if(num==1)
    {
        printf("원반1을 %c에서 %c로 이동 \n", from, to);    //4단계
    }
    else
    {
        HanoiTowerMove(num-1, from, to, by);    //1단계
        printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);  //2단계
        HanoiTowerMove(num-1, by, from, to);    //3단계
    }
}

int main(void)
{
    // 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}