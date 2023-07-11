大端序（Big-Endian）和小端序（Little-Endian）是计算机科学中用于描述字节在内存中如何存储的术语。在任何多字节的数据结构（例如，一个 32 位的整数）中，最重要的字节（高位字节）和最不重要的字节（低位字节）可以存储在低地址或高地址。

1. 大端序（Big-Endian）: 也称为网络序，最高有效位（MSB，最重要的字节）放在内存的低位地址，最低有效位（LSB，最不重要的字节）放在内存的高位地址。例如，一个 4 字节整数 `0x12345678` 存储在内存中的形式（从低地址到高地址）为 `12 34 56 78`。

2. 小端序（Little-Endian）: 相反，最低有效位（LSB，最不重要的字节）放在内存的低位地址，最高有效位（MSB，最重要的字节）放在内存的高位地址。同样的例子，`0x12345678` 在小端序中的存储形式为 `78 56 34 12`。

应用场景：

- 大端序在网络通信（TCP/IP协议）中广泛应用，因此也被称为网络字节序。
- 小端序在一些微处理器（如 Intel x86 架构）中被广泛采用。

下面是一段使用C语言编写的代码，用于判断当前处理器的字节序：

```c
#include <stdio.h>

int main() {
    union {
        short int s;
        char c[sizeof(short int)];
    } un;

    un.s = 0x0102;

    if (sizeof(short int) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("Big-Endian\n");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("Little-Endian\n");
        else
            printf("Unknown\n");
    } else {
        printf("sizeof(short int) = %lu\n", sizeof(short int));
    }

    return 0;
}
```
这段代码使用了一个联合体，它可以将同一块内存以不同的类型来访问。如果当前处理器是大端序，`0x0102`的存储形式将是 `01 02`，否则在小端序中为 `02 01`。
