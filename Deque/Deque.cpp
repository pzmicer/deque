#include "Deque.h"

template <typename InfoType>
Deque<InfoType>& Deque<InfoType>::Sort()
{
	bool exit = false;
	while(!exit)
	{
		DItem* curr = front;
		exit = true;
		for (unsigned i = 0; i < this->size - 1; i++)
		{
			if (curr->info > (curr->next)->info)
			{
				DItem* rem = curr->next;
				if(curr != front)
					(curr->prev)->next = rem;
				if(rem != rear)
					(rem->next)->prev = curr;
				curr->next = rem->next;
				rem->next = curr;
				rem->prev = curr->prev;
				curr->prev = rem;
				exit = false;
				if (i == 0)
					front = rem;
				else if (i == this->size - 2)
					rear = curr;
			}
			else
				curr = curr->next;
		}
	}
	return *this;
}

template <typename InfoType>
void Deque<InfoType>::Erase() {
	while (pop_front());
	size = 0;
}

template <typename InfoType>
void Deque<InfoType>::Clone(const Deque& Q) {
	DItem* tmp = Q.front;
	for (unsigned i = 0; i < Q.size; i++) {
		push_back(tmp->info);
		tmp = tmp->next;
	}
}

template <typename InfoType>
Deque<InfoType>::Deque(const Deque& Q) {
	size = 0; Clone(Q);
}

template <typename InfoType>
Deque<InfoType>::~Deque() {
	Erase();
}

template <typename InfoType>
Deque<InfoType>& Deque<InfoType>::operator= (const Deque& Q) {
	if (this != &Q) {
		Erase();
		Clone(Q);
	}
	return *this;
}

template <typename InfoType>
void Deque<InfoType>::push_back(InfoType Ainfo) {
	DItem* tmp = new DItem(Ainfo);
	if (size > 0)
	{
		rear->next = tmp;
		tmp->prev = rear;
	}
	else
	{
		front = tmp;
	}
	rear = tmp;
	size++;
}

template <typename InfoType>
void Deque<InfoType>::push_front(InfoType Ainfo) {
	DItem* tmp = new DItem(Ainfo);
	if (size > 0)
	{
		front->prev = tmp;
		tmp->next = front;
	}
	else
	{
		rear = tmp;
	}
	front = tmp;
	size++;
}

template <typename InfoType>
bool Deque<InfoType>::pop_front() {
	if (size == 0)
		return false;
	DItem* tmp = front;
	front = front->next;
	delete tmp;
	if(front != nullptr)
		front->prev = nullptr;
	size--;
	if (size == 0)
		rear = nullptr;
	return true;
}

template <typename InfoType>
bool Deque<InfoType>::pop_back() {
	if (size == 0)
		return false;
	DItem* tmp = rear;
	rear = rear->prev;
	delete tmp;
	if(rear != nullptr)
		rear->next = nullptr;
	size--;
	if (size == 0)
		front = nullptr;
	return true;
}

template <typename InfoType>
InfoType Deque<InfoType>::GetFirst() const {
	if (size == 0)
		throw exception("Impossible to execute GetFirst: queue is empty!");
	return front->info;
}
template <typename InfoType>
bool Deque<InfoType>::IsEmpty() const {
	return (size == 0);
}

template <typename InfoType>
unsigned Deque<InfoType>::GetSize() const {
	return size;
}
template <typename InfoType>
void* Deque<InfoType>::PtrByIndex(unsigned k) const
{
	if (k < 0 || k >= this->size)
		throw exception("Impossible to obtain deque item: invalid index.");
	DItem* tmp = front;
	for (unsigned i = 0; i < k; i++)
		tmp = tmp->next;
	return tmp;
}

template <typename InfoType>
const InfoType& Deque<InfoType>::GetByIndex(unsigned k) const
{
	return ((DItem*)PtrByIndex(k))->info;
}

template <typename InfoType>
InfoType& Deque<InfoType>::operator[] (unsigned k)
{
	return (InfoType&)((DItem*)PtrByIndex(k))->info;
}

template <typename InfoType>
void Deque<InfoType>::Browse(void ItemWork(InfoType)) const {
	DItem* tmp = front;
	for (unsigned i = 0; i < size; i++) {
		ItemWork(tmp->info);
		tmp = tmp->next;
	}
}

template <typename InfoType>
void Deque<InfoType>::Browse(void ItemWork(InfoType&)) {
	DItem* tmp = front;
	for (unsigned i = 0; i < size; i++) {
		ItemWork(tmp->info);
		tmp = tmp->next;
	}
}

template <typename InfoType>
ostream& operator<< (ostream& out, Deque<InfoType>& d)
{
	for (unsigned i = 0; i < d.GetSize(); i++)
		out << d.GetByIndex(i) << " ";
	return out;
}

template <typename InfoType>
ostream& operator<< (Deque<InfoType>& d, ostream& out)
{
	for (unsigned i = d.GetSize() - 1; i>= 0; i--)
		out << d.GetByIndex(i) << " ";
	return out;
}
