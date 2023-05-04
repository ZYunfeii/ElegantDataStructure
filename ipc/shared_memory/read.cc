#include <unistd.h>
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

    system("ipcs -m");
    // 打开共享内存
    shmid = shmget(key, BUF_SIZE, IPC_CREAT | 0666);

    // 映射
    shmadd = (char*)shmat(shmid, NULL, 0);

    // 读共享内存区数据
    printf("data = %s", shmadd);

    // 分离共享内存和当前进程
    ret = shmdt(shmadd);

    // 删除共享内存
    shmctl(shmid, IPC_RMID, NULL);
    system("ipcs -m");
    return 0;
}