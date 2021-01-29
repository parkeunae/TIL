# CSS 리셋

## 브라우저 리셋하기

브라우저마다 코드를 해석하는 방식이 다르다. 렌더링 하는 기본 스타일에도 조금씩 차이가 있다. 크로스 브라우징을 위해 브라우저의 기본 스타일부터 리셋시켜주어야 한다.

CSS를 리셋하는 데 정해진 형식은 없다. **프로젝트 성격에 맞춰 작성하면 된다. 모든 브라우저에서 동일한 화면을 보여주기 위해 기본값을 초기화한다는 점만 기억하면 된다.**

<br/>

## reset.css 제작

- 대부분 margin, padding(여백)은 0으로 초기화 하는 것이 CSS로 디자인하기 편하다. 그 외의 속성들은 프로젝트에서 공통으로 초기화할 필요가 있는 부분만!

- 모두 동일하게 보이도록 커스텀하기는 매우 까다로운 잡업이라, 디자인 요소로 커스텀을 많이 한다. 프로젝트에서 공통으로 초기화 해줄 필요가 있는 속성을 **최소한**으로 골라 리셋해주면 된다.

- 스타일은 태그별로 적용되어있기 때문에, 태그 자체에 직접 스타일을 입력해주어야 한다.

- css를 reset해주는 부분은 최상단에 작성한다.

- 예시)

```css
body,
h1, h2, h3, h4, h5, h6,
ul, ol, dl, dd,
p,
fieldset, legend {
	margin: 0;
	padding: 0;
}

body, input, textarea, select, button {
	font-size: 14px;
	font-family: Dotum,'돋움',Helvetica,"Apple SD Gothic Neo",sans-serif;
}

ul, ol {
	list-style: none;
}

table {
	border-collapse: collapse;
}

em {
	font-style: normal
}

a {
	color: inherit;
	text-decoration: none;
}

a:hover {
	text-decoration: underline;
}

img {
	vertical-align: top;
}

fieldset {
	border: 0;
}
```

- 기본적인 body와 헤더 태그들의 여백 제거

- ul, ol, dl 여백 및 글머리 기호 제거

- table (border-collapse: seperate가 기본값. 셀 테두리가 분리된다(각 셀 테두리 사이에 여백이 생김). 이런 식으로 디자인 되는 경우는 거의 없기 때문에, collapse로 변경)

- p의 여백, em의 이탈릭체로 되는 폰트 스타일, a는 프로젝트 상황에 맞춰, img는 인라인 요소라 하단에 여백이 생기는데 블록 요소로 바꾸거나 vertical-align: top으로 그 여백을 제거한다.

- form (폼 요소들마다 폰트 사이즈와 폰트 패밀리가 다르다. 프로젝트에 맞게 리셋해주는 것이 좋다.)

<br/>
<br/>

## 느낀점

이때까지 이런 식으로 css를 작성해 볼 생각은 못 해봤다. 이미 다 안다고 생각했지만 전혀 그렇지 않았다.

다음에 CSS를 작성할 땐, 프로젝트에 맞춰 리셋할 부분은 리셋하고 시작해주면, 같은 코드를 작성하는 빈도도 줄어들고, 디자인하기도 수월해질 것 같다.
