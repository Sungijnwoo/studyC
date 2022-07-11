#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//방법3

	// 기본 값 0으로 초기화 된 원소 10개를 가진 벡터 
	vector<int> myVec(10);

	// 맨뒤에 11을 추가
	myVec.push_back(11);
	myVec.push_back(11);
	myVec.push_back(11);
	myVec.push_back(11);

	myVec.pop_back();


	for (auto item : myVec) {
		cout << item << " ";
	}
	return 0;
}
