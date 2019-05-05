## 第一阶段 C++Primer 5th 学习笔记
[unsigned 与 signed](#unsigned 与 signed)
### unsigned 与 signed
C++的基本数据类型：字符、布尔、整型、浮点    
- 字符型：位数与机器数相同
- 布尔型：0值为False，其他值为True      
- 整型：short《=int 《=long《=long long     
- 浮点型：float double
#### 除了布尔类型之外都有有符号类型和无符号类型的区别。
有符号型（默认）：有符号位，数字只占2^(该基本数据类型所占位数-1)位     
无符号型：没有符号位，数字占2^(该基本数据类型所占位数)位    
尤其要注意无符号型和有符号型的混合运算，会先把有符号型转化为无符号型，再进行计算。    
```c++
 #include <iostream>
 #include <math.h>
 
 /*
  * 注释是该行的对应运行结果
  *
  */
  
 int main(){
         unsigned u=10,u2=42;         
         std::cout<<u2-u<<std::endl;//32
         std::cout<<u-u2<<std::endl;//2^32-32
         
         int i=10,i2=42;
         std::cout<<i2-i<<std::endl;//32
         std::cout<<i-i2<<std::endl;//-32
         std::cout<<i-u<<std::endl;//0
         std::cout<<u-i<<std::endl;//0
                 
         return 0;
 }

```
  

## 第二阶段 （浙大翁恺老师）C++视频课+github笔记 查缺补漏

## 第三阶段 （陈越版本）数据结构

 [是否使用typedef定义结构体的区别](https://github.com/Anna-Joe/CplusCodingProgress/blob/master/%E6%98%AF%E5%90%A6%E4%BD%BF%E7%94%A8typedef%E5%AE%9A%E4%B9%89%E7%BB%93%E6%9E%84%E4%BD%93%E7%9A%84%E5%8C%BA%E5%88%AB.md)

 [关于树形结构的小结](https://github.com/Anna-Joe/CplusCodingProgress/blob/master/%E5%85%B3%E4%BA%8E%E6%A0%91%E5%BD%A2%E7%BB%93%E6%9E%84%E7%9A%84%E5%B0%8F%E7%BB%93.md)
