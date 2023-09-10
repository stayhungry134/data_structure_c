[toc]

数据结构与算法分析(C语言描述版)

#  第一章 引论

## 基础的数学知识

### 指数

$$
X^2X^B=X^{A+B} \\
\frac{X^A}{X^B} = X^{A-B} \\
(X^A)^B = X^{AB} \\
X^N + X^N = 2 X^N \\
2^N + 2^N = 2^{N+1}
$$

### 对数

> 注：在计算机科学中，除非有特别的声明，所有的对数都是以2为底的

$$
\log_{A}{B} = \frac{\log_{C}{A}}{\log_{C}{B}}; \\
C > 0
$$

$$
\log{AB} = \log{A} + \log{B}
$$

### 级数

级数是一种数学概念，它是将一系列数值相加而得到的结果。一个级数通常包含无限多个项，这些项按照一定的规律逐个相加，从而形成一个序列的和。级数可以用来描述许多自然现象和数学问题，包括无限的几何图形、无穷级数、数学分析、和微积分等领域。
$$
S = a₁ + a₂ + a₃ + ... + aₙ + ...
$$
其中，S表示级数的和，a₁、a₂、a₃等表示级数的各个项，n表示级数的索引或序号。这些项可以是实数、复数、分数或其他数值类型。

级数可以是收敛的，这意味着级数的和可以有一个有限的值。如果级数的和趋向于一个有限的极限值，那么这个级数就是收敛的。相反，如果级数的和没有有限的极限值，那么这个级数就是发散的，它可能趋向于无穷大或没有趋向于任何值。

级数的收敛性是数学分析和微积分中的一个重要概念，它在理解无限过程、连续函数、积分等方面具有广泛的应用。许多数学问题和物理问题都可以用级数来建模和求解。

> 可以理解为数列求和？

$$
\sum_{i=0}^{N}2^i = 2^{N+1} - 1
$$

> 可以理解为 等比数列求和

$$
\sum_{i=0}^{N}A^i = \frac{A^{N+1} - 1}{A - 1}
$$

> 当 N 趋于 ∞ 时该和趋向于 1/(1 - A)，这些公式是“几何级数”公式

$$
\sum_{i=0}^{N}A' \leq \frac{1}{1 - A}
$$

$$
如果 N \geq 1, 则 \sum_{i=1}^{N}i^2 = \frac{N(N + 1)(2N + 1)}{6}
$$



### 模运算

如果 N 整除 $A - B$，那么我们就说 A 与 B模 N 同余(congruent) ，记为   $A \equiv B(rood N)$  。 直
观地看 ， 这意味着无论 A 还是 B 被 N 去除，所得余数都是相同的。 于是，$81\equiv 61 \equiv 1 (\bmod10)$。
如同等号的情形一样，若 $A \equiv B(\bmod N)$ ，则 $A + C \equiv B + C(\bmod N)$以及 $AD \equiv BD(\bmod N) $

## 递归简论

在编写递归例程的时候，关键是要牢记递归的四条基本法则

1. 基准情形：必须总有某些基准情形，它无形递归就能解出。（也就是递归的出口）
2. 不断推进： 对于那些需要推进递归求解的情形，每一次递归调用都必须要使求解状况朝接近基准情形的方向推进。
3. 设计法则：假设所有的递归调用都能进行。
4. 合成效益法则：在求解一个问题的同一实例时，切勿在不同的递归调用中做重复性的工作。