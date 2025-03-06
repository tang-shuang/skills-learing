#!/bin/bash

a=10
b=20

val=`expr $a + $b`
echo "a + b : $val"

val=`expr $a - $b`
echo "a - b : $val"

val=`expr $a \* $b`
echo "a * b : $val"

val=`expr $a / $b`
echo "a \ b : $val"


if [ $a == $b ]
then 
    echo "a 等于b"
fi

if [ $a != $b ]
then 
    echo "a 不等于b"
fi

if [ $a -eq $b ]
then
    echo "a 等于b"
else
    echo "a 不等于b"
fi


for i in 1 2 3 4 5
do 
    echo "the value is $i"
done
    
i=1
while(($i <= 5))
do 
    echo $i
    let "i++";
done



demoFunc(){
    echo "函数调用"
}

demoFunc


demoFunc1(){
    echo "函数调用"
    echo "第一个参数: $1"
    echo "第二个参数: $2"
    echo "第三个参数: $3"
    echo "第四个参数: $4"
}

demoFunc1 1 2 3 4 

