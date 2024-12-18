import pygame
import random
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

# 初始化 pygame
pygame.init()

# 屏幕设置
WIDTH, HEIGHT = 1800, 970  # 减小界面大小
screen = pygame.display.set_mode((WIDTH, HEIGHT))  # 窗口模式
pygame.display.set_caption("Natural Selection Simulation")

# 边界留白
MARGIN = 20  # 2厘米约为20像素（假设屏幕分辨率约96DPI）

# 颜色定义
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)

# 加载生物图片
creature_images = [pygame.image.load(f"creature{i}.png") for i in range(1, 6)]  # 假设有 creature1.png 至 creature5.png

# 生物类
class Creature:
    def __init__(self, x, y, size, speed, detection_range, image):
        self.x = x
        self.y = y
        self.size = size
        self.speed = speed
        self.detection_range = detection_range
        self.image = pygame.transform.scale(image, (size * 3, size * 3))  # 图像缩放加大
        self.energy = 100

    def move(self, foods, predators):
        # 检测范围内是否有食物或捕食者
        closest_food = None
        min_food_dist = float('inf')
        closest_predator = None
        min_predator_dist = float('inf')

        for food in foods:
            dist = ((food[0] - self.x)**2 + (food[1] - self.y)**2)**0.5
            if dist < min_food_dist:
                min_food_dist = dist
                closest_food = food

        for predator in predators:
            dist = ((predator.x - self.x)**2 + (predator.y - self.y)**2)**0.5
            if dist < min_predator_dist:
                min_predator_dist = dist
                closest_predator = predator

        if closest_predator and min_predator_dist < self.detection_range:
            # 逃离捕食者
            dx = self.x - closest_predator.x
            dy = self.y - closest_predator.y
        elif closest_food and min_food_dist < self.detection_range:
            # 接近食物
            dx = closest_food[0] - self.x
            dy = closest_food[1] - self.y
        else:
            # 随机运动
            dx = random.uniform(-1, 1)
            dy = random.uniform(-1, 1)

        # 归一化速度
        length = (dx**2 + dy**2)**0.5
        if length != 0:
            dx, dy = dx / length, dy / length

        self.x += dx * self.speed
        self.y += dy * self.speed

        # 保证生物在屏幕范围内
        self.x = max(MARGIN, min(WIDTH - MARGIN, self.x))
        self.y = max(MARGIN, min(HEIGHT - MARGIN, self.y))

        # 消耗能量
        self.energy -= 0.1 + 0.01 * self.size + 0.02 * self.speed

    def draw(self):
        rect = self.image.get_rect(center=(int(self.x), int(self.y)))
        screen.blit(self.image, rect)
        pygame.draw.circle(screen, BLACK, (int(self.x), int(self.y)), self.detection_range, 1)

# 捕食者类
class Predator:
    def __init__(self, x, y, speed, detection_range):
        self.x = x
        self.y = y
        self.speed = speed
        self.detection_range = detection_range

    def move(self, creatures):
        # 检测范围内是否有猎物
        closest_prey = None
        min_prey_dist = float('inf')

        for creature in creatures:
            dist = ((creature.x - self.x)**2 + (creature.y - self.y)**2)**0.5
            if dist < min_prey_dist:
                min_prey_dist = dist
                closest_prey = creature

        if closest_prey and min_prey_dist < self.detection_range:
            # 接近猎物
            dx = closest_prey.x - self.x
            dy = closest_prey.y - self.y
        else:
            # 随机运动
            dx = random.uniform(-1, 1)
            dy = random.uniform(-1, 1)

        # 归一化速度
        length = (dx**2 + dy**2)**0.5
        if length != 0:
            dx, dy = dx / length, dy / length

        self.x += dx * self.speed
        self.y += dy * self.speed

        # 保证捕食者在屏幕范围内
        self.x = max(MARGIN, min(WIDTH - MARGIN, self.x))
        self.y = max(MARGIN, min(HEIGHT - MARGIN, self.y))

    def draw(self):
        pygame.draw.circle(screen, YELLOW, (int(self.x), int(self.y)), 10)
        pygame.draw.circle(screen, BLACK, (int(self.x), int(self.y)), self.detection_range, 1)

# 初始化食物
FOOD_COUNT = 800

def generate_food():
    return [(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN)) for _ in range(FOOD_COUNT)]

