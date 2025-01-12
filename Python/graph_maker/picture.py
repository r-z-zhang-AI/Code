from graphviz import Digraph
import os

# 创建一个有向图
dot = Digraph(comment='Organization Structure')

# 添加节点（每个部门及职员）
dot.node('A', 'CEO')
dot.node('B', 'COO')
dot.node('C', 'CFO')
dot.node('D', 'CTO')
dot.node('E', 'CHRO')
dot.node('F', 'Marketing Department')
dot.node('G', 'R&D Department')
dot.node('H', 'Finance Department')
dot.node('I', 'HR Department')
dot.node('J', 'Sales Department')
dot.node('K', 'Legal Department')
dot.node('L', 'Admin Department')

# 添加层级关系（每个职位与其下属的部门关系）
dot.edge('A', 'B')
dot.edge('A', 'C')
dot.edge('A', 'D')
dot.edge('A', 'E')
dot.edge('B', 'F')
dot.edge('B', 'G')
dot.edge('C', 'H')
dot.edge('E', 'I')
dot.edge('D', 'J')
dot.edge('C', 'K')
dot.edge('C', 'L')

# 获取当前工作目录
current_dir = os.getcwd()

# 或者指定保存路径，如 Linux 系统下的某个路径
# example_path = '/home/username/Documents/organization_structure.png'
example_path = os.path.join(current_dir, 'organization_structure.png')

# 渲染图形，保存为 .png 格式到指定目录
dot.render(example_path, format='png')

print(f"组织结构图已保存到 {example_path}")
