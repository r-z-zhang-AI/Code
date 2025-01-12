import matplotlib.pyplot as plt
import numpy as np

import numpy as np

# 年份数据，注意图片中的数据从1995年开始，到2023年结束
years = np.array([1995, 2000, 2005, 2010, 2015, 2020, 2023])

# 耕地面积数据
cultivated_land_area = np.array([15609, 30000, 39250.5, 49965, 23890.5, 12650, 14000])

# 林地面积数据
forest_land_area = np.array([293145, 350000, 367305, 400950, 441855, 434600, 434600])

# 草地面积数据
grassland_area = np.array([8000.3, 19907.4, 21000.5, 1000.3, 19900.6, 19000.5, 17000.4])

# 水域面积数据
water_area = np.array([7904, 7904, 7904, 7904, 7904, 7904, 7904])

# 城乡建设用地面积数据
urban_rural_construction_land_area = np.array([2000.5, 1358.5, 1844.3, 3137.5, 2177.5, 1200.8, 1217.5])

# 设置全局字体为无衬线字体，避免出现汉字
plt.rcParams['font.family'] = 'sans-serif'  
# 解决负号显示问题
plt.rcParams['axes.unicode_minus'] = False  

# 绘制耕地面积条形图
plt.subplot(231)
plt.bar(years, cultivated_land_area)
plt.title('Cultivated Land')
plt.xlabel('Year')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.ylabel('Area (hectares)')

# 绘制林地面积条形图
plt.subplot(232)
plt.bar(years, forest_land_area)
plt.title('Forest Land')
plt.xlabel('Year')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.ylabel('Area (hectares)')

# 绘制草地面积条形图
plt.subplot(233)
plt.bar(years, grassland_area)
plt.title('Grassland')
plt.xlabel('Year')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.ylabel('Area (hectares)')

# 绘制水域面积条形图
plt.subplot(234)
plt.bar(years, water_area)
plt.title('Water')
plt.xlabel('Year')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.ylabel('Area (hectares)')

# 绘制城乡建设用地面积条形图
plt.subplot(235)
plt.bar(years, urban_rural_construction_land_area)
plt.title('Construction Land')
# # 设置横坐标刻度标签
# plt.xticks(years)  
plt.xlabel('Year')  
plt.ylabel('Area (hectares)')

# 调整子图之间的间距
plt.tight_layout()

plt.savefig('../output/land.png')
print("file created")