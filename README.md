# SolveDLT

## 介绍

已知对应四点坐标求单应性矩阵(homography matrix)，可以用DLT（direct linear transform）方法求解，即将单应性矩阵求解问题化成满秩的8x8系数矩阵A关于向量h的线性方程组Ah = b的求解问题。

本仓库不借助线性代数库实现四点DLT求解过程，包括两种方法:

* 使用PLU矩阵分解进行线性方程组Ah = b求解 

* 用gaussian消元法得到inv(A), h = inv(A) @ b。

两种方法可以扩展到使用CUDA进行大规模DLT问题的并行求解，在图像拼接、配准任务中有应用<sup>[1]</sup>。

## 算子扩展

在DLT求解的基础上，可以将求解过程嵌入到深度学习计算图中，变成一个算子F，输出为H(单应性矩阵)，输入为源点(srcPts)和目标点(dstPts)。计算图反向传播过程，需要考虑H关于srcPts和dstPts的导数，需手推矩阵导数，推荐矩阵在线求导网站[www.matrixcalculus.org/](http://www.matrixcalculus.org/)



## 参考文献

[1] Zaragoza J , Chin T , Tran Q , et al. As-Projective-As-Possible Image Stitching with Moving DLT[J]. IEEE Trans Pattern Anal Mach Intell, 2014, 36(7):1285-1298.



