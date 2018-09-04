## 第一章 程序的基本概念



[TOC]



### 1,程序和编程语言

Instruction 指令

Programming Language 编程语言

Low-level Language 低级语言/High-level

Machine Language 机器语言

Assembly Language 汇编语言

Mnemonic 助记符（汇编）

Assembler 汇编器

Compile 编译

Architecture 体系机构

Instruction Set 指令集

Interpret 解释



### 2. 自然语言和形式语言

Natural Language 自然语言

Formal Language 形式语言

Syntax 语法

>  包括 ：Token 符号
>
> 	      Structure 结构

Lexical 词法

> 关于 Token

Grammar 语法

> 关于 Structure

Parse 解析

Context 上下文

Semantic 语义

Ambiguity 歧义性

Redundancy 冗余性

Metaphor 隐喻

Literal 字面

###3/4.程序的调试/第一个程序

gcc xxx.c -o nameuwant.xxx

boilerplate 样板文件

semicolon ;号/分号

brace/curly brace  {}/大括号/花括号

indent 缩进

blank 空格

single quote/apostrophe 单引号

double quote 双引号

string literal 字符串字面值

escape sequence 转义序列

line feed 换行符

\? question mark 

\a alert/bell

\b backspace

\f form feed 分页符

\n line feed 换行

\r carriage return 回车

\t horizontal tab 水平制表符 

\v vertical tab 垂直制表符





## 第二章 常量 变量 表达式



### 1.常量

> - conversion specification 转换说明
> - placeholder 占位符

#####单引号使用

注意单引号只能括一个字符而不能像双引号那样括一串字符，字符常量也可以是一个转义序列，例如`'\n'`，这时虽然单引号括了两个字符，但实际上只表示一个字符。

##### *转义序列是编译时处理的，而转换说明是在运行时调用printf函数处理的*。

> 转义序列 ： /n /t /f /b 
>
> 转换说明： %c %d %f

源文件中的字符串字面值是`"character: %c\ninteger: %d\nfloating point: %f\n"`，`\n`占两个字符，而编译之后保存在可执行文件中的字符串是`character： %c换行integer: %d换行floating point: %f换行`，`\n`已经被替换成一个换行符，而`%c`不变，然后在运行时这个字符串被传给`printf`，`printf`再把其中的`%c`、`%d`、`%f`解释成转换说明。

有时候不同类型的数据很容易弄混，例如`"5"`、`'5'`、`5`，如果你注意了它们的界定符就会很清楚，第一个是字符串字面值，第二个是字符，第三个是整数。



### 2.变量

> - declaration 声明
>
> - **underscore** 下划线
>
> - identifier 标识符
>
>   >  变量名、函数名、宏定义、结构体成员名等

##### 声明和定义

> C语言中的声明（Declaration）有变量声明、函数声明和类型声明三种。如果一个变量或函数的声明要求编译器为它分配存储空间，那么也可以称为定义（Definition），因此定义是声明的一种。



### 3.赋值

> - assignment 赋值
> - initialization 初始化

``` c
char firstletter;
int hour, minute;
firstletter = 'a';   /* give firstletter the value 'a' */
hour = 11;           /* assign the value 11 to hour */
minute = 59;         /* set minute to 59 */
```

变量的初始化 = 变量的定义 + 赋值

``` c
char firstletter = 'a';
int hour = 11, minute = 59;
```

在初始化语句中，等号右边的值叫做Initializer，例如上面的`'a'`、11和59。注意，*初始化是一种特殊的声明，而不是一种赋值语句*。



### 4.表达式

> - operand 操作数
> - expression 表达式
> - precedence 优先级
> - parenthesis ()括号/原括号
> - associativity 结合性
> - composition 组合
> - lvalue/rvalue 左值/右值



```
向下取整的运算称为Floor，用数学符号⌊⌋表示；向上取整的运算称为Ceiling，用数学符号⌈⌉表示。例如：

⌊59/60⌋=0
⌈59/60⌉=1
⌊-59/60⌋=-1
⌈-59/60⌉=0

```

在C语言中整数除法取的既不是Floor也不是Ceiling，无论操作数是正是负总是把小数部分截掉，在数轴上向零的方向取整（Truncate toward Zero），或者说当操作数为正的时候相当于Floor，当操作符为负的时候相当于Ceiling。



### 5.字符类型与字符编码

> - ascii 
>
>   > 0 ---- 48
>   >
>   > A ---- 65
>   >
>   > a ---- 97
>
> - 

##### *以后我们把char型和int型统称为整数类型（Integer Type）或简称整型*



## 第三章 简单函数

### 1.数学函数

> - **argument** 参数!!
> - function call 函数调用
> - function designator 函数名
> - function type 函数类型
> - side effect 打印
> - generalize 泛化
> - pound sign/number sign/hash sign  #号
> - angel bracket 尖括号

``` 
在C语言的术语中，1.0是参数（Argument），log是函数（Function），log(1.0)是函数调用（Function Call）。sin(pi/2)和log(1.0)这两个函数调用在我们的printf语句中处于什么位置呢？在上一章讲过，这应该是写表达式的位置。因此函数调用也是一种表达式，这个表达式由函数调用运算符（()括号）和两个操作数组成，操作数log是一个函数名（Function Designator），它的类型是一种函数类型（Function Type），操作数1.0是double型的。log(1.0)这个表达式的值就是对数运算的结果，也是double型的，在C语言中函数调用表达式的值称为函数的返回值（Return Value）
```

