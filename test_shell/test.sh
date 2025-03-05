#!/bin/bash
echo "hello world"
name="zhangsan"
echo $name
value=21
echo $value
value=43
echo $value

new_value=$value
echo $new_value

array=(1 2 3 4 5)
echo ${#array[@]}
echo $PATH
str1="hello"
str2="$str1 world"
echo $str2


echo "执行的问价名:$0"
echo "执行的问价名:$1"
echo "执行的问价名:$2"
echo "执行的问价名:$3"

echo "参数 个数: $#"
echo "作为字符串显示: $*"
