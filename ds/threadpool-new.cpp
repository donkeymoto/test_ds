
class Task {
	public:
		void process(void) {
			std::cout << "task processing" << std::endl;
		}
};

class ThreadPool {
	private:
		int numThreads;
		std::vector<std::thread> threads;
		std::queue<Task *> tasks;
		std::mutex lock;
		std::condition_variable cv;
	
	private:
		static void *worker(void *args) {
			ThreadPool *tp = args;
			while (true) {
				std::unique_lock<std::mutex> lk(lock)
				tp->cv.wait(lk, !tp->task.empty());
				Task t = tp->task.front();
				tp->task.pop();

				t.process();
				cv.unlock;
			}

		}

	public:
		ThreadPool(int threadNum) : numThreads(threadNum) {
			for (int i = 0; i < numThreads; i++) {
				threads.emplace_back(worker, this);
			}
		}

		~ThreadPool() {
			for (auto &th : threads) {
				th.join();
			}
		}

		int appendTask(Task *t) {
			std::unique_lock<std::mutex> lk(lock);
			tasks.push(t);
			cv.notify_one();
		}
}

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