- 头文件一般位于 /usr/include 目录下
- 使用math.h时 gcc命令必须加 -lm 选项,因为数学函数位于`libm.so`库文件中（这些库文件通常位于`/lib`目录下），`-lm`选项告诉编译器，我们程序中用到的数学函数要到这个库文件里找。



### 2.自定义函数

> - prototype 原型
> - implicit declaration 隐式声明

`main`调用`threeline`，`threeline`再调用`newline`，要保证每个函数的原型出现在调用之前，就只能按先`newline`再`threeline`再`main`的顺序定义了。



### 3.形参和实参

> - rule of least surprise 例外原则
> - rationale 原因
> - parameter 形参
> - argument 实参
> - variable argument 可变参数
> - hierarchy 层级

定义参数不能并列定义: void pttime(int hour,time)  ------**x**

*形参相当于函数中定义的变量，调用函数传递参数的过程相当于定义形参变量并且用实参的值来初始化*。



#####Man Page

```
Man Page
Man Page是Linux开发最常用的参考手册，由很多页面组成，每个页面描述一个主题，这些页面被组织成若干个Section。FHS（Filesystem Hierarchy Standard）标准规定了Man Page各Section的含义如下：

表 3.1. Man Page的Section

Section	描述
1	用户命令，例如ls(1)
2	系统调用，例如_exit(2)
3	库函数，例如printf(3)
4	特殊文件，例如null(4)描述了设备文件/dev/null、/dev/zero的作用
5	系统配置文件的格式，例如passwd(5)描述了系统配置文件/etc/passwd的格式
6	游戏
7	其它杂项，例如bash-builtins(7)描述了bash的各种内建命令
8	系统管理命令，例如ifconfig(8)

注意区分用户命令和系统管理命令，用户命令通常位于/bin和/usr/bin目录，系统管理命令通常位于/sbin和/usr/sbin目录，一般用户可以执行用户命令，而执行系统管理命令经常需要root权限。系统调用和库函数的区别将在第 2 节 “main函数和启动例程”说明。

Man Page中有些页面有重名，比如敲man printf命令看到的并不是C函数printf，而是位于第1个Section的系统命令printf，要查看位于第3个Section的printf函数应该敲man 3 printf，也可以敲man -k printf命令搜索哪些页面的主题包含printf关键字。本书会经常出现类似printf(3)这样的写法，括号中的3表示Man Page的第3个Section，或者表示“我这里想说的是printf库函数而不是printf命令”。
```



### 4.全局变量 局部变量 作用域

> - local variable 局部变量
> - global variable 全局变量
> - constant expression 常量表达式
> - neccessary condition 必要条件
> - sufficient condition 充分条件



*局部变量可以用类型相符的任意表达式来初始化，而全局变量只能用常量表达式（Constant Expression）初始化*。

例如,全局变量`pi`这样初始化是合法的：

```
double pi = 3.14 + 0.0016;
```

但这样初始化是不合法的：

```
double pi = acos(-1.0);
```

> 是初始化而不是赋值!

写非定义的函数声明时参数可以只写类型而不起名，例如上面代码中的`void print_time(int, int);`，只要告诉编译器参数类型是什么



## 第四章 分支语句

### 1.if语句

> - selection statement 分支语句
>
> - contolling expression 控制表达式
>
> - control flow 控制流程
>
> - branch 分支
>
> - equality operator 相等性运算符
>
>   > == !=
>
> - relational operatro 关系运算符
>
>   > \> \>= < <=
>
> - 

True =1/非0值

False = 0

相等性运算符优先级低于关系运算符.

##### 注意语句块的}后面不需要加;号。如果}后面加了;号，则这个;号本身又是一条新的语句了，在C语言中一个单独的;号表示一条空语句（Null Statement）。



### 2.if/else 语句

> - clause 子句
>
> - modulo 取模
>
>   > %运算
>
> - remainder 余数
>
> - parity 奇偶性
>
> - odd/even 奇/偶数
>
> - encapsulate 封装
>
> - 



C语言规定%运算符的两个操作数必须是整型的。

*%运算符的结果总是与被除数同号*

####C语言规定，*else总是和它上面最近的一个if配对*



### 3.布尔代数

> logical AND 逻辑与
>
> logical OR 逻辑或
>
> pipe sign |线
>
> logical NOT 逻辑非
>
> exclamation mark !号
>
> ampersand &号
>
> truth table 真值表
>
> unary operator 单目运算符
>
> > !
>
> binary operator 双目运算符
>
> > \+ \- \* / && || !
>
> boolean algebra 布尔代数
>
> 

 !高于* / %，高于+ -，高于> < >= <=，高于== !=，高于&&，高于||，高于=



### 4.switch语句

> - 

`case`后面跟表达式的必须是常量表达式，这个值和全局变量的初始值一样必须在编译时计算出来。

C语言规定`case`后面跟的必须是整型常量表达式。

#### 进入`case`后如果没有遇到`break`语句就会一直往下执行，后面其它`case`或`default`分支的语句也会被执行到，直到遇到`break`，或者执行到整个`switch`语句块的末尾。

