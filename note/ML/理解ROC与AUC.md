## ML之模型评价

对于一个构建好的机器学习模型, 我们需要一个指标来对模型效果的好坏进行评价， 对于不同的问题，其评价指标也有所不同，本文主要介绍分类模型的评价指标。


### 一、分类模型


#### 1. 混淆矩阵

在二分类预测中，通常将测试数据从两个维度进行分类， 第一个是从数据标签角度，将数据分为**正向样本-Positive**和**负向样本-Negative**两类。第二是从预测的准确性角度，将数据分为**预测正确-True**和**预测错误-Flase**两类。


+ **P（Positive）**：代表数据为正向样本，即label为1

+ **N（Negative）**：代表数据为负向样本，即label为0

+ **T（True）**：代表预测正确

+ **F（False）**：代表预测错误


将上面的四种情况进行两两组合, 就可以将数据分为四种类型，得到如下的**混淆矩阵**: 

|  |  | 预测值 | 预测值 |
| :-: | :-: | :-: | :-: |
|  |  | Positive | Negtive |
| 真实值 | Positive | **TP** | **FN** |
| 真实值 | Negtive | **FP** | **TN** |


+ **True Positive (TP)（真阳性）** ： 预测值为正(Positive)，并且真实值也为正(Positive)，预测为真(True)。

+ **False Negative (FN)（假阴性）**：预测值为负(Negative)，但是真实值为正(Positive)，预测失败(False)。

+ **False Positive (FP)（假阳性）**：预测值为正(Positive)，但是真实值为负(Negative)，预测失败(False)。

+ **True Negative (TN)（真阴性）**：预测值为负(Negative)，并且真实值也为负(Negative)，预测为真(True)。

这四个分类比较容易混淆，这里可以按照**先看预测值，再看是否正确**的顺序进行记忆，例如**真阳性(TP)**表示预测为正样本，且预测正确的情况，**假阳性(FP)**表示预测为正样本，但预测错误的情况。

相应的，对每种类别的数据，都有一个比例表示: 

+ **真正率**(True Positive Rate,**TPR**)：$TPR=TP/(TP+FN)$，即被预测为正的正样本数 /正样本实际数。
 
+ **假正率**(False Positive Rate,**FPR**) ：$FPR=FP/(FP+TN)$，即被预测为正的负样本数 /负样本实际数。
 
+ **假负率**(False Negative Rate,**FNR**) ：$FNR=FN/(TP+FN)$，即被预测为负的正样本数 /正样本实际数。
 
+ **真负率**(True Negative Rate,**TNR**)：$TNR=TN/(TN+FP)$，即被预测为负的负样本数 /负样本实际数。

对于这四种比例，只要记住**TP+FN**为真实数据全部正样本， **FP+TN**为真实数据的全部负样本即可。

#### 2. 基础评价指标

+ **准确率（Accuracy）** : 准确率是评价分类模型时最常用的分类指标, 它表示预测正确的数据占整体数据中的比例。

	$$Accuracy = \frac{TP + TN}{TP + TN + FP + FN}$$

	**缺点** ： 在二分类问题中，如果正样本和负样本本身的本身的分布比例就不平衡, Accuracy就几乎没有参考价值(*例如在癌症预测的问题中，真实患病的样本仅占一小部分*) 。因为模型预测结果中即使TP为0，但TN很多，最终也会得到一个较高的Accuracy，而事实上我们真正想要关注的只有那一小部分TP。这种情况也被称为Accuracy paradox。


+ **精确率（查准率）(Precision)**：精确率很容易和准确率混淆, 但实际上精确率主要是对**预测为正**样本的评价，即预测为正的样本中（即真阳性与假阳性之和）实际也为正的样本所占的比例，也被称作查准率。而准确率是对全体数据进行的评价。

	$$P = \frac{TP}{TP + FP}$$

+ **召回率（查全率）(Recall)**：召回率也叫做查全率，是对全部**实际为正**样本的评价，即在全部的正向样本中（即真阳性与假阴性之和），被预测为正向的数据所占的比例。

	$$R = \frac{TP}{TP + FN}$$


可以看到，查准率P和查全率R的分子相同, 分母不同，即两者对数据的关注角度不同, 两者的关系可以用一个P-R图来展示：
	
