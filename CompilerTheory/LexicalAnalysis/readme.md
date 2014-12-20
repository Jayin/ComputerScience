C语言词法分析
---

* 识别C语言编源程序中的每个单词符号
* 读取源程序中的注释
* 统计源程序中的语句行数、单词个数和字符个数(回车换行不计入字符个数，空格不计算为单词)
* 检查源程序中存在的错误，并报告错误所在的行列位置。

Usage
---
```shell
$ g++ LexicalAnalysis.cpp - lex
$ lex in.c tokens.txt table.txt //分别指定输入文件，输出token串文件，符号表文件
```

Requirement
---

C++ 11