> 利用此规则时，default是否执行跟所在位置和有关





## 第五章 深入理解函数



### 1.return语句

> - predicate 谓词
> - code path 代码路径

比较的两边应该是同类型的数



### 2.增量式开发

> - Incremental 增量式
> - radius 半径/area 面积
> - Scaffold 脚手架
> - *Reuse* 复用
> - Stratify  分层；成层；阶层化



### 3.递归

> - recursive 递归
>
> - factorial 阶乘
>
> - base case 基础条件
>
> - stack frame 栈帧
>
> - leap of faith 
>
>   > w. 信仰之跃; 天降神迹; 信心的跳跃; 从梦境回到现实的信念; 
>
> - leap 跳跃
>
> - mathematical induction 数学归纳法、
>
> - infinite recursion 无穷递归
>
> - greatest common divisor 最大公约数 GCD

*写递归函数时一定要记得写Base Case*，否则即使递推关系正确，整个函数也不正确。

exercise: 1. euclid.c/gcd   

		2.fibonacci.c



## 第六章 循环语句



### 1.while

> - iteration 迭代
> - accumulator 累加器
> - functional programming 函数式编程
> - imperative programming 命令式编程

exercise: while_fiboxxxxx.c while_eculid.c



### 2. do/while

### 3.for

> - Prefix/Postfix Increment Operator 前缀/后缀自增运算符
>
> - Prefix/Postfix Decrement Operatro 前缀/后缀自减运算符
>
> - transition
>
>   > n. 过渡；转变；[分子生物] 转换；变调

C语言规定，如果控制表达式2为空，则认为控制表达式2的值为真，因此死循环也可以写成`for (;;) {...}`。



### 4.break&continue

> - 

##### 对于`while`循环和`do/while`循环，执行`continue`语句之后测试控制表达式，如果值为真则继续执行下一次循环；对于`for`循环，执行`continue`语句之后首先计算控制表达式3，然后测试控制表达式2，如果值为真则继续执行下一次循环。



### 5.嵌套循环

> - exercise  diamond.c/diamond



### 6.goto语句和标号

> - lable 标号
>
> - colon 冒号,:号
>
> - duff 
>
>   > n. 水果布丁；揉好的面团；笨拙的人
>   >
>   > vt. 把…改头换面；虚饰以欺骗人
>   >
>   > n. (Duff)人名；(英)达夫；(法)迪夫

这里的`error:`叫做标号（Label），任何语句前面都可以加若干个标号，每个标号的命名也要遵循标识符的命名规则。

