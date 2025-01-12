import matplotlib.pyplot as plt
import numpy as np

import numpy as np

# 年份数据，根据图片中的数据从1995年开始，到2023年结束
years = np.array([1995, 2000, 2005, 2010, 2015, 2020, 2023])

# 耕地占比数据
cultivated_land_percentage = np.array([4.78, 7.33, 8.77, 10.8, 4.82, 2.66, 2.95])

# 林地占比数据
forest_land_percentage = np.array([89.74, 85.54, 82.12, 86.61, 89.13, 91.43, 91.55])

# 草地占比数据
grassland_percentage = np.array([2.45, 4.87, 4.7, 0.22, 4.01, 4, 3.58])

# 水域占比数据
water_area_percentage = np.array([2.42, 1.93, 1.77, 1.71, 1.6, 1.66, 1.66])

# 城乡建设用地占比数据
urban_rural_construction_land_percentage = np.array([0.6, 0.3, 0.4, 0.68, 0.4, 0.25, 0.26])

# 设置全局字体为无衬线字体，避免出现汉字
plt.rcParams['font.family'] = 'sans-serif'  
# 解决负号显示问题
plt.rcParams['axes.unicode_minus'] = False  

# 绘制耕地折线图
plt.subplot(231)
plt.plot(years, cultivated_land_percentage)
plt.title('Farmland')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.xlabel('year')
plt.ylabel('(%)')

# 绘制林地折线图
plt.subplot(232)
plt.plot(years, forest_land_percentage)
plt.title('Forest Land')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.xlabel('year')
plt.ylabel('(%)')

# 绘制草地折线图
plt.subplot(233)
plt.plot(years, grassland_percentage)
plt.title('Grassland')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.xlabel('year')
plt.ylabel('(%)')

# 绘制水域折线图
plt.subplot(234)
plt.plot(years, water_area_percentage)
plt.title('Water Land')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.xlabel('year')
plt.ylabel('(%)')


# 绘制城乡建设用地折线图

plt.subplot(235)
plt.plot(years, urban_rural_construction_land_percentage)
plt.title('Construction Land')
plt.xlabel('year')
plt.ylabel('(%)')
# # 设置横坐标刻度标签
# plt.xticks(years)  

# 调整子图之间的间距
plt.tight_layout()

# 保存图片为 png 格式，文件名可根据需求修改
plt.savefig('../output/land_use_proportion_chart.png')  
print("file created")