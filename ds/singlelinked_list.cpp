

template <typename T>
class LinkedList {
	private:
		struct ListNode {
			T val;
			ListNode *next;
			ListNode(T val) {
				this->val = val;
				this->next = nullptr;
			};
			ListNode() {
				this->next = nullptr;
			};
		};

		ListNode *dummy, *tail;
		int count

	public:
		LinkedList() {
			dummy = new ListNode();
			tail = dummy;
			count = 0;
		}

		~LinkedList() {
			// release all nodes
		}

		int addItem(int index, T item) {
			if (index >= count) {
				return -1;
			}

			ListNode *prev = this->dummy;
			for (int i = 0; i < index; i++) {
				prev = prev->next;
			}

			ListNode *newNode = new ListNode(item);
			ListNode *temp = prev->next;
			prev->next = newNode;
			newNode->next = temp;

			if (count == 0) {
				tail = newNode;
			}

			count++;

			return 0;
		}
		
		int addItemHead(T item) {
			return addItem(0, item);
		}

		int addItemTail(T item) {
			ListNode *newNode = new ListNode(item);
			tail->next = newNode;
			tail = newNode;
			return 0;
		}
		
		int delItem(int index) {
			ListNode *prev = dummy;
			for (int i = 0; i < index; i++) {
				prev = prev->next;
			}
			ListNode *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
			count--;
			return 0;
		}

		int delItemHead() {
			return delItem(0);
		}

		int delItemTail() {
			return deleItem(count - 1);
		}
};
