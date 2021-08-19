# DLT求解

四点的单应性矩阵，可以用DLT（direct linear transform）方法求解，即用四个对应的(齐次)坐标，将单应性矩阵求解问题化成满秩的8x8系数矩阵A关于向量h的线性方程组Ah = b的求解问题。

本仓库不借助线性代数库实现四点DLT求解过程，使用PLU矩阵分解进行线性方程组求解。可以扩展到使用CUDA进行大规模DLT问题的求解。

## 算子扩展

在DLT求解的基础上，可以将求解过程嵌入到深度学习计算图中，变成一个算子F，输出为H(单应性矩阵)，输入为源点(srcPts)和目标点(dstPts)。计算图反向传播过程，需要考虑H关于srcPts和dstPts的导数，需手动推算矩阵导数，推荐矩阵在线求导网站[www.matrixcalculus.org/](http://www.matrixcalculus.org/)