# 主函数
def main():
    clock = pygame.time.Clock()
    running = True
    paused = False
    start_simulation = False

    # 创建初始生物
    creatures = [Creature(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN),
                          random.randint(10, 20), random.uniform(1, 3), random.randint(50, 100),
                          random.choice(creature_images)) for _ in range(50)]  # 增加生物数量

    # 创建初始捕食者
    predators = [Predator(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN),
                          random.uniform(2, 4), random.randint(80, 150)) for _ in range(8)]

    foods = generate_food()

    # 数据记录
    evolution_data = []

    RESPAWN_PROBABILITY = 0.8  # 生物死后重新生成的概率

    while running:
        screen.fill(WHITE)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                if not start_simulation:
                    start_simulation = True
                else:
                    # 检测暂停按钮点击
                    mouse_x, mouse_y = pygame.mouse.get_pos()
                    if WIDTH - 200 <= mouse_x <= WIDTH - 50 and 10 <= mouse_y <= 60:
                        paused = not paused
                    elif WIDTH - 350 <= mouse_x <= WIDTH - 250 and 10 <= mouse_y <= 60:
                        # 重新开始按钮
                        creatures = [Creature(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN),
                                              random.randint(10, 20), random.uniform(1, 3), random.randint(50, 100),
                                              random.choice(creature_images)) for _ in range(50)]  # 增加生物数量

                        predators = [Predator(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN),
                                              random.uniform(2, 4), random.randint(80, 150)) for _ in range(8)]

                        foods = generate_food()
                        evolution_data = []

        if not start_simulation:
            # 初始界面
            font = pygame.font.SysFont(None, 55)
            text = font.render("Click to Start Simulation", True, BLACK)
            screen.blit(text, (WIDTH // 2 - text.get_width() // 2, HEIGHT // 2))
        else:
            # 绘制暂停按钮
            pygame.draw.rect(screen, BLACK, (WIDTH - 200, 10, 150, 50))
            font = pygame.font.SysFont(None, 35)
            button_text = "Start" if paused else "Pause"
            text = font.render(button_text, True, WHITE)
            screen.blit(text, (WIDTH - 200 + 75 - text.get_width() // 2, 35 - text.get_height() // 2))

            # 绘制重新开始按钮
            pygame.draw.rect(screen, BLACK, (WIDTH - 350, 10, 100, 50))
            restart_text = font.render("Restart", True, WHITE)
            screen.blit(restart_text, (WIDTH - 350 + 50 - restart_text.get_width() // 2, 35 - restart_text.get_height() // 2))

            if not paused:
                # 绘制食物
                for food in foods:
                    pygame.draw.circle(screen, GREEN, food, 3)

                # 更新并绘制捕食者
                for predator in predators:
                    predator.move(creatures)
                    predator.draw()

                # 更新并绘制生物
                for creature in creatures[:]:
                    creature.move(foods, predators)
                    creature.draw()

                    # 生物进食
                    for food in foods[:]:
                        if ((food[0] - creature.x)**2 + (food[1] - creature.y)**2)**0.5 < creature.size:
                            creature.energy += 20
                            foods.remove(food)

                    # 检测能量
                    if creature.energy <= 0:
                        creatures.remove(creature)
                        if random.random() < RESPAWN_PROBABILITY:
                            creatures.append(Creature(random.randint(MARGIN, WIDTH - MARGIN), random.randint(MARGIN, HEIGHT - MARGIN),
                                                    random.randint(10, 20), random.uniform(1, 3), random.randint(50, 100),
                                                    random.choice(creature_images)))

                    # 捕食者捕食
                    for predator in predators:
                        if ((predator.x - creature.x)**2 + (predator.y - creature.y)**2)**0.5 < 10:
                            creatures.remove(creature)
                            break

                # 生成新的食物
                if len(foods) < FOOD_COUNT:
                    foods.extend(generate_food())

                # 记录进化数据
                evolution_data.append([creature.size for creature in creatures])

        pygame.display.flip()
        clock.tick(30)

    pygame.quit()

    # 绘制进化趋势
    sizes = [np.mean(gen) for gen in evolution_data if gen]
    plt.plot(sizes, label="Average Size")
    plt.xlabel("Generations")
    plt.ylabel("Average Size")
    plt.legend()
    plt.show()

    # 动图生成
    fig, ax = plt.subplots()
    ax.set_xlim(0, WIDTH)
    ax.set_ylim(0, HEIGHT)
    scat = ax.scatter([], [])

    def update(frame):
        scat.set_offsets([(creature.x, creature.y) for creature in creatures])
        return scat,

    ani = FuncAnimation(fig, update, frames=range(0, len(evolution_data)), blit=True)
    ani.save("simulation.gif", writer="imagemagick", fps=10)

if __name__ == "__main__":
    main()

