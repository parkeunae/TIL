# 알고리즘

입력값을 출력값의 형태로 바꾸기 위해 어떤 명령들이 수행되어야 하는지에 대한 규칙들의 순서적 나열

<br/>

## 알고리즘 표기법

알고리즘의 실행 시간을 나타내는 표기법이 있다.

<br/>

**Big O**

알고리즘 실행 시간의 상한을 나타낸다.

O는 "on the order of"의 약자로, "~만큼의 정도로 커지는" 의미이다.

- O(n^2) - 버블정렬, 선택정렬
- O(n log n) - 병합정렬
- O(n) - 선형 검색
- O(log n) - 이진 검색
- O(1)

<br/>

**Big Ω**

알고리즘 실행 시간의 하한을 나타낸다.

- Ω(n^2) - 선택정렬
- Ω(n log n) - 병합정렬
- Ω(n) - 배열 안에 존재하는 값의 개수 세기, 버블정렬
- Ω(log n)
- Ω(1) - 선형 검색, 이진 검색 (운이 좋으면 한번에 검색될 수 있다.)

<br/>

## 선형 검색

원하는 값이 나올 때까지 처음부터 끝까지 차례대로 검색한다.

의사코드

```
For i from 0 to n–1

    If i'th element is 50

        Return true

Return false
```

**자료가 정렬되어 있지 않거나 그 어떤 정보도 없이 하나씩 찾아야 하는 경우 유용하다.**

정렬이 오래 걸리고 공간을 더 차지한다고 해도,
리스트를 여러 번 검색해야 하거나 매우 큰 리스트를 검색해야 할 경우,
정렬 과정을 거치고 더 효율적인 검색 방법을 선택하는 것이 좋다.

<br/>

## 이진 검색

배역이 정렬되어 있다면, 중간 인덱스부터 시작해 찾는 값과 비교하여 작으면 왼쪽, 크면 오른쪽으로 이동하며 찾는다.

의사코드

```
If no items

    Return false

If middle item is 50

    Return true

Else if 50 < middle item

    Search left half

Else if 50 > middle item

    Search right half
```

<br/>

## 버블 정렬

두 개의 인접한 자료 값을 비교하며 위치를 교환하는 방식으로 정렬하는 방법이다.

두 개의 값이 서로 교환되면서 점점 옆으로 이동하는 방식이 거품이 터지면서 위로 올라가는 모양 같아서 버블 정렬이다.

간단한 방법이지만, 너무 많은 교환이 발생해 낭비가 될 수도 있다.

의사 코드

```
Repeat n–1 times

    For i from 0 to n–2

        If i'th and i+1'th elements out of order

            Swap them
```

루프가 각각 n-1번, n-1번 반복되어, (n-1)*(n-1) = n^2-2n+1번의 비교 및 교환이 필요하다.

버블 정렬 실행 시간의 상한은 O(n^2)다.

정렬이 되어 있는지 여부에 관계 없이 루프를 돌며 비교해야 하므로, 실행 시간 하한도 Ω(n^2)가 된다.

만약 안쪽 루프에서 교환이 하나도 일어나지 않는다면, 이미 정렬이 잘 되어 있는 상황일 것이다.

```
Repeat until no swaps

    For i from 0 to n–2

        If i'th and i+1'th elements out of order

            Swap them
```

안쪽 루프에 교환이 한번도 일어나지 않았다면, 정렬이 된 것으로 보고 종료한다면,
버블 정렬의 하한은 Ω(n)이 된다.

<br/>

## 선택 정렬

배열 안의 자료 중 가장 작은 수(혹은 가장 큰 수)를 찾고,
그 값을 첫 번째 위치(혹은 가장 마지막 위치)의 값과 교환해주는 방식의 정렬이다.

교환 횟수는 최소화했지만, 각 자료를 비교하는 횟수는 증가한다.

의사 코드

```
For i from 0 to n–1

    Find smallest item between i'th item and last item

    Swap smallest item with i'th item
```

소요 시간의 상한은 O(n^2)이고, 하한도 마찬가지로 Ω(n^2)이다.

<br/>

## 재귀

함수가 본인 스스로를 호출하는 것을 재귀라고 한다.

무한 루프가 되지 않도록 주의해야 한다. (종료 조건 확인)

<br/>

## 병합 정렬

원소가 한 개가 될 때까지 계속해서 반으로 나누다가 다시 합쳐나가며 정렬하는 방식이다.

7 | 4 | 5 | 2 | 6 | 3 | 8 | 1 → 가장 작은 부분 (숫자 1개)으로 나눠진 결과입니다.

4   7 | 2   5 | 3   6 | 1   8 → 숫자 1개씩을 정렬하여 병합한 결과입니다.

2   4   5   7 | 1   3   6   8 → 숫자 2개씩을 정렬하여 병합한 결과입니다.

1   2   3   4   5   6   7   8 → 마지막으로 숫자 4개씩을 정렬하여 병합한 결과입니다.

이 과정은 재귀적으로 구현된다.

실행 시간 상한은 O(n log n), 하한도 Ω(n log n)이다.
숫자들의 정렬 상태 상관 없이 나누고 병합하는 과정이 필요하기 때문.
