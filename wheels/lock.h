#ifndef LOCK_H
#define LOCK_H

#include <atomic>

class MLock {
private:
	std::atomic_flag alock = ATOMIC_FLAG_INIT;
public:
	void lock() {
		while (true == alock.test_and_set()) {}
	}
	void unlock() {
		alock.clear();
	}
};

#endif