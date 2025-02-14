import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
from scipy.stats import pearsonr

# 构造数据
data = {
    "性别": [0.06065975, 0.05298792, 0.05991464, 0.449506495, 0.304062403],
    "年龄": [0.99869109, 0.96708559, 0.89323863, 0.984638768, 0.008294337],
    "职业": [0.98861671, 0.60851267, 0.19041524, 0.439246915, 0.720235856],
    "收入水平": [0.22730012, 0.90488957, 0.93539443, 0.829886199, 0.969914853],
    "整体满意度": [0.99774994, 0.99169660, 0.99470437, 0.003533595, 0.001545465],

    "得知渠道" :          [0.98822691 ,0.37854892, 0.22637800, 0.697635477, 0.584258879],
    "购买情况"  :         [0.99924472 ,0.96865649 ,0.93864272 ,0.987470092 ,0.989196006],
    "产品口味满意度":     [0.99521476 ,0.95509264, 0.07330774 ,0.003346284 ,0.024710284],
    "最喜欢产品"    :[0.99976213 ,0.99371063, 0.99714682 ,0.987331984, 0.031527966],
    "产品价格评价"   :   [ 0.99902878, 0.97606994, 0.20605922 ,0.778018689, 0.009667492],
    "产品更新速度评价":   [0.99577907 ,0.98734586 ,0.32010092 ,0.648616587 ,0.003610822],
    "包装设计评价"     :  [0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "服务态度评价"      :[0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "点单过程评价"       :[0.99738107 ,0.96757800 ,0.98350143, 0.001697436 ,0.003950039],
    "制作速度评价"     :  [0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "会员服务满意度"    : [0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "店内环境整洁度评价" :[0.99774994, 0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "店内氛围评价"      : [0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "座位数量评价"      : [0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465],
    "整体满意度"         :[0.99774994 ,0.99169660 ,0.99470437 ,0.003533595 ,0.001545465]


    
}

df = pd.DataFrame(data)

# 计算相关性
correlations = df.corr()["整体满意度"].sort_values(ascending=False)
print("相关性分析：")
print(correlations)

# 回归分析
X = df.drop(columns=["整体满意度"])
y = df["整体满意度"]

# 多元线性回归
reg = LinearRegression()
reg.fit(X, y)
print("\n线性回归系数：")
print(pd.Series(reg.coef_, index=X.columns))

# 特征重要性（随机森林）
rf = RandomForestRegressor(random_state=42)
rf.fit(X, y)
print("\n随机森林特征重要性：")
print(pd.Series(rf.feature_importances_, index=X.columns))
