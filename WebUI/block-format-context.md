# Block Fromat Context (BFC)

블록 서식 맥락

BFC는 block boxes 레이아웃이 생기고, floats가 다른 요소와 상호 작용하는 영역이다.

다음 중, 하나 이상의 상황에 의해 만들어진다.

- document의 루트 요소, <html>
- 플로팅 요소 (float이 none이 아닌 요소)
- 절대 위치인 요소 (position이 absolute나 fixed인 요소)
- 인라인 블록 (display: inline-block인 요소)
- 테이블 셀 (display: table-cell이거나 HTML table 태그 셀들의 기본값)
- 테이블 주석 (display: table-caption이거나 HTML table caption의 기본값)
- display가 table, table-row, table-row-group, table-header-group, table-footer-group, inline-table인 요소가 암시적으로 생성한 익명 테이블 셀
- overflow가 visible이 아닌 블록 요소
- display가 flow-root인 요소
- contain이 layout, content, paint인 요소
- display: flex / inline-flex인 요소의 자식인 Flex items인데, 원래는 flex나 grid나 table 컨테이너가 아닌 요소들
- display: grid / inline-grid인 요소의 자식인 Flex items인데, 원래는 flex나 grid나 table 컨테이너가 아닌 요소들
- 다열 컨테이너 Multicol containers (column-count: 1인 요소들을 포함하여, column-count나 column-width의 값이 auto가 아닌 요소들)
- column-span이 all인 경우, 해당하는 요소가 다열 컨테이너 안에 위치하지 않아도 항상 해로운 BFC를 생성해야 한다.
    - (```column-count```, ```column-span``` 참고: [예시 코드](https://www.w3schools.com/cssref/tryit.asp?filename=trycss3_column-span](https://www.w3schools.com/cssref/tryit.asp?filename=trycss3_column-span))

BFC는 레이아웃에 영향을 주지만, 보통은 레이아웃이 아닌 position 설정과 float 해제를 위해 더 많이 사용한다. 새 BFC를 생성하는 요소들이 다음과 같은 결과를 수행하기 때문이다.

- [내부의 플로팅 요소들 가두기](#내부-플로팅-요소들-가두기)
- [외부 플로팅 요소들 제외하기](#외부-플로팅-요소들-제외하기)
- [margin collapsing 제거](#margin-collapsing-제거)

<br/>

## 내부 플로팅 요소들 가두기

아래와 같은 상황에서, float 요소는 흐름에서 벗어나 새로운 BFC를 만들고, .box를 가진 div 컨테이너 요소는 float 요소를 감싸지 못한다.

```html
<section>
    <div class="box">
        <div style="float:left;">floated box</div>
        <p>content inside the container</p>
    </div>
</section>
```

이럴 때 새 BFC 생성하는 방식을 이용해 내부의 float 요소를 가둘 수 있는 방법이 두가지 있다.

1. ```overflow: auto``` 사용

    ```html
    <section>
        <div style="overflow:auto;">
            <div style="float:left;">floated box</div>
            <p>content inside the container</p>
        </div>
    </section>
    ```

    ```overflow```에 기본 값인 ```visible```을 제외한  ```overflow: auto``` 등의 값을 설정하면 float 요소를 포함하는 새 BFC가 생성된다.

    단, 의도치 않은 스크롤바나 잘린 그림자가 생길 수 있다.

    또한, 향후 다른 개발자가 이 코드를 봤을 때, overflow를 사용한 이유를 파악하기 어려울 수 있다. 주석으로 설명을 남길 필요가 있다.

2. ```display: flow-root``` 사용

    ```html
    <section>
        <div style="flow-root">
            <div style="float:left;">floated box</div>
            <p>content inside the container</p>
        </div>
    </section>
    ```

    컨테이너 요소에 ```display: flow-root```를 적용하면, 그 안의 요소들이 모두 해당 컨테이너의 BFC에 포함된다.

    그러므로 위 예시 코드에서 div 태그 컨테이너에 ```display: flow-root```를 적용하면, 그 안의 float 요소가 밖으로 삐져나오지 않을 것이다.

<br/>

## 외부 플로팅 요소들 제외하기

아래처럼 float 요소가 있으면, ```margin-right``` 속성은 제대로 먹히지 않는다.

```html
<section>
  <div style="float:left; margin-right: 10px;">outer float</div>
  <div><p>sibling<p></div>
</section>
```

방법은 sibling div 요소에 ```display: flow-root```를 적용하여, 이중 열 레이아웃으로 만드는 것이다.

```html
<section>
  <div style="float:left; margin-right: 10px;">outer float</div>
  <div style="display:flow-root"><p>sibling<p></div>
</section>
```

float 요소의 새 BFC에 맞춰 형제 요소에도 동일한 BFC를 주어, margin이 적용되도록 하였다.

하지만 다중 열 레이아웃을 만들고자 한다면, float와 flow-root가 아닌 flexbox를 사용하는 것이 더 좋다.

<br/>

## margin collapsing 제거

새 BFC를 만들어, 인접한 두 요소의 margin 값이 합쳐지는 것을 피할 수 있다.

아래 코드와 같이 각 요소에 ```margin: 10px 0```을 주면, 1번 요소의 아래 여백과 2번 요소의 위 여백이 만나 합쳐지면서, 두 요소 사이에는 10px의 여백만 생긴다.

```html
<div style="margin:10px 0;">1</div>
<div style="margin:10px 0;">2</div>
```

이런 속성을 margin collapse라고 하는데,

margin collapse가 일어나지 않고, 위 아래 총합 20px 여백이 생기도록 하려면 한 요소에게 새 BFC를 만들어 주면 된다.

```html
<div style="margin:10px 0;">1</div>
<div style="overflow:hidden;">
	<div style="margin:10px 0;">2</div>
</div>
```

<br/>

## 출처

[MDN Block formatting context](https://developer.mozilla.org/ko/docs/Web/Guide/CSS/Block_formatting_context)
