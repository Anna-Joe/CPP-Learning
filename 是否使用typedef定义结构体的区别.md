### 是否使用typedef定义struct结构体的区别
- 1 顺序表结构 未使用typedef定义struct 编译通过 运行结果无误
```c
#include<iostream>
#define MaxSize 100

using namespace std;

typedef int ElemType;
struct SqList{
	ElemType data[MaxSize];
	int length;
}SqList;
```

- 2.1 链表结构 未使用typedef定义struct 编译不通过 
```c
#include<iostream>
#define MaxSize 100

using namespace std;

typedef int ElemType;
struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkList;
```
报错如下
> LinkList.cpp(15) : error C2065: 'l' : undeclared identifier   
> LinkList.cpp(15) : error C2676: binary '*' : 'struct LinkNode' does not define this operator or a conversion to a type acceptable to the predefined operator   
> LinkList.cpp(15) : error C2275: 'ElemType' : illegal use of this type as an expression   
> LinkList.cpp(8) : see declaration of 'ElemType'   
> LinkList.cpp(15) : error C2146: syntax error : missing ')' before identifier 'a'   
> LinkList.cpp(15) : error C2182: 'createLinkList' : illegal use of type 'void'   
> LinkList.cpp(15) : error C2078: too many initializers   
> LinkList.cpp(15) : error C2275: 'ElemType' : illegal use of this type as an expression   
> LinkList.cpp(8) : see declaration of 'ElemType'   
> LinkList.cpp(15) : error C2059: syntax error : ')'   
> LinkList.cpp(15) : error C2143: syntax error : missing ';' before '{'   
> LinkList.cpp(15) : error C2447: missing function header (old-style formal list?)   
> LinkList.cpp(30) : error C2676: binary '*' : 'struct LinkNode' does not define this operator or a conversion to a type acceptable to the predefined operator   
> LinkList.cpp(30) : error C2448: '<Unknown>' : function-style initializer appears to be a function definition   
> LinkList.cpp(45) : error C2676: binary '*' : 'struct LinkNode' does not define this operator or a conversion to a type acceptable to the predefined operator   
> LinkList.cpp(46) : error C2059: syntax error : ')'   
> LinkList.cpp(53) : error C2065: 'printLinkList' : undeclared identifier   
> Error executing cl.exe.   
>    
> LinkList.obj - 15 error(s), 0 warning(s)   

- 2.2 链表结构 使用typedef定义struct 编译通过 运行结果无误 
```c
#include<iostream>
#define MaxSize 100

using namespace std;

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkList;
```

原因未知。
