#include <stdio.h>

#include "hthreadpool.h"
#include "htime.h"

void print_task(int i) {
    printf("thread[%x]: task[%d]\n", gettid(), i);
    sleep(1);
}

int main(int argc, char** argv) {
    HThreadPool tp(4);
    tp.start();

    int i = 0;
    for (; i < 10; ++i) {
        tp.commit(print_task, i);
    }

    tp.wait();

    for (; i < 20; ++i) {
        tp.commit(print_task, i);
    }

    tp.wait();

    return 0;
}
