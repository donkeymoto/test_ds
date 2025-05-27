#include <iostream>

template <typename T>
class ArrayList {
	private:
		T *base;
		int size;
		int capacity;
	public:
		ArrayList(int cap);
		~ArrayList();
		int addItem(int index, T item);
		int addItemTail(T item);
		int addItemHead(T item);
		int delItem(int index);
		int delItemTail();
		int delItemHead();
		int findItem(int index);
		int modiItem(int index, int val);
		int getItem(int index);

		int getCurrentItemCount(void);
		int getListCapacity(void);
		void showList(void);
};

template <typename T>
ArrayList<T>::ArrayList(int cap)
{
	base = new T[cap];
	size = 0;
	capacity = cap;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	delete base;
}

template <typename T>
int ArrayList<T>::addItem(int index, T item) {
	if (index >= capacity) {
		std::cout << "index out of size" << std::endl;
		return -1;
	}

	if (size == capacity) {
		std::cout << "out of capacity" << std::endl;
		return -1;
	}

	for (int i = capacity - 1; i >= index; i--){
		base[i] = base[i - 1];
	}

	base[index] = item;
	size++;
	return 0;
}


template <typename T>
int ArrayList<T>::addItemTail(T item) {
	if (size == capacity) {
		std::cout << "out of capacity" << std::endl;
		return -1;
	}

	base[size] = item;
	size++;
	return 0;
}

template <typename T> 
int ArrayList<T>::addItemHead(T item) {
	return addItem(0, item);
}

template <typename T>
int ArrayList<T>::modiItem(int index, int val) {
	if (index >= size) {
		return -1;
	}

	base[index] = val;
	return 0;
}

template <typename T>
int ArrayList<T>::delItem(int index) {

	for (int i = index; i < capacity - 1; i++) {
		base[i] = base[i + 1];
	}	
	size--;
	return 0;
}

template <typename T>
int ArrayList<T>::delItemTail() {
	size--;
	return 0;
}

template <typename T>
int ArrayList<T>::delItemHead() {
	if (size == 0)
		return -1;

	if (size == 1) {
		size--;
		return 0;
	}

	//std::cout << "size" << size << std::endl;
	for (int i = 0; i < size - 1; i++) {
		//std::cout << "[" << i << "]" << base[i] << "==" << base[i+1] << std::endl;
		base[i] = base[i + 1];
	}

	size--;
	return 0;
}

template <typename T> 
int ArrayList<T>::getItem(int index) {
	if (index >= size) {
		return -1;
	}
	return base[index];
}

template <typename T>
void ArrayList<T>::showList(void)
{
	std::cout << " ++++++++++ total:" << size << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << base[i] << std::endl;
	}
}

int main(void)
{
	ArrayList<double> al(10);
	al.addItem(0, 10);
	al.showList();
	al.addItem(0, 9);
	al.showList();
	al.addItem(0, 8);
	al.showList();
	al.addItem(1, 7);
	al.showList();
	al.addItemHead(100);
	al.showList();
	al.addItemTail(101);
	al.showList();
	al.modiItem(3, 10000);
	al.showList();
	al.addItem(4, 24);
	al.showList();
	al.addItem(5, 25);
	al.showList();
	al.addItem(6, 26);
	al.showList();
	al.delItem(6);
	al.showList();
	al.delItemTail();
	al.showList();
	al.delItemHead();
	al.showList();
}
