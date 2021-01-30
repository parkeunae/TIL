# IR 기법

## IR

Image Replacement

이미지를 볼 수 없는 사용자에게 적절한 대체 텍스트를 제공하는 것

- 배경 이미지로 처리한 의미 있는 아이콘, 로고
- img 태그의 alt 속성 값으로 표현하기엔 대체 텍스트가 너무 길 때

화면에는 보이지 않아야 할 때, CSS로 숨긴다.

## 요소를 화면에서 숨기는 방법

1. 사용하지 말아야 하는 방법
    - 스크린 리더가 인식하지 못 함

        ```css
        /* opacity: 0;과 같은 효과, 스크린 리더 인식 x */
        visibility: hidden;
        /* 요소가 아예 없는 것으로 인식 */
        display: none;
        /* 스크린 리더가 인식 x */
        width: 0; height: 0; font-size: 0; line-height: 0;
        ```

    - 스크린 리더가 인식하지만 레이아웃, 성능 등 이슈 발생

        ```css
        /* 투명해진 것 뿐, 위치는 그대로 잡고 있기 때문에, 단독으로 사용 불가능 */
        opacity: 0;
        /* 전체 레이아웃의 크기에 영향 -> 성능에도 영향 */
        /* 첫 줄만 밀어주고, 그 밑의 줄엔 영향x */
        text-indent: -9999px;
        /* z-index를 사용하기 위해선 static 외의 다른 position을 써야한다.
        이 때문에 성능 이슈가 생길 수 있다. */
        z-index: -1;
        ```

    - ✨스크린 리더가 인식하면서 레이아웃, 성능에 영향을 미치지 않음

        ```css
        /* 레이아웃에 영향을 끼치지 않도록 */
        position: absolute;

        /* 스크린 리더가 읽을 수 있도록 */
        width: 1px;
        height: 1px;

        /* 눈에 보이는 부분을 제거 */
        clip: rect(0 0 0 0);
        margin: -1px;
        overflow: hidden;
        ```

        clip: rect(top right bottom left)

        position: absolute / fixed인 요소에 사용o

        overflow: visible일 경우 적용 x

    전체적으로 많이 쓰이기 때문에, 클래스로 추가해서 사용한다.
