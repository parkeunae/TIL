#include <stdio.h>

void sortArray(int arr[], int arrSize, int count);

int main() {
    int numbers[5] = {3,1,2,4,5};

    sortArray(numbers, 5, 0);
}

// 오름차순으로 정렬 (선택 정렬, 재귀)
void sortArray(int arr[], int arrSize, int count) {
    if(count == arrSize) {
        return;
    }

    int min = 10;
    int minIndex = -1;

    for(int i=count; i<arrSize; i++) {
        if(arr[i]<min) {
            min = arr[i];
            minIndex = i;
        }
    }

    if(count < minIndex) {
        arr[minIndex] = arr[count];
        arr[count] = min;
    }

    count++;

    sortArray(arr, arrSize, count);
}



// 구글링해서 찾은 선택 정렬 (더 깔끔하게 작성된 거 같음.)
// 출처: https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
# define MAX_SIZE 5

// 선택 정렬
void selection_sort(int list[], int n){
  int i, j, least, temp;

  // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
  for(i=0; i<n-1; i++){
    least = i;

    // 최솟값을 탐색한다.
    for(j=i+1; j<n; j++){
      if(list[j]<list[least])
        least = j;
    }

    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != least){
        SWAP(list[i], list[least], temp);
    }
  }
}
