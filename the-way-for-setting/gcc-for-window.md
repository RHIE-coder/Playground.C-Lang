# GCC for Window

## 01. Install Mingw-w64 ( GCC for Windows 64 & 32 bits )

### [download link](http://mingw-w64.org/doku.php)
### [Out Of Date](https://sourceforge.net/projects/mingw/)

 - 제일 확실한 것은 Source Forge의 File란에서 `x86_64-win32-seh`를 다운로드하고 압축을 푸는 것이다.

## 02. VS Code

### [Guide](https://code.visualstudio.com/docs/cpp/config-mingw)

## 03. Test

 - test.c

```c
#include <stdio.h>

int main(){

    printf("Hello World");

    return 0;
}
```

 - gcc 실행

```bash
gcc test.c -o test.exe
```

 - test.exe 실행

```bash
test
```