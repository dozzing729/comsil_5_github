#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받는 template 클래스 stack
//first가 가리키는 노드가 stack의 top에 대응한다
template <typename T>
class Stack : public LinkedList<T>{
	public:
		// LinkedList와 다르게 맨 첫번째 원소를 삭제(가장 늦게 들어온 원소를 삭제)
		virtual bool Delete(T& element) {
			if (this->first == 0) return false;
			//first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

			Node<T>* current = (this->first)->link;
			element = (this->first)->data;
			delete this->first;
			this->first = current;
			(this->current_size)--;

			return true;
		}
};
