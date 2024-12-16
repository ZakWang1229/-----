{{ self.title() }}

{{ s('background') }}

假设 $A$ 是一个非负整数的集合。将 $A$ 中不存在的最小非负整数记为 $\operatorname{mex}(A)$。例如，$\operatorname{mex}(\{0, 1, 2, 4, 5, 9\}) = 3$。

我们还定义了一种在含有 $0$ 的集合 $A$ 上的操作，称为 $\operatorname{Ultra}$。假设 $m = \operatorname{mex}(A)$，因为 $0\in A$，显然 $m > 0$。按照以下方法构建新的集合 $\operatorname{Ultra}(A)$：对 $A$ 中的每个元素异或 $m-1$。例如，$\operatorname{Ultra}(\{0, 1, 2, 4, 5, 9\}) = \{0\oplus2, 1\oplus2, 2\oplus2, 4\oplus2, 5\oplus2, 9\oplus2\} = \{2, 3, 0, 6, 7, 11\} = \{0, 2, 3, 6, 7, 11\}$。

不难发现，如果集合 $A$ 包含 $0$，则集合 $\operatorname{Ultra}(A)$ 也包含 $0$。

我们选择由 $0$ 到 $2^{k-1}$ 之间的整数组成的集合 $A_0$，且 $0$ 在 $A_0$ 中。考虑以下序列：

- $m_0 = \operatorname{mex}(A_0),A_1 = \operatorname{Ultra}(A_0)$。
- $m_1 = \operatorname{mex}(A_1),A_2 = \operatorname{Ultra}(A_1)$。
- $\dots$
- $m_i = \operatorname{mex}(A_i),A_{i+1} = \operatorname{Ultra}(A_i)$。

如果从某个数 $l$ 开始，数字 $m_i$ 不再变化，也就是说，对于所有 $i \ge l$，$m_i = m_l$，则称集合 $A_0$ 是 mex-stable 的，将 $m_l$ 称为集合 $A_0$ 的 mex-limit。

{{ s('description') }}

给定整数 $k,n,p$，计算满足以下条件的集合 $A_0$ 的数量：

- 它包含从 $0$ 到 $2^{k-1}$ 的 $n$ 个不同整数（其中 $0$ 必须包含在 $A_0$ 中）；
- 它是 mex-stable 的；
- 它的 mex-limit 等于 $p$。

由于答案可能很大，输出答案对 $M$ 取模后的结果。保证 $M - 1$ 能被 $2^{18}$（$262144$）整除。

{{ s('input format') }}

{{ self.input_file() }}

第一行包含一个整数 $M$，表示要对其取模的模数（$3 \le M \le 10^9$ 且 $M - 1$ 可被 $2^{18}$ 整除）（所以 $M$ 实际上不可能小于 $2^{18}+1$）。保证 $M$ 是一个质数。

第二行包含一个整数 $t$，表示输入数据的组数（$1 \le t \le 100000$）。

对于每组输入数据，包含三个整数 $k,n,p$（$1 \le k \le 17$，$ 1 \le n, p \le 2^k$）。

{{ s('output format') }}

{{ self.output_file() }}

对于每组输入数据，输出一行，包含一个整数，表示满足条件的集合 $A$ 的数量对 $M$ 取模后的结果。

{{ s('sample', 1) }}

{{ self.sample_text() }}

上面是自动读入样例 `1.in/ans`（存储在 `down` 文件夹内） 然后渲染到题面中；如果只有一组样例，则去掉 `1` 或将其替换成空串，样例仍然保存成 `1.in/ans`。上面的 `1` 可以是字符串。

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。

{{ s('subtasks') }}

除样例外，本题有三十个子任务，如下图所示。

{{ tbl('table') }}

{{ s('hint') }}

这里是一个非常温馨的提示。