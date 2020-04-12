

// Если делить класс на два файла, то вылезает ошибка LNK2019. Поэтому всё запихнул в заголовочник

//#include "LinkedList.h"
//
//template<typename T>
//LinkedList<T>::LinkedList()
//{
//	Count = 0;
//	Head = nullptr;
//}
//
//template<typename T>
//T LinkedList<T>::operator[] (const int value) 
//{
//	assert(value >= 0 && value < this->Count);
//	Node<T>* result = Head;
//	for (auto i = 0; i < value; i++)
//	{
//		result = result->NextNode;
//	}
//	return result;
//}
//
//template<typename T>
//void LinkedList<T>::Add(T data)
//{
//	if (Head == nullptr)
//	{
//		Head->Data = data;
//		Head->NextNode = nullptr;
//	}
//	else
//	{
//		Node<T>* current = Head;
//		while (current->NextNode != nullptr)
//			current = current->NextNode;
//		current->NextNode = new Node<T>(data);
//	}
//	this->Count++;
//}
//
//template<typename T>
//void LinkedList<T>::RemoveDuplicates()
//{
//	Node<T>* temp;
//	Node<T>* previous;
//	Node<T>* current;
//	Node<T>* tempPrev;
//	for (previous = Head; previous != nullptr; previous = previous->NextNode)
//	{
//		tempPrev = previous;
//		for (current = previous->NextNode; current != nullptr;)
//		{
//			if (current->Data == previous->Data)
//			{
//				temp = tempPrev->NextNode;
//				tempPrev->NextNode = current->NextNode;
//				free(current);
//				current = temp;
//				Count--;
//			}
//			else
//			{
//				tempPrev = current;
//				current = current->NextNode;
//			}
//		}
//	}
//}
//template<typename T>
//T LinkedList<T>::SearchFromEnd(int k)
//{
//	Node<T>* result = Head;
//	for (auto i = 0; i < this->Count - k; i++)
//	{
//		Head = Head->NextNode;
//	}
//	return result;
//}