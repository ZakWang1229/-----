{{ self.title() }}

{{ s('background') }}

{{ s('description') }}

有一个二元函数 $f(x,y)$，它是这么定义的：

 $f(x,y)=\left\{
\begin{array}{rcl}
a, & & {\text{if} \quad \quad \ \ \ a \leq x}\\
b, & & {\text{else if} \quad b \leq y}\\
0, & & {\text{else}}
\end{array} \right.$

其中 $a,b$ 为常数。

现在给定 $n$ 组 $x,y$，你需要选择合适的 $a,b$，使得 $\sum_{i=1}^{n} f(x_i,y_i)$ 最大。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个整数 $n$，表示 $x$，$y$ 的组数。

后面 $n$ 行，每行两个数 $x_i$，$y_i$。

{{ s('output format') }}

{{ self.output_file() }}

一行，一个数，输出 $\max(\sum_{i=1}^{n} f(x_i,y_i))$。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', '3-12') }}

{{ self.sample_file() }}

满足子任务编号 $1$ - $10$ 的限制

{{ s('subtasks') }}

对于 $100\%$ 的数据，$0\leq y_i\leq x_i\leq 10^9$，$1 \leq n \leq 1.5 \times 10^5$。

{{ tbl('table') }}

{{ s('hint') }}

这里是一个非常温馨的提示。