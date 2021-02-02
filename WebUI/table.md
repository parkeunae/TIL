# table

## 접근성

- scope (col, row, colgroup, rowgroup)
- id, headers

제목 셀(th)에 어떤 내용 셀(td)에 대한 것인지 scope으로 표시한다.

아주 복잡한 표에는 id와 headers 속성을 추가해준다.

<br/>

## 크로스 브라우징

테이블은 브라우저마다 렌더링 하는 방식이 모두 다르다.

예를 들어, td에 position: relative;를, 그 안의 요소에 position: absolute;를 적용했을 때

브라우저 별로 노출 위치가 달라질 수 있다.

td 안에 div를 추가하여, div에 relative를 주는 것이 가장 안정적이다.

(파이어폭스에선 여전히 문제지만, 높이 값과 콘텐츠가 있으면 정상 노출된다.)

-> td 안에 div를 추가

<br/>

## border

table 요소에 border를 적용하면 각 셀의 모든 선이 표시된다.

- ```border-collapse: separate;```가 기본값인데,

table, thead, tfoot, tbody 순으로 렌더링된다.


- ```border-collapse: collapse;``` 하면 인접한 border들은 병합되어 한 줄이 된다.

우측 하단부터 좌측 상단 순으로 렌더링된다.

border를 병합했을 때, 다른 테이블 요소들에게 border가 적용되어 있으면 table 태그에 적용한 border는 보이지 않는다.

테이블 요소들이 table - thead - tbody - tr - th - td 순으로 레이어처럼 쌓이기 때문이다.

가장 먼저 그려진 table 태그로 적용된 border는 셀에 적용된 border에 덮여 보이지 않는다.

colgroup의 col을 사용해 border나 background 스타일을 열에 일괄 적용할 수 있으나,
다른 셀들에 비해 z-index가 낮아 가려지는 경우가 많아서 잘 사용하지 않는다.

<br/>

## colgroup

`<coulgroup>`의 `<col>`

테이블의 열을 가리킨다.

예전에는
```html
<colgroup>
  <col width="30">
</colgroup>
```
이렇게도 썼지만, html5에서 더 이상 지원하지 않기 때문에 css로 제어한다.

```html
<colgroup>
  <col style="width: 30px;">
</colgroup>
```

col 태그에 적용할 수 있는 스타일은 width, border, background 3가지이다.

```<col span="2">``` 이렇게 span 속성으로 병합도 가능하다.
(열에 대한 스타일 제어가 필요 없거나, 동일한 스타일을 적용해야 할 때 사용한다.)

<br/>

## table-layout: fixed;

table에 전체 표의 크기를 지정하면, 각 셀의 너비는 내용과 비례하여 자동 분할된다.

**성능 상으로도 좋으니 반드시 추가해 주는 것이 좋다.**

<br/>
<br/>

## 느낀점

테이블 요소는 많이 썼는데, 생각보다 모르는 게 많았다.

특히 ```border-collapse: collapse;```일 때 렌더링 순서가 달라진다는 것, ```table-layout: fixed;```는 성능상으로도 추가하는 것이 좋다는 것.

접근성과 크로스 브라우징 문제에 대해서 공부할 것들이 아직 많이 남은 것 같다.
