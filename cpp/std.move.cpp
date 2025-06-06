#include <chrono>
#include <thread>
#include <vector>
#include <memory>
#include <utility>
#include <iostream>

class RecordSharedPtr {
	public:

#if 0
		typedef struct SharedObj {
			SharedObj(int id, std::string s) : idx_(id), s_(s) {}
			uint32_t idx_;
			std::string s_;
		} SharedObj;
#endif

		RecordSharedPtr(void) {
			printf(">>>>>>> Constructor \n");
		}
		~RecordSharedPtr(void) {
			printf("<<<<<< destructor \n");
		}

#if 1
		RecordSharedPtr(const RecordSharedPtr&) {
			printf(">>>>>>> Copy Constructor \n");
		}

		RecordSharedPtr( RecordSharedPtr&&) {
			printf(">>>>>>> Move Constructor \n");
		}
#endif

	private:
		//std::vector<SharedObj> strRecs;
};

int main(void)
{
	using namespace std::chrono_literals;

	std::vector<RecordSharedPtr> vRecs;

	{
		RecordSharedPtr rec;
		
		printf(">>>>>>> before move and push_back \n");
		vRecs.push_back(std::move(rec));
		printf(">>>>>>> after move and push_back \n");
		std::this_thread::sleep_for(4000ms);
	}
		printf(">>>>>>> out of scope \n");
	std::this_thread::sleep_for(4000ms);
	return 0;
}
