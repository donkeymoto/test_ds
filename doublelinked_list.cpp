#include <iostream>

template <typename T>
class DoubleLinkedList {
	private:
		struct Node {
			T val;
			Node *prev;
			Node *next;
			Node(T val) {
				this->val = val;
				this->prev = this->next = nullptr;
			}
			Node() {
				this->prev = this->next = nullptr;
			}
		};

		Node *head, *tail;
		int size;

	public:
		DoubleLinkedList() {
			head = new Node();
			tail = new Node();
			head->next = tail;
			tail->prev = head;
			size = 0;
		}

		~DoubleLinkedList() {
#if 0
			//free all nodes
			Node *p = head;
			while (p) {
				Node *temp = p->next;
				delete p;
				p = temp;
			}
#else
			T it;
			while (!isEmpty()) {
				delItemHead(it);
			}
#endif
		}

		int addItem(int index, T val) {
			if (index < 0 || index > size) {
				return -1;
			}

			Node *toAdd = new Node(val);
			Node *prev = head;
			for (int i = 0; i < index; i++) {
				prev = prev->next;
			}

			Node *temp = prev->next;
			prev->next = toAdd;
			toAdd->prev = prev;
			toAdd->next = temp;
			temp->prev = toAdd;

			size++;

			return 0;
		}

		int addItemHead(T val) {
			return addItem(0, val);
		}

		int addItemTail(T val) {
#if 0
			Node *toAdd = new Node(val);

			tail->prev->next = toAdd;
			toAdd->prev = tail->prev;
			toAdd->next = tail;
			tail->prev = toAdd;

			size++;
			return 0;
#endif
			return addItem(size, val);

		}

		int delItem(int index, T &it) {
			if (index >= size) {
				return -1;
			}

			Node *p = head;
			for (int i = 0; i <= index; i++) {
				p = p->next;
			}

			Node *prev = p->prev;
			Node *next = p->next;
			prev->next = next;
			next->prev = prev;

			it = p->val;
			delete p;
			size--;
			return 0;
		}

		int delItemHead(T &it) {
			if (size == 0) {
				return -1;
			}
			
			auto ret = delItem(0, it);
			return ret;
		}

		int delItemTail(T &it) {
			if (size == 0) {
				return -1;
			}

			Node *temp = tail->prev;
			tail->prev->prev->next = tail;
			tail->prev = tail->prev->prev;
			it = temp->val;
			delete temp;
			size--;
			return 0;
		}

		int getItem(int index, T &val) {
			if (index < 0 || index >= size) {
				return -1;
			}

			Node *cur = head;
			for (int i = 0; i <= index; i++) {
				cur = cur->next;
			}

			val = cur->val;
			return 0;
		}

		int getItemHead(T &val) {
			if (size == 0) {
				return -1;
			}
			val = head->next->val;
			return 0;
		}

		int getItemTail(T val) {
			if (size == 0) {
				return -1;
			}
			val = tail->prev->val;
			return 0;
		}

		int getSize() {
			return size;
		}

		int setItem(int index, T val) {
			if (index < 0 || index >= size) {
				return -1;
			}
			Node *p = head;
			for (int i = 0; i <= index; i++) {
				p = p->next;
			}

			p->val = val;
			return 0;
		}

		int showAllItems() {
			if (size == 0) {
				return 0;
			}

			std::cout << "+++++++++++ total: " << size << std::endl;
			Node *p = head->next;
			while (p != tail) {
				std::cout << p->val << std::endl;
				p = p->next;
			}
			return 0;
		}

		bool isEmpty() {
			return size == 0;
		}
};

#define CHECK_RET(x) \
{ \
	int ret = x; \
	if (ret) { \
		std::cout << "Failed at: " << __LINE__ << std::endl; \
	}\
}

template <typename T>
class ListQueue {
	private:
		DoubleLinkedList<T> myList;
	public:
		ListQueue () {}

		~ListQueue () {
			T it;
			std::cout << "destructing ListQueue" << std::endl;
			auto ret = pop(it);
			while (!ret) {
				std::cout << "Poped: " << it << std::endl;
				ret = pop(it);
			}
		}

		int push (const T &val) {
			return myList.addItemTail(val);
		}

		int pop (T &it) {
			auto ret = myList.delItemHead(it);
			return ret;
		}

		int peek(T &it) {
			T elem;
			auto ret = myList.getItemHead(it);
			return ret;
		}

		int size() {
			return myList.getSize();
		}
};

int main() {
	int it;
	DoubleLinkedList<int> dlist;
	CHECK_RET(dlist.addItemHead(11));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.addItemHead(12));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.addItemTail(13));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.addItemTail(14));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.addItemTail(15));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.addItem(3, 88));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.delItem(3, it));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.delItemHead(it));
	CHECK_RET(dlist.showAllItems());
	CHECK_RET(dlist.delItemTail(it));
	CHECK_RET(dlist.showAllItems());

	ListQueue<int> lq;
	int val;

	CHECK_RET(lq.push(22));
	CHECK_RET(lq.push(11));
	CHECK_RET(lq.push(33));
	CHECK_RET(lq.push(34));
	CHECK_RET(lq.push(34));
	CHECK_RET(lq.peek(val));
	CHECK_RET(lq.pop(val));
	std::cout << "poped: " << val << std::endl;
	CHECK_RET(lq.pop(val));
	std::cout << "poped: " << val << std::endl;
}