`goto`语句过于强大了，从程序中的任何地方都可以无条件跳转到任何其它地方，只要在那个地方定义一个标号就行，唯一的限制是`goto`只能跳转到同一个函数中的某个标号处，而不能跳到别的函数中[[11](https://akaedu.github.io/book/ch06s06.html#ftn.id2727782)]。*滥用goto语句会使程序的控制流程非常复杂，可读性很差*。

有些编程语言（如C++）中有异常（Exception）处理的语法，可以代替`goto`和`setjmp/longjmp`的这种用法。



## 第七章 结构体

### 1.复合类型与结构体

> - Primitive Type 基本类型
>
>   > 最基本的、不可再分的数据类型
>
> - Compound Type 复合类型
>
>   > 根据语法规则由基本类型组合而成的类型
>
> - Data Abstraction 数据抽象
>
> - Procedure Abstraction 过程抽象
>
> - period  .点,句点,句号
>
> - sparse 稀疏
>
> - memberwise initialization 成员初始化
>
> - arithmetic type 算数类型
>
> - scalar type 标量类型
>
>



##### 类型定义也是一种声明，声明都要以;号结尾，结构体类型定义的}后面少;号是初学者常犯的错误。

不管是用上面两种形式的哪一种定义了`complex_struct`这个Tag，以后都可以直接用`struct complex_struct`来代替类型名了。例如可以这样定义另外两个复数变量：

```
struct complex_struct z3, z4;
```

如果在定义结构体类型的同时定义了变量，也可以不必写Tag，例如：

```
struct {
	double x, y;
} z1, z2;
```

但这样就没办法再次引用这个结构体类型了，因为它没有名字。

注意，必须是局部变量才能用另一个变量`x`的值来**初始化**它的成员，如果是全局变量就只能用常量表达式来初始化。

{}这种语法不能用于结构体的**赋值**，例如这样是错误的：

```
struct complex_struct z1;
z1 = { 3.0, 4.0 };
```

Designated Initializer是C99引入的新特性，用于初始化稀疏（Sparse）结构体和稀疏数组很方便。有些时候结构体或数组中只有某一个或某几个成员需要初始化，其它成员都用0初始化即可，用Designated Initializer语法可以针对每个成员做初始化（Memberwise Initialization），很方便。例如：

```
struct complex_struct z1 = { .y = 4.0 }; 
/* z1.x=0.0, z1.y=4.0 */
```



### 2.数据抽象

> - magnitude  n. 大小；量级；[地震] 震级；重要；光度
> - Abstraction Layer 抽象层
> - 

exercise:rational_num.c / rrational



### 3.数据类型标志

> - enumeration 枚举
> - 

枚举类型的成员是常量，它们的值由编译器自动分配，例如定义了上面的枚举类型之后，`RECTANGULAR`就表示常量0，`POLAR`表示常量1。如果不希望从0开始分配，可以这样定义：

```
enum coordinate_type { RECTANGULAR = 1, POLAR };
```

这样，`RECTANGULAR`就表示常量1，而`POLAR`表示常量2。枚举常量也是一种整型，其值在编译时确定，因此也可以出现在常量表达式中，可以用于初始化全局变量或者作为`case`分支的判断条件。



### 4.嵌套结构体

嵌套结构体可以嵌套地初始化，例如：

```
struct segment s = {{ 1.0, 2.0 }, { 4.0, 6.0 }};
```

也可以平坦（Flat）地初始化。例如：

```
struct segment s = { 1.0, 2.0, 4.0, 6.0 };
```

甚至可以把两种方式混合使用（这样可读性很差，应该避免）：

```
struct segment s = {{ 1.0, 2.0 }, 4.0, 6.0 };
```

利用C99的新特性也可以做Memberwise Initialization，例如[[15](https://akaedu.github.io/book/ch07s04.html#ftn.id2731613)]：

```
struct segment s = { .start.x = 1.0, .end.x = 2.0 };
```

访问嵌套结构体的成员要用到多个.运算符，例如：

```
s.start.t = RECTANGULAR;
s.start.a = 1.0;
s.start.b = 2.0;
```



## 第八章 数组

### 1.数组的基本概念

> - array 数组
> - element 元素
> - zeroth 零的,从零开始的
> - traversal 遍历
> - 

后缀++、后缀--、结构体取成员.、数组取下标[]、函数调用()。还学习了五种单目运算符（或者叫前缀运算符）：前缀++、前缀--、正号+、负号-、逻辑非!。在C语言中后缀运算符的优先级最高，单目运算符的优先级仅次于后缀运算符，比其它运算符的优先级都高，所以上面举例的`++count[2]`应该看作对`count[2]`做前缀++运算。



数组也可以像结构体一样初始化，未赋初值的元素也是用0来初始化，例如：

```
int count[4] = { 3, 2, };
```

则`count[0]`等于3， `count[1]`等于2，后面两个元素等于0。如果定义数组的同时初始化它，也可以不指定数组的长度，例如：

```
int count[] = { 3, 2, 1, };
```

编译器会根据Initializer有三个元素确定数组的长度为3。利用C99的新特性也可以做Memberwise Initialization：

```
int count[4] = { [2] = 3 };
```

*不能用数组类型作为函数的参数或返回值*



### 2.数组应用实例：统计随机数

> - Pseudorandom 伪随机
> - Uniform Distribution 均匀分布
> - macro 宏
> - Hard coding 硬编码
> - 

用`cpp main.c`命令也可以达到同样的效果，只做预处理而不编译，`cpp`表示C preprocessor。

[\t的使用方法]:https://akaedu.github.io/book/ch08s02.html

#### exercise: 

> 1、用rand函数生成10~20之间的随机整数，表达式应该怎么写？

rand()%11 + 10



### 3.数组应用实例：直方图

> - histogaram 直方图
> - 



### 4.字符串

> - Null-terminated String 以零结尾的字符串
> - 

数组元素可以通过数组名加下标的方式访问，而字符串字面值也可以像数组名一样使用，可以加下标访问其中的字符：

```
char c = "Hello, world.\n"[0];
```

但是通过下标修改其中的字符却是不允许的：

```
"Hello, world.\n"[0] = 'A';
```

这行代码会产生编译错误，说字符串字面值是只读的，不允许修改。



如果用于初始化的字符串字面值比数组还长，比如：

```
char str[10] = "Hello, world.\n";
```

则数组`str`只包含字符串的前10个字符，不包含Null字符，这种情况编译器会给出警告。如果要用一个字符串字面值准确地初始化一个字符数组，**最好的办法是不指定数组的长度，让编译器自己计算：**

```
char str[] = "Hello, world.\n";
```

 printf("string: %s\n", str);

`printf`会从数组`str`的开头一直打印到Null字符为止，Null字符本身是Non-printable字符，不打印。这其实是一个危险的信号：如果数组`str`中没有Null字符，那么`printf`函数就会访问数组越界，后果可能会很诡异：有时候打印出乱码，有时候看起来没错误，有时候引起程序崩溃。



### 5.多维数组

> - Multi-dimensional Array 多维数组
> - Data-driven Programming 数据驱动编程

C语言多维数组存储方式 Row-major

FORTRAN 存储方式 Column-major





## 第九章 编码风格

> Thus, programs must be written for people to read, and only incidentally for machines to execute.
>
> incidentally   /adv. 顺便；偶然地；附带地
>
> rationale 基本原理



### 1.缩进和空白

>

1. 关键字`if`、`while`、`for`与其后的控制表达式的(括号之间插入一个空格分隔，但括号内的表达式应紧贴括号。

   例如：

   ```
   while␣(1);
   ```

2. 双目运算符的两侧各插入一个空格分隔，单目运算符和操作数之间不加空格，例如`i␣=␣i␣+␣1`、`++i`、`!(i␣<␣1)`、`-x`、`&a[1]`等。

3. 后缀运算符和操作数之间也不加空格，例如取结构体成员`s.a`、函数调用`foo(arg1)`、取数组成员`a[i]`。 

4. ,号和;号之后要加空格，这是英文的书写习惯，例如`for␣(i␣=␣1;␣i␣<␣10;␣i++)`、`foo(arg1,␣arg2)`。

5. 以上关于双目运算符和后缀运算符的规则并没有严格要求，有时候为了突出优先级也可以写得更紧凑一些，例如`for␣(i=1;␣i<10;␣i++)`、`distance␣=␣sqrt(x*x␣+␣y*y)`等。但是省略的空格一定不要误导了读代码的人，例如`a||b␣&&␣c`很容易让人理解成错误的优先级。

6. 由于UNIX系统标准的字符终端是24行80列的，接近或大于80个字符的较长语句要折行写，折行后用空格和上面的表达式或参数对齐，例如：

   ```
   if␣(sqrt(x*x␣+␣y*y)␣>␣5.0
       &&␣x␣<␣0.0
       &&␣y␣>␣0.0)
   ```

   再比如：

   ```
   foo(sqrt(x*x␣+␣y*y),
       a[i-1]␣+␣b[i-1]␣+␣c[i-1])
   ```

7. 较长的字符串可以断成多个字符串然后分行书写，例如：

   ```
   printf("This is such a long sentence that "
          "it cannot be held within a line\n");
   ```

   C编译器会自动把相邻的多个字符串接在一起，以上两个字符串相当于一个字符串`"This is such a long sentence that it cannot be held within a line\n"`。

8. 有的人喜欢在变量定义语句中用Tab字符，使变量名对齐，这样看起来很美观。

   ```
          →int    →a, b;
          →double →c;
   ```


内核代码风格关于缩进的规则有以下几条:

1. 要用缩进体现出语句块的层次关系，使用Tab字符缩进，不能用空格代替Tab。在标准的字符终端上一个Tab看起来是8个空格的宽度，如果你的文本编辑器可以设置Tab的显示宽度是几个空格，建议也设成8，这样大的缩进使代码看起来非常清晰。如果有的行用空格做缩进，有的行用Tab做缩进，甚至空格和Tab混用，那么一旦改变了文本编辑器的Tab显示宽度就会看起来非常混乱，所以内核代码风格规定只能用Tab做缩进，不能用空格代替Tab。 

2. `if/else`、`while`、`do/while`、`for`、`switch`这些可以带语句块的语句，语句块的{或}应该和关键字写在同一行，用空格隔开，而不是单独占一行。例如应该这样写：

   ```
   if␣(...)␣{
          →语句列表
   }␣else␣if␣(...)␣{
          →语句列表
   }
   ```

   但很多人习惯这样写：

   ```
   if␣(...)
   {
          →语句列表
   }
   else␣if␣(...)
   {
          →语句列表
   }
   ```

   内核的写法和[[K&R\]](https://akaedu.github.io/book/bi01.html#bibli.kr)一致，好处是不必占太多行，使得一屏能显示更多代码。这两种写法用得都很广泛，只要在同一个项目中能保持统一就可以了。

3.  函数定义的{和}单独占一行，这一点和语句块的规定不同，例如：

   ```c
   int␣foo(int␣a,␣int␣b)
   {
          →语句列表
   }
   ```

4. `switch`和语句块里的`case`、`default`对齐写，也就是说语句块里的`case`、`default`标号相对于`switch`不往里缩进，但标号下的语句要往里缩进。例如：

   ```c
         →switch␣(c)␣{
         →case 'A':
         →       →语句列表
         →case 'B':
         →       →语句列表
         →default:
         →       →语句列表
         →}
   ```

   用于`goto`语句的自定义标号应该顶头写不缩进，而不管标号下的语句缩进到第几层。 

5.  代码中每个逻辑段落之间应该用一个空行分隔开。例如每个函数定义之间应该插入一个空行，头文件、全局变量定义和函数定义之间也应该插入空行，例如：

   ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   int g;
   double h;
   
   int foo(void)
   {
          →语句列表
   }
   
   int bar(int a)
   {
          →语句列表
   }
   
   int main(void)
   {
          →语句列表
   }
   ```

6.  一个函数的语句列表如果很长，也可以根据相关性分成若干组，用空行分隔。这条规定不是严格要求，通常把变量定义组成一组，后面加空行，`return`语句之前加空行，例如：

   ```c
   int main(void)
   {
          →int    →a, b;
          →double →c;
   
          →语句组1
   
          →语句组2
   
          →return 0;
   }
   ```



### 2.注释

>

单行注释应采用`/*␣comment␣*/`的形式，用空格把界定符和文字分开。多行注释最常见的是这种形式：

```c
/*
␣*␣Multi-line
␣*␣comment
␣*/
```

也有更花哨的形式：

```c
/*************\
* Multi-line  *
* comment     *
\*************/
```

使用注释的场合主要有以下几种:

1. 整个源文件的顶部注释。说明此模块的相关信息，例如文件名、作者和版本历史等，顶头写不缩进。例如内核源代码目录下的`kernel/sched.c`文件的开头：

   ```c
   /*
    *  kernel/sched.c
    *
    *  Kernel scheduler and related syscalls
    *
    *  Copyright (C) 1991-2002  Linus Torvalds
    *
    *  1996-12-23  Modified by Dave Grothe to fix bugs in semaphores and
    *              make semaphores SMP safe
    *  1998-11-19  Implemented schedule_timeout() and related stuff
    *              by Andrea Arcangeli
    *  2002-01-04  New ultra-scalable O(1) scheduler by Ingo Molnar:
    *              hybrid priority-list and round-robin design with
    *              an array-switch method of distributing timeslices
    *              and per-CPU runqueues.  Cleanups and useful suggestions
    *              by Davide Libenzi, preemptible kernel bits by Robert Love.
    *  2003-09-03  Interactivity tuning by Con Kolivas.
    *  2004-04-02  Scheduler domains code by Nick Piggin
    */
   ```

2. 函数注释。说明此函数的功能、参数、返回值、错误码等，写在函数定义上侧，和此函数定义之间不留空行，顶头写不缩进。 

3.  相对独立的语句组注释。对这一组语句做特别说明，写在语句组上侧，和此语句组之间不留空行，与当前语句组的缩进一致。

4.  代码行右侧的简短注释。对当前代码行做特别说明，一般为单行注释，和代码之间至少用一个空格隔开，一个源文件中所有的右侧注释最好能上下对齐。内核源代码目录下的`lib/radix-tree.c`文件中的一个函数包含了上述三种注释：

   ```c
   /**
    *      radix_tree_insert    -    insert into a radix tree
    *      @root:          radix tree root
    *      @index:         index key
    *      @item:          item to insert
    *
    *      Insert an item into the radix tree at position @index.
    */
   int radix_tree_insert(struct radix_tree_root *root,
                           unsigned long index, void *item)
   {
           struct radix_tree_node *node = NULL, *slot;
           unsigned int height, shift;
           int offset;
           int error;
   
           /* Make sure the tree is high enough.  */
           if ((!index && !root->rnode) ||
                           index > radix_tree_maxindex(root->height)) {
                   error = radix_tree_extend(root, index);
                   if (error)
                           return error;
           }
   
           slot = root->rnode;
           height = root->height;
           shift = (height-1) * RADIX_TREE_MAP_SHIFT;
   
           offset = 0;                     /* uninitialised var warning */
           do {
                   if (slot == NULL) {
                           /* Have to add a child node.  */
                           if (!(slot = radix_tree_node_alloc(root)))
                                   return -ENOMEM;
                           if (node) {
                                   node->slots[offset] = slot;
                                   node->count++;
                           } else
                                   root->rnode = slot;
                   }
   
                   /* Go a level down */
                   offset = (index >> shift) & RADIX_TREE_MAP_MASK;
                   node = slot;
                   slot = node->slots[offset];
                   shift -= RADIX_TREE_MAP_SHIFT;
                   height--;
           } while (height > 0);
   
           if (slot != NULL)
                   return -EEXIST;
   
           BUG_ON(!node);
           node->count++;
           node->slots[offset] = item;
           BUG_ON(tag_get(node, 0, offset));
           BUG_ON(tag_get(node, 1, offset));
   
           return 0;
   }
   ```

   [[CodingStyle\]](https://akaedu.github.io/book/bi01.html#bibli.codingstyle)中特别指出，函数内的注释要尽可能少用。写注释主要是为了说明你的代码“能做什么”（比如函数接口定义），而不是为了说明“怎样做”，只要代码写得足够清晰，“怎样做”是一目了然的，如果你需要用注释才能解释清楚，那就表示你的代码可读性很差，除非是特别需要提醒注意的地方才使用函数内注释。

5.  复杂的结构体定义比函数更需要注释。例如内核源代码目录下的`kernel/sched.c`文件中定义了这样一个结构体：

   ```c
   /*
    * This is the main, per-CPU runqueue data structure.
    *
    * Locking rule: those places that want to lock multiple runqueues
    * (such as the load balancing or the thread migration code), lock
    * acquire operations must be ordered by ascending &runqueue.
    */
   struct runqueue {
           spinlock_t lock;
   
           /*
            * nr_running and cpu_load should be in the same cacheline because
            * remote CPUs use both these fields when doing load calculation.
            */
           unsigned long nr_running;
   #ifdef CONFIG_SMP
           unsigned long cpu_load[3];
   #endif
           unsigned long long nr_switches;
   
           /*
            * This is part of a global counter where only the total sum
            * over all CPUs matters. A task can increase this counter on
            * one CPU and if it got migrated afterwards it may decrease
            * it on another CPU. Always updated under the runqueue lock:
            */
           unsigned long nr_uninterruptible;
   
           unsigned long expired_timestamp;
           unsigned long long timestamp_last_tick;
           task_t *curr, *idle;
           struct mm_struct *prev_mm;
           prio_array_t *active, *expired, arrays[2];
           int best_expired_prio;
           atomic_t nr_iowait;
   
   #ifdef CONFIG_SMP
           struct sched_domain *sd;
   
           /* For active balancing */
           int active_balance;
           int push_cpu;
   
           task_t *migration_thread;
           struct list_head migration_queue;
           int cpu;
   #endif
   
   #ifdef CONFIG_SCHEDSTATS
           /* latency stats */
           struct sched_info rq_sched_info;
   
           /* sys_sched_yield() stats */
           unsigned long yld_exp_empty;
           unsigned long yld_act_empty;
           unsigned long yld_both_empty;
           unsigned long yld_cnt;
   
           /* schedule() stats */
           unsigned long sched_switch;
           unsigned long sched_cnt;
           unsigned long sched_goidle;
   
           /* try_to_wake_up() stats */
           unsigned long ttwu_cnt;
           unsigned long ttwu_local;
   #endif
   };
   ```

6.  复杂的宏定义和变量声明也需要注释。例如内核源代码目录下的`include/linux/jiffies.h`文件中的定义：

   ```c
   /* TICK_USEC_TO_NSEC is the time between ticks in nsec assuming real ACTHZ and  */
   /* a value TUSEC for TICK_USEC (can be set bij adjtimex)                */
   #define TICK_USEC_TO_NSEC(TUSEC) (SH_DIV (TUSEC * USER_HZ * 1000, ACTHZ, 8))
   
   /* some arch's have a small-data section that can be accessed register-relative
    * but that can only take up to, say, 4-byte variables. jiffies being part of
    * an 8-byte variable may not be correctly accessed unless we force the issue
    */
   #define __jiffy_data  __attribute__((section(".data")))
   
   /*
    * The 64-bit value is not volatile - you MUST NOT read it
    * without sampling the sequence number in xtime_lock.
    * get_jiffies_64() will do this for you as appropriate.
    */
   extern u64 __jiffy_data jiffies_64;
   extern unsigned long volatile __jiffy_data jiffies;
   ```



### 3.标识符命名

>

1. 标识符命名要清晰明了，可以使用完整的单词和易于理解的缩写。短的单词可以通过去元音形成缩写，较长的单词可以取单词的头几个字母形成缩写。看别人的代码看多了就可以总结出一些缩写惯例，例如`count`写成`cnt`，`block`写成`blk`，`length`写成`len`，`window`写成`win`，`message`写成`msg`，`number`写成`nr`，`temporary`可以写成`temp`，也可以进一步写成`tmp`，最有意思的是`internationalization`写成`i18n`，词根`trans`经常缩写成`x`，例如`transmit`写成`xmt`。我就不多举例了，请读者在看代码时自己注意总结和积累。

2.  内核编码风格规定变量、函数和类型采用全小写加下划线的方式命名，常量（比如宏定义和枚举常量）采用全大写加下划线的方式命名，比如上一节举例的函数名`radix_tree_insert`、类型名`struct radix_tree_root`、常量名`RADIX_TREE_MAP_SHIFT`等。

   微软发明了一种变量命名法叫匈牙利命名法（Hungarian notation），在变量名中用前缀表示类型，例如`iCnt`（i表示int）、`pMsg`（p表示pointer）、`lpszText`（lpsz表示long pointer to a zero-ended string）等。Linus在[[CodingStyle\]](https://akaedu.github.io/book/bi01.html#bibli.codingstyle)中毫不客气地讽刺了这种写法：“Encoding the type of a function into the name (so-called Hungarian notation) is brain damaged - the compiler knows the types anyway and can check those, and it only confuses the programmer. No wonder MicroSoft makes buggy programs.”代码风格本来就是一个很有争议的问题，如果你接受本章介绍的内核编码风格（也是本书所有范例代码的风格），就不要使用大小写混合的变量命名方式[[19](https://akaedu.github.io/book/ch09s03.html#ftn.id2738703)]，更不要使用匈牙利命名法。



### 4.函数

>

每个函数都应该设计得尽可能简单，简单的函数才容易维护。应遵循以下原则：

1. 实现一个函数只是为了做好一件事情，不要把函数设计成用途广泛、面面俱到的，这样的函数肯定会超长，而且往往不可重用，维护困难。
2. 函数内部的缩进层次不宜过多，一般以少于4层为宜。如果缩进层次太多就说明设计得太复杂了，应考虑分割成更小的函数（Helper Function）来调用。
3. 函数不要写得太长，建议在24行的标准终端上不超过两屏，太长会造成阅读困难，如果一个函数超过两屏就应该考虑分割函数了。[[CodingStyle\]](https://akaedu.github.io/book/bi01.html#bibli.codingstyle)中特别说明，如果一个函数在概念上是简单的，只是长度很长，这倒没关系。例如函数由一个大的`switch`组成，其中有非常多的`case`，这是可以的，因为各`case`分支互不影响，整个函数的复杂度只等于其中一个`case`的复杂度，这种情况很常见，例如TCP协议的状态机实现。
4. 执行函数就是执行一个动作，函数名通常应包含动词，例如`get_current`、`radix_tree_insert`。
5. 比较重要的函数定义上侧必须加注释，说明此函数的功能、参数、返回值、错误码等。
6. 另一种度量函数复杂度的办法是看有多少个局部变量，5到10个局部变量已经很多了，再多就很难维护了，应该考虑分割成多个函数。



### 5.indent工具

>

`$ indent -kr -i8 main.c`





## 第十章 gdb

>

### 1.单步执行和跟踪函数调用

>

[link](https://akaedu.github.io/book/ch10s01.html)

**gdb基本命令1**

| 命令                | 描述                                                   |
| ------------------- | ------------------------------------------------------ |
| backtrace（或bt）   | 查看各级函数调用及参数                                 |
| finish              | 连续运行到当前函数返回为止，然后停下来等待命令         |
| frame（或f） 帧编号 | 选择栈帧                                               |
| info（或i） locals  | 查看当前栈帧局部变量的值                               |
| list（或l）         | 列出源代码，接着上次的位置往下列，每次列10行           |
| list 行号           | 列出从第几行开始的源代码                               |
| list 函数名         | 列出某个函数的源代码                                   |
| next（或n）         | 执行下一行语句                                         |
| print（或p）        | 打印表达式的值，通过表达式可以修改变量的值或者调用函数 |
| quit（或q）         | 退出`gdb`调试环境                                      |
| set var             | 修改变量的值                                           |
| start               | 开始执行程序，停在`main`函数第一行语句前面等待命令     |
| step（或s）         | 执行下一行语句，如果有函数调用则进入到函数中           |



### 2.断点

>

| 命令                       | 描述                                     |
| -------------------------- | ---------------------------------------- |
| break（或b） 行号          | 在某一行设置断点                         |
| break 函数名               | 在某个函数开头设置断点                   |
| break ... if ...           | 设置条件断点                             |
| continue（或c）            | 从当前位置开始连续运行程序               |
| delete breakpoints 断点号  | 删除断点                                 |
| display 变量名             | 跟踪查看某个变量，每次停下来都显示它的值 |
| disable breakpoints 断点号 | 禁用断点                                 |
| enable 断点号              | 启用断点                                 |
| info（或i） breakpoints    | 查看当前设置了哪些断点                   |
| run（或r）                 | 从头开始连续运行程序                     |
| undisplay 跟踪显示号       | 取消跟踪显示                             |



### 3.观察点

> watchpoint 观察点

断点是当程序执行到某一代码行时中断，而观察点是当程序访问某个存储单元时中断，如果我们不知道某个存储单元是在哪里被改动的，这时候观察点尤其有用。

| 命令                    | 描述                                                         |
| ----------------------- | ------------------------------------------------------------ |
| watch                   | 设置观察点                                                   |
| info（或i） watchpoints | 查看当前设置了哪些观察点                                     |
| x                       | 从某个位置开始打印存储单元的内容，全部当成字节来看，而不区分哪个字节属于哪个变量 |



### 4.段错误

>

*如果某个函数的局部变量发生访问越界，有可能并不立即产生段错误，而是在函数返回时产生段错误*。





## 第十一章 排序与查找



### 1.算法的概念

> 是将一组输入转化成一组输出的一系列计算步骤，其中每个步骤必须能在有限时间内完成。

> algorithm 算法
>
>

算法是用来解决一类计算问题的，注意是一类问题，而不是一个特定的问题。由于算法是用来解决一类问题的，它必须能够正确地解决这一类问题中的任何一个实例，这个算法才是正确的。



### 2.插入排序

> [expample](/data/linux_c/prgmwrl/insertion_sort_exp)

Loop Invariant

> 假如某个判断条件满足以下三条准则，它就称为Loop Invariant：
>
> 1. 第一次执行循环体之前该判断条件为真。
> 2. 如果“第N-1次循环之后（或者说第N次循环之前）该判断条件为真”这个前提可以成立，那么就有办法证明第N次循环之后该判断条件仍为真。
> 3. 如果在所有循环结束后该判断条件为真，那么就有办法证明该算法正确地解决了问题。



### 3.算法的时间复杂度分析

> linear function 线性函数
>
> worst case 最坏情况
>
> average case 平均情况
>
> quadratic function 二次函数
>
>Upper Bound 上界

在分析算法的时间复杂度时，我们更关心最坏情况而不是最好情况，理由如下：

1. 最坏情况给出了算法执行时间的上界，我们可以确信，无论给什么输入，算法的执行时间都不会超过这个上界，这样为比较和分析提供了便利。
2. 对于某些算法，最坏情况是最常发生的情况，例如在数据库中查找某个信息的算法，最坏情况就是数据库中根本不存在该信息，都找遍了也没有，而某些应用场合经常要查找一个信息在数据库中存在不存在。
3. 虽然最坏情况是一种悲观估计，但是对于很多问题，平均情况和最坏情况的时间复杂度差不多，比如插入排序这个例子，平均情况和最坏情况的时间复杂度都是输入长度n的二次函数。

如果可以找到两个正的常数c1和c2，使得n足够大的时候（也就是n≥n0的时候）f(n)总是夹在c1g(n)和c2g(n)之间，就说f(n)和g(n)是同一量级的，f(n)就可以用Θ(g(n))来表示。

几种常见的时间复杂度函数按数量级从小到大的顺序依次是：Θ(lgn)，Θ(sqrt(n))，Θ(n)，Θ(nlgn)，Θ(n2)，Θ(n3)，Θ(2n)，Θ(n!)。



### 4.归并排序

> incremental 增量式
>
> devide-and-conquer 分而治之
>
> merge 
>
> > vt. 合并；使合并；吞没
> >
> > vi. 合并；融合
> >
> > n. (Merge)人名；(意)**梅尔杰**
>
> notation
>
> > n. 符号；乐谱；注释；记号法
>
> recurrence 递推公式
>
>

