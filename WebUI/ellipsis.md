# 말 줄임표...

<br/>

**한 줄**에 말 줄임표 붙일 땐 아래 코드로 충분하다. (블록 요소에만 가능)

```css
overflow: hidden;
text-overflow: ellipsis;
white-space: nowrap;
```

<br/>
<br/>

**여러 줄**의 글자 수를 제한하고 말 줄임표를 붙일 땐 ```white-space: nowrap```을 쓸 수 없으므로,
다른 방법을 사용해야 한다.

``` -webkit-line-clamp ``` 속성은 블록 컨테이너의 콘텐츠를 지정한 줄 수만큼으로 제한할 수 있다.

단, 이 속성을 사용하려면 ```display``` 속성을 ```-webkit-box``` 또는 ```-webkit-inline-box```로
설정하고,

```-webkit-box-orient: vertical;```를 설정한 경우에만 동작한다.

``` -webkit-line-clamp ```로 말줄임표를 만들어도, 넘친 콘텐츠가 숨겨지진 않는다.

그래서 ```overflow: hidden;``` 설정도 필요하다.

<br/>

결과) 아래처럼 작성해야 한다.

```css
overflow: hidden;
display: -webkit-box;
-webkit-box-orient: vertical;
-webkit-line-clamp: 3; /* 줄 수 */
```

<br/>

하지만 IE는 이 속성을 지원하지 않는다.

JS를 사용하여 대체할 수 있다.

혹은 ```max-height```를 ```line-height```값*(줄 수) 값으로 적용하면 원하는 줄 수 만큼 글을 자를 수 있다.
(다만 css 설정만으로는 말줄임표는 안 나온다.)