![](https://pic4.zhimg.com/80/v2-7b6fc2ccc254a4e66a9dbfe43c3b3e07_1440w.jpg)

**决定PR曲线形状的因素** 以二分类问题举例，每个样本的输出值都是一个概率，我们一般会人为指定一个**阈值**，假设阈值为0.5， 那么输出概率大于等于0.5时，认为样本为正样本 ; 概率小于0.5时，认为是负样本。如果我们对阈值进行调整，例如将0.5改为0.6，那么预测为正的样本数量就会减少，对查准率和查全率都会产生影响。
	
这个阈值是我们随便定义的，我们并不知道这个阈值是否符合我们的要求。因此，为了找到一个最合适的阈值满足我们的要求，我们就必须遍历0到1之间所有的阈值，而每个阈值下都对应着一对查准率和查全率，从而我们就得到了这条曲线。而对于阈值的选择，通常要根据实际情况考虑，关注一个指标的同时，对另一个指标必然会有一定的牺牲。

+ **F1-score** : 

	为了在查准率和查全率之间找到一个平衡点，提出新的评价指标F1，F1 表示为P和R的调和平均数。

$$\frac{2}{F1} = \frac{1}{P} + \frac{1}{R}$$

$$F1 = \frac{2PR}{P+R}$$

F还有一个一般的表示形式$F_\beta$, 为加权调和平均，其中$\beta>0$度量了查全率对查准率的相对重要程度，$\beta=1$退化为标准的F1，$\beta>1$时查全率有更大影响，$\beta<1$查准率有更大的影响。

$$F_\beta = \frac{(1+\beta^2)PR}{(\beta^2P)+R}$$



#### 3. ROC曲线(Receiver Operating Characteristic curve)

ROC也是一种可以无视样本不平衡的指标，在介绍ROC曲线之前 ，还要介绍两个指标，分别为**灵敏度**和**特异度**

+ 灵敏度（Sensitivity） = $\frac{TP}{TP+FN}$

+ 特异度（Specificity） = $\frac{TN}{FP+TN}$

这两个指标仅作为另一种表达方式,  我们真正关心的是下面两个指标: 

+ **真正率TPR**(True Positive Rate) = 灵敏度

+ **假正率FPR**(False Positive Rate) = 1- 特异度

通过这两个指标便可以构建ROC曲线，横轴为FPR，纵轴为TPR

![](https://images2018.cnblogs.com/blog/1180120/201808/1180120-20180806175351853-1846246277.png)


**ROC的绘制** : 与前面的P-R曲线类似，ROC曲线也是通过遍历所有阈值来绘制整条曲线的。如果我们不断的遍历所有阈值，预测的正样本和负样本是在不断变化的，相应的在ROC曲线图中也会沿着曲线滑动。

**ROC端点的意义**： ROC曲线中的四个点

+ 点(0,1)：即FPR=0, TPR=1，意味着FN＝0且FP＝0，将所有的样本都正确分类。

+ 点(1,0)：即FPR=1，TPR=0，最差分类器，避开了所有正确答案。

+ 点(0,0)：即FPR=TPR=0，分类器把每个实例都预测为负类。

+ 点(1,1)：即FPR=TPR=1，分类器把每个实例都预测为正类。

**为什么ROC曲线可以无视样本不平衡**：TPR指预测的正样本占实际正样本的比例，FPR指预测错误的负样本占全部负样本的比例，两个比例都是分别基于**实际的**正样本或负样本的总量，相互之间不会有影响。例如即使正样本占比90%，负样本占比10%，TPR也只是在90%的正样本中的比例，与10%的负样本无关。


**ROC曲线好坏的判断**：ROC曲线的横坐标FPR反应了模型错误上报的程度，应该尽量小；而TPR反应了正确上报的程度，应该尽量大。所以ROC曲线越接近左上角，该分类器的性能越好。而且一般来说，如果ROC是光滑的，那么基本可以判断没有太大的overfitting。

```
# ROC计算

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
%matplotlib inline

# ======================== 构建初始化数据 ======================== #

parameter=40 # 样本数量
data=pd.DataFrame(index=range(0,parameter),columns=('score','label'))
data['label']=np.random.randint(0,2,size=len(data))
# np.random.choice从数组中随机抽取数字
data['score']=np.random.choice(np.arange(0.1,1,0.01),len(data['score']))

# ======================== 计算每个阈值下的混淆矩阵 ======================== #

# 阈值
thresholds = data['score']

# 每个阈值对应一组混淆矩阵
CM_DF = pd.DataFrame(index=range(len(thresholds)),columns=('Threshold','TP','FP','TN','FN'))
CM_DF.fillna(0,inplace = True)
CM_DF['Threshold'] = thresholds
CM_DF = CM_DF.sort_values(by=['Threshold'], ascending=False)

# 判断当前样本的类型
def mapCM(row, threshold):
    s = row['score']
    l = row['label']
    if(s >= threshold):
        return 'TP' if l ==1 else 'FP'
    else:
        return 'FN' if l ==1 else 'TN'

# 填充混淆矩阵
def buildCM():
    for index, row in CM_DF.iterrows():
        t = row['Threshold']
        for i, r in data.iterrows():
            cur = mapCM(r,t)
            row[str(cur)] += 1
        # print(index, row)
        CM_DF.loc[index] = row

buildCM()

# ======================== 计算真正率和假正率并绘制曲线 ======================== #

CM_DF['TPR'] = CM_DF['TP'] / (CM_DF['TP'] + CM_DF['FN'])
CM_DF['FPR'] = CM_DF['FP'] / (CM_DF['FP'] + CM_DF['TN'])
#show roc
plt.plot(CM_DF['FPR'], CM_DF['TPR'], marker = 'o')
plt.xlabel('FPR')
plt.ylabel('TPR')
plt.show()

```

#### 4. AUC

**几何意义**：AUC全称为**下曲线面积（Area Under Curve）**， 而**ROC-AUC** 指的就是ROC曲线下方的面积。Auc作为数值可以直观的评价分类器的好坏，值越大越好。

**概率意义**：从Mann–Whitney U statistic的角度进行解释，AUC就是从所有1样本中随机选取一个样本， 从所有0样本中随机选取一个样本，然后根据分类器模型对两个随机样本进行预测，把1样本预测为1的概率为p1，把0样本预测为1的概率为p0，p1>p0的概率就等于AUC。AUC越大，对于正负样本的判断就越准确，而如果我们的分类器模型为完全随机分类，那么AUC应该为0.5。

简单描述 ： AUC是指随机选出一个正样本和负样本，正样本预测得分大于负样本得分的概率。


**计算方法**：AUC的简单计算公式


$$ AUC = \frac{\sum_{ins_i \in positiveclass} rank_{ins_i} - \frac{M \times (M + 1)}{2}}{M \times N} $$

首先通过分类模型，对每个样本进行预测，输出对应的预测得分, 并将样本按照得分从小到大进行排序。

其中：

+ $ rank_{ins_i} $ : 表示第i个样本排序后的位置。

+ $ M，N $ : 分别表示正样本和负样本的真实数量。

+ $ \sum_{ins_i \in positiveclass} $: 表示将所有正样本的rank值累加。

这个公式没有考虑排序时，得分相同但rank值不同的情况，此时需要将相同得分的样本rank进行平均处理，例如rank值为2，3，4，5的四个样本，预测得分均相同，则将rank均修改为(2+3+4+5)/4

```
# AOC计算实现

# 根据预测得分排序
new_data = data.sort_values(by=['score'])
# rank的时候从1开始算
new_data['rank'] = range(1, len(new_data) + 1)
# 相同score 的rank取平均值
new_data['rank'] = new_data.groupby(['score'])['rank'].transform('mean')
# 获取正负样本数量
M = new_data[new_data['label'] == 1]['label'].count()
N = new_data[new_data['label'] == 0]['label'].count()
# 正样本的rank值相加
rank_sum_p = new_data[new_data['label'] == 1]['rank'].sum()
# 计算AUC
auc = (rank_sum_p - (M * (M + 1) /2)) / (M * N)

```

### 二、回归模型


### 三、聚类模型



### 参考

+ [精确率、召回率、F1 值、ROC、AUC 各自的优缺点是什么？](https://www.zhihu.com/question/30643044/answer/224360465)

+ [机器学习模型评估指标汇总](https://www.cnblogs.com/zongfa/p/9431807.html)

+ [【机器学习笔记】：一文让你彻底理解准确率，精准率，召回率，真正率，假正率，ROC/AUC](https://zhuanlan.zhihu.com/p/46714763)

+ [AUC，ROC我看到的最透彻的讲解](https://blog.csdn.net/u013385925/article/details/80385873)

+ [如何理解机器学习和统计中的AUC？](https://www.zhihu.com/question/39840928/answer/84906286)

+ [AUC的计算方法](https://blog.csdn.net/qq_22238533/article/details/78666436)

