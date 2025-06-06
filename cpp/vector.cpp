#include <vector>
#include <memory>
#include <iostream>

class Record {
	public:
		Record(int size) {
			printf("Reserving vector size to %d\n", size);
			strRec.resize(size);
		};
		~Record(void) {};
		int getSize(void) { return strRec.size(); } 
		int setString(int idx, std::string s) { strRec[idx] = s; } 
		int dumpRec(void) {
			for (auto &it: strRec){
				std::cout << "str:" << it << std::endl;
			}	

		}
	private:
		std::vector<std::string> strRec;
};

class RecordSharedPtr {
	public:

		typedef struct SharedObj {
			SharedObj(int id, std::string s) : idx_(id), s_(s) {}
			uint32_t idx_;
			std::string s_;
		} SharedObj;

		RecordSharedPtr(int size) {
			//printf("Reserving vector size to %d\n", size);
			//strRecs.resize(size);
		}
		~RecordSharedPtr(void) {}

		int getSize(void) { return strRecs.size(); } 

		int addElem(std::shared_ptr<SharedObj> rec) {
			strRecs.push_back(rec);
			std::cout << "-- size of vector: " << strRecs.size() << std::endl;
			//std::cout << " rec added: " << rec->s_  << std::endl;
		} 

		int dumpRec(void) {
			std::cout << "size of vector: " << strRecs.size() << std::endl;
			for (auto &it : strRecs){
				//std::cout << "rec usecount: " << it.use_count() << std::endl;
				std::cout << "str:" << it->s_ << " id: " << it->idx_ << std::endl;
			}	
			return 0;
		}

		int dumpRec1(void) {
			std::cout << "dump from iterator: size of vector: " << strRecs.size() << std::endl;
			for (auto it = strRecs.begin(); it != strRecs.end(); it++){
				std::cout << "str:" << (*it)->s_ << " id: " << (*it)->idx_ << std::endl;
			}	
			return 0;
		}

		int dumpRec2(void) {
			std::cout << "dump from iterator shared: size of vector: " << strRecs.size() << std::endl;
			for (auto it = strRecs.begin(); it != strRecs.end(); it++){
				std::cout << "str:" << (*it).get()->s_ << " id: " << (*it).get()->idx_ << std::endl;
			}	
			return 0;
		}

	private:
		std::vector<std::shared_ptr<SharedObj>> strRecs;
};

int main(void)
{
	Record *rec = new Record(4);
	printf("size of vector: %d\n", rec->getSize());
	rec->setString(2, std::string("aaaa for index 2"));
	rec->dumpRec();


	RecordSharedPtr rsp(10);
	printf("size of vector: %d\n", rsp.getSize());
	for (auto i = 0; i < 10; i++) {
		std::shared_ptr<RecordSharedPtr::SharedObj>
		obj = std::make_shared<RecordSharedPtr::SharedObj>(i, "str" + std::to_string(i));
		rsp.addElem(obj);
	}

	rsp.dumpRec();
	rsp.dumpRec1();
	rsp.dumpRec2();
	return 0;
}
