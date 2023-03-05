#include <unistd.h>
#include <sys/ipc.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <string.h>
using namespace std;
#define BUF_SIZE 512
int main() {
    int shmid;
    int ret;
    key_t key;
    char* shmadd;
    // 创建key值
    key = ftok("./", 2015);
    // 创建共享内存
    shmid = shmget(key, BUF_SIZE, IPC_CREAT | 0666);
    // 映射
    shmadd = (char*)shmat(shmid, NULL, 0);
    printf("copy data to shared_memory\n");
    bzero(shmadd, BUF_SIZE);
    strcpy(shmadd, "i am yunfei");
    return 0;
}