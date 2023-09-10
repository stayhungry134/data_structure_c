//
// Created by stayh on 2023/9/10.
//
#include <time.h>

void time_test() {
    struct timeval start, end;
    long seconds, microseconds;

    gettimeofday(&start, NULL); // 记录开始时间

    // 在这里放置要测量执行时间的代码
    printf("%d\n", 1654151 / 2);

    gettimeofday(&end, NULL); // 记录结束时间

    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds / 1000000.0;

    printf("程序执行时间：%f 秒\n", elapsed);
}