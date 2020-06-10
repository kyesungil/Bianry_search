# B. Binary_search(이진탐색)  
* binary_search을 하기 위해서는 데이터가 정렬(sort)되어 있어야 한다.
* first, middle, last pointer을 사용한다.(※ 이 예시에서 pointer는 index을 뜻합니다.)  
* 검색할 데이터의 자료형에 따라서 함수를 따로 구현한다.(이 예시에서는 "문자열"입니다.)  
#### code>>  
```c  
const Item* binary_search(const Item items[], const int size, const char name[TMAX])
{
	int first = 0;
	int last = size - 1;
	int middle;
	int result;

	while (1)
	{
		middle = (first + last) / 2;

		// 비교 결과에 따라 탐색구간 변경
		result = strcmp(items[middle].character, name);

		if (result == 0)
			return &items[middle];
		else if (result > 0)
			last = middle - 1;
		else
			first = middle + 1;


		if (first > last)
			break;

	}
	return NULL;
}
```  
## Ex 1) 검색할 데이터 "Iron Man"  

### 1-1) 정렬된 데이터에서 first, ast, middle을 정해준다.  
![1](https://user-images.githubusercontent.com/41607872/84234691-a0559f80-ab2f-11ea-8572-82ecfa825c46.jpg)  
### 1-2) middle과 "Iron Man" 비교 후, middle의 알파벳순이 더 빠르기 때문에 first = middle+1로 이동시켜 범위를 좁혀준다.  
![2](https://user-images.githubusercontent.com/41607872/84238953-c29eeb80-ab36-11ea-978b-7881a9128a10.jpg)  
### 1-3) 다시 비교 후, middle의 알파벳순이 더 느리기 때문에 last = middle-1로 이동시켜 범위를 좁혀준다.
![3](https://user-images.githubusercontent.com/41607872/84234695-a0ee3600-ab2f-11ea-87ae-c337d26e15b8.jpg)
### 1-4) 다시 비교 후,  middle과 "Iron Man"의 문자열이 같기때문에 middle에서 "Iron Man"에 대한 데이터 반환한다.
![4](https://user-images.githubusercontent.com/41607872/84234688-9f247280-ab2f-11ea-9274-9308788e7a9d.jpg)
## Ex 2) 검색할 데이터("Zedd")가 정렬된 데이터들에 없을 경우
### 2-1) 정렬된 데이터에서 first, ast, middle을 정해준다.  
![1 1](https://user-images.githubusercontent.com/41607872/84237912-2aeccd80-ab35-11ea-896c-8420b9ad7f9d.jpg)  
### 2-2) middle과 "Zedd" 비교 후, middle의 알파벳순이 더 빠르기 때문에 first = middle+1로 이동시켜 범위를 좁혀준다.
![1 2](https://user-images.githubusercontent.com/41607872/84237914-2cb69100-ab35-11ea-9137-9ff1f283c872.jpg)
### 2-3) 2-2반복  
![1 3](https://user-images.githubusercontent.com/41607872/84237917-2e805480-ab35-11ea-85a6-8f1cbed768c6.jpg)
### 2-4) 2-2반복  
![1 4jpg](https://user-images.githubusercontent.com/41607872/84237924-2f18eb00-ab35-11ea-9b47-74ad4b72c3a4.jpg)  
### 2-5) first > last 이기때문에 loop 탈출, return NULL;
![1 5](https://user-images.githubusercontent.com/41607872/84237928-30e2ae80-ab35-11ea-8078-7d1373cc7409.jpg)
***  
[참조: 인프런-홍정모의 따라하며 배우는 c언어 부록]  
