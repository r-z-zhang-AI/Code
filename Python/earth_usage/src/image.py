import matplotlib.pyplot as plt
from matplotlib.colors import Normalize
from matplotlib.colorbar import ColorbarBase
from PIL import Image, ImageSequence
import numpy as np

# 读取GIF图像并提取指定帧
def read_gif_as_frames(gif_path):
    with Image.open(gif_path) as gif:
        frames = [frame.copy() for frame in ImageSequence.Iterator(gif)]
    return frames

# 绘制可视化区域和 colorbar
def visualize_region(frames, region, output_path, colormap='viridis'):
    # 创建白底图像
    width, height = frames[0].size
    base_image = np.ones((height, width, 3), dtype=np.uint8) * 255

    # 绘制指定区域
    data = np.zeros((height, width))
    x_min, y_min, x_max, y_max = region
    data[y_min:y_max, x_min:x_max] = np.random.rand(y_max - y_min, x_max - x_min) * 100

    # 正则化数据并应用colormap
    norm = Normalize(vmin=0, vmax=100)
    cmap = plt.get_cmap(colormap)
    color_data = cmap(norm(data))[..., :3] * 255

    # 将区域叠加到白底图像
    base_image = base_image.astype(np.uint8)
    base_image[y_min:y_max, x_min:x_max] = color_data[y_min:y_max, x_min:x_max]

    # 保存结果
    plt.figure(figsize=(8, 6))
    plt.imshow(base_image.astype(np.uint8))
    plt.axis('off')
    
    # 添加 colorbar
    cbar_ax = plt.gca().inset_axes([0.9, 0.1, 0.03, 0.8])
    ColorbarBase(cbar_ax, cmap=cmap, norm=norm, orientation='vertical')
    
    # 保存图像
    plt.savefig(output_path, bbox_inches='tight', dpi=300)
    plt.close()

# 示例使用
gif_path = "example.gif"  # GIF路径
output_path = "visualized_image.png"  # 输出路径
region = (50, 50, 150, 150)  # 给定区域 (x_min, y_min, x_max, y_max)

# 读取GIF帧
frames = read_gif_as_frames(gif_path)

# 可视化给定区域
visualize_region(frames, region, output_path)
