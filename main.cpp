#include <stdio.h>
#include "Stack.h"

// UI, 기본 선택창을 출력하는 함수
void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode;
		
		// stack 자료구조를 선택한 경우
		if(mode == 1)
			p = new Stack<int>();    // 정수를 저장하는 스택
			
		else //linkedlist 자료구조를 선택한 경우
			p = new LinkedList<int>(); // 정수를 저장하는 링크드리스트


		do{
			prnMenu();
			cin>>selectNumber;
			
			switch(selectNumber){ 
				case 1: //삽입 처리
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2: //삭제 처리
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3: //크기와 원소 출력 처리
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4: //종료 처리
					flag = true;     break;
					
				default: // 예외 입력 처리
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			//종료를 해야하는지 체크
			if(flag) break;
			
		} while(1);
		
		return 0;
}

