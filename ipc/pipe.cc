#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main() {
    int pipefd[2]; // 0读 1写
    int ret = pipe(pipefd);
    pid_t id = fork();
    if (id == 0) {
        close(pipefd[0]);
        const char*  msg = "i am zyunfei";
        fprintf(stdout, "child write:%s\n", msg);
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]);
        sleep(1);
        exit(0);
    } else {
        fprintf(stdout, "father read:");
        close(pipefd[1]);
        char msg[1024];
        ssize_t s = read(pipefd[0], msg, sizeof(msg) - 1);
        msg[s] = '\0';
        fprintf(stdout, "read msg:%s\n", msg);
    }
    if (waitpid(id, 0, NULL) != -1) {
        fprintf(stdout, "wait success\n");
    }
    return 0;
}