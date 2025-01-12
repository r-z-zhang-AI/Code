import os
from osgeo import gdal
import matplotlib.pyplot as plt
import numpy as np

def process_raster(file_path):
    """加载并处理单个栅格影像文件"""
    try:
        dataset = gdal.Open(file_path)
        if dataset is None:
            print(f"无法打开文件: {file_path}")
            return
        
        band = dataset.GetRasterBand(1)  # 获取第一个波段
        data = band.ReadAsArray()
        
        # 显示影像
        plt.figure(figsize=(10, 5))
        
        plt.subplot(1, 2, 1)
        plt.imshow(data, cmap='gray')
        plt.colorbar()
        plt.title(f"Raster Image: {os.path.basename(file_path)}")
        
        # 显示直方图
        plt.subplot(1, 2, 2)
        plt.hist(data.flatten(), bins=10, range=(-0.5, 9.5), color='blue', alpha=0.7)
        plt.title("Histogram")
        plt.xlabel("Pixel Value")
        plt.ylabel("Frequency")
        
        plt.tight_layout()
        plt.show()
    except Exception as e:
        print(f"处理文件时出错: {file_path}, 错误信息: {e}")

def batch_process_rasters(directory):
    """批量处理目录中的所有影像文件"""
    if not os.path.isdir(directory):
        print(f"目录无效: {directory}")
        return
    
    # 支持的影像文件格式
    raster_extensions = (".tif", ".tiff", ".img", ".bil", ".hdr")
    
    # 遍历目录中的文件
    for root, _, files in os.walk(directory):
        for file in files:
            if file.lower().endswith(raster_extensions):
                file_path = os.path.join(root, file)
                print(f"正在处理文件: {file_path}")
                process_raster(file_path)

# 指定要批量处理的目录
directory_path = "your_directory_path_here"  # 替换为实际目录路径
batch_process_rasters(directory_path)
