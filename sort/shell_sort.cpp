#include <iostream>

using namespace std;

void shell_sort(int A[], int N) {
	int tmp; // �ڱ�
	int increment = N; 
	int j;
	do {
		increment = increment / 3 + 1; // ������ô�仯�Ļ�����ʵ�ǲ�Ӱ��ϣ���������ȷ�Եģ����ǿ��ܻ�Ӱ������
		for (int i = increment; i < N; ++i) {
			if (A[i] < A[i - increment]) {
				tmp = A[i]; // ���ڱ��洢A[i]
				for (j = i - increment; j >= 0 && A[j] > tmp; j -= increment) {
					A[j + increment] = A[j]; // ������߼�ͦ���������ģ�ֻ�ǲ�������increment=1����ʵ�����һ��ϣ��������ǲ�������
				}
				A[j + increment] = tmp; // �������ˣ��ڱ��洢����A[i](ΪʲôҪ�洢����Ϊ�ڽ����Ĺ����л��ú��������������������jͣ�ڴ�����tmpλ�õ�ǰincrement��)
			}
		}
	} while (increment > 1); // �൱��increment = 1ʱ��ֹ
}

int main(int argc, char** argv) {
	int A[] = { 3,4,1,5 };
	int N = sizeof(A) / sizeof(A[0]);
	shell_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}