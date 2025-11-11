#pragma once
#include <iostream>

using namespace std;

template <typename InfoType>
class Deque {
private:
	struct DItem {
		InfoType info;
		DItem* next;
		DItem* prev;
		DItem(InfoType Ainfo) : info(Ainfo), next(NULL), prev(NULL) {}
	};
	DItem* front;
	DItem* rear;
	unsigned size;
	void Erase();
	void Clone(const Deque&);
protected:
	void* PtrByIndex(unsigned) const;
public:
	Deque& Sort();
	Deque() : front(NULL), rear(NULL), size(0) {};
	Deque(const Deque&);
	~Deque();

	Deque& operator= (const Deque&);

	const InfoType& GetByIndex(unsigned k) const;
	InfoType& operator[] (unsigned);
	
	void push_back(InfoType AInfo);
	void push_front(InfoType AInfo);
	
	bool pop_front();
	bool pop_back();
	InfoType GetFirst() const;
	bool IsEmpty() const;
	unsigned GetSize() const;

	void Browse(void ItemWork(InfoType)) const;
	void Browse(void ItemWork(InfoType&));

	template <typename T> friend ostream& operator<< (ostream& out, const Deque<T>& d);

	template <typename T> friend ostream& operator<< (const Deque<T>& d, ostream& out);
};

