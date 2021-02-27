# Playground.C-Lang

## 들어가기전에...

## 철학

### C99 Rationale

 - Trust the programmer
 - Don't prevent the programmer from doing what needs to be done
 - Keep the language small and simple
 - Provide only one way to do an operation
 - Make it fast, even if it is not guaranteed to be portable

여기서 특히 `Trust the programmer` 철학이 오류를 가지고 있는 프로그래머를 가정하고 엄격하게 컴파일하는 다른 언어와 다른 부분

### `C++`은 `C`의 기능을 포함하는가?

 - `C` : 절차 지향 프로그래밍
 - `C++` : 멀티패러다임 프로그래밍(객체+절차)
 - `C`에서는 허용하지만 `C++`에서는 허용하지 않고, `C++`에서는 허용하지만 `C`에서는 허용하지 않는 경우가 존재
 - `C++`는 기본적으로 C를 바탕에두고 `Simual 67`에서 비롯된 클래스의 개념을 도입해 OOP가 가능하도록 고안해낸 것. 그렇기 때문에 언어적 패러다임에는 `C++`이 `C`를 포함한다고 말할 수도 있다.
 - But, 둘은 절대 같은 언어가 아니다. `C++`이 `C`의 일부를 사용할 수 있는 이유는 `C++`가 `C`의 업그레이드 버전 때문이 아니라 멀티패러다임 프로그래밍 때문이고, `C++`를 고안한 뱌니 스트로프스트로웁이 `C++`와 `C`가 겹친 것은 우연이라고 말할 정도.
 - `C` 표준화 위원회는 `C++`와의 통합을 고려하지 않음. 시간이 지날 수록 차이가 커질 것은 자명함.
 - 파리를 잡기위해 기관총을 사용하고 적을 제거하기 위해 파리채를 사용해선 안됨. 두 언어를 서로 다른 언어로 바라보고 처해진 상황과 목적에 따라 전략적으로 언어를 선택해야 하며 모든 것을 처리하는 완벽한 언어는 존재하지 않음
 - 그러므로 `C++`로 Smalltalk와 같이 프로그래밍을 하는 것은 적절하지 않음.

#### Ref : IT 백두대간, C 언어 펀더멘탈

##### 개인적으로 여기서 맘에 든 기본 개념; Correctness, Portability, Readability, Maintainability

<br>
<hr>

## 어떤 개발 환경을 구축해야 될까

### 역사적 관점으로부터의 선택
 - 1970년대 C언어는 유닉스 커널을 C언어로 새로 쓸 수 있을 정도로 강력해졌고 유닉스는 C언어의 전파를 도왔다. 특히 C언어로 작성된 유닉스는 어셈블리어로 작성된 것보다 큰 이식성을 얻게 됨 

 - C의 준 표준이라 할 수 있는 `The C Programming Langauge(Prentice Hall, 1978)`이라는 책이 나오고 Steve Johnson은 C언어와 유닉스를 다른 환경에 옮길 때 어려움이 없도록 `pcc`(portable C compiler)를 만들었다.

 - 각 종류의 컴파일러들이 기존에는 `pcc`를 기반으로 만들어졌으나, 점차 독립적으로 구현되는 컴파일러들이 생기기 시작, 표준화 필요성 대두

 - 1983년, ANSI 산하에 `X3J11`이라는 C 표준화 위원회 조직
   - C89/90 --> 이후 ANSI가 표준 제정에 손놓고 ISO를 받아들임 --> C99, C11, C18

 - 표준화는 표준화일 뿐 표준을 따르면서 각자 독자적인 기능을 추가하는 것으로 보임. 예를 들어, MS사의 Visual C/C++에서 잘 돌아가던 코드가 GCC에서는 오류가 걸리는 현상. 대표적으로 `scanf_s()`는 MS사의 독자적인 함수로 GCC에서는 해석 못함

 - GNU99, GNU11, GNU17은 각각 c99, c11, c17의 표준을 따르는 것으로 보임

 - Boland C++, Visual C++, Clang, GCC 등의 다양한 컴파일러가 있음

 - OS 환경을 크게 Linux, Window, MacOS를 둘 때
    - Linux는 GCC에 특화됨
    - Window는 Visual C++에 특화됨
    - MacOS는 Clang에 특화됨

 - MacOS는 본래 유닉스 계열로 GCC를 사용하고 있었으나, GCC 커뮤니티가 Objective-C 기능 확장을 지지하지 않은 문제가 있어 독자적으로 Apple.Inc를 위한 Clang을 만들어 GCC를 완전히 대채하려고 있음

 - Visual Studio Code라는 IDE를 통해 Window, MacOS 위에 동시 사용하려 하였으나 MacOS에서는 VS Code C++이 지원이 안되므로 제외한다.

 - MacOS의 대표 IDE인 Xcode는 컴파일할 때 GCC를 사용하는 것으로 보임.

 - Window에서도 Minimalist GNU for Window(MinGW-`w32-->w64`)의 지원을 통해 GCC를 사용할 수 있음

 - 가벼운 IDE인 Visual Code를 통해 개발한다면 적격이라고 판단

 - 물론 OS에 상관없이 돌아가는 jetbrain의 CLion이라는 강력한 IDE도 발견하여 추후 사용 의향 있음. 컴파일러는 내장되어 있지 않아 따로 Path를 걸어주어야 한다.

### 결론

 - GCC를 사용하기로 결정. `GCC --> C` || `G++ --> C++`로 컴파일하면 됨

 - Visual Code 혹은 기본 Text Editor를 사용
