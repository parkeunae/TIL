# Flexbox in Internet Explorer

Can I use 사이트에서 flex를 검색하면 IE9 이전은 지원하지 않으며, IE10과 11은 부분적으로 지원하고 있음을 알 수 있다.

어쨌든 IE10에선 -ms- 접두사를 붙여

```css
display: -ms-flexbox;
...
-ms-flex: 1;
```

이런 식으로 사용이 가능하다.

IE11은 -ms- 접두사를 붙이지 않아도 된다.

<br/>

강의 미션 프로젝트는 IE10까지 지원하면 되므로 flexbox를 사용해 레이아웃을 짜보았다.

그런데 이게 웬일인지, IE11에서도 제대로 동작하지 않았다.

IE 관련 flexbug를 모아놓은 저장소에서 해답을 찾았다. [Flexbugs](https://github.com/philipwalton/flexbugs)

<br/><br/>

## flex-basis 단위

먼저, 원래는 flex item에 flex 축약형 속성으로 css를 설정했다.

```css
flex: 1 0 0;
```

하지만 IE에서는 ```flex: 1 0 0```처럼 ```flex-basis```의 값에 단위 없이 사용하면 flexibility 속성들은 무시되고, 오류가 발생한다.

IE10 출시 이전엔 ```flex: 1 0 0%``` 이런 식으로 단위를 적어주는 게 맞았다.

이젠 더 이상 그럴 필요없지만 IE에서는 여전하다.

(CSS minifier가 0px를 0으로 변환하기 때문에, ```flex: 1 0 0px```과 같은 값도 문제가 될 수 있다.)

Flexbugs - [flex shorthand declarations with unitless flex-basis values are ignored](https://github.com/philipwalton/flexbugs#flexbug-4)

<br/>

## flex 기본값

flex 속성의 기본값에서도 차이가 있다.

| Declaration | What it should mean |	What it means in IE 10 |
| ----------- | ------------------- | ---------------------- |
| (no flex declaration) |	```flex: 0 1 auto``` |	```flex: 0 0 auto``` |
| ```flex: 1``` |	```flex: 1 1 0%``` |	```flex: 1 0 0px``` |
| ```flex: auto``` |	```flex: 1 1 auto``` |	```flex: 1 0 auto``` |
| ```flex: initial``` |	```flex: 0 1 auto``` |	```flex: 0 0 auto``` |

그래서 IE10을 지원해야할 때는 flex-shrink 값을 설정하거나 축약형이 아닌 긴 형식으로 사용해야 한다.

Flexbugs - [The default flex value has changed](https://github.com/philipwalton/flexbugs#flexbug-6)

<br/>
<br/>
<br/>
<br/>

## 느낀점

아직 더 많은 버그들이 남아있지만, 프로젝트 하면서 체감했던 건 위의 두가지 상황이다.

나머지 버그들도 쭉 살펴보면 좋을 듯 하다.

IE를 지원해야 한다면 최대한 flex를 쓰지 않거나 버그가 있는지 확인할 필요가 있어 보인다.

