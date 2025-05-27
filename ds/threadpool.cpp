#include <vector>
#include <thread>
#include <iostream>
#include <queue>
#include <condition_variable>

#define MAX_THREADS 12

template <typename T>
class ThreadPool {
	public:
		ThreadPool(int threadNum = 1);
		~ThreadPool();
		int appendTask(T *task);

	private:
		static void *worker(void *arg);
		
	private:
			std::vector<std::thread> threads;
			std::queue<T *> tasks;
			std::mutex queueMutex;
			std::condition_variable cond;
			bool stop;
};

template<typename T>
ThreadPool<T>::ThreadPool(int num):stop(false)
{
	if (num <=0 || num > MAX_THREADS)
		throw std::exception();

	for (int i = 0; i < num; i++) {
		threads.emplace_back(worker, this);
	}
}

template<typename T>
ThreadPool<T>::~ThreadPool()
{
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		stop = true;
	}

	cond.notify_all();

	for (auto &th : threads)
		th.join();
}

template<typename T>
int ThreadPool<T>::appendTask(T *task)
{
	{
	std::unique_lock<std::mutex> lock(queueMutex);
	tasks.push(task);
	}
	cond.notify_one();
}

template<typename T>
void *ThreadPool<T>::worker(void *arg)
{
	ThreadPool *thp = (ThreadPool *)arg;
	while (!thp->stop) {
		std::unique_lock<std::mutex> lk(thp->queueMutex);
		thp->cond.wait(lk, [thp]{return !thp->tasks.empty();});
		if (thp->tasks.empty())
			continue;
		else {
			T *tsk = thp->tasks.front();
			thp->tasks.pop();
			if (tsk)
				tsk->process();
		}
	}
	return thp;
}

#if 0
template<typename T>
void ThreadPool<T>::run()
{
}
#endif

//////////////////////////////////////////////////////////////////////////
class Task
{
public:
    void process()
    {
        static int a = 0;
        ++a;
        std::cout << "run......" << a << std::endl;
    }
};

int main()
{
    ThreadPool<Task> tp(2);

    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        Task* t = new Task();
        tp.appendTask(t);
        delete t;
    }
}


